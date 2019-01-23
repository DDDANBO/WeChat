/*#include <stdio.h>
int main() 
{
	int p=1,i=2,k;
	scanf ("%d",&k);
	while (i<=k) 
	{
		p=p*i;
		i=i+1;
	}
	printf("%d!=%d\n",k,p);
	return 0;
}*/


/*#include <stdio.h>
int fac(int n);
int main() 
{
	int i,j,k;
	scanf ("%d",&j);
	for (i= 1;i <= j;i++)
	{
		k = fac(i);
	}
	printf ("%d!=%d",j,k);
	return 0;
}

int fac(int n)
{
	static int f = 1;
	f = f*n;
	return f;
}*/

#include <stdio.h>
int fun(int n);
int main() 
{
	int j,k;
	scanf ("%d",&j);
	k = fun(j);
	printf ("%d!=%d",j,k);
	return 0;
}

int fun(int n)
{
	int f;
	if(n == 1)
	f = 1;
	else
	f = n*fun(n-1);
	return f;
}
	
