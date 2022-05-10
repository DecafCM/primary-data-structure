#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//��ʼ��
void StackInit(Stack* pst)
{
	assert(pst);

	/*pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;*/

	//��ʼ������ռ䣬�ô����ڿռ䲻��ʱֱ������*2����(����տ�ʼ��0��Ҫ��������)
	pst->a = malloc(sizeof(STDataType) * 4);
	pst->top = 0;
	pst->capacity = 4;

}

//����
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//��ջ
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	//��topΪ0��λ�ÿ�ʼ��
	//������˾�����
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * pst->capacity * 2);
		if (tmp == NULL)
		{
			//������ٿռ�ʧ��
			printf("realloc fail\n");
			exit(-1);//������������(-1��ʾ�쳣�˳�)
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}

	//������
	pst->a[pst->top] = x;
	pst->top++;

}

//��ջ
void StackPop(Stack* pst)
{
	assert(pst);//�����ǿ�ָ��
	assert(!StackEmpty(pst)); //ջ�ڻ���Ԫ�ز��ܳ�ս

	pst->top--;
}

//����ջ������
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->a[pst->top - 1];
}

//�ж�ջ�Ƿ�Ϊ��,�շ���1�ǿշ���0
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