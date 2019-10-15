#include<iostream>
#include "seqlist.h"
#include "seqlist.cpp"
using namespace std;
int main()
{
	SeqList<int> s1;
	s1.Push_back(6);
	s1.Push_back(7);
	cout << s1.size() << endl;
	system("pause");
	return 0;

}

