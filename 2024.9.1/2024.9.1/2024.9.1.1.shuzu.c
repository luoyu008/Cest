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
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ������Ϊ��%d\n", y);
	}
	int x=StackTop(&s);
	if (x == -1) {
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ������Ϊ��%d\n", x);
	}
	StackPop(&s); 
	y = StackSize(&s);
	if (y == -1) {
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ������Ϊ��%d\n", y);
	}
	x = StackTop(&s);
	if (x == -1) {
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ������Ϊ��%d\n", x);
	}
	StackPop(&s);
	y = StackSize(&s);
	if (y == -1) {
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ������Ϊ��%d\n", y);
	}
	x = StackTop(&s);
	if (x == -1) {
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ������Ϊ��%d\n", x);
	}
	StackPop(&s);
	y = StackSize(&s);
	if (y == -1) {
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ������Ϊ��%d\n", y);
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