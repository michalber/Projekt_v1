#include "NumbSysConversion.h"


NumbSysConversion::NumbSysConversion() :p_inputVal(0), p_inputType(N_NSF), p_outputType(N_NSF)
{
}

NumbSysConversion::NumbSysConversion(double in, NumSysConvTypes in_type, NumSysConvTypes out_type) : p_inputVal(in), p_inputType(in_type), p_outputType(out_type)
{
	Conversion();
}

NumbSysConversion::NumbSysConversion(double in, NumSysConvTypes in_type) : p_inputVal(in), p_inputType(in_type), p_outputType(N_NSF)
{
	Conversion();
}

NumbSysConversion::NumbSysConversion(string in, NumSysConvTypes in_type, NumSysConvTypes out_type) : p_inputVal_AsString(in), p_inputType(in_type), p_outputType(out_type)
{
	if (in_type == HEX)
	{
		p_inputVal_AsString = in;
	}
	else if (in_type == BIN) {
		p_inputVal_AsString = in;
	}
	else
		p_inputVal = stod(in);

	Conversion();
}

NumbSysConversion::NumbSysConversion(string in, NumSysConvTypes in_type) : p_inputVal_AsString(in), p_inputType(in_type), p_outputType(N_NSF)
{
	Conversion();
}

NumbSysConversion::~NumbSysConversion()
{
}

double NumbSysConversion::GetInputVal()
{
	return p_inputVal;
}

double NumbSysConversion::GetOutputVal()
{
	return p_outputVal;
}

string NumbSysConversion::GetOutputVal_AsString()
{
	/*if (p_outputVal != 0) {
		std::ostringstream strs;
		strs << p_outputVal;
		std::string str = strs.str();
		return str;
	}
	else {*/
		return p_outputVal_AsString;
	
}

void NumbSysConversion::SetInputVal(double in)
{
	p_inputVal = in;
}

void NumbSysConversion::SetInputVal(string val)
{
	p_inputVal_AsString = val;
}

void NumbSysConversion::SetInputType(NumSysConvTypes in)
{
	p_inputType = in;
}

void NumbSysConversion::SetOutputType(NumSysConvTypes out)
{
	p_outputType = out;
}

string NumbSysConversion::DecToBin(int number)
{
	if (number == 0) return "0";
	if (number == 1) return "1";

	if (number % 2 == 0)
		return DecToBin(number / 2) + "0";
	else
		return DecToBin(number / 2) + "1";
}

int NumbSysConversion::BinToDec(string& number)
{
	if (number[0] == 'b' && number[1] == 'x')
		number.erase(0, 2);
	int result = 0, pow = 1;
	for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
		result += (number[i] - '0') * pow;

	return result;
}

string NumbSysConversion::DecToHex(int val)
{
	stringstream buff;
	buff << std::hex << val;
	string result;
	result = buff.str();

	return result;
}

int NumbSysConversion::HexToDec(string val)
{
	string val_copy;
	if (val[0] == '0' && val[1] == 'x')
		val_copy = val;
	else
		val_copy = "0x" + val;
	stringstream buff;
	buff << std::dec << val_copy;
	int result;
	result = stod(buff.str());

	return result;
}

int NumbSysConversion::DecToOct(int val)
{
	stringstream buff;
	buff << std::oct << val;
	int result;
	result = stoi(buff.str());

	return result;
}

int NumbSysConversion::OctToDec(int val)
{
	int result = 0, i = 0, rem;
	while (val != 0)
	{
		rem = val % 10;
		val /= 10;
		result += rem * pow(8, i);
		++i;
	}
	return result;
}


void NumbSysConversion::runConversion()
{
	Conversion();
}



void NumbSysConversion::Conversion()
{
	switch (p_inputType) {

	case 0:																			// bin ->
		switch (p_outputType) {
		case 0: p_outputVal_AsString = p_inputVal_AsString; break;						// bin
		case 1: p_outputVal = DecToOct(BinToDec(p_inputVal_AsString)); 
				p_outputVal_AsString = to_string(p_outputVal);break;					// oct
		case 2: p_outputVal_AsString = DecToHex(BinToDec(p_inputVal_AsString)); break;	// hex
		case 3: p_outputVal = BinToDec(p_inputVal_AsString);
				p_outputVal_AsString = to_string(p_outputVal); break;					// dec	
		case 4: ShowOutputTypeError(); p_outputVal = 0; break;							// NSF
		}	
	break;					

	case 1:																			// oct ->
		switch (p_outputType) {
		case 0: p_outputVal_AsString = DecToBin(OctToDec(p_inputVal)); break;			// bin
		case 1: p_outputVal = p_inputVal; 
				p_outputVal_AsString = to_string(p_outputVal); break;					// oct
		case 2: p_outputVal_AsString = DecToHex(OctToDec(p_inputVal)); break;			// hex
		case 3: p_outputVal = OctToDec(p_inputVal); 
				p_outputVal_AsString = to_string(p_outputVal); break;					// dec	
		case 4: ShowOutputTypeError(); p_outputVal = 0; break;							// NSF
		}
	break;	
		
	case 2:																			// hex ->
		switch (p_outputType) {
		case 0: p_outputVal_AsString = DecToBin(HexToDec(p_inputVal_AsString)); break;	// bin
		case 1: p_outputVal = DecToOct(HexToDec(p_inputVal_AsString));
				p_outputVal_AsString = to_string(p_outputVal); break;					// oct
		case 2: p_outputVal_AsString = p_inputVal_AsString; break;						// hex
		case 3: p_outputVal = HexToDec(p_inputVal_AsString);
				p_outputVal_AsString = to_string(p_outputVal); break;					// dec	
		case 4: ShowOutputTypeError(); p_outputVal = 0; break;							// NSF
		}
	break;

	case 3:																			// dec ->
		switch (p_outputType) {
		case 0: p_outputVal_AsString = DecToBin(p_inputVal); break;						// bin
		case 1: p_outputVal = DecToOct(p_inputVal);
				p_outputVal_AsString = to_string(p_outputVal); break;					// oct
		case 2: p_outputVal_AsString = DecToHex(p_inputVal); break;						// hex
		case 3: p_outputVal = p_inputVal;
				p_outputVal_AsString = to_string(p_outputVal); break;					// dec	
		case 4: ShowOutputTypeError(); p_outputVal = 0; break;							// NSF
		}
	break;					

	case 4:
	default: ShowInputTypeError(); p_inputVal = 0; p_outputVal = 0; 
			 p_inputVal_AsString = "0"; p_outputVal_AsString = "0"; break;				// NSF
	}
}


void NumbSysConversion::ShowInputTypeError()
{
	cout << "Input conversion type not specified" << endl;
}

void NumbSysConversion::ShowOutputTypeError()
{
	cout << "Output conversion type not specified" << endl;
}
