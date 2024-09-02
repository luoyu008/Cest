#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.2.h"
//考试最大困扰度
// 即改变k个字符串 使字符串中有连续最长的T字符串或者F字符串
// 使用滑动窗口的思想分别记录T的情况下最大字符串出现的可能和F的情况下最大字符串出现的可能 返回二者最大值
//int maxConsecutiveChar(const char* answerKey, int k, char ch) {
//    int n = strlen(answerKey);
//    int ans = 0;
//    for (int left = 0, right = 0, sum = 0; right < n; right++) {
//        sum += answerKey[right] != ch;
//        while (sum > k) {
//            sum -= answerKey[left++] != ch;
//        }
//        ans = ans>right - left + 1?ans:right-left+1;
//    }
//    return ans;
//}
//int main() {
//    char* answerKey = "FFTFTTTFFF";
//    int k = 1;
//    int cnt1 = maxConsecutiveChar(answerKey, k, 'T');
//    int cnt2 = maxConsecutiveChar(answerKey, k, 'F');
//    printf("%d", cnt1>cnt2?cnt1:cnt2);
//	return 0;
//}


//用两个栈来模拟实现队列
// 即Pop数据时 Pop是s2栈的栈顶 若s2为空则将s1中的数组由栈顶至栈底的顺序Push到s2中再Pop
//typedef struct STACK
//{
//    int val;
//    struct STACK* next;
//}stack;
//
//typedef struct {
//    stack* s1;
//    stack* s2;
//} MyQueue;
//
////入栈
//void STACKPush(stack** ss, int x) {
//    stack* new = (stack*)malloc(sizeof(stack));
//    new->val = x;
//    if (*ss == NULL) {
//        new->next = NULL;
//        *ss = new;
//    }
//    else {
// 
//            cur = cur->next;
//        }
//        new->next = NULL;
//        cur->next = new;
//    }
//}
////出栈
//void STACKPop(stack** ss)
//{
//    if (*ss == NULL)
//        return;
//    if ((*ss)->next == NULL) {
//        free(*ss);
//        *ss = NULL;
//    }
//    else {
//        stack* tail = *ss;
//        stack* tailprev = *ss;
//        while (tail->next != NULL)
//        {
//            tailprev = tail;
//            tail = tail->next;
//        }
//        tailprev->next = NULL;
//        free(tail);
//        tail = NULL;
//    }
//}
////判空
//bool STACKEmpty(stack** ss)
//{
//    return *ss == NULL;
//}
////栈顶元素
//int STACKBack(stack** ss)
//{
//    stack* tail = *ss;
//    while (tail->next != NULL) {
//        tail = tail->next;
//    }
//    return tail->val;
//}
////栈底元素
//int STACKFron(stack** ss) {
//    return (*ss)->val;
//}
////栈销毁
//void STACKDestroy(stack** ss)
//{
//    stack* tail = *ss;
//    stack* tailprev = NULL;
//    while (tail != NULL) {
//        tailprev = tail;
//        tail = tail->next;
//        free(tailprev);
//        tailprev = NULL;
//    }
//}
//MyQueue* myQueueCreate() {
//    MyQueue* m1 = (MyQueue*)malloc(sizeof(MyQueue));
//    m1->s1 = NULL;
//    m1->s2 = NULL;
//    return m1;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    STACKPush(&(obj->s1), x);
//}
//
//int myQueuePop(MyQueue* obj) {
//    int x = 0;
//    if (STACKEmpty(&(obj->s2))) {
//        while (!STACKEmpty(&(obj->s1))) {
//            STACKPush(&(obj->s2), STACKBack(&(obj->s1)));
//            STACKPop(&(obj->s1));
//        }
//    }
//    x = STACKBack(&(obj->s2));
//    STACKPop(&(obj->s2));
//    return x;
//}
//
//int myQueuePeek(MyQueue* obj) {
//    int x = 0;
//    if (STACKEmpty(&(obj->s2))) {
//        while (!STACKEmpty(&(obj->s1))) {
//            STACKPush(&(obj->s2), STACKBack(&(obj->s1)));
//            STACKPop(&(obj->s1));
//        }
//    }
//    x = STACKBack(&(obj->s2));
//    return x;
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//    return STACKEmpty((&obj->s1)) && STACKEmpty(&(obj->s2));
//}
//
//void myQueueFree(MyQueue* obj) {
//    STACKDestroy(&(obj->s1));
//    STACKDestroy(&(obj->s2));
//    free(obj);
//}
  
//用两个队列实现栈
// 即Pop时先将s1中的前n-1个数据Push到s2中再Pop
//typedef struct QUEUE {
//	int val;
//	struct QUEUE* next;
//}queue;
//typedef struct Queue {
//	queue* head;
//	queue* tail;
//}q;
//
//typedef struct {
//	q q1;
//	q q2;
//} MyStack;
//
////初始化
//void QUEUEInit(q* pp) {
//	assert(pp);
//	pp->head = NULL;
//	pp->tail = NULL;
//}
////判空
//bool QUEUQEmpty(q* pp) {
//	assert(pp);
//	return pp->head == NULL;
//}
////入队
//void QUEUEPush(q* pp, int x) {
//	assert(pp);
//	bool judge = QUEUQEmpty(pp);
//	queue* new = (queue*)malloc(sizeof(queue));
//	new->val = x;
//	new->next = NULL;
//	if (judge) {
//		pp->head = new;
//		pp->head->next = NULL;
//		pp->tail = new;
//	}
//	else {
//		queue* cur = pp->head;
//		new->next = cur;
//		pp->head = new;
//	}
//}
////出队
//void QUEUEPop(q* pp) {
//	assert(pp);
//	bool judge = QUEUQEmpty(pp);
//	if (judge) {
//		return;
//	}
//	else {
//		if (pp->head == pp->tail) {
//			free(pp->head);
//			pp->head = NULL;
//			pp->tail = NULL;
//		}
//		else {
//			queue* now = pp->head;
//			queue* tailprev = NULL;
//			while (now != NULL)
//			{
//				if (now->next == pp->tail) {
//					tailprev = now;
//					break;
//				}
//				now = now->next;
//			}
//			queue* temp = pp->tail;
//			pp->tail = tailprev;
//			pp->tail->next = NULL;
//			free(temp);
//			temp = NULL;
//		}
//	}
//}
////销毁
//void QUEUEDestroy(q* pp) {
//	assert(pp);
//	bool judge = QUEUQEmpty(pp);
//	if (judge) {
//		return;
//	}
//	else {
//		queue* cur = pp->head;
//		while (cur != NULL) {
//			queue* nect = cur->next;
//			free(cur);
//			cur = nect;
//		}
//		pp->head = pp->tail = NULL;
//	}
//}
////队头数据
//int QUEUEFront(q* pp) {
//	assert(pp);
//	bool judge = QUEUQEmpty(pp);
//	if (judge) {
//		return -1;
//	}
//	else {
//		int x = 0;
//		x = pp->tail->val;
//		return x;
//	}
//}
////队尾数据
//int QUEUEBack(q* pp) {
//	assert(pp);
//	bool judge = QUEUQEmpty(pp);
//	if (judge) {
//		return -1;
//	}
//	else {
//		int x = 0;
//		x = pp->head->val;
//		return x;
//	}
//}
////队数据量
//int QUEUESize(q* pp) {
//	assert(pp);
//	bool judge = QUEUQEmpty(pp);
//	if (judge) {
//		return -1;
//	}
//	else {
//		int x = 0;
//		queue* cur = pp->head;
//		while (cur != NULL) {
//			x++;
//			cur = cur->next;
//		}
//		return x;
//	}
//}
//
//MyStack* myStackCreate() {
//	MyStack* mystack = (MyStack*)malloc(sizeof(MyStack));
//	QUEUEInit(&mystack->q1);
//	QUEUEInit(&mystack->q2);
//	return mystack;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	if (!QUEUQEmpty(&obj->q1)) {
//		QUEUEPush(&obj->q1, x);
//	}
//	else {
//		QUEUEPush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	int x = -1;
//	if (!QUEUQEmpty(&obj->q1)) {
//		while (QUEUESize(&obj->q1) > 1) {
//			QUEUEPush(&obj->q2, QUEUEFront(&obj->q1));
//			QUEUEPop(&obj->q1);
//		}
//		x = QUEUEBack(&obj->q1);
//		QUEUEPop(&obj->q1);
//	}
//	else if (!QUEUQEmpty(&obj->q2)) {
//		while (QUEUESize(&obj->q2) > 1) {
//			QUEUEPush(&obj->q1, QUEUEFront(&obj->q2));
//			QUEUEPop(&obj->q2);
//		}
//		x = QUEUEBack(&obj->q2);
//		QUEUEPop(&obj->q2);
//	}
//	return x;
//}
//
//int myStackTop(MyStack* obj) {
//	int x = 0;
//	if (!QUEUQEmpty(&obj->q1)) {
//		x = QUEUEBack(&obj->q1);
//	}
//	if (!QUEUQEmpty(&obj->q2)) {
//		x = QUEUEBack(&obj->q2);
//	}
//	return x;
//}
//
//bool myStackEmpty(MyStack* obj) {
//	return QUEUQEmpty(&obj->q1) && QUEUQEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//	QUEUEDestroy(&obj->q1);
//	QUEUEDestroy(&obj->q2);
//	free(obj);
//}


//设计循环队列
// 即在q2队列前设置一个q1队列当q2队列满之后将q2队头数据放入q1之后在进行入队
//typedef  struct QUEUE {
//    int* val;
//    int top;
//    int capacity;
//}queue;
//typedef struct {
//    queue q1;
//    queue q2;
//} MyCircularQueue;
////队列初始化
//void QUEUEInit(queue* q, int k) {
//    q->val = (int*)malloc(sizeof(int) * k);
//    q->top = -1;
//    q->capacity = k;
//}
////入队
//void QUEUEPush(queue* q, int x) {
//    if (q->top >= q->capacity - 1)
//        return;
//    q->top++;
//    for (int i = q->top; i >= 1; i--) {
//        q->val[i] = q->val[i - 1];
//    }
//    q->val[0] = x;
//}
////出队
//void QUEUEPop(queue* q) {
//    if (q->top > -1)
//        q->top--;
//    else
//        return;
//}
////取队头元素
//int QUEUEFront(queue* q) {
//    return q->val[q->top];
//}
////取队尾元素
//int QUEUEBack(queue* q)
//{
//    return q->val[0];
//}
////判满
//bool QUEEUFULL(queue* q) {
//    return q->top == q->capacity - 1;
//}
////判有无元素
//bool QUEUEjuddge(queue* q)
//{
//    return q->top != -1;
//}
////销毁
//void QUEUEEDestroy(queue* q)
//{
//    free(q->val);
//    q->top = -1;
//    q->capacity = 0;
//}
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* m = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    QUEUEInit(&(m->q1), k / 2);
//    QUEUEInit(&(m->q2), k - k / 2);
//    return m;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//
//    if (!QUEEUFULL(&(obj->q2))) {
//        QUEUEPush(&(obj->q2), value);
//        return true;
//    }
//    else if (QUEEUFULL(&(obj->q2)) && !QUEEUFULL(&(obj->q1)))
//    {
//        QUEUEPush(&(obj->q1), QUEUEFront(&(obj->q2)));
//        QUEUEPop(&(obj->q2));
//        QUEUEPush(&(obj->q2), value);
//        return true;
//    }
//    return false;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (QUEEUFULL(&(obj->q2)) && QUEUEjuddge(&(obj->q1))) {
//        QUEUEPop(&(obj->q1));
//        return true;
//    }
//    else if (QUEUEjuddge(&(obj->q2)) && !QUEUEjuddge(&(obj->q1))) {
//        QUEUEPop(&(obj->q2));
//        return true;
//    }
//    else
//        return false;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (!QUEUEjuddge(&(obj->q1)) && !QUEUEjuddge(&(obj->q2))) {
//        return -1;
//    }
//    if (QUEUEjuddge(&(obj->q1))) {
//        return QUEUEFront(&(obj->q1));
//    }
//    else
//        return QUEUEFront(&(obj->q2));
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (!QUEUEjuddge(&(obj->q2))) {
//        return -1;
//    }
//    else
//        return QUEUEBack(&(obj->q2));
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return !QUEUEjuddge(&(obj->q2));
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    return QUEEUFULL(&(obj->q1));
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    QUEUEEDestroy(&(obj->q1));
//    QUEUEEDestroy(&(obj->q2));
//    free(obj);
//}