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

void ListInit(ListNode** pphead); // 初始化一个头结点
ListNode* CreatListNode(DataType x); // 创建一个新结点
void Listprint(ListNode* phead); // 打印链表
void ListPushBack(ListNode* phead, DataType x); // 链表尾插
void ListPopBack(ListNode* phead); // 尾删
void ListInsert(ListNode* phead, int pos, DataType x); // 具体位置插入不适用尾插
void ListDelete(ListNode* phead, int pos, DataType* x); // 具体位置删除
void DestoryList(ListNode** pphead); // 销毁链表
