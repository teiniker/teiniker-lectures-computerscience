# Greatest Common Divisor

The Greatest Common Divisor (GCD) of two integers is the largest positive 
integer that divides both numbers without leaving a remainder. 

_Example:_ The `gdc(48, 18)` is `6`.


## Euclidean Algorithm
The Euclidean Algorithm is a systematic method for finding the GCD of two 
integers based on the principle that **the GCD of two numbers also divides 
their difference**. It leverages the properties of divisibility and remainders 
to iteratively reduce the problem size until the GCD is found. 

The core idea is based on the following mathematical property:

> If `a` and `b` are two positive integers with `a > b`, then the GCD of 
> `a` and `b` is the same as the GCD of `b` and `a % b`.

Here, `%` denotes the **modulus operation**, which gives the remainder 
when a is divided by b.

Given the function declaration: `int gdc(int a, int b)`
* While the second number `b` is not zero:
    * Replace `a` with `b` and `b` with `a % b` (the remainder of a divided by `b`).
* When `b` becomes zero, `a` contains the GCD.

```C
int gcd(int a, int b)
{
    if(a == 0 && b == 0)
        return 0;

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int gcd;
    while(a % b)
    {
        gcd = a % b;
        a = b;
        b = gcd;
    }    
    return gcd;
}
```

Properties of the algorithm:

* Efficiency: The Euclidean algorithm is **highly efficient** and works well 
    even for large integers.

* Zero Handling: It's essential to handle cases where one or both inputs are 
    zero to avoid undefined behavior.


## Mathematical Foundation

The Euclidean Algorithm is grounded in fundamental properties of integers and 
divisibility:

* **Divisibility**: If `c` divides both `a` and `b`, it also divides `a - b`, 
    `a + b`, and any linear combination of `a` and `b`.

* **GCD Properties**:
    * **Commutative**: GCD(a, b) = GCD(b, a)
    * **Associative**: GCD(a, GCD(b, c)) = GCD(GCD(a, b), c)
    * **Distributive over LCM**: GCD(a, LCM(b, c)) = LCM(GCD(a, b), GCD(a, c))    


## Applications of the Euclidean Algorithm

* **Simplifying Fractions**: Reducing fractions to their simplest form by dividing 
    both numerator and denominator by their GCD.

* **Cryptography**: Essential in algorithms like RSA for key generation and 
    encryption/decryption processes.

* **Computer Algorithms**: Useful in algorithms that require handling ratios, 
    scheduling, and resource allocation.

## References

* [Wikipedia: Euclidean Algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)

* [Adding Rational Types to the C Programming Language](https://psychocod3r.wordpress.com/2020/08/07/adding-rational-types-to-the-c-programming-language/)

*Egon Teiniker, 2020-2024, GPL v3.0* 
