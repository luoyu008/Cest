#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define matrixRowLen 10
#define matrixColLen 10
//求矩阵最小路径和
//int main() {
//    int matrix[matrixRowLen][matrixColLen] = { {3,3,1,6,7,6,0,7,8,0},
//        {5,0,5,0,5,3,9,8,0,4 },
//        {2,8,8,9,0,6,8,7,6,7},
//        {6,1,0,9,0,9,6,0,6,6 },
//        {2,3,6,9,5,3,2,4,3,4},
//        {1,5,2,1,4,5,8,4,2,6 },
//        {3,0,0,5,0,0,4,6,2,2},
//        {4,6,6,2,5,1,7,9,8,0 },
//        {3,1,7,7,2,4,2,0,8,6},
//        {9,4,7,9,9,7,1,4,5,5 }
//};
//    for (int i = 0; i < matrixRowLen; i++) {
//        for (int j = 0; j < matrixColLen; j++) {
//            if (i == 0 && j > 0)
//                matrix[i][j] += matrix[i][j - 1];
//            if (i > 0 && j == 0)
//                matrix[i][j] += matrix[i - 1][j];
//            if ((i > 0 && j > 0) && matrix[i - 1][j] < matrix[i][j - 1])
//                matrix[i][j] += matrix[i - 1][j];
//            else if((i > 0 && j > 0) && matrix[i - 1][j] >= matrix[i][j - 1])
//                matrix[i][j] += matrix[i][j - 1];
//        }
//    }
//    printf("%d", matrix[matrixRowLen - 1][matrixColLen - 1]);
//	return 0;
//}
//把数字翻译为字符串
int main() {
    //int count = 0;
    //const char* nums = "31717126241541717";
    //int a[50];
    //int len = strlen(nums);
    //a[0] = 1;
    //a[1] = 1;
    //if (*nums - '0' == 0)
    //    return 0;
    //if (len==2&&(*nums - '0') * 10 + *(nums + 1) - '0' == 10 || (*nums - '0') * 10 + *(nums + 1) - '0' == 20)
    //    return 1;
    //for (int i = 1; i < len; i++) {
    //    if (nums[i] - '0' == 0)
    //        if ((nums[i - 1] - '0' != 1 && nums[i - 1] - '0' != 2) || nums[i + 1] - '0' == 0)
    //            return 0;
    //}
    //for (int i = 2; i < len; i++) {
    //    if (((nums[i - 2] - '0') * 10 + (nums[i-1] - '0') >= 11
    //        && (nums[i - 2] - '0') * 10 + (nums[i-1] - '0') <= 19) || (
    //            ((nums[i - 2] - '0') * 10 + (nums[i-1] - '0') >= 21) &&
    //            ((nums[i - 2] - '0') * 10 + (nums[i-1] - '0') <= 26)))
    //        a[i ] = a[i-2] + a[i - 1];
    //    else
    //        a[i] = a[i - 1];
    //}
    //printf("%d", a[len-1]);
    //return a[len];
    const char* nums = "31717126241541717";
        int len = strlen(nums);
        int* result = (int*)malloc(sizeof(int) * (len + 1));
        result[0] = 1;
        if (nums[0] != '0') {
            result[1] = 1;
        }
        printf("%d\n", result[1]);
        for (int i = 1; i < len; i++) {
            if (nums[i] == '0') {
                if (nums[i - 1] == '0') {
                    return 0;
                }
            }
            else {
                result[i + 1] += result[i];
            }
            if (nums[i - 1] == '1') {
                result[i + 1] += result[i - 1];
            }
            else if (nums[i - 1] == '2' && nums[i] <= '6') {
                result[i + 1] += result[i - 1];
            }
        }
        return result[len];
    }

