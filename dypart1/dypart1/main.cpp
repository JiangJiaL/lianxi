#include<iostream>
using namespace std;
struct job
{
	int id;//������
	int partnum;//������С
	int partaddress;//����ʼַ
	int flag = 1;//���Բ����ڴ滮�� Ϊ0 ��ʾ�����Բ����ڴ滮��
};
int G = 5;

void Print(job *P, int n) //��ӡ�����������ҵ���ʱ�䡣������
{
	cout << "������" << "  " << "������С" << " " << "����ʼַ" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << P->id << "\t" << P->partnum << "\t" << P->partaddress << endl;
		P++;
	}
}
void smallsort(job * P, int n) //����ʱ������
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
void smallsort1(job * P, int n) //����ʱ������
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
void smallsort2(job * P, int n) //����ʱ������
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
void bigsort(job * P, int n) //����ʱ������
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
	cout << "�ڴ����ʧ��" << endl;
}

void BF(job * P, int n, int part)//�����Ӧ�㷨
{
	bigsort(P, n); //��С�����ҵ���һ����������ҵ����ļ�ֹͣ
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


void WF(job *P, int n, int part) //���Ӧ�㷨
{
	bigsort(P, n);
	if (P[0].partnum < part)
	{
		cout << "�ڴ�ռ䲻��" << endl;
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
	int n;//�����м�������
	cout << "��������̸���" << endl;
	cin >> n;
	job P[100];
	cout << "����������� ������С ����ʼַ" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i].id >> P[i].partnum >> P[i].partaddress;
	}
	int Part;
	int num;
	cout << "1:BF  2:WF  3��FF  4:NF " << endl;
	cout << "������Ҫ���е��㷨ѡ��->";
	cin >> num;
	switch (num)
	{
	case 1:
		while (1)
		{
			bigsort(P, n);
			cout << "������Ҫ�������ҵ��С" << endl;
			cin >> Part;
			BF(P, n, Part);
			if (P[n - 1].partnum == 0)
			{
				n--;
			}
			Print(P, n);
			char str;
			cout << "�Ƿ���Ҫ�������� Y N" << endl;
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
			cout << "������Ҫ�������ҵ��С" << endl;
			cin >> Part;
			WF(P, n, Part);
			if (P[n-1].partnum == 0)
			{
				n--;
			}
			Print(P, n);
			char str;
			cout << "�Ƿ���Ҫ�������� Y N" << endl;
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
			cout << "������Ҫ�������ҵ��С" << endl;
			cin >> Part;
			FF(P, n, Part);
			Print(P, n);
			char str;
			cout << "�Ƿ���Ҫ�������� Y N" << endl;
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
			cout << "������Ҫ�������ҵ��С" << endl;
			cin >> Part;
			NF(P, n, Part);
			Print(P, n);
			char str;
			cout << "�Ƿ���Ҫ�������� Y N" << endl;
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