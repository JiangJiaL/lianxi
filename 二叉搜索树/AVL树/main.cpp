#include"AVLtree.h"

int main()
{
	jiang::AVLTree<int> t;
	t.insert(16);
	t.insert(3); 
	t.insert(7);
	t.insert(11);
	t.insert(9);
	t.insert(26);
	t.insert(18);
	t.insert(14);
	t.insert(15);
	system("pause");
	return 0;
}