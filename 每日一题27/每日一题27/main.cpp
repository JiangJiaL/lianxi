#include<iostream>
using namespace std;
 
//�ж�������
int main0()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (((a + b)>c) && ((b + c)> a) && ((a + c)> b))
		{
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}


//���������ĺ� ����+�����
int add(int a, int b)
{
	while (b != 0)
	{
		int sum = a ^ b; //��Ӻ󲻰�����λ������
		int tmp = (a & b) << 1; //�õ�������ӵĽ�λ  ֱ�����Ϊ0
		a = sum; 
		b = tmp;
	}
	return a;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << add(a, b) << endl;
	}
	system("pause");
	return 0;

}