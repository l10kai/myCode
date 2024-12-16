import re

from ultralytics import YOLO
from paddleocr import PaddleOCR
class ImageProcessor:
    def __init__(self, weight_path,savepic=False):
        # 初始化 YOLO 模型
        self.model = YOLO(weight_path)
        # 初始化 PaddleOCR，这里默认使用 GPU 和角度分类
        self.ocr = PaddleOCR(use_angle_cls=True, use_gpu=True)
        self.savepic = savepic

    def detect_objects(self, image_path,resname):
        print(image_path,resname)
        # 使用 YOLO 模型检测图像中的对象
        results = self.model.predict(source=image_path,conf=0.6)
        # 保存并显示检测结果图像
        for result in results:
            if self.savepic:
                if resname:
                    print(resname)
                    result.save(filename=resname)
        # 计算检测到的对象数量
        object_count = sum(result.boxes.xywh.shape[0] for result in results)
        return object_count

    def extract_text(self, image_path):
        # 使用 PaddleOCR 进行文字识别
        ocr_results = self.ocr.ocr(image_path, cls=True)
        # print(ocr_results[0][0][1])
        full_date_time_pattern = re.compile(r'\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}')
        date_pattern = re.compile(r'\d{4}-\d{2}-\d{2}')
        time_pattern = re.compile(r'\d{2}:\d{2}:\d{2}')

        date = ''
        time = ''
        texts = ''
        for i in ocr_results:
            for j in i:
                text = j[1][0]
                if full_date_time_pattern.match(text):
                    date = text
                    print('date', date)
                elif date_pattern.match(text):
                    date = text
                elif time_pattern.match(text):
                    time = text

        print('111',date)
        print('222',time)
        if date and time:
            date = f"{date} {time}"
            print('combined date', date)
        elif date:
            print('date only', date)
        elif time:
            print('time only', time)

        texts = [
            result[1][0] for line in ocr_results for result in line
            if ":" not in result[1][0] and not date_pattern.match(result[1][0])
        ]
        print('inpred',date,texts)
        return date,texts

# 使用示例
# 创建实例，传入 YOLO 权重路径
# processor = ImageProcessor('runs/detect/train2/weights/best.pt')
#
# # 单独调用检测对象数量
# object_count = processor.detect_objects('dataset-student&table/images/test/9.png')
# print("Detected objects:", object_count)
#
# # 单独调用提取文本
# detected_texts = processor.extract_text('dataset-student&table/images/test/9.png')
# print("Detected texts:", detected_texts)
