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

list* ListInit();//初始化
void ListPushBack(list* plist);//尾插
void ListPrint(list* plist);//打印 
void ListPopBack(list* plist);//尾删
void ListPushFront(list* plist);//头插
void ListPopFront(list* plist);//头删
list* ListFind(list* plist,datetype x);//查找
void ListInsertF(list* plist);//某位前插入
void ListInsertB(list* plist);//某位后插入
void ListEarse(list* plist);//删除某位