#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//判断字符旋转结果
//int judge(const char* s,const char* s2) {
//	if (strstr(s, s2) != NULL) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//左旋转字符
//void left(char s3[],int n,const char* s1,char s[]) {
//	strcpy(s3, s1);
//	strcat(s3, s);
//	int len = strlen(s3);
//	for (int i = n; i < len; i++) {
//		printf("%c", s3[i]);
//	}
//}
//字符串逆序
//void rever(char * s,int left,int n) {
//	int right = n;
//	while (left < right) {
//		char temp = *(s + left);
//		*(s + left) = *(s + right);
//		*(s + right) = temp;
//		left++;
//		right--;
//	}
//将数字转化为二进制
//void two(int c) {
//    int a[50];
//    int i = 0;
//    while (c > 0) {
//        a[i] = c % 2;
//        c = c / 2;
//        i++;
//    }
//    for (int j = i-1; j >=0; j--) {
//        printf("%d", a[j]);
//    }
//}
//int main() {
//	////判断字符旋转结果
//	//const char* s1 = "abcd";
//	//const char* s2 = "ACBD";
//	//char s[500]="\0";
//	//strcpy(s, s1);
//	//strcat(s, s1);
//	//int a=judge(s, s2);
//	//printf("%d", a);
//    //左旋字符
//	 char s1[50] = "ABCDEFG";
//	int n = 0;
//	char s[500] = "\0";
//	char s3[500] = "\0";
//	scanf("%d", &n);
//	int len = strlen(s1);
//	//for (int i = 0; i < n; i++) {
//	//	s[i] = *(s1 + i);
//	//}
//	//left(s3, n, s1, s);
//	//先逆序前n个字符  再逆序后n个字符  最后逆序全部字符
//	rever(s1, 0,n-1);
//	rever(s1, len - 1 - n, len - 1);
//	rever(s1, 0, len - 1);
//	for (int i = 0; i < len; i++) {
//		printf("%c", s1[i]);
//	}
	//最后一个单词长度
    //char s[50] = "a";
    //int n = strlen(s) - 1;
    //int i = 0;
    //int count = 0;
    //int num = 0;
    //int a[50];
    //while (n>= 0) {
    //    if (s[n] != ' ') {
    //        count++;
    //    }
    //    else if(count>0){
    //        a[i] = count;
    //        i++;
    //        count = 0;
    //    }
    //    n--;
    //}
    //a[i] = count;
    //printf("%d",a[0]);
    //二进制求和 给a b两数字以二进制字符串的形式返回他们的和
    //int a = 1010;
    //int b = 1011;
    ////scanf("%d %d", &a, &b);
    //int c = a + b;
    //two(c);
    //return 0;
//    int temp[45];
//    int n = 0;
//    scanf("%d", &n);
//    for (int i = 0; i <= n; i++) {
//        if (i <2) {
//            temp[i] = 1;
//        }else
//        temp[i] = temp[i - 1] + temp[i - 2];
//    }
//    printf("%d", temp[n]);
//    return temp[n];
//}