#include  <stdio.h>
#include  <stdlib.h>
#define    N    5
typedef struct node {
    int  data;
    struct node* next;
} RevList;

RevList* fun(RevList* phead)
{
    RevList* curhead, * cur, * lead;
    curhead = phead; // 头结点
    if (curhead == NULL)
        return NULL;
    cur = curhead->next; // 当前要移动的结点
    curhead->next = NULL;  // 当前头结点作为尾结点
    while (cur) // 循环移动
    {
        lead = cur->next; // 要移动的结点下一个赋给lead
        cur->next = curhead; // 当前移动结点指向当前头结点
        curhead = cur;  // 移动的结点作为头结点
        cur = lead; // 移动写一个
    }
    return  curhead;
}
RevList* creatlist(int  Elem[])
{
    RevList* Head, * cur, * newnode;        int  i;
    Head = NULL;
    for (i = 0; i < N; i++)
    {
        newnode = (RevList*)malloc(sizeof(RevList));
        newnode->data = Elem[i];
        newnode->next = NULL;
        if (Head == NULL)
            Head = cur = newnode;
        else
        {
            cur->next = newnode; // 对结点进行插入
            cur = newnode;
        }
    }
    return  Head;
}
void outlist(RevList* phead)
{
    RevList* cur;
    cur = phead;
    if (cur == NULL)  printf("The list is NULL!\n");
    else
    {
        printf("\nHead  ");
        do
        {
            printf("->%d", cur->data); 
            cur = cur->next;
        } while (cur != NULL);
        printf("->End\n");
    }
}
main()
{
    RevList* head;
    int  Elem[N] = { 2,4,6,8,10 };
    head = creatlist(Elem);
    printf("\nThe original list:\n");
    outlist(head);
    head = fun(head);
    printf("\nThe list after inverting :\n");
    outlist(head);
    getchar();
}
