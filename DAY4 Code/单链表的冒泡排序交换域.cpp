/*-----------------------------------------------------------------
////////关键部分代码用序号标出////////////
-------------------------------------------------------------------*/
#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
using namespace std;
/*-------------------------结构体定义部分------------------------------*/
struct Node       //(1)
{
    char name[10];
    int score;
    struct Node *next;
};

typedef struct Node ListNode;

/*-----------------------------创建链表---------------------------------*/
/*在链表的末端插入新的节点，建立链表*/
ListNode *CreateList(int n)
{
    ListNode *head;//指向头结点指针 //(2)
    ListNode *p,*pre;  //(3)
    int i;
    head=(ListNode *)malloc(sizeof(ListNode));//为头节点分配内存空间  //(4)
    head->next=NULL;//将头结点的指针域清空  //(5)
    pre=head;//先将头结点首地址赋给中间变量pre  //(6)
    for(i=1;i<=n;i++)//通过for循环不断加入新的结点
    {
        printf("input name of the %d student: ",i);//打印出第几个人的名字
        p=(ListNode *)malloc(sizeof(ListNode));//为要插入的节点分配  //(7)
        //内存空间p指向新插入结点的首地址
        scanf("%s",&p->name);//输入姓名  //(8)
        printf("input score of the %d student: ",i);
        scanf("%d",&p->score);//输入分数  //(9)
        pre->next=p;//将p指向新结点插入链表也就是头结点指针域指向  //(10)
        //下个结点
        //第一个结点就是p指向的，因为头结点内容为空
        pre=p;//这个起着指向下一个结点的作用  //(11)
    }
    p->next=NULL;//最后将最后一个结点的指针域清空了
    return head;//返回这个链表的首地址
}

/*-------------------------输出链表-----------------------------------*/
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
/*----------------------插入链表结点--------------------------*/
/*-----------------------------------------------------------------
函数名称:InsertList(ListNode *h,int i,char name[],int e,int n)
函数功能:插入链表结点
入口参数: h: 头结点地址 i:插入到第几个结点
name:插入结点的姓名 e:插入结点的分数
n:链表中结点的个数
除下头结点外的个数
------------------------------------------------------------------*/
void InsertList(ListNode *h,int i,char name[],int e,int n)
{
    ListNode *q,*p;//先定义2个指向一个结点的指针
    int j;
    if(i<1 || i>n+1)
        printf("Error! Please input again.\n");
    else
    {
        j=0;
        p=h;//将指针p指向要链表的头结点
        while(j<i-1) //(1)遍历找到插入节点的前一位置！！！
        {
            p=p->next;//一直查找！！！！！
            j++;
        }
        q=(ListNode *)malloc(sizeof(ListNode));/*为要插入的
        结点分配内存空间*/  //(2)

        //----赋值操作---------
        strcpy(q->name,name); //将名字拷到要插入的节点内  //(3)
        q->score=e; //将要插入的节点中分数赋值  //(4)

        //调整指针域！！！！
        q->next = p->next; /*这个是将新插入的结点指针域指向
        上一个结点指针域指向的结点地址即为p->next*/ //(5)关键！！！！！

        p->next=q;/*将要插入结点位置前面的结点指针域
        指向现在插入的结点首地址*/ //(6)关键！！！！！
  }
}
/*----------------------返回链表长度--------------------------*/
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
/*----------------------按链表数据由小到大排序------------------------*/
ListNode *BubbleSortList(ListNode *head)
{//冒泡排序
    if(head == NULL) return NULL;
    ListNode *p, *q;
    int temp_score;////交换score临时变量
    char temp_name[10];////交换name临时变量
    for(p = head->next; p != NULL; p = p->next)//!!!!!
    {
        for(q = p->next; q != NULL; q = q->next)//!!!!!
        {
            if(p->score > q->score)
            {
                temp_score = q->score;//交换score!!!
                q->score = p->score;
                p->score =temp_score;

                strcpy(temp_name,q->name);//交换name!!!
                strcpy(q->name,p->name);
                strcpy(p->name,temp_name);
            }
        }
    }
    return head;
}

/*--------------------------------------------------------------------
函数名称:DeleteList(ListNode *h, int i, int n)
函数功能:删除链表结点
入口参数: h: 头结点地址 i:要删除的结点所在位置
n:链表中结点的个数除下头结点外的个数
--------------------------------------------------------------------*/
void DeleteList(ListNode *h, int i, int n)
{
    ListNode *p,*q;//首先定义2个指向结点型结构体的指针
    int j;
    char name[10];
    int score;
    if(i<1 || i>n)//如果位置超出了1和n的范围的话则打印出错误信息
        printf("Error! Please input again.\n");
    else//没有超出除头结点外的1到n 的范围的话那么执行删除操作
    {
        j=0;
        p=h;//将指针指向链表的头结点首地址
        while(j<i-1)  //(1)遍历找到删除节点的前一位置p！！！
        {
            p=p->next;
            j++;
        }
        q=p->next; /*q指向要删除的结点*/ //(2)关键！！！！！

        p->next=q->next;/*调整指针域*/ //(3)关键！！！！！

        strcpy(name,q->name);
        score=q->score;

        free(q);//释放q指向的结点
        printf("name=%s,score=%d\n",name,score);
    }
}

/*--------------------------主函数-------------------------------*/
int main()
{
    ListNode *h;//h指向结构体NODE
    int i = 1, n, score;
    char name[10];

    while (i)
    {
        /*输入提示信息*/
        cout<<"--------------选择菜单-------------"<<endl;
        printf("1--建立新的链表\n");
        printf("2--添加元素\n");
        printf("3--删除元素\n");
        printf("4--链表测长\n");
        printf("5--输出当前表中的元素\n");
        printf("6--链表冒泡排序\n");
        printf("0--退出\n");
        cout<<"--------------选择菜单-------------"<<endl;
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                printf("input list length n : ");   /*输入创建链表结点的个数*/
                scanf("%d",&n);
                h=CreateList(n);/*创建链表*/
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

