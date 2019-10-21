#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int i = 0,j = 0;
	
	while (i < m && j < n)
	{
		if (nums1[i] <= nums2[j])
		{
			i++;
		}
		else
		{
			m += 1;
			for (int k = m; k > i + 1; k--)
			{
				nums1[k - 1] = nums1[k - 2];
			}
			nums1[i] = nums2[j];
			j++;
		}
	}
	while (j < n)
	{
		nums1[i++] = nums2[j++];
	}
	for (int s = 0; s < nums1.size(); s++)
	{
		cout << nums1[s] << ' ';
	}
}
int main()
{
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	merge(nums1, 3, nums2, 3);
	system("pause");
	return 0;
}