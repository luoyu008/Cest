#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.273.h"
void menu() {
	printf("******************************\n");
	printf("*****1.β��     2.βɾ********\n");
	printf("*****3.ͷ��     4.ͷɾ********\n");
	printf("*****5.����     6.ɾĳλ******\n");
	printf("*****7.ĳλ���� 8.��ӡ********\n");
	printf("*****      0.�˳�     ********\n");
	printf("******************************\n");

}
int main() {
	s s1;
	//��ʼ��
	SeqlistInit(&s1);
	int temp = 0;
	do {
		menu();
		printf("�����룺\n");
		scanf("%d", &temp);
		int (*f[9])(s * s1) = {Seqlistdestory
			,SeqlistPushBack
			,SeqlistPopBack
			,SeqlistPushFront
			,SeqlistPopFront
			,SeqlistFind
			,SeqlistPopn
			,SeqlistPushn
		    ,SeqlistPrintf };
		switch (temp)
		{
		case 1:
			f[1](&s1);
			break;
		case 2:
			f[2](&s1);
			break;
		case 3:
			f[3](&s1);
			break;
		case 4:
			f[4](&s1);
			break;
		case 5:
			f[5](&s1);
			break;
		case 6:
			f[6](&s1);
			break;
		case 7:
			f[7](&s1);
			break;
		case 8:
			f[8](&s1);
			break;
		case 0:
			f[0](&s1);
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	} while (temp);

	return 0;
}