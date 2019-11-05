#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> tmp(numRows);
	tmp.resize(numRows);
	for (size_t i = 1; i < numRows; i++)
	{
		tmp[i - 1].resize(i, 0);

		tmp[i - 1][0] = 1;
		tmp[i - 1][i - 1] = 1;
	}
	size_t i, j;
	for (size_t i = 0; i < tmp.size(); i++)
	{
		for (size_t j = 0; j < tmp[i].size(); j++)
		{
			if (tmp[i][j] == 0)
			{
				tmp[i][j] = tmp[i - 1][j - 1] + tmp[i - 1][j];
			}
		}
	}

	return tmp;
}

vector<int> getRow1(int rowIndex) 
{
	vector<vector<int>> tmp(rowIndex+1);
	if (rowIndex == 0)
	{
		return{ 1 };
	}
	for (size_t i = 0; i <=rowIndex; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				tmp[i].push_back(1);
			}
			else
			{
				tmp[i].push_back(tmp[i - 1][j - 1] + tmp[i - 1][j]);
			}
		}
	}
	return tmp[rowIndex];
}


vector<int> getRow(int rowIndex) {
	vector<int> res(rowIndex + 1, 0);
	res[0] = 1;
	for (int i = 1; i<rowIndex + 1; i++)
	{
		for (int j = i; j >= 1; j--)
			res[j] += res[j - 1];
	}

	return res;
}

int main()
{
	vector<int> s = getRow(3);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << ' ';
	}
	system("pause");
	return 0;
}

