#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n )
	{
		if (n == 0)
		{
			break;
		}
		int count = 0;
		long long sum = 1;
		while (sum < n)
		{
			sum *= 3;
			count++;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}