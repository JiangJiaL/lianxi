#include<iostream>
#include<string>
using namespace std;
//树根 例如 39 就是3 + 9=12 -> 1+ 2 = 3 树根就是3 
int main()
{
	string s;
	while (getline(cin,s))
	{
		int n = 0;
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			n += s[i] - '0';
		}
		if (n < 10)
		{
			sum = n;
		}
		else
		{
			while (n / 10)
			{
				int tmp = n % 10;
				int tmp1 = n / 10;
				n = tmp + tmp1;
			}
			sum = n;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}