#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;
typedef struct ListNode
{
	DataType Data;
	struct ListNode* next;
	struct ListNode* prior;
}ListNode;

void ListInit(ListNode** pphead); // ��ʼ��һ��ͷ���
ListNode* CreatListNode(DataType x); // ����һ���½��
void Listprint(ListNode* phead); // ��ӡ����
void ListPushBack(ListNode* phead, DataType x); // ����β��
void ListPopBack(ListNode* phead); // βɾ
void ListInsert(ListNode* phead, int pos, DataType x); // ����λ�ò��벻����β��
void ListDelete(ListNode* phead, int pos, DataType* x); // ����λ��ɾ��
void DestoryList(ListNode** pphead); // ��������
