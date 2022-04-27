#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����洢��������
typedef int SLTDataType;

//����һ��������
typedef struct SListNode
{
	SLTDataType data; //������
	struct SListNode* next; //ָ����
}SLTNode;

//����+����ͷ+ѭ��

//β��
void SListPushBack(SLTNode** plist, SLTDataType x);
//ͷ��
void SListPushFront(SLTNode** pplist, SLTDataType x);
//βɾ
void SListPopBack(SLTNode** pplist);
//ͷɾ
void SListPopFront(SLTNode** pplist);

//����
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//��������posλ��֮�����
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//����������֮ǰ���룬�鷳
//��������posλ��֮ǰ����(һ��ֱ��дInsert������֮ǰ����)
void SListInsert(SLTNode** plist, SLTNode* pos, SLTDataType x);

//ɾ��pos���һ�����
void SListEraseAfter(SLTNode* pos);

//��ӡ
void SListPrint(SLTNode* plist);