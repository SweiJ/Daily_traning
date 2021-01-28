#include <stdio.h>

int check_sys()
{
	int a = 1;
	return *(char*)&a;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("Ð¡¶Ë/n");
	}
	else
	{
		printf("´ó¶Ë/n");
	}
}