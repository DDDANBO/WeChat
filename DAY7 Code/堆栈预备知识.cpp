//���˸����˶�ջ������ʵ�ֵ���һ�ַ�ʽ����ֱ���ں��������д��������top������������������ɵĽṹָ�룩
//����Push��������������¡����Push������ȷ��Ϊʲô��
#define MaxSize 100
ElementType S[MaxSize];
int top;
void Push(ElementType *S, int top, ElementType item)
{
	if (top==MaxSize-1)
	{
		printf(����ջ����);
		return;
	}
	else
	{
		S[++top] = item;
		return;
	}
}
/*��������ȷ����Ϊtop�Ǿֲ��������뿪��������ʧ�ˣ�top������������++��
���������
1.��topת���������ͱ�����C++��
2.��top�����ĵ�ַ���룬ֵ����ת���ɵ�ַ���ݣ��Ӷ�ʹ��top�Ĳ������档*/
 
//�����������1����(C++)��
#define MaxSize 100
ElementType S[MaxSize];
int top;
void Push(ElementType *S, int &top, ElementType item) //���庯������ʱ�䣬��topת���������ͱ������൱�ڸ�topȡ�˸���ţ�����Ų���Ҳ���Ƕ�top������
{
	if (top==MaxSize-1)
	{
		printf(����ջ����);
		return;
	}
	else
	{
		S[++top] = item;
		return;
	}
}

//�и�С���飬topҪ��ʼ��Ϊ-1����Ȼ��topĬ�ϳ�ʼ��Ϊ0������£�ջ�ĵ�һ��Ԫ�����ڿռ�ᱻ�˷�

/*����ȡ��ַ����ʹ�þ�̬���ر���������ʽ����topȥ������ʼ����һ���棬��Ҫ˵�������ǣ���ò�Ҫ��ȫ�ֱ�����
���ǲ���ȫ�ģ��̿���ʦ��C�����н����������Է���top�ٸ���top���ԸĽ�����*/ 
