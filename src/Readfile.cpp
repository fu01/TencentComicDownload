#include "Readfile.h"

extern std::string file_path;

int file_data(std::string &data) {
	char c;
	
	std::ifstream infile;
	infile.open(file_path);	//打开文件
	
	//读取完一个文件
	while (!infile.eof()) { 
		infile >> c;
		data = data + c;
	}
	
	infile.close();	//关闭文件
	return 0;
}