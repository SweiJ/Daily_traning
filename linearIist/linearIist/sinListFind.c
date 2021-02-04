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

// ��λ���ң����ص�i��Ԫ��
NodePoint locateElem(SLNode* L, int i)
{
	if (i < 0)
		return 0;
	SLNode* p = NULL;
	int j = 0;
	p = L;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

// ��ֵ���� �ҵ�������elem�Ľ��
NodePoint valueElem(SLNode* L, ElemType elem)
{
	SLNode* p = L->next;
	//while (p != NULL && strcmp(p->Data, elem) == 0) // ����Ƚϸ��ӽṹ����
	while (p != NULL && p->Data != elem) // �ӵ�1����㿪ʼ����������Ϊelem�Ľ��
		p = p->next;
	return p;
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
	int location = 0, Elem =0;
	SLNode* head = listInitiate();
	LinkListCreatH(head);
	output(head);

	//printf("��������Ҫ���ҵ�λ�ã�\n");
	//scanf("%d", &location);
	//NodePoint elem = locateElem(head, location);
	//printf("��ǰ�Ľ���ֵΪ��%d", elem->Data);

	printf("��������Ҫ���ҵ�ֵ��\n");
	scanf("%d", &Elem);
	NodePoint elem = locateElem(head, location);
	printf("��ǰ�Ľ���ֵ�ĵ�ַΪ��%p", elem);
	DestoryList(head);
}