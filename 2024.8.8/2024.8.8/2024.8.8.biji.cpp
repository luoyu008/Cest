#define _CRT_SECURE_NO_WARNINGS
// char* a[]={"work","at","clbb"};
//char** pa=a;
//pa++;
// pa         a  
// char**---> char*--->"w"
//              char*--->"a"
//              char*--->"c"
//��pa++֮��
//              char*--->"w"
//   char**--->char*--->"a"
//              char*--->"c"
//paָ�����char*���� ����pa++��ָpa����һ��char*����  ��ָ�����������һ��

//ָ��cpp[n]��cpp+n�Ŀ�
//char* c[] = { "entrt","new","point","first" };
//char** cp = { c + 3,c + 2,c + 1,c };
//char*** cpp = cp;
//printf("%s", **++cpp);
//�������first֮��  ��Ϊ++cpp�൱��cpp + ��1 cpp���Ų��һ��������������ʱ��Ҫ�ڴ˻����ϼ���
//printf("%s", *cpp[-1] + 3);
//�����������st  ��Ϊcpp[-2]�൱���������cpp-��2��ֵ  cpp����û�з����ı伴cpp��û����ǰŲ������  
//���Ժ���ļ����ʱ��Ҫ���ڵ�ǰcpp��λ��Ҳ�������cpp+��1��λ��

//�ַ�������
//strlen
//size_t(unsigned int) strlen(const char* s)
//���ص����޷������� ���ص���ֱ������'\0'�ַ����ĳ���
//char s[] = "abc";
//strlen(s)//3
//char s[] = { 'a','c','b' };
//strlen(s)//�˴������ֵ  ��Ϊ��ʼ����δ��ʼ������\0��  ����strlen������һֱ���¶�ȡ֪������\0 
