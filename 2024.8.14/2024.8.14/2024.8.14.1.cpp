#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.14.h"
//typedef struct Square {
//    int bian;
//}square;
//typedef struct Rectangle {
//    int length;
//    int wide;
//    square s;
//}rectangle;
//typedef struct Cricle {
//    int cri;
//}Cri;
//typedef struct Shape {
//    int x;
//    int y;
//    rectangle r;
//    Cri  c;
//}shape;
//int GetArear(int a, int b) {
//    return a * b;
//}
//double GetAreac(int c) {
//    return c * c * 3.14;
//}
//int GetAreas(int a) {
//    return a * a;
//}
//int main() {
//    //shape* s;
//    shape* s= (shape*)calloc(1,sizeof(shape));
//    /*if (ss == NULL) {
//        printf("%s", strerror(errno));
//    }
//    else
//        s = ss;*/
//    scanf("%d %d", &s->r.length, &s->r.wide);
//    int ret = GetArear(s->r.length, s->r.wide);
//    scanf("%d", &s->c.cri);
//    double ret1 = GetAreac(s->c.cri);
//    scanf("%d", &s->r.s.bian);
//    int ret2 = GetAreas(s->r.s.bian);
//    printf("%d", ret);
//    printf("%.2lf", ret1);
//    printf("%d", ret2);
//    free(s);
//    s = NULL;
//    return 0;
//}

//int check(char* str, char* str1) {
//    for (int i = 0; i < 5; i++) {
//        if (str[i] != '?' && str[i] != str1[i])
//            return 0;
//    }
//    return 1;
//}
//int main() {
//    int temp = 0;
//    char time[6] = "?5:00";
//    char s[6] = "00:00";
//    int count = 0;
//    for (int h = 0; h < 24; h++) {
//        for (int m = 0; m <= 59; m++) {
//            sprintf(s, "%02d:%02d", h, m);
//            if (check(time, s)) {
//                count++;
//            }
//        }
//
//    }
//    printf("%d",count);
//    return 0;
//}