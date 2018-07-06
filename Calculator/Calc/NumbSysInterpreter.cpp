#include "NumbSysInterpreter.h"




NumbSysInterpreter::NumbSysInterpreter() : p_InputEquation("")
{
}

NumbSysInterpreter::NumbSysInterpreter(string input) : p_InputEquation(input)
{
	RunInterpreter();
}


NumbSysInterpreter::~NumbSysInterpreter()
{
}

string NumbSysInterpreter::getInputEquation()
{
	return p_InputEquation;
}

string NumbSysInterpreter::getOutputEquation()
{
	return p_OutputEquation;
}

NumSysConvTypes NumbSysInterpreter::getInputType()
{
	return p_InputType;
}

void NumbSysInterpreter::SetInputEquation(string in)
{
	p_InputEquation = in;
}


void NumbSysInterpreter::RunInterpreter()
{
	// czyszczenie wejœiowego wyra¿enia z bia³ych znaków
	p_InputEquation.erase(remove_if(p_InputEquation.begin(), p_InputEquation.end(), isspace), p_InputEquation.end());
	p_InputEquation += '?';		// oznaczenie koñca wyra¿enia do interpetacji

	p_TypeBuff = "";

	int i=0;
	int j;

	while (i < p_InputEquation.length()) {

		//zczytanie typu liczby
		for (j = i; j < (i + 2);j++) {
			p_TypeBuff += p_InputEquation[j];	// zczytaj typ liczby
		}

		//sprawdz czy jest okreœlony typ liczby, je¿eli nie to nadaj jej typ DEC
		if(isType(p_TypeBuff)) i = j;
		else { p_TypeBuff = "dx"; }

		// przekonwertuj j¹ na obs³ugiwany typ i ustal jako typ wejœciowy lub buforowy
		if (i <= 2) { p_InputType = CheckType(p_TypeBuff); p_buffType = CheckType(p_TypeBuff); }
		else 	p_buffType = CheckType(p_TypeBuff);
	
		// zczytaj liczbê 
		while (!isOperator(p_InputEquation[i])) {
			if (p_InputEquation[i] == '?') break;
			else if (p_InputEquation[i] != '?') p_NumberBuff += p_InputEquation[i];
			else p_OutputEquation += p_InputEquation[i];
			i++;
		}
		// przyspieszenie dzia³ania przez bezpoœniednie wpisanie liczby je¿eli jest typem DEC
		if (p_buffType != DEC) {
			// skonwertuj liczbe z zczytanego systemu do systemu DEC
			NumbSysConversion Liczba(p_NumberBuff, p_buffType, DEC); /// to mo¿na zastapic jedna klasa ktora bedzie liczyla 
																	 /// to samo tyle ze trzeba zrobic kopie funkcji dla 3 argumentow
			// wpisz skonwertowan¹ liczbe do wyra¿enia wyjœciowego 
			p_OutputEquation += Liczba.GetOutputVal_AsString();
		}
		// wpisz liczbe DEC do wyra¿enia wyjœciowego 
		else p_OutputEquation += p_NumberBuff;

		p_OutputEquation += p_InputEquation[i++];

		if (isOperator(p_InputEquation[i])) { p_OutputEquation += p_InputEquation[i++];}

		p_TypeBuff.erase();
		p_NumberBuff.erase();
	}

	p_OutputEquation.pop_back();
}

NumSysConvTypes NumbSysInterpreter::CheckType(string EqInType) // EqInType === EquationInputType
{
	if (EqInType == "0x") return HEX;
	else if (EqInType == "dx") return DEC;
	else if (EqInType == "bx") return BIN;
	else if (EqInType == "ox") return OCT;
	else {
		throw runtime_error("invalid number conversion type");
		return N_NSF;
	}
}

bool NumbSysInterpreter::isOperator(char currentChar)
{
	switch (currentChar) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '%':
	case '(':
	case ')':
		return true;
	default:
		return false;
	}
}

bool NumbSysInterpreter::isType(string inType)
{
	if (inType == "0x" ||
		inType == "dx" ||
		inType == "bx" ||
		inType == "ox" ) return true;
	else return false;
}
