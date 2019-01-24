
#include <stdio.h>
#include <stdlib.h>

#define N  5
typedef struct Node
{
	int number;
	struct Node *next;
}NODE;

int main()
{
	int e,idx,searchResult;
	NODE* Create(NODE *head,int n); //创建
	NODE* InsertNode(NODE *head,int idx);//插入一个节点
	NODE* DeleteNode(NODE *head,int idx);//删除一个节点
	void outputList(NODE *head); //输出链表中的数据 
	NODE* Destroy(NODE *head); //销毁链表并释放内存
	int Search(NODE *head,int e); //查找数据e在哪个位置
	NODE *head = NULL;
	head = Create(head,N);
	printf("当前链表数据为:\n");
	outputList(head);
	printf("请输出要查找的值:");
	scanf("%d",&e);
	searchResult = Search(head,e);
	if(searchResult)
		printf("%d在链表中的第%d个位置\n",e,searchResult);
	else
		printf("%d不在链表中\n",e);

	printf("请输出要插入的位置");
	scanf("%d",&idx);
	head = InsertNode(head,idx);
	printf("第%d个位置插入元素之后的链表数据为:\n",idx);
	outputList(head);
	printf("请输出要删除元素的位置");
	scanf("%d",&idx);
	head = DeleteNode(head,idx);
	printf("删除第%个位置元素之后的链表数据为:\n",idx);
	outputList(head);
	printf("释放链表占用的内存.....");
	head=Destroy(head);
	printf("内存释放完毕！\n");
	return 0;
}



NODE* Create(NODE *head,int n) //创建链表
{
	int i=0;
	NODE* newNode,*p;
	printf("正在创建一个长度为%d的链表...\n",n);
	
	while(i<n)
	{
		newNode = (NODE*)malloc(sizeof(NODE));
		printf("请输出一个整数:");
		scanf("%d",&newNode->number);
		newNode->next =NULL;

		if(!head)
			p=head = newNode;
		else
		{
			p->next = newNode;
			p = newNode;
		}
		i++;	
	}
	return head;
}


NODE* InsertNode(NODE *head,int idx)//在idx位置插入一个节点
{
	int i=1;
	NODE *p =head,*newNode;
    while(p && i<idx-1)
	{
		p=p->next;
		i++;
	}
	if(!p || i>idx)
	{
		printf("Invalid position!\n");
		return head;
	}
	else
	{
		newNode = (NODE*)malloc(sizeof(NODE));
		scanf("%d",&newNode->number);
		newNode->next = NULL;

		if(idx == 1)
		{
			newNode->next = head;
			head = newNode;			
		}
		else
		{
			if(p->next){ //不在尾部追加,因为是插队! 即idx<=表长
			newNode->next = p->next;
			p->next = newNode;}
		}
	}
	return head;	
}

NODE* DeleteNode(NODE *head,int idx)//删除链表中第idx位置的节点
{
	int i=1;
	NODE *p =head,*q;
	while(p && i<idx-1)
	{
		p=p->next;i++;
	}
	if(!p || i>idx)
	{
		printf("Invalid position!\n");
		return head;
	}
	else
	{		
		if(idx==1) //更正1  原代码为p==head有误
		{
			q= p->next;
			free(p);
			head = q;			
		}
		else
		{
			q= p->next;
			if(q){	p->next = q->next;	free(q);} //更正2,保证idx<=表长,防止q==NULL带来的异常
		}
	}
	return head;
}

int Search(NODE *head,int e)
{
	NODE *p =head;
	int j=1;
	while(p && p->number!=e)
	{
		p=p->next;
		j++;
	}
	if(!p)
		return 0;
	else
		return j;

}

NODE* Search2(NODE *head,int idx)
{
	int i=1;
	NODE *p =head,*q;
	while(p && i<idx)
	{
		p=p->next;i++;
	}

	return p;
}


void outputList(NODE *head)//输出链表中的数据
{
	NODE *p = head;
	while(p)
	{
		printf("%d\t",p->number);
		p=p->next;
	}
	printf("\n");
}

NODE* Destroy(NODE *head)//释放链表所占用的内存
{
	NODE *q = head,*p;
	while(q)
	{
		p=q->next;
		free(q);
		q=p;
	}
	return NULL;
}
