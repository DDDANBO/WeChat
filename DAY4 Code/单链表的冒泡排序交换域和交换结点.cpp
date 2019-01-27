#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<algorithm>
using namespace std;
typedef int Elemtype;

//链式结构，我们打算在链表中添加一个
//保存长度的头结点，加入这个结点可以方便我们对结点做一些
//基本的操作，结点保存的是线性表的长度
struct Node
{
    //结点的值,如果是头结点，保存是链表的长度
    Elemtype value;
    //下一个结点的地址
    Node * next;

};

//创建一个空链表，每个头结点就代表一个链表
void InitList(Node * & head) {
    head = new Node();
    head->value = 0;
    head->next = NULL;
}
//销毁一个链表
void DestroyList(Node * & head) {
    delete head;
    head = NULL;
}

//清空整个列表
void ClearList(Node * & head) {
    head->value = 0;
    head->next = NULL;
}

//插入函数
bool Listinsert(Node * & head, int i, Elemtype value) {

    //插入到前面的方法
    int j = 0;
    Node * L = head;
    //如果插入的位置不合法，直接返回错误提示
    if (i<1 || i>head->value + 1)return false;

    //得到插入位置的前一个结点
    while (j < i - 1) {
        L = L->next;
        ++j;
    }

    //s是一个临时结点
    Node * s = new Node();
    s->value = value;    //先对临时结点赋值
    s->next = L->next;   //让临时结点下一个位置指向当前需要插入前一个结点的下一个位置
    L->next = s;          //让前一个结点下一个位置指向临时结点，完成
                          //线性表的长度加一
    ++head->value;
    return true;
}
//得到某个位置上的值
Node * getitem(Node * & head, int i) {
    //我们要求程序返回特定位置上的值
    //我们一样是从头结点开始寻找该位置
    int j = 0;
    Node * L = head;
    //想要的那个位置是否合法
    if (i<1 || i >head->value)return NULL;

    //同样是先得到前一个结点
    while (j < i - 1) {
        L = L->next;
        ++j;
    }
    //value = L->next->value;
    return L;
}
//线性表的排序,采用冒泡排序,直接遍历链表
void Listsort(Node* & head) {
    int i = 0;
    int j = 0;
    //用于变量链表
    Node * L = head;
    //作为一个临时量
    Node * p;
    Node * p1;
    //如果链表为空直接返回
    if (head->value == 0)return;

    for (i = 0; i < head->value - 1; i++) {
        L = head->next;
        for (j = 0; j < head->value - i - 1; j++) {
            //得到两个值
            p = L;
            p1 = L->next;
            //如果前面的那个比后面的那个大，就交换它们之间的是数据域
            if (p->value > p1->value) {
                Elemtype temp = p->value;
                p->value = p1->value;
                p1->value = temp;
            }
            L = L->next;
        }
    }
}
//通过数组来完成我的排序
void Listsort_by_array(Node* & head) {
    int i = 0;
    int j = 0;
    //用于变量链表
    Node * L = head;
    //如果链表为空直接返回
    if (head->value == 0)return;
    Elemtype * copy = new Elemtype[head->value];
    //变量链表，存放数组
    for (i = 0; i < head->value; i++) {
        L = L->next;
        copy[i] = L->value;
    }
    //调用STL中的sort函数
    sort(copy, copy + head->value);
    L = head;
    //存放回链表中
    for (i = 0; i < head->value; i++) {
        L = L->next;
        L->value = copy[i];
    }
}

//参数为头结点和需要交换的两个结点的位置（起点为1）
void swap_node(Node * & head,int i,int j) {
    //位置不合法
    if (i<1 || j<1 || i>head->value || j >head->value) {
        cout << "请检查位置是否合法" << endl;
        return;
    }
    //同一个位置不用交换
    if (i == j)
    {
        return;
    }
    //相邻两个交换比较简单
    if (abs(i - j) == 1) {
        //位置靠前的那个结点的前一个结点
        Node * pre;
        if (i < j)
            pre = getitem(head, i);
        else
            pre = getitem(head, j);

        //保存第一个结点
        Node * a = pre->next;
        //保存第二结点
        Node * b = a->next;
        //改变pre下一个结点的值
        pre->next = b;
        //必须先把b的下一个结点值给a先
        a->next = b->next;
        //让b的下一个结点等于a
        b->next = a;
        return;
    }

    //第一个结点前一个结点
    Node * a = getitem(head, i);
    //第二个结点的前一个结点
    Node * b = getitem(head, j);
    //第一个结点
    Node * p = a->next;
    //第二个结点
    Node * q = b->next;
    //第一个结点的下一个结点
    Node * p_next = p->next;
    //第二结点的下一个结点
    Node * q_next = q->next;

    //a的下一个结点指向第二个结点q
    a->next = q;
    //第二结点的下一个结点指向第一个结点的下一个结点
    q->next = p_next;
    //b的下一个结点指向第一个结点p
    b->next = p;
    //第一个结点的下一个结点指向第二个结点的下一个结点
    p->next = q_next;

}
//反转
void rollback(Node * & head) {
    //先知道了最后一个元素和第一个元素的位置
    int end = head->value;
    int start = 1;
    //两边同时开工
    //进行调换
    while (1) {
        if (end <= start)
            return;
        swap_node(head, end, start);
        --end;
        ++start;
    }
}
void print(Node * & head);
//线性表的排序,采用冒泡排序,直接遍历链表
//线性表的排序，交换结点
void Listsort_node(Node* & head) {
    int i = 0;
    int j = 0;
    //用于变量链表
    Node * L = head;
    //作为一个临时量
    Node * p;
    Node * p1;
    //如果链表为空直接返回
    if (head->value == 0)return;
    int flag = 0;

    for (i = 0; i < head->value - 1; i++) {
        L = head->next;
        for (j = 0; j < head->value - 1 - i; j++) {
            //如果我们交换了结点，那么我们就已经在交换结点的时候，把L移动到下一个结点了，所以不要
            //再执行：L = L->next;，否则会报错的
            if (L->value > L->next->value) {
                flag = 1;
                swap_node(head, j + 1, j + 2);

            }
            if (flag == 1) {
                flag = 0;
            }
            else {
                L = L->next;
            }

        }   
    }
}

void print(Node * & head) {
    //输出我们只需要传入头结点，然后循环判断当前结点下一个结点是否为空，
    //这样就可以输出所有内容
    Node * L = head;
    while (L->next) {
        L = L->next;
        cout << L->value << " ";
    }
    cout << endl;
}
int main() {
    //链表的头结点，不存放任何值，首先初始化头结点
    Node * head;

    Node * head_array;
    Node * head_node;
    Node * head_roll;
    srand((int)time(NULL));     //每次执行种子不同，生成不同的随机数
    //创建一个链表

    InitList(head); 
    InitList(head_array);
    InitList(head_node);
    InitList(head_roll);

    int i;
    cout << "请输入需要插入元素个数" << endl;
    int n;
    cin >> n;//5
    //cout << "请输入" << n << "个值" << endl;
    for (i = 0; i < n; i++) {
        Elemtype temp;
        temp = rand();
        if (!Listinsert(head, i + 1, temp)) {
            cout << "插入元素失败" << endl;
        }
        if (!Listinsert(head_array, i + 1, temp)) {
            cout << "插入元素失败" << endl;
        }
        if (!Listinsert(head_node, i + 1, temp)) {
            cout << "插入元素失败" << endl;
        }
        if (!Listinsert(head_roll, i + 1, temp)) {
            cout << "插入元素失败" << endl;
        }

    }
    cout << "初始化结果" << endl;
    print(head);
    cout << "反转结果" << endl;
    rollback(head_roll);
    print(head_roll);
    cout << "冒泡排序（数据域交换）" << endl;
    Listsort(head);
    print(head);
    cout << "借数组为媒介进行排序（数据域交换）" << endl;
    Listsort_by_array(head_array);
    print(head_array);
    cout << "冒泡排序（结点交换）" << endl;
    Listsort_node(head_node);
    print(head_node);
    system("pause");
    return 0;

}
