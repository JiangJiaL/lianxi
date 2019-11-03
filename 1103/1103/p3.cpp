#include <iostream>
using namespace std;
template<class T>
class smart_ptr
{
	T * m_ptr;
	int * m_pcount;
public:

	smart_ptr(const smart_ptr & o)
	{
		*this = o;
		*m_pcount++;
	}
	smart_ptr & operator =(const smart_ptr & o)
	{
		destory();

		m_ptr = o.m_ptr;
		m_pcount = o.m_pcount;
		(*m_pcount)++;
		return *this;
	}


	smart_ptr(T * ptr = nullptr) :
		m_ptr(ptr),
		m_pcount(new int(1))
	{

	}

	~smart_ptr()
	{
		destory();
	}
	void destory()
	{
		if (*m_pcount > 1)
		{
			*m_pcount--;
		}
		else if (m_ptr)
		{
			delete[] m_ptr;
			delete m_pcount;
			m_ptr = nullptr;
		}
	}

	T &operator *()
	{
		return *m_ptr;
	}
	T *operator ->()
	{
		return m_ptr;
	}
	T &operator [](int i)
	{
		return m_ptr[i];
	}

	int use_count()
	{
		return *m_pcount;
	}
};

class Test
{
public:
	int m_a;
};

//
//int main()
//{
//	smart_ptr<Test> sp(new Test); //智能指针
//
//	sp->m_a = 5;
//	cout << sp->m_a << endl;
//	smart_ptr<Test> sp2(sp); //析构重释放
//	sp2->m_a = 6;
//	cout << sp->m_a;
//	system("pause");
//	return 0;
//
//}
/*
struct ListNode
{
	int _data;
	smart_ptr<ListNode> _prev;
	smart_ptr<ListNode> _next;
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};
int main()
{
	smart_ptr<ListNode> node1(new ListNode);
	smart_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	node1->_next = node2;
	node2->_prev = node1;
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	system("pause");

	return 0;

}
*/