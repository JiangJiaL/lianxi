#include<iostream>
using namespace std;
 
//判断三角形
int main0()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (((a + b)>c) && ((b + c)> a) && ((a + c)> b))
		{
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}


//求两个数的和 不用+运算符
int add(int a, int b)
{
	while (b != 0)
	{
		int sum = a ^ b; //相加后不包含进位的数据
		int tmp = (a & b) << 1; //得到两次相加的进位  直到结果为0
		a = sum; 
		b = tmp;
	}
	return a;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << add(a, b) << endl;
	}
	system("pause");
	return 0;

}