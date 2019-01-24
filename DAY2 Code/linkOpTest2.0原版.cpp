
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
	NODE* Create(NODE *head,int n); //����
	NODE* InsertNode(NODE *head,int idx);//����һ���ڵ�
	NODE* DeleteNode(NODE *head,int idx);//ɾ��һ���ڵ�
	void outputList(NODE *head); //��������е����� 
	NODE* Destroy(NODE *head); //���������ͷ��ڴ�
	int Search(NODE *head,int e); //��������e���ĸ�λ��
	NODE *head = NULL;
	head = Create(head,N);
	printf("��ǰ��������Ϊ:\n");
	outputList(head);
	printf("�����Ҫ���ҵ�ֵ:");
	scanf("%d",&e);
	searchResult = Search(head,e);
	if(searchResult)
		printf("%d�������еĵ�%d��λ��\n",e,searchResult);
	else
		printf("%d����������\n",e);

	printf("�����Ҫ�����λ��");
	scanf("%d",&idx);
	head = InsertNode(head,idx);
	printf("��%d��λ�ò���Ԫ��֮�����������Ϊ:\n",idx);
	outputList(head);
	printf("�����Ҫɾ��Ԫ�ص�λ��");
	scanf("%d",&idx);
	head = DeleteNode(head,idx);
	printf("ɾ����%��λ��Ԫ��֮�����������Ϊ:\n",idx);
	outputList(head);
	printf("�ͷ�����ռ�õ��ڴ�.....");
	head=Destroy(head);
	printf("�ڴ��ͷ���ϣ�\n");
	return 0;
}



NODE* Create(NODE *head,int n) //��������
{
	int i=0;
	NODE* newNode,*p;
	printf("���ڴ���һ������Ϊ%d������...\n",n);
	
	while(i<n)
	{
		newNode = (NODE*)malloc(sizeof(NODE));
		printf("�����һ������:");
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


NODE* InsertNode(NODE *head,int idx)//��idxλ�ò���һ���ڵ�
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
			if(p->next){ //����β��׷��,��Ϊ�ǲ��! ��idx<=��
			newNode->next = p->next;
			p->next = newNode;}
		}
	}
	return head;	
}

NODE* DeleteNode(NODE *head,int idx)//ɾ�������е�idxλ�õĽڵ�
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
		if(idx==1) //����1  ԭ����Ϊp==head����
		{
			q= p->next;
			free(p);
			head = q;			
		}
		else
		{
			q= p->next;
			if(q){	p->next = q->next;	free(q);} //����2,��֤idx<=��,��ֹq==NULL�������쳣
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


void outputList(NODE *head)//��������е�����
{
	NODE *p = head;
	while(p)
	{
		printf("%d\t",p->number);
		p=p->next;
	}
	printf("\n");
}

NODE* Destroy(NODE *head)//�ͷ�������ռ�õ��ڴ�
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
