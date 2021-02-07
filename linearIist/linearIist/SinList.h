#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data; // ������
	struct SListNode* next; // ָ����
}SLTNode;

SLTNode* CreatSListNode(SListDataType x); // ����һ�����
void SListPushBack(SLTNode** pphead, SListDataType x); // β��
void SListPopBack(SLTNode** pphead); // βɾ
void SListPushFront(SLTNode** pphead, SListDataType x); // ͷ��
void SListPopFront(SLTNode** pphead); // ͷɾ
void SListInsertAfter(SLTNode** pphead, int pos, SListDataType x);
void SListEraseAfter(SLTNode** pphead, int pos);
SLTNode* SListFind(SLTNode** phead, SListDataType x); // ���ҽ��

void SListPrint(SLTNode* phead); // ��ӡ����
void FreeList(SLTNode** phead); // �ͷ�����