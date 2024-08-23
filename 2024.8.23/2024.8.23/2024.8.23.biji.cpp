#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.23.h"
//宏
//#define name(parament-list) stuff
//例如 
//#define square(x) (x*x) 
//int main() {
//	int a = square((3+1));
//	printf("%d\n", a);
//	return 0;
//}
//宏不能递归


//#可以在宏里面把参数变为对应的字符串
//#define print(n) printf("the value of "#n" is %d\n",n)
//int main() {
//	int a = 3;
//	print(a);
//	int b = 4;
//	print(b);
//	return 0;
//}


//##可以把两个符号合并成一个符号
//#define Add(str1,str2) str1##str2
//int main() {
//	int zsp20 = 20;
//	printf("%d\n", Add(zsp, 20));
//	return 0;
//}