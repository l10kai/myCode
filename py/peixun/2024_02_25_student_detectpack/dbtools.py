import sqlite3

# 连接到 SQLite 数据库
# 如果数据库不存在，将会自动创建一个数据库文件
conn = sqlite3.connect('classroom_monitoring.db')

# 创建一个 Cursor 对象并通过它执行 SQL 语句
c = conn.cursor()

# 创建表
c.execute('''
CREATE TABLE IF NOT EXISTS monitoring_data (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    filename TEXT,
    object_count INTEGER,
    detected_date TEXT,
    classroom_name TEXT,
    head_up_count INTEGER,
    attendance_rate REAL,
    head_down_rate REAL
)
''')

# 提交事务
conn.commit()

# 关闭连接
conn.close()
