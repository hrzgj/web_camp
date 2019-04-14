#include "../inc/qgsort.h"

//插入排序
void insertSort(int *a,int n)
{
    int inserPos;
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        for(inserPos=i;inserPos>0&&a[inserPos-1]>temp;inserPos--)
        {
            a[inserPos]=a[inserPos-1];
        }
        a[inserPos]=temp;
    }
}

//归并排序
void MergeSort(int *a,int begin,int end,int *temp)
{
    if (begin < end)
    {

        int center = (begin + end) / 2;


        MergeSort(a, begin, center, temp);
        MergeSort(a, center+1, end, temp);

        MergeArray(a,begin,center,end,temp);
    }
}

//归并排序数组合并
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int i=begin,j=mid+1,k=begin;
    while(i<=mid&&j<=end)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=end)
        temp[k++]=a[j++];
    for(int z=begin;z<=end;z++)
        a[z]=temp[z];
}
//快速排序(递归)
void QuickSort_Recursion(int *a, int begin, int end)
{
    if (begin < end&&begin != end - 1)
    {
        int left = begin, right = end - 1;
        int median = Partition(a, begin, end);
        int temp;
        while (1)
        {
            while (a[++left] < median);
            while (a[--right] > median);
            if (left < right)
            {
                swap(&a[left],&a[right]);
            }
            else
                break;
        }
        swap(&a[left],&a[end-1]);
        QuickSort_Recursion(a, begin, left - 1);
        QuickSort_Recursion(a, left + 1, end);
    }
    else if (begin == end - 1 && a[begin] > a[end])
    {
        swap(&a[begin],&a[end]);
    }
}

//快速排序(非递归)
void QuickSort(int *a,int size)
{
    int begin = 0;
    int end = size;
    Stack *s;
    s=(Stack *)malloc(sizeof(Stack));
    initStack(s,10000);
    pushStack(s,begin);
    pushStack(s,end);
    while(!isEmptyStack(s))
    {
        popStack(s,&end);
        popStack(s,&begin);
        int index = Partitions(a, begin, end);
        if (index - 1 > begin)
        {
            pushStack(s, begin);
            pushStack(s,index-1);
        }
        if (index + 1 < end)
        {
            pushStack(s, index+1);
            pushStack(s,end);
        }
    }
}
//快速排序的非递归找枢纽
int Partitions(long *a, int begin, int end)
{
	int t = a[begin];
	while (begin < end)
	{
		while (begin < end&&a[end] >= t)
			end--;
		a[begin] = a[end];
		while (begin < end&&a[begin] <= t)
			begin++;
		a[end] = a[begin];
	}
	a[begin] = t;
	return begin;
}

//快速排序的枢纽
//按头中尾的顺序排好，并将枢纽放在尾-1
int Partition(int *a, int begin, int end)
{
    int center = (begin + end)/2;
    if (a[begin] > a[center])
        swap(&a[begin],&a[center]);
    if (a[begin] > a[end])
        swap(&a[begin],&a[end]);
    if (a[center] > a[end])
        swap(&a[center],&a[end]);

    swap(&a[center],&a[end-1]);
    return a[end-1];
}

//交换函数
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//颜色排序
void ColorSort(int *a,int size)
{
    int p0=0,p2=size-1;
    while(a[p0]==0)
    {
        p0++;
    }
    while(a[p2]==2)
    {
        p2--;
    }
    for(int i=p0+1;i<size;i++)
    {
        if(i==p2)
            break;
        if(a[i]==2)
        {
            if(a[p2]==0)
            {
                swap(&a[p0++],&a[p2]);
                swap(&a[i],&a[p2--]);
            }
            else
                swap(&a[i],&a[p2--]);
                continue;
        }
        if(a[i]==0)
        {
            if(a[p0]==2)
            {
                swap(&a[p0],&a[p2--]);
                swap(&a[i],&a[p0++]);
            }
            else
                swap(&a[i],&a[p0++]);
                continue;
        }


    }
}

//计数排序
void CountSort(int *a, int size)
{
    int count=0;
    int min=a[0],max=a[0];
    for(int i=0;i<size;i++)
    {
        if(min>a[i])
            min=a[i];
        if(max<a[i])
            max=a[i];
    }
    int range=max-min+1;
    int * temp=(int*)malloc(sizeof(int)*range);
     if (temp == NULL)
        return;
    memset(temp,0,sizeof(int)*range);
    for(int i=0;i<size;i++)
    {
        temp[a[i]-min]++;
    }
    for(int i=0;i<range;i++)
    {
        while(temp[i]--)
        {
            a[count++]=i+min;
        }
    }
    free(temp);
}

//基数排序
void RadixCountSort(int *a,int size)
{
    int *temp[10];
    for(int i=0;i<10;i++)
    {
        temp[i]=(int *)malloc(sizeof(int)*(size+1));
        temp[i][0]=0;
    }
    int bit;
    for(bit=1;bit<=maxNumber(a,size);bit++)
    {
        for(int i=0;i<size;i++)
        {
            int num=getNumber(a[i],bit);
            temp[num][++temp[num][0]]=a[i];
        }
        int index=0;
        for(int i=0;i<10;i++)
        {
            int j;
            for(j=1;j<=temp[i][0];j++)
                a[index++]=temp[i][j];
            temp[i][0]=0;
        }
    }
}

//数组内数字的最高位
int maxNumber(int *a,int size)
{
    int bits=1,p=10;
    for(int i=0;i<size;i++)
    {
        while(a[i]>=p)
        {
            p*=10;
            bits++;
        }
    }
    return bits;
}

//得到一个数字第digit位的值
int getNumber(int num,int digit)
{
    int temp=1;
    for(int i=0;i<digit;i++)
        temp*=10;
    return (num/temp)%10;
}





void memu()//展示用户界面
{
    printf("\n\n*********************************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("********************************数 据 结 构 之 排序 程 序 设 计*****************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         1.  插入排序            \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         2.  快速排序(递归)    \t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         3.  归并排序              \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         4.  计数排序              \t\t\t\t\t\t*\n");;
    printf("*\t\t\t\t         5.  基数排序              \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         6.  找到第k大数           \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         7.  颜色排序            \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         8.  快速排序(非递归)   \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*********************************************************************************************************\n");
}

void chooseData(long *a)
{
    printf("*********************************************************************************************************\n\n");
    printf("*\t\t\t\t         1.0-10000数据          \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         2.10000-50000数据        \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         3.50000-100000数据          \t\t\t\t\t\t*\n");
     printf("\n\n*********************************************************************************************************\n");
    printf("请输入你的选择\n");
    int n;
    n=inputError(n,'1','3');
    FILE *fp;
    if(n==1)
    {
        fp=fopen("text.txt","r");
        for(int i=0;i<10000;i++)
            fscanf(fp,"%ld",&a[i]);
    }
    if(n==2)
    {
        fp=fopen("text50000.txt","r");
        for(int i=0;i<1000;i++)
            fscanf(fp,"%ld",&a[i]);
    }
    if(n==3)
    {
        fp=fopen("text100000.txt","r");
        for(int i=0;i<1000;i++)
            fscanf(fp,"%ld",&a[i]);
    }

    fclose(fp);
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

void print(long *a)
{
    for(int i=0;i<1000;i++)
    {
        if(i%10==0)
            printf("\n");
        printf("%ld\t",a[i]);
    }
}


void mainFun()
{
    long a[1000];
    char c='y';
    while(1)
    {
        chooseData(a);
        if(c=='y'||c=='Y')
        {
            memu();
            printf("请输入你的选择\n");
            int n;
            n=inputError(n,'1','8');
            time_t start,end;
            time(&start);
            if(n==1)
             {
                 insertSort(a,1000);
                 print(a);
             }
            if(n==2)
            {
                QuickSort_Recursion(a,0,999);
                print(a);
            }
            if(n==3)
            {
                long temp[1000];
                MergeSort(a,0,999,temp);
                print(a);
            }
            if(n==4)
            {
                CountSort(a,1000);
                print(a);
            }
            if(n==5)
            {
                RadixCountSort(a,1000);
                print(a);
            }
            if(n==6)
            {
                int index;
                printf("请输入你要查找第几个数（0-1000）\n");
                scanf("%d",&index);
                QuickSort_Recursion(a,0,999);
                printf("该数为%ld",a[index-1]);
                getchar();
            }
            if(n==7)
            {
                for(int i=0;i<1000;i++)
                    a[i]=a[i]%3;
                CountSort(a,1000);
                print(a);
            }
            if(n==8)
            {
                QuickSort(a,1000);
                print(a);
            }
            time(&end);
            double cost=difftime(end,start);
            printf("\n总共花费了%.2lf秒\n",cost);
        }
        else
            break;
        printf("是否继续。是为Y，否为其他字符\n");
        c=getchar();
        getchar();
    }

}

Status initStack(Stack *s,int sizes)  //初始化栈
{
        s->data=( int * )malloc( sizes * sizeof(int));
        if(NULL==s->data)
            return ERROR;
        s->top=-1;
        s->size = sizes;
        return SUCCESS;
}


Status isEmptyStack(Stack *s)   //判断栈是否为空
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
Status getTopStack(Stack *s,int *e)   //得到栈顶元素
{
    if(isEmptyStack(s)||s->data[s->top])
    {
        return ERROR;
    }
    else
    {
        e=s->data;
    }

    return SUCCESS;
}

Status pushStack(Stack *s,int data)  //入栈
{
    if(s==NULL||s->top>=s->size-1)
    {
        return ERROR;
    }
    s->top++;
    s->data[s->top]=data;
    return SUCCESS;
}
Status popStack(Stack *s,int *data)   //出栈
{
    if(s==NULL||isEmptyStack(s))
    {
        return ERROR;
    }
    *data=s->data[s->top];
    s->top--;
    return SUCCESS;
}
