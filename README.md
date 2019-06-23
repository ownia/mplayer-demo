# mplayer-demo

> a micro video player on mini210s using mplayer-core

nfs的挂载
```
sudo mount 10.241.10.171:/opt/FriendlyARM/mini210s/linux/rootfs_qtopia_qt4 /mnt/nfs
```

错误
```
mount.nfs: access denied by server while mounting 10.241.10.171:/opt/FriendlyARM/mini210s/linux/rootfs_qtopia_qt4
```
```
sudo exportfs -r
```
```
exportfs: /etc/exports [1]: Neither 'subtree_check' or 'no_subtree_check' specified for export "*:/opt/FriendlyARM/mini210s/linux/rootfs_qtopia_qt4".
  Assuming default behaviour ('no_subtree_check').
  NOTE: this default has changed since nfs-utils version 1.0.x
exportfs: could not open /var/lib/nfs/.etab.lock for locking: errno 13 (Permission denied)
exportfs: can't lock /var/lib/nfs/etab for writing
```
新版本的nfs-kernel-server 中，在填写/etc/exports 文件时需要填写一个重要参数  no_subtree_check.

```
sudo nano /etc/exports
```
在尾部添加
```
/opt/FriendlyARM/mini210s/linux/rootfs_qtopia_qt4 *(sync,rw,no_root_squash,no_subtree_check)
```

重新安装qt
下载qt-sdk-linux-x86-opensource-2010.05.1.bin
安装之后缺少libgthread-2.0.so.0动态库
```sudo apt-get install libglib2.0-0:i386```

QGtkStyle was unable to detect the current GTK+ theme.
在config里换一个GUI Style就行

编写setqt4env文件
运行可执行程序```./<application> -qws```

编译libid3tag-0.15.1.b
配置configure
```
./configure --host=arm-linux --disable-shared --prefix=/usr/local/arm/4.5.1/lib CC="arm-linux-gcc" --disable-shared –enable-static CPPFLAGS="-I/usr/local/arm/4.5.1/lib/include" LDFLAGS="-L/usr/local/arm/4.5.1/lib/lib" 
```
编译安装
```
make CC=arm-linux-gcc
make CC=arm-linux-gcc install
```

编译libmad-0.15.1b
配置configure
```
./configure --enable-fpm=arm --host=arm-linux --disable-shared --prefix=/usr/local/arm/4.5.1/lib CC="arm-linux-gcc"
```
编译安装
```
make CC=arm-linux-gcc
make CC=arm-linux-gcc install
```
编译libmad-0.15.1b时
要在Makefile中删除-fforce-mem
高版本的arm-linux-gcc中是没有-fforce-mem的

此时lib目录下生成以下文件
```
ownia@ownia-PC:/usr/local/arm/4.5.1$ tree
.
└── lib
    ├── include
    │   ├── id3tag.h
    │   └── mad.h
    └── lib
        ├── libid3tag.a
        ├── libid3tag.la
        ├── libmad.a
        └── libmad.la
```

编译MPlayer-1.0rc3
配置configure
```
./configure --host-cc=gcc --cc=arm-linux-gcc --target=arm --enable-static --disable-win32dll --disable-dvdread --disable-dvdread-internal --disable-dvdnav --disable-libdvdcss-internal --enable-fbdev --disable-mencoder --disable-live --disable-mp3lib --disable-mad --enable-libavcodec_a --language=zh_CN --disable-live 2>&1 | tee logfile
```
编译
```
make CC=arm-linux-gcc
```
在目录下生成mplayer
```
mplayer: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, for GNU/Linux 2.6.27, not stripped
```
如果在编译时产生错误```undefined reference to `clock_gettime'```
则修改Makefile
```
mplayer$(EXESUF): $(MPLAYER_DEPS)
	$(CC) -o $@ $^ $(LDFLAGS_MPLAYER)
```
在尾部增加```-lrt```
```
mplayer$(EXESUF): $(MPLAYER_DEPS)
	$(CC) -o $@ $^ $(LDFLAGS_MPLAYER) -lrt
```