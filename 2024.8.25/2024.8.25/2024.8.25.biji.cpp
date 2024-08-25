#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.25.h"
//复习memcpy
//内存拷贝函数 void* memcpy(void* des, void* sor, size_t num);
//将大小为num个字节的起始地址为sor的内存拷贝到起始地址为des的内存处
////复习memmove
//内存移动函数 void* memmove(void* des, void* sor, size_t num);
//将大小为num个字节的起始地址为sor的内存移动到起始地址为des的内存处
//区别：memcpy一般不能处理内存重叠的数据但是在有的编译器上可以例如vs2022


//复习判断大小端
//typedef union MyUnion
//{
//	int a;
//	char b;
//}u;
//int main() {
//	u u1;
//	u1.a = 1;
//	if (u1.b = 1) {
//		printf("x");
//	}
//	else
//		printf("d");
//	return 0;
//}


//数据结构

//时间复杂度  大O渐进法(估算)  先算出准确的次数 然后保留对结果影响最大的那一项
//例如 F（N） = N * N + N * 2 + 10
//O(n * n);
//大O渐进法：
//1.用常数1取代运行时间中的所有加法常数
//2.在修改后的运行次函数中只保留最高项
//3.如果最高阶项存在且不是1，则去除该项相乘的常数，得到的结果就是O（）；
//O(1)代表运算常数次