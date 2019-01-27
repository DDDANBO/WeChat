//线性表的单链表存储结构
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
	int number;
	struct Node *next;
} NODE;

NODE* Create(NODE *head); //创建链表(尾插法)
NODE* InsertNode(NODE *head,int idx);//插入一个节点
void ModifyRecordByIndex(NODE *head);//修改指定位置的数据
NODE* DeleteNode(NODE *head,int idx);//删除一个节点
void outputList(NODE *head); //输出链表中的数据
void SortList(NODE * head); //链表排序
NODE* Destroy(NODE *head); //销毁链表并释放内存
int SearchLocation(NODE *head,int e); //查找数据e在哪个位置
NODE* SearchData(NODE *head,int idx); //查找指定位置的数据
void printfHelp();//输出帮助菜单
void SaveRecordsToFile(NODE * head,FILE * fp);//将数据保存到本地文件中
NODE* EntryRecordsByFile(NODE * head);//文件中读入数据
NODE* FileToList(NODE * head,FILE * fp); //将文件的数据读入到链表中

int main()
{
	int e,idx,searchResult,loop = 1,choice; //loop用来控制整个程序循环 
	NODE * head = NULL,* judge = NULL;
	FILE * fp; //FILE为文件指针 
	printfHelp();
	while (loop) //进入死循环，当loop赋值为0时才退出循环 
	{
		printf ("\n请输入一个选项[0-12]:");
		scanf ("%d",&choice);
		getchar();  //getchar()用来吸收换行符，下同
		switch(choice)
		{
			case 0:
			{
				head = Create(head);
				printf("\n当前链表数据为:\n");
				outputList(head);
			}
			break;
			case 1:
			{
				printf("\n请输出要插入的位置:");
				scanf ("%d",&idx);
				getchar();
				judge = InsertNode(head,idx);
				//以上三行不能合并到下面的while语句中，
				//因为当再次进行插入操作时需要先对judge赋值，
				//否则judge会保留上次的“真值”导致直接跳出case1
				while (!judge) //当judge为空指针时进入while循环，下同 
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
				printf ("\n新数据如下：\n");
				outputList(head);
			}
			break;
			case 3:
			{
				printf ("\n请输入要查找数据的位置:");
				scanf ("%d",&idx);
				judge = SearchData(head,idx);
				while (!judge)
				{
					printf ("\n输入位置有误，请重新输入:");
					scanf ("%d",&idx);
					judge = SearchData(head,idx);
				}
				if (judge)
					printf ("\n第%d个位置上的数据为%d\n",idx,judge->number);

			}
			break;
			case 4:
			{
				printf ("\n请输入要查找的数据e：");
				scanf ("%d",&e);
				searchResult = SearchLocation(head,e);
				if(searchResult)
					printf("\n%d在链表中的第%d个位置\n",e,searchResult);
				else
					printf("\n%d不在链表中\n",e);
			}
			break;
			case 5:
			{
				printf ("\n请输入要删除结点的位置：");
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
					printf ("\n%d位置上的结点已删除\n",idx);
				}

			}
			break;
			case 6:
			{
				head = Destroy(head);
				if (!head)
					printf ("\n链表已清空\n");
			}
			break;
			case 7:
			{
				printf ("\n链表数据如下：\n");
				outputList(head);
			}
			break;
			case 8:
			{
				printf ("\n链表排序结果如下：\n");
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
				fp = fopen("LinkList.txt","w"); //打开名为LinkList的txt文件，进行只写操作 
				SaveRecordsToFile(head,fp); //保存链表中的数据到fp所指向的文件中 
				printf ("\n链表数据成功保存到当前文件%s中\n","LinkList.txt");
				fclose(fp); //关闭fp所指向的文件 
			}
			break;
			case 11:
			{
				head = EntryRecordsByFile(head); //从文件中读入数据到链表中 
				outputList(head);
			}
			break;
			case 12:
			{
				printf ("\n退出程序！\n");
				loop = 0; //将0赋值给loop，结束整个程序 
			}
			break;
		}
	}
	return 0;
}

void printfHelp()//输出帮助菜单
{
	printf ("************使用帮助************\n");
	printf ("[0]链表初始化\n");
	printf ("[1]插入一个结点\n");
	printf ("[2]按位置修改一个结点\n");
	printf ("[3]查找指定位置的数据\n");
	printf ("[4]查找数据e的位置\n");
	printf ("[5]按位置删除一个节点\n");
	printf ("[6]销毁链表并释放内存\n");
	printf ("[7]输出链表中的数据\n");
	printf ("[8]链表排序\n");
	printf ("[9]输出帮助菜单\n");
	printf ("[10]保存到文件\n");
	printf ("[11]从文件中读入数据\n");
	printf ("[12]退出程序\n");
	printf ("********************************\n");
}

NODE* Create(NODE *head) //创建链表
{
	int i=0,n,min,max;
	char ch;
	NODE* newNode,*p;
	printf ("\n选择A或a进行手动输入整数，选择B或b进行随机生成整数\n");
	ch = getchar();
	if (ch == 'A' || ch == 'a') //手动输入整数 
	{
		printf("\n输入要创建的链表的长度：");
		scanf ("%d",&n);
		while(i<n)
		{
			newNode = (NODE*)malloc(sizeof(NODE));
			newNode->next =NULL;
			printf("请输出一个整数:");
			scanf("%d",&newNode->number);

			if(!head) //如果head为空指针，执行if语句，下同 
				p = head = newNode;
			else
			{
				p->next = newNode;
				p = newNode;
			}
			i++;
		}
	}
	else //随机生成整数 
	{
		printf("\n输入要创建的链表的长度：");
		scanf ("%d",&n);
		printf ("\n请输入随机数的范围[min max]\n");
		scanf ("%d%d",&min,&max);
		srand((int) time(0)); //每次执行种子不同，生成不同的随机数
		while(i<n)
		{
			newNode = (NODE*)malloc(sizeof(NODE));
			newNode->next =NULL;
			newNode->number = (rand() % (max - min + 1) + min);
			//rand()函数返回的是一个0到RAND_MAX的随机数,
			//RAND_MAX 这是一个常数，rand()函数取值范围在0-32767
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

NODE* InsertNode(NODE *head,int idx)//在idx位置插入一个节点
{
	int i=1;
	NODE *p =head,*q,*newNode;//p是快指针，指向当前指定位置，q是慢指针，指向p的前一位置
	while(p && i<idx) //遍历链表，下同 
	{
		q = p;
		p = p->next;
		i++;
	}
	if(!p || i>idx) //!p用来判断是否输入超出表长的数,i>idx用来判断是否输入非正数
	{
		printf ("\n输入位置有误，请重新输入:");
		return NULL;
	}
	else
	{
		newNode = (NODE*)malloc(sizeof(NODE));
		newNode->next = NULL;
		printf ("\n请输入要插入的数据：");
		scanf("%d",&newNode->number);
		getchar();
		if(idx == 1) //如果要插入的位置为第一个结点时，执行if语句 
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
	printf("\n第%d个位置插入元素之后的链表数据为:\n",idx);
	outputList(head);
	return head;
}

void ModifyRecordByIndex(NODE *head)
{
	NODE *p =head;
	int i,k;
	printf ("\n请输入要修改的位置：");
	scanf ("%d",&i);
	getchar();
	p = SearchData(head,i);
	while (!p) //如果p为空指针，执行while语句 
	{
		printf ("\n输入位置有误，请重新输入:");
		scanf ("%d",&i);
		getchar();
		p = SearchData(head,i);
	}
	if (p)
	{
		printf ("\n请输入新数据：");
		scanf ("%d",&k);
		p->number = k;
	}
}


NODE* DeleteNode(NODE *head,int idx)//删除链表中第idx位置的节点
{
	int i=1;
	NODE *p = head,*q; //p是快指针，指向当前指定位置，q是慢指针，指向p的前一位置
	while(p && i<idx)
	{
		q = p;
		p = p->next;
		i++;
	}
	if(!p || i>idx) //!p用来判断是否输入超出表长的数,i>idx用来判断是否输入非正数
	{
		printf ("\n输入位置有误，请重新输入:");
		return NULL;
	}
	else
	{
		if(p == head)
		{
			q = p->next;
			free(p); //free函数释放p结点 
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

int SearchLocation(NODE *head,int e) //查找数据e在哪个位置
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

NODE* SearchData(NODE *head,int idx) //查找指定位置的数据
{
	int i=1;
	NODE *p =head,*q; //p是快指针，指向当前指定位置，q是慢指针，指向p的前一位置
	while(p && i<idx)
	{
		q = p;
		p = p->next;
		i++;
	}
	if (!p || i>idx) //!p用来判断是否输入超出表长的数,i>idx用来判断是否输入非正数
		return NULL;
	else
		return p;
}

void SortList(NODE * head) //链表的冒泡排序交换域 
{
	NODE * p,*q;//p是快指针，q是慢指针
	int temp;
	for (q = head; q->next != NULL; q = q->next)
	{
		for (p = q->next; p != NULL; p = p->next)
		{
			if(q->number > p->number) 
			{
				temp = q->number; //交换p，q指针中的数据域 
				q->number = p->number;
				p->number = temp;
			}
		}
	}
}


void outputList(NODE *head)//输出链表中的数据
{
	NODE *p = head;
	if (!p)
		printf ("链表为空！");
	while(p)
	{
		printf("%d\t",p->number);
		p=p->next;
	}
	printf("\n");
}

void SaveRecordsToFile(NODE * head,FILE * fp)//将数据保存到本地文件中
{
	NODE * p = head;
	while(p)
	{
		fprintf(fp,"%5d",p->number); 
		//用fprintf函数将p->number中的值以“%5d”的格式输出到fp所指向的文件中 
		p = p->next;
	}
}

NODE* EntryRecordsByFile(NODE * head)//文件中读入数据
{
	NODE * newNode,* p = NULL,* list;//list为文件中读入的新链表
	char filename[] = "LinkList.txt";
	FILE * fp;
	printf ("\n即将从文件%s读入数据，请确保该文件存在并数据非空!\n","LinkList.txt");
	if((fp = fopen(filename,"r")) == NULL) //判断是否能打开fp所指向的文件 
	{
		printf ("数据文件加载失败!");
		exit(0); //exit函数是使程序终止 
	}
	else
	{
		printf ("\n成功从当前文件中读取到数据，具体如下：\n");
		while(fgetc(fp) != EOF) //若未到文件结束符，则一直取数据  //while中可替换为!feof(fp)
		{
			newNode = (NODE* )malloc(sizeof(NODE));
			newNode->next =NULL;
			fscanf(fp,"%5d",&newNode->number); 
			//用fscanf函数从fp指定的文件中按“%5d”的格式将输入数据送到
			//&newNode->number所指向的内存单元 
			if(p == NULL) //表头
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

NODE* Destroy(NODE *head)//释放链表所占用的内存
{
	NODE *q = head,*p; //p是快指针，指向下一位置，q是慢指针，指向当前位置
	while(q)
	{
		p = q->next;
		free(q); //释放q内存 
		q = p;
	}
	return NULL;
}
