#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main0()
{
	string s;
	getline(cin, s);
	
	for (int i = 0,j = s.size()-1; i < j; i++, j--)
	{
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	cout << s << endl;
	system("pause");
	return 0;
}


int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	if (s1.size() > s2.size())
	{
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	vector<vector<int>> count (s1.size(),vector<int>(s2.size(),0));
	int max = 0;
	for (int i = 0; i < s1.size();i++)
	{
		for (int j = 0; j < s2.size();j++)
		{
			if (s1[i] == s2[j])
			{
				if (i >= 1 && j >= 1)
				{
					count[i][j] = count[i - 1][j - 1] + 1;
				}
				else
				{
					count[i][j] = 1;
				}
			}
			if (max < count[i][j])
			{
				max = count[i][j];
			}
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}