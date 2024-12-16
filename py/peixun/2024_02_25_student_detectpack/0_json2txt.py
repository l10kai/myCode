import json
import os

# 定义类别映射字典
label_to_category_id = {
    "people": 0,
    # "table":1
}


def convert_labelme_json_to_yolov8(json_file, output_file, img_width, img_height):
    with open(json_file, 'r') as f:
        data = json.load(f)

    with open(output_file, 'w') as outfile:
        for shape in data['shapes']:
            category_id = label_to_category_id.get(shape['label'], -1)  # 使用get以防label不存在于字典中
            # 假设shape['points']包含矩形的左上角和右下角坐标
            x1, y1 = shape['points'][0]
            x2, y2 = shape['points'][1]

            # 计算中心点坐标和矩形的宽度、高度
            x_center = (x1 + x2) / 2.0
            y_center = (y1 + y2) / 2.0
            width = x2 - x1
            height = y2 - y1

            # 归一化坐标和尺寸
            norm_x_center = x_center / img_width
            norm_y_center = y_center / img_height
            norm_width = width / img_width
            norm_height = height / img_height

            # 将归一化后的标注写入输出文件
            outfile.write(f"{category_id} {norm_x_center} {norm_y_center} {norm_width} {norm_height}\n")


def process_all_jsons(folder_path, img_width, img_height):
    for filename in os.listdir(folder_path):
        if filename.endswith('.json'):
            json_file_path = os.path.join(folder_path, filename)
            output_file_path = os.path.join(folder_path, filename.replace('.json', '.txt'))
            convert_labelme_json_to_yolov8(json_file_path, output_file_path, img_width, img_height)


# 示例：假设所有图像尺寸相同，作为示例
img_width = 2800
img_height = 1600
process_all_jsons('datasetraw-onlylowerhead/labels', img_width, img_height)
