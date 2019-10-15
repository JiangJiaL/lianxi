#define _CRT_SECURE_NO_WARNINGS
#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	BTNode * root = BinaryTreeCreate("ABDH##I##E##CF##G##");
	//int ret =  BinaryTreeSize(root);
	//printf("一共有%d个节点 \n", ret);
	//int rett =  BinaryTreeLeafSize(root);
	//printf("一共有%d个叶子节点 \n", rett);
	//int k = 0;
	//scanf("%d", &k);
	//int rettt =  BinaryTreeLevelKSize(root, k);
	//printf("第%d层有%d个节点 \n",k, rettt);
	//printf("先序遍历是：");
	//BinaryTreePrevOrder(root);//先序遍历 根左右
	//printf("\n");
	//printf("中序遍历是：");
	//BinaryTreeInOrder(root);
	//printf("\n");
	//printf("后序遍历是：");
	//BinaryTreePostOrder(root);
	//printf("\n");
	//printf("层序遍历是：");
	//BinaryTreeLeveorder(root);
	//printf("\n");
	//printf("先序遍历是：");
	//BinaryTreePrevOrderNonR(root);
	//printf("\n");
	//printf("中序遍历是：");
	//BinaryTreeInOrderNonR(root);
	//printf("\n");
	//printf("后序遍历是：");
	//BinaryTreePostOrderNonR(root);
	//printf("\n");
	printf("%d \n", BinaryTreeComplete(root));
	//BinaryTreeDestory(root);
	system("pause");
	return 0;
}