/*#include <stdio.h>
#include <math.h>
int main ()
{
	int i,flag,n = 2,count = 0;
	while (n<100)//100�������� 
	{
		flag = 1;
		for (i=2;i<=(int)sqrt(n);i++)//����i<=n/2;����i<=n-1; 
	    {	    
		    if(n%i == 0)
		    {
		    	flag = 0;
		    	break;
			}
	    }
	    if(flag == 1)
	    {
	    	count++;//������������� 
	    	printf ("%d\t",n);
	    	if(count%5 == 0)
	    	printf ("\n");
		}	   
	    n++;
	}	
	return 0;
}*/ 


#include <stdio.h>
#include <math.h>
int main ()
{
	int i,k,n = 2,count = 0;
	while (n<100)//100�������� 
	{
		k = (int)sqrt(n);
		for (i=2;i<=k;i++)//����i<=n/2;����i<=n-1; 
	    {	    
		    if(n%i == 0)
		    {
		    	break;
			}
	    }
	    if(i>k)
	    {
	    	count++;//������������� 
	    	printf ("%d\t",n);
	    	if(count%5 == 0)
	    	printf ("\n");
		}	   
	    n++;
	}	
	return 0;
}


