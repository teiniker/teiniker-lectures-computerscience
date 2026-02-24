# Compiler Explorer

Compiler Explorer is a very good tool to study the effects of compiler 
flags on the generated assembly code (in real time).

Given a simple C program: 

```C
#include<stdio.h>

double mul(double a, double b)
{
    return a*b;
}

int main(void)
{
    double result;
    result = mul(3.1415, 2.7173);
    
}
```

Now, we generate the assembly code with two different optimization flags:

_Example:_ x86-64 optimizer flag **-O0**

```asm
mul(double, double):
        push    rbp
        mov     rbp, rsp
        movsd   QWORD PTR [rbp-8], xmm0
        movsd   QWORD PTR [rbp-16], xmm1
        movsd   xmm0, QWORD PTR [rbp-8]
        mulsd   xmm0, QWORD PTR [rbp-16]
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        movsd   xmm0, QWORD PTR .LC0[rip]
        mov     rax, QWORD PTR .LC1[rip]
        movapd  xmm1, xmm0
        movq    xmm0, rax
        call    mul(double, double)
        movq    rax, xmm0
        mov     QWORD PTR [rbp-8], rax
        mov     eax, 0
        leave
        ret
.LC0:
        .long   -934584884
        .long   1074117895
.LC1:
        .long   -1065151889
        .long   1074340298
```


_Example:_ x86-64 optimizer flag -O2

```asm
mul(double, double):
        mulsd   xmm0, xmm1
        ret
main:
        xor     eax, eax
        ret
```

The compiler can significantly simplify the generated assembly, so 
the **optimization flag -O2** should be used when building 
a **software release**.

During **development**, and especially for debugging, **no optimization** 
should be enabled. Use the `-g` flag to add additional **debug information** 
to the executable.


## References

* [Compiler Explorer](https://godbolt.org/)

*Egon Teiniker, 2020-2026, GPL v3.0* 