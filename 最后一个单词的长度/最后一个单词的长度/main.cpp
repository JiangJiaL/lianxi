#include<iostream>
#include<string>
using namespace std;

int lengthOfLastWord(string s)
{
	if (s.size() == 0)
	{
		return 0;
	}
	int tmp = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			tmp++;
		}
		else
		{
			if (tmp != 0)
			return tmp;
		}
	}
	return tmp;
	
}
int main()
{
	string s("a ");
	int ret = lengthOfLastWord(s);
	cout << ret;
	system("pause");
	return 0;
}