#pragma once

#include "Calc\calcRPN.h"
#include "Calculator\Calc\Infix2Postfix.h"
#include "Calc\NumbSysInterpreter.h"
#include "Calculator\Conversion\NumbSysConversion.h"

class Calculator
{
	string p_expression;
	string p_outVal="0";
	NumbSysInterpreter InputExpression;
	Infix2Postfix ConvertExpression;
	calcRPN CalcExpression;
	NumbSysConversion OutputVal;

public:
	Calculator();
	Calculator(string);
	~Calculator();

	string GetInputExpr();
	string GetOutputExpr();
	string GetOutputVal();

	void SetInputExpr(string);
	void RunCalc();

};

