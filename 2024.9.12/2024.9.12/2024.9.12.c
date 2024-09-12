#define _CRT_SECURE_NO_WARNINGS
//求出最多标记下标
int cmp(const void* str1, const void* str2) {
    return *(int*)str1 - *(int*)str2;
}
int maxNumOfMarkedIndices(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int j = (numsSize + 1) / 2;
    int count = 0;
    for (j; j < numsSize; j++) {
        if (2 * nums[i] <= nums[j])
        {
            count += 2;
            i++;
        }
    }
    return  count;
}