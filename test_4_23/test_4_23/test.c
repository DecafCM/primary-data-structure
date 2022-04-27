#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//β�塢ͷ�塢ͷɾ��βɾ
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

//����
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
		printf("�ҵ���\n");
	}
	else
	{
		printf("û�ҵ�\n");
	}
	//�ҵ���
	//ͬʱ������ͨ��pos�Ը�λ�õ�ֵ�����޸�
	pos->data = 10;
	SListPrint(plist);//1->2->10->4->NULL
}

//��pos֮��֮ǰ�����㣬ɾ��pos��Ľ��
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
