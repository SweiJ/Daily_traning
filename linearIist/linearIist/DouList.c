#include "DouList.h"

void ListInit(ListNode** pphead) 
{
	*pphead = CreatListNode(0); // ������Ϊ0
	(*pphead)->prior = *pphead; // ����ǰ��ѭ�����
	(*pphead)->next = *pphead; // ���ɺ��ѭ�����
}

ListNode* CreatListNode(DataType x) 
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	if (Node == NULL)
		exit(-1);
	Node->next = NULL; // ��ʼ���½��
	Node->prior = NULL;
	Node->Data = x;

	return Node;
}

void Listprint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead) // �ҵ�ָ��ͷ���Ľ��
	{
		printf("%d->", cur->Data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* phead, DataType x)
{
	assert(phead);

	ListNode* tail = phead->prior;
	ListNode* newnode = CreatListNode(x);

	tail->next = newnode; // β���ָ���½��
	newnode->prior = tail; // �½���ǰ��ָ��β���

	newnode->next = phead; // �½����Ϊͷ���
	phead->prior = newnode; // ͷ���ǰ��Ϊ�½��
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prior; // β���
	ListNode* prev = tail->prior; // β����ǰһ�����

	prev->next = phead; // β�����ָ��ͷ���
	phead->prior = prev; // ͷ���ǰ��ָ��β���ǰһ��
	free(tail);
}

void ListInsert(ListNode* phead, int pos, DataType x)
{
	assert(phead);

	ListNode* cur = phead->next; // ��ֵ�Ľ��
	ListNode* newnode = CreatListNode(x);
	ListNode* prev = phead;

	int curpos = 1;
	while (cur->next != phead && curpos < pos) // �ҵ�Ҫ����λ�ú�ǰһ�����
	{
		prev = cur;
		cur = cur->next;
		curpos++;
	}
	if (pos != curpos) // ����λ�ò�����Ҫ��
	{
		printf("�����λ�������⣡\n");
		exit(-1);
	}
	cur->prior = newnode; // �½��������
	newnode->next = cur;

	newnode->prior = prev;
	prev->next = newnode;
}

void ListDelete(ListNode* phead, int pos, DataType* x)
{
	assert(phead);

	ListNode* cur = phead->next; // ��ֵ�Ľ��
	ListNode* prev = phead;
	int curpos = 1;
	while (cur->next != phead && curpos < pos) // �ҵ�Ҫ����λ�ú�ǰһ�����
	{
		prev = cur;
		cur = cur->next;
		curpos++;
	}
	if (pos != curpos) // ����λ�ò�����Ҫ��
	{
		printf("ɾ����λ�������⣡\n");
		exit(-1);
	}
	*x = cur->Data; // ����ɾ��Ԫ��ֵ
	prev->next = cur->next; // ɾ��Ԫ�ز���
	cur->next->prior = prev;

	free(cur);
}

void DestoryList(ListNode** pphead)
{
	ListNode* tail = (*pphead)->prior;
	ListNode* Destory = NULL;
	while (tail->prior != *pphead)
	{
		Destory = tail;
		tail = tail->next;
		free(Destory);
		Destory = NULL;
	}
}
int main()
{
	ListNode* DouList = NULL;
	DataType Elem = 0;
	ListInit(&DouList);
	ListPushBack(DouList, 1);
	ListPushBack(DouList, 2);
	ListPushBack(DouList, 3);
	ListPushBack(DouList, 4);
	ListPushBack(DouList, 5);
	ListInsert(DouList, 2, 3);
	ListDelete(DouList, 1, &Elem);
	printf("ɾ����Ԫ��Ϊ��%d\n", Elem);
	Listprint(DouList);
}