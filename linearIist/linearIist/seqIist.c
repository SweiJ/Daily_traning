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

int ListInsert(SeqList* L, int location, int elem) // ��Ԫ��elem���뵽L�ĵ�location��λ��
{
	if (location<1 || location>L->length + 1)
	{
		printf("����λ�������⣡\n");
		return 0;
	}
	if (L->length >= L->MaxSize)		//��ǰ�洢�ռ����������ӷ���
	{
		int* newbase = (int*)realloc(L->data, sizeof(int) * (L->MaxSize + ListIncrement));
		if (!newbase)
		{
			printf("�ڴ����ʧ�ܣ�\n");
			return 0;
		}
		L->data = newbase;
		L->MaxSize += ListIncrement;
	}
	for (int i = L->length-1; i >= location-1; i--)
	{
		L->data[i+1] = L->data[i]; // ��Ҫ����Ԫ��λ�ú��������Ԫ�������һλ
	}
	L->data[location - 1] = elem; // �������Ԫ�ط���location��λ��
	L->length++; // ��Ϊ����һ��Ԫ������ʵ�ʳ��ȼ�һ
	return 1;
}

int ListDelete(SeqList* L, int location, int elem) // ��L�ĵ�location��Ԫ��ɾ��������elem����
{
	if (location<1 || location>L->length)  //�ж�ɾ����λ���Ƿ���Ч
	{
		printf("ɾ����λ������\n");
		return 0;
	}	
	elem = L->data[location - 1]; // ��Ҫɾ����λ�õ�Ԫ����elem����
	for (int i = location; i < L->length; ++i)   //��Ԫ�ش�ǰ����һ����ǰ��һ��λ��
		L->data[i - 1] = L->data[i];
	L->length--;
	return elem; 
}

int main()
{
	int n = 0;
	SeqList L;
	
	/* ����Ԫ�بD�Dָ������λ�ú�ֵ*/
	int elemLoc = 0;
	int elem = 0;

	int recvalue = 0; // ��Ϊɾ��Ԫ�ؽ���ֵ��ʵ��

	InitList(&L);
	printf("������Ҫ�����ı�ĳ��ȣ�\n");
	scanf("%d", &n);
	printf("������е�Ԫ�أ�\n");
	Create_SeqList(&L, n);
	printf("����˳������:\n");
	Print_SeqList(&L);

	printf("������Ҫ�����λ�ú�Ԫ�ص�ֵ:\n");
	scanf("%d %d", &elemLoc, &elem);
	ListInsert(&L, elemLoc, elem);
	printf("�����������:\n");
	Print_SeqList(&L);

	///*
	//ɾ��Ԫ�بD�Dָ��ɾ��λ��
	//  */
	printf("������Ҫɾ����λ��:\n");
	scanf("%d", &elemLoc);
	int value = ListDelete(&L, elemLoc, recvalue);
	printf("ɾ��������ɣ�\n");
	Print_SeqList(&L);
	printf("ɾ����Ԫ��Ϊ��%d\n", value);

	return 0;
}