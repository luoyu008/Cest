#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//typedef struct ListNode {
//    int val;
//    struct ListNode* next;
// }l;
//void STACKPush(struct ListNode** new, int num) {
//    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
//    if (temp == NULL) {
//        // 处理内存分配失败的情况  
//        return;
//    }
//    temp->val = num;
//    temp->next = NULL;
//
//    if (*new == NULL) {
//        *new = temp;
//    }
//    else {
//        struct ListNode* cur = *new;
//        while (cur->next != NULL) {
//            cur = cur->next;
//        }
//        cur->next = temp;
//    }
//} 
//
//int main(){
//    struct ListNode* head=NULL;
//    STACKPush(&head, 0);
//    STACKPush(&head, 3);
//    STACKPush(&head, 1);
//    STACKPush(&head, 0);
//    STACKPush(&head, 4);
//    STACKPush(&head, 5);
//    STACKPush(&head, 2);
//    STACKPush(&head, 0);
//    struct ListNode* cur = head;
//    // while(cur->next!=NULL){
//    //     if(cur->val==0)
//    //     zeronum++;
//    //     cur=cur->next;
//    // }
//    struct ListNode* new = NULL;//(struct ListNode*)malloc(sizeof(struct ListNode)*(zeronum-1));
//    cur = head->next;
//    int count = 0;
//    while (cur != NULL) {
//        if (cur->val != 0) {
//            count = count + cur->val;
//        }
//        if (cur->val == 0) {
//            STACKPush(&new, count);
//            count = 0;
//        }
//        cur = cur->next;
//    }
//    head = new;
//    return 0;
//}