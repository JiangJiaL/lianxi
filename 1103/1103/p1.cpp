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
	auto_ptr<int> ap2 = ap; //����ap2;
	cout << *ap2 << ' ' << apt->m_a << endl;//û����
	//cout << *ap << ' ' << apt->m_a << endl; //���� //��Ϊ��ap������ap2 ,apֱ������ ����ap������
	system("pause");
	return 0;
}
//��ν���������ֵ��������� 
//���������컹�еȺŶ�˽�л�,������Ϊ���ܱ���ֵ��ָ�룬һ������ ���ܽ��п������졣
