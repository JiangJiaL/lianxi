#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
	int m_a;
};

int main2()
{
	unique_ptr<int> ap(new int);
	unique_ptr<Test> apt(new Test);
	*ap = 5;
	apt->m_a = 6;

	cout << *ap << ' ' << apt->m_a << endl;
	//unique_ptr<int> ap2 = ap; //拷贝ap2;
	//cout << *ap2 << ' ' << apt->m_a << endl;//没问题
	//cout << *ap << ' ' << apt->m_a << endl; //崩溃 //因为将ap拷贝给ap2 ,ap直接作废 所以ap不存在
	system("pause");
	return 0;
}