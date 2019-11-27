#include "data.h"

static uint getMonthDay(int y,uint m)
{
	if (m > 12 || m == 0)
	{
		return 0;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	if (m == 2)
	{
		return 28 + ((y % 400 == 0) || (y % 100 == 0 && y % 4 != 0));
	}
	else
	{
		return 31;
	}
}
Data Data::operator -(uint delay)const
{
	Data res = *this;
	uint tmp;
	if (res.m_month == 0)
	{
		res.m_year--;
		res.m_month = 12;
	}
	else
		res.m_month--;
	tmp = getMonthDay(res.m_year, res.m_month);
	while (delay >= tmp)
	{
		delay -= tmp;
		res.m_month--;
		if (res.m_month == 0)
		{
			res.m_month = 12;
			res.m_year--;
		}
		tmp = getMonthDay(res.m_year, res.m_month);
	}
	int tmpday = res.m_day;
		tmpday = res.m_day - delay;
	if (tmpday <= 0)
	{
		tmpday += tmp;
	}
	else
	{
		res.m_month++;
		if (res.m_month > 12)
		{
			res.m_month = 1;
			res.m_year++;
		}
	}
	res.m_day = tmpday;
	return res;
}