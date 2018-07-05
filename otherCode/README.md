用到的工具： mysql数据库   线程库  

实现功能：

1.好友管理：

(1)添加好友

(2)删除好友

2.群管理

(1)创建群

(2)加群

(3)退群

(4)解散群

3.文件传送

  实现了上传和下载的断点续传

4.聊天界面分屏

  利用光标的移动对输入和屏幕聊天记录输出的分屏

5.MD5加密 

  利用MD5算法，对用户的密码进行加密，对原来的MD5加密进稍微的改动，把字符串类型加密到unsigned int 类型

6.离线传输 

  对私聊,群聊，传送文件都添加了离线功能，对方上线即时传送

7.即时状态显示

  好友列表会及时更新，并用彩色显示当前好友的状态

8.数据库

  利用mysql C语言的API函数，应用mysql数据库对聊天记录进行存储，保证聊天记录的有效性

9.多路复用

  epoll实现服务端的多路复用，保证服务端连接客户端数据的稳定性

10.容错处理

  对于输入内容进行判别，防止在不正规的操作下程序崩溃。

  运行所需环境：

1.mysql数据库安装

并且在数据库内有对应的Database 和 Table

安装数据库(unbuntu)：
```
sudo apt-get install mysql-server mysql-client // 安装数据库
sudo apt-get instal libmysqlclient-dev       //安装数据库的包  C语言 API
```
以root用户登陆数据库，并执行以下代码：
```
CREATE DATABASE happychat;
use happychat
CREATE TABLE message_tbl(send_name varchar(1024),recv_name varchar(1024),mes varchar(2048),time varchar (1024));

```