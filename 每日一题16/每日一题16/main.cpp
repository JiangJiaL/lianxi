#include<iostream>
#include<vector>
//#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int perfectNum(int n)
{
	int count = 0;
	for (int j = 1; j <= n; j++)
	{
		int sum = 0;
		for (int i = 1; i <= j / 2 ; i++)
		{
			if (j % i == 0)
			{
				sum += i;
			}
		}
		if (sum == j)
		{
			count++;
		}
	}
	return count;
	
}
int main0()
{
	int n;
	while (cin >> n)
	{
		cout << perfectNum(n);
	}
	
	system("pause");
	return 0;
}







vector<string> split(string str, char sep)
{
	stringstream ss(str);
	string tmp;
	vector<string> res;
	while (getline(ss, tmp, sep))
	{
		res.push_back(tmp);
	}
	return res;
}

int judgepoker(vector<string> poker)
{
	int flag = -1;
	if (poker.size() == 1)
	{
		flag = 0; // 单个
	}
	else if (poker.size() == 2)
	{
		if (poker[0] == string("joker") || poker[1] == string("joker"))
		{
			flag = 5; // 对王
		}
		else
		{
			flag = 1;//普通对子
		}
	}
	else if (poker.size() == 3)
	{
		flag = 2; // 三个；
	}
	else if (poker.size() == 4)
	{
		flag = 3;//炸弹
	}
	else if (poker.size() == 5)
	{
		flag = 4; // 顺子
	}
	return flag;
}
int main()
{
	string str;
	vector<string> table = { "3", "4", "5", "6", "7", "8",
		                     "9", "10", "J", "Q", "K", "A", "2","joker","JOKER" };
	while (getline(cin, str))
	{
		int win = -1; // 0 表示不能比较，1 表示第一幅，2表示第二幅

		vector<string> vec = split(str, '-');
		vector<string> poker1 = split(vec[0], ' ');
		vector<string> poker2 = split(vec[1], ' ');
		int flag1 = -1;
		int flag2 = -1;
		flag1 = judgepoker(poker1);
		flag2 = judgepoker(poker2);
		if (flag1 == 5 || flag2 == 5 || flag1 == 3 || flag2 == 3)
		{
			if (flag1 == 5)
			{
				win = 1; // 一方有对王；
			}
			else if (flag2 == 5)
			{
				win = 2;
			}
			else if (flag1 == flag2 && flag1 == 3)//双方都是炸弹
			{
				auto it1 = find(table.begin(), table.end(), poker1[0]);
				auto it2 = find(table.begin(), table.end(), poker2[0]);
				if (it1 < it2)
				{
					win = 2;
				}
				else
				{
					win = 1;
				}
			}
			else if (flag1 == 3 && flag2 != 3)
			{
				win = 1;
			}
			else if (flag1 != 3 && flag2 == 3)
			{
				win = 2;
			}
		}
		else if (flag1 == flag2)
		{
			auto it1 = find(table.begin(), table.end(), poker1[0]);
			auto it2 = find(table.begin(), table.end(), poker2[0]);
			if (it1 < it2)
			{
				win = 2;
			}
			else
			{
				win = 1;
			}
		}
		else
		{
			win = 0;
		}
		if (!win)
		{
			cout << "ERROR" << endl;
		}
		else if (win == 1)
		{
			int i = 0;
			for (; i < poker1.size()-1; i++)
			{
				cout << poker1[i] << ' ';
			}
			cout << poker1[i] << endl;
		}
		else if (win == 2)
		{
			int i = 0;
			for (; i < poker2.size()-1; i++)
			{
				cout << poker2[i] << ' ';
			}
			cout << poker2[i] << endl;
		}

	}
	system("pause");
	return 0;
}
