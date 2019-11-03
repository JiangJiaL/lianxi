
#include <iostream>
using namespace std;
 // c����ָ���ȱ�� �ڴ����µ�ָ���ʱ����Ҫ����ռ�
//����������Ҫ�����ͷ� ������ͻ�����ڴ�й©
template<class T>
//ʹ��smart_ptr��������new������ָ��,y��Ϊ�ͷ��õ���delete.
class smart_ptr
{
	T * m_ptr;
public:

	smart_ptr(const smart_ptr & o) = delete; //�Ѻ���ɾ��
	smart_ptr & operator =(const smart_ptr & o) = delete; //��=ɾ��


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
	smart_ptr<Test> sp(new Test); //����ָ��
	
	sp->m_a = 5;
	cout << sp->m_a;
	//smart_ptr<Test> sp2(sp); //�������ͷ�
	//sp2 = sp;
	system("pause");
	return 0;

}

//��������ָ�벢����ȫ ��һ���������ͻ������
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
