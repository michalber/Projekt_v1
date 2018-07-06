#include "Converter.h"


Converter::Converter():Type(C_NSF)
{
	p_inputVal = 0;
}

Converter::Converter(double numb):p_inputVal(numb),Type(C_NSF)
{
}

Converter::~Converter()
{
}

bool Converter::IsInputTypeSet() {
	return IsInputType;
}

bool Converter::IsOutputTypeSet() {
	return IsOutputType;
}

double Converter::GetInputVal()
{
	return p_inputVal;
}

string Converter::GetInputVal_AsString()
{
	return p_inputVal_AsString;
}

double Converter::GetOutputVal()
{
	return p_outputVal;
}

string Converter::GetOutputValAsString()
{
	if (p_outputVal_AsString == "")
		return to_string(p_outputVal);
	else
		return p_outputVal_AsString;
}

void Converter::SetInputVal(double val)
{
	p_inputVal = val;

	switch (Type) {
	case 0: ConvLen.SetInputVal(p_inputVal);
			ConvLen.runConversion(); 
			p_outputVal_AsString = to_string(ConvLen.GetOutputVal()); break;
	case 1: ConvWei.SetInputVal(p_inputVal);
			ConvWei.runConversion();
			p_outputVal_AsString = to_string(ConvWei.GetOutputVal());break;
	case 2:	ConvPow.SetInputVal(p_inputVal);
			ConvPow.runConversion(); 
			p_outputVal_AsString = to_string(ConvLen.GetOutputVal());break;
	case 3: ConvTemp.SetInputVal(p_inputVal);
			ConvTemp.runConversion();
			p_outputVal_AsString = to_string(ConvTemp.GetOutputVal());break;
	case 4: ConvNumSys.SetInputVal(p_inputVal);
			ConvNumSys.runConversion(); 
			p_outputVal_AsString = to_string(ConvNumSys.GetOutputVal());break;
	case 5:
	default: break;
	}
}

void Converter::SetInputVal(string val)
{
	p_inputVal_AsString = val;

	switch (Type) {
	case 0:
		p_inputVal = stod(p_inputVal_AsString);
		ConvLen.SetInputVal(p_inputVal);
		ConvLen.runConversion();
		p_outputVal = ConvLen.GetOutputVal(); break;
	case 1:
		p_inputVal = stod(p_inputVal_AsString);
		ConvWei.SetInputVal(p_inputVal);
		ConvWei.runConversion();
		p_outputVal = ConvWei.GetOutputVal();break;
	case 2:
		p_inputVal = stod(p_inputVal_AsString);
		ConvPow.SetInputVal(p_inputVal);
		ConvPow.runConversion();
		p_outputVal = ConvLen.GetOutputVal();break;
	case 3:
		p_inputVal = stod(p_inputVal_AsString);
		ConvTemp.SetInputVal(p_inputVal);
		ConvTemp.runConversion();
		p_outputVal = ConvTemp.GetOutputVal();break;
	case 4: 
		ConvNumSys.SetInputVal(p_inputVal_AsString);
		ConvNumSys.runConversion();
		p_outputVal = ConvNumSys.GetOutputVal();break;
	case 5:
	default: break;
	}
}

//-------------------------------------------------------------------------------------
//--------------------------- wersja dla konwersji d³ugosci ---------------------------
//-------------------------------------------------------------------------------------

Converter::Converter(double numb, LengthConvTypes in, LengthConvTypes out):p_inputVal(numb),Type(Length)
{
	ConvLen.SetInputType(in);
	ConvLen.SetOutpuType(out);
	ConvLen.SetInputVal(p_inputVal);
	ConvLen.runConversion();
	p_outputVal = ConvLen.GetOutputVal();
}

Converter::Converter(double numb, LengthConvTypes in) :p_inputVal(numb), Type(Length)
{
	ConvLen.SetInputType(in);
	ConvLen.SetInputVal(numb);
}

void Converter::SetInputType(LengthConvTypes in)
{
	IsInputType = 1;
	ConvLen.SetInputType(in);
}

void Converter::SetOutputType(LengthConvTypes out)
{
	IsOutputType = 1;
	ConvLen.SetOutpuType(out);
}


//-------------------------------------------------------------------------------------
//--------------------------- wersja dla konwersji masy ---------------------------
//-------------------------------------------------------------------------------------

Converter::Converter(double numb, WeightConvTypes in, WeightConvTypes out) :p_inputVal(numb), Type(Weight)
{
	ConvWei.SetInputType(in);
	ConvWei.SetOutpuType(out);
	ConvWei.SetInputVal(numb);
	ConvWei.runConversion();
	p_outputVal = ConvWei.GetOutputVal();
}

Converter::Converter(double numb, WeightConvTypes in) :p_inputVal(numb), Type(Weight)
{
	ConvWei.SetInputType(in);
	ConvWei.SetInputVal(numb);
}

void Converter::SetInputType(WeightConvTypes in)
{
	IsInputType = 1;
	ConvWei.SetInputType(in);
}

void Converter::SetOutputType(WeightConvTypes out)
{
	IsOutputType = 1;
	ConvWei.SetOutpuType(out);
}

//-------------------------------------------------------------------------------------
//--------------------------- wersja dla konwersji mocy ---------------------------
//-------------------------------------------------------------------------------------

Converter::Converter(double numb, PowerConvTypes in, PowerConvTypes out) :p_inputVal(numb), Type(Power)
{
	ConvPow = PowerConversion(numb, in, out);
	p_outputVal = ConvPow.GetOutputVal();
}

Converter::Converter(double numb, PowerConvTypes in) :p_inputVal(numb), Type(Power)
{
	ConvPow.SetInputType(in);
	ConvPow.SetInputVal(numb);
}

void Converter::SetInputType(PowerConvTypes in)
{
	IsInputType = 1;
	ConvPow.SetInputType(in);
	ConvPow.runConversion();
	p_outputVal = ConvPow.GetOutputVal();
}

void Converter::SetOutputType(PowerConvTypes out)
{
	IsOutputType = 1;
	ConvPow.SetOutpuType(out);
	ConvPow.runConversion();
	p_outputVal = ConvPow.GetOutputVal();
}


//-------------------------------------------------------------------------------------
//--------------------------- wersja dla konwersji temperatury ---------------------------
//-------------------------------------------------------------------------------------


Converter::Converter(double numb, TempConvTypes in, TempConvTypes out) :p_inputVal(numb), Type(Temp)
{
	ConvTemp.SetInputType(in);
	ConvTemp.SetOutpuType(out);
	ConvTemp.SetInputVal(numb);
	ConvTemp.runConversion();
	p_outputVal = ConvTemp.GetOutputVal();
}

Converter::Converter(double numb, TempConvTypes in) :p_inputVal(numb), Type(Temp)
{
	ConvTemp.SetInputType(in);
	ConvTemp.SetInputVal(numb);
}

void Converter::SetInputType(TempConvTypes in)
{
	IsInputType = 1;
	ConvTemp.SetInputType(in);
}

void Converter::SetOutputType(TempConvTypes out)
{
	IsOutputType = 1;
	ConvTemp.SetOutpuType(out);
}


//-------------------------------------------------------------------------------------
//--------------------------- wersja dla konwersji liczb ---------------------------
//-------------------------------------------------------------------------------------

Converter::Converter(double numb, NumSysConvTypes in, NumSysConvTypes out) :p_inputVal(numb), Type(Numb)
{
	ConvNumSys = NumbSysConversion(numb, in, out);
	/*ConvNumSys.SetInputType(in);
	ConvNumSys.SetOutpuType(out);
	ConvNumSys.SetInputVal(numb);
	ConvNumSys.runConversion();*/
	p_outputVal = ConvNumSys.GetOutputVal();
	p_outputVal_AsString = ConvNumSys.GetOutputVal_AsString();
}

Converter::Converter(double numb, NumSysConvTypes in) :p_inputVal(numb), Type(Numb)
{
	ConvNumSys.SetInputType(in);
	ConvNumSys.SetInputVal(numb);
}

Converter::Converter(string numb, NumSysConvTypes in, NumSysConvTypes out) : p_inputVal_AsString(numb), Type(Numb)
{
	ConvNumSys = NumbSysConversion(numb, in, out);
	/*ConvNumSys.SetInputType(in);
	ConvNumSys.SetOutpuType(out);
	ConvNumSys.SetInputVal(numb);
	ConvNumSys.runConversion();*/
	p_outputVal = ConvNumSys.GetOutputVal();
	p_outputVal_AsString = ConvNumSys.GetOutputVal_AsString();
}

Converter::Converter(string numb, NumSysConvTypes in) :p_inputVal_AsString(numb), Type(Numb)
{
	ConvNumSys.SetInputType(in);
	ConvNumSys.SetInputVal(numb);
}

void Converter::SetInputType(NumSysConvTypes in)
{
	IsInputType = 1;
	ConvNumSys.SetInputType(in);
}

void Converter::SetOutputType(NumSysConvTypes out)
{
	IsOutputType = 1;
	ConvNumSys.SetOutputType(out);
}
