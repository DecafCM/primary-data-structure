#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


////静态的顺序表，并不实用
//#define N 100
//struct SeqList
//{
//	int a[N];
//	int size;
//};

//顺序表的动态存储

typedef int SeqDataType; //如果要修改则只需要修改这一处

typedef struct SeqList
{
	SeqDataType* a;
	int size;     //表示a中有多少个有效数据
	int capacity;  //表示a的空间到底有多大
}SeqList, SEQ;

//增删查改

//尾插
void SeqListPushBack(SeqList* pq, SeqDataType x);
//头插
void SeqListPushFront(SeqList* pq, SeqDataType x);
//头删
void SeqListPopFront(SeqList* pq);
//尾删
void SeqListPopBack(SeqList* pq);
//查找
int SeqListFind(SeqList* pq, SeqDataType x);
//修改
void SeqListModify(SeqList* pq, int pos, SeqDataType x);
//中间位置插入
void SeqListInsert(SeqList* pq, int pos, SeqDataType x);
//中间位置删除
void SeqListErase(SeqList* pq, int pos);
//初始化
void SeqListInit(SeqList *pq);
//销毁
void SeqListDestory(SeqList *pq);
//打印
void SeqListPrint(SeqList* pq);
//扩容
void SeqCheckCapacity(SeqList* pq);