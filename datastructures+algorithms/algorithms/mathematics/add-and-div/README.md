# Multiplication and Division 

If the operations multiplication and division cannot be performed 
in the CPU as machine instructions, then these operations must be 
reduced to addition, subtraction and shift operations.

## Multiplication (Shift-and-Add)

The **Shift-and-Add algorithm** multiplies two numbers by iteratively 
adding shifted versions of one number (the multiplicand) based on 
the bits of the other number (the multiplier). 

* **Initialize Variables**:
    * **Multiplicand** `a`: The first number to be multiplied.
    * **Multiplier** `b`: The second number to be multiplied.
    * **Result** `result`: Initialize to `0`. This will accumulate 
        the final product.
    * **Bit Position** `i`: Starts at `0` (LSB).

* **Iterate Over Each Bit of the Multiplier**:
    * **Check Bit**: For each bit in the multiplier `b`, starting 
        from the least significant bit (LSB) to the most significant 
        bit (MSB):
        * If the current bit is `1`, add the multiplicand shifted left 
            by the current bit position to the result.
        * If the current bit is `0`, do nothing.

    * **Shift Multiplicand**: Left shift the multiplicand by `1` 
        (equivalent to multiplying by `2`) for the next bit position.

    * **Move to Next Bit**: Right shift the multiplier by `1` to 
        process the next bit.

* **Termination**: The process continues until all bits of the multiplier 
    have been processed (i.e., the multiplier becomes `0`).

While the Shift-and-Add method is straightforward, it has a **time complexity** of **O(n)**, where n is the number of bits in the multiplier. 

For large bit-widths, more efficient algorithms like **Karatsuba**, **Booth's Algorithm**, or hardware-specific techniques like **Wallace Trees** can be employed to reduce computation time.


## Division (Binary Long Division)

The **Binary Long Division algorithm** closely resembles the traditional long 
division method taught in elementary arithmetic but operates in binary 
(base-2) instead of decimal (base-10). 

The goal is to determine how many times the divisor can be subtracted from 
the dividend without making the remainder negative.

* **Initialize Variables**:
    * Dividend `a`: The number to be divided.
    * Divisor `b`: The number by which to divide.
    * Quotient `quotient`: Initialize to 0. This will store the result of the 
        division.
    * Remainder `remainder`: Initialize to 0. This will store the remaining 
        value after division.

* **Determine the Highest Bit Position**:
    Find the highest bit position in the dividend that is set `1`. This helps 
    in aligning the divisor appropriately.

* **Iterate from Highest Bit to Lowest**:
    For each bit position from the highest to the lowest:
    * **Shift Left**: Shift the `remainder` left by `1` bit and bring down 
        the corresponding bit from the `dividend`.
    * **Compare and Subtract**:
        * If the `remainder` is greater than or equal to the `divisor`, 
            subtract the `divisor` from the `remainder` and set the 
            corresponding bit in the `quotient` to `1`.
        * If not, leave the corresponding bit in the `quotient` as `0`.

* **Finalize**:
    After processing all bits, the `quotient` holds the result of the division, 
    and the `remainder` holds the leftover value.

The Binary Long Division algorithm is straightforward, it has a **time complexity** of **O(n)**, where n is the number of bits in the divisor.     
Minimal extra space is used, making it efficient in terms of memory.

CPUs use optimized versions of the Binary Long Division method, often incorporating 
parallelism, pipelining, and other optimizations to achieve high-speed division.

Alternative algorithms are:
* **Non-Restoring Division**: An alternative to the restoring division that 
    avoids restoring the remainder after each subtraction, potentially 
    improving performance.
* **SRT Division (Sweeney-Robertson-Tocher)**: Handles multiple bits per step, 
    enhancing speed but increasing complexity.
* **Newton-Raphson Division**: An iterative method primarily used for floating-point 
    division in high-performance scenarios.

Implementing division using only shifting and subtracting operations provides 
a clear understanding of how arithmetic operations are performed at a low level, 
both in software and hardware. The Binary Long Division algorithm is simple yet 
effective for educational purposes and certain application scenarios. However, 
for performance-critical applications, more advanced division algorithms and 
hardware optimizations are typically employed.


## References

* M. Morris Mano. **Digital Logic And Computer Design Taschenbuch**. Pearson, 2016
* Randall Hyde. **Writing Great Code / Volume 1: Understanding the Machine**. No Starch Press, 2020


*Egon Teiniker, 2020, GPL v3.0* 