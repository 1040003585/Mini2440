[toc]
#1环境搭建所需材料
- Linux 内核代码
- 编译器
- 文件系统
- samba
- tftp
- SecureCRT6.0
- 开发板uboot
- nfs-kernel-server
 
#2环境搭建所需材料之间的关系
 ![这里写图片描述](http://img.blog.csdn.net/20170606005914146?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#3所使用的开发板
 ![这里写图片描述](http://img.blog.csdn.net/20170606010030864?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#4译内核
  ![这里写图片描述](http://img.blog.csdn.net/20170606010232146?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
##4.1修改makefile
 ![这里写图片描述](http://img.blog.csdn.net/20170606010352271?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
##4.2拷贝配置文件
 ![这里写图片描述](http://img.blog.csdn.net/20170606010433934?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
##4.3编译得到zImage
![这里写图片描述](http://img.blog.csdn.net/20170606010655336?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
##4.4把zImage转成uImage
 ![这里写图片描述](http://img.blog.csdn.net/20170606010834846?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#5开发板串口连接
串口形状 ,在电脑上映射出来的串口设备连接串口
 ![这里写图片描述](http://img.blog.csdn.net/20170606012129912?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 ![这里写图片描述](http://img.blog.csdn.net/20170606012238085?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
![这里写图片描述](http://img.blog.csdn.net/20170606012209397?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
到0回车。。。
#6uboot设置
 ![这里写图片描述](http://img.blog.csdn.net/20170606012322524?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 ![这里写图片描述](http://img.blog.csdn.net/20170606012330446?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#7通过tftp服务器下载uImage
 ![这里写图片描述](http://img.blog.csdn.net/20170606012340149?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 ![这里写图片描述](http://img.blog.csdn.net/20170606012357524?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#8启动内核
![这里写图片描述](http://img.blog.csdn.net/20170606012538745?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
这时启动内核后还不会进入文件系统
#9先看挂载文件系统的样子
先看现象：挂载成功，启动板子，再tftp下载
![这里写图片描述](http://img.blog.csdn.net/20170606012615221?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#10下面正式来操作
##10.1安装nfs-kernel-server
![这里写图片描述](http://img.blog.csdn.net/20170606012858280?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
##10.2配置网络文件系统
 ![这里写图片描述](http://img.blog.csdn.net/20170606012910999?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
##10.3配置内核里面的nfs选项
`make menuconfig`
![这里写图片描述](http://img.blog.csdn.net/20170606012929859?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#11配置开发板的启动参数
   ![这里写图片描述](http://img.blog.csdn.net/20170606013027485?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 ![这里写图片描述](http://img.blog.csdn.net/20170606013042329?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#12注意（总结）
- 64位Ubuntu 编译linux源码arm-linux-gcc问题

好像要下载个软件
吴兵(1040003585) 2017-5-16 14:36:59
make出问题
韩滔(1198637117) 2017-5-16 14:37:50
你用的vm和Ubuntu什么版本
****吴兵(1040003585) 2017-5-16 14:39:19
**ubuntu 64位**
程老师(1209050967) 2017-5-16 14:43:25
**但arm编译器是32位******
韩滔(1198637117) 2017-5-16 14:45:08
 **sudo apt-get install lsb-core** 
 
吴兵(1040003585) 2017-5-16 14:57:27

吴兵(1040003585) 2017-5-16 16:32:38
**板子网线是连接和电脑同一个网段的路由器**
吴兵(1040003585) 2017-5-16 17:00:03
tftp
吴兵(1040003585) 2017-5-16 17:01:58
搞定


- bootm之后就卡在这里——两个782改为1999

![这里写图片描述](http://img.blog.csdn.net/20170606013437615?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 
**参考文档，把782改成1999即可**@吴兵 
吴兵(1040003585) 2017-5-16 17:43:40
ok
吴兵(1040003585) 2017-5-16 17:52:45
@张奥华 两个782都要改吗？
这是什么道理
张奥华(434638973) 2017-5-16 17:52:57
是的
改成1999
**mach type不匹配**
程老师(1209050967) 2017-5-16 17:53:39
**uboot引导的内核需要与其机器类型一致**
![这里写图片描述](http://img.blog.csdn.net/20170606013612444?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 ![这里写图片描述](http://img.blog.csdn.net/20170606013627648?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 ![这里写图片描述](http://img.blog.csdn.net/20170606013635898?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 
 - 设置bootargs （文件系统路径）
 
setenv bootargs noinitrd root=/dev/nfs rw nfsroot= 172.16.245.93:/home/wuchengbing/linux/root_nfs ip= 172.16.245.254:172.16.245.93: 172.16.245.1:255.255.255.0 console=ttySAC0,115200 init=/linuxrc mem=64M 

文件系统IP：172.16.245.93
板子IP：172.16.245.254
网关：172.16.245.1
掩码：255.255.255.0

- bootm能不能成功挂载文件系统


@张奥华 搞定，重启远程文件系统
**/etc/init.d/nfs-kernel-server restart**
吴兵(1040003585) 2017-5-16 18:59:05
  
#附录

工具下载链接： 
https://github.com/1040003585/Mini2440/tree/master/Tools
 
 


**Wu_Being 博客声明**：本人博客欢迎转载，请标明博客原文和原链接！谢谢！ 
《【ARM】一步一步移植Linux Kernel 2.6.13到板子》
http://blog.csdn.net/u014134180/article/details/72873397

![Wu_Being 吴兵博客接受赞助费二维码](http://img.blog.csdn.net/20170305211231929?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


如果你看完这篇博文，觉得对你有帮助，并且愿意付赞助费，那么我会更有动力写下去。
