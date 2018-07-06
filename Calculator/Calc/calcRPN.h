#pragma once
/*
Postfix (RPN) calculator in C++
Operator must be single character.
Support for multi character operands.
Only '+','-','*','/','^','%' (for root) and '$' (for exponentiation)  operators are expected.
*/

/*
wzorzec projektowy Interpreter - do interpretacji wyra¿eñ zapisanych w RPN
*/

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

class calcRPN
{
	stack<double> stack;		
	string e;					// element of RPN expression
	string expression = NULL;
	double v1, v2;				//	arguments of operation
	stringstream ss;			
	double result;				

public:
	calcRPN();
	calcRPN(string);
	~calcRPN();

	void setExpression(string);
	string getExpression();
	double getResult();
	void runCalculate();

private:
	double Calculate();
	void Operator(double& a, double b, char op);
};

