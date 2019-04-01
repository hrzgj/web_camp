#include "counter.h"


stack* InitStack()
{
        Elemtype* t;
        stack* s;
        t=(Elemtype*)malloc(stacksize*sizeof(Elemtype));
        s=(stack*)malloc(sizeof(stack));
        s->top=t;
        s->base=t;
        s->len=stacksize;
        return s;
}

//��ջ
void PushStack(stack *s, Elemtype d)
{
        if(s->top-s->base>=s->len-1)
            s->base=(Elemtype*)realloc(s->base,(s->len+stackincrease)*sizeof(Elemtype));
        *s->top=d;
        s->top++;
}

//��ջ
void PopStack(stack* s, Elemtype* d)
{
        if(s->top==s->base)
        {
            printf("\n��ջ\n");
            return;
        }
        *d=*--(s->top);
}

int LengthStack(stack *s)
{
        return (s->top-s->base);
}

int GetExp(Elemtype* str)//��ȡ�������׺���ʽ�����浽str������
{
    char c;
    int i=0;
    fflush(stdin);
    scanf("%c",&c);
    while(c!='\n')
    {
        if(i>expvalume)
    {
        printf("���ʽ̫����\n");
        return ;
    }
    *str++=c;
    i++;
    scanf("%c",&c);
    }
    if(i==0)
    {
        *str++='#';
    }
    *str='\0';

    return i;
}

void NiftoSuf(Elemtype* nif, Elemtype* suf)//����׺���ʽ��nif��ת��Ϊ��׺���ʽ(suf)
{
    int i, j, n;
    char c2;
    Elemtype c, t;
    stack *s;
    i=0;
    j=0;
    s=InitStack();
    c=(char)nif[i];
        while(c!='#')//'#'Ϊ���������־
        {
            while(isdigit(c)||c=='.')//���ַ��ķ�ʽ��ȡ����,�����ָ��Ƶ�suf��
            {
                suf[j++]=c;
                c=(char)nif[++i];
                c2=suf[j-1];
                if((c<'0'||c>'9')&&c!='.')
                {
                    suf[j++]=' ';
                }
                suf[j]='\0';
            }
            if(c==')')//��ջֱ������������
            {
                PopStack(s, &t);
                while(t!='(')
                {
                    suf[j++]=t;
                    suf[j++]=' ';
                    PopStack(s,&t);
                }
                suf[j]='\0';
            }
            else if(c=='(')//�����Ŷ���ջ
                PushStack(s,c);
            else if(c=='+'||c=='-')
            {
                if(!LengthStack(s))//��ջΪ��ջʱ��������ζ���ջ
                {
                    PushStack(s,c);
                }
                else
                {
                    //���c�ǼӼ�������ջ���������Ų���ջ������ȫ����ջ������ٰ�c��ջ
                    do{
                        PopStack(s,&t);
                        if(t=='(')
                           {
                            PushStack(s,t);
                           }
                        else
                        {
                            suf[j++]=t;
                            suf[j++]=' ';
                            suf[j]='\0';
                        }
                    } while(LengthStack(s)&&t!='('&&c!='(');
                    PushStack(s,c);
                }
            }
            else if(c=='*'||c=='/'||c=='(')//�˳������������ȼ��󣬶���ջ
            {
                PushStack(s,c);
            }
            else if(c=='#' )//���������׺���ʽ��������ջ��Ԫ�����
            {
                while(LengthStack(s))
                {
                     PopStack(s,&t);
                     suf[j++]=t;
                     suf[j++]=' ';
                }
                break;
            }
            else
            {
                printf("\n���ʽ����\n");
                return ;
            }
            i++;
            c=nif[i];
        }
        if(c=='#')
            while(LengthStack(s))
        {
            PopStack(s,&t);
            suf[j++]=t;
            suf[j++]=' ';
        }
        suf[j++]='#';
        suf[j]='\0';
        free(s);
}

Elemtype Cal(Elemtype* suf)//�����׺���ʽ
{
    int i, j;
    char c;
    Elemtype f, r, d1, d2;
    stack *s;

    i=0;
    j=0;
    s=InitStack();
    char t[maxvalume];
    c=suf[j++];
    while(c!='#')
    {
        while(isdigit(c)||c=='.')
        {
            if(i>maxvalume)
            {
                printf("̫��\n");
                return -1;
            }
            t[i++]=c;
            t[i]='\0';
            c=suf[j++];
            if(c==' ')
            {
                f=atof(t);
                PushStack(s,f);
                i=0;
            }
        }
        switch (c){
        case '+':
            PopStack(s,&d2);
            PopStack(s,&d1);
            PushStack(s,d1+d2);
            break;
        case '-':
            PopStack(s,&d2);
            PopStack(s,&d1);
            PushStack(s,d1-d2);
            break;
        case '*':
            PopStack(s,&d2);
            PopStack(s,&d1);
            PushStack(s,d1*d2);
            break;
        case '/':
            PopStack(s,&d2);
            if(d2==0)
            {
                printf("����������Ϊ0\n");
                return  ;
            }
            PopStack(s,&d1);
            PushStack(s,d1/d2);
            break;
        }
        c=suf[j++];
    }
    PopStack(s,&r);
    printf("������Ϊ%lf",r);
    free(s);
    return r;
}

void mainFun()
{
     int i,j,k;
     int judge ;
    char c,c1,y;
    Elemtype *nif, suf[expvalume];
    do{
    i=0;
    j=0;
    k=0;
    printf("��������׺���ʽ�����ʽ������#��ʾ���ʽ����\n");
    do
    {
        judge=0;
        nif=(Elemtype*)malloc(expvalume*sizeof(Elemtype));
        int i=GetExp(nif);
        if((char)nif[i-1]!='#')
        {
            printf("����������ڱ��ʽ������#\n");
            judge=1;
            free(nif);
            continue;
        }
        if((char)nif[0]=='#')
        {
            printf("û�б��ʽ���޷�����\n");
            judge=1;
            free(nif);
            continue;
        }
        if((char)nif[0]=='*'||(char)nif[0]=='/')
        {
            printf("��������û������\n");
            judge=1;
            free(nif);
            continue;
        }
        for(int j=0;j<i-1;j++)
        {
            if(((char)nif[j]>='('&&(char)nif[j]<='/')||((char)nif[j]>='0'&&(char)nif[j]<='9'));
            else
            {
                printf("��������ȷ�����ֺͷ���\n");
                free(nif);
                judge=1;
                break;
            }
            if((char)nif[j]=='+'||(char)nif[j]=='-'||(char)nif[j]=='*'||(char)nif[j]=='/')
            {
                if((char)nif[j+1]=='+'||(char)nif[j+1]=='-'||(char)nif[j+1]=='*'||(char)nif[j+1]=='/')
                    {
                        printf("�벻Ҫ���������������\n");
                        free(nif);
                        judge=1;
                        break;
                    }
            }
            if((char)nif[j]=='('&&(char)nif[j+1]=='-')
            {
                printf("���ʽ���Ϸ�\n");
                free(nif);
                judge=1;
                break;
            }

        }
    }while(judge);

    NiftoSuf(nif,suf);
    printf("\n");
    int k=0;
    while(suf[k]!='\0')
    {
        char ch=(char)suf[k];
        printf("%c",ch);
        k++;
    }
    Cal(suf);
    printf("\n����yΪ���������������˳�����\n");
    scanf("%c",&y);
    fflush(stdin);
    } while(y=='Y'||y=='y');
    return 0;
}
