#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu
{
	char name[20];
	int age;
};

int cmp_stu_by_name(const void* e1, const void* e2)
{
	// 比较名字就是比较字符串
	// 字符串比较不能直接用><=来比较，应该用strcmp函数
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}

void strusort()
{
	int i = 0;
	struct Stu s[3] = { {"jiang",20},{"zhang",30},{"qi",18} };
	int sz = sizeof(s) / sizeof(s[0]);

	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	// 第一个参数：待排序数组的首元素地址
	// 第二个参数：待排序数组的元素个数
	// 第三个参数：待排序数组的每个元素的大小 单位是字节
	// 第四个参数：是函数指针，比较两个元素的所用函数的地址-这个函数使用者自己实现
	//		       函数指针的两个参数是:待比较的两个元素的地址
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", s[i].name);
	}
}
int main()
{
	strusort();

	return 0;
}