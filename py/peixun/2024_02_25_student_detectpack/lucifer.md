# 校园智能监控系统

## 数据集准备
1. 首先将你打标的原始数据集放入项目文件夹下
2. 当前项目文件夹中 以datasetraw开头的都是原始数据集，原始数据集需要经过转换和拆分处理才能进网络训练
3. 目前已处理好的有 datasetraw-student&table 包含所有人头和桌子的数据集，datasetraw-onlyuphead 仅包含抬头数据，datasetraw-onlystudent 仅包含所有人头，datasetraw-onlylowerhead 仅包含低头数据
4. 原始数据集中 包含了png和json 两种文件，需要手动新建imgs文件夹和labels文件夹，将图片和标签各自放入文件夹中
5. 完成上述步骤后运行 0_json2text.py(运行前需要将第49行文件路径改为你刚刚处理好的原始数据集路径\labels)
6. 默认的people标签值是0，table标签值是1，但是你标注的时候 一会儿up 一会儿down或者其他的， 会导致第四步运行结束后生成的txt文件 里面的标签都是-1
7. 如果发生步骤5 所述情况请手动find and replace 将标签替换为正确标签，-1的话 训练时会报错
8. 标签字典在0_json2text的第五行，请根据你自己在打标文件中设置的label来修改字典，务必在标签字典中包含你所有的打标label

## 训练集生成
1. 完成数据集准备，确认label都无误后，修改1_dataprocess.py中44，45 两行，将路径改为你刚刚处理好的datasetraw-xxxxx路径下的imgs和labels
2. 将46行改为dataset-你自定义的训练集名字， 请注意 目前所有dataset开头的都是我生成好的训练集
3. 目前已处理好的有 dataset-student&table 包含所有人头和桌子的数据集，dataset-onlyuphead 仅包含抬头数据，dataset-onlystudent 仅包含所有人头，dataset-onlylowerhead 仅包含低头数据
4. 运行完 1_dataprocess.py 后会生成一个 dataset-你自定义的训练集名字 文件夹，里面的images和labels文件夹会自动按7：2：1的比例将数据拆分为train：val：test

## 训练
1. 然后修改sd.yaml 只需要需改第二行 将path改为你新生成的dataset的路径
2. 如果在第一步中对标签字典进行了修改，那么需要修改8行之后的names，告诉系统 哪个数字对应什么label
3. 然后直接运行 train.py
4. 等待代码运行完毕，会在runs/detect中生成新的文件夹，新文件夹就是本次训练结果
5. 当前runs中 train 是人头+桌子 train2 是仅人头 train4是仅抬头 train5 仅低头

## 推理
1. 运行predict.py， 已经写好了类只需要修改26行，选择你要使用的权重（人+桌，纯人头，纯低头，纯抬头）然后在32行，37行修改你要推理的图片路径
2. 推理完后会输出result.jpg,和相应信息

## GUI
1. pyqt写的，可以选检测低头和抬头，默认会检测总人头数和教室编号并输出
2. 点击推理时 首先检测是否选择了一张要推理的图片，如果没有就弹框警告，选了图片就会在左边显示
3. 然后这时候就可以推理了，这时候只检测总人数，和教室代码
4. 然后如果要推理低头或这抬头必须选择一个权重文件，这个权重就是train4 train5这种我们训练来专门识别低头或者抬头姿态的权重
5. 在选择了低头或抬头后，再进行推理，会输出总人头数，教室代码和低头或抬头的人数，现在不太准因为你数据太少了

## 总结
到这一步应用就做完了

# 好好好 还得做网页
