#include<vector>
#include<iostream>
using namespace std;
int removeElement(vector<int>& nums, int val) 
{
	int i = 0;
	for (int j = 0; j < nums.size(); j++)
	{
		if (nums[j] != val)
		{
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}
int main()
{
	vector<int> nums = { 2, 3, 4, 3, 2 };
	int val = 3;
	cout << removeElement(nums, val);
	system("pause");
	return 0;
}