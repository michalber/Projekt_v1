#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "LengthConversion.h"
#include "WeightConversion.h"
#include "PowerConversion.h"
#include "TempConversion.h"
#include "NumbSysConversion.h"

enum ConvTypes {
	Length = 0,		// miliwatts
	Weight = 1,		// watts
	Power = 2,	// decibel-milliwatt
	Temp = 3,	// decibell-watt
	Numb = 4,		// millivolts

	C_NSF = 5	// Not specified
};

class Converter
{
	ConvTypes Type;

	double p_inputVal;
	double p_outputVal;
	string p_inputVal_AsString;
	string p_outputVal_AsString="";
	bool IsInputType = 0;
	bool IsOutputType = 0;

	LengthConversion ConvLen;
	WeightConversion ConvWei;
	PowerConversion ConvPow;
	TempConversion ConvTemp;
	NumbSysConversion ConvNumSys;

public:
	Converter();
	Converter(double numb);
	//--------------------------- wersja dla konwersji d³ugosci ---------------------------
	Converter(double numb,LengthConvTypes in,LengthConvTypes out);
	Converter(double numb, LengthConvTypes in);
	//--------------------------- wersja dla konwersji masy ---------------------------
	Converter(double numb, WeightConvTypes in, WeightConvTypes out);
	Converter(double numb, WeightConvTypes in);
	//--------------------------- wersja dla konwersji mocy ---------------------------
	Converter(double numb, PowerConvTypes in, PowerConvTypes out);
	Converter(double numb, PowerConvTypes in);
	//--------------------------- wersja dla konwersji temperatury ---------------------------
	Converter(double numb, TempConvTypes in, TempConvTypes out);
	Converter(double numb, TempConvTypes in);
	//--------------------------- wersja dla konwersji liczb ---------------------------
	Converter(double numb, NumSysConvTypes in, NumSysConvTypes out);
	Converter(double numb, NumSysConvTypes in);
	Converter(string numb, NumSysConvTypes in, NumSysConvTypes out);
	Converter(string numb, NumSysConvTypes in);
	//-------------------------------------------------------------------------------------------
	~Converter();

	double GetInputVal();
	string GetInputVal_AsString();
	double GetOutputVal();
	string GetOutputValAsString();
	bool IsInputTypeSet();
	bool IsOutputTypeSet();
	void SetInputVal(double);
	void SetInputVal(string);

	void SetInputType(LengthConvTypes);
	void SetInputType(WeightConvTypes);
	void SetInputType(PowerConvTypes);
	void SetInputType(TempConvTypes);
	void SetInputType(NumSysConvTypes);

	void SetOutputType(LengthConvTypes);
	void SetOutputType(WeightConvTypes);
	void SetOutputType(PowerConvTypes);
	void SetOutputType(TempConvTypes);
	void SetOutputType(NumSysConvTypes);
};

