typedef struct node *link
�ͱ�ʾ�� link ���� struct node *
Ҳ���Ǳ���Ҫ����������µ�
struct node * p;
����д��
link p;

struct node {}�ṹ��,
typedef struct node *link�������ͺ������,
struct node * == link,���link p;
�൱��struct node * p������һ��node�ڵ��ָ��

typedef struct node
{
	int data;
	struct node *next;
} Node,*LinkList;
���Ƕ���һ���ṹ�壬����ṹ�����������ԣ�һ����int���͵�data;
��һ��������ṹ�屾�����͵�ָ��next;
������ṹ������һ������:Node��
һ��ָ�����:LinkList;
Node a;�ȼ��� struct node a;
��������һ��struct node�ṹ�����͵Ľṹ����� a;
LinkList b;�ȼ��� struct node *b;�ȼ��� Node *b;
����һ��struct node�ṹ�����͵�ָ����� b; 

