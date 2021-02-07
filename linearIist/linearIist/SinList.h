#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data; // 数据域
	struct SListNode* next; // 指针域
}SLTNode;

SLTNode* CreatSListNode(SListDataType x); // 创建一个结点
void SListPushBack(SLTNode** pphead, SListDataType x); // 尾插
void SListPopBack(SLTNode** pphead); // 尾删
void SListPushFront(SLTNode** pphead, SListDataType x); // 头插
void SListPopFront(SLTNode** pphead); // 头删
void SListInsertAfter(SLTNode** pphead, int pos, SListDataType x);
void SListEraseAfter(SLTNode** pphead, int pos);
SLTNode* SListFind(SLTNode** phead, SListDataType x); // 查找结点

void SListPrint(SLTNode* phead); // 打印链表
void FreeList(SLTNode** phead); // 释放链表