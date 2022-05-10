#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//初始化
void StackInit(Stack* pst)
{
	assert(pst);

	/*pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;*/

	//开始就申请空间，好处在于空间不够时直接容量*2即可(如果刚开始是0就要单独处理)
	pst->a = malloc(sizeof(STDataType) * 4);
	pst->top = 0;
	pst->capacity = 4;

}

//销毁
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	//从top为0的位置开始放
	//如果满了就增容
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * pst->capacity * 2);
		if (tmp == NULL)
		{
			//如果开辟空间失败
			printf("realloc fail\n");
			exit(-1);//结束整个程序(-1表示异常退出)
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}

	//入数据
	pst->a[pst->top] = x;
	pst->top++;

}

//出栈
void StackPop(Stack* pst)
{
	assert(pst);//不能是空指针
	assert(!StackEmpty(pst)); //栈内还有元素才能出战

	pst->top--;
}

//返回栈顶数据
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->a[pst->top - 1];
}

//判断栈是否为空,空返回1非空返回0
bool StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}