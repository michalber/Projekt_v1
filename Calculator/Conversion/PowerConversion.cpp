#include "PowerConversion.h"


PowerConversion::PowerConversion() :p_inputVal(0),p_inputValRMS(0), p_inputType(P_NSF), p_outputType(P_NSF)
{
}

PowerConversion::PowerConversion(double in, PowerConvTypes in_type, PowerConvTypes out_type) : p_inputVal(in),p_inputValRMS(in), p_inputType(in_type), p_outputType(out_type)
{
	Conversion();
}

PowerConversion::PowerConversion(double in, PowerConvTypes in_type) : p_inputVal(in), p_inputValRMS(in), p_inputType(in_type), p_outputType(P_NSF)
{
	Conversion();
}

PowerConversion::~PowerConversion()
{
}

double PowerConversion::GetInputVal()
{
	return p_inputVal;
}

double PowerConversion::GetOutputVal()
{
	return p_outputVal;
}

double PowerConversion::GetOutputValRMS()
{
	if (p_inputType == k || p_inputType == dB) return NAN;
	else return p_outputVal_rms;
}

void PowerConversion::SetInputVal(double inputVal)
{
	p_inputVal = inputVal;
}

void PowerConversion::SetInputType(PowerConvTypes inputType)
{
	p_inputType = inputType;
}

void PowerConversion::SetOutpuType(PowerConvTypes outputType)
{
	p_outputType = outputType;
}

void PowerConversion::runConversion()
{
	p_outputVal=Conversion();
}

double PowerConversion::Conversion()
{
	switch (p_inputType) {
		//sprowadzenie wszystkich wartoœci do Voltów
	case 0:	
		p_inputVal *= 0.6325; p_inputValRMS *= 0.2236; return p_outputVal=OutputTypeConv(); break;		// mW
	case 1:
		p_inputVal *= 20; p_inputValRMS *= 7.0711; return p_outputVal = OutputTypeConv(); break;			// W
	case 2:	
		p_inputVal *= 0.7096; p_inputValRMS *= 0.2509; return p_outputVal = OutputTypeConv(); break;		// dBm
	case 3:
		p_inputVal *= 22.4404; p_inputValRMS *= 7.9339; return p_outputVal = OutputTypeConv(); break;		// dBw
	case 4:
		p_inputVal *= 0.0028; p_inputValRMS *= 0.0010; return p_outputVal = OutputTypeConv(); break;		// mV
	case 5:
		p_inputVal *= 2.8284; p_inputValRMS *= 1; return p_outputVal = OutputTypeConv(); break;			// V

	case 6:	
		if (p_outputType == dB) return p_outputVal = 20 * log(p_inputVal);					// k -> dB
		else ShowkKTodBTypeError(); return 0;
		break;		
	case 7:
		if (p_outputType == k) return p_outputVal = pow(10, p_inputVal / 20);				// dB -> k
		else ShowkKTodBTypeError(); return 0;
		break;
	
	case 8:
	default: ShowInputTypeError(); return 0; break;											// NSF
	}
}

double PowerConversion::OutputTypeConv()
{
	double buff = p_inputValRMS;
	// V -> p_outputType
	switch (p_outputType) {
	case 0:
		p_outputVal_rms = NAN; return buff * 0.0200; break;							// mW
	case 1:
		p_outputVal_rms = NAN; return buff * 20; break;								// W
	case 2:
		p_outputVal_rms = NAN; return buff *13.0103; break;							// dBm
	case 3:
		p_outputVal_rms = NAN; return buff *-16.9897; break;						// dBW
	case 4:
		p_outputVal_rms = p_inputValRMS*1000.0000; return buff *2828.4271; break;	// mV
	case 5:
		p_outputVal_rms = p_inputValRMS; return buff * 2.8284; break;				// V

	case 8:
	default: p_outputVal_rms = 0; ShowOutputTypeError(); return 0; break;								// NSF
	}
}

void PowerConversion::ShowInputTypeError()
{
	cout << "Input conversion type not specified" << endl;
}

void PowerConversion::ShowOutputTypeError()
{
	cout << "Output conversion type not specified" << endl;
}

void PowerConversion::ShowkKTodBTypeError()
{
	cout << "Conversion type error. k/dB can only by converted to dB/k!" << endl;

}
