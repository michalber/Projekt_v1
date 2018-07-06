#include "WeightConversion.h"


WeightConversion::WeightConversion() :p_inputVal(0), p_inputType(W_NSF), p_outputType(W_NSF)
{
}

WeightConversion::WeightConversion(double in, WeightConvTypes in_type, WeightConvTypes out_type) : p_inputVal(in), p_inputType(in_type), p_outputType(out_type)
{
	p_outputVal = Conversion(p_inputVal);
}

WeightConversion::WeightConversion(double in, WeightConvTypes in_type) : p_inputVal(in), p_inputType(in_type), p_outputType(W_NSF)
{
	p_outputVal = Conversion(p_inputVal);
}


WeightConversion::~WeightConversion()
{
}

double WeightConversion::GetInputVal()
{
	return p_inputVal;
}

double WeightConversion::GetOutputVal()
{
	return p_outputVal;
}

void WeightConversion::SetInputVal(double inputVal)
{
	p_inputVal = inputVal;
}

void WeightConversion::SetInputType(WeightConvTypes inputType)
{
	p_inputType = inputType;
}

void WeightConversion::SetOutpuType(WeightConvTypes outputType)
{
	p_outputType = outputType;
}

void WeightConversion::runConversion()
{
	p_outputVal=Conversion(p_inputVal);
}

double WeightConversion::Conversion(double)
{
	switch (p_inputType) {
	//sprowadzenie wszystkich wartoœci do kilogramow
	case 0:	return OutputTypeConv(); break;								// kg
	case 1:	p_inputVal /= 1000; return OutputTypeConv(); break;			// g
	case 2:	p_inputVal /= 1000000; return OutputTypeConv(); break;		// mg
	case 3:	p_inputVal *= 0.4536; return OutputTypeConv(); break;		// lb
	case 4:	p_inputVal *= 0.0283; return OutputTypeConv(); break;		// oz

	case 5:
	default: ShowInputTypeError(); return 0; break;						// NSF
	}
}

double WeightConversion::OutputTypeConv()
{
	double buff = p_inputVal;
	// kg -> p_outputType
	switch (p_outputType) {
	case 0:	return p_inputVal; break;					// kg
	case 1:	return p_inputVal *= 1000; break;			// g
	case 2:	return p_inputVal *= 1000000; break;		// mg
	case 3:	return p_inputVal /= 0.4536; break;			// lb
	case 4:	return p_inputVal /= 0.0283; break;			// oz

	case 5:
	default: ShowOutputTypeError(); return 0; break;	// NSF
	}
}

void WeightConversion::ShowInputTypeError()
{
	cout << "Input conversion type not specified" << endl;
}

void WeightConversion::ShowOutputTypeError()
{
	cout << "Output conversion type not specified" << endl;
}
