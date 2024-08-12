#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//结构体声明
//struct//关键字  tag//tag是结构体标签  没有tag的结构体是匿名结构体类型他只能使用一次
//{
//	member - list;//成员变量列表
//}variable-list; //变量列表
//结构体用空间换时间
//结构体自引用 类似数据结构中链表的构成 （date，下一个结构体的地址） 这样就可以通过第一个结构体找到下一个结构体
//struct stu
//{
//	int date;
//	struct stu* nest;
//};

//结构体的内存对齐规则
//struct MyStruct
//{         //对齐数
//	int a;//4
//	char b;//1
//	int c;//4
//};
//该结构体的大小为12 a的偏移量为0 b为4 c为8
//struct MyStruct1
//{         //对齐数
//	int a;//4
//	struct MyStruct b;//4
//	char c;//1
//};
//该结构体的大小为20 a的偏移量为0 b为4 c为15
//宏offsetof(struct MyStruct,a)便能算出a在struct MyStruct中的偏移量 其头文件为#include<stddef.h>
//第一个成员在结构体偏移量为0的地址处 也就是若为char 则在内存第一个字节 若为int则在内存前四个字节
//其他的成员变量要对齐到对齐数的整数倍的地址处  对齐数是编译器默认的对齐数与该成员大小的较小的值（vs默认为8）
//结构体的总大小为所有成员的对齐数的整数倍
//如果嵌套了结构体的情况  嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数
//（含嵌套结构体的对齐数）的整数倍

//在设计结构体时要将占用空间小的成员尽量集中在一起
//#pragma pack(n)可以修改默认对齐数为n
//#pragma pack()可以取消修改
//#pragma pack(1)
//struct MyStruct
//{         //对齐数
//	int a;//4
//	char b;//1
//	int c;//4
//};
//此时struct MyStruct的大小为9


//位（比特位）端  用来节省空间 只能在结构体使用
//位端成员是整形家族数据  如int ,unsigned int, signed int, char
//struct a {
//	int _a : 3;//3的意思是_a需要3个比特位
//	int _b : 4;//4的意思是_b需要4个比特位
//}; 大小为4字节
//其空间按照需要开辟4个字节（32个比特位）或者1个字节（8个比特位）