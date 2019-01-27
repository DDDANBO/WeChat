//���Ա�ĵ�����洢�ṹ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
	int number;
	struct Node *next;
} NODE;

NODE* Create(NODE *head); //��������(β�巨)
NODE* InsertNode(NODE *head,int idx);//����һ���ڵ�
void ModifyRecordByIndex(NODE *head);//�޸�ָ��λ�õ�����
NODE* DeleteNode(NODE *head,int idx);//ɾ��һ���ڵ�
void outputList(NODE *head); //��������е�����
void SortList(NODE * head); //��������
NODE* Destroy(NODE *head); //���������ͷ��ڴ�
int SearchLocation(NODE *head,int e); //��������e���ĸ�λ��
NODE* SearchData(NODE *head,int idx); //����ָ��λ�õ�����
void printfHelp();//��������˵�
void SaveRecordsToFile(NODE * head,FILE * fp);//�����ݱ��浽�����ļ���
NODE* EntryRecordsByFile(NODE * head);//�ļ��ж�������
NODE* FileToList(NODE * head,FILE * fp); //���ļ������ݶ��뵽������

int main()
{
	int e,idx,searchResult,loop = 1,choice; //loop����������������ѭ�� 
	NODE * head = NULL,* judge = NULL;
	FILE * fp; //FILEΪ�ļ�ָ�� 
	printfHelp();
	while (loop) //������ѭ������loop��ֵΪ0ʱ���˳�ѭ�� 
	{
		printf ("\n������һ��ѡ��[0-12]:");
		scanf ("%d",&choice);
		getchar();  //getchar()�������ջ��з�����ͬ
		switch(choice)
		{
			case 0:
			{
				head = Create(head);
				printf("\n��ǰ��������Ϊ:\n");
				outputList(head);
			}
			break;
			case 1:
			{
				printf("\n�����Ҫ�����λ��:");
				scanf ("%d",&idx);
				getchar();
				judge = InsertNode(head,idx);
				//�������в��ܺϲ��������while����У�
				//��Ϊ���ٴν��в������ʱ��Ҫ�ȶ�judge��ֵ��
				//����judge�ᱣ���ϴεġ���ֵ������ֱ������case1
				while (!judge) //��judgeΪ��ָ��ʱ����whileѭ������ͬ 
				{
					scanf ("%d",&idx);
					getchar();
					judge = InsertNode(head,idx);
				}
			}
			break;
			case 2:
			{
				ModifyRecordByIndex(head);
				printf ("\n���������£�\n");
				outputList(head);
			}
			break;
			case 3:
			{
				printf ("\n������Ҫ�������ݵ�λ��:");
				scanf ("%d",&idx);
				judge = SearchData(head,idx);
				while (!judge)
				{
					printf ("\n����λ����������������:");
					scanf ("%d",&idx);
					judge = SearchData(head,idx);
				}
				if (judge)
					printf ("\n��%d��λ���ϵ�����Ϊ%d\n",idx,judge->number);

			}
			break;
			case 4:
			{
				printf ("\n������Ҫ���ҵ�����e��");
				scanf ("%d",&e);
				searchResult = SearchLocation(head,e);
				if(searchResult)
					printf("\n%d�������еĵ�%d��λ��\n",e,searchResult);
				else
					printf("\n%d����������\n",e);
			}
			break;
			case 5:
			{
				printf ("\n������Ҫɾ������λ�ã�");
				scanf ("%d",&idx);
				getchar();
				judge = DeleteNode(head,idx);
				while (!judge)
				{
					scanf ("%d",&idx);
					getchar();
					judge = DeleteNode(head,idx);
				}
				if (judge)
				{
					printf ("\n%dλ���ϵĽ����ɾ��\n",idx);
				}

			}
			break;
			case 6:
			{
				head = Destroy(head);
				if (!head)
					printf ("\n���������\n");
			}
			break;
			case 7:
			{
				printf ("\n�����������£�\n");
				outputList(head);
			}
			break;
			case 8:
			{
				printf ("\n�������������£�\n");
				SortList(head);
				outputList(head);
			}
			break;
			case 9:
			{
				printfHelp();
			}
			break;
			case 10:
			{
				fp = fopen("LinkList.txt","w"); //����ΪLinkList��txt�ļ�������ֻд���� 
				SaveRecordsToFile(head,fp); //���������е����ݵ�fp��ָ����ļ��� 
				printf ("\n�������ݳɹ����浽��ǰ�ļ�%s��\n","LinkList.txt");
				fclose(fp); //�ر�fp��ָ����ļ� 
			}
			break;
			case 11:
			{
				head = EntryRecordsByFile(head); //���ļ��ж������ݵ������� 
				outputList(head);
			}
			break;
			case 12:
			{
				printf ("\n�˳�����\n");
				loop = 0; //��0��ֵ��loop�������������� 
			}
			break;
		}
	}
	return 0;
}

void printfHelp()//��������˵�
{
	printf ("************ʹ�ð���************\n");
	printf ("[0]�����ʼ��\n");
	printf ("[1]����һ�����\n");
	printf ("[2]��λ���޸�һ�����\n");
	printf ("[3]����ָ��λ�õ�����\n");
	printf ("[4]��������e��λ��\n");
	printf ("[5]��λ��ɾ��һ���ڵ�\n");
	printf ("[6]���������ͷ��ڴ�\n");
	printf ("[7]��������е�����\n");
	printf ("[8]��������\n");
	printf ("[9]��������˵�\n");
	printf ("[10]���浽�ļ�\n");
	printf ("[11]���ļ��ж�������\n");
	printf ("[12]�˳�����\n");
	printf ("********************************\n");
}

NODE* Create(NODE *head) //��������
{
	int i=0,n,min,max;
	char ch;
	NODE* newNode,*p;
	printf ("\nѡ��A��a�����ֶ�����������ѡ��B��b���������������\n");
	ch = getchar();
	if (ch == 'A' || ch == 'a') //�ֶ��������� 
	{
		printf("\n����Ҫ����������ĳ��ȣ�");
		scanf ("%d",&n);
		while(i<n)
		{
			newNode = (NODE*)malloc(sizeof(NODE));
			newNode->next =NULL;
			printf("�����һ������:");
			scanf("%d",&newNode->number);

			if(!head) //���headΪ��ָ�룬ִ��if��䣬��ͬ 
				p = head = newNode;
			else
			{
				p->next = newNode;
				p = newNode;
			}
			i++;
		}
	}
	else //����������� 
	{
		printf("\n����Ҫ����������ĳ��ȣ�");
		scanf ("%d",&n);
		printf ("\n������������ķ�Χ[min max]\n");
		scanf ("%d%d",&min,&max);
		srand((int) time(0)); //ÿ��ִ�����Ӳ�ͬ�����ɲ�ͬ�������
		while(i<n)
		{
			newNode = (NODE*)malloc(sizeof(NODE));
			newNode->next =NULL;
			newNode->number = (rand() % (max - min + 1) + min);
			//rand()�������ص���һ��0��RAND_MAX�������,
			//RAND_MAX ����һ��������rand()����ȡֵ��Χ��0-32767
			if(!head)
				p = head = newNode;
			else
			{
				p->next = newNode;
				p = newNode;
			}
			i++;
		}
	}
	return head;
}

NODE* InsertNode(NODE *head,int idx)//��idxλ�ò���һ���ڵ�
{
	int i=1;
	NODE *p =head,*q,*newNode;//p�ǿ�ָ�룬ָ��ǰָ��λ�ã�q����ָ�룬ָ��p��ǰһλ��
	while(p && i<idx) //����������ͬ 
	{
		q = p;
		p = p->next;
		i++;
	}
	if(!p || i>idx) //!p�����ж��Ƿ����볬��������,i>idx�����ж��Ƿ����������
	{
		printf ("\n����λ����������������:");
		return NULL;
	}
	else
	{
		newNode = (NODE*)malloc(sizeof(NODE));
		newNode->next = NULL;
		printf ("\n������Ҫ��������ݣ�");
		scanf("%d",&newNode->number);
		getchar();
		if(idx == 1) //���Ҫ�����λ��Ϊ��һ�����ʱ��ִ��if��� 
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			newNode->next = p;
			q->next = newNode;
		}
	}
	printf("\n��%d��λ�ò���Ԫ��֮�����������Ϊ:\n",idx);
	outputList(head);
	return head;
}

void ModifyRecordByIndex(NODE *head)
{
	NODE *p =head;
	int i,k;
	printf ("\n������Ҫ�޸ĵ�λ�ã�");
	scanf ("%d",&i);
	getchar();
	p = SearchData(head,i);
	while (!p) //���pΪ��ָ�룬ִ��while��� 
	{
		printf ("\n����λ����������������:");
		scanf ("%d",&i);
		getchar();
		p = SearchData(head,i);
	}
	if (p)
	{
		printf ("\n�����������ݣ�");
		scanf ("%d",&k);
		p->number = k;
	}
}


NODE* DeleteNode(NODE *head,int idx)//ɾ�������е�idxλ�õĽڵ�
{
	int i=1;
	NODE *p = head,*q; //p�ǿ�ָ�룬ָ��ǰָ��λ�ã�q����ָ�룬ָ��p��ǰһλ��
	while(p && i<idx)
	{
		q = p;
		p = p->next;
		i++;
	}
	if(!p || i>idx) //!p�����ж��Ƿ����볬��������,i>idx�����ж��Ƿ����������
	{
		printf ("\n����λ����������������:");
		return NULL;
	}
	else
	{
		if(p == head)
		{
			q = p->next;
			free(p); //free�����ͷ�p��� 
			head = q;
		}
		else
		{
			q->next = p->next;
			free(p);
		}
		outputList(head);
	}
	return head;
}

int SearchLocation(NODE *head,int e) //��������e���ĸ�λ��
{
	NODE *p =head;
	int j=1;
	while(p && p->number!=e)
	{
		p = p->next;
		j++;
	}
	if(!p)
		return 0;
	else
		return j;

}

NODE* SearchData(NODE *head,int idx) //����ָ��λ�õ�����
{
	int i=1;
	NODE *p =head,*q; //p�ǿ�ָ�룬ָ��ǰָ��λ�ã�q����ָ�룬ָ��p��ǰһλ��
	while(p && i<idx)
	{
		q = p;
		p = p->next;
		i++;
	}
	if (!p || i>idx) //!p�����ж��Ƿ����볬��������,i>idx�����ж��Ƿ����������
		return NULL;
	else
		return p;
}

void SortList(NODE * head) //�����ð�����򽻻��� 
{
	NODE * p,*q;//p�ǿ�ָ�룬q����ָ��
	int temp;
	for (q = head; q->next != NULL; q = q->next)
	{
		for (p = q->next; p != NULL; p = p->next)
		{
			if(q->number > p->number) 
			{
				temp = q->number; //����p��qָ���е������� 
				q->number = p->number;
				p->number = temp;
			}
		}
	}
}


void outputList(NODE *head)//��������е�����
{
	NODE *p = head;
	if (!p)
		printf ("����Ϊ�գ�");
	while(p)
	{
		printf("%d\t",p->number);
		p=p->next;
	}
	printf("\n");
}

void SaveRecordsToFile(NODE * head,FILE * fp)//�����ݱ��浽�����ļ���
{
	NODE * p = head;
	while(p)
	{
		fprintf(fp,"%5d",p->number); 
		//��fprintf������p->number�е�ֵ�ԡ�%5d���ĸ�ʽ�����fp��ָ����ļ��� 
		p = p->next;
	}
}

NODE* EntryRecordsByFile(NODE * head)//�ļ��ж�������
{
	NODE * newNode,* p = NULL,* list;//listΪ�ļ��ж����������
	char filename[] = "LinkList.txt";
	FILE * fp;
	printf ("\n�������ļ�%s�������ݣ���ȷ�����ļ����ڲ����ݷǿ�!\n","LinkList.txt");
	if((fp = fopen(filename,"r")) == NULL) //�ж��Ƿ��ܴ�fp��ָ����ļ� 
	{
		printf ("�����ļ�����ʧ��!");
		exit(0); //exit������ʹ������ֹ 
	}
	else
	{
		printf ("\n�ɹ��ӵ�ǰ�ļ��ж�ȡ�����ݣ��������£�\n");
		while(fgetc(fp) != EOF) //��δ���ļ�����������һֱȡ����  //while�п��滻Ϊ!feof(fp)
		{
			newNode = (NODE* )malloc(sizeof(NODE));
			newNode->next =NULL;
			fscanf(fp,"%5d",&newNode->number); 
			//��fscanf������fpָ�����ļ��а���%5d���ĸ�ʽ�����������͵�
			//&newNode->number��ָ����ڴ浥Ԫ 
			if(p == NULL) //��ͷ
			{
				list = p = newNode;
			}
			else
			{
				p->next = newNode;
				p = newNode;
			}
		}
		fclose(fp);
	}
	return list;
}

NODE* Destroy(NODE *head)//�ͷ�������ռ�õ��ڴ�
{
	NODE *q = head,*p; //p�ǿ�ָ�룬ָ����һλ�ã�q����ָ�룬ָ��ǰλ��
	while(q)
	{
		p = q->next;
		free(q); //�ͷ�q�ڴ� 
		q = p;
	}
	return NULL;
}
