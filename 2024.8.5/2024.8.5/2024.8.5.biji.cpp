#define _CRT_SECURE_NO_WARNINGS
//void*指针
//int a = 0;
//void* pa = &a; //void*是无具体类型的指针 它可以接受任意类型的地址
////但是void*不能进行*操作  也不能进行+-整数的操作  因为不知道类型不确定+-整数后跳过几个字节
//需要进行强制类型转化 例如 *（int*）pa

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//回调函数实现qsort函数数组排序  快速排序思想
//int cmp(const void* e1,const void* e2) {
//	if (*(int*)e1 > *(int*)e2)
//		return 1;
//	else if (*(int*)e1 == *(int*)e2)
//		return 0;
//	else
//		return -1;
//}
//int main() {
//	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int len = sizeof(a) / sizeof(a[0]);
//	qsort(a,len,sizeof(a[0]),cmp);
// 此处a是要排序元素的首元素地址  len是要排序元素的个数 sizeof【a】是要排序元素的单个的大小 cmp是函数地址该函数可以比较任意类型的元素但是注意
// 要进行强制类型转化
//	for (int i = 0; i < len; i++) {
//		printf("%d", a[i]);
//	}
//	return 0;
//}
//回调函数实现qsort结构体数组排序  快速排序思想
// 回调函数是通过函数指针调用的函数
//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmpname(const void* e1, const void* e2) {
//	return strcmp((*(struct stu*)e1).name, (*(struct stu*)e2).name);
//}
//int cmpage(const void* e1, const void* e2) {
//	return (*(struct stu*)e1).age- (*(struct stu*)e2).age;
//}
//int main() {
//	struct stu s[] = { {"zhangsan",18},{"lisi", 55},{"wanngwu",96},{"zhaoliu",23} };
//	int len = sizeof(s) / sizeof(s[0]);
//	//qsort(s, len,sizeof(s[0]), cmpname);
//	qsort(s, len,sizeof(s[0]), cmpage);
//	for (int i = 0; i < len; i++) {
//		printf("%s %d\n", s[i].name, s[i].age);
//	}
//	return 0;
//}

//实现qsort版冒泡排序
//int cmpint(const void* e1,const void* e2) {
//	int ret = *(int*)e1 - *(int*)e2;
//	return ret;
//}
//void Swap(char* e1, char* e2, int width) {
//	for (int i = 0; i < width; i++) {
//		char temp = *(e1+i);
//		*(e1+i) = *(e2+i);
//		*(e2+i) = temp;
//		/*e1++;
//		e2++;*/
//	}
//}
//void bubbleqsort(void* base, int num, int width, int(*cmp)(const void *e1, const void *e2)) {
//	int i = 0;
//	for (i = 0; i < num - 1; i++) {
//		int j = 0;
//		int flag = 0;
//		for (j = 0; j < num - 1 - i; j++) {
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width)>0) {
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				flag = 1;
//			}
//		}
//		if (flag == 0) {
//			break;
//		}
//	}
//}
//int main() {
//	int a[] = { 5,7,3,6,4,2,1,9,0,8 };
//	int len = sizeof(a) / sizeof(a[0]);
//	bubbleqsort(a,len,sizeof(a[0]),cmpint);
//	for (int i = 0; i < len; i++) {
//		printf("%d", a[i]);
//	}
//	return 0;
//}
//动态规划思想实现找出两字符串中的最长公共字符串
//思路是将字符串一的字符一次以字符串二中的字符相比较  若相等则二维数组对应的i j 为1  若不相等则为0  当i和j>0的时候若相等则对应的
// 二维数组的位置为1同时加上i-1 j-1 位置处的数字  此举意为在确认相同的同时记录出字符串的大小 同时当二维数组的大小>length的时候 更新length
//的值和公共字符串结束位置end的值  最后输出str1中长度为length 结束位置为end的字符串  该字符串即是两字符串的最长公共字符串
int main() {
    char str1[] = "1AB2345CD";
    char str2[] = "12345EF";
    int str2Len = strlen(str2);
    int str1Len = strlen(str1);
    if (str1Len == 0 || str2Len == 0)
        return NULL;
    int length = 0;
    int end = 0;
    //int dp[str1Len+1][str2Len+1] = {0};
    //int (*a)[2]=(int(*)[2])malloc(sizeof(int)*3*2);
    //int(*dp)[str2Len] = (int(*)[str2Len])malloc(sizeof(int) * str1Len * str2Len);
    int dp[9][7];
    for (int i = 0; i < str1Len; i++) {
        for (int j = 0; j < str2Len; j++) {
            //str1第i个字符和str2第j个字符相等，dp[i][j]根据dp[i-1][j-1]进行累加
            if (str1[i] == str2[j]) {
                if (i > 0 && j > 0)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                //str1[0]和str2[0]相等
                else
                    dp[i][j] = 1;

                if (dp[i][j] > length) {
                    length = dp[i][j];
                    end = i;//end记录了最长公共子串最后一个字符在str1中的位置
                }
            }
            //str1第i个字符和str2第j个字符不相等
            else
                dp[i][j] = 0;
        }
    }
    //遍历完成时，将end+1设为'\0'将str1从最长公共子串之后截断
    str1[end + 1] = '\0';
    //返回最长公共子串在str1中的起始指针
    for (int i = end - length + 1; i <= end; i++)
    {
        printf("%c", str1[i]);
    }
    return 0;
}