#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	string s1;

	int i = 0, j = 0;
	int flag = 0;
	while (cin >> s >> s1)
	{
		while (s[i] != '\0' || s1[j] != '\0')
		{
			if (s[i] == '*')
			{
				i++;
				flag = 1;
			}
			else if (s[i] == s1[j]||s[i] == '?')
			{
				i++;
				j++;

			}
			else if (flag == 1)
			{
				while (s1[j] != s[i])
				{
					j++;
				}
				flag = 0;
			}
			else
			{
				cout << "false" << endl;
				break;
			}
		}
		if (s[i] == '\0' && s1[j] == '\0')
		{
			cout << "true" << endl;
		}
	}

	system("pause");
	return 0;
}