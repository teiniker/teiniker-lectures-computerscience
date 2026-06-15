#include <cstddef>
#include <cstdio>
#include <cstdlib>

#include "array_list.h"

ArrayList::ArrayList(size_t dimension)
{
    _size = 0;
    _dimension = dimension;
    _array = new int[dimension]();
}

ArrayList::~ArrayList()
{
    delete[] _array;
}

size_t ArrayList::size()
{
    return _size;
}

int ArrayList::get(int index)
{
    if (index < 0 || index >= (int)_size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return _array[index];
}

int ArrayList::find(int value)
{
    for (int i = 0; i < (int)_size; i++)
    {
        if (_array[i] == value)
            return i;
    }
    return -1;
}

void ArrayList::append(int value)
{
    _array[_size] = value;
    _size++;
}

void ArrayList::insert(int index, int value)
{
    if (index < 0 || index > (int)_size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    for (int i = (int)_size; i > index; i--)
    {
        _array[i] = _array[i - 1];
    }
    _array[index] = value;
    _size++;
}

void ArrayList::remove(int index)
{
    if (index < 0 || index >= (int)_size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    _size--;
    for (int i = index; i < (int)_size; i++)
    {
        _array[i] = _array[i + 1];
    }
}

void ArrayList::print()
{
    printf("[ ");
    for (int i = 0; i < (int)_size; i++)
    {
        printf("%d ", _array[i]);
    }
    printf("]\n");
}
