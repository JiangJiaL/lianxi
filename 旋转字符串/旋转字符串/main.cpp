#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool rotateString(string A, string B)
{
	if (A == B || (A.size() == 0 && B.size() == 0))
	{
		return true;
	}
	if (A.size() != B.size())
	{
		return false;
	}
	string tmp(A + A);
	int pos = 0;
	pos = tmp.find(B);
	if (pos > 0)
	{
		return true;
	}
	return false;
}
int main()
{
	string A("abcde");
	string B("cdeab");
	cout << rotateString(A, B);
	system("pause");
	return 0;
}