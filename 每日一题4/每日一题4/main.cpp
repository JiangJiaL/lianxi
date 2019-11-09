#include<iostream>
using namespace std;
int main0()
{
	int A = 0, B = 0, C = 0;
	unsigned int a, b, c, d;
	cin >> a >> b >> c >> d;
	A = (a + c) / 2;
	B = (b + d) / 2;
	C = (d - b) / 2;
	if (A - B == a&& B - C == b&&A + B == c && B + C == d)
	{
		cout << A << ' ' << B << ' ' << C;
	}
	else
	{
		cout << 'No';
	}
	system("pause");
	return 0;
}

int main()
{
	string s = "";
	string tmp = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;
	if (M == 0)
	{
		s = "0";
	}
	while (M)
	{
		if (M < 0)
		{
			M = -M;
			cout << "-";
		}
		s = tmp[M%N] + s;
		M /= N;
	}
	cout << s.c_str() << endl;
	system("pause");
	return 0;
}









