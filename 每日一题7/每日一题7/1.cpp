#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int Fib(int n)
{
	if (n == 0 || n == 1)
	{
		return 0;
	}
	int a = 1, b = 1;
	int c = 0;
	int arr[100] = { 0 };
	int i = 0;
	while (n > c)
	{
		c = a + b;
		a = b;
		b = c;
		arr[i] = c;
		i++;
	}
	int min = (arr[i-1] - n) < (arr[i - 2] - n)*(-1) ? arr[i-1] - n : (arr[i - 2] - n)*(-1);
	return min;
}
int main1()
{
	int n;
	cin >> n;
	 cout << Fib(n);
	system("pause");
	return 0;
}

bool chkParenthesis(string A, int n) 
{
	if (A[0] == ')')
		return false;
	int count = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (A[i] == '(' || A[i] == ')')
		{
			if (A[i] == '(')
			{
				count++;
			}
			else if (A[i] == ')')
			{
				count--;
			}
			if (count < 0)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
			
	}
		return true;
	
}

int main2()
{
	cout << chkParenthesis("()a()()", 7);
	system("pause");
	return 0;
}



