#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int add(int a, int b) {
	return a + b;
}
int main() {
	int a = 0;
	int b = 3;
	int ret=add(a, b);
	printf("%d", ret);
	return 0;
}