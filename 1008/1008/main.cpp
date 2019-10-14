
#include<iostream>
#include<deque>
#include<queue>
#include <functional>
using namespace std;

int main1()
{
	deque <int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(-1);
	deque <int> ::iterator di = d.begin();
	cout << di[2] << endl;

	system("pause");
	return 0;
}

int main()
{
	vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	vector <int> v2;
	priority_queue<int> q1;
	for (auto & i : v)
	{
		q1.push(i);
	}
	while (!q1.empty())
	{
		v2.push_back(q1.top());
		q1.pop();
	}
	for (auto & i : v2)
	{
		cout << i << endl;
	}
	cout << q1.top() << endl;
	q1.pop();
	cout << q1.top() << endl;
	system("pause");
	return 0;
}

