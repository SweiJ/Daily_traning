#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	char ch;
	fp = fopen("data.txt", "w"); // 打开文件 w表示写
	printf("Input a string: ");
	scanf("%c", &ch);
	while(ch != '\n')
	{
		fputc(ch, fp); // 将输入字符ch 写入fp指向的文件中
		scanf("%c", &ch);
	}
	fclose(fp); // 关闭文件
	fp = fopen("data.txt", "r"); // r表示读 a表示追加 b表示二进制文件 t表示文本文件
	ch = fgetc(fp); // 将fp指向的文件中读出一个字符并赋值给ch
	while (ch != EOF) // 循环读出文件中的字符
	{
		printf("%c", ch);
		ch = fgetc(fp);
	}
	printf("\n");
	fclose(fp);
	return 0;
}