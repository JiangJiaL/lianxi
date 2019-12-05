#include<iostream>
using namespace std;
struct job
{
	int id;//分区号
	int partnum;//分区大小
	int partaddress;//分区始址
	int flag = 1;//可以参与内存划分 为0 表示不可以参与内存划分
};
int G = 5;

void Print(job *P, int n) //打印的最后计算的作业完成时间。。。。
{
	cout << "分区号" << "  " << "分区大小" << " " << "分区始址" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << P->id << "\t" << P->partnum << "\t" << P->partaddress << endl;
		P++;
	}
}
void smallsort(job * P, int n) //到达时间排序
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partnum >(P + j + 1)->partnum)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
}
void smallsort1(job * P, int n) //到达时间排序
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partaddress >(P + j + 1)->partaddress)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << P[i].partaddress << ' ';
	}
	cout << endl;
}
void smallsort2(job * P, int n) //到达时间排序
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partaddress <(P + j + 1)->partaddress)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << P[i].partaddress << ' ';
	}
	cout << endl;
}
void bigsort(job * P, int n) //到达时间排序
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partnum <(P + j + 1)->partnum)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << P[i].partnum << ' ';
	}
	cout << endl;
}
int flag = 0;
void NF(job * P, int n, int part)
{
	for (int i = flag; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			flag = i % (n - 1);
			break;
		}
	}
}


void FF(job * P, int n, int part)
{

	for (int i = 0; i < n; i++)
	{
		if (P[i].partnum >= part && P[i].partnum >= G)
		{
			P[i].partnum = P[i].partnum - part;

			if (P[i].partnum == 0)
			{
				P[i] = P[n];
			}
			break;
		}
	}
	cout << "内存分配失败" << endl;
}

void BF(job * P, int n, int part)//最佳适应算法
{
	bigsort(P, n); //从小到大，找到第一个不满足作业需求的即停止
	for (int i = 0; i < n; i++)
	{
		if (P[i].partnum < part)
		{
			P[i - 1].partnum -=  part;
			bigsort(P, n);
			break;	
		}
	}
}


void WF(job *P, int n, int part) //最坏适应算法
{
	bigsort(P, n);
	if (P[0].partnum < part)
	{
		cout << "内存空间不够" << endl;
	}
	else
	{
		P[0].partnum = P[0].partnum - part;
		if (P[0].partnum < 5)
		{
			P[0].flag = 0;
		}
		bigsort(P, n);
		
	}
}


int main()
{
	int n;//代表有几个进程
	cout << "请输入进程个数" << endl;
	cin >> n;
	job P[100];
	cout << "请输入分区号 分区大小 分区始址" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i].id >> P[i].partnum >> P[i].partaddress;
	}
	int Part;
	int num;
	cout << "1:BF  2:WF  3：FF  4:NF " << endl;
	cout << "请输入要进行的算法选择->";
	cin >> num;
	switch (num)
	{
	case 1:
		while (1)
		{
			bigsort(P, n);
			cout << "请输入要分配的作业大小" << endl;
			cin >> Part;
			BF(P, n, Part);
			if (P[n - 1].partnum == 0)
			{
				n--;
			}
			Print(P, n);
			char str;
			cout << "是否需要继续分配 Y N" << endl;
			cin >> str;
			if (str == 'N')
			{
				break;
			}
		}

		break;
	case 2:
		while (1)
		{
			smallsort2(P, n);
			cout << "请输入要分配的作业大小" << endl;
			cin >> Part;
			WF(P, n, Part);
			if (P[n-1].partnum == 0)
			{
				n--;
			}
			Print(P, n);
			char str;
			cout << "是否需要继续分配 Y N" << endl;
			cin >> str;
			if (str == 'N')
			{
				break;
			}
		}
		break;
	case 3:
		while (1)
		{
			//Print(P, n);
			cout << "请输入要分配的作业大小" << endl;
			cin >> Part;
			FF(P, n, Part);
			Print(P, n);
			char str;
			cout << "是否需要继续分配 Y N" << endl;
			cin >> str;
			if (str == 'N')
			{
				break;
			}

		}
		break;
	case 4:
		while (1)
		{
			cout << "请输入要分配的作业大小" << endl;
			cin >> Part;
			NF(P, n, Part);
			Print(P, n);
			char str;
			cout << "是否需要继续分配 Y N" << endl;
			cin >> str;
			if (str == 'N')
			{
				break;
			}
		}
		
		break;
	default:
		break;
	}
	//FinPrint(P, n);
	system("pause");
	return 0;

}