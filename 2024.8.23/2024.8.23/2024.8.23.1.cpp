#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.23.h"

//int main() {
//    int a, b;
//    while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
//        b = 2 * a + 1;
//        int count = 0;
//
//        for (int i = 0; i < b; i++) {
//
//            if (i < a) {
//                for (int j = 0; j < (2 * a) - (i * 2); j++) {
//                    printf(" ");
//                }
//                for (int j = 0; j < i + 1; j++) {
//                    printf("*");
//                }
//                printf("\n");
//            }
//            else if (i == a) {
//                for (int j = 0; j < a + 1; j++) {
//                    printf("*");
//                }
//                printf("\n");
//            }
//            else {
//                for (int j = 0; j < (i - a) * 2; j++) {
//                    printf(" ");
//                }
//                for (int j = 0; j < i - (2*count)-1; j++) {
//                    printf("*");
//                }
//                count++;
//                printf("\n");
//            }
//        }
//    }
//    return 0;
//}

int  findmax(int* p) {
    int temp = *p;
    int count = 0;
    for (int i = 0; i < 7; i++) {
        if (p[i] > temp) {
            temp = p[i];
            count = i;
        }
    }
    return count;
}
int  findmin(int* p) {
    int temp = *p;
    int count = 0;
    for (int i = 0; i < 7; i++) {
        if (p[i] < temp) {
            temp = p[i];
            count = i;
        }
    }
    return count;
}
int main() {
    /*int* p = (int*)calloc(8, sizeof(int));
    for (int i = 0; i < 7; i++) {
        scanf("%d", &p[i]);
    }*/
    int p[] = {99, 45, 78 ,67 ,72, 88, 60};
    int count1=findmax(p);
    int count2=findmin(p);
    p[count1] = 0;
    p[count2] = 0;
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum = sum + p[i];
    }
    printf("%.2lf\n", (double)sum / 5.00);
    return 0;
}