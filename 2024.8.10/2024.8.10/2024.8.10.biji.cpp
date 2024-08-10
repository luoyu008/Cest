#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//memcmp函数  内存比较函数
//int memcmp(void* s1, conat void* s2,size_t num)
//该函数是比较num个字节s1和s2的内存内的数据的大小
//s1>s2时  返回>0的数
//  =          =
//  <          <
//int main() {
//	int a[] = { 1,3,3,4,5,6 };
//	int b[] = { 1,4,3 };
//	int ret = memcmp(a, b, 12);
//	printf("%d", ret);
//	return 0;
//		
//}

//memset函数 内存设置函数  以字节为单位
//void* memset(void* ptr,int value,size_t num)
//int main() {
//	char s1[] = "zspzuishuai";
//	memset(s1, 'a', 7);
//	printf("%s", s1);
//	return 0;
//}