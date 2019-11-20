#include<iostream>
using namespace std;


//bool LeapYear(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		return true;
//	}
//	return false;
//}

int getMonthDay(int m,int y)
{
	/*int tmp = LeapYear(y);
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		return 31;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else if (m == 2 && tmp)
	{
		return 29;
	}
	else
	{
		return 28;
	}*/
	int tmp = 0;
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		tmp = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		tmp = 30;
		break;
	case 2:
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			tmp = 29;
		}
		else
		{
			tmp = 28;
		}	
		break;
	default:
		break;
	}
	return tmp;
}

int getOutDay(int y,int m,int n)
{
	int ret = getMonthDay(m, y);
	int AllMonthDay = 0;
	if (m < 1 || m > 12 || n < 1 || n > ret)
	{
		return -1;
	}
	for (int i = 1; i < m; i++)
	{
		
		AllMonthDay  += getMonthDay(i, y);
	}
	return AllMonthDay;

}

int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	cout <<getOutDay(year, month, day) + day;
	system("pause");
	return 0;
}