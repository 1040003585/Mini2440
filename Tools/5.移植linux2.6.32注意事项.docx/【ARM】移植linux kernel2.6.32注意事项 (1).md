[TOC]
#三个文件
程老师(1209050967) 19:05:41
**链接：http://pan.baidu.com/s/1pLg8V8J 密码：xu5r**
程老师(1209050967) 19:06:03
 
程老师(1209050967) 19:06:31
各位到我网盘把这个三个文件下下来放到你们的ubuntu里面
**（gcc4.4.3, linux-2.6.32, roots_rtm_2440）**

**加sudo 解压后才有/rootfs/dev/console这个文件**
sudo tar –zxvf root…
/rootfs/dev/**console**

#arm-linux-gcc –v
**export PATH=$PATH:/home/wuchengbing/linux/…gcc4.4.3**的路径/bin
输入arm-linux-gcc –v查看gcc版本


#注意权限问题
sudo chown wuchengbing:wuchengbing *
sudo chmod 744 *


cp ***.n35 .config
make

#boorargs参数
boorargs参数设置
```
setenv ipaddr 192.168.1.244
setenv serverip 192.168.1.2
setenv gatewayip 192.168.1.1
setenv bootargs noinitrd root=/dev/nfs rw nfsroot=192.168.1.4:/home/wu-being/linux/2.6.32/rootfs_rtm_2440 ip=192.168.1.244:192.168.1.4:192.168.1.1:255.255.255.0 console=ttySAC0,115200 init=/linuxrc mem=64M 
setenv bootcmd "tftp 32000000 uimage;bootm"
```
#mkimage
原来是目录缺少mkimage这个程序，添加进去就好了
`tftp 32000000 uiamge`
![这里写图片描述](http://img.blog.csdn.net/20170606124941552?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 

程老师(1209050967) 21:15:26
吴盛宇说的bdinfo命令
#-lm 数学库
吴盛宇(113443584) 21:39:11
**-lm 数学库要带进去**
杨帆(1262255026) 21:39:18
哦哦

#/etc/exports
@韩滔 把/etc/exports配置一下就好 
**/etc/init.c/nfs-server*… restart**
 ![这里写图片描述](http://img.blog.csdn.net/20170606125025957?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#dev下没有fb/0
**dev下没有fb/0,代码里多写了一个/吧，改为`/dev/fb0`**
会报错的 
![这里写图片描述](http://img.blog.csdn.net/20170606125049585?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

#drawtree函数
主程序有什么要改的吗
邱炎盛(1335204457) 2017-5-26 23:15:08
加上drawtree函数
徐权(1404497589) 2017-5-26 23:17:18 
![这里写图片描述](http://img.blog.csdn.net/20170606125133927?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#隐约有颗树
有人出现这种情况吗？隐约有颗树
吴盛宇(113443584) 2017-5-27 10:04:43
系统启动的时候陌生启动了一个app，把它kill掉先
ps查下
杨帆(1262255026)  
![这里写图片描述](http://img.blog.csdn.net/20170606125236990?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#搞定！！！
![这里写图片描述](http://img.blog.csdn.net/20170606125343557?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

#附录

工具下载链接： 
https://github.com/1040003585/Mini2440/tree/master/Tools
 
 


**Wu_Being 博客声明**：本人博客欢迎转载，请标明博客原文和原链接！谢谢！ 
《【ARM】移植linux kernel2.6.32注意事项》
http://blog.csdn.net/u014134180/article/details/72877048

![Wu_Being 吴兵博客接受赞助费二维码](http://img.blog.csdn.net/20170305211231929?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


如果你看完这篇博文，觉得对你有帮助，并且愿意付赞助费，那么我会更有动力写下去。
