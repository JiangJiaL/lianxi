#include<iostream>
#include<vector>

using namespace std;

int binInsert(int n, int m, int j, int i) {
	m = m << j;
	n = n | m;
	return  n;
}
int main0()
{
	int n, m, j, i;
	cin >> n >> m >> j >> i;
	cout << binInsert(n, m, j, i);
	system("pause");
	return 0;
}
bool IsPrime(int n)
{
	for (int j = 2; j < n; j++)
	{
		if (n % j == 0)
			return false;
	}
	return true;

}
void allPrime(int n)
{
	vector<int> v;
	for (int i = 2; i < n; i++)
	{
		if (IsPrime(i))
		v.push_back(i);
	}
	
	int min = n;
	int k, j;
	int ret1, ret2;
	for ( k = 0; k < v.size(); k++)
	{
		for ( j = k; j < v.size(); j++)
		{
			if (((v[j] - v[k]) < min) && (v[j] + v[k]) == n)
			{
				min = v[j] - v[k];
			    ret1 = v[j];
				ret2 = v[k];
			}
		}

	}
	cout << ret1 << endl;
	cout << ret2;
}



//做法2
bool IsPrime(int n)
{
	for (int j = 2; j < n; j++)
	{
		if (n % j == 0)
			return false;
	}
	return true;

}
void allPrime(int n)
{
	if (n > 2)
	{
		int ret1 = n / 2 - 1;
		int ret2 = n / 2 + 1;
		//只要有一个不是素数就继续找
		while (!IsPrime(ret1) || !IsPrime(ret2))
		{
			ret1++;
			ret2--;
		}
		//说明两个都是素数
		cout << ret1 << endl;
		cout << ret2 << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	allPrime(n);
	system("pause");
	return 0;
}
