#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//方便存储其他类型
typedef int SLTDataType;

//定义一个链表结点
typedef struct SListNode
{
	SLTDataType data; //数据域
	struct SListNode* next; //指针域
}SLTNode;

//单向+不带头+循环

//尾插
void SListPushBack(SLTNode** plist, SLTDataType x);
//头插
void SListPushFront(SLTNode** pplist, SLTDataType x);
//尾删
void SListPopBack(SLTNode** pplist);
//头删
void SListPopFront(SLTNode** pplist);

//查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//单链表在pos位置之后插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//并不建议在之前插入，麻烦
//单链表在pos位置之前插入(一般直接写Insert就是在之前插入)
void SListInsert(SLTNode** plist, SLTNode* pos, SLTDataType x);

//删除pos后的一个结点
void SListEraseAfter(SLTNode* pos);

//打印
void SListPrint(SLTNode* plist);