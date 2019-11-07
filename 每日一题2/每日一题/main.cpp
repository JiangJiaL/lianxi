#include<iostream>
#include<vector>
using namespace std;
int Min_Test(vector <int> &A, int n)
{
	int i = 0;
	int count = 0;
	while (i < n)
	{
		if (A[i] >= A[i + 1])
		{
			i++;
			count++;
			while (i < (n - 1) && (A[i] >= A[i + 1]))
			{
				i++;
			}
		}
		else if (A[i] <= A[i + 1])
		{
			i++;
			count++;
			while (i < (n - 1) && (A[i] <= A[i + 1]))
			{
				i++;
			}
		}
		i++;
	}
	return count;

}

int main0()
{
	int n;
	cin >> n;
	vector <int> A(n);
	A.reserve(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		A.push_back(A[i]);
	}
	cout << Min_Test(A, n);

	system("pause");
	return 0;
}