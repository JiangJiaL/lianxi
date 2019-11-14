#include<iostream>
#include<vector>
#include<string>
using namespace std;
int min(int m,int n)
{
	int min = m > n ? m : n;
	if (m % n == 0 || n % m == 0)
	{
		return min;
	}
	while (!(min % n == 0 && min % m == 0))
	{
		min++;
	}
	return min;

}
int main1()
{
	int m, n; 
	cin >> m >> n;
	cout << min(m, n);
	system("pause");
	return 0;
}

bool letter(vector<string> & v, int n)
{
	int size = v[0].size();
	for (int i = 1; i < n; i++)
	{
		if (v[i].size() < size)
		{
			size = v[i].size();
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[j][i] - '0' > v[j+1][i] - '0')
				return false;
		}
	}
	return true;
}
bool length(vector<string> & v, int n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		if (v[i].size() > v[i + 1].size())
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int s = length(v, n);
	int m = letter(v, n);
	if (s&&m)
	{
		cout << "both";
	}
	else if (s)
	{
		cout << "length";
	}
	else if (m)
	{
		cout << "letter";
	}
	else
	{
		cout << "none";
	}

	system("pause");
	return 0;
}