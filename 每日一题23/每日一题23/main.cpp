#include <iostream>
#include<vector>
using namespace std;
int findMaxTimesNum(const vector<int> & v)
{
	int icount = 1;
	int num = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1])
		{
			icount++;
		}
		else
		{
			if (icount <= 1)
			{
				num = v[i];
			}
			else
			{
				icount--;
			}

		}
	}
	if (v.size() / 2 < count(v.begin(), v.end(), num))//返回num出现的次数 
	{
		return num;
	}
	return 0;
}

int main()
{
	int nums[] = { 0 };
	int n;
	for (auto & i : nums)
	{
		cin >> i;
	}
	cin >> n;
	vector<int> v;
	v.insert(v.begin(), nums, nums + n -1);
	cout << findMaxTimesNum(v);
	system("pause");
	return 0;
}
