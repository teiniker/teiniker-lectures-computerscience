# Project Layout

This project separates sources, headers, tests, and build artifacts into
clear directories. This keeps the repository clean, makes the public
interface explicit, and avoids mixing generated files with edited code.

```bash
├── build
│   ├── main
│   ├── main.o
│   ├── test
│   ├── test.o
│   ├── unity.o
│   └── vector.o
├── include
│   └── vector.h
├── Makefile
├── src
│   ├── main.c
│   └── vector.c
└── test
    └── test.c
```

Build and test steps using the Makefile:

* `make` builds objects into `build/`, links the test binary, and runs the
  test suite via the `run_test` target.

* `make run` builds and executes the main program in `build/main`.

* `make run_test` builds and executes the test binary in `build/test`.

* `make clean` removes the `build/` directory.

*Egon Teiniker, 2020-2026, GPL v3.0*
