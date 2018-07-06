#include "Calculator.h"


Calculator::Calculator()
{
}

Calculator::Calculator(string inExpr) :p_expression(inExpr)
{
	RunCalc();
}


Calculator::~Calculator()
{
}

string Calculator::GetInputExpr()
{
	return InputExpression.getInputEquation();
}

string Calculator::GetOutputExpr()
{
	return ConvertExpression.GetPostfixResult();
}

string Calculator::GetOutputVal()
{
	p_outVal = OutputVal.GetOutputVal_AsString();
	if (p_outVal != "") {
		if (InputExpression.getInputType() == BIN) p_outVal = "bx" + p_outVal;
		else if (InputExpression.getInputType() == OCT) p_outVal = "ox" + p_outVal;
		else if (InputExpression.getInputType() == HEX) p_outVal = "0x" + p_outVal;
	}
	return p_outVal;
}

void Calculator::SetInputExpr(string in)
{
	p_expression = in;
	RunCalc();
}

void Calculator::RunCalc()
{
	InputExpression.SetInputEquation(p_expression);
	InputExpression.RunInterpreter();

	ConvertExpression.SetExpression(InputExpression.getOutputEquation());
	ConvertExpression.runConverter();

	CalcExpression.setExpression(ConvertExpression.GetPostfixResult());
	CalcExpression.runCalculate();

	OutputVal.SetInputVal(CalcExpression.getResult());
	OutputVal.SetInputType(DEC);
	OutputVal.SetOutputType(InputExpression.getInputType());
	OutputVal.runConversion();
}