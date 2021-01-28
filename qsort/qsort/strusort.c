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
	// �Ƚ����־��ǱȽ��ַ���
	// �ַ����Ƚϲ���ֱ����><=���Ƚϣ�Ӧ����strcmp����
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
	// ��һ���������������������Ԫ�ص�ַ
	// �ڶ��������������������Ԫ�ظ���
	// �����������������������ÿ��Ԫ�صĴ�С ��λ���ֽ�
	// ���ĸ��������Ǻ���ָ�룬�Ƚ�����Ԫ�ص����ú����ĵ�ַ-�������ʹ�����Լ�ʵ��
	//		       ����ָ�������������:���Ƚϵ�����Ԫ�صĵ�ַ
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