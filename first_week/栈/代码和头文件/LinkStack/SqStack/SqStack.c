#include"SqStack.h"

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
        s->elem=( ElemType * )malloc( sizes * sizeof(ElemType));
        if(NULL==s->elem)
            return ERROR;
        s->top = -1;
        s->size = sizes;
        printf("初始化成功\n");
        return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //判断栈是否为空
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

Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
    if(isEmptyStack(s)||s->elem[s->top])
    {
        printf("栈未赋值，无栈顶\n");
        return ERROR;
    }
    else
        e=s->elem;
    printf("栈顶元素为%d\n",*e);
    return SUCCESS;
}
Status clearStack(SqStack *s)   //清空栈
{
    if(isEmptyStack(s)||s==NULL)
    {
        printf("该栈为空\n");
        return ERROR;
    }
    free(s->elem);
    s->elem=( ElemType * )malloc( s->size * sizeof(ElemType));
    s->top=-1;
    printf("清空成功\n");
}
Status destroyStack(SqStack *s)  //销毁栈
{
    free(s->elem);
    free(s);
    printf("销毁成功\n");
    exit(0);
}
Status stackLength(SqStack *s,int *length)   //检测栈长度
{
    if(s==NULL)
        return ERROR;
    length=&s->top;
    printf("栈的长度为%d\n",*length+1);
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //入栈
{
    if(s==NULL||s->top>=s->size-1)
    {
        printf("栈已满，入栈失败\n");
        return ERROR;
    }
    s->top++;
    s->elem[s->top]=data;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //出栈
{
    if(s==NULL||isEmptyStack(s))
    {
        printf("栈为空，无法出栈\n");
        return 0;
    }
    *data=s->elem[s->top];
    s->top--;
    return SUCCESS;
}

void  choose(SqStack *s)
{
    int sizes;
    printf("请输入你要初始化栈的大小\n");
    sizes=inputError(sizes);
    initStack(s,sizes);
    int a=1;
    while(a==1)
    {
        int n;
        printf("请输入你的选择\n");
        n=inputError(n);
        if(n==6)
        {
            int data;
            printf("请输入要入栈的元素\n");
            data=inputError(data);
            pushStack(s,data);
        }
        else if(n==7)
        {
            int data;
            if(popStack(s,&data))
            printf("出栈的元素为%d\n",data);
        }
        else if(n==1)
        {
            if(isEmptyStack(s))
                printf("该栈为空\n");
            else printf("该栈不为空\n");
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
            printf("输入错误\n");
        printf("请选择是否继续，1.yes\\2.no\n");
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
		printf("\n输入错误，请重新输入！\n");
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
    printf("*\t\t\t\t-\t1:判断是否为空\t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t2:得到栈顶元素\t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t3:清空栈      \t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t4:销毁栈      \t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t5:检测栈的长度\t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t6:入栈        \t-\t\t\t\t*\n");
    printf("*\t\t\t\t-\t7:出栈        \t-\t\t\t\t*\n");
    printf("*****************************************************************************************\n");
}
