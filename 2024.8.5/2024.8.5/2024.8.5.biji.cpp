#define _CRT_SECURE_NO_WARNINGS
//void*ָ��
//int a = 0;
//void* pa = &a; //void*���޾������͵�ָ�� �����Խ����������͵ĵ�ַ
////����void*���ܽ���*����  Ҳ���ܽ���+-�����Ĳ���  ��Ϊ��֪�����Ͳ�ȷ��+-���������������ֽ�
//��Ҫ����ǿ������ת�� ���� *��int*��pa

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ص�����ʵ��qsort������������  ��������˼��
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
// �˴�a��Ҫ����Ԫ�ص���Ԫ�ص�ַ  len��Ҫ����Ԫ�صĸ��� sizeof��a����Ҫ����Ԫ�صĵ����Ĵ�С cmp�Ǻ�����ַ�ú������ԱȽ��������͵�Ԫ�ص���ע��
// Ҫ����ǿ������ת��
//	for (int i = 0; i < len; i++) {
//		printf("%d", a[i]);
//	}
//	return 0;
//}
//�ص�����ʵ��qsort�ṹ����������  ��������˼��
// �ص�������ͨ������ָ����õĺ���
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

//ʵ��qsort��ð������
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
//��̬�滮˼��ʵ���ҳ����ַ����е�������ַ���
//˼·�ǽ��ַ���һ���ַ�һ�����ַ������е��ַ���Ƚ�  ��������ά�����Ӧ��i j Ϊ1  ���������Ϊ0  ��i��j>0��ʱ����������Ӧ��
// ��ά�����λ��Ϊ1ͬʱ����i-1 j-1 λ�ô�������  �˾���Ϊ��ȷ����ͬ��ͬʱ��¼���ַ����Ĵ�С ͬʱ����ά����Ĵ�С>length��ʱ�� ����length
//��ֵ�͹����ַ�������λ��end��ֵ  ������str1�г���Ϊlength ����λ��Ϊend���ַ���  ���ַ����������ַ�����������ַ���
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
            //str1��i���ַ���str2��j���ַ���ȣ�dp[i][j]����dp[i-1][j-1]�����ۼ�
            if (str1[i] == str2[j]) {
                if (i > 0 && j > 0)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                //str1[0]��str2[0]���
                else
                    dp[i][j] = 1;

                if (dp[i][j] > length) {
                    length = dp[i][j];
                    end = i;//end��¼��������Ӵ����һ���ַ���str1�е�λ��
                }
            }
            //str1��i���ַ���str2��j���ַ������
            else
                dp[i][j] = 0;
        }
    }
    //�������ʱ����end+1��Ϊ'\0'��str1��������Ӵ�֮��ض�
    str1[end + 1] = '\0';
    //����������Ӵ���str1�е���ʼָ��
    for (int i = end - length + 1; i <= end; i++)
    {
        printf("%c", str1[i]);
    }
    return 0;
}