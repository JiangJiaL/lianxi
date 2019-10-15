#ifndef _LIST_H_
#define _LIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef int * QuDataType;
typedef struct QueueNode
{
	QuDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* plist);
void QueueDestory(Queue* plist);

void QueuePush(Queue* plist, QuDataType x);
void QueuePop(Queue* plist);
QuDataType QueueTop(Queue *plist);
int QueueIsEmpty(Queue * plist);
#endif