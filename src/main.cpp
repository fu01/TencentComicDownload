#include "Download.h"
#include "Readfile.h"
#include "Regular.h"
#include <cstring>

std::string ac_uri = "https://ac.qq.com";

/*
得到所有章节链接
num 限制获取的章节数, 例如: num = 1, 表示只获取第一章
*/
int dirList(std::vector<std::string> &list, int num) {
	std::string data;
	int first, tail;
	
	file_data(data);
	
	/*检索到目录的起始位置*/
	regString = "works-chapter-list-wr";
	RegEx reg;
	regBuf = data.c_str();
	reg.Run(first, tail);
	regBuf = &regBuf[first];

	/*检索目录并保存*/
	regString = "/ComicView/index/id/[0-9]*/cid/[0-9]*";
	reg.setRule();
	while (!reg.Run(first, tail)) {
		std::string temp;
		for (int i = first; i < tail; i++)
		{
			temp.push_back(regBuf[i]);
		}
		
		list.push_back(temp);
		
		/*偏移, 跳过以查询的章节链接*/
		regBuf = &regBuf[tail];	
		
		/*达到需要查询的章节数, 退出循环*/
		if((--num) == 0) 
			break;
	}	
	
	
	return 0;
}

/*检索图片链接*/
int retImages(std::vector<std::string> &images_list) {
	std::string data;
	int first, tail;
	
	file_data(data);
	regBuf = data.c_str();
	
	regString = "https://manhua.qpic.cn/manhua_detail/0/[0-9]*_[0-9]*_[0-9]*_[A-Za-z0-9]*_[0-9]*.jpg/[0-9]*";
	RegEx reg;
	
	while (!reg.Run(first, tail)) {
		std::string temp;
		for (int i = first; i < tail; i++)
		{
			temp.push_back(regBuf[i]);
		}
		
		images_list.push_back(temp);
		
		regBuf = &regBuf[tail];
	}
	
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "格式: Comic [uri]" << std::endl;
		exit(0);
	}
	
	Download dl;
	std::vector<std::string> dir_list;	//目录列表
	
	/*下载章节页*/
	std::vector<std::string> uris = {argv[1]};
	dl.addUri(uris);
	dl.run();
	
	dirList(dir_list, 10); //获取所有章节保存到dir_list
	for (const auto& list : dir_list) {
		//std::cout << ac_uri + list << std::endl;
		/*下载选定章节页*/
		uris[0] = ac_uri + list;
		dl.refresh();
		dl.addUri(uris);
		dl.run();
		
		std::vector<std::string> images_list; //图片列表
		/*图片链接保存到images_list*/
		retImages(images_list);
		for (const auto& I_list : images_list) {
			std::cout << I_list << std::endl;
		}
	}
	
	return 0;
}