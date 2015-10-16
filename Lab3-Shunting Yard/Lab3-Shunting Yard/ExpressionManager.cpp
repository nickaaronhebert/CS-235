#include "ExpressionManager.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>



ExpressionManager::ExpressionManager()
{
}


ExpressionManager::~ExpressionManager()
{
}

bool ExpressionManager::validateString(string stringToEvaluate)
{
	stringstream ss(stringToEvaluate);
	string next;

	while (ss >> next)
	{
		if (isNum(next))
		{
			continue;
		}
		else if (isParenthesis(next))
		{
			continue;
		}
		else if(isSign(next))
		{
			continue;
		}
		else
		{
			return "Invalid string";
		}
	}

}

bool ExpressionManager::isParenthesis(string letter)
{
	 string paren_types = "( ) { } [ ]";
	 stringstream ss(paren_types);
	 string next;

	while(ss >> next)
	{
		if (letter == next)
		{
			return true;
		}
	}
	return false;
}

bool ExpressionManager::isNum(string letter)
{
	string num_types = "1 2 3 4 5 6 7 8 9 0";
	stringstream ss(num_types);
	char next;

	while (ss >> next)
	{
		for (int i = 0; i < letter.size(); i++)
		{
			if (letter[i] == next)
			{
				return true;
			}
		}
	}
	return false;
}

bool ExpressionManager::isSign(string letter)
{
	string sign_types = "- + / * %";
	stringstream ss (sign_types);
	string next;

	while (ss >> next)
	{
		if (letter == next)
		{
			return true;
		}
	}
	return false;
}



int ExpressionManager::paren_type(char parenth)
{
	switch (parenth)
	{
	case '{':
		return 1;

	case '}':
		return 1;
	case '[':
		return 2;
	case ']':
		return 2;
	case '(':
		return 3;
	case ')':
		return 3;
	}
}

int ExpressionManager::sign_type(char sign)
{
	switch (sign)
	{
	case '-':
		return 1;

	case '+':
		return 1;
	case '/':
		return 2;
	case '*':
		return 2;
	case '%':
		return 2;
	}
}

int ExpressionManager::sign_type2(char sign)
{
	switch (sign)
	{
	case '-':
		return 1;

	case '+':
		return 2;
	case '/':
		return 3;
	case '*':
		return 4;
	case '%':
		return 5;
	}
}


bool ExpressionManager::isBalanced(string expression)
{
	if (!validateString(expression)) { return false; }
	stack<string>paren_stack;	
	stringstream ss (expression);
	string next;

	while (ss >> next)
	{
		if (isParenthesis(next))
		{
			if (next == "{" || next == "[" || next == "(")
			{
				paren_stack.push(next);
				continue;
			}
			if (( next == "}" || next == "]" || next == ")") && paren_stack.empty())
			{
				return false;
			}
			if ( next == "}" || next == "]" || next == ")")
			{
				string paren_to_analyze = paren_stack.top();
				int left_paren = paren_type(paren_to_analyze[0]);
				int right_paren = paren_type(next[0]);
				if (left_paren != right_paren)
				{
					return false;
				}
				paren_stack.pop();
			}
			
		}
	}
	return true;
}


string ExpressionManager:: postfixToInfix(string postfixExpression)
{
	//once you hit an operator, make sure that the stack is not empty. If it is empty, return zero. 
	bool postToIn = isBalanced(postfixExpression);
	stringstream ss (postfixExpression);
	string next;
	stack<string>num_stack;
	if (postToIn)
	{
		while (ss >> next)
		{
			if (isNum(next))
			{ 
				num_stack.push(next);
				continue;
			}
			if (isSign(next)) 
			{ 
				if (num_stack.size() == 0) { return false;}
				string right_side = num_stack.top();
				num_stack.pop();
				string left_side = num_stack.top();
				num_stack.pop();
				string new_string = "(" + left_side + next + right_side + ")";
				num_stack.push(new_string);
				continue; 
			}
		}
	}
	return "";
}

string ExpressionManager:: infixToPostfix(string infixExpression)
{
	bool inToPost = isBalanced(infixExpression);
	stringstream ss(infixExpression);
	string next;
	stack<string>num_stack;
	stack<char>operators;
	string result_string;

	if (inToPost)
	{
		while (ss >> next)
		{
			if (isNum(next))
			{
				result_string +=  " " + next;
				continue;
			}
			else if (isSign(next))
			{
				if (operators.size()==0)
				{
					operators.push(next[0]);
					continue;
				}
				if (operators.top()== '(' || operators.top() == '{' || operators.top() == '[')
				{
					operators.push(next[0]);
					continue;
				}
				if (sign_type(next[0]) > sign_type(operators.top()))
				{
					operators.push(next[0]);
					continue;
				}
				else
				{
					char operatorToAdd = operators.top();
					stringstream cast;
					string newOpToResult;
					cast << operatorToAdd;
					cast >> newOpToResult;
					operators.pop();

					result_string += " " + newOpToResult ;
				}

			}
			else if (isParenthesis(next))
			{
				if (next[0] == '(' || next[0] == '{' || next[0] == '[' )
				{
					operators.push(next[0]);
				}
				else
				{
					while (operators.top()!= '(' && operators.top()!= '{' && operators.top()!= '[')
					{
						char operatorToAdd = operators.top();
						stringstream cast;
						string newOpToResult;
						cast << operatorToAdd;
						cast >> newOpToResult;
						operators.pop();

						result_string += " " + newOpToResult;

					}
					if (paren_type(operators.top()) == paren_type(next[0]))
					{
						operators.pop();
						continue;
					}
				}
			}
		}
		while (!operators.empty())
		{
			char operatorToAdd = operators.top();
			stringstream cast;
			string newOpToResult;
			cast << operatorToAdd;
			cast >> newOpToResult;
			operators.pop();

			result_string += " " + newOpToResult;
			
		}
		cout << result_string;
	}
	return "";
}

int ExpressionManager::EvaluateExpression(string rightSide, string leftSide, string sign)
{
	int RightVal = atoi(rightSide.c_str());
	int LeftVal = atoi(leftSide.c_str());
	int finalResult = 0;
	int signToEval = sign_type2(sign[0]);
	switch (signToEval)
	{
	case 1:
		finalResult = LeftVal - RightVal;
		return finalResult;
	case 2:
		finalResult = LeftVal + RightVal;
		return finalResult;
	case 3: 
		finalResult = LeftVal / RightVal;
		return finalResult;
	case 4: 
		finalResult = LeftVal * RightVal;
		return finalResult;
	case 5:
		finalResult = LeftVal % RightVal;
		return finalResult;
	}

	return 0;
}
string ExpressionManager:: postfixEvaluate(string postfixExpression)
{
	bool postToIn = isBalanced(postfixExpression);
	stack<string>number_stack;
	stringstream ss(postfixExpression);
	string next;
	stack<string>num_stack;
	if (postToIn)
	{
		while (ss >> next)
		{
			if (isNum(next))
			{
				number_stack.push(next);
				continue;
			}

			if (isSign(next))
			{
				if (number_stack.empty()) { return false; }
				string right_num = number_stack.top();
				number_stack.pop();
				string left_num = number_stack.top();
				number_stack.pop();
				string signForEquation = next;
				int number_to_push = EvaluateExpression(right_num, left_num, signForEquation);
				stringstream rr;
				rr << number_to_push;
				string numToAdd = rr.str();
				number_stack.push(numToAdd);
			}
		}
	}
	else
	{
		return false;
	}
}
