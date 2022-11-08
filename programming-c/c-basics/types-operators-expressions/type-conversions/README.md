# Type Conversion

Computers tend to be more restrictive than C when it comes to arithmetic.
For a computer to perform an arithmetic operation, the operands must usually be of the same size (same number of bits) and be stored in the same way.

**C allows the basic types to be mixed in expressions**.
We can combine integers, floating-point numbers, and even characters in a single expression.
The C compiler may then have to generate instructions that convert some operands to different types so that the hardware will be able to eveluate the expression.

Because the compiler handles these conversions automatically, without the programmer's involvement, they are known as **implicit conversions**.
C also allows the programmer to perform **explicit conversions**, using the **cast operator**.


## Usual Arithmetic Conversions

The strategy behind the usual arithmetic conversions is to convert operands to the _narrowest_ type that will safely accommodate both values.

The types of the operands can often be made match by converting the operand of the narrower type to the type of the other operand (known as **promotion**).

We can divide the rules for performing the usual arithmetic conversions into two cases:

* **The type of either operand is integer**:
    Use the following diagram to promote the operand whose type is narrower:
    ```
    int -> unsigned int -> long int -> unsigned long int
    ```

* **The type of one operand is a floating-point type**: 
    ```
    float -> double -> long double
    ```
    If one operand has a floating-point type, then convert the other operand also to a floating-point type. 

    Note that these rules cover mixtures of integer and floating types: **if one operand has an integer type and
    the other hast a floating point type, the integer operand is converted into the floating-point**.

_Example: Type conversions
```C
char c;
short int s;
int i;
unsigned int u;
long int l;
unsigned long int ul;

i = i + c;      // c -> int
i = i + s;      // s -> int
u = u + i;      // i -> unsigned int 
l = l + u;      // u -> long int
ul = ul + l;    // l -> unsigned long int

float f;
double d;
long double ld;

f = f + ul;     // ul -> float !!
d = d + f;      // f  -> double
ld = ld + d;    // d  -> long double  
```

## Casting 

Sometimes, we need a greater degree of control over type conversion.
For this reason, C provides **cast expressions**:
```
    (type-name) expression
```
where **type-name** specifies the type to which the expression should be converted.

_Example: Convert a floating-point into an integer type
```C
    float f;
    int i;

    i = (int)f; // f -> int    
```
The cast expression `(int)f` represents the result if converting the value of `f` to type `int`. 
The difference between `f` and `(int)f` is the fractional part of `f`, which was dropped during the cast.

Cast expressions enable us to **document type conversions** that would take place anyway.

They also enable us to overrule the compiler and force it to do conversations that we want.

_Example: 
```C
    double quotient;
    int dividend, divisor;

    quotient = (double) divergend / divisor;
```
Unary operators have higher precedence than binary operators, so the compiler interprets: 
```C
    (double) divident / divisor;
```
as
```C
    ((double) divident) / divisor    
```

## Rounding


* **double ceil( double arg )**\
    The `ceil()` function computes the nearest integer greater than the argument passed.
  
    _Example_: If `2.3` is passed to `ceil()`, it will return `3`.

* **double floor(double arg)**\
    The `floor()` function calculates the nearest integer less than the argument passed.
    
    _Example_: If `2.3` is passed to `floor()`, it will return `2`.
    
* **double round (double y)**\
    The `round()` function provides the integer value that is nearest to the double argument 
    passed to it. 
    
    If the decimal number is between `1` and `.5`, it gives an integer number less than the 
    argument. If the decimal number is between `.6` and `.9`, it gives an integer number 
    greater than the parameter.
    
* **double trunc(double arg)**\
    The `trunc()` function allows to remove the decimal value from a floating number 
    and return an inetger value.
    
    _Example_: If `2.3` is passed to `trunc()`, it will return 2.
    
    
## References
* K. N. King. **C Programming, A Modern Approach**. W. W. Norton & Company, inc. 2nd Edition 2008
    * Chapter 7: Basic Types 
    

*Egon Teiniker, 2020-2022, GPL v3.0* 
