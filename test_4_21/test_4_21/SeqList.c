#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//初始化
void SeqListInit(SeqList *pq)
{
	assert(pq);

	pq->a = NULL;
	pq->size = pq->capacity = 0;
}
//销毁
void SeqListDestory(SeqList *pq)
{
	free(pq->a);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}

//扩容
void SeqCheckCapacity(SeqList* pq)
{
	//如果满了，需要增容
	if (pq->size == pq->capacity)
	{
		//int newcapacity = pq->capacity * 2; //这样会存在问题，当一开始插入数据时，capacity为0，乘2后还是为0
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2; //如果capacity等于0了,则开辟4个空间
		SeqDataType* newA = realloc(pq->a, sizeof(SeqDataType*) * newcapacity);
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		pq->a = newA;
		pq->capacity = newcapacity;

	}
}

//尾插
void SeqListPushBack(SeqList* pq, SeqDataType x)
{
	assert(pq);

	//如果满了，需要增容
	SeqCheckCapacity(pq);

	pq->a[pq->size] = x;
	pq->size++;

}
//头插
void SeqListPushFront(SeqList* pq, SeqDataType x)
{
	assert(pq);

	//如果满了，需要增容
	SeqCheckCapacity(pq);

	//头插操作
	int end = pq->size - 1;
	while (end >= 0) //当end = -1时终止
	{
		//前面的元素以此向后移动
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	pq->a[0] = x;
	pq->size++;
}

//尾删
void SeqListPopBack(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0); //如果size为0了，没有元素了，谈何删除

	pq->size--;
	//注意，不能把pq->size置0，这不叫删除，且万一该数据就是0呢
}

//头删
void SeqListPopFront(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0);
	int begin = 0;
	//从下标1开始依次前移一个
	while (begin < pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];
		begin++;
	}
	pq->size--;
}

//查找
int SeqListFind(SeqList* pq, SeqDataType x)
{
	assert(pq);
	int i = 0;
	for (i = 0; i < pq->size; i++)
	{
		if (pq->a[i] == x)//若查找成功，返回下标
			return i;
	}
	return -1;
}

//修改
void SeqListModify(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);

	pq->a[pos] = x;
}

//中间位置插入
void SeqListInsert(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	//当pos = 0时     => 头插
	//当pos = size时  => 尾插 
	
	//如果已满，需要增容
	SeqCheckCapacity(pq);

	//把pos后面的数全部前移
	int end = pq->size - 1;
	while (end >= pos)
	{
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	//pos处放入x
	pq->a[pos] = x;
	pq->size++;
}

//中间位置删除
void SeqListErase(SeqList* pq, int pos)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	//当 pos = size - 1 => 尾删 
	//   pos = 0        => 头删
	int begin = pos;
	while (begin < pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];
		begin++;
	}

	pq->size--;
}

//打印
void SeqListPrint(SeqList* pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; ++i)
	{
		printf("%d ", pq->a[i]);
	}
}

