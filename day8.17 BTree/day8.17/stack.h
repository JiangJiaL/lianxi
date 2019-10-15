#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTree.h"
//˳���Ķ�̬�洢
#ifndef _Stack_H_
#define _Stack_H_
typedef BTNode * SLDataType;

typedef struct Stack
{
	SLDataType* array;  // ָ��̬���ٵ�����     
	size_t size;       // ��Ч���ݸ���  
	size_t capicity;   // �����ռ�Ĵ�С 
}Stack;

// ������ɾ��Ľӿ� 
void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);

void CheckCapacity(Stack* psl);
void StackPush(Stack* psl, SLDataType x);
void StackPop(Stack* psl);
SLDataType StackTop(Stack* psl);
int StackIsEmpty(Stack * psl);


// ��չ������ʵ��
//void StackBubbleSort(Stack* psl); //ð��
//int StackBinaryFind(Stack* psl, SLDataType x);//����
//void StackRemoveAll(Stack* psl, SLDataType x); //ɾ������
#endif

