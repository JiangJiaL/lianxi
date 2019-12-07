#include<iostream>
using namespace std;
int jumpFloorII(int number) {
	if (number <= 0)
	{
		return 0;
	}
	return 1 << (number - 1);
}
int main0()
{
	int n;
	cin >> n;
	cout << jumpFloorII(n);

	system("pause");
	return 0;
}


int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		double s = 2 * 3.14 * r;
		if (s < n)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	system("pause");
	return 0;
}