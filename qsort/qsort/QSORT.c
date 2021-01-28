#include <stdio.h>
#include <stdlib.h>

int cmp_float(const void* e1, const void* e2)
{
	return ((int)(*(float*)e1 - *(float*)e2));
}

int Flsort()
{
	int i = 0;
	float fl[] = { 9.0, 8.0, 7.0, 6.9, 5.0, 4.0, 3.0, 2.0, 1.0 };
	int sz = sizeof(fl) / sizeof(fl[0]);
	qsort(fl, sz, sizeof(fl[0]), cmp_float);
	for (i = 0; i < sz; i++)
	{
		printf("%f\t", fl[i]);
	}
}
int main()
{
	Flsort();
	
	return 0;
}