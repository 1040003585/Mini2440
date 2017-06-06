[TOC]

#1用VMware Tools
安装VMware Tools后，Windows系统的文件就可以和虚拟机VMware Ubuntu系统用鼠标直接相互施放，这种方法比较容易安装，就不多讲解。
#2用samba共享Ubuntu目录
##2.1安装samba
在Ubuntu终端输入`sudo apt-get install samba`安装。如果找不到指定的包可能要`sudo apt-get install update`一下。安装好后`ls /etc/init.d/`会有`smbd`。
##2.2编辑samba配置文件
编辑samba配置文件`/etc/samba/smb.conf`，在该文件最后添加：
```
[wu-being]
comment=shared folder with username and password
path=/home/wu-being
public=yes
valid users=wu-being
create mask=0700
writable=yes
directory mask=0700
force user=nobody
force group=nogroup
available=yes
browseable=yes
```
- `[wu-being]`中的`wu-being`：在windows上共享的名称；
- ` path=/home/wu-being `：Ubuntu共享到windows的目录；
- ` valid users=wu-being`：访问共享目录的用户；
- ` force user=nobody`：共享文件的所有者名；
- `force group=nogroup`：共享文件所在的组名；
##2.3添加samba用户
`sudo smbpasswd –a wu-being`
##2.4 在Windows访问共享文件夹
- 右击`我的电脑`，选择`映射网络驱动器`；
- 在映射网络驱动器窗口，选择一个没有用的驱动器盘符，文件夹输入框输入`\\ubuntu的ip\共享名称`，如`\\192.168.1.102\wu-being`；（其中：192.168.1.102即为ubuntu的ip地址（这个IP要和本机IP在同一个网段），wu-being即为ubuntu中samba共享出来的名称。
点“完成”，会跳到登录界面）
- 在登录界面输入samba共享用户和密码。
- 跳出Ubuntu共享目录。

现在就可以任意用鼠标拖放文件了，注意共享目录和共享文件所在组和权限，有时在用`sudo chmod 744 文件名`命令修改共享文件权限，用`sudo chown 用户名:组名 文件名`命令修改文件的所有者和所在组。

#3smb简单方法
##3.1ubuntu控制端设置
1. `sudo smbpasswd -a wuchengbing` 后输入密码.ubuntu passwd ,newpasswd
2. `sudo service smbd restart`
##3.2windows端设置
1. 在文件窗口输入`\\ubuntu的ip`
2. 然后输入用户名的密码。\\wuchengbing newpasswd
#4通过文件中转站连接到Ubuntu
##4.1在windows端设置
- 在中转站服务器（`\\中转站服务器ip\users$`）新建个人目录Wu_Being
- 添加一人网络位置，后面`下一步`两次。
  ![这里写图片描述](http://img.blog.csdn.net/20170605002350440?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
- 下面的在指定网站的位置窗口的Internet地址输入：`\\中转站服务器ip\users$\Wu_Being`
- 在下一步的的网络名称输入在Windows显示的名称，如`Wu_Being-Ubuntu`。
- 然后下一步就完成。在`我的电脑`下面的网络位置就有了`Wu_Being-Ubuntu`。
  ![这里写图片描述](http://img.blog.csdn.net/20170605002653803?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
##4.2ubuntu控制端设置
 ![这里写图片描述](http://img.blog.csdn.net/20170605002917209?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 ![这里写图片描述](http://img.blog.csdn.net/20170605002957631?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#5SSH
##5.1ubuntu控制端设置
要在XP上通过命令控制ubuntu，必须在ubuntu上安装ssh服务。
`sudo apt-get install openssh-server` 
如果在安装ssh时失败，其原因是没有更新源。所以需要`sudo apt-get update`
（安装ssh客户端有时是有必要的`sudo apt-get install ssh` ）
用scp进行文件远程复制：`scp somy_file root@192.168.1.254:/home/wu_being/`

 ![这里写图片描述](http://img.blog.csdn.net/20170605003126403?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
	选择Y即可安装，安装完后将会在`/etc/init.d`目录生成`ssh`可执行文件。
 
##5.2windows端设置
 ![这里写图片描述](http://img.blog.csdn.net/20170605003234710?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 
如果出现下面界面，则说明可以连上ubuntu的ssh.

![这里写图片描述](http://img.blog.csdn.net/20170605003426938?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 

即登录ubuntu的用户帐号。
Xp通过SecureCRT 6.0登录ubuntu效果
![这里写图片描述](http://img.blog.csdn.net/20170605003553930?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 
这样命令通道就打开了，大大方便了今后xp与ubuntu的协同开发。
#6附：ubuntu软件安装原理
Ubuntu中是通过apt(一个软件包管理工具)来实现的，你只需告诉apt你想要安装的工具，它自动会为你安装，那么这是怎么实现的呢？apt有一个源列表，这个源列表存放的是ubuntu的一些服务器网址，这些服务器上保存着ubuntu的很多软件。

 ![这里写图片描述](http://img.blog.csdn.net/20170605003628503?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

而这些源列表不可能保持着最新状态，所以有些软件就找不到，因此我们常需要更新源列表。


**Wu_Being 博客声明**：本人博客欢迎转载，请标明博客原文和原链接！谢谢！
 《虚拟机VMware Ubuntu系统与Windows文件共享的各种方法》
http://blog.csdn.net/u014134180/article/details/72863252 

![Wu_Being 吴兵博客接受赞助费二维码](http://img.blog.csdn.net/20170305211231929?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 

如果你看完这篇博文，觉得对你有帮助，并且愿意付赞助费，那么我会更有动力写下去。
