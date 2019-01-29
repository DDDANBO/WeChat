typedef struct node *link
就表示用 link 代替 struct node *
也就是本来要定义变量如下的
struct node * p;
可以写成
link p;

struct node {}结构体,
typedef struct node *link这样看就很清楚了,
struct node * == link,如果link p;
相当于struct node * p定义了一个node节点的指针

typedef struct node
{
	int data;
	struct node *next;
} Node,*LinkList;
这是定义一个结构体，这个结构体有两个属性，一个是int类型的data;
另一个是这个结构体本身类型的指针next;
给这个结构定义了一个别名:Node，
一个指针别名:LinkList;
Node a;等价于 struct node a;
都是声明一个struct node结构体类型的结构体变量 a;
LinkList b;等价于 struct node *b;等价于 Node *b;
声明一个struct node结构体类型的指针变量 b; 

