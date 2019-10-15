#ifndef _HEAP _H_

#define _HEAP _H_

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* data;
	int size;
	int capacity;
}Heap;
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp); //返回堆顶
int HeapSize(Heap* hp); //返回大小
int HeapEmpty(Heap* hp);//返回是否为空
void HeapSort(Heap* hp);
void HeapPrint(Heap* hp);

#endif 