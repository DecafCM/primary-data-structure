#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "SList.h"

//��ӡ
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

//����һ�����
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;

	return node;
}

//β��
void SListPushBack(SLTNode** pplist, SLTDataType x)
//Ϊʲô��**pplist����Ϊ����Ҫ�ı����һ��ָ��plist�����Դ��ν���Ӧ����һ������ָ��(��ַ����)
{
	//����һ���½ڵ�
	SLTNode* newnode = BuySLTNode(x);
	
	//�������Ϊ�գ���β��Ľ���ɸñ�ĵ�һ��Ԫ��
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else //�ǿ�, ֱ��β��
	{
		//�ȱ�������β���
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
		//���½�㶨��ʱ��ָ��NULL�ˣ�������tail��nextָ��ý�㼴��
	}
}

//ͷ��
void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	//���������ǿ�ָ��Ҳ������������
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

//βɾ
void SListPopBack(SLTNode** pplist)
{	
	//1.û�н������
	if (*pplist == NULL)
	{
		return;
	}
	//2.ֻ��һ���������
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3.����������
	else
	{
		//ǰ��ָ��
		SLTNode* prev = NULL;
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			//��β����ǰ�����
			prev = tail;
			//��β���
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

//ͷɾ
void SListPopFront(SLTNode** pplist)
{
	//1.û�н������
	if (*pplist == NULL)
	{
		return;
	}
	//2.����������
	else
	{
		//��һ����һ��Ԫ�صĵ�ַ(����free������Ҳ�����)
		SLTNode* next = (*pplist)->next; //��Ҫ�����ţ���Ϊ*��->���ȼ���ͬ
		free(*pplist);
		*pplist = next;
	}
}

//����
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

//��������posλ��֮�����
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	//ע��˳��
	newnode->next = pos->next;
	pos->next = newnode;
}

//��������posλ��֮ǰ���� (�鷳��������ʹ��)
void SListInsert(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);

	//�ڵ�һ��λ�ò��� => �൱��ͷ��
	if (pos == *pplist)
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL; //ǰ��
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
//�����Ҫ��һ����ͷ�������ĳһ������ǰ�����һ��ֵx����β��룿
//˼·���Ⱥ�壬Ȼ�����ǰһ������ֵ(data)���н�������

//ɾ��pos���һ�����
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	//1.pos����û�����
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

