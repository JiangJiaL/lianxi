#include<iostream>
#include<string>
using namespace std;

bool isLetterOrNumber(char ch)
{
	return (ch >= 'a'&&ch <= 'z') ||
		   (ch >= 'A'&&ch <= 'Z') ||
		   (ch >= '0'&&ch <= '9');
}
bool isSame(char a, char b)
{
	return a == b ||
  (a | (1 << 5)) == (b | (1 << 5));// 把大小写字母进行比较 （A a);
}
bool isPalindrome(string s) 
{
	string tmp;
	for (auto &ch : s)
	{
		if (isLetterOrNumber(ch))
		{
			tmp.push_back(ch);
		}
	}
	int i, j;
	for (i = 0, j = tmp.size() - 1; i < j; i++, j--)
	{
		if (!isSame(tmp[i], tmp[j]))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s(" race a car");
	string s1("abc d d cba");
	cout << isPalindrome(s) << endl;
	cout << isPalindrome(s1) <<endl;
	system("pause");
	return 0;
}