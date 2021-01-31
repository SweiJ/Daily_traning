#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	char* s[3] = { "goole","baidu","Cprogramming" }, t[3][10];
	int i;
	fp = fopen("info.txt", "w");
	for (i = 0; i < 3; i++)
	{
		fputs(s[i], fp); // 将字符串写入fp所指向的文件中
		fputc('\n', fp); // 将\n写入fp指向的文件中
	}
	fclose(fp);
	fp = fopen("info.txt", "r");
	for (i = 0; i < 3; i++)
	{
		fgets(t[i], 10, fp); // 从文件指针指向的文件中读取最多10-1个字符，存储到t数组中
		printf("%s", t[i]);
	}
	fclose(fp);
	return 0;
}