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

//入栈
void PushStack(stack *s, Elemtype d)
{
        if(s->top-s->base>=s->len-1)
            s->base=(Elemtype*)realloc(s->base,(s->len+stackincrease)*sizeof(Elemtype));
        *s->top=d;
        s->top++;
}

//出栈
void PopStack(stack* s, Elemtype* d)
{
        if(s->top==s->base)
        {
            printf("\n空栈\n");
            return;
        }
        *d=*--(s->top);
}

int LengthStack(stack *s)
{
        return (s->top-s->base);
}

int GetExp(Elemtype* str)//读取输入的中缀表达式，保存到str数组中
{
    char c;
    int i=0;
    fflush(stdin);
    scanf("%c",&c);
    while(c!='\n')
    {
        if(i>expvalume)
    {
        printf("表达式太长了\n");
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

void NiftoSuf(Elemtype* nif, Elemtype* suf)//将中缀表达式（nif）转换为后缀表达式(suf)
{
    int i, j, n;
    char c2;
    Elemtype c, t;
    stack *s;
    i=0;
    j=0;
    s=InitStack();
    c=(char)nif[i];
        while(c!='#')//'#'为输入结束标志
        {
            while(isdigit(c)||c=='.')//以字符的方式读取数字,将数字复制到suf中
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
            if(c==')')//出栈直到遇到左括号
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
            else if(c=='(')//左括号都入栈
                PushStack(s,c);
            else if(c=='+'||c=='-')
            {
                if(!LengthStack(s))//当栈为空栈时，无论如何都入栈
                {
                    PushStack(s,c);
                }
                else
                {
                    //如果c是加减，除非栈顶是左括号不出栈，其余全部出栈，最后再把c入栈
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
            else if(c=='*'||c=='/'||c=='(')//乘除和左括号优先级大，都入栈
            {
                PushStack(s,c);
            }
            else if(c=='#' )//最后整个中缀表达式结束，把栈内元素输出
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
                printf("\n表达式错误\n");
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

Elemtype Cal(Elemtype* suf)//计算后缀表达式
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
                printf("太大\n");
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
                printf("被除数不能为0\n");
                return  ;
            }
            PopStack(s,&d1);
            PushStack(s,d1/d2);
            break;
        }
        c=suf[j++];
    }
    PopStack(s,&r);
    printf("计算结果为%lf",r);
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
    printf("请输入中缀表达式，表达式最后加上#表示表达式结束\n");
    do
    {
        judge=0;
        nif=(Elemtype*)malloc(expvalume*sizeof(Elemtype));
        int i=GetExp(nif);
        if((char)nif[i-1]!='#')
        {
            printf("输入错误，请在表达式最后加上#\n");
            judge=1;
            free(nif);
            continue;
        }
        if((char)nif[0]=='#')
        {
            printf("没有表达式，无法计算\n");
            judge=1;
            free(nif);
            continue;
        }
        if((char)nif[0]=='*'||(char)nif[0]=='/')
        {
            printf("运算符左边没有数字\n");
            judge=1;
            free(nif);
            continue;
        }
        for(int j=0;j<i-1;j++)
        {
            if(((char)nif[j]>='('&&(char)nif[j]<='/')||((char)nif[j]>='0'&&(char)nif[j]<='9'));
            else
            {
                printf("请输入正确的数字和符号\n");
                free(nif);
                judge=1;
                break;
            }
            if((char)nif[j]=='+'||(char)nif[j]=='-'||(char)nif[j]=='*'||(char)nif[j]=='/')
            {
                if((char)nif[j+1]=='+'||(char)nif[j+1]=='-'||(char)nif[j+1]=='*'||(char)nif[j+1]=='/')
                    {
                        printf("请不要连续输入多个运算符\n");
                        free(nif);
                        judge=1;
                        break;
                    }
            }
            if((char)nif[j]=='('&&(char)nif[j+1]=='-')
            {
                printf("表达式不合法\n");
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
    printf("\n输入y为继续，输入其他退出程序\n");
    scanf("%c",&y);
    fflush(stdin);
    } while(y=='Y'||y=='y');
    return 0;
}
