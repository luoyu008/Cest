#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define strsLen 5
//�ַ�������  ����nowcoder����ɡ�NOWCODER��
//void rever(char* s, int left, int right) {
//    while (left < right) {
//        char temp = s[left];
//        s[left] = s[right];
//        s[right] = temp;
//        left++;
//        right--;
//    }
//}
//int main() {
//     char s[] = "now coder";
//    int n = strlen(s);
//    int left = 0;
//    int rigtht = n - 1;
//    rever(s, left, rigtht);
//    rigtht = 0;
//    for (int i = 0; i < n; i++) {
//        if (s[i] != ' ') {
//            rigtht++;
//        }
//        else {
//            rever(s, left, rigtht - 1);
//            left = rigtht + 1;
//            rigtht = rigtht + 1;
//        }
//        if (rigtht == n) {
//            rever(s, left, rigtht - 1);
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        if (s[i] >= 'a' && s[i] <= 'z')
//            s[i] = s[i] - 32;
//         else if (s[i] >= 'A' && s[i] <= 'Z')
//            s[i] = s[i] + 32;
//    }
//    for (int i = 0; i < n; i++) {
//        printf("%c", s[i]);
//    }
//    return 0;
//}
//���ַ�������������ǰ׺
int main() {
    int max = 0;
    int end = 0;//�����ǰ׺���һλ�±�
    int length = 0;//����ǰ׺�ĳ���
    int a[50];//����ַ���������ÿ���ַ����Ĵ�С
     char strs[strsLen][5] = {"abca","abc","abca","abc","abcc"};
    if(strsLen == 0)
        return "";
    for (int i = 0; strs[0][i] != '\0'; ++i) {
        for (int j = 1; j < strsLen; j++) {
            if (strs[0][i] != strs[j][i]) {
                strs[0][i] = '\0';
                //return strs[0];
            }
        }
    }
    //return strs[0]
}