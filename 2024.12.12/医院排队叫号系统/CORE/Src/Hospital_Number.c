#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "Hospital_Number.h"
uint16_t Number_Count=0;
HL* newList;
/*
	�˺������ڳ�ʼ����ͷ˫��ѭ������
*/
HL* Hospital_List_Init(void){
	HL* List1 =(HL*)malloc(sizeof(HL));
	if(List1==NULL){
		return NULL;
	}
	List1->pre=List1;
	List1->val=0;
	List1->next=List1;
	return List1;
}

/*
	�˺������ڻ���ȡ��
	����ֵ��ȡ���ĺ�ֵ
*/
uint16_t Hospital_patient_Take(HL** List){
	Number_Count++;
	HL* cur=(*List);
	
	while((cur->next)->val!=0){				/*���˽ڵ����һ���ڵ��ֵΪ0��ʱ��Ϊβ�ڵ�*/
		cur=cur->next;
	}
	newList=(HL*)malloc(sizeof(HL));	/*�����µĽڵ�*/
	newList->val=Number_Count;
	/*���½ڵ���뵽�б���*/
	(cur->next)->pre=newList;				/*β�ڵ����һ���ڵ㼴ͷ�ڵ����һ���ڵ����½ڵ�*/
	newList->next=cur->next;				/*�½ڵ����һ���ڵ���β�ڵ����һ���ڵ㼴ͷ�ڵ�*/
	newList->pre=cur;						/*�½ڵ����һ���ڵ���β�ڵ�*/
	cur->next=newList;						/*β�ڵ����һ�������½ڵ�*/
	
	return Number_Count;
}
/*
	�˺�������ҽ��ȡ��
	����ֵΪ0ʱ����ռ�û�в���
	����ֵΪ����ʱ�����в���
*/
uint16_t Hospital_doctor_Take(HL** List){
	uint16_t num=0;
	HL* cur=(*List)->next;					/*Ѱ���б�ڶ����ڵ�*/
	if(cur->val==0){						/*���ڶ����ڵ��ֵ���ڵ�һ���ڵ�ʱ����ֻ��ͷ�ڵ�*/
		return 0;
	}
	num=cur->val;
	/*ɾ����ǰ�ڵ�*/
	
	(cur->pre)->next=cur->next;				/*ͷ������һ���ڵ��ǵ�ǰ�ڵ����һ���ڵ�*/
	(cur->next)->pre=cur->pre;				/*��һ���ڵ����һ���ڵ���ͷ�ڵ�*/
	
	free(cur);								/*�ͷŽڵ�*/
	
	return num;
}
