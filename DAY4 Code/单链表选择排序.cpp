#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
 
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList; /* ����LinkList */
 
Status visit(ElemType c)
{
    printf("->%d",c);
    return OK;
}
 
/* ��ʼ��˳�����Ա� */
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if(!(*L)) /* �洢����ʧ�� */
        return ERROR;
    (*L)->next=NULL; /* ָ����Ϊ�� */
 
    return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* pָ���һ����� */
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
 
/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
    LinkList p,r;
    int i;
    srand(time(0));                      /* ��ʼ����������� */
    *L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
    r=*L;                                /* rΪָ��β���Ľ�� */
    for (i=0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
        p->data = rand()%100+1;           /*  �������100���ڵ����� */
        r->next=p;                        /* ����β�ն˽���ָ��ָ���½�� */
        r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
    }
    r->next = NULL;                       /* ��ʾ��ǰ������� */
}
 
LinkList SelectSort2(LinkList L)
{
    LinkList p,q,small;
    int temp;
 
    for(p = L->next; p->next != NULL; p = p->next)
    {
        small = p;
        for(q = p->next; q; q = q->next)
        {
            if(q->data < small->data)
            {
                small = q;
            }
        }
        printf("ѭ���󣬻����СֵΪ:%d, ��ʱ����Ϊ:", small->data);
        if(small != p)
        {
            temp = p->data;
            p->data = small->data;
            small->data = temp;
        }
        ListTraverse(L);
    }
    printf("�������������:\n");
    return L;
}
 
LinkList SelectSort(LinkList L)
{
    LinkList first;     /*���к��������ı�ͷָ��*/
    LinkList tail;      /*���к��������ı�βָ��*/
    LinkList p_min;     /*������ֵ��С�Ľڵ��ǰ���ڵ��ָ��*/
    LinkList min;       /*�洢��С�ڵ�*/
    LinkList p;         /*��ǰ�ȽϵĽڵ�*/
 
    first = NULL;
    while (L != NULL) /*���������Ҽ�ֵ��С�Ľڵ㡣*/
    {
        /*ע�⣺����for����������ѡ������˼��ĵط�*/
        for (p=L,min=L; p->next!=NULL; p=p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/
        {
            if (p->next->data < min->data) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/
            {
                p_min = p; /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/
                min = p->next; /*�����ֵ��С�Ľڵ㡣*/
            }
        }
 
        /*����for�������󣬾�Ҫ�������£�
            һ�ǰ����������������У�
            ���Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/
 
        /*��һ����*/
        if (first == NULL) /*�����������Ŀǰ����һ��������*/
        {
            first = min; /*��һ���ҵ���ֵ��С�Ľڵ㡣*/
            tail = min; /*ע�⣺βָ������ָ������һ���ڵ㡣*/
        }
        else /*�����������Ѿ��нڵ�*/
        {
            tail->next = min; /*�Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/
            tail = min; /*βָ��ҲҪָ������*/
        }
        /*�ڶ�����*/
        if (min == L) /*����ҵ�����С�ڵ���ǵ�һ���ڵ�*/
        {
            //printf("��ͷ%d�Ѿ�����С����ǰ�����ơ�\n", min->data);
            L = L->next; /*��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK*/
        }
        else /*������ǵ�һ���ڵ�*/
        {
            p_min->next = min->next; /*ǰ����С�ڵ��nextָ��ǰmin��next,��������min�뿪��ԭ����*/
        }
    }
    if (first != NULL) /*ѭ�������õ���������first*/
    {
        tail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL*/
    }
    L = first;
    return L;
}
 
int main()
{
    LinkList L;
    Status i;
    char opp;
    ElemType e;
    int find;
    int tmp;
 
    i=InitList(&L);
    printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
 
    printf("\n1.�鿴���� \n2.��������β�巨�� \n3.������ \n4.����������� \n0.�˳� \n��ѡ����Ĳ�����\n");
    while(opp != '0')
    {
        scanf("%c",&opp);
        switch(opp)
        {
        case '1':
            ListTraverse(L);
            printf("\n");
            break;
 
        case '2':
            CreateListTail(&L,10);
            printf("���崴��L��Ԫ��(β�巨)��\n");
            ListTraverse(L);
            printf("\n");
            break;
 
        case '3':
            //clearList(pHead);   //�������
            printf("ListLength(L)=%d \n",ListLength(L));
            printf("\n");
            break;
 
        case '4':
            L = SelectSort2(L);
            //printf("%d \n", find);
            ListTraverse(L);
            printf("\n");
            break;
 
        case '0':
            exit(0);
        }
    }
}

