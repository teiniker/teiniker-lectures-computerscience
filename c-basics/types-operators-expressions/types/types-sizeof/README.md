# Type Sizes in C

Data types in c refer to an extensive system **used for declaring variables or functions** 
of different types. 
The type of a variable determines how much space it occupies in storage and how the bit 
pattern stored is interpreted.

To get the exact size of a type or a variable on a particular platform, you can use the sizeof operator. The expressions sizeof(type) yields the storage size of the object or type in bytes.


## Integer Types 

On a 64bit Linux machine we get the following values from **sizeof**:

```C
    printf("char : %u\n", sizeof(char)); 
    printf("short: %u\n", sizeof(short)); 
    printf("int  : %u\n", sizeof(int)); 
    printf("long : %u\n", sizeof(long)); 
    printf("long long: %u\n", sizeof(long long));
```

```
    char     : 1
    short    : 2
    int      : 4
    long     : 8
    long long: 8
```

We can also inspect the different constants defined in **limits.h** header file.

```C
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
```

```
    CHAR_BIT    :   8
    CHAR_MAX    :   127
    CHAR_MIN    :   -128
    INT_MAX     :   2147483647
    INT_MIN     :   -2147483648
    LONG_MAX    :   9223372036854775807
    LONG_MIN    :   -9223372036854775808
    SCHAR_MAX   :   127
    SCHAR_MIN   :   -128
    SHRT_MAX    :   32767
    SHRT_MIN    :   -32768
    UCHAR_MAX   :   255
    UINT_MAX    :   4294967295
    ULONG_MAX   :   18446744073709551615
    USHRT_MAX   :   65535
```

## Floating-Point Types

```C
    printf("float : %u\n", sizeof(float)); 
    printf("double: %u\n", sizeof(double)); 
    printf("long double: %u\n", sizeof(long double));
```

```
    float       : 4
    double      : 8
    long double : 16
```

Related constants for floating-point types are deifined in the **float.h** file.
```C
    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
    printf("LDBL_MIN     :  %g\n", (double) LDBL_MIN);
    printf("LDBL_MAX     :  %g\n", (double) LDBL_MAX);
```

```
    FLT_MAX     :   3.40282e+38
    FLT_MIN     :   1.17549e-38
    DBL_MAX     :   1.79769e+308
    DBL_MIN     :   2.22507e-308
    LDBL_MIN     :  0
    LDBL_MAX     :  inf
```


## References
* [C Data Types (Programiz)](https://www.programiz.com/c-programming/c-data-types)

* [C Data Types (Tutorialspoint)](https://www.tutorialspoint.com/cprogramming/c_data_types.htm)

*Egon Teiniker, 2020-2021, GPL v3.0*
