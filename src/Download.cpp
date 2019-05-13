#include "Download.h"

std::string file_path;	//保存当前下载文件的路径

int downloadEventCallback(aria2::Session* session, aria2::DownloadEvent event,
                          aria2::A2Gid gid, void* userData)
{
	switch (event) {
	case aria2::EVENT_ON_DOWNLOAD_COMPLETE:		//指示下载已完成.
		std::cerr << "完成";
		break;
	case aria2::EVENT_ON_DOWNLOAD_ERROR:		//由于错误, 指示下载已停止.
		std::cerr << "错误";
		break;
	default:
		return 0;
	}
  
	std::cerr << " [" << aria2::gidToHex(gid) << "] ";	//打印gid的文本.
	aria2::DownloadHandle* dh = aria2::getDownloadHandle(session, gid);	//获取gid表示的下载句柄
	if (!dh)
		return 0;
	if (dh->getNumFiles() > 0) {	//文件数是否大于0
		aria2::FileData f = dh->getFile(1);	//获取指定索引处的文件的FileData.
		//如果尚未确定文件名, 则路径可能为空/
		if (f.path.empty()) {
			if (!f.uris.empty()) {
				std::cerr << f.uris[0].uri;
			}
		}
		else {
			std::cerr << f.path;
			
			//获取文件路径
			file_path = f.path;
		}
	}
	
	aria2::deleteDownloadHandle(dh);
	std::cerr << std::endl;

	return 0;
}

/*class Download*/
Download::Download() {
	/*全局初始化*/
	aria2::libraryInit();
	
	config.downloadEventCallback = downloadEventCallback;	//设置下载消息的回调
	session = aria2::sessionNew(aria2::KeyVals(), config);
}

Download::~Download() {
	int rv;
	
	/*清除会话*/
	rv = aria2::sessionFinal(session);		
	std::cout << "错误代码: " << rv << std::endl;
	
	/*libaria2结束需要调用*/
	rv = aria2::libraryDeinit();
	std::cout << "Download退出状态: " << rv << std::endl;
}

int Download::addUri(std::vector<std::string> &uris) {
	int rv;
	aria2::KeyVals options;
    
	/*添加uri*/
	rv = aria2::addUri(session, nullptr, uris, options);
	if (rv < 0) {
		std::cerr << "无法添加下载 " << uris[0] << std::endl;
	}
	
	return 0;
}

int Download::run() {
	int rv;
	
	/*执行下载*/
	while (true) {
		rv = aria2::run(session, aria2::RUN_ONCE);
		if (rv != 1) break;
	}
	
	return 0;
}

int Download::refresh() {
	int rv;
	rv = aria2::sessionFinal(session);
	std::cout << "数据刷新情况: " << rv << std::endl;
	
	config.downloadEventCallback = downloadEventCallback;
	session = aria2::sessionNew(aria2::KeyVals(), config);
	
	return 0;
}

