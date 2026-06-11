#include "complex_number.h"

//Constructor
ComplexNumber::ComplexNumber(double re, double im) : _re(re), _im(im)
{
}

// Destructor
ComplexNumber::~ComplexNumber() 
{
}
    
double ComplexNumber::real() const  
{
    return _re;
}

void ComplexNumber::real(const double re)
{
    _re = re;
}

double ComplexNumber::imag() const 
{
    return _im;
}

void ComplexNumber::imag(const double im)
{
    _im = im;
}

void ComplexNumber::add(const ComplexNumber& c)
{
    _re += c.real();
    _im += c.imag();
}

void ComplexNumber::sub(const ComplexNumber& c)
{
    _re -= c.real();
    _im -= c.imag();
}
