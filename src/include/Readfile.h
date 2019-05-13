#ifndef READFILE_H__
#define READFILE_H__

#include <fstream>

/*
将整个文本的数据保存到data中
注:换行符没有被读取到data中
*/
int file_data(std::string &data);

#endif