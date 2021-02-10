#include  <stdio.h>
#include  <stdlib.h>
#define    N    5
typedef struct node {
    int  data;
    struct node* next;
} RevList;

void fun(RevList* phead)
{
    RevList* curhead, * cur, * lead;
    curhead = phead->next; // ͷ���
    if (curhead == NULL)
        exit(-1);
    cur = curhead->next; // ��ǰҪ�ƶ��Ľ��
    curhead->next = NULL;  // ��ǰͷ�����Ϊβ���
    while (cur) // ѭ���ƶ�
    {
        lead = cur->next; // Ҫ�ƶ��Ľ����һ������lead
        cur->next = curhead; // ��ǰ�ƶ����ָ��ǰͷ���
        curhead = cur;  // �ƶ��Ľ����Ϊͷ���
        cur = lead; // �ƶ�дһ��
    }
    phead->next = curhead;
}
RevList* creatlist(int  Elem[])
{
    RevList* Head, * cur, * newnode;        int  i;
    Head = (RevList*)malloc(sizeof(RevList)); // ͷ���
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
            cur->next = newnode; // �Խ����в���
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
    int  Elem[N] = { 2,4,6,8,10 };
    head = creatlist(Elem);
    printf("\nThe original list:\n");
    outlist(head);
    fun(head);
    printf("\nThe list after inverting :\n");
    outlist(head);
    getchar();
}
