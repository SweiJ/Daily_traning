#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
#define Elemtype int
#define ListIncrement 10

typedef struct
{
	Elemtype* data; //ָ��������Ĵ洢�ռ�Ļ���ַ
	int MaxSize; //��ǰ����Ĵ洢�ռ�Ĵ�С�������㣬���ٽ��з���
	int length; //��ǰ��ʵ�ʳ��ȣ��Ѿ��洢Ԫ�غ�ռ�õĳ���
}SeqList;

int InitList(SeqList* L)
{
	// ��malloc��������һƬ�����Ŀռ�
	L->data = (int*)malloc(InitSize * sizeof(int));
	if (!L->data)
	{
		printf("��ʼ��ʧ�ܣ�\n");
		exit(0);
	}
	L->length = 0;
	L->MaxSize = InitSize;
	return 1;
}

int Create_SeqList(SeqList* L, int n)
{
	if (n > L->MaxSize)
	{
		/*
		ָ����=(��������*)realloc(Ҫ�ı��ڴ��С��ָ�������µĴ�С),��ԭ�еĿռ������ӿռ�
		 */
		int* newbase = (int*)realloc(L->data, sizeof(int) * (L->MaxSize + ListIncrement));
		if (!newbase) // �������ʧ��
		{
			printf("��ʼ��ʧ�ܣ�\n");
			exit(0);
		}
		L->data = newbase;   //��data�ĵ�ַָ���¿��ٵĵ�ַ
		L->MaxSize += ListIncrement;  //���Ӵ洢����
	}
	/*
	��������
	 */
	for (int i = 0; i < n; i++)
	{
		/*L->data[i] = i;*/
		printf("�����%d��ֵ��", i);
		/*getchar();*/
		scanf("%d", &(L->data[i]));

	}
	L->length = n;
	return 1;
}

void Print_SeqList(SeqList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}

int GetElem(SeqList* L, int Findlocation)
{
	if (Findlocation < 0 || Findlocation > L->MaxSize)
	{
		printf("�������λ������");
		return 0;
	}
	printf("��ǰλ�õ�Ԫ��Ϊ:%d\n", L->data[Findlocation - 1]);
	return 1;
}
int LocateElem(SeqList* L, int FindElem)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == FindElem)
		{
			printf("��Ԫ��Ϊ��%d��", i + 1);
			return 0;
		}
	}
	printf("û���ҵ�Ҫ���ҵ�ֵ��\n");
	return 0;
}

int main()
{
	int n = 0;
	int Findlocation = 0, FindElem = 0;
	SeqList L;

	InitList(&L);
	printf("������Ҫ�����ı�ĳ��ȣ�\n");
	scanf("%d", &n);
	printf("������е�Ԫ�أ�\n");
	Create_SeqList(&L, n);
	printf("����˳������:\n");
	Print_SeqList(&L);

	printf("����������ҵ�λ��:\n");
	scanf("%d", &Findlocation);
	GetElem(&L, Findlocation);

	printf("����������ҵ�ֵ:\n");
	scanf("%d", &FindElem);
	LocateElem(&L, FindElem);
	return 0;
}