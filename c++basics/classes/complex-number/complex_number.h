#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_

class ComplexNumber 
{
    private:
        double _re;
        double _im;
   
   public:
        ComplexNumber(double re, double im);
        ~ComplexNumber();
        
        double real();
        void real(double re);
        double imag();
        void imag(double im);
        void add(ComplexNumber c);
        void sub(ComplexNumber c);
};

#endif /* _COMPLEX_NUMBER_H_ */