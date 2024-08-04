#define _CRT_SECURE_NO_WARNINGS
//函数指针 
// void add（int）{}
// int （*p）（int）=add；
// (*(void(*)())0)();   该表达式是对0进行强制类型转化为 返回值为void 无形参的函数指针的地址 
// 同时调用0地址处的该函数  也可写成(void(*)())0()   0也可理解为0x00000000
//void(* signal(int ,void(*)(int)))(int);
//signal是一个函数名  以上代码是一个函数声明  声明的signal函数的第一个参数为int类型  
// 第二个参数为 返回值为void 参数类型为int的函数指针 signal函数的返回类型也是void  参数为int的函数指针
typedef void(*pf)(int);
//该代码也可以重新命名为 pf(* signal(int,pf))
//函数指针的简易小实例 简易计算器
//回调函数

//函数指针数组可以这样写
//int (*p[4])(int,int)={add,sub,mul,div};
//可以在循环中通过*p[i](8,4)调用依次调用四个函数
//函数指针数组指针
//int (*(*pp)[4])(int,int)=&p;
#include<stdio.h>
void menu() {
	printf("**********************\n");
	printf("******   1.add   *****\n");
	printf("******   2.sub   *****\n");
	printf("******   3.mul   *****\n");
	printf("******   4.div   *****\n");
	printf("******   0.exit  *****\n");
	printf("**********************\n");
}
int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
//函数指针
//void calc(int (*p)(int ,int)) {
//	printf("请输入两个数\n");
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = p(a, b);
//	printf("%d\n" ,ret);
//}
//函数指针数组
void calc(int (*p[5])(int ,int), int inpute, int x, int y) {
	            printf("请输入：\n");
				scanf("%d %d", &x, &y);
				int ret = p[inpute](x, y);
				printf("%d\n", ret);
}
int main() {
	int inpute = 0;
	//函数指针数组实现  函数指针数组也叫做转移表即通过数组下标来调用函数
	do {
		menu();
		printf("请输入选项:\n");
		scanf("%d", &inpute);
		int x = 0;
		int y = 0;
		int (*p[5])(int, int) = { 0,add,sub,mul,div };
		if (inpute == 0) {
			printf("退出\n");
		}
		else if (inpute > 4) {
			printf("请重新输入\n");
		}
		else {
			calc(p, inpute, x, y);
		}
	} while (inpute);
//	/*do
//	{*/
//	/*menu();
//	printf("请输入:\n");
//	scanf("%d", &inpute);*/
//	//函数指针
////		switch (inpute)
////		{
////		case 1:
////			calc(add);
////			break;
////		case 2:
////			calc(sub);
////			break;
////		case 3:
////			calc(mul);
////
////			break;
////		case 4:
////			calc(div);
////			break;
////		case 0:
////			printf("退出\n");
////			break;
////		default:
////			printf("请重新输入\n");
////			break;
////		}
////	} while (inpute);
//
//
//	return 0;
////}
}