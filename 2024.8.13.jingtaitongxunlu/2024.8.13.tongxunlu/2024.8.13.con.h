#pragma once
//���ļ����ں���������
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<iostream>
#define MAX 100
#define NAME 10
#define TEL 20
#define SEX 5
#define ADDR 30
//�˵�
void menu();

//��Ա��Ϣ
typedef struct people {
	char name[NAME];
	int age;
	char tel[TEL];
	char sex[SEX];
	char addr[ADDR];
}people;
//ͨѶ¼��Ϣ
 typedef struct con {
    people date[MAX];
	int count;//��¼�����˶���ͨѶ¼��Ϣ
}Contact ;

 //ͨѶ¼��ʼ��
 void Initcon(Contact* contact);
 //�����ϵ��
 void Addcon(Contact* contact);
 //ɾ����ϵ��
 void Delecon(Contact* contact);
 //������ϵ��
 void Findcon(Contact* contact);
 //�޸���ϵ��
 void Revisecon(Contact* contact);
 //������ϵ��
 void Sortcon(Contact* contact);
 //��ʾ���е���ϵ����Ϣ
 void Showcon(const Contact* contact);
