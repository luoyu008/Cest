#pragma once
#include<stdio.h>;
#include<assert.h>;
#include<stdlib.h>;
#include<stdbool.h>;
typedef struct TREE
{
	char date;
	struct TREE* Lchild;
	struct TREE* Rchild;
}tree;

typedef struct QUEUE
{
	tree** arr;
	int front;
	int tail;
}queue;

typedef struct STACK
{
	tree* t;
	int x;
	struct STACK* prev;
	struct STACK* next;
}stack;
typedef struct S
{
	stack* front;
	stack* tail;
}s;
//二叉树创建
tree* TREECreat();
//统计节点个数
int TREENum(tree* root);
//队列初始化
void QUEUEInit(queue* qq,int size);
void QUEUEPush(queue* qq,tree* t);//入队
int QUEUEEmpty(queue* qq);//队列判空
tree* QUEUEPop(queue* qq);//出队

void TREEFRONT(tree* t);//迭代先序遍历
void STACKPush(stack** ss,tree* pt,int x);//入栈
bool STACKEmpty(stack** ss);//栈判空
tree* STACKPop(stack** ss);//出栈
