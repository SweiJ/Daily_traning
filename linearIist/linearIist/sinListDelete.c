#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct Node
{
	ElemType Data; // ������
	struct Node* next; // ָ���� �洢ֱ�Ӻ�̽��Ĵ洢λ��
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

// ������Ĵ���һ ͷ�巨����������
void LinkListCreatH(SLNode* L)
{
	printf("�������������������ctrl+z\n");
	printf("������Ҫ�����ֵ��");
	ElemType Elem; // Ҫ�����Ԫ��
	while (scanf("%d", &Elem) != EOF)
	{
		printf("������Ҫ�����ֵ���˳���");
		SLNode* currentNodeH = NULL; // ��ǰ���
		currentNodeH = (SLNode*)malloc(sizeof(SLNode));
		currentNodeH->Data = Elem; // Ԫ�ط��ڵ�ǰ����������
		currentNodeH->next = L->next; // ��ǰ��ָ����ָ��֮ǰ����ͷ����ָ����
		L->next = currentNodeH; // ֮ǰ�����ͷ���ָ��ǰ���
	}
}

// ������Ĵ����� β�巨����������
void LinkListCreatT(SLNode* L)
{
	SLNode* priorNode; // ��Ե�ǰ����ǰһ�����
	priorNode = L; // ��ʼΪLͷ���
	ElemType Elem;
	printf("�������������������ctrl+z\n");
	printf("������Ҫ�����ֵ��");
	while (scanf("%d", &Elem) != EOF)
	{
		printf("������Ҫ�����ֵ���˳���");
		SLNode* currentNodeT; // ��ǰҪ������
		currentNodeT = (SLNode*)malloc(sizeof(SLNode));
		currentNodeT->Data = Elem;
		//p->next = NULL;
		priorNode->next = currentNodeT; // ǰһ�����ָ��ǰ���
		priorNode = currentNodeT; // ����ǰ����Ϊǰһ����㣬���ڲ�����һ�����
	}
	priorNode->next = NULL; // ����Ľ�β
}

void output(NodePoint L)//����
{
	SLNode* p;
	for (p = L->next; p != NULL; p = p->next)
	{
		printf("%d   ", p->Data);
	}
	printf("\n");
}

// ɾ������L�еĵ�i��Ԫ�ز�����elem��Ϊ��ɾ��Ԫ�صĽ���ֵ
ElemType ListDelete(SLNode* L, int i, ElemType* elem)
{
	if (i < 1) // ��0��λ�õ���ͷָ��λ��
		return 0;
	SLNode* p = NULL;
	int j = 0;
	p = L;
	while (p != NULL && p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL) // �����ǰ������Ҫɾ��λ�õĽ��Ϊ��������
		return 0;
	SLNode* q = p->next; // Ҫɾ��λ�ý�㸳��ָ��q
	*elem = q->Data; // ��elem����ɾ������ֵ
	if(q->next != NULL) // ���Ҫɾ��������һ����㲻Ϊ����ɾ��ǰ�Ľ��ָ����һ�����
		p->next = q->next;
	free(q); // �ͷ�ɾ�����
	return 1;
}

void DestoryList(SLNode* L)
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
	int location = 0, Elem = 0;
	SLNode* head = listInitiate();
	LinkListCreatH(head);
	output(head);
	printf("������Ҫɾ��Ԫ�ص�λ��:\n");
	scanf("%d", &location);
	ListDelete(head, location, &Elem);
	printf("%d ��ɾ��\n", Elem);
	output(head);
	DestoryList(head);
}