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

stack* InitStack();//��ʼ��ջ
//��ջ
void PushStack(stack *s, Elemtype d);
//��ջ
void PopStack(stack* s, Elemtype* d);
//ջ�ĳ���
int LengthStack(stack *s);
//��ȡ�������׺���ʽ�����浽str������
int GetExp(Elemtype* str);
//����׺���ʽ��nif��ת��Ϊ��׺���ʽ(suf)
void NiftoSuf(Elemtype* nif, Elemtype* suf);
//�����׺���ʽ
Elemtype Cal(Elemtype* suf);

void mainFun();
#endif // COUNTER_H_INCLUDED
