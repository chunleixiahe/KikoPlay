# KikoPlay - NOT ONLY A Full-Featured Danmu Player

---
不仅仅是全功能弹幕播放器
[![latest packaged version(s)](https://repology.org/badge/latest-versions/kikoplay.svg)](https://repology.org/project/kikoplay/versions)
[![GitHub All Releases](https://img.shields.io/github/downloads/Protostars/KikoPlay/total)](https://github.com/Protostars/KikoPlay/releases)

<div align=center><img src="res/images/kikoplay-4.png" />
</div>

## 特性

 - OpenGL渲染，流畅的弹幕体验
 - libmpv播放内核，支持多种媒体文件格式，保留mpv灵活的参数设置，支持实时进度条预览
 - 树形播放列表，可随意组织你的番剧
 - 支持所有主流视频网站弹幕搜索下载：AcFun,Bilibili,Tucao,5dm,巴哈姆特,爱奇艺,优酷,腾讯视频,PPTV
 - 灵活的弹幕屏蔽规则设定，支持自动合并相似弹幕、弹幕事件分析标注，提升观看体验
 - 支持批量管理弹幕池，支持弹幕时间轴调整，更好地处理本地视频和网站上的视频时长不一致的情况
 - 资料库可以记录并组织你看过的番剧，同时可以从Bangumi上获取详细信息
 - 局域网服务，你可以通过网页在其他设备上观看，现在还有[Android端](https://github.com/Protostars/KikoPlay-Android-LAN)可供选择
 - 集成aria2下载功能
 - 每日放送功能：可快速浏览新番列表并添加关注
 - 基于Lua脚本的资源搜索功能，你也可以为KikoPlay编写脚本，[脚本仓库](https://github.com/Protostars/KikoPlayScript)
 - 支持自动下载，通过设置规则，KikoPlay可自动搜索下载资源
 - 独特的KikoPlay资源代码和弹幕池代码，可直接分享包含弹幕池信息的资源链接
 - .........

## 编译

KikoPlay基于以下项目：

 - Qt 5.15.0
 - [libmpv](https://github.com/mpv-player/mpv)
 - [aria2](https://github.com/aria2/aria2)
 - [Qt-Nice-Frameless-Window](https://github.com/Bringer-of-Light/Qt-Nice-Frameless-Window)
 - zlib 1.2.11
 - [QHttpEngine](https://github.com/nitroshare/qhttpengine)
 - Lua 5.3

编译环境： MSVC2015，gcc 7.3.0(其他版本未测试)

Windows上使用Qt Creator打开工程文件后可直接编译

Linux上看[这里](linux.md)

Mac OS 系统可自行尝试

自从0.2.3版本后只提供64位版本，不建议使用32位版本

## 下载

最新版本均在[百度网盘](https://pan.baidu.com/s/1gyT0FU9rioaa77znhAUx2w)发布

## 反馈

如果有问题，欢迎创建issue或者联系我:
dx_8820832#yeah.net（#→@），或者加QQ群874761809反馈

## 截图

![](screenshot/KikoPlay1.jpg)
![](screenshot/KikoPlay1-2.jpg)
![](screenshot/KikoPlay-Ubuntu.png)
![](screenshot/KikoPlay2.jpg)
![](screenshot/KikoPlay3.jpg)
![](screenshot/KikoPlay4.jpg)
![](screenshot/KikoPlay_web.jpg)
