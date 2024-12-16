---
title: 云服务器配置frp（基础篇）
date: 2024-12-04 13:09:35
tags: frp
categories:
- 服务器
---
# 云服务器配置frp（基础篇）

本文基于debian11.3系统，云服务器为阿里云轻量应用服务器。该基础篇仅介绍frp服务基本配置，不涉及具体应用场景。



以下所有代码默认以root身份执行



我们选择在 `\opt\frp`文件夹下部署frp服务，如没有文件夹请提前用`mkdir`命令创建

## 下载frp压缩包

通过`cd \opt\frp `定位到该文件夹，使用`\wget https://github.com/fatedier/frp/releases/download/v0.xx.x/frp_0.xx.x_linux_amd64.tar.gz tar -zxvf frp_0.xx.x_linux_amd64.tar.gz`命令下载frp安装包，注意`v0.xx.x`应严格换成所需版本，本文中 笔者使用的是`0.61.0`版本，命令即为`wget https://github.com/fatedier/frp/releases/download/v0.61.0/frp_0.61.0_linux_amd64.tar.gz `

## 解压缩

执行解压缩命令`tar -zxvf frp_0.61.0_linux_amd64.tar.gz`

在当前目录下会出现一个`frp_0.61.0_linux_amd64`文件夹

文件夹中包含`frpc  frpc.toml  frps  frps.toml  LICENSE`等四个文件

注意：在较新版本中，已经没有`frps.init`文件，取而代之的是`frpc.toml`文件

## 修改配置文件

使用nano 或 vim命令对`frpc.toml`文件稍作修改，参考：

```toml
# 服务端口
bindPort = 7000

# Dashboard 配置
webServer.addr = "0.0.0.0"
webServer.port = 7001
webServer.user = "admin"
webServer.password = "password"

```

## 开放端口

在阿里云服务器中，我们只需在服务器控制台中添加规则即可。

在上面的配置中，我们使用了 `7000`和`7001`端口，分别添加规则即可

应用类型 为自定义，协议为TCP, 来源为0.0.0.0 都用默认设置即可，自行设置端口范围和备注。



## 启动服务

此时，输入`frps -c frps.toml `即可启动服务

任选设备在浏览器中输入`x.x.x.x:7001`，出现如下图页面即为服务开放成功，其中，`x.x.x.x`为您的服务器公网ip



## 配置Systemd管理服务

我们发现输入`frps -c frps.toml `过于繁琐，且不方便查看服务状态

可以执行`nano \etc\systemd\system\frps.service` 在`\etc\systemd\system\`文件夹中创建`frps.service`文件，写入以下内容：
```toml
[Unit]
# 服务名称
Description = frp server
After = network.target syslog.target
Wants = network.target

[Service]
Type = simple
# 启动frps
ExecStart = /opt/frp/frp_0.61.0_linux_amd64/frps -c /opt/frp/frp_0.61.0_linux_amd64/frps.toml

[Install]
WantedBy = multi-user.target

```

其中，`ExecStart = /.../x/frps -c /.../x/frps.toml`这一行`/.../x/`所对应的应为您frps文件和frps.toml文件所对应的地址。



现在我们可以方便的管理服务了：

```bash
systemctl status frps
#服务状态
systemctl start frps
#启动服务
systemctl stop frps
#停止服务
systemctl enable frps
#设置开机自启
```

