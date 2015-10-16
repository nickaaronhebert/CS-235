#include <string>
#include <iostream>
#include <iomanip>
#include "ExpressionManagerInterface.h"
#include "ExpressionManager.h"
#include "Factory.h"

using namespace std;

int main()
{
	ExpressionManagerInterface* testExpressions = Factory::createManager();
	cout << testExpressions->postfixEvaluate("2 3 4 5 * - + ");
	system("pause");
	return 0;
}