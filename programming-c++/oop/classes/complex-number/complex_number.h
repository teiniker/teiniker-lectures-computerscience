#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_

class ComplexNumber 
{
    public:
        ComplexNumber(double re, double im);    // Constructor
        ~ComplexNumber();                       // Destructor
        
        // Accessor methods
        double real() const;
        void real(const double re);
        double imag() const;
        void imag(const double im);

        // Methods 
        void add(const ComplexNumber& c);
        void sub(const ComplexNumber& c);

    private:
        double _re;
        double _im;   
};

#endif 