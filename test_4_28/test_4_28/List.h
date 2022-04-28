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

//创建一个结点
ListNode* BuyListNode(LTDataType x);
//初始化
ListNode* ListInit();
//尾插
void ListPushBack(ListNode* phead, LTDataType x);
//头插
void ListPushFront(ListNode* phead, LTDataType x);
//尾删
void ListPopBack(ListNode* phead);
//头删
void ListPopFront(ListNode* phead);
//查找
ListNode* ListFind(ListNode* phead, LTDataType x);
//在pos指针位置(前面)插入
void ListInsert(ListNode* pos, LTDataType x);
//在pos指针位置删除
void ListErase(ListNode* pos);
//判空(空返回1，非空返回0)
int ListEmpty(ListNode* phead);
//链表结点个数
int ListSize(ListNode* phead);
//销毁链表
void ListDestory(ListNode* phead);
//打印
void ListPrint(ListNode* phead);
