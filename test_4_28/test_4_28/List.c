#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//创建一个结点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

//初始化
//由于是双向带头循环链表，所以此时的next和prev都指向他们自己
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	//这样初始化可以让插入操作不需要单独考虑只有phead的情况
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	//assert(phead);

	////找尾
	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);
	////尾插
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	////如果插入第一个结点需不需要修改上述代码？ 并不
	////这就是双向带头循环链表的优势：结构虽然复杂但操作反而简单

	//代码复用
	//在phead前面插入，相当于尾删
	ListInsert(phead, x);
}

//头插
//同样不用考虑只有phead的情况
void ListPushFront(ListNode* phead, LTDataType x)
{
	//assert(phead);

	////用first记录下第一个结点后，头插时就不需要考虑插入的步骤
	//ListNode* first = phead->next;
	//ListNode* newnode = BuyListNode(x);
	//
	////头插 phead newnode first
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = first;
	//first->prev = newnode;
	
	//代码复用
	//相当于在head->next之前插入
	ListInsert(phead->next, x);
}

//尾删
//不用考虑phead后只有一个结点的情况，但要考虑使用该函数把链表删除到只剩phead时，再调用该函数就会删除phead
void ListPopBack(ListNode* phead)
{
	//assert(phead);

	//assert(phead->next != phead);//只剩phead的情况

	////找到尾结点及其前驱
	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev;

	////尾删
	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;

	//复用
	ListErase(phead->prev);

}

//头删
//也要考虑删除到只有phead的情况
void ListPopFront(ListNode* phead)
{
	/*assert(phead);

	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;

	free(first);

	phead->next = second;
	second->prev = phead;*/

	//复用
	ListErase(phead->next);
}

//查找
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

//在pos指针位置插入
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
//在pos指针位置删除
void ListErase(ListNode* pos)
{
	assert(pos);

	//找到pos的前驱后驱
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
	//当pos是phead->prev的时候就是尾删
	//pos是phead->next就是头删
}

//判空(空返回1，非空返回0)
int ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead ? 1 : 0;
}
//链表结点个数
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
//销毁链表
//*注调用后要把phead置空
void ListDestory(ListNode* phead)
{
	assert(phead);

	//从第一个结点开始销毁
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;//提前保存cur的next,免得释放cur后找不到了
		free(cur);
		cur = next;
	}
	//最后把phead销毁,*注意*想销毁phead有两个办法:1.传入二级指针2.用完该函数之后加一句plist = NULL
	free(phead);
	//phead = NULL;//不起作用，此处选择不用二级指针是为了保证接口的一致性
}

//打印
void ListPrint(ListNode* phead)
{
	//cur指向头结点的下一个结点
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
