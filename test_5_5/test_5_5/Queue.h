#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;

//�����е�һ�����
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

//����(������Ҫ����ָ�룬�����ýṹ�嶨��)
typedef struct Queue
{
	QueueNode* head; //ͷָ��
	QueueNode* tail; //βָ��
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestroy(Queue* pq);
//���
void QueuePush(Queue* pq, QDataType x);
//����
void QueuePop(Queue* pq);
//ȡ��ͷ����
QDataType QueueFront(Queue* pq);
//ȡ��β����
QDataType QueueBack(Queue* pq);
//�п�
bool QueueEmpty(Queue* pq);
//�������Ԫ�ظ���
int QueueSize(Queue* pq);



