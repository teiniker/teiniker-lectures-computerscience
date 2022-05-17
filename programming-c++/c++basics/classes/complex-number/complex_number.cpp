#include "complex_number.h"

/*
 * Constructor
 */
ComplexNumber::ComplexNumber(double re, double im)
{
    _re = re;
    _im = im;
}

// Destructor
ComplexNumber::~ComplexNumber() 
{
}
    
double ComplexNumber::real()
{
    return _re;
}

void ComplexNumber::real(double re)
{
    _re = re;
}

double ComplexNumber::imag()
{
    return _im;
}

void ComplexNumber::imag(double im)
{
    _im = im;
}

void ComplexNumber::add(ComplexNumber c)
{
    _re += c.real();
    _im += c.imag();
}

void ComplexNumber::sub(ComplexNumber c)
{
    _re -= c.real();
    _im -= c.imag();
}

