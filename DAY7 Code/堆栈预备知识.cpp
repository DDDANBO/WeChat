//有人给出了堆栈用数组实现的另一种方式，即直接在函数参数中传递数组和top变量（而不是两者组成的结构指针）
//其中Push操作函数设计如下。这个Push函数正确吗？为什么？
#define MaxSize 100
ElementType S[MaxSize];
int top;
void Push(ElementType *S, int top, ElementType item)
{
	if (top==MaxSize-1)
	{
		printf(“堆栈满”);
		return;
	}
	else
	{
		S[++top] = item;
		return;
	}
}
/*函数不正确，因为top是局部变量，离开函数就消失了，top并不能真正的++。
解决方法：
1.将top转换成引用型变量（C++）
2.将top变量的地址读入，值传递转换成地址传递，从而使对top的操作成真。*/
 
//下面给出方法1代码(C++)：
#define MaxSize 100
ElementType S[MaxSize];
int top;
void Push(ElementType *S, int &top, ElementType item) //定义函数参数时间，将top转换成引用型变量，相当于给top取了个外号，对外号操作也就是对top操作。
{
	if (top==MaxSize-1)
	{
		printf(“堆栈满”);
		return;
	}
	else
	{
		S[++top] = item;
		return;
	}
}

//有个小建议，top要初始化为-1，不然在top默认初始化为0的情况下，栈的第一个元素所在空间会被浪费

/*可以取地址或者使用静态本地变量，将形式参数top去掉（初始化是一方面，我要说的问题是，最好不要用全局变量，
这是不安全的（翁凯老师在C语言中讲过），可以返回top再赋给top用以改进。）*/ 
