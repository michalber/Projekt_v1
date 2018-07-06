#pragma once
/*
Class to convert length values
- NSF - Not Specyfied - if In/Out Types are not specified
*/

#include <iostream>
#include <string>
using namespace std;

enum LengthConvTypes {
	mm = 0,
	cm = 1,
	m = 2,
	km = 3,	// mili/centy/kilo - meters

	uin = 4,
	in = 5,
	ft = 6,
	yd = 7,
	mi = 8,	// microinch, inch, feet, yard, miles

	L_NSF = 9	// Not specified
};

class LengthConversion
{
	double p_inputVal;
	double p_outputVal;

	LengthConvTypes p_inputType;
	LengthConvTypes p_outputType;

public:
	LengthConversion();
	LengthConversion(double, LengthConvTypes, LengthConvTypes);
	LengthConversion(double, LengthConvTypes);
	~LengthConversion();
		
	double GetInputVal();
	double GetOutputVal();
	void SetInputVal(double);
	void SetInputType(LengthConvTypes);
	void SetOutpuType(LengthConvTypes);

	void runConversion();

private:
	double Conversion();
	double OutputTypeConv();
	void ShowInputTypeError();
	void ShowOutputTypeError();

};
