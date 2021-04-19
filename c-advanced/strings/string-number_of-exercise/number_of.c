#include <stdio.h>
#include <assert.h>

size_t string_number_of(const char *s, char c);

int main(void)
{
    char *s = "1001 0011 1111 0000";
    size_t ones = string_number_of(s, '1');
    size_t zeros = string_number_of(s, '0');
    size_t spaces = string_number_of(s, ' ');

    printf("\"%s\" contains: %d x '1', %d x '0', %d x ' '\n", s, (int)ones, (int)zeros, (int)spaces);
    assert(ones == 8);
    assert(zeros == 8);
    assert(spaces == 3);

    return 0;
}

// TODO: Implementation