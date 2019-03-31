#include"LinkStack.h"

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
    s->count = 0;
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(s->top == NULL)
    {
        printf("\t\t\t\t动态分配内存失败!\n");
        return ERROR;
    }
    else
    {
        s->top = NULL;
    }
    return SUCCESS;
}
Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
    if(s->count == 0)
    {
        printf("\t\t\t\t栈为空！\n");
        return SUCCESS;
    }
    return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
    if(isEmptyLStack(s))
        return ERROR;
    *e = s->top->data;
    return SUCCESS;
}
Status clearLStack(LinkStack *s)   //清空栈
{
    if(isEmptyLStack(s))
        return ERROR;
    LinkStackPtr p = s->top;
    while(p)
    {
        p->data = 0;
        p=p->next;
    }
    return SUCCESS;
}
Status destroyLStack(LinkStack *s)   //销毁栈
{
    if(isEmptyLStack(s))
        return ERROR;
    while(s->top != NULL)
    {
        LinkStackPtr p = s->top;
        s->top = s->top->next;
        free(p);
    }
    s->count = 0;
    return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
    if(isEmptyLStack(s))
        return ERROR;
    *length = s->count;
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if(p == NULL)
    {
        printf("\t\t\t\t动态分配内存失败!\n");
        return ERROR;
    }
    p->data = data;
    p->next = s->top;
    s->top = p;
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
    if(isEmptyLStack(s))
        return ERROR;
    *data = s->top->data;
    LinkStackPtr p = s->top;
    s->top = p->next;
    free(p);
    p = NULL;
    s->count--;
    return SUCCESS;
}

void userFace(LinkStack *s)//展示用户界面
{
    printf("\n\n*********************************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("********************************数 据 结 构 之 链 栈 程 序 设 计*****************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         1.  判断链栈是否为空        \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         2.  得到栈顶元素            \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         3.  清空栈                  \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         4.  销毁栈                  \t\t\t\t\t\t*\n");;
    printf("*\t\t\t\t         5.  检测栈长度              \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         6.  入栈                    \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         7.  出栈                    \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*********************************************************************************************************\n");
    selcetAction(s);
}

void selcetAction(LinkStack *s)//选择操作
{
    int n;
    printf("\n\n\t\t\t\t选择你想进行的操作：");
    inputCheck(&n);
    while( n < 1||n > 7 )
    {
        printf("\n\t\t\t\t输入错误！请重新输入:");
        inputCheck(&n);
    }
    switch(n)
    {
    case 1:
        {
            if(!isEmptyLStack(s))
                printf("\t\t\t\t栈不为空!\n");
            break;
        }
    case 2:
        {
            int val;
            if(getTopLStack(s, &val))
                printf("\t\t\t\t栈顶的元素是:%d", val);
			break;
        }
    case 3:
        {
            if(clearLStack(s))
                printf("\t\t\t\t清空成功！\n");
            else
                printf("\t\t\t\t清空失败！\n");
            break;
        }
    case 4:
        {
            if(destroyLStack(s))
                printf("\t\t\t\t销毁成功！\n");
            else
                printf("\t\t\t\t销毁失败！\n");
            break;
        }
    case 5:
        {
            int length;
            if(LStackLength(s, &length))
                printf("\t\t\t\t链栈的长度为：%d", length);
            break;
        }
    case 6:
        {
            int data;
            printf("\t\t\t\t输入你想入栈的元素:");
            inputCheck(&data);
            if(pushLStack(s, data))
                {
                    printf("\t\t\t\t入栈成功！\n");
                    s->count ++;
                }
            else
                printf("\t\t\t\t入栈失败！\n");
            break;
        }
    case 7:
        {
            int data;
            if(popLStack(s, &data))
                printf("\t\t\t\t出栈成功！出栈的元素为：%d\n", data);
            else
                printf("\t\t\t\t出栈失败！\n");
            break;
        }
    }
}

void inputCheck(int *val)  //检查输入
{
	char n[50]={0};
	int i = 0;
	*val = 0;
	scanf("%s", n);
	getchar();
    while(1)
    {
        if(n[i] < '0'||n[i] > '9')
        {
            printf("\n\t\t\t\t输入错误！请重新输入:");
            scanf("%s", n);
            i=0;
        }
        else
        {
            i++;
        }
        if(n[i] == '\0')
            break;
    }
    i = 0;
	while (n[i] != '\0')
	{
		*val = (*val * 10 + (int)n[i] - 48);
		i++;
	}
}
