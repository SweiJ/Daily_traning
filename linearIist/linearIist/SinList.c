#include "SinList.h"

SLTNode* CreatSListNode(SListDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL)
	{
		printf("申请空间失败！\n");
		exit(-1);
	}
	newNode->data = x; // 将数据赋给新结点的数据域
	newNode->next = NULL; // 下一个结点为NULL

	return newNode;
}

void SListPrint(SLTNode* phead)
{
	int count = 0;
	SLTNode* cur = phead; // 初始化当前值
	while (cur != NULL) // 当前值不为空时
	{
		printf("%d->", cur->data);
		cur = cur->next;
		count++;
	}
	printf("NULL\n");
	printf("当前结点个数为：%d", count);
}

void SListPushBack(SLTNode** pphead, SListDataType x)
{
	SLTNode* newNode = CreatSListNode(x);

	if (*pphead == NULL) // 当头结点为空时直接赋值
		*pphead = newNode;
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL) // 找到最后一个结点
		{
			tail = tail->next;
		}
		tail->next = newNode; // 将新结点赋给最后一个结点的next
	}
}

void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL) // 如果头结点为空
		exit(-1);
	else if ((*pphead)->next == NULL) // 当只有一个结点时
	{
		free(*pphead);
		*pphead = NULL;
	}
	else // 有多个结点时
	{
		SLTNode* prev = NULL; // 定义一个跟踪结点
		SLTNode* tail = *pphead;
		while (tail->next != NULL) // 找到最后一个结点
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail); // 释放最后一个结点
		prev->next = NULL; // 将最后一个结点置为NULL

	}
}

void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newNode = CreatSListNode(x);
	newNode->next = *pphead; // 新结点指向头结点
	*pphead = newNode; // 新结点成为头结点
}

void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL) // 头结点为空
		exit(-1);
	else
	{
		SLTNode* next = (*pphead)->next;
		free(*pphead); // 释放头结点
		*pphead = next; // 第二个结点为头指针
	}
}

SLTNode* SListFind(SLTNode** pphead, SListDataType x)
{
	SLTNode* cur = *pphead;
	while(cur) // 当前结点不为空时
	{
		if (cur->data == x) // 查找匹配项
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

	int curpos = 1; // 当前位置
	while (cur->next != NULL && curpos < pos - 1) // 循环找到对应位置的前一个结点
	{
		cur = cur->next;
		curpos++;
	}
	newnode->next = cur->next; // 新结点指向插入位置的后一个结点
	cur->next = newnode; // 前一个结点指向新结点
}

void SListEraseAfter(SLTNode** pphead, int pos)
{
	if (*pphead == NULL)
		exit(-1);
	if (pos == 1) // 删除第一个结点
		*pphead = (*pphead)->next;
	else
	{
		int curpos = 1; // 当前位置
		SLTNode* prev = NULL; // 用于定位删除位置的前一个结点
		SLTNode* cur = *pphead;
		while (cur->next != NULL && curpos < pos) // 循环找到对应删除位置结点
		{
			prev = cur;
			cur = cur->next;
			curpos++;
		}
		prev->next = cur->next; // 删除位置前的结点指向要删除位置结点的后一个结点
		free(cur); // 释放删除结点
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
		printf("%d存在\n", ret->data);
	else
		printf("不存在\n");
	SListPrint(L);
	FreeList(&L);
}

