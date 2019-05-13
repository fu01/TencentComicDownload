#include "Regular.h"

const char *regString = nullptr;
const char *regBuf = nullptr;

RegEx::RegEx() {
	int cflags = REG_EXTENDED;
	regcomp(&reg, regString, cflags);
}

RegEx::~RegEx() {
	regfree(&reg);
}

/*
开始查询文本
first 匹配文本串在目标串中的开始位置
tail 匹配文本串在目标串中的结束位置
*/
int RegEx::Run(int &first, int &tail) {
	int status;
	status = regexec(&reg, regBuf, 1, pmatch, 0);
	if(status == REG_NOMATCH) 
		return 1;
	
	first = pmatch[0].rm_so;
	tail = pmatch[0].rm_eo;
	
	return 0;
}

/*指定新的regString需要运行*/
int RegEx::setRule() {
	int cflags = REG_EXTENDED;
	regfree(&reg);
	regcomp(&reg, regString, cflags);
	
	return 0;
}
