#include <stdio.h>
#include <assert.h>

char* my_stycpy(char* dest, const char* src)
{
    char* ret = dest;
    assert(dest != NULL);
    assert(src != NULL);

    while(*dest++ = *src++)
    {
        ;
    }
    return ret;
}

int main()
{
    //×Ö·û´®¿½±´
    char arr1[] = "#######";
    char arr2[] = "Swei";

    printf("%s\n", my_stycpy(arr1, arr2));

    return 0;
}