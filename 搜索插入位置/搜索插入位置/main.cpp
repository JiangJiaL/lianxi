#include<iostream>
#include<vector>
using namespace std;

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
*/


int searchInsert1(vector<int>& nums, int target)
{
	int i;
	for (i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target || nums[i] > target)
		{
			return i;
		}
	}
	return nums.size();
}
int searchInsert(vector<int>& nums, int target) 
{
	int i;
	for (i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
		{
			return i;
		}
	}
	int k = 0;
	if (target < nums[0])
	{
		return 0;
	}
	else
	{
		k++;
	}
	while (k < nums.size())
	{
		if (target > nums[k - 1] && target < nums[k])
		{
			return k;
		}
		k++;
	}
		return nums.size();
}
int main()
{
	vector<int> nums = { 1, 3, 5, 6 };
	int a = 7;
	cout << searchInsert1(nums, a);
	system("pause");
	return 0;
}