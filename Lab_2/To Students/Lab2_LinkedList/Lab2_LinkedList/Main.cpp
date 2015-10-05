#include "LinkedList.h"
#include "LinkedListInterface.h"
#include <iomanip>
#include <iostream>


using namespace std;

int main()
{
	LinkedList<int> test_list;
	test_list.insertHead(7);
	test_list.insertHead(10);
	test_list.insertTail(15);
	test_list.insertAfter(14, 10);
	test_list.remove(7);
	test_list.at(1);
	test_list.clear();
	
	cout << test_list.size();

	system("pause");
	return 0;
}