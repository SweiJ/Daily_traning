#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1

void hanoi(int n, char a, char b, char c) //�������a�����ϵ����ӽ���b�����ƶ���c����
{
    if (1 == n) //�����һ������ֱ�ӽ�a�����ϵ������ƶ���c
    {
        printf("%c-->%c\n", a, c);
    }
    else
    {
        hanoi(n - 1, a, c, b);     //��a������n-1�����ӽ���c���ӣ��ƶ���b����
        printf("%c-->%c\n", a, c); //��ֱ�ӽ�a�����ϵ����һ�������ƶ���c
        hanoi(n - 1, b, a, c);     //Ȼ��b�����ϵ�n-1�����ӽ���a�ƶ���c
    }
}

int main()
{
    int input;
    printf("Input the number of diskes:");
    scanf("%d", &input);
    hanoi(input, 'A', 'B', 'C');
    return 0;
}
