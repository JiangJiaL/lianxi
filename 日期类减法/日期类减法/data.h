
#pragma once 
typedef int uint;
class Data
{
	int m_year;
	uint m_month;
	uint m_day;
public:
	Data(int y, uint m, uint d) :
		m_year(y), m_month(m),
		m_day(d)
	{
	}

	Data operator -(const uint delay)const;
	
};