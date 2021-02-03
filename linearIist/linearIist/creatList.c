#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct Node
{
	ElemType Data; // 数据域
	struct Node* next; // 指针域 存储直接后继结点的存储位置
} SLNode, * NodePoint;

NodePoint listInitiate()
{
	SLNode* L = NULL;
	L = (SLNode*)malloc(sizeof(SLNode));
	if (!L)
		printf("申请空间失败！");
	L->next = NULL;
	return L;
}

// 单链表的创建一 头插法建立单链表
void LinkListCreatH(SLNode* L)
{
	ElemType Elem; // 要插入的元素
	while (scanf("%d", &Elem) != EOF)
	{
		printf("ceshi");
		SLNode* currentNodeH; // 当前结点
		currentNodeH = (SLNode*)malloc(sizeof(SLNode));
		currentNodeH->Data = Elem; // 元素放在当前结点的数据域
		currentNodeH->next = L->next; // 当前的指针域指向之前链表头结点的指针域
		L->next = currentNodeH; // 之前链表的头结点指向当前结点
	}
}

// 单链表的创建二 尾插法建立单链表
void LinkListCreatT(SLNode* L)
{
    SLNode * priorNode; // 相对当前结点的前一个结点
	priorNode = L; // 初始为L头结点
    ElemType Elem;
    while (scanf("%d", &Elem) != EOF)
    {
        SLNode * currentNodeT; // 当前要插入结点
		currentNodeT = (SLNode*)malloc(sizeof(SLNode));
		currentNodeT->Data = Elem;
        //p->next = NULL;
		priorNode->next = currentNodeT; // 前一个结点指向当前结点
		priorNode = currentNodeT; // 将当前结点改为前一个结点，便于插入下一个结点
    }
	priorNode->next = NULL; // 链表的结尾
}

void output(NodePoint L)//遍历
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