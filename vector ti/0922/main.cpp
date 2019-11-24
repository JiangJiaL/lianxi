#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
//
//int main()
//{
//	vector<int> v;
//	for (int i = 1; i <= 10; i++)
//	{
//		v.push_back(i);
//	}
//#if 0 // 插入
//	v.insert(v.begin() + 5, 20);
//
//	v.insert(v.begin() + 5, 3, 20);
//
//
//	v.insert(v.begin() + 5, v.begin(), v.end());
//
//
//	int a[5] = { 10, 20, 30, 40, 50 };
//	v.insert(v.begin() + 5, a + 1, a + 3);
//#endif
//#if 0 // 删除
//	v.erase(v.begin() + 5);
//
//	v.erase(v.begin() + 5, v.end() - 3);
//#endif
//
//	vector<int> v2;
//	for (int i = 1; i <= 10; i++)
//	{
//		v2.push_back(i);
//	}
//	v.swap(v2);
//
//	for (auto & i : v2)
//	{
//		cout << i << ' ';
//	}
//	cout << endl;
//
//
//	system("pause");
//	return 0;
//}
// 只出现一次的数字i


int singleNumber(vector<int >& nums)
{
	int res = 0;
	for (auto & i : nums)
	{
		res ^= i;
	}
	return res;
}

int main4()
{
	int nums[11] = { 1, 5, 6, 3, 5, 2, 1, 8, 6, 3, 8 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 11);
	cout << singleNumber(v);

	system("pause");
	return 0;
}


//杨辉三角OJ

#if 0
void PrintArray(const vector <int> & v, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}

void printGenerate(int n)
{
	vector <int> v(n, 0);
	v[0] = 1;
	PrintArray(v, 1);
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0; j--)
		{
			v[j] += v[j - 1];
		}
		PrintArray(v, i + 1);
	}
}

//一维数组

   
//二维数组
vector<vector<int>> genreate(int numRows)
{
	vector<vector<int>> data(numRows);
	if (numRows == 0)
	{
		return data;
	}
	int i, j;
	data[0].push_back(1);
	for (i = 1; i < numRows; i++)
	{
		data[i] = data[i - 1]; 
		for (j = i - 1; j > 0; j--)
		{
			data[i][j] += data[i][j - 1];
		}
		data[i].push_back(1);
	}
	return data;
}

int main2()
{

	vector<vector<int>>data =  genreate(10);
	for (auto &i : data)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}
	//printGenerate(10);
	system("pause");
	return 0;
}

 // 删除排序数组中的重复项
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		if (nums.size() == 0)
			return 0;
		int i = 0;
		int j;
		for (j = 1; j< nums.size(); j++)
		{
			if (nums[j] != nums[i])
			{
				i++;
				nums[i] = nums[j];
			}
		}
		return i + 1;
	}
};

//给定一个非空整数数组，除了某个元素只出现一次以外，
//其余每个元素均出现了三次。找出那个只出现了一次的元素。
int singleNumber(vector<int> & nums)
{
	int sum = 0;
	int tmp = 0;
	for (auto & i : nums)
	{
		sum = (sum ^ i) & ~tmp;
		tmp = (tmp ^ i) & ~sum;
	}
	return sum;
}



int _singleNumber(vector<int> & nums)
{
	int sum = 0 , count = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		for (auto j : nums)
		{
			count += j >> i & 1;
		}
		if (count % 3)
		{
			sum |= 1 << i;
		}
		count = 0;
	}
	return sum;
}
int main1()
{
	int nums[10] = { 2, 3, 5, 8, 5, 3, 2, 3, 5, 2 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 10);
	cout << _singleNumber(v);
	system("pause");
	return 0;
}


//数组中出现次数超过一半的数字 
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
	int nums[10] = { 3, 2, 7, 8, 2, 2, 2, 5, 2 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 9);
	cout << findMaxTimesNum(v);
	system("pause");
	return 0;
}




//电话号码的字母组合
//循环层数不确定 用递归

	namespace _tmp
	{
		string numLetter[] = { "abc", "def", "ghi", "jil", "mno", "pqrs", "tuv", "wxyz" };
	}


	void dealLetterCombinations(string &digits, size_t pos, vector<string> & alldata)
	{

		static string res = digits;
		if (pos < digits.size())
		{
			for (auto & i : _tmp::numLetter[digits[pos] - '2'])
			{
				res[pos] = i;
				dealLetterCombinations(digits, pos+1, alldata);
			}
		}
		else
		{
			cout << res << endl;
			alldata.push_back(res);
		}
		
	}
	vector<string> letterCombinations(string digits)
	{
		vector<string> res;
		
		dealLetterCombinations(digits, 0, res);
		return res;
	}


int main0()
{
	string digits = "23";
	vector<string>data = letterCombinations(digits);
	system("pause");
	return 0;
}

#endif
// 连续子数组的最大和
 //分治法
int dealMax(vector<int>array, int begin, int end)
{
	if (begin == end)
	{
		return array[begin];
	}
	int mid = (begin + end) / 2;
	int leftmax = dealMax(array, begin, mid);
	int rightmax = dealMax(array, mid + 1, end);

	int crossmax = 0;

	int i;
	int sum = 0;
	int tmpmax = array[mid];
	for (i = mid; i >= begin; i--)
	{
		sum += array[i];
		if (sum > tmpmax)
		{
			tmpmax = sum;
		}
	}
	crossmax += tmpmax;

	sum = 0;
	tmpmax = array[mid + 1];
	for (i = mid + 1; i <= end; i++)
	{
		sum += array[i];
		if (sum > tmpmax)
		{
			tmpmax = sum;
		}
	}
	crossmax += tmpmax;
	return max(max(leftmax, rightmax), crossmax);
}


int Max(vector<int> array)
{
	return dealMax(array, 0, array.size() - 1);
}

int main5()
{

	int data[] = { 6, -3, -2, 7, -15, 1, 2, 2, 4 };
	vector<int> num (data, data + 8);
	cout << Max(num);

	system("pause");
	return 0;
}



//动态规划求最大子段和
int FindGreatestSumOfSubArray(vector<int> array)
{
	int tmp = array[0];
	int maxpre = array[0];
	int i;
	for (i = 1; i < array.size(); i++)
	{
		if (maxpre > 0)
		{
			maxpre += array[i];
		}
		else
		{
			maxpre = array[i];
		}
		if (maxpre > tmp)
		{
			tmp = maxpre;
		}
	}
	return tmp;

}

int main()
{
	int data[] = { 6, -3, -2, 7, -15, 1, 2, 2, 4 };
	vector <int> v(data, data+9);
	cout << FindGreatestSumOfSubArray(v);

	system("pause");
	return 0;
}
