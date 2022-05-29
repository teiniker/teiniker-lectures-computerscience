#include <stdio.h>
#include <assert.h>

int search(int data[], int size, int value)
{
    for(int i=0; i<size; i++)
    {
        if(data[i] == value)
        {
            return i;
        }
    }
    return -1;
}


int main(void)
{
    int data[10] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};

    assert(search(data, 10, 60) == 4);
    assert(search(data, 10, 130) == 8);
    assert(search(data, 10, 99) == -1);

	return 0;
}

