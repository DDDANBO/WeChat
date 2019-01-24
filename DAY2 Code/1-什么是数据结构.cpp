//递归打印
#include <stdio.h>
void PrintN ( int N );
int main () {
	int N;
	scanf("%d", &N);
	PrintN( N );
	return 0;
}
void PrintN ( int N ) {
	if ( N ) {
		PrintN( N - 1 );
		printf("%d\n", N );
	}
	return;
}

//写程序计算给定多项式在给定点x处的值
//f(x) = a0 + a1*x + ... + a(n-1)*x^(n-1) + an*x^n
double f( int n, double a[], double x ) {
	int i;
	double p = a[0];
	for ( i=1; i<=n; i++ )
		p += (a[i] * pow(x, i));
	return p;
}

//f(x) = a0 + x(a1 + x(...(a(n-1) + x(an))...))
double f( int n, double a[], double x ) {
	int i;
	double p = a[n];
	for ( i=n; i>0; i-- )
		p = a[i-1] + x*p;
	return p;
}

clock()：捕捉从程序开始运行到clock()被调用时所耗费的时间。这个
时间单位是clock tick，即“时钟打点”。
常数CLK_TCK(或CLOCKS_PER_SEC)：机器时钟每秒所走的时钟打点数。

#include <stdio.h>
#include <time.h>
clock_t start, stop;
/* clock_t是clock()函数返回的变量类型*/
double duration;
/* 记录被测函数运行时间，以秒为单位*/
int main () {
	/* 不在测试范围内的准备工作写在clock()调用之前*/
	start = clock();/* 开始计时*/
	MyFunction();   /* 把被测函数加在这里*/
	stop = clock(); /* 停止计时*/
	duration = ((double)(stop - start))/CLK_TCK;
	/* 计算运行时间*/
	/* 其他不在测试范围的处理写在后面，例如输出duration的值*/
	return 0;
}


//写程序计算给定多项式在给定点x = 1.1 处的值f(1.1)
//f(x) = 求和i = 0至9 i*x^i  即  //f(x) = a0 + x(a1 + x(...(a(n-1) + x(an))...))
double f1( int n, double a[], double x ) {
	int i;
	double p = a[0];
	for ( i=1; i<=n; i++ )
		p += (a[i] * pow(x, i));
	return p;
}
double f2( int n, double a[], double x ) {
	int i;
	double p = a[n];
	for ( i=n; i>0; i-- )
		p = a[i-1] + x*p;
	return p;
}

#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start, stop;
double duration;
#define MAXN 10 /* 多项式最大项数，即多项式阶数+1 */
double f1( int n, double a[], double x );
double f2( int n, double a[], double x );

int main () {
	int i;
	double a[MAXN]; /* 存储多项式的系数*/
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i;

	start = clock();
	f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);

	start = clock();
	f2(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("duration2 = %6.2e\n", duration);

	return 0;
}


//让被测函数重复运行充分多次，使得测出的总的时钟打点
//间隔充分长，最后计算被测函数平均每次运行的时间即可!
#include <stdio.h>
#include <time.h>
#include <math.h>
....
#define MAXK 1e7 /* 被测函数最大重复调用次数*/
....
int main () {
	....
	
	start = clock();
	for ( i=0; i<MAXK; i++ ) /* 重复调用函数以获得充分多的时钟打点数*/
		f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK; /* 计算函数单次运行的时间*/
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);
	....
	return 0;
}

/*#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start, stop;
double duration;
#define MAXK 1e7 // 被测函数最大重复调用次数
double f1( int n, double a[], double x );
double f2( int n, double a[], double x );
int main () 
{
	int i;
	double a[MAXN]; // 存储多项式的系数
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i;
	
	start = clock();
	for ( i=0; i<MAXK; i++ ) // 重复调用函数以获得充分多的时钟打点数
		f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK; // 计算函数单次运行的时间
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);
	
	start = clock();
	for ( i=0; i<MAXK; i++ ) 
		f2(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK; 
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("duration2 = %6.2e\n", duration);
	
	return 0;
}
*/ 

例4：“矩阵”的抽象数据类型定义
. 类型名称：矩阵（Matrix）
. 数据对象集：一个M*N的矩阵AM*N = (aij) (i=1, …, M; j=1, …, N )由M*N个三
元组< a, i, j >构成，其中a是矩阵元素的值，i是元素所在的行号，j是元素
所在的列号。
. 操作集：对于任意矩阵A、B、C . Matrix，以及整数i、j、M、N
. Matrix Create( int M, int N )：返回一个M*N的空矩阵；
. int GetMaxRow( Matrix A )：返回矩阵A的总行数；
. int GetMaxCol( Matrix A )：返回矩阵A的总列数；
. ElementType GetEntry( Matrix A, int i, int j )：返回矩
阵A的第i行、第j列的元素；
. Matrix Add( Matrix A, Matrix B )：如果A和B的行、列数一
致，则返回矩阵C=A+B，否则返回错误标志；
. Matrix Multiply( Matrix A, Matrix B )：如果A的列数等于B
的行数，则返回矩阵C=AB，否则返回错误标志；
. ……




