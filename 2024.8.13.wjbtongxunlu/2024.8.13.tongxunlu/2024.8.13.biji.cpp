#define _CRT_SECURE_NO_WARNINGS
//枚举
#include"2024.8.13.con.h"
//typedef enum day
//{
//	mon=1,
//	tues,
//	wed,
//	thur,
//	fri,
//	sat,
//	sun,
//}day;
//里面的成员是枚举常量
//下标默认从0开始
//int main() {
//	day d = mon;//此时才开始占据内存空间
//	//printf("%s", d);
//	int a[mon];
//	printf("%d\n", d);
//	printf("%d", mon);
//	return 0;
//}

//联合体（共用体） 成员公用一块空间 成员不同时使用 其空间大小至少是最大的成员的大小
//union u
//{
//	char c;
//	int a;
//};
//int main() {
//	union u un;
//	printf("%d", sizeof(un));//4
//	return 0;
//}
// 联合体大小的规则与结构体的对齐规则一致
//int key() {
//	union u {
//		char c;
//		int a;
//	}un;
//	un.a = 1;
//	return un.c;
//}
//int main() {
//	int ret = key();
//	if (ret == 1)
//		printf("x");
//	else printf("d");
//	return 0;
//}