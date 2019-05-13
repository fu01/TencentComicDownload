# 腾讯漫画下载器(未完成)



#### 1. 实际运行

```
$ ./TencentComic https://ac.qq.com/Comic/ComicInfo/id/532992
完成 [711608c49a1bf8dd] /home/fu01/WORK/source/TencentComicDownload/532992
数据刷新情况: 0
完成 [786af91254ed3758] /home/fu01/WORK/source/TencentComicDownload/1.1
https://manhua.qpic.cn/manhua_detail/0/17_21_05_f95796..._1255.jpg/0
数据刷新情况: 0
完成 [70a43ca42f355ca3] /home/fu01/WORK/source/TencentComicDownload/2.1
https://manhua.qpic.cn/manhua_detail/0/17_21_06_2ba8a3d7..._2166.jpg/0
...
数据刷新情况: 0
完成 [3e7e29d25d624e46] /home/fu01/WORK/source/TencentComicDownload/10.1
https://manhua.qpic.cn/manhua_detail/0/17_21_08_3606ff1a0..._1358.jpg/0
错误代码: 0
Download退出状态: 0
```

现在已经完成到了, 可以将当前章节的图片链接检索出来。

但下载的html文件中, 还未生成主体漫画部分。



#### 2. 编译需求

本程序调用了`libaria2`, 进行实际的下载操作。

一般可以使用`包管理器`安装, 也可以通过源代码编译生成。

github: [aria2](https://github.com/aria2/aria2)  (编译时需要指明需要生成lib库文件)



#### 3. 编译

```
$ make
```







