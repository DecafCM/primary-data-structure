#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//尾插、头插、头删、尾删
void TestSList1()
{
	SLTNode * plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	//SListPrint(plist);//1->2->3->4->NULL

	SListPushFront(&plist, 0);
	//SListPrint(plist);//0->1->2->3->4->NULL

	SListPopBack(&plist);
	//SListPrint(plist);//0->1->2->3->NULL

	SListPopFront(&plist);
	SListPrint(plist);//1->2->3->NULL
}

//查找
void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SLTNode* pos = SListFind(plist, 3);
	if (pos != NULL)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
	//找到了
	//同时，可以通过pos对该位置的值进行修改
	pos->data = 10;
	SListPrint(plist);//1->2->10->4->NULL
}

//在pos之后、之前插入结点，删除pos后的结点
void TestSList3()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SLTNode* pos = SListFind(plist, 3);
	SListInsertAfter(pos, 30);
	//SListPrint(plist); //1->2->3->30->4->NULL
	SListInsert(&plist, pos, 300);
	//SListPrint(plist); //1->2->300->3->30->4->NULL
	SListEraseAfter(pos);
	//SListPrint(plist); //1->2->300->3->4->NULL

}

int main()
{
	TestSList3();
	return 0;
}
