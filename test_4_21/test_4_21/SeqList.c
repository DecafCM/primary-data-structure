#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ʼ��
void SeqListInit(SeqList *pq)
{
	assert(pq);

	pq->a = NULL;
	pq->size = pq->capacity = 0;
}
//����
void SeqListDestory(SeqList *pq)
{
	free(pq->a);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}

//����
void SeqCheckCapacity(SeqList* pq)
{
	//������ˣ���Ҫ����
	if (pq->size == pq->capacity)
	{
		//int newcapacity = pq->capacity * 2; //������������⣬��һ��ʼ��������ʱ��capacityΪ0����2����Ϊ0
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2; //���capacity����0��,�򿪱�4���ռ�
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

//β��
void SeqListPushBack(SeqList* pq, SeqDataType x)
{
	assert(pq);

	//������ˣ���Ҫ����
	SeqCheckCapacity(pq);

	pq->a[pq->size] = x;
	pq->size++;

}
//ͷ��
void SeqListPushFront(SeqList* pq, SeqDataType x)
{
	assert(pq);

	//������ˣ���Ҫ����
	SeqCheckCapacity(pq);

	//ͷ�����
	int end = pq->size - 1;
	while (end >= 0) //��end = -1ʱ��ֹ
	{
		//ǰ���Ԫ���Դ�����ƶ�
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	pq->a[0] = x;
	pq->size++;
}

//βɾ
void SeqListPopBack(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0); //���sizeΪ0�ˣ�û��Ԫ���ˣ�̸��ɾ��

	pq->size--;
	//ע�⣬���ܰ�pq->size��0���ⲻ��ɾ��������һ�����ݾ���0��
}

//ͷɾ
void SeqListPopFront(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0);
	int begin = 0;
	//���±�1��ʼ����ǰ��һ��
	while (begin < pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];
		begin++;
	}
	pq->size--;
}

//����
int SeqListFind(SeqList* pq, SeqDataType x)
{
	assert(pq);
	int i = 0;
	for (i = 0; i < pq->size; i++)
	{
		if (pq->a[i] == x)//�����ҳɹ��������±�
			return i;
	}
	return -1;
}

//�޸�
void SeqListModify(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);

	pq->a[pos] = x;
}

//�м�λ�ò���
void SeqListInsert(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	//��pos = 0ʱ     => ͷ��
	//��pos = sizeʱ  => β�� 
	
	//�����������Ҫ����
	SeqCheckCapacity(pq);

	//��pos�������ȫ��ǰ��
	int end = pq->size - 1;
	while (end >= pos)
	{
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	//pos������x
	pq->a[pos] = x;
	pq->size++;
}

//�м�λ��ɾ��
void SeqListErase(SeqList* pq, int pos)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	//�� pos = size - 1 => βɾ 
	//   pos = 0        => ͷɾ
	int begin = pos;
	while (begin < pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];
		begin++;
	}

	pq->size--;
}

//��ӡ
void SeqListPrint(SeqList* pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; ++i)
	{
		printf("%d ", pq->a[i]);
	}
}

