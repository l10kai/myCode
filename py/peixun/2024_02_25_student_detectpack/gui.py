import os
import sys
from PyQt5.QtWidgets import (QApplication, QWidget, QLabel, QPushButton, QVBoxLayout,
                             QHBoxLayout, QFileDialog, QComboBox, QTextEdit)
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QMessageBox
from predict import ImageProcessor



class ImageProcessorApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
        self.selected_image = None  # 初始化时没有选中的图片
        self.selected_weight = None  # 初始化时没有选中的权重文件

    def initUI(self):
        # 创建顶级布局
        layout = QVBoxLayout()

        # 创建标题
        title = QLabel("课堂参与度智能监测系统")
        title.setAlignment(Qt.AlignCenter)  # 设置标题居中
        title.setStyleSheet("font-size: 24px; font-weight: bold;")
        layout.addWidget(title)

        # 创建两个图片框
        self.img_label1 = QLabel()
        self.img_label1.setFixedSize(700, 400)
        self.img_label1.setStyleSheet("background-color: grey")

        self.img_label2 = QLabel()
        self.img_label2.setFixedSize(700, 400)
        self.img_label2.setStyleSheet("background-color: grey")

        # 图片框布局
        image_layout = QHBoxLayout()
        image_layout.addWidget(self.img_label1)
        image_layout.addWidget(self.img_label2)
        layout.addLayout(image_layout)

        # 创建一行布局放置权重和图片选择器
        selector_layout = QHBoxLayout()

        # 权重文件选择器
        weight_label = QLabel("请选择权重文件")
        selector_layout.addWidget(weight_label)
        self.weight_btn = QPushButton("选择权重")
        self.weight_btn.setFixedWidth(300)
        self.weight_btn.clicked.connect(self.choose_weight_file)
        selector_layout.addWidget(self.weight_btn)

        # 图片文件选择器
        image_label = QLabel("选择图片")
        selector_layout.addWidget(image_label)
        self.image_btn = QPushButton("选择图片")
        self.image_btn.setFixedWidth(300)
        self.image_btn.clicked.connect(self.choose_image_file)
        selector_layout.addWidget(self.image_btn)

        # 将选择器行添加到主布局
        layout.addLayout(selector_layout)

        # 推理项目选择行布局
        inference_layout = QHBoxLayout()

        # 推理项目选择
        inference_label = QLabel("选择推理项目")
        inference_layout.addWidget(inference_label)
        self.combo = QComboBox()
        self.combo.setFixedWidth(300)
        self.combo.addItems(['无', '低头', '抬头'])
        inference_layout.addWidget(self.combo)
        hide_label = QLabel(" ")
        inference_layout.addWidget(hide_label)
        infer_btn = QPushButton("推理")
        infer_btn.setFixedWidth(300)
        infer_btn.clicked.connect(self.infer)
        inference_layout.addWidget(infer_btn)

        # 将推理选择行添加到主布局
        layout.addLayout(inference_layout)

        # 日志展示区
        self.log = QTextEdit()
        self.log.setPlaceholderText("等待运行。。。")
        layout.addWidget(self.log)

        self.setLayout(layout)
        self.setWindowTitle('Deep Learning Based Student Status Detection App')
        self.setGeometry(300, 200, 1400, 800)

    def choose_weight_file(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "Select Weight File", "", "PyTorch Model Files (*.pt)")
        if file_name:
            self.selected_weight = file_name  # 设置选中的权重文件路径
            self.log.append(f"Selected weight file: {file_name}")
            display_text = file_name if len(file_name) < 25 else file_name[:22] + '...'
            self.weight_btn.setText(display_text)
        else:
            self.selected_weight = None

    def choose_image_file(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "Select Image File", "", "Image Files (*.png *.jpg)")
        if file_name:
            self.selected_image = file_name  # 设置选中的图片路径
            self.log.append(f"Selected image file: {file_name}")
            display_text = file_name if len(file_name) < 25 else file_name[:22] + '...'
            self.image_btn.setText(display_text)
            # 加载图像
            pixmap = QPixmap(file_name)
            pixmap = pixmap.scaled(700, 400, Qt.KeepAspectRatio, Qt.SmoothTransformation)
            # 显示图像
            self.img_label1.setPixmap(pixmap)
        else:
            self.selected_image = None

    def infer(self):
        if not hasattr(self, 'selected_image') or self.selected_image is None:
            # 弹出提示框告知用户需要选择图片
            QMessageBox.warning(self, "推理错误", "请先选择一张图片再进行推理！", QMessageBox.Ok, QMessageBox.Ok)
            return

        # 检查并删除存在的 result.jpg 文件
        if os.path.exists('result.jpg'):
            os.remove('result.jpg')
            self.log.append("Existing 'result.jpg' has been deleted.")


        if self.combo.currentText() == '无':
            self.log.append("Running inference with no specific task...")
            processor = ImageProcessor('runs/detect/train2/weights/best.pt',savepic=True)
            object_count = processor.detect_objects(self.selected_image)
            self.log.append(f"检测到学生人数：{object_count}")
            detected_date,detected_texts = processor.extract_text(self.selected_image)
            self.log.append(f"检测到班级代码：{detected_texts[0]}")
            if detected_date:
                self.log.append(f"检测时间为：{detected_date}")
            # 检查 result.jpg 是否生成
            if os.path.exists('result.jpg'):
                # 加载生成的图片
                pixmap = QPixmap('result.jpg')
                # 调整图片大小以适应图片框
                pixmap = pixmap.scaled(700, 400, Qt.KeepAspectRatio, Qt.SmoothTransformation)
                # 显示图片
                self.img_label2.setPixmap(pixmap)
            else:
                self.log.append("未能生成结果图片 result.jpg")
        else:
            if not hasattr(self, 'selected_weight') or self.selected_weight is None:
                # 弹出提示框告知用户需要选择权重文件
                QMessageBox.warning(self, "推理错误", "请先选择权重文件再进行推理！", QMessageBox.Ok, QMessageBox.Ok)
            else:
                self.log.append(
                    f"Running inference with task: {self.combo.currentText()} and weight file: {self.selected_weight}")
                processor = ImageProcessor('runs/detect/train2/weights/best.pt')
                object_count = processor.detect_objects(self.selected_image)
                self.log.append(f"检测到学生人数：{object_count}")
                if self.combo.currentText() == '低头':
                    processor2 = ImageProcessor(self.selected_weight,savepic=True)
                    object_count2 = processor2.detect_objects(self.selected_image)
                    self.log.append(f"检测到低头人数：{object_count2}")
                else:
                    processor2 = ImageProcessor(self.selected_weight,savepic=True)
                    object_count2 = processor2.detect_objects(self.selected_image)
                    self.log.append(f"检测到抬头人数：{object_count2}")
                detected_date, detected_texts = processor.extract_text(self.selected_image)
                self.log.append(f"检测到班级代码：{detected_texts[0]}")
                if detected_date:
                    self.log.append(f"检测时间为：{detected_date}")
                # 检查 result.jpg 是否生成
                if os.path.exists('result.jpg'):
                    # 加载生成的图片
                    pixmap = QPixmap('result.jpg')
                    # 调整图片大小以适应图片框
                    pixmap = pixmap.scaled(700, 400, Qt.KeepAspectRatio, Qt.SmoothTransformation)
                    # 显示图片
                    self.img_label2.setPixmap(pixmap)
                else:
                    self.log.append("未能生成结果图片 result.jpg")

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = ImageProcessorApp()
    ex.show()
    sys.exit(app.exec_())
