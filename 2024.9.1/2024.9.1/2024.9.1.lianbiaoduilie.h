#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef int datetype;
typedef struct QUEUE
{
	int val;
	struct QUEUE* next;
}queue;

typedef struct Queue
{
	queue* head;
	queue* tail;
}q;
void QUEUEInit(q* pp);//初始化
void QUEUEDestroy(q* pp);//销毁
bool QUEUQEmpty(q* pp);//判空
void QUEUEPush(q* pp);//入队
void QUEUEPop(q* pp);//出队
datetype QUEUEFront(q* pp);//队头数据
datetype QUEUEBack(q* pp);//队尾数据
int QUEUESize(q* pp);//队数据量


