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


void BinaryTreeDestory(BTNode* root) //�����������
{
	if (root)
	{
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);

	}
}

int BinaryTreeSize(BTNode* root)//�ж��ٽڵ�
{
	static int count = 0;
	if (root)
	{
		BinaryTreeSize(root->lchild);
		BinaryTreeSize(root->rchild);
		//putchar(root->data);//��ӡ���ڵ�
		count++;		
	}
	return count;
}
int BinaryTreeLeafSize(BTNode* root)//�ж���Ҷ�� 
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
		//putchar(root->data);//��ӡ���ڵ�
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
int BinaryTreeLevelKSize(BTNode* root, int k)//��ڼ����м����ڵ�

{

	if (root == NULL)
		return 0;
	{
		if (k == 1)   //kΪ1ʱ�Ż᷵��1
			return 1;
	}
	return BinaryTreeLevelKSize(root->lchild, k - 1)
		+ BinaryTreeLevelKSize(root->rchild, k - 1);
}
// ����
void BinaryTreePrevOrder(BTNode* root) //������� ������ ���ݹ飩
{
	if (root)
	{
		putchar(root->data);//��ӡ���ڵ�
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}	
}
void BinaryTreeInOrder(BTNode* root) //������� ����� ���ݹ飩
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
	
}
void BinaryTreePostOrder(BTNode* root)//�������  ���Ҹ� ���ݹ飩
{
	if (root)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->data);
		
	}
}

// �������

// �ж϶������Ƿ�����ȫ������
void BinaryTreeLeveorder(BTNode* root)//�������
{
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);//��ʼ������
	QueuePush(&qu, root);//�����
	while (!QueueIsEmpty(&qu))//���в�Ϊ��
	{
		cur = QueueTop(&qu); //cur ���ڶ���ͷ
		putchar(cur->data); //���cur
		if (cur->lchild) // ���Ӵ���
		{
			QueuePush(&qu, cur->lchild);//���������
		}
		if (cur->rchild)//�Һ��Ӵ���
		{
			QueuePush(&qu, cur->rchild); //�Һ��������
		}
		QueuePop(&qu);//��ͷԪ�س�����
	}
	QueueDestory(&qu);//����
}

// �ǵݹ����
void BinaryTreePrevOrderNonR(BTNode* root) // �������   ���ǵݹ飩
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100); //��ʼ��ջ
	while (cur) 
	{
		putchar(cur->data); //��ӡ��ǰ���ڵ��ֵ
		if (cur->rchild) //�Һ��Ӵ���
		{
			StackPush(&st, cur->rchild); //�Һ�����ջ
		}
		if (cur->lchild) //���Ӵ���
		{
			cur = cur->lchild; //���ڵ�Ϊ����
		}
		else//û������ȡջ��
		{
			cur = StackTop(&st); //ȡ����ʱ����������
			StackPop(&st); //��ջ
		}
	}
	StackDestory(&st);
}
void BinaryTreeInOrderNonR(BTNode* root) //�������  ���ǵݹ飩
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st,100);
	while (cur || !StackIsEmpty(&st))//(1)
	{
		for (; cur; cur = cur->lchild)//����ǰ�ڵ㼰������ջ ���������)
		{
			StackPush(&st, cur);
		}
		    cur = StackTop(&st);//ȡ��ջ�� (1���Һ���Ϊ�գ�forѭ������ֱ��ȡջ����
			//2������Һ��Ӳ�Ϊ�գ���ô����һ��û�����ӵĽڵ㡣
			//��һ�������������������ϣ��ڶ��������������Ϊ�ա�
			//�������֣���ǰ�ڵ㶼Ҫ��ӡ����
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
void BinaryTreePostOrderNonR(BTNode* root)//�������  ���ǵݹ飩
{
	char tag[64];
	Stack st;
	BTNode* cur = root;
	StackInit(&st, 100);

	do
	{
		for (; cur; cur = cur->lchild)//����ǰ�ڵ㼰������ջ �����������
		{
			StackPush(&st, cur);//������ջ
			tag[st.size - 1] = 0;//�������������ʱ�ǣ�LT��
		}
		while (!StackIsEmpty(&st)&&tag[st.size - 1])//ջ��Ϊ�ղ��ұ��Ϊ1 
			//ǰ�������ֻ�����һ��ѭ������ʱ��Ч
			//������������������
			//1����curΪ��ʱ�������for������������������
			//2����cur��Ϊ�գ������for������������������
			//�����⵽��ǰ��LT����λ����ô�ڴ�ӡ�굱ǰ�ڵ����ȥֱ�Ӽ����һ���ڵ㣨���ڵ㣩ҲҪ����ӡ�ˣ�LT��λ��֤����
		{
			cur = StackTop(&st); //ȡջ��
			putchar(cur->data);//��ӡ
			StackPop(&st);//��ջ
		}
		if (!StackIsEmpty(&st))//ջ��Ϊ�� //������ֻ�����һ��ѭ������ʱ��Ч
		{
			cur = StackTop(&st);//ȡջ��
			//1����������while���ˣ���ô֤��������������ϣ���LT��λ
			//2����������whileû������ô֤�������������ڣ���LT��λ
			tag[st.size - 1] = 1;//��Ǹ�Ϊ1
			cur = cur->rchild; //ȡ�Һ���
			//������������Ϻ󣬷�����������
		}
			//
	} while (!StackIsEmpty(&st));//���ں�������и��ڵ�����ջǰ��ջ������Ϊ�գ������Ը��ڵ��Ƿ�Ϊ���ж�
	StackDestory(&st);
}
int BinaryTreeComplete(BTNode* root)//�ж��Ƿ�Ϊ��ȫ������
{
	Queue qu;
	BTNode * cur;
	int tag = 0;
	QueueInit(&qu);//��ʼ������
	QueuePush(&qu, root);//�����
	while (!QueueIsEmpty(&qu))//���в�Ϊ��
	{
		cur = QueueTop(&qu); //cur ���ڶ���ͷ
		putchar(cur->data); //���cur
		if (cur->rchild && !cur->lchild)
		{
			return 0;
		}
		if (tag && (cur->rchild || cur->lchild))
		{
			return 0;
		}
		if (cur->lchild) // ���Ӵ���
		{
			QueuePush(&qu, cur->lchild);//���������
		}
		
		if (cur->rchild)//�Һ��Ӵ���
		{
			QueuePush(&qu, cur->rchild); //�Һ��������
		}
		else
		{
			tag = 1;
		}
		QueuePop(&qu);//��ͷԪ�س�����
	}
	QueueDestory(&qu);//����
	return 1;
}

