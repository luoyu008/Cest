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
//����������
tree* TREECreat();
//ͳ�ƽڵ����
int TREENum(tree* root);
//���г�ʼ��
void QUEUEInit(queue* qq,int size);
void QUEUEPush(queue* qq,tree* t);//���
int QUEUEEmpty(queue* qq);//�����п�
tree* QUEUEPop(queue* qq);//����

void TREEFRONT(tree* t);//�����������
void STACKPush(stack** ss,tree* pt,int x);//��ջ
bool STACKEmpty(stack** ss);//ջ�п�
tree* STACKPop(stack** ss);//��ջ
