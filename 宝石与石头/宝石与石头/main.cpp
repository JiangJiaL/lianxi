#include<iostream>
#include<string>
using namespace std;
int numJewelsInStones(string J, string S) {
	int count = 0;
	for (int i = 0; i < S.size(); i++)
	{
		for (int j = 0; j < J.size(); j++)
		{
			if (S[i] == J[j])
			{
				count++;
				break;
			}
		}
	}
	return count;
}
int main()
{
	string J;
	string S;
	J.push_back('a');
	J.push_back('A');
	S.push_back('a');
	S.push_back('A');
	S.push_back('A');
	S.push_back('b');
	S.push_back('b');
	S.push_back('b');
	S.push_back('b');
	cout << numJewelsInStones(J, S) << endl;
	system("pause");
	return 0;
}