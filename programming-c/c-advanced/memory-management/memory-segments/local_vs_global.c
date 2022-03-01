#include <stdio.h>
#include <assert.h>

// 1 + 2 + 3 + ... + n-1 + n
int sum_of_integers(int n)
{
    int result;         // Local variable
    result = n*(n+1)/2;
    return result;
}

int counter(void)
{
    static int value;   // Local variable with static storage duration
    return value++;
}


int counter_value = 0;  // Global variable
void increment()
{
    counter_value++;
}
void decrement()
{
    counter_value--;
}


int main(void)
{
    int result = sum_of_integers(100);
    assert(result == 5050);

    // Block scope
    {
        int i = 7;
        assert(i == 7);
    }
    {
        int i = 3;
        assert(i==3);
    }
    for(int i=0; i<10; i++)
    {
        assert(i < 10);
    }

    // Static variable 
    assert(0 == counter());
    assert(1 == counter());
    assert(2 == counter());

    // Global variable
    counter_value = 7;
    increment();
    increment();
    decrement();
    assert(8 == counter_value);


    return 0;
}
