#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//≤‚ ‘Õ∑≤Â°¢Œ≤≤Â°¢Õ∑…æ°¢Œ≤…æ
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	//SeqListPrint(&s); //1 2 3 4 5

	SeqListPushFront(&s, 0);
	
	//SeqListPrint(&s); //0 1 2 3 4 5
	
	SeqListPopBack(&s);
	//SeqListPrint(&s); //0 1 2 3 4 

	SeqListPopFront(&s);
	//SeqListPrint(&s); //1 2 3 4 

	SeqListDestory(&s);
}

//≤‚ ‘÷–º‰≤Â»Î°¢…æ≥˝°¢–ﬁ∏ƒ
void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

	SeqListInsert(&s, 2, 30);
	//SeqListPrint(&s);//1 2 30 3 4 5

	SeqListErase(&s, 0);
	//SeqListPrint(&s);//2 30 3 4 5

	SeqListModify(&s, 1, 3);
	SeqListPrint(&s);//2 3 3 4 5

	SeqListDestory(&s);
}

int main()
{
	TestSeqList2();
	return 0;
}

