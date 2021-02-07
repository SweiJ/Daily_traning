#include <stdio.h>
#include <stdlib.h>

typedef int CirListType;
typedef struct CirList
{ 
	CirListType Data; // ������
	struct CirList* next; // ָ����
}CirList;

void InitCirList(CirList** pphead) // ��ʼ��һ��ͷ���
{
	CirList* head = (CirList*)malloc(sizeof(CirList));
	if (head == NULL)
		exit(-1);
	head->Data = 0;
	head->next = NULL;
	*pphead = head;
}
void CreatCirList(CirList** pphead, CirListType x) // ����ͷ���β��ʵ��ѭ������
{
	CirList* newnode = (CirList*)malloc(sizeof(CirList)); // ����һ������Ϊx�Ľ��
	if (newnode == NULL)
		exit(-1);
	newnode->Data = x;
	newnode->next = NULL;

	if ((*pphead)->next == NULL) // ���ͷ���ָ��Ϊ��
	{
		(*pphead)->next = newnode; // ͷ���ָ���½��
		newnode->next = *pphead; // �½����ָ��ͷ���
	}
	else
	{
		CirList* cur = *pphead; // ��ǰ���
	/*	newnode->next = (*pphead)->next; // �����д���Ϊͷ���÷�
		(*pphead)->next = newnode;*/
		while (cur->next->Data != 0) // ѭ���ҵ�ָ��ͷ���Ľ��
		{
			cur = cur->next;
		}
		cur->next = newnode; // ָ��ͷ���Ľ��ָ���½��
		newnode->next = *pphead; // �½��ָ��ͷ���
	}
}
	
void CirListPrint(CirList* pphead) // ע���ѭ��������ѭ��
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