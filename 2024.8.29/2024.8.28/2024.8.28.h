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

//void SListInit(SL* sl);//初始化链表第一个
void SListPushBack(SL** sl);//尾插
void SListPopBack(SL** sl);//尾删
void SListPrint(SL* sl);//打印测试
void SListPushFront(SL** sl);//头插
void SListPopFront(SL** sl);//头删
SL* SListFind(SL* sl,datetype x);//查找数据
void SListInsertF(SL** ssl);//在数据位置之前插入数据
void SListInsertB(SL** ssl);//在数据位置后插入数据
void SListErase(SL** ssl);//删除某位
void SListEraseF(SL** ssl);//删除某位的后一位
void SListdestory(SL** ssl);//销毁链表

