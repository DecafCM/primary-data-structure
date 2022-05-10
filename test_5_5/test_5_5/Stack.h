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
	int top;       //ջ��
	int capacity;  //��������������
};

//typedef struct Stack ST;
typedef struct Stack Stack;

//��ʼ��
void StackInit(Stack* pst);
//����
void StackDestroy(Stack* pst);
//��ջ
void StackPush(Stack* pst, STDataType x);
//��ջ
void StackPop(Stack* pst);
//����ջ������
STDataType StackTop(Stack* pst);
//�ж�ջ�Ƿ�Ϊ��,�շ���1�ǿշ���0
//int StackEmpty(Stack* pst);
bool StackEmpty(Stack* pst);
//ջ�����ݸ���
int StackSize(Stack* pst);