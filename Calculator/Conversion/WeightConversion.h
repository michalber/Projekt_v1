#pragma once
#include <iostream>
using namespace std;

enum WeightConvTypes {
	kg = 0,
	g = 1,
	mg = 2,
	lb = 3,	// pounds
	oz = 4,	// ounces

	W_NSF = 5	// Not specified
};

class WeightConversion
{
	double p_inputVal;
	double p_outputVal;

	WeightConvTypes p_inputType;
	WeightConvTypes p_outputType;

public:
	WeightConversion();
	WeightConversion(double in, WeightConvTypes in_type, WeightConvTypes out_type);
	WeightConversion(double, WeightConvTypes in_type);
	~WeightConversion();

	double GetInputVal();
	double GetOutputVal();
	void SetInputVal(double);
	void SetInputType(WeightConvTypes);
	void SetOutpuType(WeightConvTypes);

	void runConversion();

private:
	double Conversion(double);
	double OutputTypeConv();
	void ShowInputTypeError();
	void ShowOutputTypeError();

};

