#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<assert.h>
////��̬˳���
//typedef int SLdatetype;
//#define N 100
//
//typedef struct Seqlist {
//	SLdatetype a[N];
//	int size;//��ʾ�����д����˶�������
//}s;
////��̬���ص㣺��������֮��Ͳ��ܲ��� ����ȷ�����ʵ������С
////�ӿں���
//void SeqlistInt(s* s1);//��ʼ��
//void SeqlistPushBack(s* s1, SLdatetype x);//��β����
//void SeqlistPopBack(s* s1);//��β���
//void SeqlistPushFront(s* s1, SLdatetype x);//��ͷ����
//void SeqlistPopFront(s* s1);//��ͷ���


//��̬˳���
typedef int SLdatetype;

typedef struct Seqlist {
	SLdatetype* a;
	int size;//��ʾ�����д����˶�������
	int capactity;//��ʾ�����ܴ洢�������Ĵ�С
}s;
//��̬���ص㣺��������֮��Ͳ��ܲ��� ����ȷ�����ʵ������С
//�ӿں���
void SeqlistInit(s* s1);//��ʼ��
//void Seqlistm(s* s1);//��ʼ���ٿռ�
void Seqlistmm(s* s1);//����
void Seqlistdestory(s* s1);//����
void SeqlistPushBack(s* s1);//��β����
void SeqlistPopBack(s* s1);//��βɾ��
void SeqlistPushFront(s* s1);//��ͷ����
void SeqlistPopFront(s* s1);//��ͷɾ��
void SeqlistPrintf(s* s1);//��ӡ����
void SeqlistFind(s* s1);//�ҵ�x��λ�ò�����
void SeqlistPopn(s* s1);//ɾ��xλ�õ�����
void SeqlistPushn(s* s1);//����nλ��һ������