# mplayer-demo

> a micro video player on mini210s using mplayer-core

详细介绍在`./documentation.md`

mini210s配套LCD型号为HSD043I9W1
> This TFT LCD has a 4.3 (16:9) inch diagonally measured active
display area with WQVGA (480 horizontal by 272 vertical pixel) resolution

所以利用Inkscape绘制了GUi整体框架(480mm x 272mm)
程序整体GUI设计存储在`./gui-inkscape.svg`中(内嵌Inkscape特殊格式)

![](https://github.com/ownia/mplayer-demo/raw/master/gui.png)

compiler目录包含需要通过`arm-linux-gcc`编译的三个库
```
compiler/
├── libid3tag-0.15.1b
├── libmad-0.15.1b
└── MPlayer-1.0rc3
```