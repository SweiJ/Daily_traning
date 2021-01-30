#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* s1 = NULL;
	char* s2 = NULL;
	char* foot_num = str1;
	if (!*str2)
		return (char*)str1;

	while (*foot_num)
	{
		s1 = foot_num;
		s2 = (char*)str2;
		while (*s1 && s2 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return foot_num; // ÕÒµ½×Ö·û´®²¢·µ»Ø
		foot_num++;
	}
	return(NULL); //ÕÒ²»µ½×Ö·û´®
}

int main()
{
	const char* str1 = "abcdef";
	const char* str2 = "abc";

	char* ret = my_strstr(str1, str2);
	printf("%s\n", ret);
}