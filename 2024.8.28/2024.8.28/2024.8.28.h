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

void SListInit(SL* sl);//初始化链表第一个
void SListPushBack(SL** sl);//尾插
void SListPopBack(SL** sl);//尾删
void SListPrint(SL* sl);//打印测试
void SListPushFront(SL** sl);//头插
void SListPopFront(SL** sl);//头删

