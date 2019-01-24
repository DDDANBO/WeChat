//¶àÏîÊ½ f(x) = a0 + a1x + ... + an-1x^(n-1) + anx^n
#include <stdio.h>
#include <math.h>
double f(int n,double a[],double x);
int main()
{
	int j;
    double x[5];
	for (j=0;j<5;j++)
	{
		scanf ("%lf",&x[j]);
	}
	printf ("%lf",f(5,x,3));//
	return 0;	
}

/*double f(int n,double a[],double x)
{
	int i;
	double p = a[0];
	for (i = 1;i<=n;i++)
	{
		p +=(a[i] * pow(x,i));
	}
	return p;
}*/


double f(int n,double a[],double x)
{
	int i;
	double p = a[n];
	for (i = n;i>0;i--)
	{
		p = a[i-1] + x*p;
	}
	return p;
}
