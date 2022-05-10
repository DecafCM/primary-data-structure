#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"


//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	//不带哨兵位
	pq->head = pq->tail = NULL;
}

//销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

//判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL; //等于空就为真, 不为空就是假
}


//入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)//申请空间失败
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

}

//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//空队列也不能调用出队操作

	if (pq->head->next == NULL)//只有一个结点的情况(如果不单独考虑，那当只有一个结点时，tail会仍然指向曾经的队尾)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode* cur = pq->head;

	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}