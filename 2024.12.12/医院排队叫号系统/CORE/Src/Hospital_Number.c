#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "Hospital_Number.h"
uint16_t Number_Count=0;
HL* newList;
/*
	此函数用于初始化带头双向循环链表
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
	此函数用于患者取号
	返回值是取到的号值
*/
uint16_t Hospital_patient_Take(HL** List){
	Number_Count++;
	HL* cur=(*List);
	
	while((cur->next)->val!=0){				/*当此节点的下一个节点的值为0的时候为尾节点*/
		cur=cur->next;
	}
	newList=(HL*)malloc(sizeof(HL));	/*申请新的节点*/
	newList->val=Number_Count;
	/*将新节点加入到列表中*/
	(cur->next)->pre=newList;				/*尾节点的下一个节点即头节点的上一个节点是新节点*/
	newList->next=cur->next;				/*新节点的下一个节点是尾节点的下一个节点即头节点*/
	newList->pre=cur;						/*新节点的上一个节点是尾节点*/
	cur->next=newList;						/*尾节点的下一个节是新节点*/
	
	return Number_Count;
}
/*
	此函数用于医生取号
	返回值为0时代表空即没有病人
	返回值为其他时代表有病人
*/
uint16_t Hospital_doctor_Take(HL** List){
	uint16_t num=0;
	HL* cur=(*List)->next;					/*寻找列表第二个节点*/
	if(cur->val==0){						/*当第二个节点的值等于第一个节点时代表只有头节点*/
		return 0;
	}
	num=cur->val;
	/*删除当前节点*/
	
	(cur->pre)->next=cur->next;				/*头结点的下一个节点是当前节点的下一个节点*/
	(cur->next)->pre=cur->pre;				/*下一个节点的上一个节点是头节点*/
	
	free(cur);								/*释放节点*/
	
	return num;
}
