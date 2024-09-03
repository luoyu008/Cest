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
tree* TREECreat();//树创建
void TREELink(tree* t, struct TREE* Lchild, struct TREE* Rchild);//树连接
void PRINT(tree* root);//打印
void FRONT(tree* root);//先序
void FRONTF(tree* root);//先序非递归
void MITREE(tree* root);//中序
void LAST(tree* root);//后序