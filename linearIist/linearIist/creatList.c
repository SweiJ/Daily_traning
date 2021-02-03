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
	ElemType Elem; // Ҫ�����Ԫ��
	while (scanf("%d", &Elem) != EOF)
	{
		printf("ceshi");
		SLNode* currentNodeH; // ��ǰ���
		currentNodeH = (SLNode*)malloc(sizeof(SLNode));
		currentNodeH->Data = Elem; // Ԫ�ط��ڵ�ǰ����������
		currentNodeH->next = L->next; // ��ǰ��ָ����ָ��֮ǰ����ͷ����ָ����
		L->next = currentNodeH; // ֮ǰ�����ͷ���ָ��ǰ���
	}
}

// ������Ĵ����� β�巨����������
void LinkListCreatT(SLNode* L)
{
    SLNode * priorNode; // ��Ե�ǰ����ǰһ�����
	priorNode = L; // ��ʼΪLͷ���
    ElemType Elem;
    while (scanf("%d", &Elem) != EOF)
    {
        SLNode * currentNodeT; // ��ǰҪ������
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
	SLNode* head = listInitiate();
	LinkListCreatH(head);
	output(head);
	DestoryList(head);
}