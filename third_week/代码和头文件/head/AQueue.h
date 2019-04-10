/***************************************************************************************
 *    File Name                :    AQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2019.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

/**************************************************************
 *    Macro Define Section
 **************************************************************/
#define MAXQUEUE 10
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//循环队列结构

typedef enum
{
    INT = 1,CHAR = 2,DOUBLE = 3,STRING = 4
}Type;


typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length;           //队列长度
    int type[MAXQUEUE];    //存放进入队列的数据类型
} AQueue;


typedef enum
{
    FALSE=0, TRUE=1
} Status;

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q);


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q);



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q);

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q);



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e);



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q);

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data);



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q);



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q);



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int typeData));



/**
 *  @name        : void APrint(void *q, int type)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : 这里因为不知道怎么进行操作，所以增加了一个形参辅助判断数据类型
 */
void APrint(void *q ,int typeData);

/**
 *  @name        : void inputCheck(int *val)
 *    @description : 检查用户输入
 *    @param         整型指针val
 *  @notice      : None
 */

void inputCheck(void *val, int type);
void Catalogue(AQueue *Q);

void SelectOpe(AQueue *Q);
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED

