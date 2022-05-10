#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"


//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	//�����ڱ�λ
	pq->head = pq->tail = NULL;
}

//����
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

//�п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL; //���ڿվ�Ϊ��, ��Ϊ�վ��Ǽ�
}


//���
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)//����ռ�ʧ��
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

//����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//�ն���Ҳ���ܵ��ó��Ӳ���

	if (pq->head->next == NULL)//ֻ��һ���������(������������ǣ��ǵ�ֻ��һ�����ʱ��tail����Ȼָ�������Ķ�β)
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

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//ȡ��β����
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