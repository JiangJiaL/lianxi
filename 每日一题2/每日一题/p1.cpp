#include<iostream>
#include<string>
using namespace std;
void resreveOneWord(string& s, int spos, int epos)
{
	int i, j;
	for (i = spos, j = epos; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
}
string reserveWord(string s)
{
	int spos = 0;
	int epos = s.find(' ');
	while (epos >= 0)
	{
		resreveOneWord(s, spos, epos - 1);
		spos = epos + 1;
		epos = s.find(' ', spos);
	}
	resreveOneWord(s, spos, s.size() - 1);
	return s;
}
int main()
{
	string s;
	getline(cin, s);
	resreveOneWord(s, 0, s.size() - 1);
	cout << reserveWord(s) << endl;
	system("pause");
	return 0;
}
