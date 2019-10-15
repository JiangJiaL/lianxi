#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int data[10] = { 15,18,30,35,36,45,48,53,72,93 };
	Heap hp;
	HeapInit(&hp, data, 10);
	HeapPrint(&hp);
	putchar('\n');
	HeapPush(&hp, 80);
	HeapPrint(&hp);
	putchar('\n');
	HeapPop(&hp);
	HeapPrint(&hp);
	putchar('\n');
	HeapSort(&hp);
	HeapPrint(&hp);
	//HeapPrint(&hp);
	putchar('\n');
	HeapDestory(&hp);
	system("pause");
	return 0;
}
