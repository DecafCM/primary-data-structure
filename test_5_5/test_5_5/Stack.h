#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int bool;
#define TRUE 1;
#define FALSE 0;

typedef int STDataType;

struct Stack
{
	STDataType* a;
	int top;       //栈顶
	int capacity;  //容量，方便增容
};

//typedef struct Stack ST;
typedef struct Stack Stack;

//初始化
void StackInit(Stack* pst);
//销毁
void StackDestroy(Stack* pst);
//入栈
void StackPush(Stack* pst, STDataType x);
//出栈
void StackPop(Stack* pst);
//返回栈顶数据
STDataType StackTop(Stack* pst);
//判断栈是否为空,空返回1非空返回0
//int StackEmpty(Stack* pst);
bool StackEmpty(Stack* pst);
//栈中数据个数
int StackSize(Stack* pst);