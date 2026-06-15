#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#include <cstddef>


class ArrayList
{
public:
    ArrayList(size_t dimension);
    ~ArrayList();

    size_t size();
    int    get(int index);
    int    find(int value);
    void   append(int value);
    void   insert(int index, int value);
    void   remove(int index);
    void   print();

private:
    size_t  _size;
    size_t  _dimension;
    int    *_array;
};

#endif /* _ARRAY_LIST_H_ */
