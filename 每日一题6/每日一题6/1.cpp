#include<iostream>
#include<string>
using namespace std;

int main1()
{
	int a, b;
	cin >> a >> b;
	int x, y;
	int suba = 4 - (a % 4 ? a % 4 : 4);
	int subb = 4 - (b % 4 ? b % 4 : 4);
	x = a + suba;
	y = b + subb;
	int sum = x*y / 2;
	sum -= suba*(x / 2) + subb*(y / 2);
	if (suba == 0 || subb == 0)
	{
		//不做任何操作；
	}
	else if (suba == 3 && subb == 3)
	{
		sum += 5;
	}
	else if (suba == 1 && subb == 1)
	{
		sum++;
	}
	else if (suba == 1 || subb == 1)
	{
		sum += 2;
	}
	else
	{
		sum += 4;
	}
	cout << sum;
	system("pause");
	return 0;
}
int StrToInt(string str) 
{
	int res = 0;
	int i;
	int flag = 1;
	if (str.size() < 0)
	{
		return 0;
	}
	if (str[0] == '-') 
	{
		flag = -1;
	}
	for ( i = (str[0] == '+' || str[0] == '-' ? 1 : 0); i < str.size(); i++)
	{
		
		if (str[i] >= '0'&&str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
		}
		else
		{
			return 0;
		}
	}
	return res * flag;
}

int main()
{
	string str;
	getline(cin, str);
	cout << StrToInt(str);
	system("pause");
	return 0;

}