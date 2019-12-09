#include<iostream>
#include<vector>
using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len)
{
	int i = 0, j = 1;
	while (i < len && j < len)
	{
		if ((arr[i] % 2) == 0)
		{
			i += 2;
			continue;
		}
		if ((arr[j] % 2) != 0)
		{
			j += 2;
			continue;
		}
		swap(arr[i], arr[j]);
	}
}
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };


	oddInOddEvenInEven(v, 9);
	for (auto &i : v)
	{
		cout << i <<' ';
	}

	system("pause");
	return 0;
}
