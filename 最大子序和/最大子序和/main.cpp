#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
	int max = nums[0];
	int sum = nums[0];
	int i = 1;
	if (nums.size() < 1)
	{
		return 0;
	}
	for (i = 1; i < nums.size(); i++)
	{
		if (sum < 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (sum>max)
		{
			max = sum;
		}
	}

	return max;
}

int main()
{
	vector <int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << maxSubArray(nums);
	system("pause");
	return 0;
}