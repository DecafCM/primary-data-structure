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

//前序遍历
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
//中序遍历
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
//后序遍历
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

//层序遍历
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	//注：此时队列的data里放的是树节点的指针
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

//创建一个二叉树节点
BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//求树中节点个数
//思路一：遍历计数的方式 (为了保证每次递归使用的是同一个size所以此处传的是指针，且每次调用该函数前要先把size置0)
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

//思路二: 子问题拆解(分治算法)
//1. 如果为空 0个节点
//2. 如果非空 左子树节点个数 + 右子树节点个数 + 1(自己)
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//求树中叶子节点的个数 (分支思想)
//1. 空树           return 0
//2. 叶子           return 1
//3. 非空且不是叶子 return 左子树叶节点个数+右子树叶节点个数
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

//求树中第k层结点个数(k > 0)
//可划分为求根节点左、右子树的第k-1层之和，以此类推，直到k = 1时，相当于只有一个根结点
//1. 空树                return 0
//2. k划分到了1          return 1
//3. 非空且k还未划分到1  return 左子树的第k-1层节点数 + 右子树的第k-1层节点数 
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

//查找树中值为x的那个结点
//思路：
//1.root == NULL return NULL
//2.root节点不是要找的那个结点，先到左树去找，如果没有在再到树去找
//3.左右都没有，返回NULL
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
	
	BTNode* lret = TreeFind(root->left, x);  //记录左子树查找操作，避免重复操作
	BTNode* rret = TreeFind(root->right, x); //记录右子树查找
	//如果在左子树中找到了,返回
	if (lret)
	{
		return lret;
	}
	//右子树找到了，返回
	if(rret)
	{
		return rret;
	}
	//左右都没找到，返回空
	return NULL;
}

//二叉树的销毁
//遍历然后挨个释放空间(用后序遍历)
//传入一级指针存在野指针问题，调用该函数后，需把root手动置空
//void BinaryTreeDstory(BTNode** pproot)//传二级指针是为了在最后把root置空,一级指针改变不了root，但为了保持接口一致性还是传一级指针
void BinaryTreeDstory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//递归销毁左树
	BinaryTreeDstory(root->left);
	//递归销毁右树
	BinaryTreeDstory(root->right);
	//销毁根
	free(root);
	//调用该函数后，需把root手动置空
}

//判断二叉树是否为完全二叉树
//回顾：完全二叉树前n-1层是满的，最后一层从左到右连续
//思路：1.借助层序遍历(区别在于，左右孩子如果是空结点也入队)，按照层序遍历走，节点是连续的
//2.如果是完全二叉树，当队列出的节点是NULL时，队列里的剩余节点应全部为NULL
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
		//队头出队
		QueuePop(&q);
		if (front == NULL)//如果此时队头为空，则跳出循环，对队列剩下节点进行检查
		{
			break;
		}
		//入队头的左右孩子
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	//检查队列剩余结点
	while(!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)//如果有非空元素，说明不是完全二叉树
			return false;
	}

	QueueDestroy(&q);
	return  true; //队内全是空，说明是完全二叉树
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

	////思路一的方式计算树中节点个数
	//int size = 0;
	//TreeSize(A, &size);
	//printf("TreeSize = %d\n", size);
	//size = 0;
	//TreeSize(A, &size);
	//printf("TreeSize = %d\n", size);

	//思路二的方式计算树中节点个数
	printf("TreeSize = %d\n", TreeSize(A));  //6
	printf("TreeSize = %d\n", TreeSize(A));  //6

	printf("TreeLeafSize = %d\n", TreeLeafSize(A)); //3

	printf("TreeKLevelSize = %d\n", TreeKLevelSize(A, 3)); //3

	//查找成功和查找失败
	printf("TreeFind:%p\n", TreeFind(A, 'E'));//00C6C5C8
	printf("TreeFind:%p\n", TreeFind(A, 'X'));//00000000

	//层序遍历
	TreeLevelOrder(A); //A B C D E F

	//判断完全二叉树
	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A)); //BinaryTreeComplete:0

	BinaryTreeDstory(A);

	return 0;
}