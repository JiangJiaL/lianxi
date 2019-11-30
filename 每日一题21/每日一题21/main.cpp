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
		int flag = 1;//��ǰ���ı�ţ�
		int first = 1;//��ǰҳ�ĵ�һ�׸���
		if (n <= 4) //���������ڵ���4�� ���÷�ҳ
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (flag == 1 && s[i] == 'U')
				{
					flag = n;//���Ų�����һ�׸�
				}
				else if (flag == n && s[i] == 'D')
				{
					flag = 1; //���Ų����һ�׸裻
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
		else //����4
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