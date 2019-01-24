//�ݹ��ӡ
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

//д��������������ʽ�ڸ�����x����ֵ
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

clock()����׽�ӳ���ʼ���е�clock()������ʱ���ķѵ�ʱ�䡣���
ʱ�䵥λ��clock tick������ʱ�Ӵ�㡱��
����CLK_TCK(��CLOCKS_PER_SEC)������ʱ��ÿ�����ߵ�ʱ�Ӵ������

#include <stdio.h>
#include <time.h>
clock_t start, stop;
/* clock_t��clock()�������صı�������*/
double duration;
/* ��¼���⺯������ʱ�䣬����Ϊ��λ*/
int main () {
	/* ���ڲ��Է�Χ�ڵ�׼������д��clock()����֮ǰ*/
	start = clock();/* ��ʼ��ʱ*/
	MyFunction();   /* �ѱ��⺯����������*/
	stop = clock(); /* ֹͣ��ʱ*/
	duration = ((double)(stop - start))/CLK_TCK;
	/* ��������ʱ��*/
	/* �������ڲ��Է�Χ�Ĵ���д�ں��棬�������duration��ֵ*/
	return 0;
}


//д��������������ʽ�ڸ�����x = 1.1 ����ֵf(1.1)
//f(x) = ���i = 0��9 i*x^i  ��  //f(x) = a0 + x(a1 + x(...(a(n-1) + x(an))...))
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
#define MAXN 10 /* ����ʽ���������������ʽ����+1 */
double f1( int n, double a[], double x );
double f2( int n, double a[], double x );

int main () {
	int i;
	double a[MAXN]; /* �洢����ʽ��ϵ��*/
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


//�ñ��⺯���ظ����г�ֶ�Σ�ʹ�ò�����ܵ�ʱ�Ӵ��
//�����ֳ��������㱻�⺯��ƽ��ÿ�����е�ʱ�伴��!
#include <stdio.h>
#include <time.h>
#include <math.h>
....
#define MAXK 1e7 /* ���⺯������ظ����ô���*/
....
int main () {
	....
	
	start = clock();
	for ( i=0; i<MAXK; i++ ) /* �ظ����ú����Ի�ó�ֶ��ʱ�Ӵ����*/
		f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK; /* ���㺯���������е�ʱ��*/
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
#define MAXK 1e7 // ���⺯������ظ����ô���
double f1( int n, double a[], double x );
double f2( int n, double a[], double x );
int main () 
{
	int i;
	double a[MAXN]; // �洢����ʽ��ϵ��
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i;
	
	start = clock();
	for ( i=0; i<MAXK; i++ ) // �ظ����ú����Ի�ó�ֶ��ʱ�Ӵ����
		f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK; // ���㺯���������е�ʱ��
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

��4�������󡱵ĳ����������Ͷ���
. �������ƣ�����Matrix��
. ���ݶ��󼯣�һ��M*N�ľ���AM*N = (aij) (i=1, ��, M; j=1, ��, N )��M*N����
Ԫ��< a, i, j >���ɣ�����a�Ǿ���Ԫ�ص�ֵ��i��Ԫ�����ڵ��кţ�j��Ԫ��
���ڵ��кš�
. �������������������A��B��C . Matrix���Լ�����i��j��M��N
. Matrix Create( int M, int N )������һ��M*N�Ŀվ���
. int GetMaxRow( Matrix A )�����ؾ���A����������
. int GetMaxCol( Matrix A )�����ؾ���A����������
. ElementType GetEntry( Matrix A, int i, int j )�����ؾ�
��A�ĵ�i�С���j�е�Ԫ�أ�
. Matrix Add( Matrix A, Matrix B )�����A��B���С�����һ
�£��򷵻ؾ���C=A+B�����򷵻ش����־��
. Matrix Multiply( Matrix A, Matrix B )�����A����������B
���������򷵻ؾ���C=AB�����򷵻ش����־��
. ����




