#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int datetype;
typedef struct Stack {
	datetype* a;
	int top;
	int capacity;
}stack;

void StackInit(stack* s);//初始化
void StackPush(stack* s);//入栈
void StackPop(stack* s);//出栈
void StackPrint(stack* s);//打印
stack* StackExpansion(stack* s);//扩容
datetype StackTop(stack* s);//取栈顶数据
int StackSize(stack* s);//栈数据量
bool StackEmpty(stack* s);//栈判空
void StackDestroy(stack* s);//销毁栈	