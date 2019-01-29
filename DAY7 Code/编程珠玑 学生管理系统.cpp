#include <stdio.h>
#include <stdlib.h>
#define STU_NAME_LEN 16
/*ѧ����Ϣ*/
typedef struct student_tag
{
	char name[STU_NAME_LEN];  //ѧ������
	unsigned int id;          //ѧ��ѧ��
	int score;                //ѧ���ɼ�
} student_t;

int studentCompare(const void *stu1,const void *stu2)
{
	/*ǿת����Ҫ�Ƚϵ����ݽṹ*/
	student_t *value1 = (student_t*)stu1;
	student_t *value2 = (student_t*)stu2;
	return value1->score-value2->score;
}

int main(void)
{
	/*��������ѧ����Ϣ*/
	student_t stu1 = {"one",1,99};
	student_t stu2 = {"two",2,77};
	student_t stu3 = {"three",3,88};

	student_t stu[] = {stu1,stu2,stu3};

	/*���򣬽�studentCompare��Ϊ��������qsort*/
	qsort((void*)stu,3,sizeof(student_t),studentCompare);
	int loop = 0;

	/**�������*/
	for(loop = 0; loop < 3; loop++)
	{
		printf("name:%s,id:%u,score:%d\n",stu[loop].name,stu[loop].id,stu[loop].score);
	}
	return 0;
}
