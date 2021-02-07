#include <stdio.h>
#include <stdlib.h>

typedef int CirListType;
typedef struct CirList
{ 
	CirListType Data; // 数据域
	struct CirList* next; // 指针域
}CirList;

void InitCirList(CirList** pphead) // 初始化一个头结点
{
	CirList* head = (CirList*)malloc(sizeof(CirList));
	if (head == NULL)
		exit(-1);
	head->Data = 0;
	head->next = NULL;
	*pphead = head;
}
void CreatCirList(CirList** pphead, CirListType x) // 利用头插和尾插实现循环链表
{
	CirList* newnode = (CirList*)malloc(sizeof(CirList)); // 创建一个数据为x的结点
	if (newnode == NULL)
		exit(-1);
	newnode->Data = x;
	newnode->next = NULL;

	if ((*pphead)->next == NULL) // 如果头结点指向为空
	{
		(*pphead)->next = newnode; // 头结点指向新结点
		newnode->next = *pphead; // 新结点又指向头结点
	}
	else
	{
		CirList* cur = *pphead; // 当前结点
	/*	newnode->next = (*pphead)->next; // 这两行代码为头插用法
		(*pphead)->next = newnode;*/
		while (cur->next->Data != 0) // 循环找到指向头结点的结点
		{
			cur = cur->next;
		}
		cur->next = newnode; // 指向头结点的结点指向新结点
		newnode->next = *pphead; // 新结点指向头结点
	}
}
	
void CirListPrint(CirList* pphead) // 注意该循环会无限循环
{
	CirList* cur = pphead;
	while (cur->next != NULL)
	{
		printf("%d->", cur->Data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	CirList* head;
	InitCirList(&head);
	CreatCirList(&head, 1);
	CreatCirList(&head, 2);
	CreatCirList(&head, 3);
	CirListPrint(head);
}