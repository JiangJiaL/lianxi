//#include <stdio.h>
#ifndef SORT_H
#define SORT_H

void ShellSort(int *src,int n);
void InsertSort(int *src, int n);
void MergeSort(int * src, int n);
void dealMergeSort(int *src, int *tmp, int start, int end);
#endif