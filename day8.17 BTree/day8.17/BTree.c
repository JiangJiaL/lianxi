#include "BTree.h"
#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
BTNode* BinaryTreeCreate(BTDataType* src)

{
	static int s_n = 0;
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	BTNode * cur = (BTNode *)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;
	cur->lchild = BinaryTreeCreate(src);
	cur->rchild = BinaryTreeCreate(src);

	return cur;
}


void BinaryTreeDestory(BTNode* root) //后序遍历销毁
{
	if (root)
	{
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);

	}
}

int BinaryTreeSize(BTNode* root)//有多少节点
{
	static int count = 0;
	if (root)
	{
		BinaryTreeSize(root->lchild);
		BinaryTreeSize(root->rchild);
		//putchar(root->data);//打印根节点
		count++;		
	}
	return count;
}
int BinaryTreeLeafSize(BTNode* root)//有多少叶子 
{
	static int count = 0;
	if (root)
	{
		BinaryTreeLeafSize(root->lchild);
		BinaryTreeLeafSize(root->rchild);
		if (root->lchild == NULL && root->rchild == NULL)
		{
			count++;
		}
		//putchar(root->data);//打印根节点
	}
	return count;	
}
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	static int count = 0;
//	if (k == 1)
//	{
//		count++;
//	}
//	if (root && k > 0)
//	{
//		BinaryTreeLevelKSize(root->lchild, k-1);
//		BinaryTreeLevelKSize(root->rchild, k-1);
//	}
//	return count;
//}
int BinaryTreeLevelKSize(BTNode* root, int k)//求第几层有几个节点

{

	if (root == NULL)
		return 0;
	{
		if (k == 1)   //k为1时才会返回1
			return 1;
	}
	return BinaryTreeLevelKSize(root->lchild, k - 1)
		+ BinaryTreeLevelKSize(root->rchild, k - 1);
}
// 遍历
void BinaryTreePrevOrder(BTNode* root) //先序遍历 根左右 （递归）
{
	if (root)
	{
		putchar(root->data);//打印根节点
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}	
}
void BinaryTreeInOrder(BTNode* root) //中序遍历 左根右 （递归）
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
	
}
void BinaryTreePostOrder(BTNode* root)//后序遍历  左右根 （递归）
{
	if (root)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->data);
		
	}
}

// 层序遍历

// 判断二叉树是否是完全二叉树
void BinaryTreeLeveorder(BTNode* root)//层序遍历
{
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);//初始化队列
	QueuePush(&qu, root);//入队列
	while (!QueueIsEmpty(&qu))//队列不为空
	{
		cur = QueueTop(&qu); //cur 等于队列头
		putchar(cur->data); //输出cur
		if (cur->lchild) // 左孩子存在
		{
			QueuePush(&qu, cur->lchild);//左孩子入队列
		}
		if (cur->rchild)//右孩子存在
		{
			QueuePush(&qu, cur->rchild); //右孩子入队列
		}
		QueuePop(&qu);//队头元素出队列
	}
	QueueDestory(&qu);//销毁
}

// 非递归遍历
void BinaryTreePrevOrderNonR(BTNode* root) // 先序遍历   （非递归）
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100); //初始化栈
	while (cur) 
	{
		putchar(cur->data); //打印当前根节点的值
		if (cur->rchild) //右孩子存在
		{
			StackPush(&st, cur->rchild); //右孩子入栈
		}
		if (cur->lchild) //左孩子存在
		{
			cur = cur->lchild; //根节点为左孩子
		}
		else//没有左孩子取栈顶
		{
			cur = StackTop(&st); //取到空时，遍历结束
			StackPop(&st); //出栈
		}
	}
	StackDestory(&st);
}
void BinaryTreeInOrderNonR(BTNode* root) //中序遍历  （非递归）
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st,100);
	while (cur || !StackIsEmpty(&st))//(1)
	{
		for (; cur; cur = cur->lchild)//将当前节点及左孩子入栈 （链表遍历)
		{
			StackPush(&st, cur);
		}
		    cur = StackTop(&st);//取出栈顶 (1、右孩子为空，for循环不进直接取栈顶。
			//2、如果右孩子不为空，那么这是一个没有左孩子的节点。
			//第一种情况是左子树访问完毕，第二种情况是右子树为空。
			//无论哪种，当前节点都要打印。）
			/*if (!cur )
			{
			break;
			}*/
			putchar(cur->data);
			StackPop(&st);
			cur = cur->rchild;
		
	}
	StackDestory(&st);
}
void BinaryTreePostOrderNonR(BTNode* root)//后序遍历  （非递归）
{
	char tag[64];
	Stack st;
	BTNode* cur = root;
	StackInit(&st, 100);

	do
	{
		for (; cur; cur = cur->lchild)//将当前节点及左孩子入栈 （链表遍历）
		{
			StackPush(&st, cur);//左孩子入栈
			tag[st.size - 1] = 0;//重置左子树访问标记（LT）
		}
		while (!StackIsEmpty(&st)&&tag[st.size - 1])//栈不为空并且标记为1 
			//前面的条件只在最后一次循环跳出时生效
			//后面的条件分两种情况
			//1、当cur为空时，上面的for不进，此条件成立。
			//2、当cur不为空，上面的for进，此条件不成立。
			//如果检测到当前的LT被置位，那么在打印完当前节点后，再去直接检查上一个节点（父节点）也要被打印了（LT置位，证明）
		{
			cur = StackTop(&st); //取栈顶
			putchar(cur->data);//打印
			StackPop(&st);//出栈
		}
		if (!StackIsEmpty(&st))//栈不为空 //此条件只在最后一次循环跳出时生效
		{
			cur = StackTop(&st);//取栈顶
			//1、如果上面的while进了，那么证明左子树访问完毕，给LT置位
			//2、如果上面的while没进，那么证明左子树不存在，给LT置位
			tag[st.size - 1] = 1;//标记改为1
			cur = cur->rchild; //取右孩子
			//左子树访问完毕后，访问呢右子树
		}
			//
	} while (!StackIsEmpty(&st));//由于后序遍历中根节点最后出栈前，栈不可能为空，所以以根节点是否为空判断
	StackDestory(&st);
}
int BinaryTreeComplete(BTNode* root)//判断是否为完全二叉树
{
	Queue qu;
	BTNode * cur;
	int tag = 0;
	QueueInit(&qu);//初始化队列
	QueuePush(&qu, root);//入队列
	while (!QueueIsEmpty(&qu))//队列不为空
	{
		cur = QueueTop(&qu); //cur 等于队列头
		putchar(cur->data); //输出cur
		if (cur->rchild && !cur->lchild)
		{
			return 0;
		}
		if (tag && (cur->rchild || cur->lchild))
		{
			return 0;
		}
		if (cur->lchild) // 左孩子存在
		{
			QueuePush(&qu, cur->lchild);//左孩子入队列
		}
		
		if (cur->rchild)//右孩子存在
		{
			QueuePush(&qu, cur->rchild); //右孩子入队列
		}
		else
		{
			tag = 1;
		}
		QueuePop(&qu);//队头元素出队列
	}
	QueueDestory(&qu);//销毁
	return 1;
}

