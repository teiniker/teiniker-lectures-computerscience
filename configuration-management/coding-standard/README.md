# C Coding Standard

As Robert C. Martin says, **every team should follow a coding standard based on common industry norms**, therefore, we also use one... 

The following rules are extracted from the [Embedded C Coding Standard](https://barrgroup.com/embedded-systems/books/embedded-c-coding-standard) 
defined by the **Barr Group** which is available online and as a PDF document. But keep in mind, that every organization or even every team can have 
its own flavor of a coding standard.

## General Rules

* **Line Widths**
    * _Rule_: The width of all lines in a program shall be limited to a maximum of 80 characters.

    * _Reasoning_: From time-to-time, peer reviews and other code examinations are conducted on printed pages. 
    To be useful, such print-outs must be free of distracting line wraps as well as missing (i.e., past the right margin) characters.    

* **Braces**
    * _Rule_: Braces shall always surround the blocks of code, following `if`, `else`, `switch`, `while`, `do`, and `for` statements; single statements and empty statements following these keywords shall also always be surrounded by braces.
    
    * _Rule_: Each left brace `{` shall appear by itself on the line below the start of the block it opens. 
    The corresponding right brace `}` shall appear by itself in the same position the appropriate number of lines later in the file.

    * _Reasoning_: There is considerable risk associated with the presence of empty statements and single statements that are not surrounded by braces. Code constructs like this are often associated with bugs when nearby code is changed or commented out. This risk is entirely eliminated by the consistent use of braces.\ 
    The placement of the left brace on the following line allows for easy visual checking for the corresponding right brace.

* **Parentheses**
    * _Rule_: Do not rely on C’s operator precedence rules, as they may not be obvious to those who maintain the code. 
    To aid clarity, use parentheses to ensure proper execution order within a sequence of operations.    

    * _Rule_: Unless it is a single identifier or constant, each operand of the logical AND `&&` and logical OR `||` operators shall be surrounded by parentheses.

    * _Reasoning_: The syntax of the C programming language has many operators. The precedence rules that dictate which operators are evaluated before which others are complicated—with over a dozen priority levels—and not always obvious to all programmers. When in doubt it’s better to be explicit about what you hope the compiler will do with your calculations.

* **Casts**
    * _Rule_: Each cast shall feature an associated comment describing how the code ensures proper behavior across the range 
    of possible values on the right side.

    * _Reasoning_: Casting is dangerous. 


## White Space Rules

* **Spaces**

    * _Rule_: Each of the keywords `if`, `while`, `for`, `switch`, and `return` shall be followed by one space when there is additional program text on the same line.

    * _Rule_: Each of the assignment operators `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `~=`, and `!=` shall always be preceded and followed by one space.

    * _Rule_: Each of the binary operators `+`, `-`, `*`, `/`, `%`, `<`, `<=`, `>`, `>=`, `==`, `!=`, `<<`, `>>`, `&`, `|`, `^`, `&&`, and `||` shall always be preceded and followed by one space.

    * _Rule_: Each of the unary operators `+`, `-`, `++`, `--`, `!` , and `~`, shall be written **without a space** on the operand side.

    * _Rule_: The pointer operators `*` and `&` shall be written with white space on each side within declarations but otherwise without a space on the operand side.

    * _Rule_: The `?` and `:` characters that comprise the ternary operator shall each always be preceded and followed by one space.

    * _Rule_: The structure pointer and structure member operators (`->` and `.`, respectively) shall always be **without surrounding spaces**.

    * _Rule_: The left and right brackets of the array subscript operator `[` and `]` shall be **without surrounding spaces**.

    * _Rule_: Expressions within parentheses shall always have no spaces adjacent to the left and right parenthesis characters.

    * _Rule_: The left and right parentheses of the function call operator shall always be without surrounding spaces.

    * _Rule_: Except when at the end of a line, each comma separating function parameters shall always be followed by one space.

    * _Rule_: Each semicolon separating the elements of a statement shall always be followed by one space.

    * _Rule_: Each semicolon shall follow the statement it terminates without a preceding space.

    * _Reasoning_: In source code, the placement of white space is as important as the placement of text. 
    Good use of white space reduces eyestrain and increases the ability of programmers and reviewers of the code to spot potential bugs.


* **Alignment**

    * _Rule_: The names of variables within a series of declarations shall have their first characters aligned.

    * _Rule_: The names of struct and union members shall have their first characters aligned.

    * _Rule_: The assignment operators within a block of adjacent assignment statements shall be aligned.

    * _Rule_: The `#` in a preprocessor directive shall always be located at the start of a line, though the directives themselves may be indented within a #if or #ifdef sequence.

    * _Reasoning_: Visual alignment emphasizes similarity. 
    A series of consecutive lines each containing a variable declaration is easily seen and understood as a block of related lines of code. Blank lines and differing alignments should be used as appropriate to visually separate and distinguish unrelated blocks of code that happen to be located in proximity.


* **Blank Lines**
    * _Rule_: No line of code shall contain more than one statement.

    * _Rule_: There shall be a blank line before and after each natural block of code. 
    Examples of natural blocks of code are loops, `if…else` and `switch` statements, and consecutive declarations.

    * _Rule_: Each source file shall terminate with a comment marking the end of file followed by a blank line.

    * _Reasoning_: Appropriate placement of white space provides visual separation and thus makes code easier to read and understand, just as the white space areas between paragraphs of this coding standard aid readability. Clearly marking the end of a file is important for human reviewers looking at printouts and the blank line following may be required by some older compilers.


* **Indentation**
    * _Rule_: Each indentation level should align at a multiple of 4 characters from the start of the line.

    * _Rule_: Within a `switch` statement, the case labels shall be aligned; the contents of each case block shall be indented once from there.

    * _Rule_: Whenever a line of code is too long to fit within the maximum line width, indent the second and any subsequent lines in the most readable manner possible.

    * _Reasoning_: Fewer indentation spaces increase the risk of visual confusion while more spaces increases the likelihood of line wraps.


* **Tabs**

    * _Rule_: The tab character (ASCII `0x09`) shall never appear within any source code file.

    * _Reasoning_: The width of the tab character varies by text editor and programmer preference, making consistent visual layout a continual source of headaches during code reviews and maintenance.


* **Non-Printing Characters**

    * _Rule_: Whenever possible, all source code lines shall end only with the single character ‘LF’ (ASCII `0x0A`), 
    not with the pair ‘CR’-‘LF’ (`0x0D 0x0A`).

    * _Reasoning_: The multi-character sequence ‘CR’-‘LF’ is more likely to cause problems in a multi-platform development environment than the single character ‘LF’. One such problem is associated with multi-line preprocessor macros on Unix platforms.


## Data Type Rules

* **Booleans**
    * _Rule_: Boolean variables shall be declared as type `bool`.

    * _Rule_: Non-Boolean values shall be converted to Boolean via use of relational operators (e.g., `<` or `!=`), not via casts.

    * _Reasoning_: The C99 language standard introduced a new data type for Boolean variables along with new constants `true` and `false` in the `<stdbool.h>` header file.

* **Fixed-Width Integers**
    * _Rule_: Whenever the width, in bits or bytes, of an integer value matters in the program, one of the **fixed width data types** (`int8_t`, `int16_t`, `int32_t`, `int64_t`, `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`) shall be used in place 
    of `char`, `short`, `int`, `long`, or `long long`. 

    * _Rule_: The keywords `short` and `long` shall not be used.    

    * _Rule_: Use of the keyword `char` shall be restricted to the declaration of and operations concerning strings.

    * _Reasoning_: The C99 standard did introduce the type names shown in the table, which are defined in the `stdint.h` header file.

* **Floating Point**
    * _Rule_: Avoid the use of floating point constants and variables whenever possible.

    * _Rule_: Use the C99 type names `float32_t`, `float64_t`, and `float128_t`.

    * _Rule_: Append an `f` to all single-precision constants (e.g., `pi = 3.141592f`).

    * _Rule_: Ensure that the compiler supports double precision, if your math depends on it.

    * _Rule_: Never test for equality or inequality of floating point values.    

    * _Rule_: Always invoke the `isfinite()` macro to check that prior calculations have resulted in neither `INFINITY` nor `NAN`.

    * Reasoning: A large number of risks of defects stem from incorrect use of floating point arithmetic.
    By default, C promotes all floating-point constants to double precision, which may be inefficient or unsupported on the target platform. However, many microcontrollers do not have any hardware support for floatingpoint math. The compiler may not warn of these incompatibilities, instead performing the requested numerical operations by linking in a large (typically a few kilobytes of code) and slow (numerous instruction cycles per operation) floating- point emulation library.

* **Naming Conventions**
    * _Rule_: The names of all new data types, including structures, unions, and enumerations, shall consist only of lowercase characters and internal underscores and end with `_t`.

    * _Rule_: All new structures, unions, and enumerations shall be named via a typedef.

    * _Reasoning_: Data type names and variable names are often appropriately similar.



* **Naming Conventions**
No variable shall have a name that is a keyword of C, C++, or any other well-known extension of the C programming language, including specifically K&R C and C99. Restricted names include `interrupt`, `inline`, `restrict`, `class`, `true`, `false`, `public`, `private`, `friend`, and `protected`.

    * _Rule_: No variable shall have a name that overlaps with a variable name from the C Standard Library (e.g., `errno`).

    * _Rule_: No variable shall have a name that begins with an underscore.

    * _Rule_: No variable name shall be longer than 31 characters.

    * _Rule_: No variable name shall contain any uppercase letters.  

    * _Rule_: Underscores shall be used to separate words in variable names.

    * _Rule_: Each variable’s name shall be descriptive of its purpose.

    * _Reasoning_: The base rules are adopted to maximize code portability across compilers. Many C compilers recognize differences only in the first 31 characters in a variable’s name and reserve names beginning with an underscore for internal names.
    The other rules are meant to highlight risks and ensure consistent proper use of variables. 

* **Initialization**

    * _Rule_: All variables shall be initialized before use.

    * _Rule_: Any pointer variable lacking an initial address shall be initialized to `NULL`.

    * _Rule_: It is preferable to define local variables as you need them, rather than all at the top of a function.

    * _Rule_: If project- or file-global variables are used, their definitions shall be grouped together and placed at the top of a source code file.

    * _Reasoning_: Too many programmers assume the C run-time will watch out for them, e.g., by zeroing the value of uninitialized variables on system startup. This is a bad assumption, which can prove dangerous in a mission-critical system. For readability reasons it is better to declare local variables as close as possible to their first use, which C99 makes possible by incorporating that earlier feature of C++.


## Statement Rules 

* **Variable Declarations**
    * _Rule_: The comma operator `,` shall not be used within variable declarations.

    * _Reasoning_: The cost of placing each declaration on a line of its own is low. 
    By contrast, the risk that either the compiler or a maintainer will misunderstand your intentions is high.


* **Conditional Statement**
    * _Rule_: It is a preferred practice that the shortest (measured in lines of code) of the `if` and `else if` clauses should be placed first.

    * _Rule_: Nested `if…else` statements shall not be deeper than two levels. 
    Use function calls or `switch` statements to reduce complexity and aid understanding.

    * _Rule_:  Assignments shall not be made within an `if` or `else if` test.    

    * _Rule_:  Any `if` statement with an `else if` clause shall end with an `else` clause.

    * _Reasoning_: Long clauses can distract the human eye from the decision-path logic. By putting the shorter clause earlier, the decision path becomes easier to follow. (And easier to follow is always good for reducing bugs.) Deeply nested `if…else` statements are a sure sign of a complex and fragile state machine implementation; there is always a safer and more readable way to do the same thing.


* **Switch Statement**

    * _Rule_: The `break` for each case shall be indented to align with the associated `case`, rather than with the contents of the case code block.

    * _Rule_: All `switch` statements shall contain a `default` block.

    * _Rule_: Any `case` designed to fall through to the next shall be commented to clearly explain the absence of the corresponding `break`.

    * _Reasoning_: C’s `switch` statements are powerful constructs, but prone to errors such as omitted `break` statements and unhandled cases. By aligning the case labels with their `break` statements it is easier to spot a missing `break`.


* **Loops**
    * _Rule_: Magic numbers shall not be used as the initial value or in the endpoint test of a `while`, `do…while`, or `for` 
    loop.

    * _Rule_: With the exception of the initialization of a loop counter in the first clause of a for statement and the change to the same variable in the third, no assignment shall be made in any loop’s controlling expression.

    * _Reasoning_: It is always important to synchronize the number of loop iterations to the size of the underlying data structure. Doing this via a descriptively-named constant prevents defects that result when changes in one part of the code, such as the dimension of an array, are not matched in other areas of the code.


* **Jumps**
    * _Rule_: The `goto` statements shall not be used.

    * _Rule_: C Standard Library functions `abort()`, `exit()`, `setjmp()`, and `longjmp()` shall not be used.

    * _Reasoning_: Algorithms that utilize `jumps` to move the instruction pointer can and should be rewritten in a manner that is more readable and thus easier to maintain.


* **Equivalence Tests**

    * _Rule_: When evaluating the equality of a variable against a constant, the constant shall always be placed to the left of the equal-to operator `==`.

    * _Reasoning_: It is always desirable to detect possible typos and as many other coding defects as possible at compile-time. Defect discovery in later phases is not guaranteed and often also more costly. By following this rule, any compiler will reliably detect erroneous attempts to assign (i.e., `=` instead of `==`) a new value to a constant.


## Procedure Rules

* **Naming Conventions**
    * _Rule_: No procedure shall have a name that is a keyword of any standard version of the C or C++ programming language. Restricted names include `interrupt`, `inline`, `class`, `true`, `false`, `public`, `private`, `friend`, `protected`, and many others.

    * _Rule_: No procedure shall have a name that overlaps a function in the C Standard Library. Examples of such names include `strlen`, `atoi`, and `memset`.

    * _Rule_: No procedure shall have a name that begins with an underscore.

    * _Rule_: No procedure name shall be longer than 31 characters.

    * _Rule_: No function name shall contain any uppercase letters.

    * _Rule_: No macro name shall contain any lowercase letters.

    * _Rule_: Underscores shall be used to separate words in procedure names.

    * _Rule_: Each procedure’s name shall be descriptive of its purpose. Note that procedures encapsulate the “actions” of a program and thus benefit from the use of verbs in their names (e.g., `adc_read()`); this “noun-verb” word ordering is recommended. Alternatively, procedures may be named according to the question they answer (e.g., `led_is_on()`).

    * _Rule_: The names of all public functions shall be prefixed with their module name and an underscore (e.g., `sensor_read()`).

    * _Reasoning_: Good function names make reviewing and maintaining code easier (and thus cheaper). The data (variables) in programs are nouns. Functions manipulate data and are thus verbs. The use of module prefixes is in keeping with the important goal of encapsulation and helps avoid procedure name overlaps.

* **Functions**

    * _Rule_: All reasonable effort shall be taken to keep the length of each function limited to one printed page, or a maximum of 100 lines.

    * _Rule_: It is a preferred practice that all functions shall have just one exit point and it shall be via a return at the bottom of the function.

    * _Rule_: Each parameter shall be explicitly declared and meaningfully named.

    * _Rule_: A prototype shall be declared for each public function in the module header file.

    * _Rule_: All private functions shall be declared static.

    * _Reasoning_: Code reviews take place at the function level and often on paper. Each function should thus ideally be visible on a single printed page, so that flipping papers back and forth does not distract the reviewers.
    Multiple return statements should be used only when it improves the readability of the code.


## Module Rules

* **Naming Conventions**

    * _Rule_: All module names shall consist entirely of lowercase letters, numbers, and underscores. 
        No spaces shall appear within the module’s header and source file names.

    * _Rule_: All module names shall be unique in their first 8 characters and end with suffices `.h` and `.c` for the 
        header and source file names, respectively.

    * _Rule_: No module’s header file name shall share the name of a header file from the C Standard Library 
        or C++ Standard Library. For example, modules shall not be named `stdio` or `math`.

    * _Rule_: Any module containing a `main()` function shall have the word `main` as part of its source file name.

    * _Reasoning_: Multi-platform development environments (e.g., Unix and Windows) are the norm rather than the exception. 
        Mixed case names can cause problems across operating systems and are also error prone due to the possibility of 
        similarly- named but differently-capitalized files becoming confused by human programmers.
        The inclusion of `main` in a file name is an aid to code maintainers that has proven useful in projects with 
        multiple software configurations.

* **Header Files**

    * _Rule_: There shall always be precisely one header file for each source file and they shall always have the same root name.

    * _Rule_: Each header file shall contain a **preprocessor guard against multiple inclusion**.

    * _Rule_: The header file shall identify only the procedures, constants, and data types (via prototypes or macros, 
        #define, and typedefs, respectively) about which it is strictly necessary for other modules to be informed.

        * It is a preferred practice that no variable ever be declared (via `extern`) in a header file.

        * No storage for any variable shall be allocated in a header file.

    * _Rule_: No public header file shall contain a `#include` of any private header file.

    * _Reasoning_: The C language standard gives all variables and functions global scope by default. 
        The downside of this is unnecessary (and dangerous) coupling between modules. 
        To reduce inter-module coupling, keep as many procedures, constants, data types, and variables as possible 
        privately hidden within a module’s source file.


* **Source Files**

    * _Rule_: Each source file shall include only the behaviors appropriate to control one “entity”. 
    Examples of entities include encapsulated data types, active objects, peripheral drivers (e.g., for a UART), 
    and communication protocols or layers (e.g., ARP).

    * _Rule_: Each source file shall be comprised of some or all of the following sections, in the order listed: 
        * comment block
        * include statements
        * data type, constant, and macro definitions
        * static data declarations 
        * private function prototypes
        * public function bodies
        * then private function bodies.

    * _Rule_: Each source file shall always `#include` the header file of the same name 
    (e.g., file `adc.c` should `#include “adc.h”`), to allow the compiler to confirm that each public function and 
    its prototype match.

    * _Rule_: Absolute paths shall not be used in include file names.

    * _Rule_: Each source file shall be free of unused include files.

    * _Rule_: No source file shall `#include` another source file.

    * _Reasoning_: The purpose and internal layout of a source file module should be clear to all who maintain it. 
    For example, the public functions are generally of most interest and thus appear ahead of the private functions 
    they call. Of critical importance is that every function declaration be matched by the compiler against its prototype.


## Comment Rules

* **Acceptable Formats**
    * _Rule_: Single-line comments in the C++ style (i.e., preceded by `//`) are a useful and acceptable alternative to traditional C style comments (i.e., `/* … */`).

    * _Rule_: Comments shall never contain the preprocessor tokens `/*`, `//`, or `\`.

    * _Rule_: Code shall never be commented out, even temporarily.
        * To temporarily disable a block of code, use the preprocessor’s conditional compilation feature 
        (e.g., `#if 0 … #endif`).

        * Any line or block of code that exists specifically to increase the level of debug output information shall 
        be surrounded by `#ifndef NDEBUG …#endif`.

    * _Reasoning_: Whether intentional or not, nested comments run the risk of confusing source code reviewers about 
    the chunks of the code that will be compiled and run. Our choice of negative-logic `NDEBUG` is deliberate, as that 
    constant is also associated with disabling the `assert()` macro. In both cases, the programmer acts to disable the 
    verbose code.


* **Locations and Content**
    * _Rule_: All comments shall be written in clear and complete sentences, with proper spelling and grammar and 
    appropriate punctuation.

    * _Rule_: The most useful comments generally precede a block of code that performs one step of a larger algorithm. 
    A blank line shall follow each such code block. The comments in front of the block should be at the same indentation 
    level.

    * _Rule_: Avoid explaining the obvious. Assume the reader knows the C programming language. 

    * _Rule_: The number and length of individual comment blocks shall be proportional to the complexity of the code 
    they describe.

    * _Rule_: Whenever an algorithm or technical detail is defined in an external reference—e.g., a design specification, 
    patent, or textbook—a comment shall include a sufficient reference to the original source to allow a reader of the 
    code to locate the document.

    * _Rule_: Whenever a flow chart or other diagram is needed to sufficiently document the code, the drawing shall be 
    maintained with the source code under version control and the comments should reference the diagram by file name or title.

    * _Rule_: All assumptions shall be spelled out in comments.

    * _Rule_: Each module and function shall be commented in a manner suitable for automatic documentation generation, 
    e.g., via Doxygen.

    * _Rule_: Use the following capitalized comment markers to highlight important issues:
        * “WARNING:” alerts a maintainer there is risk in changing this code. 
        For example, that a delay loop counter’s terminal value was determined empirically and may need to change when the code is ported or the optimization level tweaked.

        * “NOTE:” provides descriptive comments about the “why” of a chunk of code—as distinguished from the “how” usually placed in comments. For example, that a chunk of driver code deviates from the datasheet because there was an errata in the chip. Or that an assumption is being made by the original programmer.

        * “TODO:” indicates an area of the code is still under construction and explains what remains to be done. When appropriate, an all-caps programmer name or set of initials may be included before the word TODO (e.g., “MJB TODO:”).

    * _Reasoning_: Following these rules results in good comments. And good comments correlate with good code. It is a best practice to write the comments before writing the code that implements the behaviors those comments outline.

    Unfortunately, it is easy for source code and documentation to drift over time. The best way to prevent this is to keep the documentation as close to the code as possible. Likewise, anytime a question is asked about a section of the code that was previously thought to be clear, you should add a comment addressing that issue nearby.

    Doxygen is a useful tool to generate documentation describing the modules, functions, and parameters of an API for its users. However, comments are also still necessary inside the function bodies to reduce the cost of code maintenance.


## References
* Robert C. Martin. Clean Code. Prentice Hall, 2008

* Barr Group. [Embedded C Coding Standard](https://barrgroup.com/embedded-systems/books/embedded-c-coding-standard)

*Egon Teiniker, 2020-2022, GPL v3.0*      
