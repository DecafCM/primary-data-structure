#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


////��̬��˳�������ʵ��
//#define N 100
//struct SeqList
//{
//	int a[N];
//	int size;
//};

//˳���Ķ�̬�洢

typedef int SeqDataType; //���Ҫ�޸���ֻ��Ҫ�޸���һ��

typedef struct SeqList
{
	SeqDataType* a;
	int size;     //��ʾa���ж��ٸ���Ч����
	int capacity;  //��ʾa�Ŀռ䵽���ж��
}SeqList, SEQ;

//��ɾ���

//β��
void SeqListPushBack(SeqList* pq, SeqDataType x);
//ͷ��
void SeqListPushFront(SeqList* pq, SeqDataType x);
//ͷɾ
void SeqListPopFront(SeqList* pq);
//βɾ
void SeqListPopBack(SeqList* pq);
//����
int SeqListFind(SeqList* pq, SeqDataType x);
//�޸�
void SeqListModify(SeqList* pq, int pos, SeqDataType x);
//�м�λ�ò���
void SeqListInsert(SeqList* pq, int pos, SeqDataType x);
//�м�λ��ɾ��
void SeqListErase(SeqList* pq, int pos);
//��ʼ��
void SeqListInit(SeqList *pq);
//����
void SeqListDestory(SeqList *pq);
//��ӡ
void SeqListPrint(SeqList* pq);
//����
void SeqCheckCapacity(SeqList* pq);