#include "SeqList.h"

void SeqListInit(SL* s)
{
	s->Elem = (SLDataType *)malloc(sizeof(SLDataType) * 4);
	if (s->Elem == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	s->size = 0;
	s->capacity = 4;
}

void SeqListPrint(SL* ps) // ����˳���
{
	assert(ps);
	
	int num = 0;
	for (num = 0; num < ps->size; num++)
	{
		printf("��%d��Ԫ�ص�ֵΪ��%d \n", num + 1, ps->Elem[num]);
	}
}

void SeqListDestory(SL* ps) // ����˳���
{
	free(ps->Elem);
	ps->Elem = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	// �������Ԫ�ظ�����������ʱ
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2; // һ�������������ԭ��������
		SLDataType* newbase = (SLDataType *)realloc(ps->Elem, sizeof(SLDataType) * ps->capacity);
		if (ps->Elem == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		ps->Elem = newbase;
	}
}

void SeqListPushBack(SL* ps, SLDataType x) // β��
{
	assert(ps); // ���� ������ʽΪ������ֹ����

	SeqListCheckCapacity(ps);

	ps->Elem[ps->size] = x; // Ԫ�ز���
	ps->size++; // ��Ч���ݴ�С����
}

void SeqListPopBack(SL* ps) // βɾ
{
	assert(ps);

	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x) // ͷ��
{
	assert(ps);

	SeqListCheckCapacity(ps);

	int end = ps->size - 1; // ���һ��Ԫ�ص��±�
	while (end >= 0) // ѭ��������Ԫ�������
	{
		ps->Elem[end + 1] = ps->Elem[end];
		--end;
	}
	ps->Elem[0] = x; // ��Ԫ�ظ�����һ��λ��
	ps->size++; // ��Ч��������
}

void SeqListPopFront(SL* ps) // ͷɾ
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

void SeqListInsert(SL* ps, int pos, SLDataType x) // ��posλ�ò���x
{
	assert(ps);
	assert(pos <= ps->size && pos > 0);

	SeqListCheckCapacity(ps);

	//if (pos < 1 || pos > ps->size + 1)
	//{
	//	printf("����λ�������⣡\n"); //�жϲ����λ���Ƿ���Ч
	//	exit(-1);
	//}

	int Sub = ps->size - 1;
	while (Sub >= pos - 1) // ѭ��������Ԫ�������
	{
		ps->Elem[Sub + 1] = ps->Elem[Sub];
		--Sub;
	}
	ps->Elem[pos - 1] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos) // ��posλ��ɾ��
{
	assert(ps);
	assert(pos <= ps->size && pos > 0);

	if (pos < 1 || pos > ps->size)  //�ж�ɾ����λ���Ƿ���Ч
	{
		printf("ɾ����λ������\n");
		exit(-1);
	}

	//int elem = ps->Elem[pos - 1]; // ��Ҫɾ����λ�õ�Ԫ����elem����
	int Sub = pos;
	while (Sub < ps->size) //��Ԫ�ش�ǰ����һ����ǰ��һ��λ��
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