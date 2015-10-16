#pragma once
#include "ExpressionManagerInterface.h"

class ExpressionManager : public ExpressionManagerInterface {
public:
	ExpressionManager();
	virtual ~ExpressionManager();
	bool isParenthesis(string letter);
	bool isNum(string letter);
	bool isSign(string letter);
	bool isBalanced(string expression);
	bool validateString(string stringToEvaluate);
	const int OPEN_PAREN = 1;
	const int CLOSE_PAREN = 0;
	int paren_type(char parenth);
	int sign_type(char sign);
	int sign_type2(char sign);
	int EvaluateExpression(string rightSide, string leftSide, string sign);


	/**
	* Converts a postfix expression into an infix expression
	* and returns the infix expression.
	*
	* - The given postfix expression will have a space between every number or operator.
	* - The returned infix expression must have a space between every number or operator.
	* - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if postfixExpression is not a valid postfix expression.
	* otherwise, return the correct infix expression as a string.
	*/
	string postfixToInfix(string postfixExpression);

	/*
	* Converts an infix expression into a postfix expression
	* and returns the postfix expression
	*
	* - The given infix expression will have a space between every number or operator.
	* - The returned postfix expression must have a space between every number or operator.
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if infixExpression is not a valid infix expression.
	* otherwise, return the correct postfix expression as a string.
	*/
	string infixToPostfix(string infixExpression);

	/*
	* Evaluates a postfix expression returns the result as a string
	*
	* - The given postfix expression will have a space between every number or operator.
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if postfixExpression is not a valid postfix Expression
	* otherwise, return the correct evaluation as a string
	*/
	string postfixEvaluate(string postfixExpression);

};

