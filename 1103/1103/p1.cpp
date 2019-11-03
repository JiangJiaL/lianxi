#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
	int m_a;
};

int main1()
{
	auto_ptr<int> ap (new int);
	auto_ptr<Test> apt(new Test);
	*ap = 5;
	apt->m_a = 6;

	cout << *ap << ' ' << apt->m_a << endl;
	auto_ptr<int> ap2 = ap; //拷贝ap2;
	cout << *ap2 << ' ' << apt->m_a << endl;//没问题
	//cout << *ap << ' ' << apt->m_a << endl; //崩溃 //因为将ap拷贝给ap2 ,ap直接作废 所以ap不存在
	system("pause");
	return 0;
}
//如何解决拷贝出现的这种问题 
//将拷贝构造还有等号都私有化,让它称为不能被赋值的指针，一经定义 不能进行拷贝构造。
