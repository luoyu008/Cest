#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct TREE
{
	char date;
	struct TREE* Lchild;
	struct TREE* Rchild;
}tree;

typedef struct STACK
{
	char date;
	struct STACK* next;
}stack;
tree* TREECreat();//������
void TREELink(tree* t, struct TREE* Lchild, struct TREE* Rchild);//������
void PRINT(tree* root);//��ӡ
void FRONT(tree* root);//����
void FRONTF(tree* root);//����ǵݹ�
void MITREE(tree* root);//����
void LAST(tree* root);//����