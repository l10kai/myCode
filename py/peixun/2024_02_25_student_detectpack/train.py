

from ultralytics import YOLO


if __name__ == '__main__':
    # Windows系统下需要加入这段代码
    import multiprocessing
    multiprocessing.freeze_support() 
    # 载入一个模型
    model = YOLO('yolov8n.yaml').load('LOv8n.ptYO')

    # 训练模型
    results = model.train(data='sd.yaml', epochs=1000, imgsz=512,device=[1],save_period=10,batch=32)


