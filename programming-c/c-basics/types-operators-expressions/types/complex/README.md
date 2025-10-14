# Complex Numbers 

Complex numbers are an extension of the real numbers and provide solutions to certain 
equations that have no solutions in the real numbers. 

## Complex Numbers in C 

Using the following include file:

```C 
#include <complex.h>
```

Three standard complex types (aliases for _Complex) are available:

```C 
float complex        // aka float _Complex
double complex       // aka double _Complex
long double complex  // aka long double _Complex
```

Note that **there are no complex literals**.

We build values from real/imag parts with `I` (the imaginary unit) or with constructor-like macros:

* `I` is a macro from `<complex.h>` that expands to the imaginary unit 
    (type participates in the usual arithmetic conversions so the resulting 
    type matches the expression).

* The `CMPLX*` macros avoid surprises with promotions and signed zeros, thus, prefer them 
    when constructing from variables.

_Example:_ Create complex numbers 

```C 
double complex z1 = 3.0 + 4.0*I;         // common idiom
double complex z2 = CMPLX(3.0, 4.0);     // safer constructor macro
float  complex z3 = CMPLXF(3.0f, 4.0f);
long double complex z4 = CMPLXL(3.0L, 4.0L)
```

Arithmetic on complex values uses the normal **operators**:

* Unary operators:
    - `+z1` 
    - `-z1`  

* Binary operators:
    - `z1 + z2`
    - `z1 - z2`
    - `z1 * z2`
    - `z1 / z2`

* Assignments, compound assignments (`+=`, `*=`) work.

* Casts operators also work as usual.

* Equality/inequality (`==`, `!=`) are defined (both parts equal).

* Ordering comparisons (`<`, `>`, …) are **not defined**.

There are also some accessor functions defined in <complex.h>:

* `double creal(double complex z)`: This function computes the real part of a complex number.

* `double cimag(double complex z)`: This function computes the imaginary part of the complex number.

* `double cabs(double complex)`: This function calculate the magnitude of a complex number.

* `double carg(double complex)`: This function calculate the phase angle of a complex number.

* `double complex conj(double complex)`: This function calculate the complex conjugate.


## Memory Layout 

Each complex type is represented as **two adjacent real components** 
of the corresponding real type: **real first**, **imaginary second**
It has the same alignment as an array of two such reals. 
So in practice it behaves as if it were `T[2]`.

Although this means we can reinterpret as an array of two reals, the portable, 
intention-revealing way to access parts is via the accessor functions/macros 
below.


## References

* [C Library - <complex.h> (Tutorialspoint)](https://www.tutorialspoint.com/c_standard_library/c_library_complex_h.htm)

*Egon Teiniker, 2020-2025, GPL v3.0* 
