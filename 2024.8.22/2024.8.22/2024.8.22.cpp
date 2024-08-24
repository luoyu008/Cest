#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    char str = '0';
    int i = 0;
    int count = 0;
    while (scanf("%c\n", &str) != EOF) {
        if (str == ' ')
            count += 1;
        else
            count = count + ((str - 'a') % 3) + 1;
        printf("%d\n", count);
        
    }
    return 0;
}
//Í¬¹¹×Ö·û´®
//bool isIsomorphic(char* s, char* t) {
//    // int len1=strlen(s);
//    // int len2=strlen(t);
//    // if(len1!=len2)
//    // return false;
//    // int* s1=(int *)malloc(sizeof(int )*len1);
//    // int *t1=(int *)malloc(sizeof(int )*len2);
//    // for(int i=0;i<len1-1;i++){
//    //     if(s[i]!=s[i+1])
//    //     s1[i]=1;
//    //     else{
//    //     s1[i]=0;
//    //     s1[i+1]=0;
//    //     }
//    // }
//    // for(int i=0;i<len2-1;i++){
//    //     if(t[i]!=t[i+1])
//    //     t1[i]=1;
//    //     else{
//    //         t1[i]=0;
//    //         t1[i+1]=0;
//    //     }
//    // }
//    // for(int i=0;i<len1;i++){
//    //     if(s1[i]!=t1[i])
//    //     return false;
//    // }
//    // return true;
//    int count1 = 0;
//    int count2 = 0;
//    int len1 = strlen(s);
//    int len2 = strlen(t);
//    int* p = (int*)calloc(128, sizeof(int));
//    int* p1 = (int*)calloc(128, sizeof(int));
//    if (len1 != len2)
//        return false;
//    for (int i = 0; i < len1; i++) {
//        if (p[s[i]] == 0) {
//            count1++;
//            p[s[i]] = ++count1;
//        }
//        if (p1[t[i]] == 0) {
//            count2++;
//            p1[t[i]] = ++count2;
//        }
//        if (p[s[i]] != p1[t[i]])
//            return false;
//    }
//    free(p);
//    p = NULL;
//    free(p1);
//    p1 = NULL;
//    return true;
//}