#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTree.h"
//顺序表的动态存储
#ifndef _Stack_H_
#define _Stack_H_
typedef BTNode * SLDataType;

typedef struct Stack
{
	SLDataType* array;  // 指向动态开辟的数组     
	size_t size;       // 有效数据个数  
	size_t capicity;   // 容量空间的大小 
}Stack;

// 基本增删查改接口 
void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);

void CheckCapacity(Stack* psl);
void StackPush(Stack* psl, SLDataType x);
void StackPop(Stack* psl);
SLDataType StackTop(Stack* psl);
int StackIsEmpty(Stack * psl);


// 扩展面试题实现
//void StackBubbleSort(Stack* psl); //冒泡
//int StackBinaryFind(Stack* psl, SLDataType x);//二分
//void StackRemoveAll(Stack* psl, SLDataType x); //删除所有
#endif

