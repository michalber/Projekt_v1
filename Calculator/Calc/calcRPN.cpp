#include "calcRPN.h"



calcRPN::calcRPN():expression("0")
{
}

calcRPN::calcRPN(string _expression): expression(_expression)
{
	Calculate();
}


calcRPN::~calcRPN()
{
}

void calcRPN::setExpression(string _expression)
{
	expression = _expression;
}

string calcRPN::getExpression()
{
	return expression;
}

double calcRPN::getResult()
{
	return result;
}

void calcRPN::runCalculate()
{
	Calculate();
}

void calcRPN::Operator(double& a, double b, char op) {
	switch (op)      // wykonujemy operacje wg operatora
	{
	case '+': a += b; break;
	case '-': a -= b; break;
	case '*': a *= b; break;
	case '/': a /= b; break;
	case '^': a = pow(a,b); break;
	case '%': a = pow(a,1/b); break;
		
	default:break;
	}
}

double calcRPN::Calculate()
{
	int i = 0;
	expression.push_back(' ');
	expression.push_back('=');		//dodanie spacji i '=' na koncu 
	expression.push_back(' ');

	if (expression.length() > 3) {
		while (true)           // w pêtli przetwarzamy wyra¿enie ONP
		{
			e.erase();
			while (!isblank(expression[i])) {	// wpisywanie do bufora wartoœci liczby a¿ nie napotka spacji 
				e.push_back(expression[i++]);
			}
			i++;

			if (e == "=")	break; // sprawdzamy koniec wyra¿enia
			
			ss.str("");         // usuwamy wszelki tekst ze strumienia
			ss.clear();         // czyœcimy b³êdy konwersji z poprzednich wywo³añ
			ss << e;            // odczytany element umieszczamy w strumieniu

			if (ss >> v1) {       // konwertujemy na liczbê i sprawdzamy, czy nie by³o b³êdu
								 // liczba
				stack.push(v1);      // umieszczamy j¹ na stosie
			}
			else 
			{                   // operator
				v2 = stack.top();
				stack.pop();		// pobieramy ze stosu dwa argumenty
				v1 = stack.top();
				stack.pop();

				Operator(v1, v2, e[0]);	// wykonujemy operacje wg operatora

				stack.push(v1);      // wynik umieszczamy na stosie
			}
		}

		result = stack.top();
		stack.pop();

		//cout << expression << endl;
		//cout << result << endl; // wypisujemy wynik ze szczytu stosu

		return result;
	}
	else {
		//throw runtime_error("There's no input expression");
		return 0;
	}
}