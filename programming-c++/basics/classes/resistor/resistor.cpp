#include "resistor.h"

/*
 * Constructor
 */
Resistor::Resistor(uint32_t value, uint8_t tolerance) : _value(value), _tolerance(tolerance)
{
}

uint32_t Resistor::value() const
{
    return _value;
}

uint8_t Resistor::tolerance() const
{
    return _tolerance;
}
    
void Resistor::serial(Resistor& r)
{
    _value = _value + r.value();
    _tolerance =  _max(_tolerance, r.tolerance());
}

void Resistor::parallel(Resistor& r)
{
    _value = _value * r.value() / (_value + r.value());
    _tolerance =  _max(_tolerance, r.tolerance());
}

int Resistor::_max(const uint8_t t1, const uint8_t t2)
{
    return (t1 > t2)? t1: t2;
}
