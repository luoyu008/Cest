#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
//一个数字中如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0
//int main() {
//    int n = 10011010;
//    int count = 0;
//    int i = 0;
//    int num = 0;
//    //scanf("%d", &n);
//    while (n > 0) {
//        int temp = n % 10;
//        n = n / 10;
//        count++;
//        if (temp % 2 != 0)
//        {
//            temp = 1;
//            num = num + temp * pow(10, count - 1);
//        }
//        else {
//            temp = 0;
//            num = num + temp * pow(10, count - 1);
//        }
//    }
//    printf("%d", num);
//    return 0;
//

//带空格的直角三角形图案
//void printfn(int a, char a1[a][2 * a - 1]) {
//    for (int i = 0; i < a; i++) {
//        for (int j = 0; j <= 2 * (a - 1); j++) {
//            a1[i][j] = ' ';
//        }
//    }
//    for (int i = 0; i < a; i++) {
//        for (int j = 2 * (a - 1); j >= 2 * (a - 1) - (2 * i); j = j - 2) {
//            a1[i][j] = '*';
//        }
//    }
//    for (int i = 0; i < a; i++) {
//        for (int j = 0; j <= 2 * (a - 1); j++) {
//            printf("%c", a1[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int a;
//    while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
//        char a1[a][2 * a - 1];
//        printfn(a, a1);
//
//    }
//    return 0;
//}
#define num 6
int main() {
    //int num = 0;
    char s[50] = {'a','b','c','d','e','f'};
    //scanf("%d", &num);
    int a[num];
    //scanf("%s", &s);
    for (int i = 0; i < num; i++) {
        scanf("%d ", &a[i]);
    }
    for (int i = 0; i < num; i++) {
        printf("%c", s[a[i] - 1]);
    }
    return 0;
}
//#define t 3
//int main(int argc, char* argv[])
//{
//    /*int t = 0;
//    scanf("%d", &t);*/
//    char s1[t][1001] = { "aba" ,"abc" ,"c",};
//    char ss1[t][1001] ;
//    char* sss1[t];
//    char s2[t][1001] = { "aac" ,"ade" ,"d" };
//    char ss2[t][1001];
//    char sss2[t];
//    int flag = 0;
//    /*for (int i = 0; i < t; i++) {
//        scanf("%s", &s1[i][1001]);
//        scanf("%s", &s2[i][1001]);
//    }*/
//    for (int i = 0; i < t; i++) {
//        // if(strlen(s1[i]==1)){
//        // printf("YES\n");
//        // continue;
//        // }
//        int len = strlen(s1[i]);
//        for (int j = 0; j < len; j++) {
//            for (int n = 0; n < len && n != j;n++ ) {
//                *(ss1+n) = s1[i][n];
//            }
//            for (int k = 0; k < len; k++) {
//                for (int n = 0; n < len && n != k;n++) {
//                    sss2[n] = s2[i][n];
//                }
//                if (strstr(ss1 ,sss2)) {
//                    flag = 1;
//                    break;
//                }
//                else {
//                    flag = 0;
//                }
//            }
//        }
//        if (flag == 1)
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}