#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.1shuzu.h"
void test() {
	stack s;
	StackInit(&s);
	StackPush(&s);
	StackPush(&s);
	StackPush(&s);
	int y = StackSize(&s);
	if (y == -1) {
		printf("栈为空\n");
	}
	else
	{
		printf("栈数据量为：%d\n", y);
	}
	int x=StackTop(&s);
	if (x == -1) {
		printf("栈为空\n");
	}
	else
	{
		printf("栈顶数据为：%d\n", x);
	}
	StackPop(&s); 
	y = StackSize(&s);
	if (y == -1) {
		printf("栈为空\n");
	}
	else
	{
		printf("栈数据量为：%d\n", y);
	}
	x = StackTop(&s);
	if (x == -1) {
		printf("栈为空\n");
	}
	else
	{
		printf("栈顶数据为：%d\n", x);
	}
	StackPop(&s);
	y = StackSize(&s);
	if (y == -1) {
		printf("栈为空\n");
	}
	else
	{
		printf("栈数据量为：%d\n", y);
	}
	x = StackTop(&s);
	if (x == -1) {
		printf("栈为空\n");
	}
	else
	{
		printf("栈顶数据为：%d\n", x);
	}
	StackPop(&s);
	y = StackSize(&s);
	if (y == -1) {
		printf("栈为空\n");
	}
	else
	{
		printf("栈数据量为：%d\n", y);
	}
	StackPrint(&s);
	/*StackPop(&s);
	StackPrint(&s); 
	StackPop(&s);
	StackPrint(&s); 
	StackPop(&s);
	StackPrint(&s);*/
	/*StackPush(&s);
	StackPush(&s);
	StackPush(&s);
	StackPush(&s);
	StackPush(&s);*/
	
}
//int main() {
//	test();
//	return 0;
//}