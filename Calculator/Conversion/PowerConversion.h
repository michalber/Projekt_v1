#pragma once
/*
Class to convert power values
- NSF - Not Specyfied - if In/Out Types are not specified
- k can only by converted to dB or opposite 
*/

#include <iostream>
#include <math.h>
using namespace std;

enum PowerConvTypes {
	mW = 0,		// miliwatts
	W = 1,		// watts
	dBm = 2,	// decibel-milliwatt
	dBW = 3,	// decibell-watt
	mV = 4,		// millivolts
	V = 5,		// volts

	k = 6,		// gain -> dB
	dB =7,	

	P_NSF = 8	// Not specified
};

class PowerConversion
{
	double p_inputVal;
	double p_inputValRMS;
	double p_outputVal;	// Vpp
	double p_outputVal_rms;	// Vrms


	PowerConvTypes p_inputType;
	PowerConvTypes p_outputType;

public:
	PowerConversion();
	~PowerConversion();
	PowerConversion(double, PowerConvTypes, PowerConvTypes);
	PowerConversion(double, PowerConvTypes);

	double GetInputVal();
	double GetOutputVal();
	double GetOutputValRMS();
	void SetInputVal(double);
	void SetInputType(PowerConvTypes);
	void SetOutpuType(PowerConvTypes);

	void runConversion();

private:
	double Conversion();
	double OutputTypeConv();
	void ShowInputTypeError();
	void ShowOutputTypeError();
	void ShowkKTodBTypeError();
};

