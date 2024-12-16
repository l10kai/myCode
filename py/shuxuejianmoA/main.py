# 导入所需的库
import numpy as np
import matplotlib.pyplot as plt

# 定义GM(1,1)类
class GM11:
    def __init__(self):
        self.a = 0  # 灰色作准指数
        self.b = 0  # 灰色作准常数
        self.X0 = None  # 初始数据序列
        self.X_cum = None  # 累加数据序列

    def fit(self, X):
        self.X0 = X
        n = len(X)
        self.X_cum = np.cumsum(X)  # 累加生成数列
        Z = 0.5 * (self.X_cum[:-1] + self.X_cum[1:])  # 紧邻均值生成数列
        B = np.vstack((-Z, np.ones(n - 1))).T
        Y = X[1:]
        U = np.dot(B.T, B)
        self.a, self.b = np.dot(np.linalg.inv(U), np.dot(B.T, Y))  # 最小二乘估计参数

    def predict(self, n):
        # 预测n个数据点
        X_pred = np.zeros(n)
        X_pred[0] = self.X0[0]

        for i in range(1, n):
        # 具体代码见数模百科

        # 将累加预测数据进行还原
        X_pred_restored = np.zeros(n)
        X_pred_restored[0] = X_pred[0]
        for i in range(1, n):
            X_pred_restored[i] = X_pred[i] - X_pred[i - 1]

        return X_pred_restored

# 生成示例数据
X = np.array([20, 25, 30, 35, 40, 45])

# 创建GM(1,1)模型实例
model = GM11()
model.fit(X)

# 预测未来的数据
m = 3  # 预测未来3个数据点
X_pred_future = model.predict(len(X) + m)[len(X):]

# 绘制原始数据和预测数据
plt.plot(range(len(X)), X, 'o-', label='Original')
plt.plot(range(len(X), len(X) + m), X_pred_future, 'x--', label='Future Prediction')
plt.legend()
plt.show()