#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//����һ�����
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

//��ʼ��
//������˫���ͷѭ���������Դ�ʱ��next��prev��ָ�������Լ�
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	//������ʼ�������ò����������Ҫ��������ֻ��phead�����
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//β��
void ListPushBack(ListNode* phead, LTDataType x)
{
	//assert(phead);

	////��β
	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);
	////β��
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	////��������һ������費��Ҫ�޸��������룿 ����
	////�����˫���ͷѭ����������ƣ��ṹ��Ȼ���ӵ�����������

	//���븴��
	//��pheadǰ����룬�൱��βɾ
	ListInsert(phead, x);
}

//ͷ��
//ͬ�����ÿ���ֻ��phead�����
void ListPushFront(ListNode* phead, LTDataType x)
{
	//assert(phead);

	////��first��¼�µ�һ������ͷ��ʱ�Ͳ���Ҫ���ǲ���Ĳ���
	//ListNode* first = phead->next;
	//ListNode* newnode = BuyListNode(x);
	//
	////ͷ�� phead newnode first
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = first;
	//first->prev = newnode;
	
	//���븴��
	//�൱����head->next֮ǰ����
	ListInsert(phead->next, x);
}

//βɾ
//���ÿ���phead��ֻ��һ�������������Ҫ����ʹ�øú���������ɾ����ֻʣpheadʱ���ٵ��øú����ͻ�ɾ��phead
void ListPopBack(ListNode* phead)
{
	//assert(phead);

	//assert(phead->next != phead);//ֻʣphead�����

	////�ҵ�β��㼰��ǰ��
	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev;

	////βɾ
	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;

	//����
	ListErase(phead->prev);

}

//ͷɾ
//ҲҪ����ɾ����ֻ��phead�����
void ListPopFront(ListNode* phead)
{
	/*assert(phead);

	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;

	free(first);

	phead->next = second;
	second->prev = phead;*/

	//����
	ListErase(phead->next);
}

//����
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

//��posָ��λ�ò���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}
//��posָ��λ��ɾ��
void ListErase(ListNode* pos)
{
	assert(pos);

	//�ҵ�pos��ǰ������
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
	//��pos��phead->prev��ʱ�����βɾ
	//pos��phead->next����ͷɾ
}

//�п�(�շ���1���ǿշ���0)
int ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead ? 1 : 0;
}
//���������
int ListSize(ListNode* phead)
{
	assert(phead);

	int size = 0;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}

	return size;
}
//��������
//*ע���ú�Ҫ��phead�ÿ�
void ListDestory(ListNode* phead)
{
	assert(phead);

	//�ӵ�һ����㿪ʼ����
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;//��ǰ����cur��next,����ͷ�cur���Ҳ�����
		free(cur);
		cur = next;
	}
	//����phead����,*ע��*������phead�������취:1.�������ָ��2.����ú���֮���һ��plist = NULL
	free(phead);
	//phead = NULL;//�������ã��˴�ѡ���ö���ָ����Ϊ�˱�֤�ӿڵ�һ����
}

//��ӡ
void ListPrint(ListNode* phead)
{
	//curָ��ͷ������һ�����
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
