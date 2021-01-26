#include <stdio.h>
#include <assert.h>

char* my_stycpy(char* dest, const char* src)
{
    char* ret = dest;  // 首先将dest的首地址赋给ret
    assert(dest != NULL); //断言 如果括号里面是真的则报错
    assert(src != NULL);

    while(*dest++ = *src++) // 把src指向的字符串拷贝到dest指向的空间，包含'\0'
    {
        ;
    }
    return ret;
}

int main()
{
    //字符串拷贝
    char arr1[] = "#######";
    char arr2[] = "Swei";

    printf("%s\n", my_stycpy(arr1, arr2));

    return 0;
}