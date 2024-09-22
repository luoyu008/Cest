#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//找到小镇的法官
int main() {
    int trust[][2] = { {1,3},{2,3} };
    int trustSize = 2;
    int n = 3;
    int* in = (int*)calloc(10001, sizeof(int));
    int* out = (int*)calloc(10001, sizeof(int));
    for (int i = 0; i < trustSize; i++) {
        out[trust[i][0]]++;
    }
    for (int i = 0; i < trustSize; i++) {
        in[trust[i][1]]++;

    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == n - 1 && out[i] == 0)
            return i;
    }
    return -1;
}