# Stronger Type Checking in C++ 

 C++ enforces stricter type checking compared to C, which helps to 
 **catch more errors at compile time**.

 C++ will reject at compile-time questionable operations that C will accept.

 _Example:_ In C, assigning an `int*` to a `void*` pointer does not require 
    an explicit cast, but in C++, this requires an explicit cast:
```C++
// C (allowed):
int* ptr = malloc(sizeof(int));       // Implicit void* to int* conversion is fine.

// C++ (error without cast):
int* ptr = malloc(sizeof(int));       // Error: invalid conversion from void* to int*.
int* ptr = (int*)malloc(sizeof(int)); // OK: explicit conversion from void* to int*.
```



