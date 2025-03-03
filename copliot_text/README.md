# 牛客网Rating爬虫

这是一个用于获取牛客网用户Rating信息的爬虫程序。

## 功能特点

- 获取用户基本信息（用户名、当前Rating、排名、段位）
- 获取用户Rating历史记录
- 支持登录认证，解决API访问限制问题
- 随机延迟请求，减少被反爬拦截概率
- 详细日志记录

## 使用方法

### 直接运行

```bash
python nowcoder_rating_crawler.py
```

然后按照提示输入用户ID，如果需要登录，还需要输入账号密码。

### 指定用户ID

```bash
python nowcoder_rating_crawler.py 用户ID
```

例如：

```bash
python nowcoder_rating_crawler.py 710089126
```

## 注意事项

1. 牛客网可能会限制API访问，需要登录才能获取数据
2. 请勿频繁使用，以免对牛客网服务器造成负担
3. 本程序仅供学习和个人使用，请勿用于商业目的
4. 请遵守牛客网的用户协议和网站规定

## 日志

程序会生成`nowcoder_crawler.log`日志文件，记录运行状态和错误信息。
