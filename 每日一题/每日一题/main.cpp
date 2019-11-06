#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void bubble(vector<int>& arr, size_t len)
{
	size_t i = 0, j = 0;
	for (i = 0; i < len - 1; i++)
	{
		int count = 0; //是否进行交换的标记
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}


int AllSum()
{
	int n = 0;
	cin >> n;
	if (n == 0)
	{
		return 0;
	}
	while (n)
	{
		vector<int> arr(3 * n);
		long sum = 0;
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> arr[i];
		}
		bubble(arr, arr.size());
		for (int i = n; i < 3 * n - 1; i += 2)
		{
			sum += arr[i];
		}
		return sum;
	}
}
int main()
{
	cout << AllSum();
	system("pause");
	return 0;
}