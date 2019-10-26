#include<iostream>
using namespace std;
//爬楼梯 可以理解成fib的变形
int climbStairs(int n) {
	if (n <= 2)
	{
		return n;
	}
	int a = 1;
	int b = 2;
	for (int i = 3; i <= n; i++)
	{
		int c = a + b;
		a = b;
		b = c;
	}
	return b;
}
int main()
{
	cout << climbStairs(6);
	system("pause");
	return 0;
}