#pragma once
//该文件用于函数声明等
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<iostream>
#define MAX 100
#define NAME 10
#define TEL 20
#define SEX 5
#define ADDR 30
//菜单
void menu();

//人员信息
typedef struct people {
	char name[NAME];
	int age;
	char tel[TEL];
	char sex[SEX];
	char addr[ADDR];
}people;
//通讯录信息
 typedef struct con {
    people date[MAX];
	int count;//记录存入了多少通讯录信息
}Contact ;

 //通讯录初始化
 void Initcon(Contact* contact);
 //添加联系人
 void Addcon(Contact* contact);
 //删除联系人
 void Delecon(Contact* contact);
 //查找联系人
 void Findcon(Contact* contact);
 //修改联系人
 void Revisecon(Contact* contact);
 //排序联系人
 void Sortcon(Contact* contact);
 //显示已有的联系人信息
 void Showcon(const Contact* contact);
