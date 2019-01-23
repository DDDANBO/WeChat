/*最小公倍数等于两个数值的乘积除以这两个数值的最大公约数。

1、辗转相除法的核心就是不断的让两个数做除法运算。
其原理基于两个整数的最大公约数等于其中较小的数和两数的相除余数的最大公约数。

假设两数为 x，y。
先令 z = x % y ;
之后 y 赋给 x 即令 x = y;
再将 z 赋给 y 即令 y = z;
辗转相除,其终止条件为：y 等于0时。
#include<stdio.h>
int main() 
{
	int x, y, z, m, n;
	printf("请输入两个数：");
	scanf("%d%d", &x, &y);
	m = x;
	n = y;
	while (y != 0) 
	{
		z = x%y;
		x = y;
		y = z;
	}
	printf("最大公约数是: %d\n", x);
	printf("最小公倍数是: %d\n", m*n / x);
	return 0;
}*/


/*2、 辗转相减法即通过对两数的不断减法运算。
假设两数为 x, y。
当 x > y 时，令 x = x - y;
反之，则令 y = y - x;
之后一直辗转相减，直至 x = y 时，终止。
#include<stdio.h>
int main() 
{
	int x, y, m, n;
	printf("请输入两个数：");
	scanf("%d%d", &x, &y);
	m = x;
	n = y;
	while (x!=y) 
	{
		if (x>y)
			x = x-y;
		else
			y = y-x;
	}
	printf("最大公约数是: %d\n", x);
	printf("最小公倍数是: %d\n", m*n / x);
	return 0;
}*/

/*3、 穷举法的基本思想是根据题目的部分条件确定答案的大致范围，并
在此范围内对所有可能的情况逐一验证，直到全部情况验证完毕。
穷举法又称枚举法，通过对数值范围内的所有数字进行检验，得出其结果。
#include<stdio.h>
int main() 
{
	int x, y, i, m, n;
	printf("请输入两个数：");
	scanf("%d%d", &x, &y);
	m = x;
	n = y;
	for (i = 1; i <= x; i++) 
	{
		if (x%i == 0 && y%i == 0)
			break;
	}
	for (i = x; i > 0; i--) 
	{
		if (x%i == 0 && y%i == 0)
			break;
	}
	printf("最大公约数是: %d\n", i);
	printf("最小公倍数是: %d\n", m*n / i);
	return 0;
}*/
