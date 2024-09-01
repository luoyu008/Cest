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

void StackInit(stack* s);//��ʼ��
void StackPush(stack* s);//��ջ
void StackPop(stack* s);//��ջ
void StackPrint(stack* s);//��ӡ
stack* StackExpansion(stack* s);//����
datetype StackTop(stack* s);//ȡջ������
int StackSize(stack* s);//ջ������
bool StackEmpty(stack* s);//ջ�п�
void StackDestroy(stack* s);//����ջ	