#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define stacksize 30
#define stackincrease 30
#define maxvalume 30
#define expvalume 200

typedef double Elemtype;

typedef struct STACK{
    Elemtype* top;
    Elemtype* base;
    int len;
} stack;

stack* InitStack();//初始化栈
//入栈
void PushStack(stack *s, Elemtype d);
//出栈
void PopStack(stack* s, Elemtype* d);
//栈的长度
int LengthStack(stack *s);
//读取输入的中缀表达式，保存到str数组中
int GetExp(Elemtype* str);
//将中缀表达式（nif）转换为后缀表达式(suf)
void NiftoSuf(Elemtype* nif, Elemtype* suf);
//计算后缀表达式
Elemtype Cal(Elemtype* suf);

void mainFun();
#endif // COUNTER_H_INCLUDED
