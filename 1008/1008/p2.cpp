#include<stack>
#include<queue>
#include<iostream>
using namespace std;

class stackQueue
{
	stack<int> m_sk1;
	stack<int> m_sk2;
	

public:
	stackQueue()
	{

	}
	void push(int x)
	{
		m_sk1.push(x);

	}

	void pop()
	{
		while (m_sk1.size() > 1)
		{
			m_sk2.push(m_sk1.top());
			m_sk1.pop();
		}
		m_sk1.pop();
		while (!m_sk2.empty())
		{
			m_sk1.push(m_sk2.top());
			m_sk2.pop();
		}
	}

	int front()
	{

		while (m_sk1.size() > 1)
		{
			m_sk2.push(m_sk1.top());
			m_sk1.pop();
		}
		int tmp = m_sk1.top();
		while (!m_sk2.empty())
		{
			m_sk1.push(m_sk2.top());
			m_sk2.pop();
		}
		return tmp;
	}
	int back()
	{
		return m_sk1.top();
	}
};
int main()
{
	stackQueue sq;
	sq.push(1);
	sq.push(2);
	sq.push(3);
	sq.push(4);
	cout << sq.front() << endl;
	sq.pop();
	cout << sq.front() << endl;
	sq.pop();
	cout << sq.front() << endl;
	sq.pop();
	cout << sq.front() << endl;
	sq.pop();
	system("pause");
	return 0;
}