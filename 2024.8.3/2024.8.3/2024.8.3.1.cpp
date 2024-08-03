#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//void rever(char str[]) {
//    int left = 0;
//    int right = (strlen(str) - 1);
//    while (left < right) {
//        char temp = *(str+left);
//        *(str+left) = *(str+right);
//        *(str+right) = temp;
//        left++;
//        right--;
//    }
//}
//int main() {
    ////字符串逆序
    // char  s[10] = "";
    //gets_s(s);
    //rever(s);
    //for (int i = 0; i <=strlen(s)-1; i++) {
    //    printf("%c", s[i]);
    //}
    //return 0;
    //有序序列合并
   /* 5 6
        1 3 7 9 22
        2 8 10 17 33 44*/
        //int a = 5;
        //int b = 6;
        //int a1[5] = {1,3,7,9,22};
        //int a2[6] = {2,8,10,17,33,44};
        //int i = 0;
        //int j = 0;
        //scanf("%d %d", &a, &b);
        //for (i = 0; i < a; i++) {
        //    scanf("%d ", &a1[i]);
        //}
        //for (j = 0; j < b; j++) {
        //    scanf("%d ", &a2[j]);
        //}
        ////int c = a + b;
        ////int a3[11];
        ////for (i = 0; i < c; i++) {
        ////    if (i < a)
        ////        a3[i] = a1[i];
        ////    else
        ////        a3[i] = a2[i - a];
        ////}
        ////for (i = 0; i < c-1; i++) {
        ////    for (j = 0; j < c - 1 - i; j++) {
        ////        if (a3[j] > a3[j + 1]) {
        ////            int temp = a3[j];
        ////            a3[j] = a3[j + 1];
        ////            a3[j + 1] = temp;
        ////        }

        ////    }
        ////}
        ////for (i = 0; i < c; i++) {
        ////    printf("%d ", a3[i]);
        ////}
        //for (i = 0; i < a; i++) {
        //    scanf("%d ", &a1[i]);
        //}
        //for (j = 0; j < b; j++) {
        //    scanf("%d ", &a2[j]);
        //}
        //// int c=a>b?a:b;
        //// for(i=0;i<c;i++){

        //// }
        //i = 0;
        //j = 0;
        //while (i < a && j < b) {
        //    if (a1[i] >= a2[j]) {
        //        printf("%d ", a2[j]);
        //        j++;
        //    }
        //    if (a1[i] < a2[j]) {
        //        printf("%d ", a1[i]);
        //        i++;
        //    }
        //}
        //if (j == b) {
        //    for (; i < a; i++) {
        //        printf("%d ", a1[i]);
        //    }
        //}
        //else {
        //    for (; j < b; j++) {
        //        printf("%d ", a2[j]);
        //    }
        //}
    //指针数组模拟二维数组
    //int a[] = { 1,2,3,4 };
    //int b[] = { 5,6,7,8 };
    //int c[] = { 9,10,11,12 };
    //int* p[] = { a,b,c };
    //int i = 0;
    //for (i = 0; i < 3; i++) {
    //    for (int j = 0; j < 4; j++) {
    //        printf("%d ", *(*(p + i) + j));
    //        printf("%d ", p[i][j]);
    //        printf("%d ", *(p[i]) + j);
    //    }
    //    printf("\n");
    //}
    //int a1[10];
    //int(*p)[10] = &a1;
    //移除元素
    //int i = 0;
    //int count = 0;
    //for (i = 0; i < numsSize-count+1; i++) {
    //    if (nums[i] == val) {
    //        for (int j = i + 1; j <= numsSize - 1; j++) {
    //            nums[j - 1]=nums[j];
    //        }
    //        count++;
    //        i--;
    //    }
    //}
    //for (i = 0; i <= numsSize - count; i++) {
    //    printf("%d ", nums[i]);
    //}
    //    return 0;
//int left = 0;
//int nums[] = { 0,1,2,2,3,0,4,2 };
//int val = 2;
//int numsSize = sizeof(nums) / sizeof(nums[0]);
//for (int right = 0; right < numsSize; right++) {
//    if (nums[right] != val) {
//        nums[left] = nums[right];
//        left++;
//    }
//}
//return left;
//1
//
//1 1
//
//1 2 1
//
//1 3 3 1
//杨辉三角
//int a[10][10];
//for (int i = 0; i < 10; i++) {
//    for (int j = 0; j <= i; j++) {
//        if (j == 0) {
//            a[i][j] = 1;
//        }
//        else if (i == j) {
//            a[i][j] = 1;
//        }
//        else {
//            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//        }
//    }
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j <= i; j++) {
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }
//}
//return 0;
//