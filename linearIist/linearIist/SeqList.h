#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* Elem;
	int size;  // 有效数据的个数
	int capacity; // 容量
}SL, SeqList;

void SeqListInit(SL* s);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);
void SeqListCheckCapacity(SL* ps);
// 尾插尾删 头插头删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

// 任意位置插入删除
void SeqListInsert(SL* ps,int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

// 顺序表查找
int SeqListFind(SL* psl, SLDataType x);