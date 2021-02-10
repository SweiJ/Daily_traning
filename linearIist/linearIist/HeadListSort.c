#include  <stdio.h>
#include  <stdlib.h>

#define    N    6
typedef struct node {
    int  data;
    struct node* next;
} RevList;

void fun(RevList* phead)
{
    RevList* curhead, *cur;    
    int  t;
    curhead = phead->next;
    while (curhead) 
    {
        cur = curhead->next;
        while (cur) 
        {
            if (curhead->data > cur->data)
            {
                t = curhead->data;  
                curhead->data = cur->data;  
                cur->data = t;
            }
            cur = cur->next;
        }
        curhead = curhead->next;
    }
}

RevList* creatlist(int  Elem[])
{
    RevList* Head, * cur, * newnode;    
    int  i;
    Head = (RevList*)malloc(sizeof(RevList)); // 头结点
    Head->data = -1;
    Head->next = NULL;
    for (i = 0; i < N; i++)
    {
        newnode = (RevList*)malloc(sizeof(RevList));
        newnode->data = Elem[i];
        newnode->next = NULL;
        if (Head->next == NULL)
            Head->next = cur = newnode;
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
    cur = phead->next;
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
    int  Elem[N] = { 0, 10, 4, 2, 8, 6 };
    head = creatlist(Elem);
    printf("\nThe original list:\n");
    outlist(head);
    fun(head);
    printf("\nThe list after inverting :\n");
    outlist(head);
    getchar();
}