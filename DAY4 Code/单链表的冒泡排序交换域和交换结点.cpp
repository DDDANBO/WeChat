#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<algorithm>
using namespace std;
typedef int Elemtype;

//��ʽ�ṹ�����Ǵ��������������һ��
//���泤�ȵ�ͷ��㣬������������Է������ǶԽ����һЩ
//�����Ĳ�������㱣��������Ա�ĳ���
struct Node
{
    //����ֵ,�����ͷ��㣬����������ĳ���
    Elemtype value;
    //��һ�����ĵ�ַ
    Node * next;

};

//����һ��������ÿ��ͷ���ʹ���һ������
void InitList(Node * & head) {
    head = new Node();
    head->value = 0;
    head->next = NULL;
}
//����һ������
void DestroyList(Node * & head) {
    delete head;
    head = NULL;
}

//��������б�
void ClearList(Node * & head) {
    head->value = 0;
    head->next = NULL;
}

//���뺯��
bool Listinsert(Node * & head, int i, Elemtype value) {

    //���뵽ǰ��ķ���
    int j = 0;
    Node * L = head;
    //��������λ�ò��Ϸ���ֱ�ӷ��ش�����ʾ
    if (i<1 || i>head->value + 1)return false;

    //�õ�����λ�õ�ǰһ�����
    while (j < i - 1) {
        L = L->next;
        ++j;
    }

    //s��һ����ʱ���
    Node * s = new Node();
    s->value = value;    //�ȶ���ʱ��㸳ֵ
    s->next = L->next;   //����ʱ�����һ��λ��ָ��ǰ��Ҫ����ǰһ��������һ��λ��
    L->next = s;          //��ǰһ�������һ��λ��ָ����ʱ��㣬���
                          //���Ա�ĳ��ȼ�һ
    ++head->value;
    return true;
}
//�õ�ĳ��λ���ϵ�ֵ
Node * getitem(Node * & head, int i) {
    //����Ҫ����򷵻��ض�λ���ϵ�ֵ
    //����һ���Ǵ�ͷ��㿪ʼѰ�Ҹ�λ��
    int j = 0;
    Node * L = head;
    //��Ҫ���Ǹ�λ���Ƿ�Ϸ�
    if (i<1 || i >head->value)return NULL;

    //ͬ�����ȵõ�ǰһ�����
    while (j < i - 1) {
        L = L->next;
        ++j;
    }
    //value = L->next->value;
    return L;
}
//���Ա������,����ð������,ֱ�ӱ�������
void Listsort(Node* & head) {
    int i = 0;
    int j = 0;
    //���ڱ�������
    Node * L = head;
    //��Ϊһ����ʱ��
    Node * p;
    Node * p1;
    //�������Ϊ��ֱ�ӷ���
    if (head->value == 0)return;

    for (i = 0; i < head->value - 1; i++) {
        L = head->next;
        for (j = 0; j < head->value - i - 1; j++) {
            //�õ�����ֵ
            p = L;
            p1 = L->next;
            //���ǰ����Ǹ��Ⱥ�����Ǹ��󣬾ͽ�������֮�����������
            if (p->value > p1->value) {
                Elemtype temp = p->value;
                p->value = p1->value;
                p1->value = temp;
            }
            L = L->next;
        }
    }
}
//ͨ������������ҵ�����
void Listsort_by_array(Node* & head) {
    int i = 0;
    int j = 0;
    //���ڱ�������
    Node * L = head;
    //�������Ϊ��ֱ�ӷ���
    if (head->value == 0)return;
    Elemtype * copy = new Elemtype[head->value];
    //���������������
    for (i = 0; i < head->value; i++) {
        L = L->next;
        copy[i] = L->value;
    }
    //����STL�е�sort����
    sort(copy, copy + head->value);
    L = head;
    //��Ż�������
    for (i = 0; i < head->value; i++) {
        L = L->next;
        L->value = copy[i];
    }
}

//����Ϊͷ������Ҫ��������������λ�ã����Ϊ1��
void swap_node(Node * & head,int i,int j) {
    //λ�ò��Ϸ�
    if (i<1 || j<1 || i>head->value || j >head->value) {
        cout << "����λ���Ƿ�Ϸ�" << endl;
        return;
    }
    //ͬһ��λ�ò��ý���
    if (i == j)
    {
        return;
    }
    //�������������Ƚϼ�
    if (abs(i - j) == 1) {
        //λ�ÿ�ǰ���Ǹ�����ǰһ�����
        Node * pre;
        if (i < j)
            pre = getitem(head, i);
        else
            pre = getitem(head, j);

        //�����һ�����
        Node * a = pre->next;
        //����ڶ����
        Node * b = a->next;
        //�ı�pre��һ������ֵ
        pre->next = b;
        //�����Ȱ�b����һ�����ֵ��a��
        a->next = b->next;
        //��b����һ��������a
        b->next = a;
        return;
    }

    //��һ�����ǰһ�����
    Node * a = getitem(head, i);
    //�ڶ�������ǰһ�����
    Node * b = getitem(head, j);
    //��һ�����
    Node * p = a->next;
    //�ڶ������
    Node * q = b->next;
    //��һ��������һ�����
    Node * p_next = p->next;
    //�ڶ�������һ�����
    Node * q_next = q->next;

    //a����һ�����ָ��ڶ������q
    a->next = q;
    //�ڶ�������һ�����ָ���һ��������һ�����
    q->next = p_next;
    //b����һ�����ָ���һ�����p
    b->next = p;
    //��һ��������һ�����ָ��ڶ���������һ�����
    p->next = q_next;

}
//��ת
void rollback(Node * & head) {
    //��֪�������һ��Ԫ�غ͵�һ��Ԫ�ص�λ��
    int end = head->value;
    int start = 1;
    //����ͬʱ����
    //���е���
    while (1) {
        if (end <= start)
            return;
        swap_node(head, end, start);
        --end;
        ++start;
    }
}
void print(Node * & head);
//���Ա������,����ð������,ֱ�ӱ�������
//���Ա�����򣬽������
void Listsort_node(Node* & head) {
    int i = 0;
    int j = 0;
    //���ڱ�������
    Node * L = head;
    //��Ϊһ����ʱ��
    Node * p;
    Node * p1;
    //�������Ϊ��ֱ�ӷ���
    if (head->value == 0)return;
    int flag = 0;

    for (i = 0; i < head->value - 1; i++) {
        L = head->next;
        for (j = 0; j < head->value - 1 - i; j++) {
            //������ǽ����˽�㣬��ô���Ǿ��Ѿ��ڽ�������ʱ�򣬰�L�ƶ�����һ������ˣ����Բ�Ҫ
            //��ִ�У�L = L->next;������ᱨ���
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
    //�������ֻ��Ҫ����ͷ��㣬Ȼ��ѭ���жϵ�ǰ�����һ������Ƿ�Ϊ�գ�
    //�����Ϳ��������������
    Node * L = head;
    while (L->next) {
        L = L->next;
        cout << L->value << " ";
    }
    cout << endl;
}
int main() {
    //�����ͷ��㣬������κ�ֵ�����ȳ�ʼ��ͷ���
    Node * head;

    Node * head_array;
    Node * head_node;
    Node * head_roll;
    srand((int)time(NULL));     //ÿ��ִ�����Ӳ�ͬ�����ɲ�ͬ�������
    //����һ������

    InitList(head); 
    InitList(head_array);
    InitList(head_node);
    InitList(head_roll);

    int i;
    cout << "��������Ҫ����Ԫ�ظ���" << endl;
    int n;
    cin >> n;//5
    //cout << "������" << n << "��ֵ" << endl;
    for (i = 0; i < n; i++) {
        Elemtype temp;
        temp = rand();
        if (!Listinsert(head, i + 1, temp)) {
            cout << "����Ԫ��ʧ��" << endl;
        }
        if (!Listinsert(head_array, i + 1, temp)) {
            cout << "����Ԫ��ʧ��" << endl;
        }
        if (!Listinsert(head_node, i + 1, temp)) {
            cout << "����Ԫ��ʧ��" << endl;
        }
        if (!Listinsert(head_roll, i + 1, temp)) {
            cout << "����Ԫ��ʧ��" << endl;
        }

    }
    cout << "��ʼ�����" << endl;
    print(head);
    cout << "��ת���" << endl;
    rollback(head_roll);
    print(head_roll);
    cout << "ð�����������򽻻���" << endl;
    Listsort(head);
    print(head);
    cout << "������Ϊý��������������򽻻���" << endl;
    Listsort_by_array(head_array);
    print(head_array);
    cout << "ð�����򣨽�㽻����" << endl;
    Listsort_node(head_node);
    print(head_node);
    system("pause");
    return 0;

}
