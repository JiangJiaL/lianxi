#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define BUFSIZE 10000
void printArray(int *src, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ", src[i]);
	}
	putchar('\n');
}

int main()
{
#if 1
	int src[10] = { 5, 3, 7, 2, 4, 6, 8, 1, 10, 9 };
	 
	//InsertSort (src,10);
	//ShellSort(src, 10);
	MergeSort(src, 10);
	printArray(src, 10);

#else
	srand (time(NULL));

	int src[BUFSIZE];
	for (int i = 0;i < BUFSIZE; i++)
	{
		src[i] = rand() % 5000 + 1;
	}
	//InsertSort(src, BUFSIZE);
	ShellSort(src, BUFSIZE);
	printArray(src, BUFSIZE);
#endif
	system("pause");
	return 0;
}