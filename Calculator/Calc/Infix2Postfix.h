#pragma once
/*
Infix to postfix conversion in C++
Input Postfix expression must be in a desired format.
Operator must be single character.
Support for multi character operands.
Only '+','-','*','/','^','%' (for root) and '$' (for exponentiation)  operators are expected.
*/

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Infix2Postfix
{
	string infix;			// input expression
	string result;			// output expression (after conversion to rpn)
	stringstream postfix;	
	stack<char> stack;		

public:
	Infix2Postfix();		// default constr.
	Infix2Postfix(string);	// constr. with input expression
	~Infix2Postfix();		// destr.

	void SetExpression(string);	
	string GetExpression();
	string GetPostfixResult();
	string runConverter();

private:
	string convertToPostfix();
	bool isOperator(char currentChar);
	bool precedence(char leftOperator, char rightOperator);
};

