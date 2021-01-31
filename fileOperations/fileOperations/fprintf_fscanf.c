#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student
{
	char sno[8];
	char name[20];
	char sex;
	int age;
	double score;
};
int main(void)
{
	FILE* fp;
	struct student s[3] = {
		{"2020001","LiMing",'M',18, 92.5},
		{"2020002","WangFang",'M',18, 89.0},
		{"2020003","ZhangJiaQi",'F',20, 95.5},
	};
	struct student t[3];
	int i;
	fp = fopen("stu.txt", "w");
	for (i = 0; i < 3; i++)
		fprintf(fp, "%c %s %s %d %.1f\n", 
			s[i].sex, s[i].sno, s[i].name, s[i].age, s[i].score); // 将数据写入fp指向的文件中
		fclose(fp);
		puts("sno		     name     sex  age  score");
		fp = fopen("stu.txt", "r");
		for (i = 0; i < 3; i++)
		{
			fscanf(fp, "%c%s%s%d%lf",
				&t[i].sex, t[i].sno, t[i].name, &t[i].age, &t[i].score); // 从fp指向的文件中读取数据
			fgetc(fp);
			printf("%s%20s%5c%5d%8.1f\n", 
				t[i].sno, t[i].name, t[i].sex, t[i].age, t[i].score);
		}
		fclose(fp);
		return 0;
}