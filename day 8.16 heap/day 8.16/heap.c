#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void adjustDown(Heap* hp, int m) //���µ����㷨
{
	int cur = m;
	//int m; //ֵ
	int n; //�±�
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
		if (hp->data[cur] < hp->data[n])// ���ڵ������Һ��ӽϴ�ıȽϣ����ڵ�С�Ļ����н�����
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

void HeapInit(Heap* hp, HPDataType* a, int n) //�������ɶ� 
//�����һ����Ҷ�ӽڵ㿪ʼ����
{
	hp->capacity = n * 2;
	hp->size = n;
	hp->data = (HPDataType*)malloc(hp->capacity * sizeof(HPDataType));

	int  i;
	for (i = 0; i < n; i++)
	{
		hp->data[i] = a[i];
	}
	for (i = n / 2 - 1; i >= 0; i--)//�Ӻ���ǰ ��ÿһ����Ҷ�ӽڵ�������µ����㷨
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
	hp->data[hp->size] = x;//�����ֵ�ȷź����Ľڵ���
	hp->size++;
	while (cur > 0)
	{
		if (hp->data[cur] > hp->data[(cur - 1) / 2])//���ϵ����㷨
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
void HeapPop(Heap* hp) //ɾ�����Ԫ��(�Ѷ�)
{
	if (hp->size == 0)
	{
		return;
	}
	hp->size--;
	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];//���Ԫ�ص�������β��size--,ɾ��
	hp->data[hp->size] = tmp;
	adjustDown(hp, 0);
}
HPDataType HeapTop(Heap* hp) //���ضѶ�
{
	if (hp->size == 0)
	{
		return  (HPDataType)0;

	}
	return hp->data[0];
}
int HeapSize(Heap* hp) //���ش�С
{
	return hp->size;
}
int HeapEmpty(Heap* hp)//�����Ƿ�Ϊ��
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
	int tmp = hp->size; //���нڵ����
	while (hp->size > 1)
	{
		HeapPop(hp);//ÿ�ν���������ֵpop�����ų����⡣
	}
	hp->size = tmp; //
}