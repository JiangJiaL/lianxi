#include<iostream>
#include<string>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) 
{
	int i, j;
	for (i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
}
int main0()
{

	vector<char> s1;
	s1.push_back('a');
	s1.push_back('b');
	s1.push_back('c');
	s1.push_back('d');
	s1.push_back('e');
	reverseString(s1);
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	system("pause");
	return 0;
}