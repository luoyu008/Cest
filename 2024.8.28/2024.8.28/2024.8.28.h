#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<assert.h>
typedef int datetype;
typedef struct SList {
	datetype date;
	struct SList *p;
}SL;

void SListInit(SL* sl);//��ʼ�������һ��
void SListPushBack(SL** sl);//β��
void SListPopBack(SL** sl);//βɾ
void SListPrint(SL* sl);//��ӡ����
void SListPushFront(SL** sl);//ͷ��
void SListPopFront(SL** sl);//ͷɾ

