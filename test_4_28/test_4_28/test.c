#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//测试: 头插、尾插、头删、尾删
void TestList1()
{
	/*ListNode* plist;
	ListInit(&plist);*/
	ListNode* plist = ListInit();

	//不需要传二级指针，因为plist始终指向头结点的
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	
	//ListPrint(plist); //1 2 3 4

	ListPushFront(plist, 0);
	//ListPrint(plist); //0 1 2 3 4

	ListPopBack(plist);
	//ListPrint(plist); //0 1 2 3

	ListPopFront(plist);
	//ListPrint(plist); //1 2 3
}

void TestList2()
{
	ListNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);

	ListNode* pos = ListFind(plist, 4);
	
	ListInsert(pos, 40);//判断pos是否为空在该函数内部
	//ListPrint(plist); //1 2 3 40 4 5 6
}

int main()
{
	TestList1();
	return 0;
}