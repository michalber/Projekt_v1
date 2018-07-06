#include "TempConversion.h"


TempConversion::TempConversion() :p_inputVal(0), p_inputType(T_NSF), p_outputType(T_NSF)
{
}

TempConversion::TempConversion(double in, TempConvTypes in_type, TempConvTypes out_type) : p_inputVal(in), p_inputType(in_type), p_outputType(out_type)
{
	p_outputVal = Conversion();
}

TempConversion::TempConversion(double in, TempConvTypes in_type) : p_inputVal(in), p_inputType(in_type), p_outputType(T_NSF)
{
	p_outputVal = Conversion();
}

TempConversion::~TempConversion()
{
}

double TempConversion::GetInputVal()
{
	return p_inputVal;
}

double TempConversion::GetOutputVal()
{
	return p_outputVal;
}

void TempConversion::SetInputVal(double inputVal)
{
	p_inputVal = inputVal;
}

void TempConversion::SetInputType(TempConvTypes inputType)
{
	p_inputType = inputType;
}

void TempConversion::SetOutpuType(TempConvTypes outputType)
{
	p_outputType = outputType;
}

void TempConversion::runConversion()
{
	p_outputVal=Conversion();
}

double TempConversion::Conversion()
{
	switch (p_inputType) {
		//sprowadzenie wszystkich wartoœci do Celsiuszy
	case 0:	p_inputVal = 5 * (p_inputVal - 32) / 9; return OutputTypeConv(); break;			// F
	case 1:	return OutputTypeConv(); break;													// C
	case 2:	p_inputVal -= 273.15; return OutputTypeConv(); break;							// K

	case 3:
	default: ShowInputTypeError(); return 0; break;											// NSF
	}
}

double TempConversion::OutputTypeConv()
{
	double buff = p_inputVal;
	// Celsius -> p_outputType
	switch (p_outputType) {
	case 0:	return 9 * buff / 5 + 32; break;			// F
	case 1:	return buff; break;							// C
	case 2:	return buff + 273.15; break;				// K

	case 3:
	default: ShowOutputTypeError(); return 0; break;	// NSF
	}
}

void TempConversion::ShowInputTypeError()
{
	cout << "Input conversion type not specified" << endl;
}

void TempConversion::ShowOutputTypeError()
{
	cout << "Output conversion type not specified" << endl;
}
