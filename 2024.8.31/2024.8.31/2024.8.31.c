#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.31.h"
void test() {
	list* plist = ListInit();
	/*ListPushBack(plist);
	ListPushBack(plist);
	ListPushBack(plist);
	ListPushBack(plist);*/
	ListPushFront(plist);
	ListPushFront(plist);
	ListPushFront(plist);
	ListPushFront(plist);
	ListPushFront(plist); 
	/*ListEarse(plist);
	ListPrint(plist);
	ListEarse(plist);
	ListPrint(plist);
	ListEarse(plist);
	ListPrint(plist);
	ListEarse(plist);
	ListPrint(plist);*/
	ListInsertB(plist);
	//ListFind(plist);
      //ListInsertF(plist);
	/*ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);*/
	/*ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);*/
	  ListPrint(plist);
}

int main() {
	test();
	return 0;
}
//随机链表的复制
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* cur = head;
//    if (head == NULL)
//        return NULL;
//    //在原节点后连接一个与前一个结点一样的节点
//    while (cur != NULL) {
//        struct Node* new = (struct  Node*)malloc(sizeof(struct Node));
//        new->val = cur->val;
//        new->next = cur->next;
//        cur->next = new;
//        cur = new->next;
//    }
//    cur = head;
//    while (cur) {
//        struct Node* new = cur->next;
//        if (cur->random == NULL) {
//            new->random = NULL;
//        }
//        else
//            new->random = cur->random->next;
//        cur = new->next;
//    }
//    cur = head;
//    struct Node* newhead = NULL;
//    struct Node* newtail = NULL;
//    while (cur) {
//        struct Node* new = cur->next;
//        struct Node* next = new->next;
//        if (newhead == NULL) {
//            newhead = new;
//            newtail = new;
//        }
//        else {
//            newtail->next = new;
//            newtail = new;
//        }
//        cur->next = next;
//        cur = next;
//    }
//    return newhead;
//}

