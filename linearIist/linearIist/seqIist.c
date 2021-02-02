#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
#define Elemtype int
#define ListIncrement 10

typedef struct
{
	Elemtype* data; //指向所分配的存储空间的基地址
	int MaxSize; //当前分配的存储空间的大小，若不足，可再进行分配
	int length; //当前的实际长度，已经存储元素后占用的长度
}SeqList;

int InitList(SeqList* L)
{
	// 用malloc函数申请一片连续的空间
	L->data = (int*)malloc(InitSize * sizeof(int));
	if (!L->data)
	{
		printf("初始化失败！\n");
		exit(0);
	}
	L->length = 0;
	L->MaxSize = InitSize;
	return 1;
}

int Create_SeqList(SeqList* L, int n) 
{
	if (n > L->MaxSize)
	{
		/*
		指针名=(数据类型*)realloc(要改变内存大小的指针名，新的大小),在原有的空间上增加空间
		 */
		int* newbase = (int*)realloc(L->data, sizeof(int) * (L->MaxSize + ListIncrement));
		if (!newbase) // 如果申请失败
		{
			printf("初始化失败！\n");
			exit(0);
		}
		L->data = newbase;   //将data的地址指向新开辟的地址
		L->MaxSize += ListIncrement;  //增加存储容量
	}
	/*
	存入数据
	 */
	for (int i = 0; i < n; i++)
	{
		/*L->data[i] = i;*/
		printf("输入第%d个值：", i);
		/*getchar();*/
		scanf("%d", &(L->data[i]));
		
	}
	L->length = n;
	return 1;
}

void Print_SeqList(SeqList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}

int ListInsert(SeqList* L, int location, int elem) // 将元素elem插入到L的第location个位置
{
	if (location<1 || location>L->length + 1)
	{
		printf("插入位置有问题！\n");
		return 0;
	}
	if (L->length >= L->MaxSize)		//当前存储空间已满，增加分配
	{
		int* newbase = (int*)realloc(L->data, sizeof(int) * (L->MaxSize + ListIncrement));
		if (!newbase)
		{
			printf("内存分配失败！\n");
			return 0;
		}
		L->data = newbase;
		L->MaxSize += ListIncrement;
	}
	for (int i = L->length-1; i >= location-1; i--)
	{
		L->data[i+1] = L->data[i]; // 将要插入元素位置后面的所有元素向后移一位
	}
	L->data[location - 1] = elem; // 将插入的元素放在location的位置
	L->length++; // 因为插入一个元素所以实际长度加一
	return 1;
}

int ListDelete(SeqList* L, int location, int elem) // 将L的第location个元素删除，并用elem返回
{
	if (location<1 || location>L->length)  //判断删除的位置是否有效
	{
		printf("删除的位置有误！\n");
		return 0;
	}	
	elem = L->data[location - 1]; // 将要删除的位置的元素用elem接收
	for (int i = location; i < L->length; ++i)   //将元素从前往后一次向前移一个位置
		L->data[i - 1] = L->data[i];
	L->length--;
	return elem; 
}

int main()
{
	int n = 0;
	SeqList L;
	
	/* 插入元素――指定插入位置和值*/
	int elemLoc = 0;
	int elem = 0;

	int recvalue = 0; // 作为删除元素接收值的实参

	InitList(&L);
	printf("输入需要创建的表的长度：\n");
	scanf("%d", &n);
	printf("输入表中的元素：\n");
	Create_SeqList(&L, n);
	printf("创建顺序表完成:\n");
	Print_SeqList(&L);

	printf("输入需要插入的位置和元素的值:\n");
	scanf("%d %d", &elemLoc, &elem);
	ListInsert(&L, elemLoc, elem);
	printf("插入数据完成:\n");
	Print_SeqList(&L);

	///*
	//删除元素――指定删除位置
	//  */
	printf("输入需要删除的位置:\n");
	scanf("%d", &elemLoc);
	int value = ListDelete(&L, elemLoc, recvalue);
	printf("删除数据完成：\n");
	Print_SeqList(&L);
	printf("删除的元素为：%d\n", value);

	return 0;
}