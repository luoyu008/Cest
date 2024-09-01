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
void QUEUEInit(q* pp);//��ʼ��
void QUEUEDestroy(q* pp);//����
bool QUEUQEmpty(q* pp);//�п�
void QUEUEPush(q* pp);//���
void QUEUEPop(q* pp);//����
datetype QUEUEFront(q* pp);//��ͷ����
datetype QUEUEBack(q* pp);//��β����
int QUEUESize(q* pp);//��������


