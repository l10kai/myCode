import os
import sqlite3

from flask import Flask, request, jsonify
from flask_cors import CORS
from predict import ImageProcessor
processor = ImageProcessor('runs/detect/train2/weights/best.pt')
processor2 = ImageProcessor('runs/detect/train5/weights/best.pt',savepic=True)

app = Flask(__name__)
CORS(app)  # Enabling CORS


def insert_data(filename, object_count, detected_date, classroom_name, head_up_count, attendance_rate, head_down_rate):
    conn = sqlite3.connect('classroom_monitoring.db')
    c = conn.cursor()

    # 插入数据
    c.execute('''
    INSERT INTO monitoring_data (filename, object_count, detected_date, classroom_name, head_up_count, attendance_rate, head_down_rate)
    VALUES (?, ?, ?, ?, ?, ?, ?)
    ''', (filename, object_count, detected_date, classroom_name, head_up_count, attendance_rate, head_down_rate))

    # 提交事务
    conn.commit()

    # 关闭连接
    conn.close()


def generate_unique_filename(directory, filename):
    """生成不重复的文件名，如果文件已存在，则添加后缀（如 _1, _2等）"""
    base_name, extension = os.path.splitext(filename)
    counter = 1
    unique_filename = filename

    while os.path.exists(os.path.join(directory, unique_filename)):
        unique_filename = f"{base_name}_{counter}{extension}"
        counter += 1

    return unique_filename
@app.route('/upload', methods=['POST'])
def upload_file():
    files = request.files.getlist('files')
    attendance = int(request.form['attendance'])
    for file in files:
        unique_filename = generate_unique_filename('tmp', file.filename)
        temp_path = os.path.join('tmp', unique_filename)
        file.save(temp_path)
        base_name, extension = os.path.splitext(file.filename)
        res_filename = f"{base_name}_res{extension}"
        res_path = os.path.join('tmp', res_filename)
        # print(temp_path)
        object_count = processor.detect_objects(temp_path,'')
        detected_date, detected_texts = processor.extract_text(temp_path) #日期 教室号
        # print(detected_date, detected_texts)
        object_count2 = processor2.detect_objects(temp_path,res_path) # 抬头数
        attendance_rate = 'null' if attendance == 0 else "{:.2f}%".format((object_count / attendance) * 100)
        head_down_rate = 'null' if object_count == 0 else "{:.2f}%".format(
            ((object_count - object_count2) / object_count) * 100)
        # print('文件名:', file.filename,
        #       '人数：', object_count,
        #       "日期：", detected_date if detected_date else "未检测到日期",
        #       "教室名：", detected_texts[0] if detected_texts else "未检测到教室名",
        #       "抬头数：", object_count2,
        #       "出勤率：", attendance_rate,
        #       "低头率：", head_down_rate)
        insert_data(unique_filename, object_count, detected_date if detected_date else "未检测到日期", detected_texts[0] if detected_texts else "未检测到教室名", object_count2, attendance_rate,
                    head_down_rate)

    return {"message": "Received"}


@app.route('/getdata', methods=['GET'])
def get_data():
    conn = sqlite3.connect('classroom_monitoring.db')
    cur = conn.cursor()
    cur.execute('SELECT * FROM monitoring_data')  # 假设表名为 monitoring_data
    rows = cur.fetchall()

    # 将查询结果从sqlite3.Row对象转换为字典列表
    data_list = []
    for row in rows:
        data_list.append(row)

    conn.close()
    return jsonify({'data': data_list})

if __name__ == '__main__':
    app.run(debug=True)
