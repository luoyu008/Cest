#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//strstr函数 
//const char* strstr(const char* str1,const char* str2)
//该函数是字符串查找函数   即查找str1中是否包含str2  若能找到返回str1中str2的首字符的地址 否则返回NULL
//模拟实现
//char* mystrstr(const char* str1, const  char* str2) {
//	//char* pstr1 =(char*) str1;
//	int count = 0;
//	while (*str2 != '\0'&&*str1!='\0') {
//		if (*str1 == *str2) {
//			count++;
//			str1++;
//			str2++;
//		}
//		else {
//			str2 -= count;
//			str1 = str1 - count + 1;
//			count = 0;
//		}
//
//	}
//	if (count == 0) {
//		return NULL;
//	}
//
//	return (char*)str1-count;
//}
//int main() {
//	char str1[] = "ahbgdc";
//	char str2[] = "abc";
//	char* ret=mystrstr(str1, str2);
//	printf("%s", ret);
//	return 0;
//}

//memcpy函数 内存拷贝函数 拷贝两块独立内存的数据  不能处理重叠内存的拷贝
//void* memcpy(void* destination,const void* source,size_t num)
//该函数是将source内存的数据拷贝到destination内存中  大小是num个字节
//模拟实现
#include<assert.h>
//void* mymemcpy(void* des,const void* source,size_t num) {
//	assert(des && source);
//	void* pdes = des;
//	while (num--) {
//		*(char*)des = *(char*)source;
//		des = (char*)des + 1;
//		source = (char*)source + 1;
//	}
//	return pdes;
//}
//int main() {
//	unsigned int a[] = { 1,5,8,6,4967294 };
//	unsigned int b[50] = {0};
//	mymemcpy(b, a, sizeof(a));
//	return 0;
//}


//memmove函数 内存拷贝函数 可以实现处理重叠内存的拷贝
//void* memcpy(void* destination,const void* source,size_t num)
//模拟实现
//void* mymemmove(void* des,const void* src,size_t num){
//	assert(des && src);
//	void* pdes = des;
//	if (des < src) {
//		while (num--) {
//			*(char*)des = *(char*)src;
//			des = (char*)des + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else {
//		while (num--) {
//			*((char*)des+num) = *((char*)src+num);
//		}
//	}
//	return des;
//}
//int main() {
//	 int a[] = { 1,5,8,6,4967294,4,3,7,9 };
//	//unsigned int b[50] = { 0 };
//	mymemmove(a, a, 16);
//	return 0;
//}
//strtok函数 字符串分割
//char* strtok(char* str, const char* sep);
////str是要分割的字符串  sep是分割符字符串  
// str1可以传字符串的拷贝字符串
//当strtok第一个参数不为NULL的时候 strtok函数将分割字符串直到第一个分割符 将分隔符换为‘\0’
//并返回分割后字符串第一个字符的地址
//当strtok第一个参数为NULL的时候strtok将在第二个字符开始分割字符串知道下一个分割符 将分割符换为‘\0’
//并返回分割后字符串不为‘\0’的起始地址
//如果字符串中不再有分隔符 将返回空指针

//int main() {
//	char str1[] = "zspdwa@asdfwa#wdas.awd";
//	const char* sep = "@#.";
//	char ss[50] = {0};
//	strcpy(ss, str1);
//	char* ret = NULL;
//	for (ret = strtok(ss, sep); ret != NULL; ret = strtok(NULL, sep)) {
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strerror函数
//把错误码转换为对应的错误信息
#include<errno.h>
//int main() {
//	FILE* p = fopen("test.text", "r");
//	if (p == NULL) {
//		printf("%s\n", strerror(errno));//errno是C语言设置的一个错误码存放的全局变量 需要头文件#include<errno.h>
//	}
//	else {
//		
//	}
//	return 0;
//}