#include<stdio.h>
#include<string.h>

char BF(char S[], char T[])
{
    int i, j;
    for (i = 0; i <= strlen(T) + 1; i++)
    {
        for (j = 0; j <= strlen(S) + 1; j++)
        {
            if (T[j] == S[i])
            {
                printf("%C", T[i]);
            }
        }
    }
}
void main()
{
    char S[] = "chuanmoshipipeisuanfa";
    char T[] = "suanfa";
    BF(S, T);
}
