#define _CRT_SECURE_NO_WARNINGS
//�߻�����ߵĽڵ�
//����һ������ͼ��ͼ���� n ���ڵ㣬�ڵ��Ŵ� 0 �� n - 1 ������ÿ���ڵ㶼 ǡ��һ�� ���ߡ�
//
//ͼ��һ���±�� 0 ��ʼ������Ϊ n ���������� edges ��ʾ������ edges[i] ��ʾ����һ���ӽڵ� i ���ڵ� edges[i] �� ���� �ߡ�
//
//�ڵ� i �� �߻��� ����Ϊ�����д���һ��ָ��ڵ� i �ıߵĽڵ�� ��� �ܺ͡�
//
//���� �߻��� ��ߵĽڵ㡣�������ڵ�� �߻��� ��ͬ�����ر�� ��С ���Ǹ���
int edgeScore(int* edges, int edgesSize) {
    long long* arr = (long long*)calloc(100000, sizeof(long long));
    for (int i = 0; i < edgesSize; i++) {
        arr[edges[i]] += i;
    }
    long long temp = arr[0];
    int location = 0;
    for (int i = 0; i < edgesSize; i++) {
        if (arr[i] > temp) {
            temp = arr[i];
            location = i;
        }
    }
    return location;
}