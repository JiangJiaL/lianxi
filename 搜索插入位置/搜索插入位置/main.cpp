#include<iostream>
#include<vector>
using namespace std;

/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
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