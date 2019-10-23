#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums)
{
	int count = 0;
	for (auto i = nums.begin(); i != nums.end(); )
	{
		if (*i == 0)
		{
			i = nums.erase(i);
			count++;
		}
		else
		{
			i++;
		}
	}
	nums.insert(nums.end(), count,0);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
}
int main()
{
	vector<int> nums = { 0, 1, 0, 3, 12 };
	moveZeroes(nums);
	system("pause");
	return 0;
}