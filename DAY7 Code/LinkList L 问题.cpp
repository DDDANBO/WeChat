/*LinkList *L ， LinkList *&L 和 LinkList &*L 的区别
时间  2014-10-07
原文   http://blog.csdn.net/u013539441/article/details/39859741*/
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
} LinkList;

void update_1(LinkList *L1)
{
	L1 = (LinkList *)malloc(sizeof(LinkList));
	L1->data = 1;
}

void update_2(LinkList *&L2)
{
	L2 = (LinkList *)malloc(sizeof(LinkList));
	L2->data = 1;
}

int main()
{
	LinkList *L;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->data = 2;
	printf("%d\n", L->data);
	update_1(L);
	printf("%d\n", L->data);
	update_2(L);
	printf("%d\n", L->data);
	return 0;
}

/*
输出结果：
2
2
1
*/



/*在函数update_1 和 update_2里面我们都给传入的指针变量分配了一个新的内存，然后再将数据域的值赋值为1，但是我们发现，当函数结束之后，update_1没有改变传入指针L对应的L->data 的值，而update_2改变了L->data 的值，为什么呢？

原因很简单，因为 LinList *&L 相当于 linkList* &L，就是说，L就是传入指针的别名。

一般来说，每一个变量都有一个自己的地址，指针变量也不例外，所谓变量的别名，就是指，一个变量和一个变量的别名所指向的地址是相同的，就好比一个人可以有多个外号（别名），不同的人以不同的方式来称呼你，但是这些称呼所指向的都是同一个人，就是你自己。
所以update_2 里L2本身的地址，实际上就是L本身所对应的地址，然后，既然他们是同一个“人”，那么他们所指向的地址当然也是相同的，这里要注意一下，指针变量本身的地址和他们所指向地址的意义。

那么，对于update_1中的LinList *L来说，只是单纯的将传入指针L的指向地址赋予L1这个临时指针的指向地址，就好比你知道某个mm的电话号码，然后你把他的电话号码告诉了另一个人，然后你们都知道她的电话号码了，但是你们两个人还是独立的，不能说你把电话号码给了他，他就会变成你。

所以，如果只是单纯的改变指针指向地址的内容的话，那么两者是等效的，如果涉及到改变指针本身地址的时候，那么两者就不能等同起来了，前者可以改变传入指针本身，而后者改变的只是临时变量而已。

下面来说说LinkList &*L，这会肯定有人已经写了一个函数试着运行了，发现LinkList &*L会报错，为什么呢？原因很简单，LinkList &*L3我们分开来看，LinkList &(*L3)，那么我们就会发现，我们定义了一个LinkList& 型的类型，他的地址为（*L），显然不靠谱嘛，哪来的LinkList &类型啊=，=
到这里还没完..其实如果是单独&*L3的话（假设现在L3是一个LinkList* 类型的变量），还是有意义的，根据运算符的运算顺序，&（*L3），我们先*L3取到了L3地址所在的值，然后我们再对这个值进行取址，也就是&（*L3），那么我们由会获得他本来的地址了。嗯，有点绕，好好想想还是会明白的。
*/
