#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main0()
{
	int T, n, k;
	cin >> T;
	
	while (T--)
	{
		cin >> n >> k;
		vector<int> cards(2 * n);
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> cards[i];	
		}
		
		while (k--)
		{
			vector<int> tmp(cards.begin(),cards.end());
			for (int i = 0; i < n; i++)
			{
				cards[2 * i] = tmp[i];
				cards[2 * i + 1] = tmp[i + n];
			}
		}
			for (int i = 0; i < 2 * n - 1; i++)
			{
				cout<< cards[i] << " ";
				
			}
			cout << cards[2 * n - 1] << endl;
	}
	system("pause");
	return 0;
}


int main()
{
	int n;
	string s;
	while (cin >> n>>s)
	{
		int flag = 1;//当前光标的编号；
		int first = 1;//当前页的第一首歌曲
		if (n <= 4) //当歌曲少于等于4首 不用翻页
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (flag == 1 && s[i] == 'U')
				{
					flag = n;//光标挪到最后一首歌
				}
				else if (flag == n && s[i] == 'D')
				{
					flag = 1; //光标挪到第一首歌；
				}
				else if (s[i] == 'U')
				{
					flag--;
				}
				else
				{
					flag++;
				}
			}
			for (int i = 1; i < n; i++)
			{
				cout << i << ' ';
			}
			cout << n << endl;
			cout << flag << endl;
		}
		else //大于4
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (first == 1 && flag == 1 && s[i] == 'U')
				{
					flag = n;
					first = n - 3;
				}
				else if (first == n - 3 && flag == n && s[i] == 'D')
				{
					flag = 1;
					first = 1;
				}
				else if (first != 1 && flag == first && s[i] == 'U')
				{
					flag--;
					first--;
				}
				else if (first != n - 3 && flag == first + 3 && s[i] == 'D')
				{
					flag++;
					first++;

				}
				else if (s[i] == 'U')
				{
					flag--;
				}
				else
				{
					flag++;
				}
			}
			for (int i = first; i < first + 3; i++)
			{
				cout << i << ' ';
			}
			cout << first + 3<<endl;
			cout << flag << endl;
		}
	}
	system("pause");
	return 0;
}