# Copilot Instructions

## Repository Overview
This is an educational repository containing **examples, exercises, and model 
solutions** for teaching computer science and programming in C/C++.
These small examples are distributed in different folders.

### High-Level Organization

```
teiniker-lectures-computerscience/
├── introduction/                  # Course introduction
│   ├── language-processing/       # Compiled vs. interpreted languages
│   ├── setup/                     # Dev environment (Linux, macOS, Windows)
│   └── agentic-engineering/       # Using AI agents and GitHub
├── programming-c/                 # C language topics
│   ├── c-basics/                  # Types, control flow, functions, structs
│   ├── c-advanced/                # Arrays, strings, memory, files, errors,
│   │                              # modular programming
│   └── c-std-lib/                 # math, stdint, stdio, string, time
├── programming-c++/               # C++ language topics
│   ├── introduction/              # Hello world in C and C++
│   ├── basics/                    # Functions, structures, extern "C"
│   ├── oop/                       # Classes, associations, inheritance
│   ├── stl/                       # Standard Template Library
│   ├── datastructures/            # C++ data structures
│   ├── controlling/               # State machine examples (LED)
│   └── unity/                     # Unity testing framework
├── datastructures+algorithms/     # Data structures and algorithms in C
│   ├── introduction/              # Growth of functions, sequential search
│   ├── datastructures/            # Array, list, stack, queue, map, tree
│   ├── algorithms/                # Searching, sorting, mathematics
│   └── libraries/                 # GLib, Unity
├── configuration-management/      # Build, test, debug, document, version
│   ├── building/                  # Compiler flags and build concepts
│   ├── testing/                   # Unity framework examples and test patterns
│   ├── debugging/                 # Asserts, interactive debugger, logging
│   ├── coding-standard/           # Barr Group C Coding Standard
│   ├── documentation/             # Doxygen, Markdown, UML
│   ├── versioning/                # Version control (Git)
│   └── continuous-integration/    # Jenkins
└── linux/                         # Linux OS concepts and utilities
    ├── shell/, editors/           # Command line and editors
    ├── filesystem/, processes/    # File system, process management
    ├── system-calls/              # Linux system call examples
    ├── user-management/           # Users, groups, permissions
    ├── package-manager/, docker/  # Software installation, containers
    └── raspberry-pi/              # Embedded Linux on Raspberry Pi
```

## Build and TestCommands

Every subdirectory contains a `Makefile`. The standard targets are:

- **`make`** or **`make all`**: Compiles and runs the program/tests (default target)
- **`make build`**: Compiles the program without running
- **`make run`** or **`make run_test`**: Runs the compiled program or tests
- **`make clean`**: Removes the `build/` directory and all artifacts
- **`make init`**: Creates the `build/` directory (often called by other targets)

Projects use **`gcc`** for C and **`g++`** for C++:

- **C flags**: `-std=c17`, `-g`, `-O0`, `-Wall`
- **C++ flags**: `-std=c++11`, `-g`, `-Wall`
- **Test flags**: `-DUNITY_INCLUDE_DOUBLE` (for floating-point assertions in Unity tests)


### Testing Framework

The repository uses the **Unity Testing Framework** for unit tests:
- Unity source is located in differnt directories and accessed via relative paths 
    like `../../../unity`

## Key Conventions

### Naming Conventions

- **Exercise directories**: Suffix with `-exercise` (e.g., `leap-years-exercise`)
- **Model solution directories**: No suffix (e.g., `leap-years`)
- **Test files**: Named `test.c` or `test.cpp`
- **Source organization**: Each logical unit (functions, structures, algorithms) 
    has its own subdirectory

### Coding Standard

- **Line width**: Maximum **80 characters** per line
- **Indentation**: **4 spaces** per level (not tabs)
- **Braces**: 
  - Always surround blocks with braces `{ }`, even for single statements
  - Left brace `{` goes on the next line after the statement
  - Right brace `}` aligns with the opening keyword
- **Spacing**:
  - Binary operators (`+`, `-`, `*`, `/`, `==`, etc.) surrounded by spaces
  - Unary operators (`++`, `--`, `!`, `~`) have no space on operand side
  - Pointer operators (`*`, `&`) have spaces in declarations but not on operand side
  - No spaces around member/arrow operators (`.`, `->`, `[`, `]`)
- **Variable declarations**: First characters aligned within a block
- **Blank lines**: Before and after natural blocks of code (loops, if/else, declarations)

#### Example

```c
int  x = 0;
int  y = 5;
int  sum = 0;

for (i = 0; i < 10; i++)
{
    sum = sum + i;
}

if ((sum > 0) && (sum < 100))
{
    printf("Sum is within range\n");
}
```

### Documentation 

* Use only 80 chars per line for documentation text.
* Don't use —, ---, and emojis in generated text.

* Use Mermaid to generate class diagrams.
    - Use direction LR
    - Add a : between an attribute name and type, e.g. id:int
    - Make the constructor static (add $ at the end)

