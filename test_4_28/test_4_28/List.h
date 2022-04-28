#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

//����һ�����
ListNode* BuyListNode(LTDataType x);
//��ʼ��
ListNode* ListInit();
//β��
void ListPushBack(ListNode* phead, LTDataType x);
//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);
//βɾ
void ListPopBack(ListNode* phead);
//ͷɾ
void ListPopFront(ListNode* phead);
//����
ListNode* ListFind(ListNode* phead, LTDataType x);
//��posָ��λ��(ǰ��)����
void ListInsert(ListNode* pos, LTDataType x);
//��posָ��λ��ɾ��
void ListErase(ListNode* pos);
//�п�(�շ���1���ǿշ���0)
int ListEmpty(ListNode* phead);
//���������
int ListSize(ListNode* phead);
//��������
void ListDestory(ListNode* phead);
//��ӡ
void ListPrint(ListNode* phead);
