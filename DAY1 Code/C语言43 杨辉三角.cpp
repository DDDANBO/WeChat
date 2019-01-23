#include <stdio.h>
int main ()
{
	int a[30][30]={1},i,j,m,n;
    while (scanf ("%d",&n) != EOF)
	{
		for (i=0;i<n;i++)
		{
			a[i][0]=1;
			for (j=1;j<=i;j++)
			{
				a[i][j]=1;
				if (j<i)
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<=i;j++)
			{
				if (j==i)
				printf ("%d\n",a[i][j]);
			    else printf ("%d ",a[i][j]);
			}
		}
		printf ("\n");
	}
		return 0;
}
		
