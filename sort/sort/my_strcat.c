#include <stdio.h>
#include <assert.h>
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(*dest != NULL);
	assert(*src != NULL);

	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "zhang"; // arr1�Ŀռ�����㹻��
	char arr2[] = "jiaqi";

	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}