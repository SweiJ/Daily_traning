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

int GetElem(SeqList* L, int Findlocation)
{
	if (Findlocation < 0 || Findlocation > L->MaxSize)
	{
		printf("你输入的位置有误！");
		return 0;
	}
	printf("当前位置的元素为:%d\n", L->data[Findlocation - 1]);
	return 1;
}
int LocateElem(SeqList* L, int FindElem)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == FindElem)
		{
			printf("该元素为第%d个", i + 1);
			return 0;
		}
	}
	printf("没有找到要查找的值！\n");
	return 0;
}

int main()
{
	int n = 0;
	int Findlocation = 0, FindElem = 0;
	SeqList L;

	InitList(&L);
	printf("输入需要创建的表的长度：\n");
	scanf("%d", &n);
	printf("输入表中的元素：\n");
	Create_SeqList(&L, n);
	printf("创建顺序表完成:\n");
	Print_SeqList(&L);

	printf("输入你想查找的位置:\n");
	scanf("%d", &Findlocation);
	GetElem(&L, Findlocation);

	printf("输入你想查找的值:\n");
	scanf("%d", &FindElem);
	LocateElem(&L, FindElem);
	return 0;
}