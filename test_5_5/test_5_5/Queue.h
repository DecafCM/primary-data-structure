#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;

//队列中的一个结点
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

//队列(由于需要两个指针，所以用结构体定义)
typedef struct Queue
{
	QueueNode* head; //头指针
	QueueNode* tail; //尾指针
}Queue;

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);
//入队
void QueuePush(Queue* pq, QDataType x);
//出队
void QueuePop(Queue* pq);
//取队头数据
QDataType QueueFront(Queue* pq);
//取队尾数据
QDataType QueueBack(Queue* pq);
//判空
bool QueueEmpty(Queue* pq);
//计算队列元素个数
int QueueSize(Queue* pq);



