#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define len 2
//int main() {
//	int a[20] = { 1,2 };
//	return 0;
//}
//�ϲ�������������
//int cmp(const void *s1,const void *s2) {
//    if (*(int*)s1 - *(int*)s2 > 0)
//        return 1;
//    else if (*(int *)s1 - *(int *)s2 == 0)
//        return 0;
//    else
//        return -1;
//}
//int main() {
//    int nums1[] = { 1,2,3,0,0,0 };
//    int nums2[] = { 2,5,6 };
//    int m = 3;
//    int n = 3;
//    int nums[6];
//    for (int i = 0; i < m; i++) {
//        nums[i] = nums1[i];
//    }
//    for (int i = m; i < m + n; i++) {
//        nums[i] = nums2[i - m];
//    }
//    //ð�ݷ���
//    /*for (int i = 0; i < m + n - 1; i++) {
//        for (int j = 0; j < m + n - i - 1; j++) {
//            if (nums[j] > nums[j + 1]) {
//                int temp = nums[j];
//                nums[j] = nums[j + 1];
//                nums[j + 1] = temp;
//            }
//        }
//    }*/
//    //qsort����
//    qsort(nums, m + n, sizeof(nums[0]), cmp);
//    for (int i = 0; i < m + n; i++) {
//        printf("%d", nums[i]);
//        if (i < m + n - 1)
//            printf(",");
//    }
//	return 0;
//}
// ��֤�����ַ���
int main() {
    const char* s = "0P";
    char s1[len+1];
    int i = 0;
    if (len == 1)
        return true;
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') {
            s1[i] = *s;
            s++;
            i++;
        }
        else if (*s >= 'A' && *s <= 'Z') {
            s1[i] = *s + 32;
            s++;
            i++;
        }
        else if (*s >= '0' && *s <= '9') {
            s1[i] = *s;
            s++;
            i++;
        }
        else
            s++;

    }
    s1[i] = '\0';
    int left = 0;
    int right = (int)strlen(s1) - 1;
    while (left < right) {
        if (s1[left] != s1[right])
            printf("false") ;
    }
    printf("true");
	return 0;
}
//ģ��ʵ��strlen���������ַ��� ������ �ݹ�  ָ��-ָ��
//������
//int my_strlen(char* s){
//	int count = 0;
//	while (*s != '\0') {
//      assert(s);
//		count++;
//		s++;
//	}
//	return count;
//}
//�ݹ�
//int my_strlen(char* s) {
//	assert(s);
//	if (*s != '\0')
//		return 1 + my_strlen(s + 1);
//	else
//		return 0;
//}
//ָ��-ָ��
//int my_strlen(char* s) {
//	char* ps = s;
//	while (*s != '\0') {
//		s++;
//	}
//	return s-ps;
//}
//int main() {
//	char s[] = { 'a','b','c','\0'};
//	//char s[] = "absdef";
//	int len=my_strlen(s);
//	printf("%d", len);
//	return 0;
//}

//strcpy����
//char* strcpy(char* destination,const char* source)  destinationΪĿ�ĵ� sourceΪԴͷ  �˺���Ϊ�Ѻ����ַ��
// �ַ���������ǰ����ַ����У�����\0��Ϊֹ��
//ģ��ʵ��
//char* my_strcpy(char* str1,char* str2){
//	//assert(str1);
//	//assert(str2);
//	//char* pstr1 = str1;
//	//while (*str1 != '\0' || *str2 != '\0') {
//	//	*str1 = *str2;
//	//	str1++;
//	//	str2++;
//	//}
//	//*str1 = *str2;//\0
//	assert(str1 && str2);
//	char* pstr1 = str1;
//	while (*str1++ = *str2++);
//	return pstr1;
//}
//int main() {
//	char arr1[] = "abcdefg";
//	char arr2[50] = { 0 };
//	my_strcpy(arr2, arr1);
//	printf("%s", arr2);
//	return 0;
//}

//strcat����  �ַ���׷�Ӻ���
//char* strcat(char* destination,char* source)
//Դ�ַ�����source�����ԡ�\0������
//Ŀ��ռ伴destination�������㹻��Ŀռ�
//Ŀ��ռ������޸�
//ģ��ʵ��
//char* my_strcat(char* str1, char* str2) {
//	char* pstr1 = str1;
//	assert(str1&&str2);
//	while (*str1 != '\0') {
//		str1++;
//	}
//	while (*str2 != '\0') {
//		*str1 = *str2;
//		str1++;
//		str2++;
//	}
//	return pstr1;
//}
//
//int main() {
//	char str1[50] = "abcdefg";
//	char str2[] = "world";
//	//strcat(str1, str1);
//	//my_strcat(str1, str2);
//	printf("%s", str1);
//	return 0;
//}

//strcmp����
//int strcmp(const char* str1,const char*str2)
//�ú����Ƕ����ַ����е��ַ�����һ�αȽ�  ��str1>str2 ����>0����  < ����<0��  ==����=0����
//ģ��
//int mystrcmp(const char* str1,const char *str2) {
//	assert(str1 && str2);
//	int flag = 0;
//	while (*str1 != '\0' || *str2 != '\0') {
//		if (*str1  == *str2) {
//			str1++;
//			str2++;
//		}
//		else if (*str1  > *str2 ) {
//			flag = 1;
//			break;
//		}
//		else {
//		 flag = -1;
//		 break;
//		}
//	}
//	return flag;
//}
//int main() {
//	char str1[] = "abcdef";
//	char str2[] = "abcde";
//	mystrcmp(str1, str2);
//	if (mystrcmp(str1, str2) > 0)
//		printf(">\n");
//	else if (mystrcmp(str1, str2) == 0)
//		printf("=\n");
//	else
//		printf("<\n");
//	return 0;
//}
//���Ϻ���Ϊ���Ȳ������Ƶĺ���

//���������Ƶĺ���
//strncat
//int main() {
//	char str1[20] = "abcdefg";
//	char str2[] = "qwert";
//	strncat(str1, str2, 5);//�˴���5 ��ָstr1Ҫ׷�ӵ�str2���ֽ���  ��str2�ĳ���С��5��ʱ����str2׷����֮��
//	//����һ����\0�� ������ȫ��׷��5���ֽ�
//	printf("%s", str1);
//	return 0;
//}
//strncpy
//int main() {
//	char str1[50] = "abcdefg";
//	char str2[] = "asdfg";
//	strncpy(str1, str2, 5);//�˴���5 ��ָstr1Ҫ������str2���ֽ���  ��str2�ĳ���С��5��ʱ���á�\0������
//	printf("%s", str1);
//	return 0;
//}
//strncmp
//int main() {
//	char str1[50] = "abcdefg";
//	char str2[] = "aadfg";
//	printf("%d",strncmp(str1, str2, 2));//�˴���2��ָҪ�Ƚϸ��ַ�����
//	return 0;
//}














