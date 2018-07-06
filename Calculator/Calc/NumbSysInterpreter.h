#pragma once
/*
Interpreter do sprowadzenia wartoœci liczb zapisanych w ró¿nych systemach liczbowych
0x... -- hex
dx... -- dec
bx... -- bin
ox... -- oct
*/

/*
wzorzec projektowy Interpreter - do reinterpretacji wyra¿eñ zapisanych w ró¿nych systemach liczbowych 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "Calculator\Conversion\NumbSysConversion.h"

using std::cin;
using std::cout;
using std::string;


class NumbSysInterpreter
{
	string p_InputEquation;
	string p_OutputEquation;

	string p_TypeBuff;
	string p_NumberBuff;

	NumSysConvTypes p_InputType;
	NumSysConvTypes p_buffType;


public:
	NumbSysInterpreter();
	NumbSysInterpreter(string);
	~NumbSysInterpreter();
	string getInputEquation();
	string getOutputEquation();
	NumSysConvTypes getInputType();
	void SetInputEquation(string);
	void RunInterpreter();

private:
	NumSysConvTypes CheckType(string);
	bool isOperator(char currentChar);
	bool isType(string);
};

