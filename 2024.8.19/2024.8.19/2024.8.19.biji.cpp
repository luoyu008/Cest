#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.19.h"
//��������
//�ṹ�����������һ��Ԫ��Ϊ��Сδ֪������ �������������
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

//�ص㣺
//1.���������Աǰ������һ��������Ա
//2.sizeof����ṹ���Сʱ���������������Ա
//3.���ٿռ�ʱҪ��malloc�������� malloc(sizeof(s)+sizeof(int)*��Ҫ������Ԫ�ظ���)
int main() {
	//printf("%d", (int)sizeof(struct MyStruct));4
	//s* ps = (s*)malloc(sizeof(s) + sizeof(int) * 10);
	//if (ps == NULL)
	//{
	//	printf("%s", strerror(errno));
	//}
	// free(ps);
	// ps=NULL;//���ַ�ʽ���ٵ�����a��i�ĵ�ַ��������
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
	pd = NULL;//���ַ�ʽ���ٵ�����a��i�ĵ�ַ�ǲ�������
	return 0;
}