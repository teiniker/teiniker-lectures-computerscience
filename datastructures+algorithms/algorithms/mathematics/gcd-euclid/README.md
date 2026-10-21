# Greatest Common Divisor (GCD)

> The Greatest Common Divisor (GCD) is largest positive integer that divides 
> two integers without leaving a remainder.

Here we use the iterative Euclidean Algorithm.


## Step-by-Step Breakdown

1. **Handling Negatives:**
```c
a = abs(a);
b = abs(b);

```

The mathematical definition of GCD is always non-negative (e.g., $\gcd(-12, 18) = 6$). 
Calling `abs()` guarantees both values are non-negative before running 
the division steps.

2. **The Loop Condition (`while (b != 0)`):**
The Euclidean algorithm is based on the principle that:

$$\gcd(a, b) = \gcd(b, a \pmod b)$$

The loop continues replacing $(a, b)$ with $(b, a \pmod b)$ until the 
remainder $b$ becomes $0$.

3. **Updating Variables:**
```c
int tmp = b;
b = a % b;
a = tmp;

```

* `tmp` stores the current value of `b`.
* `b` is assigned the remainder of `a` divided by `b` (`a % b`).
* `a` receives the old value of `b` stored in `tmp`.


4. **Return Value:**
```c
return a;

```

When `b` reaches $0$, `a` holds the last non-zero remainder, which is the GCD.


## Key Properties

* **Order Agnostic:** Even if $a < b$ initially (e.g., `gcd(18, 48)`), 
    the very first iteration swaps them because $18 \pmod{48} = 18$, 
    yielding $a = 48, b = 18$ for the next cycle.

* **Time Complexity:** $O(\log(\min(a, b)))$, making it extremely 
    fast even for 64-bit numbers.

* **Space Complexity:** $O(1)$ auxiliary memory since it runs iteratively 
    without recursion stack overhead.

* **Edge Case (`INT_MIN`):** In standard two's-complement C/C++, 
    `abs(INT_MIN)` causes integer overflow/undefined behavior 
    because $-(-2^{31}) = 2^{31}$ cannot fit into a signed 32-bit `int`.

## References

* [YouTube (Numberphile): Euclid's Algorithm ](https://youtu.be/6Y3jHHE_hbA?si=UOm8tTei4oVTY85l)

*Egon Teiniker, 2020-2026, GPL v3.0* 