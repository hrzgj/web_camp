#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈
void userFace(LinkStack *s);//展示用户界面
void selcetAction(LinkStack *s);//选择操作
void inputCheck(int *val);  //检查输入
#endif // STACK_H_INCLUDED
