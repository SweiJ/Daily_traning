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
		fputs(s[i], fp); // ���ַ���д��fp��ָ����ļ���
		fputc('\n', fp); // ��\nд��fpָ����ļ���
	}
	fclose(fp);
	fp = fopen("info.txt", "r");
	for (i = 0; i < 3; i++)
	{
		fgets(t[i], 10, fp); // ���ļ�ָ��ָ����ļ��ж�ȡ���10-1���ַ����洢��t������
		printf("%s", t[i]);
	}
	fclose(fp);
	return 0;
}