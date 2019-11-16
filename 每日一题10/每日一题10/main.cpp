#include<iostream>
#include<string>
#include<vector>
using namespace std;


int length(string & pPasswordStr)
{
	int size = pPasswordStr.size();
	if (size <= 4)
	{
		return 5;
	}
	else if (size >= 5 && size <= 7)
	{
		return 10;
	}
	else if (size >= 8)
	{
		return 25;
	}
}

int letter(string & pPasswordStr)
{
	int size = pPasswordStr.size();
	int flag = 0, flag1 = 0;
	for (int i = 0; i < size; i++)
	{
		if (pPasswordStr[i] >= 'a' && pPasswordStr[i] <= 'z')
		{
			flag = 1;
		}
		else if (pPasswordStr[i] >= 'A' && pPasswordStr[i] <= 'Z')
		{
			flag1 = 1;
		}
	}
	if (flag  && flag1)
	{
		return  20;
	}
	else if (flag || flag1)
	{
		return 10;
	}
}

int num(string & pPasswordStr)
{
	int size = pPasswordStr.size();
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		if (pPasswordStr[i] >= '0' && pPasswordStr[i] <= '9')
		{
			num++;
		}
	}
	if (num == 1)
	{
		return 10;
	}
	else if (num > 1)
	{
		return 20;
	}
}

int symbol(string & pPasswordStr)
{
	int  num = 0;
	int size = pPasswordStr.size();
	for (int i = 0; i < size; i++)
	{
		if (!isalnum(pPasswordStr[i]))
		{
			num++;
		}
	}

	if (num == 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 10;
	}
	else if (num > 1)
	{
		return 25;
	}
}

int rewd(string & pPasswordStr)
{
	if (letter(pPasswordStr) > 0 && num(pPasswordStr) > 0)
	{
		if (symbol(pPasswordStr) > 0)
		{
			if (letter(pPasswordStr) == 20)
			{
				return 5;
			}
			return 3;
		}
		return 2;
	}
}
void GetPwdSecurityLevel(string & pPasswordStr)
{
	int count1 = length(pPasswordStr);
	int count2 = letter(pPasswordStr);
	int count3 = num(pPasswordStr);
	int count4 = symbol(pPasswordStr);
	int count5 = rewd(pPasswordStr);
	int count = count1 + count2 + count3 + count4 + count5;
	
	if (count >= 90)
	{

		cout << "VERY_SECURE";
	}
	else if (count >= 80)
	{

		cout << "SECURE";
	}
	else if (count >= 70)
	{
		cout << "VERY_STRONG";
	}
	else if (count >= 60)
	{
		cout << "STRONG";
	}
	else if (count >= 50)
	{
		cout << "AVERAGE";
	}
	else if (count >= 25)
	{
		cout << "WEAK";
	}
	else if (count >= 0)
	{
		cout << "VERY_WEAK";
	}

}

int main()
{
	string pPasswordStr;
	getline(cin, pPasswordStr);
	GetPwdSecurityLevel(pPasswordStr);
	system("pause");
	return 0;
}



bool checkWon(vector<vector<int> > board) {
	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] == 1))
		{
			return true;
		}
	}
	for (int j = 0; j < 3; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[0][j] == 1))
		{
			return true;
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] == 1))
	{
		return true;
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] == 1))
	{
		return true;
	}
}

