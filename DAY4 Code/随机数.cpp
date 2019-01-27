//0~10随机数
/*#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int i,j,k;
	srand((int)time(0));
	for (k=0; k<2; k++)
	{
		for(i=0; i<10; i++)
		{
			j=1+(int)(10.0*rand()/(RAND_MAX+1.0));
			printf("%d\t",j);
		}
		printf ("\n");
	}

	return 0;
}*/

//0~99随机数
/*#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
	int i,j;
	srand((int) time(0));
	printf("Ten random numbers from 0 to 99\n\n");
	for (j=0; j<2; j++)
	{
		for(i=0; i<10; i++)
		{
			printf("%d\t", rand() % 100);
		}
		printf ("\n");
	}

	return 0;
}*/

//0~range随机数
/*#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
	int i,j,rounds,range,groups;
	printf ("请输入要产生随机数的轮次\n");
	scanf ("%d",&rounds);
	while (rounds--)
	{
		printf ("\n请输入随机数的范围\n");
		scanf ("%d",&range);
		printf ("\n请输入产生随机数的组数\n");
		scanf ("%d",&groups);
		srand((int) time(0));
		printf("\nrandom numbers from 0 to %d\n",range);
		for (j=0; j<groups; j++)
		{
			for(i=0; i<10; i++)
			{
				printf("%d\t",(int)(range*rand()/(RAND_MAX+1.0)));	//rand()函数返回的是一个0到RAND_MAX的随机数，
																	//RAND_MAX 这是一个常数，rand()函数取值范围在0-32767
			}
			printf ("\n");
		}
	}
	return 0;
}*/

//min~max随机数
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
	int i,j,rounds,min,max,groups;
	printf ("请输入要产生随机数的轮次\n");
	scanf ("%d",&rounds);
	while (rounds--)
	{
		printf ("\n请输入随机数的范围[min,max]\n");
		scanf ("%d%d",&min,&max);
		printf ("\n请输入产生随机数的组数\n");
		scanf ("%d",&groups);
		srand((int) time(0));
		printf("\nrandom numbers from %d to %d\n",min,max);
		for (j=0; j<groups; j++)
		{
			for(i=0; i<10; i++)
			{
				printf("%d\t",(rand() % (max - min + 1) + min));	
				//rand()函数返回的是一个0到RAND_MAX的随机数,RAND_MAX 这是一个常数，rand()函数取值范围在0-32767
			}
			printf ("\n");
		}
	}
	return 0;
}


