#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(struct student)

struct student
{
	char name[20];//学生姓名
	char sex[4];
	char affliate[20];//民族
	int age;
	char address[100];//家庭住址
	int score[4];//0 linearMath;1:english;2:highlevelMath;3:cprogram;
	int totalScore;
	struct student * next;
};

typedef struct student STUDENT_INFO;

char username[] = "xxh";
char password[] = "123";

//函数声明

//系统指令函数
void helpMenu();//帮助菜单 
void setLoginPassword();//修改系统登录密码

//链表处理函数
STUDENT_INFO * MakeNode();//创建一个结点并实例化数据成员
STUDENT_INFO * InitializeTables(STUDENT_INFO * stu_info_table);//链表初始化
STUDENT_INFO * BuildBankByHand(STUDENT_INFO * stu_info_table);//人工初始化学生信息表
STUDENT_INFO * BuildBankByFile(STUDENT_INFO * stu_info_table,FILE * fp);//初始化学生信息表
void SaveRecordsToFile(STUDENT_INFO * stu_info_table,FILE * fp);//将数据保存到本地文件中
void ModifyScore(STUDENT_INFO * stu_info_table,char name[]);//按姓名修改学生成绩
void SearchScore(STUDENT_INFO * stu_info_table,char name[]);//按姓名查询学生成绩
STUDENT_INFO * DeleteScore(STUDENT_INFO * stu_info_table,char name[]);//按姓名删除学生成绩
STUDENT_INFO * EmptyList(STUDENT_INFO * stu_info_table);//清空链表
STUDENT_INFO * AppendStuScoreAtTail(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode);//表尾追加学生记录     
STUDENT_INFO * AppendStuScoreAtHead(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode);//表头追加学生记录
STUDENT_INFO * AppendByName(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode);//按姓名追加学生记录
STUDENT_INFO * SortByTotalScore(STUDENT_INFO * stu_info_table);//按总分排序降序 
void printRecord(STUDENT_INFO * stu_info_table);//打印输出链表中的记录

int main()
{
	char uname[20],ps[20],stu_name[20];
	int choice,loop = 1;
	STUDENT_INFO * stu_info_table = NULL,*newNode;
	STUDENT_INFO * sorted_table = NULL;
	FILE * fp;
	printf ("欢迎登录学生信息管理系统：\n");
	begin:if(choice == 9);//goto语句的标号begin，若输入choice为9，则返回到begin处重新执行
	printf ("\n请输入用户名：");
	scanf ("%s",uname);
	//gets(uname);
	printf ("请输入密码：");
	scanf ("%s",ps);
	//gets(ps);
	if(strcmp(uname,username) || strcmp(ps,password))
	{
		printf ("\n用户名或密码错误，退出系统！\n");
		return 0;
	}
	helpMenu();
	while(loop)
	{
		printf ("\n请输入一个选项：[0,13]：");
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
				printf ("\n请输入要追加学生的信息\n");
				newNode = MakeNode();
				stu_info_table = AppendByName(stu_info_table,newNode);
				printRecord(stu_info_table);
			}
			break;
		case 4:
			{
				printf("\n修改学生的成绩，请谨慎操作！\n");
				printf ("请输入要修改的学生姓名：");
				scanf ("%s",stu_name);
				ModifyScore(stu_info_table,stu_name);
				//printRecord(stu_info_table);
			}
			break;
		case 5:
			{
				printf ("\n删除学生的成绩记录，请谨慎操作！\n");
				printf ("请输入要删除的学生姓名：");
				scanf ("%s",stu_name);
				stu_info_table = DeleteScore(stu_info_table,stu_name);
				printRecord(stu_info_table);
			}
			break;
		case 6:
			{
				printf ("\n查询学生成绩：\n");
				printf ("请输入要查询的学生姓名：");
				scanf ("%s",stu_name);
				SearchScore(stu_info_table,stu_name);
			}
			break;
		case 7:
			{
				printf ("\n按总分降序排序后学生信息如下：\n");
				stu_info_table = SortByTotalScore(stu_info_table);
				printRecord(stu_info_table);
			}
			break;
		case 8:
			{
				fp = fopen("studentscore.txt","w");//"a"
				SaveRecordsToFile(stu_info_table,fp);
				printf ("学生数据成功保存到当前文件%s中","studentscore.txt");//\"%s\"中.\n
				fclose(fp);
			}
			break;
		case 9:
			setLoginPassword();
			goto begin;//设置完新密码后，用goto语句返回到上面的登录界面 
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
			printf ("\n退出系统！\n");
			loop = 0;
			break;
		default:
			{
				printf ("输入了非法的选项，退出系统！\n");
				loop = 0;
			};
		}
	}
	return 0;
}

void setLoginPassword()//修改系统登录密码
{
	char newPassword[20];
	printf ("\n请输入新密码：");
	scanf ("%s",newPassword);
    //gets(newPassword);
	strcpy(password,newPassword);
}

void helpMenu()//帮助菜单
{
	printf ("*******************使用帮助*******************\n");
	printf ("[0]链表初始化\n");
	printf ("[1]插入学生成绩[表头插入]\n");
	printf ("[2]插入学生成绩[表尾插入]\n");
	printf ("[3]插入学生成绩[在某学生前插入]\n");
	printf ("[4]修改学生成绩[按名字]\n");
	printf ("[5]删除学生成绩[按名字]\n");
	printf ("[6]查询学生成绩[按名字]\n");
	printf ("[7]按总分降序排名\n");
	printf ("[8]将学生数据保存到本地文件\n");
	printf ("[9]修改系统登录密码\n");
	printf ("[10]打印所有学生成绩\n");
	printf ("[11]显示帮助\n");
	printf ("[12]清空数据\n");
	printf ("[13]退出系统\n");
	printf ("**********************************************\n");
}

void printRecord(STUDENT_INFO * stu_info_table)
{
	int i = 0;
	STUDENT_INFO * q = stu_info_table;
	printf ("\n%s: %6s %s %s %s %s ","序号","姓名","性别","民族","年龄","地址");
	printf ("%s %s %s %3s %s\n","线代","英语","高数","C","总成绩");	
	while(q)
	{
		printf ("%4d: %6s %4s %4s %4d %4s ",i+1,q->name,q->sex,q->affliate,q->age,q->address);
		printf ("%4d %4d %4d %4d %4d\n",q->score[0],q->score[1],q->score[2],q->score[3],q->totalScore);
		q = q->next;
		i++;
	}
	if(i == 0)
	    printf ("列表记录为空!\n");
}


STUDENT_INFO * InitializeTables(STUDENT_INFO * stu_info_table)//链表初始化
{
	char node;
	//char * filename = "studentscore.txt";// = "D://1.txt";
	char filename[] = "studentscore.txt";
	FILE * fp;
	getchar();
	printf ("\n是否选择手动输入数据？[Y/N]：");
	node = getchar();
	if(node == 'Y' || node == 'y')
	{
		stu_info_table = BuildBankByHand(stu_info_table);
	}
	else
	{
		printf ("\n即将从文件%s读入数据，请确保该文件存在并数据非空!\n","studentscore.txt");//\"%s\"  filename
		if((fp = fopen(filename,"rb")) != NULL)
		{
			stu_info_table = BuildBankByFile(stu_info_table,fp);
			fclose(fp);
		}
		else
		    printf ("数据文件加载失败!");
	}
	return stu_info_table;
}

STUDENT_INFO * BuildBankByHand(STUDENT_INFO * stu_info_table)//人工初始化学生信息表
{
	int loop = 1,i = 0;
	char ctemp;
	STUDENT_INFO * newNode,* p=stu_info_table;
	while(loop)
	{
		printf ("\n增加新记录？[Y/N]：");
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

STUDENT_INFO * BuildBankByFile(STUDENT_INFO * stu_info_table,FILE * fp)//初始化学生信息表
{
	STUDENT_INFO * newNode;
	STUDENT_INFO * p = stu_info_table;
	int i;
    printf ("成功从当前文件中读取到学生信息数据，具体如下：\n");
    getchar();
    while(fgetc(fp) != EOF)//若未到文件结束符，则一直取数据
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

STUDENT_INFO * MakeNode()//创建一个结点并实例化数据成员
{
	STUDENT_INFO * newNode = (STUDENT_INFO * )malloc(LEN);
	int j;
	newNode->totalScore = 0;	
	printf ("请输入学生姓名：");
	scanf ("%s",newNode->name);
	printf ("请输入学生的民族：");
	scanf ("%s",newNode->affliate);
	printf ("请输入性别：");
	scanf ("%s",newNode->sex);
	printf ("请输入年龄：");
	scanf ("%d",&newNode->age);
	printf ("请输入地址：");
	scanf ("%s",newNode->address);		
	printf ("请输入四门课程的成绩：\n");
    for(j=0;j<4;j++)
    {
    	scanf ("%d",&newNode->score[j]);
    	newNode->totalScore += newNode->score[j];
	}
	return newNode;	 
}


STUDENT_INFO * AppendStuScoreAtHead(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode)//表头追加学生记录
{
	STUDENT_INFO * p = stu_info_table;
	newNode->next = p;
	stu_info_table = newNode;
	return stu_info_table;	
}


STUDENT_INFO * AppendStuScoreAtTail(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode)//表尾追加学生记录
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



STUDENT_INFO * AppendByName(STUDENT_INFO * stu_info_table,STUDENT_INFO * newNode)//按姓名追加学生记录
{
	char appendstu[20];
	STUDENT_INFO * p = stu_info_table,* q;
	printf ("\n请输入要追加记录位置学生的姓名：");
	scanf ("%s",appendstu);
	while(p && strcmp(p->name,appendstu) != 0)
	{
		q = p;
		p = p->next;
	}
    if(!p)
	{
		printf ("\n未找到要追加学生记录的姓名，将追加的学生记录插在头部\n");
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


void ModifyScore(STUDENT_INFO * stu_info_table,char name[])//按姓名修改学生成绩
{
	STUDENT_INFO * p = stu_info_table;
	int i;
	while(p && strcmp(p->name,name) != 0)
	{
		p = p->next;
	}
	if(!p)
	{
		printf ("\n该学生不存在！\n"); 
	}
	else
	{
		printf ("\n请修改%s的学生成绩记录！\n",name);
		p->totalScore = 0;//重新令p->totalScore赋为0 
        for(i=0;i<4;i++)
        {
        	scanf ("%d",&p->score[i]);
        	p->totalScore += p->score[i];
		}
		printf ("\n已经修改姓名为%s的学生成绩记录！\n",name);
		printf ("%s %s %s %3s %s\n","线代","英语","高数","C","总成绩");
		printf ("%4d %4d %4d %4d %4d\n",p->score[0],p->score[1],p->score[2],p->score[3],p->totalScore);
	}
}

STUDENT_INFO * DeleteScore(STUDENT_INFO * stu_info_table,char name[])//按姓名删除学生成绩
{
	STUDENT_INFO * p = stu_info_table,* q = NULL;
	while (p && strcmp(p->name,name))
    {
    	q = p;
    	p = q->next;
	}
	if(p == NULL)
	{
		printf ("链表中不存在姓名为%s的记录！",name);
	}
	else
	{
		if(p == stu_info_table)//删除的是表首元素
	  //if(q == NULL) //或者用q来判断
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
		printf ("\n已删除学生成绩！\n");
	}
	return stu_info_table;
}

void SearchScore(STUDENT_INFO * stu_info_table,char name[])//按姓名查询学生成绩
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
		printf ("链表中不存在姓名为%s的记录！",name);
	}
	else
	{
		printf ("\n%s: %6s %s %s %s %s ","序号","姓名","性别","民族","年龄","地址");
	    printf ("%s %s %s %3s %s\n","线代","英语","高数","C","总成绩");	
		printf ("%4d: %6s %4s %4s %4d %4s ",i+1,q->name,q->sex,q->affliate,q->age,q->address);
		printf ("%4d %4d %4d %4d %4d\n",q->score[0],q->score[1],q->score[2],q->score[3],q->totalScore);
	}
}


STUDENT_INFO * SortByTotalScore(STUDENT_INFO * stu_info_table/*,int nchoice*/)//按总分排序降序 
{
	//STUDENT_INFO * sortedTable,* p = stu_info_table,* copyNode,* q,* q_prev;
	STUDENT_INFO * p,* q,copyNode;//* copyNode
	int i;
	//copyNode = (STUDENT_INFO * )malloc(LEN);//创建一个结点
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


void SaveRecordsToFile(STUDENT_INFO * stu_info_table,FILE * fp)//将数据保存到本地文件中
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


STUDENT_INFO * EmptyList(STUDENT_INFO * stu_info_table)//清空链表
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
 
    






















