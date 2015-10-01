#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x = 12;
	int* xp = &x;
	int* yp = xp;

	cout << "Here is the value: " << *yp;
	system("pause");
	return 0;
}