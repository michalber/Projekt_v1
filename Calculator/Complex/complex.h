/*

*/

#pragma once


#include <iostream>
#include <cmath>

#define PI acos(-1)

// define Complex class
//=========================================================================
class Complex {
private:
	double real, imag;
public:
	Complex(void);			// default constructor
	Complex(double r);
	Complex(double r, double i);

	double re(void);
	friend double re(Complex z);
	double im(void);
	friend double im(Complex z);

	Complex conj(void);
	friend Complex conj(Complex z);
	double abs(void);
	friend double abs(Complex z);
	double arg(void);
	friend double arg(Complex z);
	double norm(void);
	friend double norm(Complex z);


	// operatory podstawowe

	Complex operator+(Complex z);
	Complex operator+(double a);
	friend Complex operator+(double a, Complex z);

	Complex operator-(Complex a);
	Complex operator-(double a);
	friend Complex operator-(double a, Complex z);
	friend Complex operator-(Complex z);

	Complex operator*(Complex z);
	Complex operator*(double a);
	friend Complex operator*(double a, Complex z);

	Complex operator/(Complex a);
	Complex operator/(double a);
	friend Complex operator/(double a, Complex z);

	// incr, dec, etc.
	const Complex& operator+=(const Complex& z);
	const Complex& operator-=(const Complex& z);
	int operator==(Complex z);

	// operatory math

	friend Complex sqrt(Complex z);
	friend Complex log(Complex z);
	friend Complex exp(Complex z);
	friend Complex pow(Complex z, double c);

	friend Complex sin(Complex z);
	friend Complex cos(Complex z);
	friend Complex tan(Complex z);
	

	friend Complex asin(Complex z);
	friend Complex acos(Complex z);
	friend Complex atan(Complex z);
	
	// stream operator 

	friend std::ostream& operator<<(std::ostream& stream, Complex z);

	Complex rnd(int precision);
	friend Complex rnd(Complex z, int precision);

};
