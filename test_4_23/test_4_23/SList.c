#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "SList.h"

//打印
void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//创建一个结点
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;

	return node;
}

//尾插
void SListPushBack(SLTNode** pplist, SLTDataType x)
//为什么是**pplist？因为我们要改变的是一级指针plist，所以传参进来应该是一个二级指针(传址调用)
{
	//创建一个新节点
	SLTNode* newnode = BuySLTNode(x);
	
	//如果链表为空，让尾插的结点变成该表的第一个元素
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else //非空, 直接尾插
	{
		//先遍历，找尾结点
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
		//该新结点定义时就指向NULL了，所以让tail的next指向该结点即可
	}
}

//头插
void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	//如果传入的是空指针也可以正常插入
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

//尾删
void SListPopBack(SLTNode** pplist)
{	
	//1.没有结点的情况
	if (*pplist == NULL)
	{
		return;
	}
	//2.只有一个结点的情况
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3.多个结点的情况
	else
	{
		//前驱指针
		SLTNode* prev = NULL;
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			//找尾结点的前驱结点
			prev = tail;
			//找尾结点
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

//头删
void SListPopFront(SLTNode** pplist)
{
	//1.没有结点的情况
	if (*pplist == NULL)
	{
		return;
	}
	//2.多个结点的情况
	else
	{
		//存一份下一个元素的地址(否则free过后就找不到了)
		SLTNode* next = (*pplist)->next; //需要加括号，因为*和->优先级相同
		free(*pplist);
		*pplist = next;
	}
}

//查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	//while (cur != NULL)
	while(cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}

//单链表在pos位置之后插入
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	//注意顺序
	newnode->next = pos->next;
	pos->next = newnode;
}

//单链表在pos位置之前插入 (麻烦，不建议使用)
void SListInsert(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);

	//在第一个位置插入 => 相当于头插
	if (pos == *pplist)
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL; //前驱
		SLTNode* cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
//如果需要在一个无头单链表的某一个结点的前面插入一个值x，如何插入？
//思路：先后插，然后跟他前一个结点的值(data)进行交换即可

//删除pos后的一个结点
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	//1.pos后面没结点了
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}

