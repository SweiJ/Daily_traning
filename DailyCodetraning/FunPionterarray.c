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
    int (*pfArr[])(int,int) = {Add, Sub, Mul, Div}; // 函数指针数组

    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        if( input >=1 && input <= 4)
        {
            printf("请输入两个数:>");
            scanf("%d%d", &Firnum, &Secnum);
            int ret = pfArr[input](Firnum, Secnum); // 调用数组里面的函数
            printf("%d\n", ret);
        }
        else if( input == 0)
        {
            printf("退出！");
        }
        else
        {
            printf("输入错误！");
        }
    } while (input);
    
}