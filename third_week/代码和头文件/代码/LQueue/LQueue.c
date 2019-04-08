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
    printf("*\t\t\t\t         8.  ��������                 \t\t\t\t\t\t*\n");
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
            printf("����������������룡\n");
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
        printf("���������ѡ��\n");
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
        printf("�Ƿ��������ΪY����Ϊ�����ַ�\n");
        a=getchar();
        getchar();

    }
}


//���г�ʼ��
void InitLQueue(LQueue* q)
{
    q->front=NULL;
    q->rear=NULL;
    q->length=0;
}
//���ٶ���
void DestoryLQueue(LQueue *Q)
{
    while(Q->front!=Q->rear)
    {
        Node *destory=Q->front;
        Q->front=Q->front->next;
        free(destory);
    }
    free(Q->front);
    printf("���ٳɹ�\n");
    printf("�Ƿ�Ҫ���³�ʼ��(���˳�����)��������Y,�����������ַ�,\n");
    char n;
    n=getchar();
    if(n=='y'||n=='Y')
    {
        InitLQueue(Q);
        getchar();
    }
    else
    {
        printf("û�����³�ʼ�����������٣��޷�������������\n");
        exit(0);
    }

}
//�ж϶����Ƿ�Ϊ��
Status IsEmptyLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("����Ϊ��\n");
        return TRUE;
    }

    else
        printf("���в�Ϊ��\n");
        return FALSE;
}
//�õ���ͷԪ��
Status GetHeadLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("��ǰ����Ϊ��\n");
        return FALSE;
    }
    else
    {
        if(Q->front->type==1)
        {
            printf("��Ԫ������Ϊ���ͣ���ֵΪ%d\n",*(int *)Q->front->data);
        }
        else if(Q->front->type==2)
            printf("��Ԫ������Ϊ�����ͣ���ֵΪ%lf\n",*(double *)Q->front->data);
        else
        {
            printf("��ǰԪ������Ϊ�ַ���������Ϊ%s\n",Q->front->data);
        }
    }
}
//�õ����г���
int LengthLQueue(LQueue *Q)
{
    if(Q->length!=0)
        printf("��ǰ���г���%d\n",Q->length);
    else
        printf("��ǰ����Ϊ��\n");
}

//���
Status EnLQueue(LQueue *Q)
{
    Node *p=(Node *)malloc(sizeof(Node));
    ChooseMenu();
    int n;
    printf("��������Ҫ�������������\n");
    n=inputError(&n,'1','3');
    printf("��������Ҫ���������\n");
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
//��ն���
void ClearLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("�ö���Ϊ�գ��������\n");
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
        printf("������\n");
        return TRUE;
    }

}
//����
Status DeLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("����Ϊ�գ��޷�����\n");
    }
    else
    {
        if(Q->front->type==1)
        {
            printf("��Ԫ������Ϊ���ͣ���ֵΪ%d\n",*(int *)Q->front->data);
        }
        else if(Q->front->type==2)
            printf("��Ԫ������Ϊ�����ͣ���ֵΪ%lf\n",*(double *)Q->front->data);
        else
        {
            printf("��ǰԪ������Ϊ�ַ���������Ϊ%s\n",Q->front->data);
        }
        Node *destory=Q->front;
        Q->front=Q->front->next;
        free(destory);
        Q->length--;
        printf("��ջ���\n");
    }
}
//�������У���ӡ����Ԫ��
Status TraverseLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("����Ϊ��,��Ԫ��\n");
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
                printf("��%dԪ������Ϊ���ͣ���ֵΪ%d\n",i,*(int *)Q->front->data);
            }
            else if(Q->front->type==2)
                printf("��%dԪ������Ϊ�����ͣ���ֵΪ%lf\n",i,*(double *)Q->front->data);
            else
            {
                printf("��%dԪ������Ϊ�ַ���������Ϊ%s\n",i,Q->front->data);
            }
            Q->front=Q->front->next;
            i++;
        }
            if(Q->front->type==1)
            {
                printf("��%dԪ������Ϊ���ͣ���ֵΪ%d\n",i,*(int *)Q->front->data);
            }
            else if(Q->front->type==2)
                printf("��%dԪ������Ϊ�����ͣ���ֵΪ%lf\n",i,*(double *)Q->front->data);
            else
            {
                printf("��%dԪ������Ϊ�ַ���������Ϊ%s\n",i,Q->front->data);

            }
        Q->front=t;
    }
}


void ChooseMenu()
{
    printf("----------------------------\n");
    printf("****************************\n");
    printf("1--����--2--������--3--�ַ���\n");
    printf("****************************\n");
    printf("----------------------------\n");
}

