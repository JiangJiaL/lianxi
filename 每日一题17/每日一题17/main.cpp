#include <iostream>
#include <vector>
using namespace std;

int getRow(int line)
{
	vector<vector<int>> res;
	vector<int> tmp(1, 1);
	res.push_back(tmp);
	for (int i = 1; i < line; i++) {
		tmp.clear();
		for (int j = 0; j < 2 * i + 1; j++) 
		{
			int sum = 0;
			if (j >= 2 && j<2 * i + 1)
				sum += res[i - 1][j - 2];
			if (j >= 1 && j<2 * i)
				sum += res[i - 1][j - 1];
			if (j >= 0 && j < 2 * i - 1)
				sum += res[i - 1][j];
			tmp.push_back(sum);
		}
		res.push_back(tmp);
	}
	int arr = -1;
	for (int i = 0; i < 2 * line - 1; i++) {
		if ((res[line - 1][i] % 2) == 0) {
			arr = i + 1;
			i = 2 * line;
		}
	}
	return arr;
}
int main0()
{
	int line;
	while (cin >> line) 
	{	
		cout << getRow(line) << endl;
	}
	return 0;
}
