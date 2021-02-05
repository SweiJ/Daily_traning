#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* Elem;
	int size;  // ��Ч���ݵĸ���
	int capacity; // ����
}SL, SeqList;

void SeqListInit(SL* s);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);
void SeqListCheckCapacity(SL* ps);
// β��βɾ ͷ��ͷɾ
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

// ����λ�ò���ɾ��
void SeqListInsert(SL* ps,int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

// ˳������
int SeqListFind(SL* psl, SLDataType x);