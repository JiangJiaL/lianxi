#include"process.h"
int main()
{
	int n;//�����м�������
	cout << "��������̸���" << endl;
	cin >> n;
	process P[100];
	cout << "������������� ���̵���ʱ�� ���̷���ʱ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i].name >> P[i].arrtime >> P[i].sertime;
	}

	int num;
	cout << "1:�ȵ��ȷ���  2:����ҵ  3��ʱ��Ƭ��ת " << endl;
	cout << "������Ҫ���е��㷨ѡ��->";
	cin >> num;
	switch (num)
	{
	case 1:
		SortArrtime(P, n);
		FCFS(P, n);
		//FinPrint(P, n);
		break;
	case 2:
		SSortSertime(P, n);
		SJF(P, n);
		//FinPrint(P, n);
		break;
	case 3:
		SortArrtime(P, n);
		RR(P, n,n);
		//FinPrint(P, n);
		RRturn(P, n);
		break;
	default:
		break;
	}
	//SortArrtime(P,n);
	//FCFS(P,n);
	FinPrint(P, n);

	/*SSortSertime(P,n);
	SJF(P,n);
	FinPrint(P,n);*/
	system("pause");
	return 0;
}