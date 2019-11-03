
#include <iostream>
using namespace std;
 // c语言指针的缺陷 在创建新的指针的时候需要申请空间
//，用完后必须要进行释放 ，否则就会造成内存泄漏
template<class T>
//使用smart_ptr，必须是new出来的指针,y因为释放用的是delete.
class smart_ptr
{
	T * m_ptr;
public:

	smart_ptr(const smart_ptr & o) = delete; //把函数删掉
	smart_ptr & operator =(const smart_ptr & o) = delete; //将=删掉


	smart_ptr(T * ptr = nullptr) :
		m_ptr(ptr)
	{

	}

	~smart_ptr()
	{
		if (m_ptr)
		{
			delete[] m_ptr;
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
};

class Test
{
public:
	int m_a;
};


int main0()
{
	smart_ptr<Test> sp(new Test); //智能指针
	
	sp->m_a = 5;
	cout << sp->m_a;
	//smart_ptr<Test> sp2(sp); //析构重释放
	//sp2 = sp;
	system("pause");
	return 0;

}

//以上智能指针并不安全 ，一旦被拷贝就会出问题
//int main()
//{
//	smart_ptr<int> sp(new int[5]);
//	for (int i = 0; i < 5; i++)
//	{
//		sp[i] = i + 1;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << sp[i] << ' ';
//	}
//	system("pause");
//	return 0;
//}
