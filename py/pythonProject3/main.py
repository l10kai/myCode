import tkinter as tk
from tkinter import messagebox
import sqlite3
import datetime
import pymc3 as pm
import numpy as np


# 创建或连接数据库
conn = sqlite3.connect('diagnosis_system.db')
c = conn.cursor()

# 创建users表和diagnosis_history表（如果不存在）
c.execute('''
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY,
        username TEXT UNIQUE,
        password TEXT,
        email TEXT
    )
''')

c.execute('''
    CREATE TABLE IF NOT EXISTS diagnosis_history (
        id INTEGER PRIMARY KEY,
        user_id INTEGER,
        timestamp TEXT,
        symptoms TEXT,
        diagnosed_disease TEXT,
        probabilities TEXT,
        FOREIGN KEY (user_id) REFERENCES users(id)
    )
''')

conn.commit()

class DiseaseDiagnosisApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Disease Diagnosis System")

        # 登录相关变量
        self.logged_in_user = None

        # 登录界面
        self.login_frame = tk.Frame(root)
        self.login_frame.pack(pady=20)

        tk.Label(self.login_frame, text="Username:").grid(row=0, column=0)
        self.username_entry = tk.Entry(self.login_frame)
        self.username_entry.grid(row=0, column=1)

        tk.Label(self.login_frame, text="Password:").grid(row=1, column=0)
        self.password_entry = tk.Entry(self.login_frame, show="*")
        self.password_entry.grid(row=1, column=1)

        tk.Button(self.login_frame, text="Login", command=self.login).grid(row=2, columnspan=2, pady=10)

        tk.Button(self.login_frame, text="Register", command=self.register).grid(row=3, columnspan=2)

        # 主功能界面（需要登录后显示）
        self.main_frame = None

    def login(self):
        username = self.username_entry.get()
        password = self.password_entry.get()

        c.execute('SELECT * FROM users WHERE username=? AND password=?', (username, password))
        user = c.fetchone()

        if user:
            self.logged_in_user = user
            self.show_main_window()
        else:
            messagebox.showerror("Login Failed", "Invalid username or password")

    def register(self):
        # 界面清空
        self.username_entry.delete(0, tk.END)
        self.password_entry.delete(0, tk.END)

        # 新建注册窗口
        register_window = tk.Toplevel(self.root)
        register_window.title("Register")

        tk.Label(register_window, text="Username:").grid(row=0, column=0)
        username_entry = tk.Entry(register_window)
        username_entry.grid(row=0, column=1)

        tk.Label(register_window, text="Password:").grid(row=1, column=0)
        password_entry = tk.Entry(register_window, show="*")
        password_entry.grid(row=1, column=1)

        tk.Label(register_window, text="Email:").grid(row=2, column=0)
        email_entry = tk.Entry(register_window)
        email_entry.grid(row=2, column=1)

        def register_user():
            username = username_entry.get()
            password = password_entry.get()
            email = email_entry.get()

            if username and password and email:
                try:
                    c.execute('INSERT INTO users (username, password, email) VALUES (?, ?, ?)', (username, password, email))
                    conn.commit()
                    messagebox.showinfo("Success", "Registration successful. You can now login.")
                    register_window.destroy()
                except sqlite3.IntegrityError:
                    messagebox.showerror("Error", "Username already exists. Please choose another username.")
            else:
                messagebox.showerror("Error", "Please fill in all fields.")

        tk.Button(register_window, text="Register", command=register_user).grid(row=3, columnspan=2, pady=10)

    def show_main_window(self):
        if self.main_frame:
            self.main_frame.destroy()

        self.main_frame = tk.Frame(self.root)
        self.main_frame.pack(padx=20, pady=20)

        tk.Label(self.main_frame, text=f"Welcome, {self.logged_in_user[1]}!").pack()

        # 症状输入界面
        self.symptoms_frame = tk.LabelFrame(self.main_frame, text="Symptom Input")
        self.symptoms_frame.pack(pady=10)

        tk.Label(self.symptoms_frame, text="Select Symptoms:").grid(row=0, column=0, sticky=tk.W)

        self.symptom_vars = []
        symptoms = ["Fever", "Cough", "Headache", "Fatigue"]
        for i, symptom in enumerate(symptoms):
            var = tk.IntVar()
            tk.Checkbutton(self.symptoms_frame, text=symptom, variable=var).grid(row=i+1, column=0, sticky=tk.W)
            self.symptom_vars.append(var)

        tk.Button(self.symptoms_frame, text="Diagnose", command=self.diagnose).grid(row=len(symptoms)+1, columnspan=2, pady=10)

    def diagnose(self):
        selected_symptoms = [var.get() for var in self.symptom_vars]

        symptom_data = np.array([selected_symptoms])

        with pm.Model() as model:
            # 定义疾病的先验概率
            disease_prior = pm.Bernoulli('disease_prior', 0.5, shape=2)  # D1, D2

            # 定义症状给定疾病的条件概率
            p_symptom_given_disease = pm.Deterministic('p_symptom_given_disease',
                                                       pm.math.stack([
                                                           [0.9, 0.1],  # S1 given D1, D2
                                                           [0.2, 0.8]   # S2 given D1, D2
                                                       ]))

            # 定义观察数据
            symptoms = pm.Bernoulli('symptoms', p_symptom_given_disease[disease_prior], observed=symptom_data)

            # 运行推断
            trace = pm.sample(1000, return_inferencedata=False)

        # 获取后验分布
        posterior_prob = np.mean(trace['disease_prior'], axis=0)

        # 显示诊断结果
        if posterior_prob[0] > posterior_prob[1]:
            diagnosed_disease = "Disease 1"
        else:
            diagnosed_disease = "Disease 2"

        # 保存诊断历史
        timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        symptoms_str = ", ".join([symptoms[i] for i in range(len(symptoms)) if selected_symptoms[i]])
        probabilities_str = f"Disease 1: {posterior_prob[0]:.2f}, Disease 2: {posterior_prob[1]:.2f}"

        c.execute('INSERT INTO diagnosis_history (user_id, timestamp, symptoms, diagnosed_disease, probabilities) VALUES (?, ?, ?, ?, ?)',
                  (self.logged_in_user[0], timestamp, symptoms_str, diagnosed_disease, probabilities_str))
        conn.commit()

        # 显示结果窗口
        self.show_result_window(diagnosed_disease, probabilities_str)

    def show_result_window(self, diagnosed_disease, probabilities_str):
        result_window = tk.Toplevel(self.root)
        result_window.title("Diagnosis Result")

        tk.Label(result_window, text="Diagnosis Result", font=("Helvetica", 16, "bold")).pack(pady=10)

        tk.Label(result_window, text=f"Diagnosed Disease: {diagnosed_disease}").pack()
        tk.Label(result_window, text=f"Probabilities: {probabilities_str}").pack()

        # 显示历史记录按钮
        tk.Button(result_window, text="View History", command=self.show_history).pack(pady=10)

    def show_history(self):
        history_window = tk.Toplevel(self.root)
        history_window.title("Diagnosis History")

        tk.Label(history_window, text="Diagnosis History", font=("Helvetica", 16, "bold")).pack(pady=10)

        # 查询用户的诊断历史记录
        c.execute('SELECT * FROM diagnosis_history WHERE user_id=? ORDER BY timestamp DESC', (self.logged_in_user[0],))
        history_entries = c.fetchall()

        if not history_entries:
            tk.Label(history_window, text="No history found.").pack(pady=10)
        else:
            for entry in history_entries:
                tk.Label(history_window, text=f"Timestamp: {entry[2]}").pack()
                tk.Label(history_window, text=f"Symptoms: {entry[3]}").pack()
                tk.Label(history_window, text=f"Diagnosed Disease: {entry[4]}").pack()
                tk.Label(history_window, text=f"Probabilities: {entry[5]}").pack()
                tk.Label(history_window, text="-----------------------------------").pack()

# 创建主窗口并运行应用
if __name__ == "__main__":
    root = tk.Tk()
    app = DiseaseDiagnosisApp(root)
    root.mainloop()

# 关闭数据库连接
conn.close()

