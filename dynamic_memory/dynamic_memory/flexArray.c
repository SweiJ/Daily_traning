#include <stdio.h>
#include <stdlib.h>

struct flexArr
{
	int num;
	int arr[0]; // ��������--���Ե������С
};

int main()
{
	int i = 0;
	// ���ṹ���������������20���ֽڵĿռ�
	struct flexArr* momery = (struct flexArr*)malloc(sizeof(struct flexArr)+5*sizeof(int));
	
	if (momery == NULL)
	{
		return 0;
	}
	momery->num = 100;
	for (i = 0; i < 5; i++)
	{
		momery->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", momery->arr[i]);
	}
	//struct flexArr* mom = realloc(momery, 44); // ����������ռ䲻��ʱ����������ռ�
	free(momery);
	momery = NULL;
	/*free(mom);
	mom = NULL;*/
}