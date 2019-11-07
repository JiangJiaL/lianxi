#include<iostream>
#include<string>
#include<vector>
using namespace std;

void resreveOneWord(string& s, int spos, int epos)
{
	int i, j;
	for (i = spos, j = epos ; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
}

string reverseStr(string s, int k)
{
	int spos = 0;
	int epos = k;
	int size = s.size();
	while (spos < size - 1)
	{
		epos = spos + k;
		if (epos > size)
		{
			epos = size;
		}
		resreveOneWord(s, spos, epos - 1);
		spos += 2 * k;
	}
	return s;
}
string reserveWord(string s)
{
	int spos = 0;
	int epos = s.find(' ');
	while (epos >= 0)
	{
		resreveOneWord(s, spos, epos-1);
		spos = epos + 1;
		epos = s.find(' ', spos);
	}
	resreveOneWord(s, spos, s.size()-1);
	return s;
}
int main()
{
	string s("This is your book");
	cout << reserveWord(s) << endl;
	system("pause");
	return 0;
}


