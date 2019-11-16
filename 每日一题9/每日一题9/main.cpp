#include<iostream>
using namespace std;
int factorial(int a)
{
	int sum = 1;
	for (int i = a; i > 0; i--)
	{
		sum *= i;
	}
	return sum;
}
int factorial1(int a, int b)
{
	int sum = 1;
	for (int i = 0; i < b; i++)
	{
		sum *= a;
		a--;
	}
	return sum;
}


int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	int s = m + n;
	if (n == 0 && m == 0)
	{
		cout << n;
	}
	else if (n == 0 || m == 0)
	{
		int sum = 1;
		cout << sum;
	}
	else if (n&&m)
	{
		int ret = factorial1(s, n);
		int tmp = factorial(n);
		cout << (ret / tmp);
	}

	system("pause");
	return 0;
}