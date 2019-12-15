#include "binarySortTree.h"
#include<iostream>
using namespace std;
int main1()
{
	Jiang::BinarySortTree<int> bst;
	bst.insert(5);
	bst.insert(2);
	bst.insert(8);
	bst.insert(4);
	bst.insert(7);
	bst.insert(1);
	bst.erase(2);



	system("pause");
	return 0;
}