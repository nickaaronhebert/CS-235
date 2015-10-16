#include "LinkedList.h"
#include "LinkedListInterface.h"
#include <iomanip>
#include <iostream>


using namespace std;

int main()
{
	LinkedList<int> test_list;

	
	test_list.insertTail(5);
	test_list.insertTail(6);
	test_list.insertTail(7);
	test_list.insertTail(8);
	test_list.insertTail(9);

	test_list.size();

	


	
	cout << test_list.size();

	system("pause");
	return 0;
}