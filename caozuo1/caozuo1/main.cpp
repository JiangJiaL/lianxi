#include<iostream>
#include<vector>
#include<string>
#include <queue>
using namespace std;
struct process
{
	string name;//进程名
	double arrtime;//到达时间
	double sertime;//服务时间
	int flag = 0;//标记这个进程是否已被执行，执行置位1，没有执行置位0
	int num = 0;//没有过队列 则num 为0，否则num为1；
	double N; //时间片
	double fintime = 0;//完成时间
	double turntime  =0;//周转时间
	double Turntime = 0;//带权周转时间

};

void SortArrtime(process * P, int n) //到达时间排序
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
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

void SSortSertime(process * P, int n) //服务时间排序
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->sertime >= (P + j + 1)->sertime)
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
void SJF(process *P, int n) //短作业算法
{
	int time = 0; //当前的时间
	int i = n;
	int j = 0;
	//P->flag = 0; //标记进程是否以被执行
	while (i >= 1)
	{
		for (int j = 0; j < n; j++)
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

void FCFS(process *P, int n) //先到先服务算法
{
	int time = 0;

	int i = 1;
	P[0].fintime = P[0].arrtime + P[0].sertime;
	P[0].turntime = P[0].fintime - P[0].arrtime;
	P[0].Turntime = P[0].turntime / P[0].sertime;
	while (i < n)
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

void RR(process *P, int n, int m) //时间片轮转算法
{
	int T;
	cout << "请输入时间片" << endl;
	cin >> T;
	double serive[5] = { 0 };
	for (int i = 0; i < n; i++)
	{
		serive[i] = P[i].sertime;
	}
	queue<string> qu; //定义一个队列，放要执行的作业
	double time = 0.0;
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
	for (int i = 1; i < n; i++)
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
		for (int s = 0; s < m; s++)
		{
			for (int j = 0; j < n && (!qu.empty()); j++)
			{
				tmp = qu.front();
				if (tmp == P[j].name)
				{
					if (serive[j] > T&& P[j].flag == 0)
					{
						serive[j] -= T;
						time += T;
						P[j].fintime = time;
						qu.pop();
						for (int i = 0; i < n; i++)
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
						for (int i = 0; i < n; i++)
						{
							if (P[i].num == 0 && P[i].arrtime <= time)
							{
								qu.push(P[i].name);
								P[i].num = 1;
							}
						}
						m--;
					}
				}
			}
		}
	}
}


void RRturn(process * P, int n)
{
	for (int j = 0; j < n; j++)
	{
		P[j].turntime = P[j].fintime - P[j].arrtime;
		P[j].Turntime = P[j].turntime / P[j].sertime;
	}
}

void FinPrint(process *P, int n) //打印的最后计算的作业完成时间。。。。
{
	double sumturntime = 0.0;//所有进程的周转时间
	double sumTurntime = 0.0;//所有进程的带权周转时间
	for (int i = 0; i < n; i++)
	{
		sumturntime += P[i].turntime;
		sumTurntime += P[i].Turntime;
	}
	cout << "进程名" << "  " << "到达时间" << " " << "服务时间" << "  " << "完成时间" << "  " << "周转时间" << "  " << "带权周转时间" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" << "   " << P->sertime << "\t\t" << P->fintime << "\t" << P->turntime << "\t\t" << P->Turntime << endl;
		P++;
	}
	printf("周转时间的平均值是 ：%f \n", (sumturntime / n));
	printf("带权周转时间的平均值是 ：%f \n", (sumTurntime / n));

}
int main()
{

	//process P[5] = { { "A", 0.0, 4.0 }, { "B", 1.0, 3.0 }, { "C", 2.0, 4.0 }, { "D", 3.0, 2.0 }, { "E", 4.0, 4.0 } };

	//print(P);

	int n;//代表有几个进程
	cout << "请输入进程个数" << endl;
	cin >> n;
	process P[100];
	cout << "请输入进程名称 进程到达时间 进程服务时间" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i].name >> P[i].arrtime >> P[i].sertime;
	}

	int num;
	cout << "1:先到先服务  2:短作业  3：时间片轮转 " << endl;
	cout << "请输入要进行的算法选择->";
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