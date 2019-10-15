//#include"HighAcc.h"
//
//int main()
//{
//	string s1("123");
//	string s2("78");
//	HighAcc num1(s1);
//	HighAcc num2(s2);
//	cout << (string)(num1 + num2) <<endl;
//	cout << (string)(num1 * num2) <<endl;
//	system("pause");
//	return 0;
//}
//
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

void reserveOneWord(string &s, int spos, int epos)
{
	int i, j;
	for (i = spos, j = epos - 1; i < j; i++, j--)
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
		reserveOneWord(s, spos, epos);
		spos = epos + 1;
		epos = s.find(' ', spos);
	}
	reserveOneWord(s, spos, s.size());
	return s;
}
int main()
{
	cout << reserveWord("This way is not fit me");
	system("pause");
	return 0;
}
