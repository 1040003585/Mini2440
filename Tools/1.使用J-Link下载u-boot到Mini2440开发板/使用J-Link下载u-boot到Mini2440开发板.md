[TOC]

#1各种引导系统介绍
##1.1 bios[^bios]
**BIOS**是英文"Basic Input Output System"的缩略语，直译过来后中文名称就是"基本输入输出系统"。其实，它是一组固化到计算机内主板上一个ROM芯片上的程序，它保存着计算机最重要的基本输入输出的程序、系统设置信息、开机后自检程序和系统自启动程序。 其主要功能是为计算机提供最底层的、最直接的硬件设置和控制。
##1.2 Grub[^grub_u-boot]
**GNU GRUB**（GRand Unified Bootloader简称“GRUB”）是一个来自GNU项目的多操作系统启动程序。GRUB是多启动规范的实现，它允许用户可以在计算机内同时拥有多个操作系统，并在计算机启动时选择希望运行的操作系统。GRUB可用于选择操作系统分区上的不同内核，也可用于向这些内核传递启动参数。可用来用来引导不同系统，如windows，linux，通常用于linux，毕竟是GNU的嘛。
     Windows也有类似的工具**NTLOADER**；比如我们在机器中安装了Windows 98后，我们再安装一个Windows XP ，在机器启动的会有一个菜单让我们选择进入是进入Windows 98 还是进入Windows XP。NTLOADER就是一个多系统启动引导管理器，NTLOADER 同样也能引导Linux，只是极为麻烦罢了。
      **bootmgr**：启动管理器。Bootmgr是Boot Manager的缩写，是在Windows Vista、Windows 7、windows 8/8.1和windows 10中使用的新的启动管理器，以代替Windows NT系列操作系统（Windows XP、Windows 2003）中的启动管理器——NTLDR。
##1.3 u-boot
**U-Boot**，全称为Universal Boot Loader，即通用Bootloader，是遵循GPL条款的开放源代码项目。其前身是由德国DENX软件工程中心的Wolfgang Denk基于8xxROM的源码创建的PPCBOOT工程。后来整理代码结构使得非常容易增加其他类型的开发板、其他架构的CPU(原来只支持 PowerPC)；增加更多的功能，比如启动Linux、下载S-Record格式的文件、通过网络启动、通过PCMCIA/CompactFLash /ATA disk/SCSI等方式启动。增加ARM架构CPU及其他更多CPU的支持后，改名为U-Boot。

- 支持多种嵌入式操作系统内核，如Linux、NetBSD、VxWorks、QNX、RTEMS、ARTOS、LynxOS；
- 支持多个处理器系列，如PowerPC、ARM、x86、MIPS、XScale；
#2下载u-boot过程[^jz2440]
(**要注意步骤顺序，操作要连贯，时间隔太久连接好像会断开**)
##2.1 开发板设置为norflash启动
##2.2 连好线后启动J-Flash ARM
（安装JLINK驱动后会出来的软件，文后有下载链接），进行如下操作
 ![这里写图片描述](http://img.blog.csdn.net/20170526001316528?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
file->open progect，打开s3c2440.jflash（下面下载链接里的jlink.zip有）），每次操作都有相对应的log打印
##2.3 Target->Connect
必须设为norflash启动才能检测到flash
##2.4 File->Open
打开要烧写的二进制文件u-boot.bin（u-bootyf.bin，下面下载链接里的jlink.zip有），并在弹出的start address对话框里面输入0
##2.5 Target->Auto，即可自动烧写
##2.6 烧写完成后，关电，取下j-link，重新启动即可进入u-boot界面
###A 烧u-bootyf.bin复位启动后界面：
 ![这里写图片描述](http://img.blog.csdn.net/20170526001338809?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
###B 烧光盘u-boot.bin复位启动后界面：
 ![这里写图片描述](http://img.blog.csdn.net/20170526001349278?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
##2.7 在u-boot界面下我们可以配合DNW将u-boot下载到nandflash(这一步尚未实践)
# 附录
**工具下载链接**：
https://github.com/1040003585/Mini2440/tree/master/Tools

[^bios]: 【整理】BIOS、BootLoader、uboot对比：
http://blog.csdn.net/conowen/article/details/7253620 

[^grub_u-boot]: Bootloader和BIOS、Grub、uboot概念：
http://blog.csdn.net/jia_guoqiang/article/details/53149314

[^jz2440]: 如何使用jlink下载u-boot到jz2440开发板的norflash：
http://liu1227787871.blog.163.com/blog/static/205363197201261392838122/

**Wu_Being 博客声明**：本人博客欢迎转载，请标明博客原文和原链接！谢谢！ 
《使用J-Link下载u-boot到Mini2440开发板》http://blog.csdn.net/u014134180/article/details/72760796

![Wu_Being 吴兵博客接受赞助费二维码](http://img.blog.csdn.net/20170305211231929?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvdTAxNDEzNDE4MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


如果你看完这篇博文，觉得对你有帮助，并且愿意付赞助费，那么我会更有动力写下去。
