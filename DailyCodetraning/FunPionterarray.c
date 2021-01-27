#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void menu()
{
    printf("*********************\n");
    printf("** 1.add      2.sub**\n");
    printf("** 3.mul      4.div**\n");
    printf("**      0.exit     **\n");
    printf("*********************\n");
}
int Add(int Firnum, int Secnum)
{
    return Firnum + Secnum;
}
int Sub(int Firnum, int Secnum)
{
    return Firnum - Secnum;
}
int Mul(int Firnum, int Secnum)
{
    return Firnum * Secnum;
}
int Div(int Firnum, int Secnum)
{
    return Firnum / Secnum;
}
int main()
{
    int input = 0;
    int Firnum = 0;
    int Secnum = 0;
    int (*pfArr[])(int,int) = {Add, Sub, Mul, Div}; // ����ָ������

    do
    {
        menu();
        printf("��ѡ��:>");
        scanf("%d", &input);
        if( input >=1 && input <= 4)
        {
            printf("������������:>");
            scanf("%d%d", &Firnum, &Secnum);
            int ret = pfArr[input](Firnum, Secnum); // ������������ĺ���
            printf("%d\n", ret);
        }
        else if( input == 0)
        {
            printf("�˳���");
        }
        else
        {
            printf("�������");
        }
    } while (input);
    
}