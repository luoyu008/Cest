#define _CRT_SECURE_NO_WARNINGS
//该文件用于函数实现
#include "2024.8.13.con.h"
//菜单实现
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
	printf("****1.姓名****\n");
	printf("****2.年龄*****\n");
	printf("****3.电话*****\n");
	printf("****4.性别*****\n");
	printf("****5.住址*****\n");
	printf("***************\n");
}
void commenu() {
	printf("********************\n");
	printf("******1.姓名   *****\n");
	printf("******2.年龄   *****\n");
	printf("******3.电话   *****\n");
	printf("******4.地址   *****\n");
	printf("********************\n");
}
//结构体增容
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
		printf("增容成功！\n");
	}
}
//加载
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
//初始化通讯录实现
//静态
//void Initcon(con* contact) {
//	assert(contact);
//	memset(contact, 0, sizeof(con));//通过内存设置函数初始化结构体contact内
//}
//动态
void Initcon(con* contact) {
	assert(contact);
	contact->date = (people*)calloc(MAX, sizeof(people));
	if (contact->date == NULL) {
		printf("%s", strerror(errno));
		return ;
	}
	contact->count = 0;
	contact->temp = MAX;
	//加载
	load(contact);
}

//添加联系人
//静态
//void Addcon(Contact* contact) {
//	assert(contact);
//	if (contact->count == MAX) {
//		printf("通讯录已满\n");
//		return;
//	}
//	else {
//		printf("请输入姓名：\n");
//		scanf("%s", contact->date[contact->count].name);
//		printf("请输入年龄：\n");
//		scanf("%d", &contact->date[contact->count].age);
//		printf("请输入电话：\n");
//		scanf("%s", contact->date[contact->count].tel);
//		printf("请输入性别：\n");
//		scanf("%s", contact->date[contact->count].sex);
//		printf("请输入住址：\n");
//		scanf("%s", contact->date[contact->count].addr);
//		contact->count++;
//	}
//	printf("增加成功!\n");
//}

//动态
void Addcon(Contact* contact){
	assert(contact);
	ADD(contact);
		printf("请输入姓名：\n");
		scanf("%s", &contact->date[contact->count].name);
		printf("请输入年龄：\n");
		scanf("%d", &contact->date[contact->count].age);
		printf("请输入电话：\n");
		scanf("%s", &contact->date[contact->count].tel);
		printf("请输入性别：\n");
		scanf("%s", &contact->date[contact->count].sex);
		printf("请输入住址：\n");
		scanf("%s", &contact->date[contact->count].addr);
		contact->count++;
	
	printf("增加成功!\n");
}

//找到需要操作的联系人的下标
static int  find1(Contact* contact,char* n) {//加了static之后该函数只能在这个2024.8.13.con.cpp这个文件中看到
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
//删除联系人
void Delecon(Contact* contact) {
	assert(contact);
	if (contact->count == 0) {
		printf("联系人为空 无法删除！\n");
		return;
	}
	printf("请输入你要删除的联系人的姓名：\n");
	char n[NAME] = "0";
	scanf("%s", n);
	int temp = find1(contact,n);
	if (temp == -1) {
		printf("没有此联系人！\n");
		return;
	}
	//memset(&contact->date[temp], 0, sizeof(contact->date[temp]));
	/*for (int i = temp; i < contact->count - 1; i++) {
		contact->date[i] = contact->date[i + 1];
	}*/
	memmove(&contact->date[temp], &contact->date[temp + 1], sizeof(contact->date[temp])*(contact->count-temp-1));
	contact->count--;
	printf("删除成功！\n");
}

//查找联系人实现
void Findcon(Contact* contact) {
	assert(contact);
	printf("请输入你要查找的联系人的姓名：\n");
	char n[NAME] = "0";
	scanf("%s", n);
	int temp = find1(contact,n);
	if (temp == -1) {
		printf("没有此联系人！\n");
		return;
	}
	printf("姓名:%s\t 年龄:%d\t 电话:%s\t 性别:%s\t 住址:%s\t\n", contact->date[temp].name, contact->date[temp].age, contact->date[temp].tel,
		contact->date[temp].sex, contact->date[temp].addr);
}

//修改联系人实现
void Revisecon(Contact* contact) {
	assert(contact);
	printf("请输入你要修改的联系人：\n");
	char n[NAME] = "0";
	scanf("%s", n);
	int temp = find1(contact,n);
	if (temp == -1) {
		printf("没有此联系人！\n");
		return;
	}
	printf("请输入你要修改的内容：\n");
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
		printf("请输入你要修改的姓名：\n");
		scanf("%s", n1);
		memcpy(contact->date[temp].name, n1, sizeof(n1));
		break;
	case 2:
		printf("请输入你要修改的年龄：\n");
		scanf("%d", &age1);
		contact->date[temp].age = age1;
		break;
	case 3:
		printf("请输入你要修改的电话：\n");
		scanf("%s", tel1);
		memcpy(contact->date[temp].tel, tel1, sizeof(tel1));
		break;
	case 4:
		printf("请输入你要修改的性别：\n");
		scanf("%s", sex1);
		memcpy(contact->date[temp].sex, sex1, sizeof(sex1));
		break;
	case 5:
		printf("请输入你要修改的住址：\n");
		scanf("%s", addr1);
		memcpy(contact->date[temp].addr, addr1, sizeof(addr1));
		break;
	default:
		printf("输入错误！\n");
		break;
	}
}
//比较函数
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
//排序联系人实现
void Sortcon(Contact* contact)
{
	assert(contact);
	int(* com[5])(const void*, const void*) = { 0,comname,comage,comtel,comaddr };
	commenu();
	printf("请选择要排序的方式：\n");
	int temp = 0;
	scanf("%d", &temp);
	qsort(contact->date, contact->count, sizeof(people),com[temp]);
	printf("排序成功！\n");
}



//显示已有的联系人信息
void Showcon(const Contact* contact) {
	assert(contact);
	for (int i = 0; i < contact->count; i++) {
		printf("姓名:%10s\t 年龄:%3d\t 电话:%20s\t 性别:%5s\t 住址:%30s\t\n", contact->date[i].name, contact->date[i].age,
			contact->date[i].tel, contact->date[i].sex, contact->date[i].addr);
	}
}
//释放内存
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
		/*fprintf(f, "姓名:%s\t 年龄:%d\t 电话:%s\t 性别:%s\t 住址:%s\t\n", contact->date[i].name,
			contact->date[i].age,
			contact->date[i].tel,
			contact->date[i].sex,
			contact->date[i].addr);*/
	}
	fclose(f);
	f = NULL;
}
