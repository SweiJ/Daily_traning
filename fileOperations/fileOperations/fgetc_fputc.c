#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	char ch;
	fp = fopen("data.txt", "w"); // ���ļ� w��ʾд
	printf("Input a string: ");
	scanf("%c", &ch);
	while(ch != '\n')
	{
		fputc(ch, fp); // �������ַ�ch д��fpָ����ļ���
		scanf("%c", &ch);
	}
	fclose(fp); // �ر��ļ�
	fp = fopen("data.txt", "r"); // r��ʾ�� a��ʾ׷�� b��ʾ�������ļ� t��ʾ�ı��ļ�
	ch = fgetc(fp); // ��fpָ����ļ��ж���һ���ַ�����ֵ��ch
	while (ch != EOF) // ѭ�������ļ��е��ַ�
	{
		printf("%c", ch);
		ch = fgetc(fp);
	}
	printf("\n");
	fclose(fp);
	return 0;
}