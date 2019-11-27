#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct process
{
	string name;//������
	double arrtime;//����ʱ��
	double sertime;//����ʱ��
	double fintime;//���ʱ��
	double turntime;//��תʱ��
	double Turntime;//��Ȩ��תʱ��
	double Aturntime;//ƽ����תʱ��
	double ATurntime;//ƽ����Ȩ��תʱ��
};




void print(process * P)
{
	cout << "������" << " " << "����ʱ��" << " " << "����ʱ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" << P->sertime << endl;
		P++;
	}
}


void SortArrtime(process * P)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - 1 - i; j++)
		{
			if ((P + j)->arrtime >(P + j + 1)->arrtime)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp = (P + j)->name;
				(P + j)->name = (P + j + 1)->name;
				(P + j + 1)->name = tmp;

				tmp1 = (P + j)->arrtime;
				(P + j)->arrtime = (P + j + 1)->arrtime;
				(P + j + 1)->arrtime = tmp1;

				tmp2 = (P + j)->sertime;
				(P + j)->sertime = (P + j + 1)->sertime;
				(P + j + 1)->sertime = tmp2;
			}
		}
	}
}

void FCFS(process *P)
{
	int time = 0;

	int i = 1;
	P[0].fintime = P[0].arrtime + P[0].sertime;
	P[0].turntime = P[0].fintime - P[0].arrtime;
	P[0].Turntime = P[0].turntime / P[0].sertime;
	while (i < 5)
	{
		if (time > P[i].arrtime)
		{
			P[i].fintime = P[i - 1].fintime + P[i].sertime;
			P[i].turntime = P[i].fintime - P[i].arrtime;
			P[i].Turntime = P[i].turntime / P[i].sertime;
			i++;
		}
		else
		{
			time++;
		}	
	}
	

}
void FinPrint(process *P)
{
	double sumturntime = 0.0;//���н��̵���תʱ��
	double sumTurntime = 0.0;//���н��̵Ĵ�Ȩ��תʱ��
	for (int i = 0; i < 5; i++)
	{
		sumturntime += P[i].turntime;
		sumTurntime += P[i].Turntime;
	}
	cout << "������" << "  " << "����ʱ��" << " " << "����ʱ��" <<"  " << "���ʱ��"<<"  " <<"��תʱ��" <<"  "<<"��Ȩ��תʱ��"<< endl;
	for (int i = 0; i < 5; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" <<"   "<<P->sertime << "\t\t"<<P->fintime <<"\t"<<P->turntime<<"\t\t" <<P->Turntime <<endl;
		P++;
	}
	printf("��תʱ���ƽ��ֵ�� ��%f \n", (sumturntime / 5.0));
	printf("��Ȩ��תʱ���ƽ��ֵ�� ��%f \n", (sumTurntime / 5.0));

}
int main0()
{
	process P[5] = { { "A", 0.0, 4.0 }, { "B", 1.0, 3.0 }, { "C", 2.0, 4.0 }, { "D", 3.0, 2.0 }, { "E", 4.0, 4.0 } };
	
	print(P);
	SortArrtime(P);
	FCFS(P);
	FinPrint(P);
	system("pause");
	return 0;
}