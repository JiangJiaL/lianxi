#include <stdio.h>
#include <stdlib.h>
static void adjustDown(int * data, int size, int m) //向下调整算法
{
	int cur = m;
	//int m; //值
	int n; //下标
	while (cur * 2 + 1 < size)
	{
		if (cur * 2 + 2 >= size)
		{
			n = cur * 2 + 1;
		}
		else
		{
			if (data[cur * 2 + 1] > data[cur * 2 + 2])
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (data[cur] < data[n])// 根节点与左右孩子较大的比较，根节点小的话进行交换。
		{
			int tmp = data[cur];
			data[cur] = data[n];
			data[n] = tmp;

			cur = n;
		}
		else
		{
			break;
		}
	}

}
void SwapHeap(int * data, int size) //删除最大元素(堆顶)
{
	if (size == 0)
	{
		return;
	}
	int tmp = data[0];
	data[0] = data[size - 1];//最大元素调整到队尾，size--,删掉
	data[size - 1] = tmp;
	adjustDown(data, size - 1, 0);
}

void HeapSortS(int * src, int n) //把数组变成堆 
//从最后一个非叶子节点开始遍历
{
	int  i;
	for (i = n / 2 - 1; i >= 0; i--)//从后向前 对每一个非叶子节点进行向下调整算法
	{
		adjustDown(src, n, i);
	}
	for (; n > 1; n--)
	{
		SwapHeap(src, n);
	}
}
void printArray(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);

	}
	putchar("\n");
}


int main()
{
	int data[10] = { 6, 2, 5, 4, 1, 9, 8, 10, 7, 3 };
	HeapSortS(data, 10);
	printArray(data, 10);
	system("pause");
	return 0;

}