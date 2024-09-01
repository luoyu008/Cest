#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.1.liianbiaozhan.h"
//void Test() {
//	slstack* sl = NULL;
//	bool judge=SLStackEmpty(sl);
//	if (judge)
//	{
//		printf("栈为空\n");
//	}
//	SLStackPush(&sl);
//	SLStackTop(&sl);
//	SLStackPush(&sl);
//	SLStackTop(&sl);
//	SLStackPush(&sl);
//	SLStackPrint(&sl);
//	//SLStackPop(&sl);
//	//SLStackPop(&sl);
//	//SLStackPop(&sl);
//	//SLStackPop(&sl);
//	int num=SLStackSize(&sl);
//	if (num == -1||num==0) {
//		printf("栈为空\n");
//	}
//	else {
//		printf("栈数据量为：%d\n", num);
//	}
//	SLStackDestroy(&sl);
//
//}
//int main() {
//	Test();
//	return 0;
//}























typedef struct SLstack
{
    char val;
    struct SLstack* next;
}slstack;
////int main() {
//    slstack* sl = NULL;
//    char* s = "()";
//    while (*s != '\0') {
//        if (*s == '(' || *s == '{' || *s == '[') {
//            if (sl == NULL) {
//                slstack* new = (slstack*)malloc(sizeof(slstack));
//                new->val = *s;
//                new->next = NULL;
//                sl = new;
//            }
//            else {
//                slstack* new = (slstack*)malloc(sizeof(slstack));
//                new->val = *s;
//                new->next = sl;
//                sl = new;
//            }
//        }
//        if (*s == '}' || *s == ']') {
//            if (*s-sl->val != 2)
//                printf( "false");
//            sl = sl->next;
//        }
//        if (*s == ')') {
//            if (*s-sl->val != 1)
//                printf("false");
//            sl = sl->next;
//        }
//        s++;
//    }
//    printf("true");
////}
//int main() {
//    int a = -1;
//    while (a)
//    {
//        printf("%d", a);
//        a++;
//    }
//    return 0;
//}