import os
from datetime import datetime

# 源 cpp 文件目录
cpp_dir = r"E:\cppgit\我的板子"
# 目标 md 文件目录
md_dir = r"E:\blog\source\_posts"

# 如果目标目录不存在，创建目录
if not os.path.exists(md_dir):
    os.makedirs(md_dir)

for root, dirs, files in os.walk(cpp_dir):
    for file in files:
        if file.endswith(".cpp"):
            cpp_file_path = os.path.join(root, file)
            file_name = os.path.splitext(file)[0]
            md_file_path = os.path.join(md_dir, f"{file_name}.md")

            # 读取 cpp 文件内容
            with open(cpp_file_path, "r", encoding="utf-8") as cpp_file:
                cpp_content = cpp_file.read()

            # 获取当前日期和时间
            current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            # 生成md文件内容
            md_content = f"""---
title: {file_name}
date: {current_time}
tags: {file_name}
categories:
- 算法竞赛
- 模板类
---

```cpp
{cpp_content}
```
"""

            # 写入 md 文件
            with open(md_file_path, "w", encoding="utf-8") as md_file:
                md_file.write(md_content)

            print(f"{file_name}.md 生成成功！")
