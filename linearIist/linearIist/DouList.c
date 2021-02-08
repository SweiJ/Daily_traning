#include "DouList.h"

void ListInit(ListNode** pphead) 
{
	*pphead = CreatListNode(0); // 数据域为0
	(*pphead)->prior = *pphead; // 构成前驱循环结点
	(*pphead)->next = *pphead; // 构成后继循环结点
}

ListNode* CreatListNode(DataType x) 
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	if (Node == NULL)
		exit(-1);
	Node->next = NULL; // 初始化新结点
	Node->prior = NULL;
	Node->Data = x;

	return Node;
}

void Listprint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead) // 找到指向头结点的结点
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

	tail->next = newnode; // 尾结点指向新结点
	newnode->prior = tail; // 新结点的前驱指向尾结点

	newnode->next = phead; // 新结点后继为头结点
	phead->prior = newnode; // 头结点前驱为新结点
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prior; // 尾结点
	ListNode* prev = tail->prior; // 尾结点的前一个结点

	prev->next = phead; // 尾结点后继指向头结点
	phead->prior = prev; // 头结点前驱指向尾结点前一个
	free(tail);
}

void ListInsert(ListNode* phead, int pos, DataType x)
{
	assert(phead);

	ListNode* cur = phead->next; // 有值的结点
	ListNode* newnode = CreatListNode(x);
	ListNode* prev = phead;

	int curpos = 1;
	while (cur->next != phead && curpos < pos) // 找到要插入位置和前一个结点
	{
		prev = cur;
		cur = cur->next;
		curpos++;
	}
	if (pos != curpos) // 插入位置不符合要求
	{
		printf("输入的位置有问题！\n");
		exit(-1);
	}
	cur->prior = newnode; // 新结点插入操作
	newnode->next = cur;

	newnode->prior = prev;
	prev->next = newnode;
}

void ListDelete(ListNode* phead, int pos, DataType* x)
{
	assert(phead);

	ListNode* cur = phead->next; // 有值的结点
	ListNode* prev = phead;
	int curpos = 1;
	while (cur->next != phead && curpos < pos) // 找到要插入位置和前一个结点
	{
		prev = cur;
		cur = cur->next;
		curpos++;
	}
	if (pos != curpos) // 插入位置不符合要求
	{
		printf("删除的位置有问题！\n");
		exit(-1);
	}
	*x = cur->Data; // 接收删除元素值
	prev->next = cur->next; // 删除元素操作
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
	printf("删除的元素为：%d\n", Elem);
	Listprint(DouList);
}