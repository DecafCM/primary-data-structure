#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//����: ͷ�塢β�塢ͷɾ��βɾ
void TestList1()
{
	/*ListNode* plist;
	ListInit(&plist);*/
	ListNode* plist = ListInit();

	//����Ҫ������ָ�룬��Ϊplistʼ��ָ��ͷ����
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
	
	ListInsert(pos, 40);//�ж�pos�Ƿ�Ϊ���ڸú����ڲ�
	//ListPrint(plist); //1 2 3 40 4 5 6
}

int main()
{
	TestList1();
	return 0;
}