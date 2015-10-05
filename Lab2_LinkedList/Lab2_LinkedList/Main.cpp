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
	test_list.insertHead(11);
	test_list.insertHead(18);
	test_list.insertTail(15);
	test_list.insertAfter(14, 10);

	test_list.at(0);
	test_list.at(1);
	test_list.at(2);
	test_list.at(3);
	test_list.at(4);
	test_list.at(5);
	test_list.at(6);
	
	cout << test_list.size();

	system("pause");
	return 0;
}