import json

# # 使用json.load从文件中加载JSON数据
# with open('dataset/labels/test0.json', 'r', encoding='utf-8') as file:
#     data = json.load(file)
#
# # 提取所有的label
# labels = [shape['label'] for shape in data['shapes']]
#
# # 使用集合找出唯一的label
# unique_labels = set(labels)
#
# # 计算有多少种不同的label
# num_unique_labels = len(unique_labels)
#
# print(f"共有 {num_unique_labels} 种不同的label，分别是: {unique_labels}")

import matplotlib.pyplot as plt
from PIL import Image, ImageDraw, ImageFont

def draw_labels(img_path, label_path, class_names):
    # 读取图片
    image = Image.open(img_path)
    draw = ImageDraw.Draw(image)
    img_width, img_height = image.size

    # 读取标注
    with open(label_path, 'r') as file:
        for line in file:
            parts = line.strip().split()
            class_id, x_center, y_center, width, height = map(float, parts)

            # 转换归一化坐标到图像坐标
            x_center *= img_width
            y_center *= img_height
            width *= img_width
            height *= img_height

            # 计算边框坐标
            left = x_center - width / 2
            top = y_center - height / 2
            right = x_center + width / 2
            bottom = y_center + height / 2

            # 绘制边框和标签
            try:
                draw.rectangle([left, top, right, bottom], outline='red', width=2)
            except:
                print([left, top, right, bottom])
            draw.text((left, top), class_names[int(class_id)], fill='yellow')

    # 显示结果
    plt.imshow(image)
    plt.axis('off')
    plt.show()

# 图片和标注文件路径
img_path = 'dataset2/images/train/test156.png'
label_path = 'dataset2/labels/train/test156.txt'

# 类别名称列表，与YOLO标注中的类别ID相对应
class_names = ['people', 'empty']

# 调用函数绘制标注
draw_labels(img_path, label_path, class_names)