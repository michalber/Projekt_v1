#pragma once
/*
Class to convert length values
- NSF - Not Specyfied - if In/Out Types are not specified
*/

#include <iostream>
using namespace std;

enum TempConvTypes {
	F = 0,		// Farenheit
	C = 1,		// Celsius
	K = 2,		// Kelvin

	T_NSF = 3	// Not specified
};

class TempConversion
{
	double p_inputVal;
	double p_outputVal;

	TempConvTypes p_inputType;
	TempConvTypes p_outputType;

public:
	TempConversion();
	TempConversion(double, TempConvTypes, TempConvTypes);
	TempConversion(double, TempConvTypes);
	~TempConversion();

	double GetInputVal();
	double GetOutputVal();
	void SetInputVal(double);
	void SetInputType(TempConvTypes);
	void SetOutpuType(TempConvTypes);

	void runConversion();

private:
	double Conversion();
	double OutputTypeConv();
	void ShowInputTypeError();
	void ShowOutputTypeError();

};

