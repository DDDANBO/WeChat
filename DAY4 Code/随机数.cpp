//0~10�����
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

//0~99�����
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

//0~range�����
/*#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
	int i,j,rounds,range,groups;
	printf ("������Ҫ������������ִ�\n");
	scanf ("%d",&rounds);
	while (rounds--)
	{
		printf ("\n������������ķ�Χ\n");
		scanf ("%d",&range);
		printf ("\n��������������������\n");
		scanf ("%d",&groups);
		srand((int) time(0));
		printf("\nrandom numbers from 0 to %d\n",range);
		for (j=0; j<groups; j++)
		{
			for(i=0; i<10; i++)
			{
				printf("%d\t",(int)(range*rand()/(RAND_MAX+1.0)));	//rand()�������ص���һ��0��RAND_MAX���������
																	//RAND_MAX ����һ��������rand()����ȡֵ��Χ��0-32767
			}
			printf ("\n");
		}
	}
	return 0;
}*/

//min~max�����
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
	int i,j,rounds,min,max,groups;
	printf ("������Ҫ������������ִ�\n");
	scanf ("%d",&rounds);
	while (rounds--)
	{
		printf ("\n������������ķ�Χ[min,max]\n");
		scanf ("%d%d",&min,&max);
		printf ("\n��������������������\n");
		scanf ("%d",&groups);
		srand((int) time(0));
		printf("\nrandom numbers from %d to %d\n",min,max);
		for (j=0; j<groups; j++)
		{
			for(i=0; i<10; i++)
			{
				printf("%d\t",(rand() % (max - min + 1) + min));	
				//rand()�������ص���һ��0��RAND_MAX�������,RAND_MAX ����һ��������rand()����ȡֵ��Χ��0-32767
			}
			printf ("\n");
		}
	}
	return 0;
}


