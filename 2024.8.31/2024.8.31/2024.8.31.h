#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int datetype;
typedef struct List
{
	struct List* prev;
	datetype val;
	struct List* next;
 }list;

list* ListInit();//��ʼ��
void ListPushBack(list* plist);//β��
void ListPrint(list* plist);//��ӡ 
void ListPopBack(list* plist);//βɾ
void ListPushFront(list* plist);//ͷ��
void ListPopFront(list* plist);//ͷɾ
list* ListFind(list* plist,datetype x);//����
void ListInsertF(list* plist);//ĳλǰ����
void ListInsertB(list* plist);//ĳλ�����
void ListEarse(list* plist);//ɾ��ĳλ