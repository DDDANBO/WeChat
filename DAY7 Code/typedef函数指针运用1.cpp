//typedef给变量类型定义一个别名.
typedef struct
{
	int a;
	int b;
} MY_TYPE;
/*这里把一个未命名结构直接取了一个叫MY_TYPE的别名, 这样如果你想定义结构的实例的时候就可以这样:
MY_TYPE tmp;*/ 

//第二种用法：typedef 原变量类型 别名
//简单的函数指针的用法
//形式1：返回类型（*函数名）（参数表列）
char(*pFun)(int);
char glFun(int a)
{
	switch (a)
	{
		case 1:
			return 'A';
		default:
			return 'E';
	}
}
void main()
{
	pFun =glFun;
	printf("---------- %c \n",  (*pFun)(2));
}
//第一行定义了一个指针变量pFun.它是一个指向某种函数的指针，这种函数参数是一个int类型，返回值是char类型。只有第一句我们还无法使用这个指针，因为我们还未对它进行赋值。
//第二行定义了一个函数glFun().该函数正好是一个以int为参数返回char的函数。我们要从指针的层次上理解函数-函数的函数名实际上就是一个指针，函数名指向该函数的代码在内存中的首地址。
