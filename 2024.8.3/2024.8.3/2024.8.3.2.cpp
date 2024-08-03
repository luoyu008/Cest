#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int a[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                a[i][j] = 1;
            }
            else if (i == j) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }

    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}