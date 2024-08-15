#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.15.h"
//int main() {
//    int nums[] = {4,3,1,6};
//    int queries[][2] = { {0,2},{2,3} };
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    int* d = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++) {
//        d[i] = 1;
//    }
//    for (int i = 0; i < numsSize-1; i++) {
//        if ((nums[i] ^ nums[i+1]) & 1) {
//            d[i+1] = d[i] + 1;
//        }
//    }
//    bool* r = (bool*)malloc(sizeof(bool) * 2);
//    for (int i = 0; i < 2; i++) {
//        int x = queries[i][0];
//        int y = queries[i][1];
//        r[i] = (d[y] >= y - x + 1);
//    }
//    free(d);
//    d = NULL;
//    for (int i = 0; i < 2; i++) {
//        printf("%d", r[i]);
//    }
//    free(r);
//    r = NULL;
//	return 0;
//}
