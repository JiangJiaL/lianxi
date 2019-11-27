#include<iostream>
#include<string>
using namespace std;
struct process
{
	string name;//������
	double arrtime;//����ʱ��
	double sertime;//����ʱ��
	int flag;//�����������Ƿ��ѱ�ִ�У�ִ����λ1��û��ִ����λ0
	double fintime;//���ʱ��
	double turntime;//��תʱ��
	double Turntime;//��Ȩ��תʱ��
	
};


void Sprint(process * P)
{
	cout << "������" << " " << "����ʱ��" << " " << "����ʱ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" << P->sertime << endl;
		P++;
	}
}


void SSortSertime(process * P)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - 1 - i; j++)
		{
			if ((P + j)->sertime >=(P + j + 1)->sertime)
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

void SJF(process *P)
{
	int time = 0;
	int i = 5;
	int j = 0;
	P->flag = 0;
	while (i > 1)
	{
		for (int j = 0; j < 5; j++)
		{
			if (P[j].arrtime <= time && P[j].flag == 0)
			{
				P[j].fintime = time + P[j].sertime;
				P[j].turntime = P[j].fintime - P[j].arrtime;
				P[j].Turntime = P[j].turntime / P[j].sertime;
				time = P[j].fintime;
				P[j].flag = 1;
				i--;
				j = -1;
			}
		}
		time++;
	}
}

void SFinPrint(process *P)
{
	double sumturntime = 0.0;//���н��̵���תʱ��
	double sumTurntime = 0.0;//���н��̵Ĵ�Ȩ��תʱ��
	for (int i = 0; i < 5; i++)
	{
		sumturntime += P[i].turntime;
		sumTurntime += P[i].Turntime;
	}
	cout << "������" << "  " << "����ʱ��" << " " << "����ʱ��" << "  " << "���ʱ��" << "  " << "��תʱ��" << "  " << "��Ȩ��תʱ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" << "   " << P->sertime << "\t\t" << P->fintime << "\t" << P->turntime << "\t\t" << P->Turntime << endl;
		P++;
	}
	printf("��תʱ���ƽ��ֵ�� ��%f \n", (sumturntime / 5.0));
	printf("��Ȩ��תʱ���ƽ��ֵ�� ��%f \n", (sumTurntime / 5.0));
}

int mainS()
{
	process P[5] = { { "A", 0.0, 4.0 }, { "B", 1.0, 3.0 }, { "C", 2.0, 4.0 }, { "D", 3.0, 2.0 }, { "E", 4.0, 4.0 } };

	Sprint(P);
	SSortSertime(P);
	SJF(P);
	SFinPrint(P);
	system("pause");
	return 0;
}