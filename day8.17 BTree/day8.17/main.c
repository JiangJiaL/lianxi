#define _CRT_SECURE_NO_WARNINGS
#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	BTNode * root = BinaryTreeCreate("ABDH##I##E##CF##G##");
	//int ret =  BinaryTreeSize(root);
	//printf("һ����%d���ڵ� \n", ret);
	//int rett =  BinaryTreeLeafSize(root);
	//printf("һ����%d��Ҷ�ӽڵ� \n", rett);
	//int k = 0;
	//scanf("%d", &k);
	//int rettt =  BinaryTreeLevelKSize(root, k);
	//printf("��%d����%d���ڵ� \n",k, rettt);
	//printf("��������ǣ�");
	//BinaryTreePrevOrder(root);//������� ������
	//printf("\n");
	//printf("��������ǣ�");
	//BinaryTreeInOrder(root);
	//printf("\n");
	//printf("��������ǣ�");
	//BinaryTreePostOrder(root);
	//printf("\n");
	//printf("��������ǣ�");
	//BinaryTreeLeveorder(root);
	//printf("\n");
	//printf("��������ǣ�");
	//BinaryTreePrevOrderNonR(root);
	//printf("\n");
	//printf("��������ǣ�");
	//BinaryTreeInOrderNonR(root);
	//printf("\n");
	//printf("��������ǣ�");
	//BinaryTreePostOrderNonR(root);
	//printf("\n");
	printf("%d \n", BinaryTreeComplete(root));
	//BinaryTreeDestory(root);
	system("pause");
	return 0;
}