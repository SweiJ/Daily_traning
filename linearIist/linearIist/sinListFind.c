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
	printf("如果完成输入则键入三次ctrl+z\n");
	printf("输入你要输入的值：");
	ElemType Elem; // 要插入的元素
	while (scanf("%d", &Elem) != EOF)
	{
		printf("输入你要输入的值或退出：");
		SLNode* currentNodeH = NULL; // 当前结点
		currentNodeH = (SLNode*)malloc(sizeof(SLNode));
		currentNodeH->Data = Elem; // 元素放在当前结点的数据域
		currentNodeH->next = L->next; // 当前的指针域指向之前链表头结点的指针域
		L->next = currentNodeH; // 之前链表的头结点指向当前结点
	}
}

// 单链表的创建二 尾插法建立单链表
void LinkListCreatT(SLNode* L)
{
	SLNode* priorNode; // 相对当前结点的前一个结点
	priorNode = L; // 初始为L头结点
	ElemType Elem;
	printf("如果完成输入则键入三次ctrl+z\n");
	printf("输入你要输入的值：");
	while (scanf("%d", &Elem) != EOF)
	{
		printf("输入你要输入的值或退出：");
		SLNode* currentNodeT; // 当前要插入结点
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
	printf("\n");
}

// 按位查找，返回第i个元素
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

// 按值查找 找到数据域elem的结点
NodePoint valueElem(SLNode* L, ElemType elem)
{
	SLNode* p = L->next;
	//while (p != NULL && strcmp(p->Data, elem) == 0) // 处理比较复杂结构类型
	while (p != NULL && p->Data != elem) // 从第1个结点开始查找数据域为elem的结点
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

	//printf("请输入你要查找的位置：\n");
	//scanf("%d", &location);
	//NodePoint elem = locateElem(head, location);
	//printf("当前的结点的值为：%d", elem->Data);

	printf("请输入你要查找的值：\n");
	scanf("%d", &Elem);
	NodePoint elem = locateElem(head, location);
	printf("当前的结点的值的地址为：%p", elem);
	DestoryList(head);
}