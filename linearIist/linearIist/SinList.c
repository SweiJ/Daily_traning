#include "SinList.h"

SLTNode* CreatSListNode(SListDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL)
	{
		printf("����ռ�ʧ�ܣ�\n");
		exit(-1);
	}
	newNode->data = x; // �����ݸ����½���������
	newNode->next = NULL; // ��һ�����ΪNULL

	return newNode;
}

void SListPrint(SLTNode* phead)
{
	int count = 0;
	SLTNode* cur = phead; // ��ʼ����ǰֵ
	while (cur != NULL) // ��ǰֵ��Ϊ��ʱ
	{
		printf("%d->", cur->data);
		cur = cur->next;
		count++;
	}
	printf("NULL\n");
	printf("��ǰ������Ϊ��%d", count);
}

void SListPushBack(SLTNode** pphead, SListDataType x)
{
	SLTNode* newNode = CreatSListNode(x);

	if (*pphead == NULL) // ��ͷ���Ϊ��ʱֱ�Ӹ�ֵ
		*pphead = newNode;
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL) // �ҵ����һ�����
		{
			tail = tail->next;
		}
		tail->next = newNode; // ���½�㸳�����һ������next
	}
}

void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL) // ���ͷ���Ϊ��
		exit(-1);
	else if ((*pphead)->next == NULL) // ��ֻ��һ�����ʱ
	{
		free(*pphead);
		*pphead = NULL;
	}
	else // �ж�����ʱ
	{
		SLTNode* prev = NULL; // ����һ�����ٽ��
		SLTNode* tail = *pphead;
		while (tail->next != NULL) // �ҵ����һ�����
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail); // �ͷ����һ�����
		prev->next = NULL; // �����һ�������ΪNULL

	}
}

void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newNode = CreatSListNode(x);
	newNode->next = *pphead; // �½��ָ��ͷ���
	*pphead = newNode; // �½���Ϊͷ���
}

void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL) // ͷ���Ϊ��
		exit(-1);
	else
	{
		SLTNode* next = (*pphead)->next;
		free(*pphead); // �ͷ�ͷ���
		*pphead = next; // �ڶ������Ϊͷָ��
	}
}

SLTNode* SListFind(SLTNode** pphead, SListDataType x)
{
	SLTNode* cur = *pphead;
	while(cur) // ��ǰ��㲻Ϊ��ʱ
	{
		if (cur->data == x) // ����ƥ����
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SLTNode** pphead, int pos, SListDataType x)
{
	if (*pphead == NULL)
		exit(-1);

	SLTNode* cur = *pphead;
	SLTNode* newnode = CreatSListNode(x);

	int curpos = 1; // ��ǰλ��
	while (cur->next != NULL && curpos < pos - 1) // ѭ���ҵ���Ӧλ�õ�ǰһ�����
	{
		cur = cur->next;
		curpos++;
	}
	newnode->next = cur->next; // �½��ָ�����λ�õĺ�һ�����
	cur->next = newnode; // ǰһ�����ָ���½��
}

void SListEraseAfter(SLTNode** pphead, int pos)
{
	if (*pphead == NULL)
		exit(-1);
	if (pos == 1) // ɾ����һ�����
		*pphead = (*pphead)->next;
	else
	{
		int curpos = 1; // ��ǰλ��
		SLTNode* prev = NULL; // ���ڶ�λɾ��λ�õ�ǰһ�����
		SLTNode* cur = *pphead;
		while (cur->next != NULL && curpos < pos) // ѭ���ҵ���Ӧɾ��λ�ý��
		{
			prev = cur;
			cur = cur->next;
			curpos++;
		}
		prev->next = cur->next; // ɾ��λ��ǰ�Ľ��ָ��Ҫɾ��λ�ý��ĺ�һ�����
		free(cur); // �ͷ�ɾ�����
	}
}

void FreeList(SLTNode** phead)
{
	SLTNode* current = *phead;
	while (*phead != NULL)
	{
		*phead = current->next;
		free(current);
		current = *phead;
	}
}
int main()
{
	SLTNode* L = NULL;
	SListPushBack(&L, 1);
	SListPushBack(&L, 2);
	SListPushBack(&L, 3);
	SListPushBack(&L, 4);
	SListPopBack(&L);
	SListPushFront(&L, 6);
	SListInsertAfter(&L, 7, 4);
	SListEraseAfter(&L, 1);
	SLTNode* ret = SListFind(&L, 7);
	if (ret)
		printf("%d����\n", ret->data);
	else
		printf("������\n");
	SListPrint(L);
	FreeList(&L);
}

