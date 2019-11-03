#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums)
{
	int i;
	int sum = 0;
	for ( i = 0; i < nums.size(); i++)
	{
		sum ^= nums[i];
	}
	return sum;
}
int main()
{
	vector<int> nums = { 1, 2, 3, 4, 3, 2, 1 };
	cout <<singleNumber(nums);


	system("pause");
	return 0;
}