#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void findNumberOf1(int num)
{
	int counter = 0;
	while (num)
	{
		counter++;
		num = num & num - 1;
	}
	cout << counter << endl;
	return;
}

int main0()
{
	int num;
	while (cin >> num)
	{
		findNumberOf1(num);
	}
	return 0;
}


int findMinimum(int n, vector<int> left, vector<int> right) 
{
	int Min = 0; // 记录最终需要的手套数
	int min = 0; //记录如果有一个颜色手套数为0 则累加
	int lmin = INT_MAX; 
	int lsum = 0;
	int rmin = INT_MAX;
	int rsum = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(left[i] * right[i])) // 如果有一个为0 累加数量
		{
			min += left[i] + right[i];
		}
		else
		{
			lsum += left[i]; //左手套所有个数和
			rsum += right[i]; //右手套所有个数和
			lmin = left[i] < lmin ? left[i] : lmin;  //判断左手套那个颜色最少
			rmin = right[i] < rmin ? right[i] : rmin; //判断右手套那个颜色最少
		}
	}
	//最终的手套数用 有0的手套数量加上 （某个手的手套和减去颜色最少的手套在加上一）
	//两个数比较取较小的  然后再加上1，就是最终要取的数量
	Min = min + ((lsum - lmin + 1) < (rsum - rmin + 1) ? (lsum - lmin + 1) : (rsum - rmin + 1)) + 1;
	
	return Min;
}
int main()
{
	int n;
	cin >> n;
	vector<int> left;
	vector<int> right;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		left.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		right.push_back(tmp);
	}
	cout << findMinimum(n, left, right);
	system("pause");
	return 0;
}
