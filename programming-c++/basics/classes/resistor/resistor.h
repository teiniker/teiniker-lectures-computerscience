#ifndef _RESISTOR_H_
#define _RESISTOR_H_

#include <cstdint>

class Resistor 
{   
    public:
        Resistor(uint32_t value, uint8_t tolerance = 1);
        
        // Accessor methods
        uint32_t value() const;
        uint8_t tolerance() const;

        // Methods 
        void serial(Resistor& r);
        void parallel(Resistor& r);

    private:
        uint32_t _value;
        uint8_t _tolerance;
        int _max(const uint8_t t1, const uint8_t t2);
};

#endif 