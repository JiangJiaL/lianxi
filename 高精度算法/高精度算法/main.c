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
	int maxlen = a.len > b.len ? a.len : b.len; //�ҳ����ȱȽϳ���һ��ĳ���
	
	//�߾��ȼӺ��Ĵ���
	for (i = 0; i < maxlen; i++)
	{
		tmp = a.data[i] + b.data[i] + sum.data[i]; //
		sum.data[i] = tmp % 10;
		sum.data[i + 1] = tmp / 10;
	}
	sum.len = maxlen + sum.data[maxlen]; //�ж��Ƿ���Ҫ��1
	//

	return sum;
}
HighAcc mul(HighAcc a, HighAcc b)
{
	HighAcc sum = { 0 };
	int i,j;
	int tmp;
	//�����е�һ������Ϊ0ʱ ֱ�ӽ������0
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
void dealnumber(HighAcc *h) //��ת�ַ� Ϊ��ʹ����ʱ���ֵ�λ���� �����ַ���������
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