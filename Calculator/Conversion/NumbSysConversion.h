#pragma once
/*
Class to convert number system values
- NSF - Not Specyfied - if In/Out Types are not specified
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

enum NumSysConvTypes {
	BIN = 0,
	OCT = 1,
	HEX = 2,
	DEC = 3,	

	N_NSF = 4	// Not specified
};

class NumbSysConversion
{
	double p_inputVal;
	double p_outputVal;	
	string p_inputVal_AsString;
	string p_outputVal_AsString;

	NumSysConvTypes p_inputType;
	NumSysConvTypes p_outputType;

public:
	NumbSysConversion();
	NumbSysConversion(double in, NumSysConvTypes in_type, NumSysConvTypes out_type);
	NumbSysConversion(double in, NumSysConvTypes in_type);
	NumbSysConversion(string in, NumSysConvTypes in_type, NumSysConvTypes out_type);
	NumbSysConversion(string in, NumSysConvTypes in_type);
	~NumbSysConversion();

	double GetInputVal();
	double GetOutputVal();
	string GetOutputVal_AsString();
	void SetInputVal(double);
	void SetInputVal(string);
	void SetInputType(NumSysConvTypes);
	void SetOutputType(NumSysConvTypes);

	void runConversion();

private:
	void Conversion();
	void ShowInputTypeError();
	void ShowOutputTypeError();

	string DecToBin(int number);
	int BinToDec(string& number);

	string DecToHex(int);
	int HexToDec(string);

	int DecToOct(int);
	//int OctToDec(string val);
	int OctToDec(int);

};

