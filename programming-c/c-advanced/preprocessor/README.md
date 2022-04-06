# Preprocessor

The preprocessor is a piece of software that **edits C programs just prior to compilation**. This makes C and also C++ unique among major programming languages.

The bahavior of the preprocessor is controlled by **preprocessing directives**:
commands that begin with a `#` character.

Most preprocessing directives fall into one of three categories:
* **Macro definition**: The `#define` directive defines a macro; the `#udef` directive removes a macro definition.

* **File inclusion**: The `#include` directive causes the contents of a specified file to be included in a program.

* **Conditional compilation**: The `#if`, `#ifdef`, `#ifndef`, `#elif`, `#else` 
and `#endif` directives allow blocks of text to be either included in or excluded from a program, depending on conditions that can be tested by the preprocessor.

The remaining directives `#error`, `#line`, and `#pragma` are more specialized and therefore used less often.

## Macro Definitions

```

```
## File Inclusion


## Conditional Compilation


## Miscellaneous Directives



## References

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
    * Chapter 14: The Preprocessor

*Egon Teiniker, 2020-2022, GPL v3.0* 
