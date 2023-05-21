#include <cstdio>

#include "hello.h"

size_t say_hello(const char *name)
{
    size_t len = printf("Hello %s!\n",name);
    return len;
}