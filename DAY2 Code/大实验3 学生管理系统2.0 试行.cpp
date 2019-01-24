#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(struct student)

struct student
{
	char name[20];//ѧ������
	char sex[4];
	char affliate[20];//����
	int age;
	char address[100];//��ͥסַ
	int score[4];//0 linearMath;1:english;2:highlevelMath;3:cprogram;
	int totalScore;
	struct student * next;
};

typedef struct student STUDENT_INFO;

char username[] = "xxh";
char password[] = "123";

//��������

//ϵͳָ���
void helpMenu();//�����˵� 
void setLoginPassword();//�޸�ϵͳ��¼����

//��������
STUDENT_INFO * MakeNode();//����һ����㲢ʵ�������ݳ�Ա
STUDENT_INFO * InitializeTables(STUDENT_INFO * stu_info_table);//�����ʼ��
STUDENT_INFO * BuildBankByHand(STUDENT_INFO * stu_info_table);//�˹���ʼ��ѧ����Ϣ��
STUDENT_INFO * BuildBankByFile(STUDENT_INFO * stu_info_table,FILE * fp);//��ʼ��ѧ����Ϣ��
void SaveRecordsToFile(STUDENT_INFO * stu_info_table,FILE * fp);//�����ݱ��浽�����ļ���
void ModifyScore(STUDENT_INFO * stu_info_table,char name[]);//�������޸�ѧ���ɼ�
void SearchScore(STUDENT_INFO * stu_info_table,char name[]);//��������ѯѧ���ɼ�
STUDENT_INFO * DeleteScore(STUDENT_INFO * stu_info_table,char name[]);//������ɾ��ѧ���ɼ�
STUDENT_INFO * EmptyList(STUDENT_INFO * stu_info_table);//�������
STUDENT_INFO * AppendStuScoreAtTail(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode);//��β׷��ѧ����¼     
STUDENT_INFO * AppendStuScoreAtHead(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode);//��ͷ׷��ѧ����¼
STUDENT_INFO * AppendByName(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode);//������׷��ѧ����¼
STUDENT_INFO * SortByTotalScore(STUDENT_INFO * stu_info_table);//���ܷ������� 
void printRecord(STUDENT_INFO * stu_info_table);//��ӡ��������еļ�¼

int main()
{
	char uname[20],ps[20],stu_name[20];
	int choice,loop = 1;
	STUDENT_INFO * stu_info_table = NULL,*newNode;
	STUDENT_INFO * sorted_table = NULL;
	FILE * fp;
	printf ("��ӭ��¼ѧ����Ϣ����ϵͳ��\n");
	begin:if(choice == 9);//goto���ı��begin��������choiceΪ9���򷵻ص�begin������ִ��
	printf ("\n�������û�����");
	scanf ("%s",uname);
	//gets(uname);
	printf ("���������룺");
	scanf ("%s",ps);
	//gets(ps);
	if(strcmp(uname,username) || strcmp(ps,password))
	{
		printf ("\n�û�������������˳�ϵͳ��\n");
		return 0;
	}
	helpMenu();
	while(loop)
	{
		printf ("\n������һ��ѡ�[0,13]��");
		scanf ("%d",&choice);
		switch(choice)
		{
		case 0:
			{
				stu_info_table = InitializeTables(stu_info_table);
				printRecord(stu_info_table);
			}
			break;
		case 1:
			{
				newNode = MakeNode();
				stu_info_table = AppendStuScoreAtHead(stu_info_table,newNode);
				printRecord(stu_info_table);
			}
			break;
		case 2:
			{
				newNode = MakeNode();
				stu_info_table = AppendStuScoreAtTail(stu_info_table,newNode);
				printRecord(stu_info_table);
			}
			break;
		case 3:
			{
				printf ("\n������Ҫ׷��ѧ������Ϣ\n");
				newNode = MakeNode();
				stu_info_table = AppendByName(stu_info_table,newNode);
				printRecord(stu_info_table);
			}
			break;
		case 4:
			{
				printf("\n�޸�ѧ���ĳɼ��������������\n");
				printf ("������Ҫ�޸ĵ�ѧ��������");
				scanf ("%s",stu_name);
				ModifyScore(stu_info_table,stu_name);
				//printRecord(stu_info_table);
			}
			break;
		case 5:
			{
				printf ("\nɾ��ѧ���ĳɼ���¼�������������\n");
				printf ("������Ҫɾ����ѧ��������");
				scanf ("%s",stu_name);
				stu_info_table = DeleteScore(stu_info_table,stu_name);
				printRecord(stu_info_table);
			}
			break;
		case 6:
			{
				printf ("\n��ѯѧ���ɼ���\n");
				printf ("������Ҫ��ѯ��ѧ��������");
				scanf ("%s",stu_name);
				SearchScore(stu_info_table,stu_name);
			}
			break;
		case 7:
			{
				printf ("\n���ֽܷ��������ѧ����Ϣ���£�\n");
				stu_info_table = SortByTotalScore(stu_info_table);
				printRecord(stu_info_table);
			}
			break;
		case 8:
			{
				fp = fopen("studentscore.txt","w");//"a"
				SaveRecordsToFile(stu_info_table,fp);
				printf ("ѧ�����ݳɹ����浽��ǰ�ļ�%s��","studentscore.txt");//\"%s\"��.\n
				fclose(fp);
			}
			break;
		case 9:
			setLoginPassword();
			goto begin;//���������������goto��䷵�ص�����ĵ�¼���� 
			break;
		case 10:
			printRecord(stu_info_table);
			break;
		case 11:
			helpMenu();
			break;
		case 12:
			stu_info_table = EmptyList(stu_info_table);
			printRecord(stu_info_table);
			break;			
		case 13:
			printf ("\n�˳�ϵͳ��\n");
			loop = 0;
			break;
		default:
			{
				printf ("�����˷Ƿ���ѡ��˳�ϵͳ��\n");
				loop = 0;
			};
		}
	}
	return 0;
}

void setLoginPassword()//�޸�ϵͳ��¼����
{
	char newPassword[20];
	printf ("\n�����������룺");
	scanf ("%s",newPassword);
    //gets(newPassword);
	strcpy(password,newPassword);
}

void helpMenu()//�����˵�
{
	printf ("*******************ʹ�ð���*******************\n");
	printf ("[0]�����ʼ��\n");
	printf ("[1]����ѧ���ɼ�[��ͷ����]\n");
	printf ("[2]����ѧ���ɼ�[��β����]\n");
	printf ("[3]����ѧ���ɼ�[��ĳѧ��ǰ����]\n");
	printf ("[4]�޸�ѧ���ɼ�[������]\n");
	printf ("[5]ɾ��ѧ���ɼ�[������]\n");
	printf ("[6]��ѯѧ���ɼ�[������]\n");
	printf ("[7]���ֽܷ�������\n");
	printf ("[8]��ѧ�����ݱ��浽�����ļ�\n");
	printf ("[9]�޸�ϵͳ��¼����\n");
	printf ("[10]��ӡ����ѧ���ɼ�\n");
	printf ("[11]��ʾ����\n");
	printf ("[12]�������\n");
	printf ("[13]�˳�ϵͳ\n");
	printf ("**********************************************\n");
}

void printRecord(STUDENT_INFO * stu_info_table)
{
	int i = 0;
	STUDENT_INFO * q = stu_info_table;
	printf ("\n%s: %6s %s %s %s %s ","���","����","�Ա�","����","����","��ַ");
	printf ("%s %s %s %3s %s\n","�ߴ�","Ӣ��","����","C","�ܳɼ�");	
	while(q)
	{
		printf ("%4d: %6s %4s %4s %4d %4s ",i+1,q->name,q->sex,q->affliate,q->age,q->address);
		printf ("%4d %4d %4d %4d %4d\n",q->score[0],q->score[1],q->score[2],q->score[3],q->totalScore);
		q = q->next;
		i++;
	}
	if(i == 0)
	    printf ("�б��¼Ϊ��!\n");
}


STUDENT_INFO * InitializeTables(STUDENT_INFO * stu_info_table)//�����ʼ��
{
	char node;
	//char * filename = "studentscore.txt";// = "D://1.txt";
	char filename[] = "studentscore.txt";
	FILE * fp;
	getchar();
	printf ("\n�Ƿ�ѡ���ֶ��������ݣ�[Y/N]��");
	node = getchar();
	if(node == 'Y' || node == 'y')
	{
		stu_info_table = BuildBankByHand(stu_info_table);
	}
	else
	{
		printf ("\n�������ļ�%s�������ݣ���ȷ�����ļ����ڲ����ݷǿ�!\n","studentscore.txt");//\"%s\"  filename
		if((fp = fopen(filename,"rb")) != NULL)
		{
			stu_info_table = BuildBankByFile(stu_info_table,fp);
			fclose(fp);
		}
		else
		    printf ("�����ļ�����ʧ��!");
	}
	return stu_info_table;
}

STUDENT_INFO * BuildBankByHand(STUDENT_INFO * stu_info_table)//�˹���ʼ��ѧ����Ϣ��
{
	int loop = 1,i = 0;
	char ctemp;
	STUDENT_INFO * newNode,* p=stu_info_table;
	while(loop)
	{
		printf ("\n�����¼�¼��[Y/N]��");
		getchar();		
		ctemp = getchar();
		if(ctemp == 'Y' || ctemp == 'y')
		{
			newNode = MakeNode();
			if(p == NULL)
			{
				newNode->next = p;
				stu_info_table = newNode;
				p = stu_info_table;
			}
			else
			{
				newNode->next = p->next;
				p->next = newNode;
				p = newNode;
			}
		}
		else
		{
			loop = 0;
		}
		    
	}
	return stu_info_table;
}

STUDENT_INFO * BuildBankByFile(STUDENT_INFO * stu_info_table,FILE * fp)//��ʼ��ѧ����Ϣ��
{
	STUDENT_INFO * newNode;
	STUDENT_INFO * p = stu_info_table;
	int i;
    printf ("�ɹ��ӵ�ǰ�ļ��ж�ȡ��ѧ����Ϣ���ݣ��������£�\n");
    getchar();
    while(fgetc(fp) != EOF)//��δ���ļ�����������һֱȡ����
	{
		newNode = (STUDENT_INFO * )malloc(LEN);
		fscanf(fp,"%20s",newNode->name);
		fscanf(fp,"%4s",/*&*/newNode->sex);
		fscanf(fp,"%20s",newNode->affliate);
		fscanf(fp,"%4d",&newNode->age);
		fscanf(fp,"%20s",newNode->address);
		for(i=0;i<4;i++)
		{
			fscanf(fp,"%4d",&newNode->score[i]);
		}
		fscanf(fp,"%6d",&newNode->totalScore);
		if(p == NULL)
		{
			newNode->next = p;
			stu_info_table = newNode;
			p = stu_info_table;
		}
		else
		{
			newNode->next = p->next;
			p->next = newNode;
			p = newNode;
		}
	}
	return stu_info_table;
}

STUDENT_INFO * MakeNode()//����һ����㲢ʵ�������ݳ�Ա
{
	STUDENT_INFO * newNode = (STUDENT_INFO * )malloc(LEN);
	int j;
	newNode->totalScore = 0;	
	printf ("������ѧ��������");
	scanf ("%s",newNode->name);
	printf ("������ѧ�������壺");
	scanf ("%s",newNode->affliate);
	printf ("�������Ա�");
	scanf ("%s",newNode->sex);
	printf ("���������䣺");
	scanf ("%d",&newNode->age);
	printf ("�������ַ��");
	scanf ("%s",newNode->address);		
	printf ("���������ſγ̵ĳɼ���\n");
    for(j=0;j<4;j++)
    {
    	scanf ("%d",&newNode->score[j]);
    	newNode->totalScore += newNode->score[j];
	}
	return newNode;	 
}


STUDENT_INFO * AppendStuScoreAtHead(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode)//��ͷ׷��ѧ����¼
{
	STUDENT_INFO * p = stu_info_table;
	newNode->next = p;
	stu_info_table = newNode;
	return stu_info_table;	
}


STUDENT_INFO * AppendStuScoreAtTail(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode)//��β׷��ѧ����¼
{
	STUDENT_INFO * p = stu_info_table,* q;
	while(p)
	{
		q = p;
		p = p->next;
	}
	q->next = newNode;
	newNode->next = NULL;
	return stu_info_table;
}



STUDENT_INFO * AppendByName(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode)//������׷��ѧ����¼
{
	char appendstu[20];
	STUDENT_INFO * p = stu_info_table,* q;
	printf ("\n������Ҫ׷�Ӽ�¼λ��ѧ����������");
	scanf ("%s",appendstu);
	while(p && strcmp(p->name,appendstu) != 0)
	{
		q = p;
		p = p->next;
	}
    if(!p)
	{
		printf ("\nδ�ҵ�Ҫ׷��ѧ����¼����������׷�ӵ�ѧ����¼����ͷ��\n");
		newNode->next = stu_info_table;
		stu_info_table = newNode;
	}
	else
	{
		if(p == stu_info_table)
		{
			newNode->next = p;
		    stu_info_table = newNode;
		}
		else
		{
			newNode->next = p;
		    q->next = newNode;
		}
		
	}
	return stu_info_table;
}


void ModifyScore(STUDENT_INFO * stu_info_table,char name[])//�������޸�ѧ���ɼ�
{
	STUDENT_INFO * p = stu_info_table;
	int i;
	while(p && strcmp(p->name,name) != 0)
	{
		p = p->next;
	}
	if(!p)
	{
		printf ("\n��ѧ�������ڣ�\n"); 
	}
	else
	{
		printf ("\n���޸�%s��ѧ���ɼ���¼��\n",name);
		p->totalScore = 0;//������p->totalScore��Ϊ0 
        for(i=0;i<4;i++)
        {
        	scanf ("%d",&p->score[i]);
        	p->totalScore += p->score[i];
		}
		printf ("\n�Ѿ��޸�����Ϊ%s��ѧ���ɼ���¼��\n",name);
		printf ("%s %s %s %3s %s\n","�ߴ�","Ӣ��","����","C","�ܳɼ�");
		printf ("%4d %4d %4d %4d %4d\n",p->score[0],p->score[1],p->score[2],p->score[3],p->totalScore);
	}
}

STUDENT_INFO * DeleteScore(STUDENT_INFO * stu_info_table,char name[])//������ɾ��ѧ���ɼ�
{
	STUDENT_INFO * p = stu_info_table,* q = NULL;
	while (p && strcmp(p->name,name))
    {
    	q = p;
    	p = q->next;
	}
	if(p == NULL)
	{
		printf ("�����в���������Ϊ%s�ļ�¼��",name);
	}
	else
	{
		if(p == stu_info_table)//ɾ�����Ǳ���Ԫ��
	  //if(q == NULL) //������q���ж�
	    {
	    	q = p->next;
	    	stu_info_table = q;
	    	free(p);
		}
		else
		{
			p = q->next;
			q->next = p->next;
			free(p);
		}
		printf ("\n��ɾ��ѧ���ɼ���\n");
	}
	return stu_info_table;
}

void SearchScore(STUDENT_INFO * stu_info_table,char name[])//��������ѯѧ���ɼ�
{
	STUDENT_INFO * q = stu_info_table;
	int i=0;
	while(q && strcmp(q->name,name))
	{
		q = q->next;
		i++;
	}
	if(q == NULL)
	{
		printf ("�����в���������Ϊ%s�ļ�¼��",name);
	}
	else
	{
		printf ("\n%s: %6s %s %s %s %s ","���","����","�Ա�","����","����","��ַ");
	    printf ("%s %s %s %3s %s\n","�ߴ�","Ӣ��","����","C","�ܳɼ�");	
		printf ("%4d: %6s %4s %4s %4d %4s ",i+1,q->name,q->sex,q->affliate,q->age,q->address);
		printf ("%4d %4d %4d %4d %4d\n",q->score[0],q->score[1],q->score[2],q->score[3],q->totalScore);
	}
}


STUDENT_INFO * SortByTotalScore(STUDENT_INFO * stu_info_table/*,int nchoice*/)//���ܷ������� 
{
	//STUDENT_INFO * sortedTable,* p = stu_info_table,* copyNode,* q,* q_prev;
	STUDENT_INFO * p,* q,copyNode;//* copyNode
	int i;
	//copyNode = (STUDENT_INFO * )malloc(LEN);//����һ�����
	//copyNode = NULL;
	for (p = stu_info_table;p->next != NULL;p = p->next)
	{
		for (q = p->next;q != NULL;q = q->next)
		{
			if(q->totalScore > p->totalScore)
			{
				strcpy(copyNode.name,p->name);
    			strcpy(p->name,q->name);
    			strcpy(q->name,copyNode.name);
    			
    			strcpy(copyNode.sex,p->sex);
    			strcpy(p->sex,q->sex);
    			strcpy(q->sex,copyNode.sex);
    			
    			strcpy(copyNode.affliate,p->affliate);
    			strcpy(p->affliate,q->affliate);
    			strcpy(q->affliate,copyNode.affliate);
    			
    			copyNode.age = p->age;
    			p->age = q->age;
    			q->age = copyNode.age;
    			
    			strcpy(copyNode.address,p->address);
    			strcpy(p->address,q->address);
    			strcpy(q->address,copyNode.address);
    			
    			for (i=0;i<4;i++)
    			{
    				copyNode.score[i] = p->score[i];
    		    	p->score[i] = q->score[i];
    		    	q->score[i] = copyNode.score[i];
				}
    			
    			copyNode.totalScore = p->totalScore;
    			p->totalScore = q->totalScore;
    			q->totalScore = copyNode.totalScore;
			}
		}
	}
	return stu_info_table;
}
    /*if(stu_indo_table)
        stu_indo_table = EmptyList(stu_indo_table);
    if(sorted_table)
        stu_indo_table = EmptyList(sorted_table );    
    return 1;*/


void SaveRecordsToFile(STUDENT_INFO * stu_info_table,FILE * fp)//�����ݱ��浽�����ļ���
{
	STUDENT_INFO * p = stu_info_table;
	int i;	
	while(p)
	{
		fprintf(fp,"%20s",p->name);
		fprintf(fp,"%4s",p->sex);
		fprintf(fp,"%20s",p->affliate);
		fprintf(fp,"%4d",p->age);
		fprintf(fp,"%20s",p->address);
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%4d",p->score[i]);
		}
		fprintf(fp,"%6d",p->totalScore);
		p = p->next;
	}
}


STUDENT_INFO * EmptyList(STUDENT_INFO * stu_info_table)//�������
{
	STUDENT_INFO * p = stu_info_table,* q = NULL;
	while(p)
	{
		q = p;
		p = q->next;
		free(q);
	}
	return NULL;
}
 
    






















