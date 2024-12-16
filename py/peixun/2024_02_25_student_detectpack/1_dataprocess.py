import os
import shutil
import random

def create_dataset_folders(base_path):
    for folder in ['train', 'val', 'test']:
        os.makedirs(os.path.join(base_path, 'images', folder), exist_ok=True)
        os.makedirs(os.path.join(base_path, 'labels', folder), exist_ok=True)

def distribute_files(file_path, target_base_path, subset, category):
    target_path = os.path.join(target_base_path, category, subset, os.path.basename(file_path))
    shutil.copy(file_path, target_path)

def process_dataset_folder(imgs_path, labels_path, dataset2_path):
    create_dataset_folders(dataset2_path)

    # Get all image files
    images = [f for f in os.listdir(imgs_path) if os.path.isfile(os.path.join(imgs_path, f)) and not f.lower().endswith('.json')]
    random.shuffle(images)

    # Determine split sizes
    total = len(images)
    train_split = int(total * 0.7)
    val_split = int(total * 0.9)

    for i, image_name in enumerate(images):
        if i < train_split:
            subset = 'train'
        elif i < val_split:
            subset = 'val'
        else:
            subset = 'test'

        image_path = os.path.join(imgs_path, image_name)
        distribute_files(image_path, dataset2_path, subset, 'images')

        # Assuming label file names match image file names except extension
        label_name = os.path.splitext(image_name)[0] + '.txt'
        label_path = os.path.join(labels_path, label_name)
        if os.path.exists(label_path):
            distribute_files(label_path, dataset2_path, subset, 'labels')

# 使用示例
imgs_path = './datasetraw-onlylowerhead/imgs'  # 图片文件夹的路径
labels_path = './datasetraw-onlylowerhead/labels'  # 标签文件夹的路径
dataset2_path = './dataset-onlylowerhead'  # 目标文件夹的路径

process_dataset_folder(imgs_path, labels_path, dataset2_path)
