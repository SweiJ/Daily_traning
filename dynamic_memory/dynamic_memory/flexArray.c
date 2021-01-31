#include <stdio.h>
#include <stdlib.h>

struct flexArr
{
	int num;
	int arr[0]; // 柔性数组--可以调整其大小
};

int main()
{
	int i = 0;
	// 将结构体的柔性数组申请20个字节的空间
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
	//struct flexArr* mom = realloc(momery, 44); // 当柔性数组空间不够时，重新申请空间
	free(momery);
	momery = NULL;
	/*free(mom);
	mom = NULL;*/
}