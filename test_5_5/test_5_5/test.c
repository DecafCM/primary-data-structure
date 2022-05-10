#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include "Queue.h"
//对栈操作的测试
void TestStack()
{
	Stack st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);


	//栈遍历数据
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	//4 3 2 1

	StackDestroy(&st);
}

//对队列操作的测试
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d\n", QueueSize(&q)); //4

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	//1 2 3 4

	QueueDestroy(&q);
}

int main()
{
	TestQueue();
	return 0;
}