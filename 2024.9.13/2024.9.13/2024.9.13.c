#define _CRT_SECURE_NO_WARNINGS
//两数相加链表版
void LinstPop(struct ListNode** str) {
    struct ListNode* cur = *str;
    struct ListNode* prev = cur;
    if (cur->next == NULL) {
        free(cur);
        *str = NULL;
        return;
    }
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    free(cur);
    prev->next = NULL;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = 0;
    new->next = NULL;
    struct ListNode* result = new;
    int count = 0;
    int count1 = 0;
    while (l1 != NULL || l2 != NULL || count != 0) {
        count = count1;
        if (l1) {
            count += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            count += l2->val;
            l2 = l2->next;
        }
        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->val = count % 10;
        count1 = count / 10;
        cur->next = NULL;
        new->next = cur;
        new = cur;
    }
    result = result->next;
    LinstPop(&result);
    if (result == NULL) {
        result = (struct ListNode*)malloc(sizeof(struct ListNode));
        result->val = 0;
        result->next = NULL;
    }
    return result;
}