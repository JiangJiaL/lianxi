#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int MaxArray(vector<int> & nums)
{
	int max = nums[0];
	int sum = nums[0];
	int i;
	if (nums.size() < 1)
		return 0;
	for (i = 1; i < nums.size(); i++)
	{
		if (sum < 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (max < sum)
		{
			max = sum;
		}
	}
	return max;
}
int main()
{
	int n;
	cin >> n;
	vector<int> nums (n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	cout << MaxArray(nums);
	system("pause");
	return 0;
}


bool isSame(char a, char b)
{
	return a == b;

}

int isPalindrome(string &tmp,string & c)
{
	int i, j;
	int count = 0;
	for (int k = 0; k < tmp.size(); k++)
	{
		tmp.insert(k, c);
		for (i = 0, j = tmp.size() - 1; i < j; i++, j--)
		{
			if (!isSame(tmp[i], tmp[j]))
			{
				continue;
			}
		}
		count++;
	}
	return count;
}
int main0()
{
	string s;
	getline(cin, s);
	string c;
	getline(cin, c);
	cout << isPalindrome(s, c);

	system("pause");
	return 0;
}


int main()
{
	/*int x = 1;
	do{
		printf("%2d\n", x++);
	} while (x--);*/

	/*char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	printf("%s", str);*/

	/*int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2]; */

	
	system("pause");
	return 0;
}