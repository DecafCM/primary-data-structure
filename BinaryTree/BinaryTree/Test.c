#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

//ǰ�����
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//�������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//�������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

//�������
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	//ע����ʱ���е�data��ŵ������ڵ��ָ��
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->data);
		
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");

	QueueDestroy(&q);
}

//����һ���������ڵ�
BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//�����нڵ����
//˼·һ�����������ķ�ʽ (Ϊ�˱�֤ÿ�εݹ�ʹ�õ���ͬһ��size���Դ˴�������ָ�룬��ÿ�ε��øú���ǰҪ�Ȱ�size��0)
//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//	{
//		return ;
//	}
//	++(*psize);
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

//˼·��: ��������(�����㷨)
//1. ���Ϊ�� 0���ڵ�
//2. ����ǿ� �������ڵ���� + �������ڵ���� + 1(�Լ�)
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//������Ҷ�ӽڵ�ĸ��� (��֧˼��)
//1. ����           return 0
//2. Ҷ��           return 1
//3. �ǿ��Ҳ���Ҷ�� return ������Ҷ�ڵ����+������Ҷ�ڵ����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	
}

//�����е�k�������(k > 0)
//�ɻ���Ϊ����ڵ����������ĵ�k-1��֮�ͣ��Դ����ƣ�ֱ��k = 1ʱ���൱��ֻ��һ�������
//1. ����                return 0
//2. k���ֵ���1          return 1
//3. �ǿ���k��δ���ֵ�1  return �������ĵ�k-1��ڵ��� + �������ĵ�k-1��ڵ��� 
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}
	
	return TreeKLevelSize(root->left, k-1) + TreeKLevelSize(root->right, k-1);
}

//��������ֵΪx���Ǹ����
//˼·��
//1.root == NULL return NULL
//2.root�ڵ㲻��Ҫ�ҵ��Ǹ���㣬�ȵ�����ȥ�ң����û�����ٵ���ȥ��
//3.���Ҷ�û�У�����NULL
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}
	
	BTNode* lret = TreeFind(root->left, x);  //��¼���������Ҳ����������ظ�����
	BTNode* rret = TreeFind(root->right, x); //��¼����������
	//��������������ҵ���,����
	if (lret)
	{
		return lret;
	}
	//�������ҵ��ˣ�����
	if(rret)
	{
		return rret;
	}
	//���Ҷ�û�ҵ������ؿ�
	return NULL;
}

//������������
//����Ȼ�󰤸��ͷſռ�(�ú������)
//����һ��ָ�����Ұָ�����⣬���øú��������root�ֶ��ÿ�
//void BinaryTreeDstory(BTNode** pproot)//������ָ����Ϊ��������root�ÿ�,һ��ָ��ı䲻��root����Ϊ�˱��ֽӿ�һ���Ի��Ǵ�һ��ָ��
void BinaryTreeDstory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//�ݹ���������
	BinaryTreeDstory(root->left);
	//�ݹ���������
	BinaryTreeDstory(root->right);
	//���ٸ�
	free(root);
	//���øú��������root�ֶ��ÿ�
}

//�ж϶������Ƿ�Ϊ��ȫ������
//�عˣ���ȫ������ǰn-1�������ģ����һ�����������
//˼·��1.�����������(�������ڣ����Һ�������ǿս��Ҳ���)�����ղ�������ߣ��ڵ���������
//2.�������ȫ�������������г��Ľڵ���NULLʱ���������ʣ��ڵ�Ӧȫ��ΪNULL
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		//��ͷ����
		QueuePop(&q);
		if (front == NULL)//�����ʱ��ͷΪ�գ�������ѭ�����Զ���ʣ�½ڵ���м��
		{
			break;
		}
		//���ͷ�����Һ���
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	//������ʣ����
	while(!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)//����зǿ�Ԫ�أ�˵��������ȫ������
			return false;
	}

	QueueDestroy(&q);
	return  true; //����ȫ�ǿգ�˵������ȫ������
}

int main()
{
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');

	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;

	PrevOrder(A);  //A B D NULL NULL NULL C E NULL NULL F NULL NULL
	printf("\n");
	InOrder(A);    //NULL D NULL B NULL A NULL E NULL C NULL F NULL
	printf("\n");
	PostOrder(A);  //NULL NULL D NULL B NULL NULL E NULL NULL F C A
	printf("\n");

	////˼·һ�ķ�ʽ�������нڵ����
	//int size = 0;
	//TreeSize(A, &size);
	//printf("TreeSize = %d\n", size);
	//size = 0;
	//TreeSize(A, &size);
	//printf("TreeSize = %d\n", size);

	//˼·���ķ�ʽ�������нڵ����
	printf("TreeSize = %d\n", TreeSize(A));  //6
	printf("TreeSize = %d\n", TreeSize(A));  //6

	printf("TreeLeafSize = %d\n", TreeLeafSize(A)); //3

	printf("TreeKLevelSize = %d\n", TreeKLevelSize(A, 3)); //3

	//���ҳɹ��Ͳ���ʧ��
	printf("TreeFind:%p\n", TreeFind(A, 'E'));//00C6C5C8
	printf("TreeFind:%p\n", TreeFind(A, 'X'));//00000000

	//�������
	TreeLevelOrder(A); //A B C D E F

	//�ж���ȫ������
	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A)); //BinaryTreeComplete:0

	BinaryTreeDstory(A);

	return 0;
}