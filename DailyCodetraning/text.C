#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

char* my_stycpy(char* dest, const char* src)
{
    char* ret = dest;  // ���Ƚ�dest���׵�ַ����ret
    assert(dest != NULL); //���� �����������������򱨴�
    assert(src != NULL);

    while(*dest++ = *src++) // ��srcָ����ַ���������destָ��Ŀռ䣬����'\0'
    {
        ;
    }
    return ret;
}

int main()
{
    //�ַ�������
    char arr1[] = "#######";
    char arr2[] = "Swei";

    printf("%s\n", my_stycpy(arr1, arr2));

    return 0;
}