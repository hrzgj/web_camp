#include"SqStack.h"

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
        s->elem=( ElemType * )malloc( sizes * sizeof(ElemType));
        if(NULL==s->elem)
            return ERROR;
        s->top = -1;
        s->size = sizes;
        printf("��ʼ���ɹ�\n");
        return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
    if(s->top<0)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
    if(isEmptyStack(s)||s->elem[s->top])
    {
        printf("ջδ��ֵ����ջ��\n");
        return ERROR;
    }
    else
        e=s->elem;
    printf("ջ��Ԫ��Ϊ%d\n",*e);
    return SUCCESS;
}
Status clearStack(SqStack *s)   //���ջ
{
    if(isEmptyStack(s)||s==NULL)
    {
        printf("��ջΪ��\n");
        return ERROR;
    }
    free(s->elem);
    s->elem=( ElemType * )malloc( s->size * sizeof(ElemType));
    s->top=-1;
    printf("��ճɹ�\n");
}
Status destroyStack(SqStack *s)  //����ջ
{
    free(s->elem);
    free(s);
    printf("���ٳɹ�\n");
    exit(0);
}
Status stackLength(SqStack *s,int *length)   //���ջ����
{
    if(s==NULL)
        return ERROR;
    length=&s->top;
    printf("ջ�ĳ���Ϊ%d\n",*length+1);
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //��ջ
{
    if(s==NULL||s->top>=s->size-1)
    {
        printf("ջ��������ջʧ��\n");
        return ERROR;
    }
    s->top++;
    s->elem[s->top]=data;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //��ջ
{
    if(s==NULL||isEmptyStack(s))
    {
        printf("ջΪ�գ��޷���ջ\n");
        return 0;
    }
    *data=s->elem[s->top];
    s->top--;
    return SUCCESS;
}

void  choose(SqStack *s)
{
    int sizes;
    printf("��������Ҫ��ʼ��ջ�Ĵ�С\n");
    sizes=inputError(sizes);
    initStack(s,sizes);
    int a=1;
    while(a==1)
    {
        int n;
        printf("���������ѡ��\n");
        n=inputError(n);
        if(n==6)
        {
            int data;
            printf("������Ҫ��ջ��Ԫ��\n");
            data=inputError(data);
            pushStack(s,data);
        }
        else if(n==7)
        {
            int data;
            if(popStack(s,&data))
            printf("��ջ��Ԫ��Ϊ%d\n",data);
        }
        else if(n==1)
        {
            if(isEmptyStack(s))
                printf("��ջΪ��\n");
            else printf("��ջ��Ϊ��\n");
        }
        else if(n==2)
        {
            int *data;
            getTopStack(s,data);
        }
        else if(n==3)
        {
            clearStack(s);
        }
        else if(n==4)
            destroyStack(s);
        else if(n==5)
        {
            int *length;
            stackLength(s,length);
        }
        else
            printf("�������\n");
        printf("��ѡ���Ƿ������1.yes\\2.no\n");
        a=inputError(a);
    }
}

int inputError(int val)
{
	char n[20];
	int i = 0;
	val = 0;
	scanf("%s", n);
	getchar();
	while (n[0]<'0' || n[0]>'9')
	{
		printf("\n����������������룡\n");
		scanf("%s", n);
		getchar();
	}
	while (n[i] >= '0'&&n[i] <= '9')
	{
		val = (val * 10 + (int)n[i] - 48);
		i++;
	}
	return val;
}


void memu()
{
    printf("*****************************************************************************************\n");
    printf("*\t\t\t\t-\t1:�ж��Ƿ�Ϊ��\t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t2:�õ�ջ��Ԫ��\t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t3:���ջ      \t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t4:����ջ      \t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t5:���ջ�ĳ���\t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t6:��ջ        \t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t7:��ջ        \t-\t\t\t\t*\n");
    printf("*****************************************************************************************\n");
}
