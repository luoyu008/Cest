#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.30.h"
//所有数对中数位差之和
//int main() {
//    int nums[] = { 50,28,48 };
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    long long temp = 0;
//    while (nums[0] > 0) {
//        int count[10] = { 0 };
//        for (int i = 0; i < numsSize; i++) {
//            count[nums[i] % 10] += 1;
//            nums[i] = nums[i] / 10;
//        }
//        for (int i = 0; i < 10; i++) {
//            temp += (long long)count[i] * (numsSize - count[i]);
//        }
//    }
//    printf("%d", temp);
//	return 0;
//}


//反转链表
//int main() {
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    while (cur != NULL) {
//        struct ListNode* next = cur->next;
//        cur->next = newhead;
//        newhead = cur;
//
//        cur = next;
//        if (next)
//            next = next->next;
//
//    }
//    return newhead;
//}

//返回链表中倒数第k个节点
//int kthToLast(struct ListNode* head, int k) {
//    int count = 0;
//    struct ListNode* temp = head;
//    while (temp != NULL) {
//        temp = temp->next;
//        count++;
//    }
//    int count1 = 0;
//    while (head != NULL) {
//        count1++;
//        if (count1 == count - k + 1)
//            break;
//        head = head->next;
//    }
//    return head->val;
//}


//分割链表
//void SListpushfront(struct ListNode** hhead, struct ListNode* temp, struct ListNode* find) {
//    struct ListNode* prev = NULL;
//    if (temp == *hhead) {
//        find->next = *hhead;
//        *hhead = find;
//    }
//    else {
//        struct ListNode* count = *hhead;
//        while (count->next != NULL) {
//            if ((count->next) == temp)
//                break;
//            else
//                count = (count)->next;
//        }
//        (count)->next = find;
//        find->next = temp;
//    }
//}
//struct ListNode* partition(struct ListNode* head, int x) {
//    struct ListNode* temp = head;
//    while (temp != NULL) {
//        if (temp->val >= x)
//            break;
//        temp = temp->next;
//    }
//    struct ListNode* find = temp;
//    struct ListNode* prevfind = NULL;
//    while (find != NULL) {
//        prevfind = find;
//        find = find->next;
//
//        if (find)
//            if (find->val < x) {
//                prevfind->next = find->next;
//                SListpushfront(&head, temp, find);
//                find = prevfind;
//            }
//
//    }
//    return head;
//}

//环形链表的判断
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    if (head == NULL)
//        return false;
//    if (head->next == NULL)
//        return false;
//    while (fast != NULL && fast->next != NULL) {
//
//        slow = slow->next;
//
//        fast = fast->next->next;
//
//
//        if (slow == fast) {
//            return true;
//        }
//    }
//    return false;
//}

//返回环形链表环的进入节点
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    struct ListNode* temp = NULL;
//    while (fast != NULL && fast->next != NULL) {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast) {
//            temp = fast;
//            break;
//        }
//    }
//    if (temp == NULL) {
//        return NULL;
//    }
//    while (temp != head) {
//        head = head->next;
//        temp = temp->next;
//        if (temp == head) {
//            break;
//        }
//    }
//    return temp;
//}

//