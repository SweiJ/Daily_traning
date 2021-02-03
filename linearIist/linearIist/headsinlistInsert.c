#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct Node
{
	ElemType Data;
	struct Node* next;
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

int listInsert(SLNode* L, int i, ElemType e) // 在第 i 个位置插入元素 e
{
	if (i < 1)
		return 0;
	SLNode* p = NULL; // 该指针用于指向要存放元素的位置
	int j = 0; // 当前p指向的位置
	p = L; // L指向头结点
	while (p != NULL && j < i - 1) // 当i不在第一个时，p通过循环找到对应i的位置
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	SLNode* NewNode = (SLNode*)malloc(sizeof(SLNode));
	NewNode->Data = e;
	NewNode->next = p->next; // 新结点指向以前p指向的结点
	p->next = NewNode; // 要插入前面的p指向新插入结点
	return 1;
}

void output(NodePoint L)//遍历
{
	SLNode* p;
	for (p = L->next; p != NULL; p = p->next)
	{
		printf("%d   ", p->Data);
	}
}

void Destory(SLNode* L)
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
	int num, elem;
	SLNode* head = listInitiate();
	printf("输入你要插入的个数：\n");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		printf("请输入第%d个元素：", i);
		scanf("%d", &elem);
		listInsert(head, i, elem);
	}
	output(head);
}