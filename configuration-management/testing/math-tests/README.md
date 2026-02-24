# Testing math.h Functions

Test cases in this example demonstrate how to use several `math.h` functions. 
They illustrate typical inputs, expected outputs, and precision-aware assertions 
for floating-point results.


## Implementation Details

To run these tests successfully, the `Makefile` needs a few extra settings. 
In particular, the math library must be linked and Unity must be configured 
to allow double-precision checks. 

Because floating-point values are not exact, use the dedicated Unity assert 
macros for approximate equality instead of integer assertions.

### Linking: libm.a

The math functions (`sqrt`, `sin`, `cos`, `tan`, `pow`, `exp`, `log`) live 
in the math library. 

Link it by adding `-lm` to the final link command (as done in `Makefile` 
via `LIBS=-lm`). This ensures the linker can resolve math symbols.


### Enabling Double Precision in Unity

Unity disables double-precision assertions by default. Enable them by defining `UNITY_INCLUDE_DOUBLE` during compilation. The `Makefile` adds this flag via `CFLAGS=-DUNITY_INCLUDE_DOUBLE`.

### Assert Macros Used

The tests use Unity’s double-precision assertions:

- `TEST_ASSERT_DOUBLE_WITHIN(delta, expected, actual)` for approximate equality.

*Egon Teiniker, 2020-2026, GPL v3.0* 