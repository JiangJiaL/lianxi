#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void adjustDown(Heap* hp, int m) //向下调整算法
{
	int cur = m;
	//int m; //值
	int n; //下标
	while (cur * 2 + 1 < hp->size)
	{
		if (cur * 2 + 2 >= hp->size)
		{
			n = cur * 2 + 1;
		}
		else
		{
			if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2])
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (hp->data[cur] < hp->data[n])// 根节点与左右孩子较大的比较，根节点小的话进行交换。
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;

			cur = n;
		}
		else
		{
			break;
		}
	}

}

void HeapInit(Heap* hp, HPDataType* a, int n) //把数组变成堆 
//从最后一个非叶子节点开始遍历
{
	hp->capacity = n * 2;
	hp->size = n;
	hp->data = (HPDataType*)malloc(hp->capacity * sizeof(HPDataType));

	int  i;
	for (i = 0; i < n; i++)
	{
		hp->data[i] = a[i];
	}
	for (i = n / 2 - 1; i >= 0; i--)//从后向前 对每一个非叶子节点进行向下调整算法
	{
		adjustDown(hp, i);
	}
}
void HeapDestory(Heap* hp)
{
	if (hp->data)
	{
		free(hp->data);
	}
	hp->data = NULL;
	hp->size = 0;
	hp->capacity = 0;
}
void HeapPush(Heap* hp, HPDataType x) //
{
	if (hp->size == hp->capacity)
	{
		hp->capacity *= 2;
		hp->data = (HPDataType *)realloc(hp->data, hp->capacity * sizeof(HPDataType));
	}
	int cur = hp->size;
	hp->data[hp->size] = x;//插入的值先放后最后的节点上
	hp->size++;
	while (cur > 0)
	{
		if (hp->data[cur] > hp->data[(cur - 1) / 2])//向上调整算法
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[(cur - 1) / 2];
			hp->data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Heap* hp) //删除最大元素(堆顶)
{
	if (hp->size == 0)
	{
		return;
	}
	hp->size--;
	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];//最大元素调整到队尾，size--,删掉
	hp->data[hp->size] = tmp;
	adjustDown(hp, 0);
}
HPDataType HeapTop(Heap* hp) //返回堆顶
{
	if (hp->size == 0)
	{
		return  (HPDataType)0;

	}
	return hp->data[0];
}
int HeapSize(Heap* hp) //返回大小
{
	return hp->size;
}
int HeapEmpty(Heap* hp)//返回是否为空
{
	return hp->size = 0;
}

void HeapPrint(Heap* hp)
{
	int  i;
	int rn = 0;
	int bin = 2;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
		if (i == rn)
		{
			putchar('\n');
			rn += bin;
			bin = bin * 2;
		}
	}
}

void HeapSort(Heap* hp) 
{
	int tmp = hp->size; //堆中节点个数
	while (hp->size > 1)
	{
		HeapPop(hp);//每次将队中最大的值pop出，排出堆外。
	}
	hp->size = tmp; //
}