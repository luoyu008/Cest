#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<assert.h>
////静态顺序表
//typedef int SLdatetype;
//#define N 100
//
//typedef struct Seqlist {
//	SLdatetype a[N];
//	int size;//表示数组中存入了多少数据
//}s;
////静态的特点：数据满了之后就不能插入 很难确定合适的数组大小
////接口函数
//void SeqlistInt(s* s1);//初始化
//void SeqlistPushBack(s* s1, SLdatetype x);//表尾插入
//void SeqlistPopBack(s* s1);//表尾输出
//void SeqlistPushFront(s* s1, SLdatetype x);//表头插入
//void SeqlistPopFront(s* s1);//表头输出


//动态顺序表
typedef int SLdatetype;

typedef struct Seqlist {
	SLdatetype* a;
	int size;//表示数组中存入了多少数据
	int capactity;//表示数组能存储的容量的大小
}s;
//静态的特点：数据满了之后就不能插入 很难确定合适的数组大小
//接口函数
void SeqlistInit(s* s1);//初始化
//void Seqlistm(s* s1);//初始开辟空间
void Seqlistmm(s* s1);//增容
void Seqlistdestory(s* s1);//销毁
void SeqlistPushBack(s* s1);//表尾插入
void SeqlistPopBack(s* s1);//表尾删除
void SeqlistPushFront(s* s1);//表头插入
void SeqlistPopFront(s* s1);//表头删除
void SeqlistPrintf(s* s1);//打印测试
void SeqlistFind(s* s1);//找到x的位置并返回
void SeqlistPopn(s* s1);//删除x位置的数据
void SeqlistPushn(s* s1);//插入n位置一个数据