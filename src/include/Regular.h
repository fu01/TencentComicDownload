#ifndef REGULAR_H__
#define REGULAR_H__

#include <sys/types.h>
#include <regex.h>

extern const char *regString;	//指向正则的文本
extern const char *regBuf;		//指向需要查询的数据

class RegEx {
private:
	regmatch_t pmatch[1];
	regex_t reg;
	
public:
	RegEx();
	~RegEx();
	int Run(int &first, int &tail);	//运行
	int setRule();	//重新设置regString
};

#endif