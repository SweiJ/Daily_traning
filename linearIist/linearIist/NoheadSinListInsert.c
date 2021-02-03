#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct Node
{
	ElemType Data;
	struct Node* next;
} SLNode, * NodePoint;

NodePoint listInitiate()
{
	SLNode* L = NULL;
	L = (SLNode*)malloc(sizeof(SLNode));
	if (!L)
		printf("����ռ�ʧ�ܣ�");
	L->next = NULL;
	return L;
}

int listInsert(SLNode* L, int i, ElemType e) // �ڵ� i ��λ�ò���Ԫ�� e
{
	if (i < 1)
		return 0;
	if (i == 1) // �����1�����Ĳ���
	{
		SLNode* s = (SLNode*)malloc(sizeof(SLNode));
		s->Data = e;
		s->next = L;
		L = s; // ͷָ��ָ���½��
		return 1;
	}
	SLNode* p = NULL; // ��ָ������ָ��Ҫ���Ԫ�ص�λ��
	int j = 1; // ��ǰpָ���λ��
	p = L; // Lָ��ͷ���
	while (p != NULL && j < i - 1) // ��i���ڵ�һ��ʱ��pͨ��ѭ���ҵ���Ӧi��λ��
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	SLNode* NewNode = (SLNode*)malloc(sizeof(SLNode));
	NewNode->Data = e;
	NewNode->next = p->next; // �½��ָ����ǰpָ��Ľ��
	p->next = NewNode; // Ҫ����ǰ���pָ���²�����
	return 1;
}

void output(NodePoint L)//����
{
	SLNode* p;
	for (p = L->next; p != NULL; p = p->next)
	{
		printf("%d   ", p->Data);
	}
}

void DestoryList(SLNode* L) // ��������
{
	SLNode* p;
	while (L)
	{
		p = L->next;
		free(L);
		L = p;
	}
	L = NULL;
}

int main()
{
	int num, elem;
	SLNode* head = listInitiate();
	printf("������Ҫ����ĸ�����\n");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		printf("�������%d��Ԫ�أ�", i);
		scanf("%d", &elem);
		listInsert(head, i, elem);
	}
	output(head);
	DestoryList(head);
}