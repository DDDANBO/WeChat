/*#include <stdio.h>
char(*pFun)(int);
char glFun(int a)
{
	return a + '0';
}

int main()
{
	pFun = glFun;
	printf("%c",(*pFun)(2));
	return 0;
}
*/

#include <stdio.h>
typedef int (*fp_t)(char c);

int f0(char c)
{
	printf("f0, c = %c\n", c);
	return 0;
}
int f1(char c)
{
	printf("f1, c = %c\n", c);
	return 1;
}

int main()
{
	int ret;
	fp_t fp;
	fp = f0;
	ret = fp('a');
	printf ("%d\n",ret);
	fp = f1;
	ret = fp('x');
	printf ("%d\n",ret);
	return 0;
}


//#include <stdio.h>
//typedef char(*pFun)(int);   //跟上一行功能等同
/*typedef的功能是定义新的类型。第一句就是定义了一种PTRFUN的类型，并定义这种类型为指向某种函数的指针，这种函数以一个int为参数并返回char类型。*/
/*char glFun(int a);
pFun gl_pFun()
{
	return glFun;
}
char glFun(int a)
{
	switch (a)
	{
		case 1:
			return 'A';
		default:
			return 'E';
	}
}
int main()
{
	pFun pf = gl_pFun();
	printf("---------- %c \n",  pf(2));
	return 0;
}*/


/*#include <stdio.h>
char (*pFun)(int);
char glFun(int a)
{
	switch (a)
	{
		case 1:
			return 'A';
		default:
			return 'E';
	}
}
int main()
{
	pFun = glFun;
	printf("---------- %c \n",  (*pFun)(2));
	return 0;
}*/ 
