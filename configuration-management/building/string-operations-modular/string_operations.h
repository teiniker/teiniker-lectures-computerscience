#ifndef _STRING_OPERATIONS_H_
#define _STRING_OPERATIONS_H_

#include <stdio.h>
#include <stdbool.h>

extern size_t string_length(const char *s);
extern bool string_equal(const char *s1, const char *s2);
extern char *string_copy(const char *s);
extern char *string_concatenation(const char *s1, const char *s2);

#endif /* _STRING_OPERATIONS_H_ */