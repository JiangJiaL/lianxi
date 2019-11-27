#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct process
{
	string name;//进程名
	double arrtime;//到达时间
	double sertime;//服务时间
	double fintime;//完成时间
	double turntime;//周转时间
	double Turntime;//带权周转时间
	double Aturntime;//平均周转时间
	double ATurntime;//平均带权周转时间
};




void print(process * P)
{
	cout << "进程名" << " " << "到达时间" << " " << "服务时间" << endl;
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
	double sumturntime = 0.0;//所有进程的周转时间
	double sumTurntime = 0.0;//所有进程的带权周转时间
	for (int i = 0; i < 5; i++)
	{
		sumturntime += P[i].turntime;
		sumTurntime += P[i].Turntime;
	}
	cout << "进程名" << "  " << "到达时间" << " " << "服务时间" <<"  " << "完成时间"<<"  " <<"周转时间" <<"  "<<"带权周转时间"<< endl;
	for (int i = 0; i < 5; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" <<"   "<<P->sertime << "\t\t"<<P->fintime <<"\t"<<P->turntime<<"\t\t" <<P->Turntime <<endl;
		P++;
	}
	printf("周转时间的平均值是 ：%f \n", (sumturntime / 5.0));
	printf("带权周转时间的平均值是 ：%f \n", (sumTurntime / 5.0));

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