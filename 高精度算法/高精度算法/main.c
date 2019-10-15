#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct HighAcc
{
	char data[1000];
	int len;
}HighAcc;

HighAcc add(HighAcc a, HighAcc b)
{
	HighAcc sum = { 0 };
	int i;
	int tmp;
	int maxlen = a.len > b.len ? a.len : b.len; //找出长度比较长的一组的长度
	
	//高精度加核心代码
	for (i = 0; i < maxlen; i++)
	{
		tmp = a.data[i] + b.data[i] + sum.data[i]; //
		sum.data[i] = tmp % 10;
		sum.data[i + 1] = tmp / 10;
	}
	sum.len = maxlen + sum.data[maxlen]; //判断是否需要补1
	//

	return sum;
}
HighAcc mul(HighAcc a, HighAcc b)
{
	HighAcc sum = { 0 };
	int i,j;
	int tmp;
	//当其中的一个乘数为0时 直接结果等于0
	if (a.len == 1 && a.data[0] == 0 || b.len == 1 && b.data[0] == 0)
	{
		sum.len = 1;
		return sum;
	}
	for (i = 0; i < a.len; i++)
	{
		for (j = 0; j < b.len; j++)
		{
			tmp = a.data[i] * b.data[j] + sum.data[i + j];
			sum.data[i + j] = tmp % 10;
			sum.data[i + j + 1] += tmp / 10;
		}
	}
	sum.len = a.len + b.len - !(sum.data[a.len + b.len - 1]);
	return sum;

}
void dealnumber(HighAcc *h) //反转字符 为了使计算时数字低位对齐 并将字符换成数字
{
	int i = 0;
	char tmp;
	int j = strlen(h->data) - 1;
	h->len = j + 1;
	for (; i <= j; i++, j--)
	{
		tmp = h->data[i];
		h->data[i] = h->data[j] - '0';
		h->data[j] = tmp - '0';
	}
}
void printNumber(HighAcc h)
{
	int i;
	for (i = h.len - 1; i >= 0; i--)
	{
		putchar(h.data[i] + '0');
	}

}
int main()
{
	HighAcc a = { 0 }; 
	HighAcc b = { 0 };
	HighAcc sum = { 0 };
	scanf("%s%s", a.data, b.data);
	dealnumber(&a);
	dealnumber(&b);
	
	sum = mul(a,b);

	printNumber(sum);
	system("pause");
	return 0;
}
#endif