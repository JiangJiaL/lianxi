#include<iostream>
#include<vector>
using namespace std;
int max(int n)
{
	int i; int max = 0;
	vector<int> s(16);
	int j = 0;
	for (i = 0; i < 31; i++)
	{
		if ((n >> i) & 1 == 1)
		{
			max += 1;
		}
		else
		{
			max = s[j];
			j++;
			max = 0;
		}
	}
	int MAX = s[0];
	for (int k = 1; k <s.size() ; k++)
	{
		if (s[k] > MAX)
		{
			MAX = s[k];
		}
	}
	return MAX;
}
int main()
{
	int num;
	cin >> num;
	max(num);
	system("pause");
	return 0;
}