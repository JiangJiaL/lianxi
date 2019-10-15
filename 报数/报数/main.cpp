#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n) {
	if (n == 1)
	{
		return "1";
	}
	string tmp = countAndSay(n - 1);
	int count = 1;
	string ret;
	for (int i = 0; i < tmp.size(); i++)
	{
	
		if (tmp[i] == tmp[i + 1])
		{
			count++;
		}
		else
		{
			ret += to_string(count) + tmp[i];
			count = 1;
		}
	}
	return ret;
}
int main()
{
	cout << countAndSay(5);
	system("pause");
	return 0;
}