#include "SeqList.h"

void SeqListInit(SL* s)
{
	s->Elem = (SLDataType *)malloc(sizeof(SLDataType) * 4);
	if (s->Elem == NULL)
	{
		printf("申请内存失败！\n");
		exit(-1);
	}
	s->size = 0;
	s->capacity = 4;
}

void SeqListPrint(SL* ps) // 遍历顺序表
{
	assert(ps);
	
	int num = 0;
	for (num = 0; num < ps->size; num++)
	{
		printf("第%d个元素的值为：%d \n", num + 1, ps->Elem[num]);
	}
}

void SeqListDestory(SL* ps) // 销毁顺序表
{
	free(ps->Elem);
	ps->Elem = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	// 如果插入元素个数比容量大时
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2; // 一般扩大的容量是原来的两倍
		SLDataType* newbase = (SLDataType *)realloc(ps->Elem, sizeof(SLDataType) * ps->capacity);
		if (ps->Elem == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		ps->Elem = newbase;
	}
}

void SeqListPushBack(SL* ps, SLDataType x) // 尾插
{
	assert(ps); // 断言 如果表达式为假则终止程序

	SeqListCheckCapacity(ps);

	ps->Elem[ps->size] = x; // 元素插入
	ps->size++; // 有效数据大小增加
}

void SeqListPopBack(SL* ps) // 尾删
{
	assert(ps);

	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x) // 头插
{
	assert(ps);

	SeqListCheckCapacity(ps);

	int end = ps->size - 1; // 最后一个元素的下标
	while (end >= 0) // 循环将所有元素向后移
	{
		ps->Elem[end + 1] = ps->Elem[end];
		--end;
	}
	ps->Elem[0] = x; // 将元素赋给第一个位置
	ps->size++; // 有效数据增加
}

void SeqListPopFront(SL* ps) // 头删
{
	assert(ps);

	int start = 0;
	while (start < ps->size - 1) 
	{
		ps->Elem[start] = ps->Elem[start + 1];
		++start;
	}
	ps->size--;
}

void SeqListInsert(SL* ps, int pos, SLDataType x) // 在pos位置插入x
{
	assert(ps);
	assert(pos <= ps->size && pos > 0);

	SeqListCheckCapacity(ps);

	//if (pos < 1 || pos > ps->size + 1)
	//{
	//	printf("插入位置有问题！\n"); //判断插入的位置是否有效
	//	exit(-1);
	//}

	int Sub = ps->size - 1;
	while (Sub >= pos - 1) // 循环将所有元素向后移
	{
		ps->Elem[Sub + 1] = ps->Elem[Sub];
		--Sub;
	}
	ps->Elem[pos - 1] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos) // 在pos位置删除
{
	assert(ps);
	assert(pos <= ps->size && pos > 0);

	if (pos < 1 || pos > ps->size)  //判断删除的位置是否有效
	{
		printf("删除的位置有误！\n");
		exit(-1);
	}

	//int elem = ps->Elem[pos - 1]; // 将要删除的位置的元素用elem接收
	int Sub = pos;
	while (Sub < ps->size) //将元素从前往后一次向前移一个位置
	{
		ps->Elem[Sub - 1] = ps->Elem[Sub];
		++Sub;
	}
	ps->size--;
}

int main()
{
	SL L;
	SeqListInit(&L);
	SeqListPushBack(&L, 2);
	SeqListPushBack(&L, 0);
	SeqListPushBack(&L, 2);
	SeqListPushBack(&L, 0);
	SeqListPushBack(&L, 11);
	SeqListPushBack(&L, 15);
	SeqListPushBack(&L, 99);
	SeqListPushBack(&L, 66);

	SeqListPopBack(&L);
	SeqListPushFront(&L, 2020);
	SeqListPopFront(&L);
	SeqListInsert(&L, 1, 2020);
	SeqListErase(&L, 2);

	SeqListPrint(&L);
	SeqListDestory(&L);

	return 0;
}