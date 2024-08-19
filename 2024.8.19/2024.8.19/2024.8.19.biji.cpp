#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.19.h"
//柔性数组
//结构体中允许最后一个元素为大小未知的数组 这就是柔性数组
typedef struct MyStruct
{
	int i;
	int a[0];//int a[];
}s;
typedef struct S
{
	int a;
	int* b;
}d;

//特点：
//1.柔性数组成员前至少有一个其他成员
//2.sizeof计算结构体大小时不包含柔性数组成员
//3.开辟空间时要用malloc函数开辟 malloc(sizeof(s)+sizeof(int)*想要的数组元素个数)
int main() {
	//printf("%d", (int)sizeof(struct MyStruct));4
	//s* ps = (s*)malloc(sizeof(s) + sizeof(int) * 10);
	//if (ps == NULL)
	//{
	//	printf("%s", strerror(errno));
	//}
	// free(ps);
	// ps=NULL;//这种方式开辟的数组a和i的地址是连续的
	d* pd = (d*)malloc(sizeof(d));
	if (pd == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	pd->a = 100;
	pd->b = (int*)malloc(sizeof(int) * 10);
	if (pd->b == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	for (int i = 0; i < 10; i++) {
		pd->b[i] = i + 1;
	}
	printf("%d", pd->a);
	for (int i = 0; i < 10; i++) {
		printf("%d", pd->b[i]);
	}
	free(pd->b);
	pd->b = NULL;
	free(pd);
	pd = NULL;//这种方式开辟的数组a和i的地址是不连续的
	return 0;
}