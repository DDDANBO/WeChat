//����N������������{ A1, A2, ��, AN}�����������ֵ��
//f(i,j) = max {0,���k = i��j Ak}

�㷨1  T( N ) = O( N^3 )
int MaxSubseqSum1( int A[], int N ) {
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for( i = 0; i < N; i++ ) { /* i���������λ��*/
		for( j = i; j < N; j++ ) { /* j�������Ҷ�λ��*/
			ThisSum = 0; /* ThisSum�Ǵ�A[i]��A[j]�����к�*/
			for( k = i; k <= j; k++ )
				ThisSum += A[k];
			if( ThisSum > MaxSum ) /* ����յõ���������к͸���*/
				MaxSum = ThisSum; /* ����½��*/
		} /* jѭ������*/
	} /* iѭ������*/
	return MaxSum;
}

�㷨2 T( N ) = O( N2 )
int MaxSubseqSum2( int A[], int N ) {
	int ThisSum, MaxSum = 0;
	int i, j;
	for( i = 0; i < N; i++ ) { /* i���������λ��*/
		ThisSum = 0; /* ThisSum�Ǵ�A[i]��A[j]�����к�*/
		for( j = i; j < N; j++ ) { /* j�������Ҷ�λ��*/
			ThisSum += A[j];
			/*������ͬ��i����ͬ��j��ֻҪ��j-1��ѭ���Ļ������ۼ�1���*/
			if( ThisSum > MaxSum ) /* ����յõ���������к͸���*/
				MaxSum = ThisSum; /* ����½��*/
		} /* jѭ������*/
	} /* iѭ������*/
	return MaxSum;
}

�㷨3���ֶ���֮
T ( N ) = 2 T( N/2 ) + c N, T(1) = O(1)
= 2 [2 T( N/2^2 ) + c N/2] + c N
= 2^k O(1) + c k N ����N/2^k = 1
= O( N log N )

�㷨4�����ߴ���  T( N ) = O( N)
int MaxSubseqSum4( int A[], int N ) {
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for( i = 0; i < N; i++ ) {
		ThisSum += A[i]; /* �����ۼ�*/
		if( ThisSum > MaxSum )
			MaxSum = ThisSum; /* ���ָ��������µ�ǰ���*/
		else if( ThisSum < 0 ) /* �����ǰ���к�Ϊ��*/
			ThisSum = 0; /* �򲻿���ʹ����Ĳ��ֺ���������֮*/
	}
	return MaxSum;
}
�����ߡ�����˼��ָÿ����һ�����ݾͽ��м�ʱ��������
��һ���ط���ֹ���룬�㷨������ȷ������ǰ�Ľ⡣









