#include "Infix2Postfix.h"



Infix2Postfix::Infix2Postfix() :infix(""), result("")
{
}

Infix2Postfix::Infix2Postfix(string _expression):infix(_expression), result("")
{
	convertToPostfix();
}

Infix2Postfix::~Infix2Postfix()
{
}

bool Infix2Postfix::isOperator(char currentChar)
{
	switch (currentChar) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '%':
		return true;
	default:
		return false;
	}
}

bool Infix2Postfix::precedence(char leftOperator, char rightOperator)
{
	if (leftOperator == '^') {
		return true;
	}
	else if (rightOperator == '^') {
		return false;
	}
	else if (leftOperator == '*' || leftOperator == '/' || leftOperator == '%') {
		return true;
	}
	else if (rightOperator == '*' || rightOperator == '/' || rightOperator == '%') {
		return false;
	}

	return true;
}

string Infix2Postfix::convertToPostfix()
{
	stack.push('('); // Push a left parenthesis ‘(‘ onto the stack.

	for (size_t i = 0, l = infix.size(); i < l; ++i) {

		const char current = infix[i];

		if (isspace(current)) {
			// ignore
		}
		// If it's a digit or '.' or a letter ("variables"), add it to the output
		else if (isalnum(current) || '.' == current) {
			postfix << current;
		}

		else if ('(' == current) {
			stack.push(current);
		}

		else if (isOperator(current)) {
			char rightOperator = current;
			while (!stack.empty() && isOperator(stack.top()) && precedence(stack.top(), rightOperator)) {
				postfix << ' ' << stack.top();
				stack.pop();
			}
			postfix << ' ';
			stack.push(rightOperator);
		}

		// We've hit a right parens
		else if (')' == current) {
			// While top of stack is not a left parens
			while (!stack.empty() && '(' != stack.top()) {
				postfix << ' ' << stack.top();
				stack.pop();
			}
			if (stack.empty()) {
				throw runtime_error("missing left paren");
			}
			// Discard the left paren
			stack.pop();
			//postfix << ' ';	// zakomentowane bo program wywala³o przy NumbSysInterpreter 
		}
		else {
			throw runtime_error("invalid input character");
		}
	}


	// Started with a left paren, now close it:
	// While top of stack is not a left paren
	while (!stack.empty() && '(' != stack.top()) {
		postfix << ' ' << stack.top();
		stack.pop();
	}
	if (stack.empty()) {
		throw runtime_error("missing left paren");
	}
	// Discard the left paren
	stack.pop();

	// all open parens should be closed now -> empty stack
	if (!stack.empty()) {
		throw runtime_error("missing right paren");
	}

	result = postfix.str();
	return postfix.str();
}

void Infix2Postfix::SetExpression(string SetExpression)
{
	infix = SetExpression;
}

string Infix2Postfix::GetExpression()
{
	return infix;
}

string Infix2Postfix::GetPostfixResult()
{
	return result;
}

string Infix2Postfix::runConverter()
{
	return convertToPostfix();
}


