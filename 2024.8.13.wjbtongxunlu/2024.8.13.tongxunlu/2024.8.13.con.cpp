#define _CRT_SECURE_NO_WARNINGS
//���ļ����ں���ʵ��
#include "2024.8.13.con.h"
//�˵�ʵ��
void menu() {
	printf("******************************\n");
	printf("******1.add  2.dele     ******\n");
	printf("******3.find 4.revise   ******\n");
	printf("******5.sort 6.show     ******\n");
	printf("******    0.exit        ******\n");
	printf("******************************\n");

}
void Choicemenu() {
	printf("***************\n");
	printf("****1.����****\n");
	printf("****2.����*****\n");
	printf("****3.�绰*****\n");
	printf("****4.�Ա�*****\n");
	printf("****5.סַ*****\n");
	printf("***************\n");
}
void commenu() {
	printf("********************\n");
	printf("******1.����   *****\n");
	printf("******2.����   *****\n");
	printf("******3.�绰   *****\n");
	printf("******4.��ַ   *****\n");
	printf("********************\n");
}
//�ṹ������
static void ADD(Contact* contact) {
	assert(contact);
	if (contact->count == contact->temp) {
		people* data2 = (people*)realloc(contact->date, sizeof(people) * (contact->temp + 2));
		if (data2 != NULL) {
			contact->date = data2;
			contact->temp += 2;
		}
		else {
			printf("%s\n", strerror(errno));
			return;
		}
		printf("���ݳɹ���\n");
	}
}
//����
void load(Contact* contact) {
	FILE* f = fopen("D:\\vs c\\2024.8.13.tongxunlu\\2024.8.13.tongxunlu\\xinxi2.txt", "rb");
	if (f == NULL) {
		perror("fopen");
		return;
	}
	people p = { 0 };
	while ((fread(&p, sizeof(people), 1, f) == 1))
	{
		ADD(contact);
		contact->date[contact->count] = p;
		contact->count++;
		}
	fclose(f);
	f = NULL;
}
//��ʼ��ͨѶ¼ʵ��
//��̬
//void Initcon(con* contact) {
//	assert(contact);
//	memset(contact, 0, sizeof(con));//ͨ���ڴ����ú�����ʼ���ṹ��contact��
//}
//��̬
void Initcon(con* contact) {
	assert(contact);
	contact->date = (people*)calloc(MAX, sizeof(people));
	if (contact->date == NULL) {
		printf("%s", strerror(errno));
		return ;
	}
	contact->count = 0;
	contact->temp = MAX;
	//����
	load(contact);
}

//�����ϵ��
//��̬
//void Addcon(Contact* contact) {
//	assert(contact);
//	if (contact->count == MAX) {
//		printf("ͨѶ¼����\n");
//		return;
//	}
//	else {
//		printf("������������\n");
//		scanf("%s", contact->date[contact->count].name);
//		printf("���������䣺\n");
//		scanf("%d", &contact->date[contact->count].age);
//		printf("������绰��\n");
//		scanf("%s", contact->date[contact->count].tel);
//		printf("�������Ա�\n");
//		scanf("%s", contact->date[contact->count].sex);
//		printf("������סַ��\n");
//		scanf("%s", contact->date[contact->count].addr);
//		contact->count++;
//	}
//	printf("���ӳɹ�!\n");
//}

//��̬
void Addcon(Contact* contact){
	assert(contact);
	ADD(contact);
		printf("������������\n");
		scanf("%s", &contact->date[contact->count].name);
		printf("���������䣺\n");
		scanf("%d", &contact->date[contact->count].age);
		printf("������绰��\n");
		scanf("%s", &contact->date[contact->count].tel);
		printf("�������Ա�\n");
		scanf("%s", &contact->date[contact->count].sex);
		printf("������סַ��\n");
		scanf("%s", &contact->date[contact->count].addr);
		contact->count++;
	
	printf("���ӳɹ�!\n");
}

//�ҵ���Ҫ��������ϵ�˵��±�
static int  find1(Contact* contact,char* n) {//����static֮��ú���ֻ�������2024.8.13.con.cpp����ļ��п���
	int temp = -1;
	for (int i = 0; i < contact->count; i++) {
		if (strcmp(n, contact->date[i].name) == 0)
		{
			temp = i;
			break;
		}
	}
	return temp;
}
//ɾ����ϵ��
void Delecon(Contact* contact) {
	assert(contact);
	if (contact->count == 0) {
		printf("��ϵ��Ϊ�� �޷�ɾ����\n");
		return;
	}
	printf("��������Ҫɾ������ϵ�˵�������\n");
	char n[NAME] = "0";
	scanf("%s", n);
	int temp = find1(contact,n);
	if (temp == -1) {
		printf("û�д���ϵ�ˣ�\n");
		return;
	}
	//memset(&contact->date[temp], 0, sizeof(contact->date[temp]));
	/*for (int i = temp; i < contact->count - 1; i++) {
		contact->date[i] = contact->date[i + 1];
	}*/
	memmove(&contact->date[temp], &contact->date[temp + 1], sizeof(contact->date[temp])*(contact->count-temp-1));
	contact->count--;
	printf("ɾ���ɹ���\n");
}

//������ϵ��ʵ��
void Findcon(Contact* contact) {
	assert(contact);
	printf("��������Ҫ���ҵ���ϵ�˵�������\n");
	char n[NAME] = "0";
	scanf("%s", n);
	int temp = find1(contact,n);
	if (temp == -1) {
		printf("û�д���ϵ�ˣ�\n");
		return;
	}
	printf("����:%s\t ����:%d\t �绰:%s\t �Ա�:%s\t סַ:%s\t\n", contact->date[temp].name, contact->date[temp].age, contact->date[temp].tel,
		contact->date[temp].sex, contact->date[temp].addr);
}

//�޸���ϵ��ʵ��
void Revisecon(Contact* contact) {
	assert(contact);
	printf("��������Ҫ�޸ĵ���ϵ�ˣ�\n");
	char n[NAME] = "0";
	scanf("%s", n);
	int temp = find1(contact,n);
	if (temp == -1) {
		printf("û�д���ϵ�ˣ�\n");
		return;
	}
	printf("��������Ҫ�޸ĵ����ݣ�\n");
	Choicemenu();
	int choice = 0;
	scanf("%d", &choice);
	char n1[NAME] = "0";
	int age1 = 0;
	char tel1[TEL] = "0";
	char addr1[ADDR] = "0";
	char sex1[SEX] = "0";
	switch (choice)
	{
	case 1:
		printf("��������Ҫ�޸ĵ�������\n");
		scanf("%s", n1);
		memcpy(contact->date[temp].name, n1, sizeof(n1));
		break;
	case 2:
		printf("��������Ҫ�޸ĵ����䣺\n");
		scanf("%d", &age1);
		contact->date[temp].age = age1;
		break;
	case 3:
		printf("��������Ҫ�޸ĵĵ绰��\n");
		scanf("%s", tel1);
		memcpy(contact->date[temp].tel, tel1, sizeof(tel1));
		break;
	case 4:
		printf("��������Ҫ�޸ĵ��Ա�\n");
		scanf("%s", sex1);
		memcpy(contact->date[temp].sex, sex1, sizeof(sex1));
		break;
	case 5:
		printf("��������Ҫ�޸ĵ�סַ��\n");
		scanf("%s", addr1);
		memcpy(contact->date[temp].addr, addr1, sizeof(addr1));
		break;
	default:
		printf("�������\n");
		break;
	}
}
//�ȽϺ���
int comname(const void* a1,const void* a2) {
	return strcmp(((people*)a1)->name , ((people*)a2)->name);
}
int comage(const void* a1, const void* a2) {
	return ((people*)a1)->age-((people*)a2)->age;
}
int comtel(const void* a1, const void* a2) {
	return strcmp(((people*)a1)->tel, ((people*)a2)->tel);
}
int comaddr(const void* a1, const void* a2) {
	return strcmp(((people*)a1)->addr, ((people*)a2)->addr);
}
//������ϵ��ʵ��
void Sortcon(Contact* contact)
{
	assert(contact);
	int(* com[5])(const void*, const void*) = { 0,comname,comage,comtel,comaddr };
	commenu();
	printf("��ѡ��Ҫ����ķ�ʽ��\n");
	int temp = 0;
	scanf("%d", &temp);
	qsort(contact->date, contact->count, sizeof(people),com[temp]);
	printf("����ɹ���\n");
}



//��ʾ���е���ϵ����Ϣ
void Showcon(const Contact* contact) {
	assert(contact);
	for (int i = 0; i < contact->count; i++) {
		printf("����:%10s\t ����:%3d\t �绰:%20s\t �Ա�:%5s\t סַ:%30s\t\n", contact->date[i].name, contact->date[i].age,
			contact->date[i].tel, contact->date[i].sex, contact->date[i].addr);
	}
}
//�ͷ��ڴ�
void destory(Contact* contact) {
	assert(contact);
	free(contact->date);
	contact->date = NULL;
}
void save(Contact* contact) {
	assert(contact);
	FILE* f = fopen("D:\\vs c\\2024.8.13.tongxunlu\\2024.8.13.tongxunlu\\xinxi2.txt", "wb");
	if (f == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	for (int i = 0; i < contact->count; i++) {
		fwrite(contact->date+i, sizeof(people), 1, f);
		/*fprintf(f, "����:%s\t ����:%d\t �绰:%s\t �Ա�:%s\t סַ:%s\t\n", contact->date[i].name,
			contact->date[i].age,
			contact->date[i].tel,
			contact->date[i].sex,
			contact->date[i].addr);*/
	}
	fclose(f);
	f = NULL;
}
