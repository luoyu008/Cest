//#define _CRT_SECURE_NO_WARNINGS
//#define N 20
//#include<stdio.h>;
//int main() {
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	char c[N][N] = { " " };
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			c[i][j] = ' ';
//		}
//	}
//	for (i = 0; i <N/2; i++) {
//		for (j = N / 2 + n; j >= N / 2 - n; j--) {
//			c[i][j] = '*';
//		}
//		n++;
//	}
//	int m = 0;
//	for (i = N - 1; i >= N / 2 ; i--) {
//		for (j = N / 2 + m; j >= N / 2 - m; j--) {
//			c[i][j] = '*';
//		}
//		m++;
//	}
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			printf("%c", c[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>;
//
//int main() {
//
//	int a = 0;
//
//	int sum = 0;
//
//	int p = 0;
//
//	scanf("%d", &a);
//
//	sum = a / 1;
//
//	p = a;
//
//	while (p > 1) {
//
//		sum += p / 2;
//
//		p = p - p / 2;
//
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//
//}
//#include <stdio.h>
//int main() {
//    char c[101] = "\0";
//    int a[100];
//    int i = 0;
//    int j = 0;
//    int m = 0;
//    int n = 0;
//    int l = 0;
//    char c1[100][100];
//    gets_s(c);
//    while (c[i] != '\0') {
//        if (c[i] != ' ') {
//            c1[j][l] = c[i];
//            n++;
//            l++;
//            i++;
//        }
//        if (c[i] == ' ') {
//            m++;
//            a[j] = n;
//            j++;
//            n = 0;
//            l = 0;
//            i++;
//        }
//    }
//    a[j] = n;
//    for (i = j; i >=0; i--) {
//        if (i <= j - 1)
//            printf(" ");
//        for (int k = 0; k < a[i]; k++) {
//            printf("%c", c1[i][k]);
//        }
//    }
//    return 0;
//}
#include <stdio.h>
#include<string.h>
//void rever(char* left, char* right) {
//    while (left < right) {
//            char temp = *left;
//            *left = *right;
//            *right = temp;
//        left++;
//        right--;
//    }
//}
//int main() {
 /*   char c[101] = "\0";
    char* start = c;
    char* end = c;
    gets_s(c);
    int l = strlen(c);
    rever(c, c+l-1);
    while (*start != '\0') {
        end = start;
        while (*end != '\0' && *end != ' ') {
            end++;
        }
        rever(start, end-1);
        if(*end!='\0')
        end++;
        start = end;

        
    }
    for (int i = 0; i < l; i++) {
        printf("%c", c[i]);
    }*/
//    int a = 1;
//    char c= *(char*)&a;
//    if (c == 1)
//        printf("x");
//    if (c == 0)
//        printf("d");
//    return 0;
//}
//int compare(char str[], char* s) {
//    int temp = 1;
//    while (1) {
//        if (*str++ == *s) {
//            temp--;
//            break;
//        }
//    }
//    return temp;
//
//}
//void change(int a[], int left, int right) {
//    while (left <= right) {
//        if (a[right] % 2 == 1 && a[left] % 2 == 0) {
//            int temp = a[left];
//            a[left] = a[right];
//            a[right] = temp;
//            left++;
//        }
//        if (a[right] % 2 == 1 && a[left] % 2 != 0) {
//            left++;
//        }
//        if (a[right] % 2 != 1)
//            right--;
//    }
//}
void rever(char str[], int left, int right) {
    while (left < right) {
        char temp = *(str+left);
        *(str + left) = *(str + right);
        *(str + right) = *(str + left);
        left++;
        right--;
    }
}
int main() {
    //int a[10000];
    //char c1[100000] = "\0";
    //int i = 0;
    //while (*s != '\0') {
    //    int count = 0;
    //    int k = 0;
    //    while (*s != '\0' && compare(c1, s)) {
    //        c1[k] = *s;
    //        k++;
    //        count++;
    //        s++;
    //    }
    //    a[i] = count;
    //    i++;
    //}
    //int max = a[0];
    //for (int j = 0; j <= i; j++) {
    //    if (a[j] > max) {
    //        max = a[j];
    //    }
    //}
    //printf("%d", max);
    //return 0;
    //int left = 0;
    //int right = 0;
    //int count = 0;
    //int a[100];
    //int i = 0;
    //int temp = 0;
    //while (s[right] != '\0') {
    //    if (left != right) {
    //        for (int k = left; k < right; k++) {
    //            if (s[k] == s[right]) {
    //                left++;
    //                a[i] = count;
    //                i++;
    //                count = right-left+1; 
    //                temp = 1;
    //            }
    //        }
    //        if (temp == 1) {
    //            temp = 0;
    //            right++;
    //            continue;
    //        }
    //    }
    //    if (right != left && s[right] == s[left]) {
    //        left++;
    //        a[i] = count;
    //        i++;

    //        count = 0;
    //    }
    //    if (right > 1 && s[right] == s[right - 1]) {
    //        left = right;
    //        a[i] = count;
    //        i++;

    //        count = 0;
    //    }
    //    right++;
    //    count++;
    //}
    //a[i] = count;
    //int max = a[0];
    //for (int j = 0; j < (sizeof(a) / sizeof(a[0])) - 1; j++) {
    //    if (a[j] > max)
    //        max = a[j];
    //}
    //printf("%d\n", max);
    //return 0;
       //滑动窗口维护
    //int left = 0;
    //int right = 0;
    //int max = 0;
    //int i, j;
    //const char* s = "dvdf";
    //int len = strlen(s);
    //int haveSameChar = 0;
    //for (i = 0; i < len; i++)
    //{
    //    if (left <= right)
    //    {
    //        //检测是否出现重复
    //         //循环遍历整个数组 left -> right
    //        haveSameChar = 0;
    //        for (j = left; j < right; j++)
    //        {
    //            if (s[j] == s[right])
    //            {
    //                haveSameChar = 1;
    //                break;
    //            }
    //        }
    //        if (haveSameChar)
    //        {
    //            //指向下一个
    //            left = j + 1;
    //        }
    //    }
    //    //统计最大的间距
    //    max = max < (right - left + 1) ? (right - left + 1) : max;
    //    right++;
    //}
    //return max;
//奇数在前偶数在后
//int a[10] = { 1,11,3,13,5,15,7,19,9,21 };
//    int left = 0;
//    int right = sizeof(a)/sizeof(a[0]);
//    change(a, left, right);
//    
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
//        printf("%d ", a[i]);
//    }
//字符串逆序
     char  s[10] = "\0";
     gets_s(s);
    int left = 0;
    int right = strlen(s) - 1;
    rever(s,left,right);
    for (int i = 0; i <= right; i++) {
        printf("%c", s[i]);
    }
    return 0;

}