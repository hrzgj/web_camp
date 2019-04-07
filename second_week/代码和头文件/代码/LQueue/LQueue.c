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
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*********************************************************************************************************\n");
}

int inputError(int val)
{
	char n[20];
	int i = 0;
	val = 0;
	printf("请输入你的选择\n");
	scanf("%s", n);
	getchar();
	while (n[i]<'0' || n[i]>'9')
	{
		printf("\n输入错误，请重新输入！\n");
		scanf("%s", n);
		getchar();
		i++;
	}
	i=0;
	while (n[i] >= '0'&&n[i] <= '9')
	{
		val = (val * 10 + (int)n[i] - 48);
		i++;
	}
	return val;
}

void mainfun(LQueue *Q)
{
    memu();

    InitLQueue(Q);
    int n;
    printf("%d\n",Q->length);
    n=inputError(&n);
    switch(n)
    {
        case 1:IsEmptyLQueue(Q);
        break;
    }
}



void InitLQueue(LQueue* Q)
{
    Q=(LQueue*)malloc(sizeof(LQueue));
    Q->length=(size_t)malloc(sizeof(Q->length));
    Q->front=NULL;
    Q->rear=NULL;
    Q->length=0;
    printf("%d\n",Q->length);
}

void DestoryLQueue(LQueue *Q)
{
    while(Q->front!=Q->rear)
    {
        Node *destory=Q->front;
        Q->front=Q->front->next;
        free(destory);
    }
    free(Q->front);
    free(Q);
    printf("是否要重新初始化？是输入Y,否输入其他字符\n");
    char n;
    getc(n);
    if(n=='y'||n=='Y')
    {
        InitLQueue(Q);
    }
    else
    {
        printf("不进行重新初始化，队列销毁，无法继续操作队列\n");
        exit(0);
    }

}

Status IsEmptyLQueue(LQueue *Q)
{
    if(Q->length==0)
        printf("队列为空\n");
    else
        printf("队列不为空\n");
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(IsEmptyLQueue(Q))
    {
        printf("当前队列为空\n");
        return FALSE;
    }
    else
    {
        e=Q->front->data;
        printf("%s",e);
    }
}

int LengthLQueue(LQueue *Q)
{
    if(Q->length=0)
        printf("当前队列长度%d\n",Q->length);
    else
        printf("当前队列为空\n");
}

Status EnLQueue(LQueue *Q, void *data)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=data;
    Q->rear->next=p;
    Q->rear=p;
}




