#include "LengthConversion.h"


LengthConversion::LengthConversion() :p_inputVal(0), p_inputType(L_NSF), p_outputType(L_NSF)
{
}

LengthConversion::LengthConversion(double in, LengthConvTypes in_type, LengthConvTypes out_type) :p_inputVal(in), p_inputType(in_type), p_outputType(out_type)
{
	p_outputVal = Conversion();
}

LengthConversion::LengthConversion(double in, LengthConvTypes in_type) : p_inputVal(in), p_inputType(in_type),p_outputType(L_NSF)
{
	p_outputVal = Conversion();
}


LengthConversion::~LengthConversion()
{
}

double LengthConversion::GetInputVal()
{
	return p_inputVal;
}

double LengthConversion::GetOutputVal()
{
	return p_outputVal;
}

void LengthConversion::SetInputVal(double inputVal)
{
	p_inputVal = inputVal;
}

void LengthConversion::SetInputType(LengthConvTypes inputType)
{
	p_inputType = inputType;
}

void LengthConversion::SetOutpuType(LengthConvTypes outputType)
{
	p_outputType = outputType;
}

void LengthConversion::runConversion()
{
	p_outputVal = Conversion();
}

double LengthConversion::Conversion()
{
	switch (p_inputType) {
		//sprowadzenie wszystkich wartoœci do centymetrów
	case 0:	p_inputVal /= 10; return OutputTypeConv(); break;			// mm
	case 1:	return OutputTypeConv(); break;								// cm
	case 2:	p_inputVal *= 100; return OutputTypeConv(); break;			// m
	case 3:	p_inputVal *= 100000; return OutputTypeConv(); break;		// km

	case 4:	p_inputVal /= 393701.7659; return OutputTypeConv(); break;	// uin
	case 5:	p_inputVal *= 2.5400; return OutputTypeConv(); break;		// in
	case 6:	p_inputVal *= 30.4799; return OutputTypeConv(); break;		// ft
	case 7:	p_inputVal *= 91.4398; return OutputTypeConv(); break;		// yd
	case 8:	p_inputVal *= 160934; return OutputTypeConv(); break;		// mi
	case 9:
	default: ShowInputTypeError(); return 0; break;						// NSF
	}
}

double LengthConversion::OutputTypeConv()
{
	double buff = p_inputVal;
	// cm -> p_outputType
	switch (p_outputType) {
	case 0:	return 10*buff; break;					// mm
	case 1:	return buff; break;						// cm
	case 2:	return buff /100; break;				// m
	case 3:	return buff /100000; break;				// km
	case 4:	return buff*393701.7659; break;			// uin
	case 5:	return buff*0.3937; break;				// in
	case 6:	return buff / 30.4799; break;			// ft
	case 7:	return buff / 91.4398; break;			// yd
	case 8:	return buff / 160934; break;			// ml
	case 9:
	default: ShowOutputTypeError(); return 0; break;// NSF
	}
}

void LengthConversion::ShowInputTypeError()
{
	cout << "Input conversion type not specified" << endl;
}

void LengthConversion::ShowOutputTypeError()
{
	cout << "Output conversion type not specified" << endl;
}
