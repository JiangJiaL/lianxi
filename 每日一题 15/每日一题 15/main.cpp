#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void findNumberOf1(int num)
{
	int counter = 0;
	while (num)
	{
		counter++;
		num = num & num - 1;
	}
	cout << counter << endl;
	return;
}

int main0()
{
	int num;
	while (cin >> num)
	{
		findNumberOf1(num);
	}
	return 0;
}


int findMinimum(int n, vector<int> left, vector<int> right) 
{
	int Min = 0; // ��¼������Ҫ��������
	int min = 0; //��¼�����һ����ɫ������Ϊ0 ���ۼ�
	int lmin = INT_MAX; 
	int lsum = 0;
	int rmin = INT_MAX;
	int rsum = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(left[i] * right[i])) // �����һ��Ϊ0 �ۼ�����
		{
			min += left[i] + right[i];
		}
		else
		{
			lsum += left[i]; //���������и�����
			rsum += right[i]; //���������и�����
			lmin = left[i] < lmin ? left[i] : lmin;  //�ж��������Ǹ���ɫ����
			rmin = right[i] < rmin ? right[i] : rmin; //�ж��������Ǹ���ɫ����
		}
	}
	//���յ��������� ��0�������������� ��ĳ���ֵ����׺ͼ�ȥ��ɫ���ٵ������ڼ���һ��
	//�������Ƚ�ȡ��С��  Ȼ���ټ���1����������Ҫȡ������
	Min = min + ((lsum - lmin + 1) < (rsum - rmin + 1) ? (lsum - lmin + 1) : (rsum - rmin + 1)) + 1;
	
	return Min;
}
int main()
{
	int n;
	cin >> n;
	vector<int> left;
	vector<int> right;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		left.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		right.push_back(tmp);
	}
	cout << findMinimum(n, left, right);
	system("pause");
	return 0;
}
