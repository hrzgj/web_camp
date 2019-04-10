#include "../../head/AQueue.h"
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        //不知道用户想放入的数据类型大小，所以给个20
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return;
    }
	for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q))
        return FALSE;
    if(LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else
        return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！没有队头！\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],20);
    return TRUE;
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+Q->length)%Q->length;
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("队列满了！不能再入队了！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, 20);
		Q->rear = (Q->rear + 1) % Q->length;
		return TRUE;
	}
    memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列是空的！出不了队！\n");
		return FALSE;
	}
    Q->front = (Q->front+1)%Q->length;
    return TRUE;
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列已经是空的了！\n");
		return;
	}
    Q->front = Q->rear = 0;
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int typeData))
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	if (IsEmptyAQueue(Q))
	{
		printf("队列里面什么都没有!\n");
		return FALSE;
	}
	int i = 0;
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[Q->front+i], Q->type[Q->front+i]);
		i = (i + 1) % MAXQUEUE;
	}
    return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q, int typeData)
{
    if(typeData == DOUBLE)
        printf("--> %.2lf", *(double*)q);
    if(typeData == CHAR)
        printf("--> %c", *(char*)q);
    if(typeData == INT)
        printf("--> %d ", *(int*)q);
    if(typeData == STRING)
        printf("--> %s ", (char*)q);
}

void SelectOpe(AQueue *Q)
{
    int n;
    printf("\n你想执行那个操作 ?");
	inputCheck(&n, INT);
	while(n < 0||n > 10)
    {
        printf("\n输入错误！请重输：");
        inputCheck(&n, INT);
    }
    switch(n)
    {
        case 1:DestoryAQueue(Q);break;
        case 2:
                if(IsEmptyAQueue(Q))
                {
                    printf("队列为空！");
                    break;
                }
                IsFullAQueue(Q);break;
        case 3:
                if(IsEmptyAQueue(Q))
                {
                    printf("队列为空！");
                    break;
                }
                IsEmptyAQueue(Q);break;
        case 4:
            {
                if(Q->data[0] == NULL)
                {
                    printf("队列目前未初始化！请先初始化队列！\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("队列为空！");
                    break;
                }
                switch(Q->type[Q->front])
                {
					case INT:
					{
						int a;
						GetHeadAQueue(Q, &a);
						printf("队列头元素是： %d\n", (int)a);
						break;
					}
					 case CHAR:
					{
						 char a;
						 GetHeadAQueue(Q, &a);
						 printf("队列头元素是： %c\n", (char)a);
						 break;
					}
					case DOUBLE:
					{
						double a ;
						GetHeadAQueue(Q, &a);
						printf("队列头元素是： %.2lf\n", (double)a);
						break;
					}
					case STRING:
					{
						char a[20] = {0};
						GetHeadAQueue(Q, a);
						printf("队列头元素是： %s\n", (char*)a);
						break;
					}
                }
				break;
            }
        case 5:
            {
                    if(Q->data[0] == NULL)
                    {
                        printf("队列目前未初始化！请先初始化队列！\n");
                        break;
                    }
                    printf("目前长度是：%d\n", LengthAQueue(Q));
                    break;
            }
        case 6:
            {
                    if(Q->data[0] == NULL)
                    {
                        printf("队列目前未初始化！请先初始化队列！\n");
                        break;
                    }
					if (IsFullAQueue(Q))
					printf("队列是满的！\n");
					int t;
                    printf("你想入队哪种类型？:\n");
                    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
                    inputCheck(&t, INT);
                    while(t<1 || t>4)
                    {
                        printf("应输入在[1,4]之间的整数！\n请重输：");
                        inputCheck(&t, INT);
                    }
					printf("想入队的数据 :");
                    switch(t)
                    {
                        case INT:{
							int a;
							inputCheck(&a, INT);
							Q->type[Q->rear]=t;
							EnAQueue(Q, &a);
							break;
						}
						case CHAR: {
							char a ;
							inputCheck(&a, CHAR);
							Q->type[Q->rear]=t;
							EnAQueue(Q, &a);
							break;
						}
                        case DOUBLE:{
							double a ;
							inputCheck(&a, DOUBLE);
							Q->type[Q->rear]=t;
							EnAQueue(Q, &a);
							break;
						}
                        case STRING:{
							char a[20];
							printf("最大长度为20哦！\n");
							inputCheck(&a, STRING);
							Q->type[Q->rear]=t;
							EnAQueue(Q, a);
							break;
						}
                    }
					break;
            }
        case 7:
            {
                if(Q->data[0] == NULL)
                {
                    printf("队列目前未初始化！请先初始化队列！\n");
                    break;
                }
                if(DeAQueue(Q))
                    printf("出队成功！\n");
                else
                    printf("出队失败！\n");
				break;
            }
        case 8:
            {
                if(Q->data[0] == NULL)
                {
                    printf("队列目前未初始化！请先初始化队列！\n");
                    break;
                }
                if (!IsEmptyAQueue(Q))
                {
                    ClearAQueue(Q);
                    printf("已清空！\n");
                }
                    else
                        printf("目前是空的！\n");
                    break;
            }
        case 9:
            {
               void (*p)(void *q,int type);
               p=APrint;
			   TraverseAQueue(Q, p);
				break;
            }
		case 10:
		{
			if(LengthAQueue(Q))
            {
                printf("队列里还有元素！请先清空！\n");
                break;
            }
			InitAQueue(Q);
			printf("初始化成功！\n");
			break;
		}
    }
}
/**
 *  @name        : void inputCheck(int *val)
 *    @description : 检查用户输入
 *    @param         整型指针val
 *  @notice      : None
 */

void inputCheck(void *val ,int type)
{
        char n[50]={0};
        int i = 0, flag = 0;
        scanf("%s", n);
        getchar();
        if(strlen(n)>20)
                flag = 1;
        if(flag == 1)
        {
            printf("\n输入错误！请重新输入：");
            inputCheck(val, type);
            flag = 0;
        }
		if (type == INT)
		{
            if(strlen(n)>10)
                {
                    flag = 1;
                }
            for(int j = 0; n[j] != '\0'; j++)
                {
                    if((n[j] < '0'||n[j] > '9')&&(n[j] == '-'&& j != 0))
                        flag = 1;
                }
		}
		else if(type == CHAR)
        {
            if(strlen(n) > 1)
                flag = 1;
        }
        else if(type == DOUBLE)
        {
            int pointNum = 0;
            //用于计算字符串中的小数点数量
            for(int j = 0; n[j] != '\0';j++)
            {
                if(n[j] == '.')
                    pointNum++;
                if((n[j] < '0'||n[j] > '9')&&n[j]!='.'&&(n[j]== '-'&& j!=0 ))
                    flag = 1;
            }
        }
        if(flag == 1)
            {
                printf("\n输入错误！请重新输入：");
                inputCheck(val, type);
            }
		else
		{
			if (type == INT)
			{
				int temp = 0;
				//记录是否有负号
				int minus = 0;
				if(n[0] == '-')
                    minus = 1;
				for (int j = minus; n[j] != '\0'; j++)
					temp = temp*10 + (n[j] - 48);
                if(minus == 1)
                    temp*=(-1);
				memcpy(val, &temp, 4);
			}
			else if (type == DOUBLE)
			{
				double temp = 0;
				//记录小数点位置
				int k = -1;
				//记录是否有负数
				int minus = 0;
				if(n[0] == '-')
                    minus = 1;
				for (int j = minus; n[j] != '\0'; j++)
				{
					if (n[j] == '.')
					{
						k = j;
						continue;
					}
					if (k == -1)
						temp = temp * 10 + (n[j] - 48);
					else
						temp = temp + (n[j] - 48)*pow(10, k - j);
				}
				if(minus == 1)
                    temp*= -1;
				memcpy(val, &temp, 8);
			}
			else if (type == CHAR)
			{
				memcpy(val, n, 1);
			}
			else
				memcpy(val, n, 20);
		}
}

void Catalogue(AQueue *Q)
{
    while(1)
    {


        int i;
        printf("\n\n*********************************************************************************************************\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("****************************数 据 结 构 之 循 环 队 列 程 序 设 计***************************************\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         1.  销毁队列                \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         2.  判断队列是否为满        \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         3.  判断队列是否为空        \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         4.  获取队头元素            \t\t\t\t\t\t*\n");;
        printf("*\t\t\t\t         5.  获取队列长度            \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         6.  入队                    \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         7.  出队                    \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         8.  清空队列                \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         9.  遍历队列                \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         10. 初始化队列              \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("*********************************************************************************************************\n");


	    SelectOpe(Q);
	    printf("\n\n你想继续吗?(1：继续/  其他： 退出)");
	    inputCheck(&i, INT);
	    if(i != 1)
            break;
	}
}
