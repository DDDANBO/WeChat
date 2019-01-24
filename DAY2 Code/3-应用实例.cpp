//给定N个整数的序列{ A1, A2, …, AN}，求函数的最大值。
//f(i,j) = max {0,求和k = i至j Ak}

算法1  T( N ) = O( N^3 )
int MaxSubseqSum1( int A[], int N ) {
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for( i = 0; i < N; i++ ) { /* i是子列左端位置*/
		for( j = i; j < N; j++ ) { /* j是子列右端位置*/
			ThisSum = 0; /* ThisSum是从A[i]到A[j]的子列和*/
			for( k = i; k <= j; k++ )
				ThisSum += A[k];
			if( ThisSum > MaxSum ) /* 如果刚得到的这个子列和更大*/
				MaxSum = ThisSum; /* 则更新结果*/
		} /* j循环结束*/
	} /* i循环结束*/
	return MaxSum;
}

算法2 T( N ) = O( N2 )
int MaxSubseqSum2( int A[], int N ) {
	int ThisSum, MaxSum = 0;
	int i, j;
	for( i = 0; i < N; i++ ) { /* i是子列左端位置*/
		ThisSum = 0; /* ThisSum是从A[i]到A[j]的子列和*/
		for( j = i; j < N; j++ ) { /* j是子列右端位置*/
			ThisSum += A[j];
			/*对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可*/
			if( ThisSum > MaxSum ) /* 如果刚得到的这个子列和更大*/
				MaxSum = ThisSum; /* 则更新结果*/
		} /* j循环结束*/
	} /* i循环结束*/
	return MaxSum;
}

算法3：分而治之
T ( N ) = 2 T( N/2 ) + c N, T(1) = O(1)
= 2 [2 T( N/2^2 ) + c N/2] + c N
= 2^k O(1) + c k N 其中N/2^k = 1
= O( N log N )

算法4：在线处理  T( N ) = O( N)
int MaxSubseqSum4( int A[], int N ) {
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for( i = 0; i < N; i++ ) {
		ThisSum += A[i]; /* 向右累加*/
		if( ThisSum > MaxSum )
			MaxSum = ThisSum; /* 发现更大和则更新当前结果*/
		else if( ThisSum < 0 ) /* 如果当前子列和为负*/
			ThisSum = 0; /* 则不可能使后面的部分和增大，抛弃之*/
	}
	return MaxSum;
}
“在线”的意思是指每输入一个数据就进行即时处理，在任
何一个地方中止输入，算法都能正确给出当前的解。









