#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_

class ComplexNumber 
{
    private:
        double _re;
        double _im;
   
    public:
        ComplexNumber(double re, double im);    // Constructor
        ~ComplexNumber();                       // Destructor
        
        // Accessor methods
        double real();
        void real(double re);
        double imag();
        void imag(double im);

        // Methods 
        void add(ComplexNumber c);
        void sub(ComplexNumber c);
};

#endif 