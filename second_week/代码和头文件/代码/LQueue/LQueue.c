#include "../../ͷ�ļ�/LQueue.h"

void memu()//չʾ�û�����
{
    printf("\n\n*********************************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("********************************�� �� �� �� ֮ ���� �� �� �� ��*****************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         1.  �ж϶����Ƿ�Ϊ��        \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         2.  �õ���ͷԪ��            \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         3.  ���ٶ���                 \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         4.  ȷ�����г���              \t\t\t\t\t\t*\n");;
    printf("*\t\t\t\t         5.  ��ն���              \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         6.  ���                    \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         7.  ����                    \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*********************************************************************************************************\n");
}

int inputError(int val)
{
	char n[20];
	int i = 0;
	val = 0;
	printf("���������ѡ��\n");
	scanf("%s", n);
	getchar();
	while (n[i]<'0' || n[i]>'9')
	{
		printf("\n����������������룡\n");
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
    printf("�Ƿ�Ҫ���³�ʼ����������Y,�����������ַ�\n");
    char n;
    getc(n);
    if(n=='y'||n=='Y')
    {
        InitLQueue(Q);
    }
    else
    {
        printf("���������³�ʼ�����������٣��޷�������������\n");
        exit(0);
    }

}

Status IsEmptyLQueue(LQueue *Q)
{
    if(Q->length==0)
        printf("����Ϊ��\n");
    else
        printf("���в�Ϊ��\n");
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(IsEmptyLQueue(Q))
    {
        printf("��ǰ����Ϊ��\n");
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
        printf("��ǰ���г���%d\n",Q->length);
    else
        printf("��ǰ����Ϊ��\n");
}

Status EnLQueue(LQueue *Q, void *data)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=data;
    Q->rear->next=p;
    Q->rear=p;
}




