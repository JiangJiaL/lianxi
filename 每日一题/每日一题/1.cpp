#include<iostream>
#include<string>
using namespace std;
int main0()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	char buf[256] = { 0 };
	for (int i = 0; i < s2.size(); i++)
	{
		buf[s2[i]]++;
	}
	string ret;
	for (int i = 0; i < s1.size(); i++)
	{
		if (buf[s1[i]] == 0)
		{
			ret += s1[i];
		}
	}
	cout << ret << endl;
	system("pause");
	return 0;
}