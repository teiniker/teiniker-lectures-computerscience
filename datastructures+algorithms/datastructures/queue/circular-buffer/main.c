#include <stdio.h>
#include <stdlib.h>

#include "buffer.h"

int main() 
{
    circular_buffer_t *cb = buffer_new(10);

    buffer_enqueue(cb, 10);
    buffer_enqueue(cb, 20);
    buffer_enqueue(cb, 30);

    printf("Dequeuing: %d\n", buffer_dequeue(cb));
    printf("Dequeuing: %d\n", buffer_dequeue(cb));

    buffer_enqueue(cb, 40);
    buffer_enqueue(cb, 50);
    buffer_enqueue(cb, 60);

    printf("Dequeuing: %d\n", buffer_dequeue(cb));
    printf("Dequeuing: %d\n", buffer_dequeue(cb));
    printf("Dequeuing: %d\n", buffer_dequeue(cb));

    return EXIT_SUCCESS;
}
