#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct process
{
	string name;//进程名
	double arrtime;//到达时间
	double sertime;//服务时间
	int flag;//标记这个进程是否已被执行，执行置位1，没有执行置位0
	int num;//没有过队列 则num 为0，否则num为1；
	double N; //时间片
	double fintime;//完成时间
	double turntime;//周转时间
	double Turntime;//带权周转时间

};


void RSortArrtime(process * P, int W)
{
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < W - 1 - i; j++)
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

void check(queue<string> qu, process * P, int time, int W)
{
	for (int i = 0; i < W; i++)
	{
		if (P[i].arrtime <= time)
		{
			qu.push(P[i].name);
			P[i].num = 1;
		}

	}
}

void RR(process *P, int W)
{
	for (int i = 0; i < W; i++)
	{
		P[i].N = 1.0;
	}
	double serive[5] = { 0 };
	for (int i = 0; i < W; i++)
	{
		serive[i] = P[i].sertime;
	}
	queue<string> qu; //定义一个队列，放要执行的作业
	double time = 0.0;
	P->flag = 0;
	P->num = 0;
	while (qu.empty())
	{
		if (P[0].arrtime <= time)
		{
			qu.push(P[0].name);
			P[0].num = 1;
		}
		else
		{
			time++;
		}
	}
	for (int i = 1; i < W; i++)
	{
		if (P[i].arrtime <= time)
		{
			qu.push(P[i].name);
			P[i].num = 1;
		}
	}
	while (!qu.empty())
	{
		string tmp;
		for (int s = 0; s < W; s++)
		{
			for (int j = 0; j < 5 && (!qu.empty()); j++)
			{
				tmp = qu.front();
				if (tmp == P[j].name)
				{
					if (serive[j] > P[j].N && P[j].flag == 0)
					{
						serive[j] -= P[j].N;
						time += P[j].N;
						P[j].fintime = time;
						qu.pop();
						for (int i = 0; i < W; i++)
						{
							if (P[i].num == 0 && P[i].arrtime <= time)
							{
								qu.push(P[i].name);
								P[i].num = 1;
							}
						}
						qu.push(tmp);

					}
					else
					{
						time += serive[j];
						P[j].fintime = time;
						P[j].flag = 1;
						qu.pop();

						for (int i = 0; i < W; i++)
						{
							if (P[i].num == 0 && P[i].arrtime <= time)
							{
								qu.push(P[i].name);
								P[i].num = 1;
							}
						}
						W--;
					}
				}
			}
		}
	}
}

void RRturn(process * P, int W)
{
	for (int j = 0; j < W; j++)
	{
		P[j].turntime = P[j].fintime - P[j].arrtime;
		P[j].Turntime = P[j].turntime / P[j].sertime;
	}
}



void Rprint(process * P, int W)
{
	cout << "进程名" << " " << "到达时间" << " " << "服务时间" << endl;
	for (int i = 0; i < W; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" << P->sertime << endl;
		P++;
	}
}
void RFinPrint(process *P, int W)
{
	double sumturntime = 0.0;//所有进程的周转时间
	double sumTurntime = 0.0;//所有进程的带权周转时间
	for (int i = 0; i < 5; i++)
	{
		sumturntime += P[i].turntime;
		sumTurntime += P[i].Turntime;
	}
	cout << "进程名" << "  " << "到达时间" << " " << "服务时间" << "  " << "完成时间" << "  " << "周转时间" << "  " << "带权周转时间" << endl;
	for (int i = 0; i < W; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" << "   " << P->sertime << "\t\t" << P->fintime << "\t" << P->turntime << "\t\t" << P->Turntime << endl;
		P++;
	}
	printf("周转时间的平均值是 ：%f \n", (sumturntime / 5.0));
	printf("带权周转时间的平均值是 ：%f \n", (sumTurntime / 5.0));
}
int main()
{
	int W = 5;
	process P[5] = { { "A", 0.0, 4.0 }, { "B", 1.0, 3.0 }, { "C", 2.0, 4.0 }, { "D", 3.0, 2.0 }, { "E", 4.0, 4.0 } };
	Rprint(P, W);
	RSortArrtime(P, W);
	RR(P, W);
	RRturn(P, W);
	RFinPrint(P, W);

	system("pause");
	return 0;
}