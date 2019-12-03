#include"process.h"
int main()
{
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