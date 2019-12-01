#include<iostream>
#include<vector>
#include<string>
using namespace std;



int max(int x, int y)
{
	int z = y;
	while (x%y != 0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}

int main0()
{
	int n; //表示怪物的数量
	
	int a; //表示初始能量
	while (cin >> n >> a)
	{
		while (n--)
		{
			int v;
			cin >> v;
			a = a + ((a > v) ? v : max(a, v));
		}
		cout << a << endl;
	}
	system("pause");
	return 0;
}



void firstUniqChar(string s)
{
	int count[26] = { 0 };
	for (auto & i : s)
	{
		count[i - 'a']++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (count[s[i] - 'a'] == 1)
		{
			cout << s[i] << endl;
			return;
		}
	}
	cout << -1 << endl;
}
int main()
{

	string s;
	while (cin >> s)
	{
		firstUniqChar(s);
	}
	//getline(cin, s);
	system("pause");
	return 0;
}