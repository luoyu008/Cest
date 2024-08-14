#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.14.h"
//动态内存管理
//malloc函数
//void* malloc(size_t size);
//开辟size大小个字节的内存空间 返回开辟的空间的起始地址   当开辟失败时返回NULL空指针
//free函数 只能释放动态内存开辟的空间 free（p）完之后一定要p=NULL；置为空指针
//void free(void* ptr);
//int main() {
//	int a[10];//空间在栈区
//	int* p = (int *)malloc(INT_MAX*2);//空间在堆区
//	int* pp = (int*)malloc(sizeof(int) * 10);
//	if (p == NULL) {
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	free(p);
//	p = NULL;
//	return 0;//当退出时系统会自动回收空间
//}

//calloc函数 内存开辟的同时初始化为0 返回开辟的起始地址
//void* calloc(size_t num, size_t size);
//num是要开辟的元素个数  size是一个元素的大小
//int main() {
//	int a[10];//空间在栈区
//	int* p = (int *)calloc(10,sizeof(int));//空间在堆区
//	if (p == NULL) {
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	free(p);
//	p = NULL;
//	return 0;//当退出时系统会自动回收空间
//}

//realloc函数 内存调整函数
//void* realloc(void* ptr, size_t size);
//ptr是需要调整的内存的起始地址  size是想要调整的内存的新大小  返回新的内存空间的起始地址
//此函数分为两种情况 若p为40字节  想调整为80字节
//第一种：若p这块空间后面40个字节有其他数据占用 则开辟新的大小为80个字节的空间 然后把p里的数据拷贝到新的空间ptr中
//并释放掉p空间 返回ptr的起始地址
//第二种：若p这块空间后面40个字节没有其他数据占用 则直接将p这块空间向后扩展40个字节 返回这块空间的起始地址
//realloc(NULL,40)==malloc(40);
//int main() {
//	int a[10];//空间在栈区
//	int* p = (int *)calloc(10,sizeof(int));//空间在堆区
//	if (p == NULL) {
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	for (int i = 0; i < 10; i++) {
//		*(p + i) = i + 1;
//	}
//	int* pp = (int*)realloc(p, sizeof(int) * 20);
//	if (pp != NULL)
//		p = pp;
//	free(p);
//	p = NULL;
//	pp = NULL;
//	return 0;//当退出时系统会自动回收空间
//}

//动态内存常见的错误
//1.对NULL进行解引用（ * ）  （程序会崩溃）
//2.对开辟的动态内存空间进行越界访问
//3.对非动态开辟的内存进行释放
//例如 int a = 0; int* p = &a; free(p);
//4.使用free释放部分开辟的内存空间
//5.对同一块内存多次释放
//6.开辟的内存忘记释放