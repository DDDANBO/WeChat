/*-----------------------------------------------------------------
////////�ؼ����ִ�������ű��////////////
-------------------------------------------------------------------*/
#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
using namespace std;
/*-------------------------�ṹ�嶨�岿��------------------------------*/
struct Node       //(1)
{
    char name[10];
    int score;
    struct Node *next;
};

typedef struct Node ListNode;

/*-----------------------------��������---------------------------------*/
/*�������ĩ�˲����µĽڵ㣬��������*/
ListNode *CreateList(int n)
{
    ListNode *head;//ָ��ͷ���ָ�� //(2)
    ListNode *p,*pre;  //(3)
    int i;
    head=(ListNode *)malloc(sizeof(ListNode));//Ϊͷ�ڵ�����ڴ�ռ�  //(4)
    head->next=NULL;//��ͷ����ָ�������  //(5)
    pre=head;//�Ƚ�ͷ����׵�ַ�����м����pre  //(6)
    for(i=1;i<=n;i++)//ͨ��forѭ�����ϼ����µĽ��
    {
        printf("input name of the %d student: ",i);//��ӡ���ڼ����˵�����
        p=(ListNode *)malloc(sizeof(ListNode));//ΪҪ����Ľڵ����  //(7)
        //�ڴ�ռ�pָ���²�������׵�ַ
        scanf("%s",&p->name);//��������  //(8)
        printf("input score of the %d student: ",i);
        scanf("%d",&p->score);//�������  //(9)
        pre->next=p;//��pָ���½���������Ҳ����ͷ���ָ����ָ��  //(10)
        //�¸����
        //��һ��������pָ��ģ���Ϊͷ�������Ϊ��
        pre=p;//�������ָ����һ����������  //(11)
    }
    p->next=NULL;//������һ������ָ���������
    return head;//�������������׵�ַ
}

/*-------------------------�������-----------------------------------*/
void PrintList(ListNode *h)
{
    ListNode *p; //(1)
    p=h->next;  //(2)
    while(p)//!!!!
    {
        printf("%s,%d",p->name,p->score);  //(3)
        p=p->next;  //(4)
        printf("\n");
    }
}
/*----------------------����������--------------------------*/
/*-----------------------------------------------------------------
��������:InsertList(ListNode *h,int i,char name[],int e,int n)
��������:����������
��ڲ���: h: ͷ����ַ i:���뵽�ڼ������
name:����������� e:������ķ���
n:�����н��ĸ���
����ͷ�����ĸ���
------------------------------------------------------------------*/
void InsertList(ListNode *h,int i,char name[],int e,int n)
{
    ListNode *q,*p;//�ȶ���2��ָ��һ������ָ��
    int j;
    if(i<1 || i>n+1)
        printf("Error! Please input again.\n");
    else
    {
        j=0;
        p=h;//��ָ��pָ��Ҫ�����ͷ���
        while(j<i-1) //(1)�����ҵ�����ڵ��ǰһλ�ã�����
        {
            p=p->next;//һֱ���ң���������
            j++;
        }
        q=(ListNode *)malloc(sizeof(ListNode));/*ΪҪ�����
        �������ڴ�ռ�*/  //(2)

        //----��ֵ����---------
        strcpy(q->name,name); //�����ֿ���Ҫ����Ľڵ���  //(3)
        q->score=e; //��Ҫ����Ľڵ��з�����ֵ  //(4)

        //����ָ���򣡣�����
        q->next = p->next; /*����ǽ��²���Ľ��ָ����ָ��
        ��һ�����ָ����ָ��Ľ���ַ��Ϊp->next*/ //(5)�ؼ�����������

        p->next=q;/*��Ҫ������λ��ǰ��Ľ��ָ����
        ָ�����ڲ���Ľ���׵�ַ*/ //(6)�ؼ�����������
  }
}
/*----------------------����������--------------------------*/
int LengthList(ListNode *h)
{
    int n=0;
    ListNode *p;
    p=h->next;
    while(p)
    {
        p=p->next;
        n++;
    }
    return n;
}
/*----------------------������������С��������------------------------*/
ListNode *BubbleSortList(ListNode *head)
{//ð������
    if(head == NULL) return NULL;
    ListNode *p, *q;
    int temp_score;////����score��ʱ����
    char temp_name[10];////����name��ʱ����
    for(p = head->next; p != NULL; p = p->next)//!!!!!
    {
        for(q = p->next; q != NULL; q = q->next)//!!!!!
        {
            if(p->score > q->score)
            {
                temp_score = q->score;//����score!!!
                q->score = p->score;
                p->score =temp_score;

                strcpy(temp_name,q->name);//����name!!!
                strcpy(q->name,p->name);
                strcpy(p->name,temp_name);
            }
        }
    }
    return head;
}

/*--------------------------------------------------------------------
��������:DeleteList(ListNode *h, int i, int n)
��������:ɾ��������
��ڲ���: h: ͷ����ַ i:Ҫɾ���Ľ������λ��
n:�����н��ĸ�������ͷ�����ĸ���
--------------------------------------------------------------------*/
void DeleteList(ListNode *h, int i, int n)
{
    ListNode *p,*q;//���ȶ���2��ָ�����ͽṹ���ָ��
    int j;
    char name[10];
    int score;
    if(i<1 || i>n)//���λ�ó�����1��n�ķ�Χ�Ļ����ӡ��������Ϣ
        printf("Error! Please input again.\n");
    else//û�г�����ͷ������1��n �ķ�Χ�Ļ���ôִ��ɾ������
    {
        j=0;
        p=h;//��ָ��ָ�������ͷ����׵�ַ
        while(j<i-1)  //(1)�����ҵ�ɾ���ڵ��ǰһλ��p������
        {
            p=p->next;
            j++;
        }
        q=p->next; /*qָ��Ҫɾ���Ľ��*/ //(2)�ؼ�����������

        p->next=q->next;/*����ָ����*/ //(3)�ؼ�����������

        strcpy(name,q->name);
        score=q->score;

        free(q);//�ͷ�qָ��Ľ��
        printf("name=%s,score=%d\n",name,score);
    }
}

/*--------------------------������-------------------------------*/
int main()
{
    ListNode *h;//hָ��ṹ��NODE
    int i = 1, n, score;
    char name[10];

    while (i)
    {
        /*������ʾ��Ϣ*/
        cout<<"--------------ѡ��˵�-------------"<<endl;
        printf("1--�����µ�����\n");
        printf("2--���Ԫ��\n");
        printf("3--ɾ��Ԫ��\n");
        printf("4--����ⳤ\n");
        printf("5--�����ǰ���е�Ԫ��\n");
        printf("6--����ð������\n");
        printf("0--�˳�\n");
        cout<<"--------------ѡ��˵�-------------"<<endl;
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                printf("input list length n : ");   /*���봴��������ĸ���*/
                scanf("%d",&n);
                h=CreateList(n);/*��������*/
                //printf("list elements is : \n");
                //PrintList(h);
                break;
            case 2:
                printf("input the position of insert element : ");
                scanf("%d",&i);
                printf("input name of the student : ");
                scanf("%s",name);
                printf("input score of the student : ");
                scanf("%d",&score);
                InsertList(h,i,name,score,n);
                //printf("list elements is:\n");
                //PrintList(h);
                break;
            case 3:
                printf("input the position of delete element : ");
                scanf("%d",&i);
                DeleteList(h,i,n);
                //printf("list elements is : \n");
                //PrintList(h);
                break;
            case 4:
                cout<<"list length is : ";
                cout<<LengthList(h)<<endl;
                break;
            case 5:
                printf("list element is : \n");
                PrintList(h);
                break;
            case 6:
                cout<<"after bubble_sort : "<<endl;
                BubbleSortList(h);
                PrintList(h);
                break;
            case 0:
                break;
            default:
                printf("ERROR!Try again!\n");
        }
    }
    return 0;
}

