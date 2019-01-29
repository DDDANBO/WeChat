#include <stdio.h>
#include <stdlib.h>
#define STU_NAME_LEN 16
/*学生信息*/
typedef struct student_tag
{
	char name[STU_NAME_LEN];  //学生姓名
	unsigned int id;          //学生学号
	int score;                //学生成绩
} student_t;

int studentCompare(const void *stu1,const void *stu2)
{
	/*强转成需要比较的数据结构*/
	student_t *value1 = (student_t*)stu1;
	student_t *value2 = (student_t*)stu2;
	return value1->score-value2->score;
}

int main(void)
{
	/*创建三个学生信息*/
	student_t stu1 = {"one",1,99};
	student_t stu2 = {"two",2,77};
	student_t stu3 = {"three",3,88};

	student_t stu[] = {stu1,stu2,stu3};

	/*排序，将studentCompare作为参数传入qsort*/
	qsort((void*)stu,3,sizeof(student_t),studentCompare);
	int loop = 0;

	/**遍历输出*/
	for(loop = 0; loop < 3; loop++)
	{
		printf("name:%s,id:%u,score:%d\n",stu[loop].name,stu[loop].id,stu[loop].score);
	}
	return 0;
}
