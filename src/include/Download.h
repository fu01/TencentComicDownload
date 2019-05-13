#ifndef DOWNLOAD_H__
#define DOWNLOAD_H__

#include <iostream>
#include <chrono>

#include <aria2/aria2.h>

class Download {
private:
	aria2::Session* session;
	aria2::SessionConfig config;

public:
	Download();
	~Download();
	
	int addUri(std::vector<std::string> &uris);	//添加下载地址
	int run();	//执行下载
	int refresh();	//刷新, 这样才可以执行新的下载
};

#endif


