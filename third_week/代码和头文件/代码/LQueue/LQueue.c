#include "../../头文件/LQueue.h"

void memu()//展示用户界面
{
    printf("\n\n*********************************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("********************************数 据 结 构 之 队列 程 序 设 计*****************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         1.  判断队列是否为空        \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         2.  得到队头元素            \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         3.  销毁队列                 \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         4.  确定队列长度              \t\t\t\t\t\t*\n");;
    printf("*\t\t\t\t         5.  清空队列              \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         6.  入队                    \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         7.  出队                    \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         8.  遍历队列                 \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*********************************************************************************************************\n");
}

int inputError(int val,char front,char rear)
{
	char *n=(char *)malloc(sizeof(char)*50);
	int i = 0;
	val = 0;
	gets(n);
	while (n[i]<front || n[i]>rear)
	{
	    if(n[i++]<front || n[i]>rear)
        {
            printf("输入错误，请重新输入！\n");
            free(n);
            n=(char *)malloc(sizeof(char)*50);
            gets(n);
            i=0;
        }
	}
	i=0;
	while (n[i] >= front &n[i] <= rear)
	{
		val = (val * 10 + (int)n[i] - 48);
		i++;
	}
	return val;
}

void mainfun(LQueue *Q)
{
    InitLQueue(Q);
    char a='y';
    while(a=='y'||a=='Y')
    {
        int n;
        memu();
        printf("请输入你的选择\n");
        n=inputError(&n,'1','8');
        switch(n)
        {
            case 1:
                IsEmptyLQueue(Q);
                break;
            case 2:
                GetHeadLQueue(Q);
                break;
            case 3:
                DestoryLQueue(Q);
                break;
            case 4:
                LengthLQueue(Q);
                break;
            case 5:
                ClearLQueue(Q);
                break;
            case 6:
                EnLQueue(Q);
                break;
            case 7:
                DeLQueue(Q);
                break;
            case 8:
                TraverseLQueue(Q);
                break;
        }
        printf("是否继续。是为Y，否为其他字符\n");
        a=getchar();
        getchar();

    }
}


//队列初始化
void InitLQueue(LQueue* q)
{
    q->front=NULL;
    q->rear=NULL;
    q->length=0;
}
//销毁队列
void DestoryLQueue(LQueue *Q)
{
    while(Q->front!=Q->rear)
    {
        Node *destory=Q->front;
        Q->front=Q->front->next;
        free(destory);
    }
    free(Q->front);
    printf("销毁成功\n");
    printf("是否要重新初始化(否将退出程序)？是输入Y,否输入其他字符,\n");
    char n;
    n=getchar();
    if(n=='y'||n=='Y')
    {
        InitLQueue(Q);
        getchar();
    }
    else
    {
        printf("没有重新初始化，队列销毁，无法继续操作队列\n");
        exit(0);
    }

}
//判断队列是否为空
Status IsEmptyLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("队列为空\n");
        return TRUE;
    }

    else
        printf("队列不为空\n");
        return FALSE;
}
//得到队头元素
Status GetHeadLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("当前队列为空\n");
        return FALSE;
    }
    else
    {
        if(Q->front->type==1)
        {
            printf("此元素类型为整型，数值为%d\n",*(int *)Q->front->data);
        }
        else if(Q->front->type==2)
            printf("此元素类型为浮点型，数值为%lf\n",*(double *)Q->front->data);
        else
        {
            printf("当前元素类型为字符串，内容为%s\n",Q->front->data);
        }
    }
}
//得到队列长度
int LengthLQueue(LQueue *Q)
{
    if(Q->length!=0)
        printf("当前队列长度%d\n",Q->length);
    else
        printf("当前队列为空\n");
}

//入队
Status EnLQueue(LQueue *Q)
{
    Node *p=(Node *)malloc(sizeof(Node));
    ChooseMenu();
    int n;
    printf("请输入你要插入的数据类型\n");
    n=inputError(&n,'1','3');
    printf("请输入你要插入的数据\n");
    if(n==1)
    {
        p->data=malloc(sizeof(int));
        int a;
        scanf("%d",&a);
        *((int *)p->data)=a;
        p->type=1;
        getchar();
    }
    if(n==2)
    {
        p->data=malloc(sizeof(double));
        double a;
        scanf("%lf",&a);
        *((double *)p->data)=a;
        p->type=2;
        getchar();
    }
    if(n==3)
    {
        p->data=malloc(sizeof(char)*50);
        char a[50];
        gets(a);
        int i;
        for( i=0;a[i]!='\0';i++)
        *(((char*)p->data)+i)=a[i];
        *(((char*)p->data)+i)='\0';
        p->type=3;
    }
    if(Q->front==NULL)
    {
        Q->front=p;
        Q->rear=p;
        Q->length++;
    }
    else
    {
        Q->rear->next=p;
        Q->rear=p;
        Q->rear->next=NULL;
        Q->length++;
    }
}
//清空队列
void ClearLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("该队列为空，无需清空\n");
        return FALSE;
    }
    else
    {
        while(Q->front!=Q->rear)
        {
            Node *destory=Q->front;
            Q->front=Q->front->next;
            free(destory);
        }
        free(Q->front);
        Q->front=NULL;
        Q->rear=NULL;
        Q->length=0;
        printf("清空完毕\n");
        return TRUE;
    }

}
//出队
Status DeLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("队列为空，无法出队\n");
    }
    else
    {
        if(Q->front->type==1)
        {
            printf("此元素类型为整型，数值为%d\n",*(int *)Q->front->data);
        }
        else if(Q->front->type==2)
            printf("此元素类型为浮点型，数值为%lf\n",*(double *)Q->front->data);
        else
        {
            printf("当前元素类型为字符串，内容为%s\n",Q->front->data);
        }
        Node *destory=Q->front;
        Q->front=Q->front->next;
        free(destory);
        Q->length--;
        printf("出栈完毕\n");
    }
}
//遍历队列，打印队列元素
Status TraverseLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("队列为空,无元素\n");
        return  FALSE;
    }
    else
    {
        Node *t=Q->front;
        int i=1;
        while(Q->front!=Q->rear)
        {
           if(Q->front->type==1)
            {
                printf("第%d元素类型为整型，数值为%d\n",i,*(int *)Q->front->data);
            }
            else if(Q->front->type==2)
                printf("第%d元素类型为浮点型，数值为%lf\n",i,*(double *)Q->front->data);
            else
            {
                printf("第%d元素类型为字符串，内容为%s\n",i,Q->front->data);
            }
            Q->front=Q->front->next;
            i++;
        }
            if(Q->front->type==1)
            {
                printf("第%d元素类型为整型，数值为%d\n",i,*(int *)Q->front->data);
            }
            else if(Q->front->type==2)
                printf("第%d元素类型为浮点型，数值为%lf\n",i,*(double *)Q->front->data);
            else
            {
                printf("第%d元素类型为字符串，内容为%s\n",i,Q->front->data);

            }
        Q->front=t;
    }
}


void ChooseMenu()
{
    printf("----------------------------\n");
    printf("****************************\n");
    printf("1--整型--2--浮点型--3--字符串\n");
    printf("****************************\n");
    printf("----------------------------\n");
}

