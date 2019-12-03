#include<iostream>
#include<vector>
using namespace std;
int getMost(vector<vector<int> > board) 
{
	int i, j;
	for (i = 0; i < board.size(); i++)
	{
		for (j = 0; j < board.size(); j++)
		{
			if (i == 0 && j == 0)
			{
				//Æðµã
			}
			else if (i == 0)
			{
				board[0][j] += board[0][j - 1];
			}
			else if (j == 0)
			{
				board[i][0] += board[i - 1][0];
			}
			else
			{
				int tmp = board[i][j - 1];
				int tmp1 = board[i - 1][j];
				board[i][j] += (tmp > tmp1 ? tmp : tmp1);
			}
		}
	}
	return board[board.size() - 1][board.size() - 1];	
}
int main()
{
	
	int m , n;
	cin >> m >> n;
	vector<int> v(m,0);
	vector<vector<int>> board(n,v);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	cout << getMost(board);
	system("pause");
	return 0;
}