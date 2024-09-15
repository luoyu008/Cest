#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//与车相交的点
// 给你一个下标从 0 开始的二维整数数组 nums 表示汽车停放在数轴上的坐标。对于任意下标 i，nums[i] = [starti, endi] ，
// 其中 starti 是第 i 辆车的起点，endi 是第 i 辆车的终点。
//int numberOfPoints(int** nums, int numsSize, int* numsColSize) {
//    int* arr = (int*)calloc(101, sizeof(int));
//    for (int i = 0; i < numsSize; i++) {
//        for (int j = nums[i][0]; j <= nums[i][1]; j++) {
//            arr[j]++;
//        }
//    }
//    int count = 0;
//    for (int i = 0; i < 101; i++) {
//        if (arr[i] != 0)
//            count++;
//    }
//    return count;
//}
