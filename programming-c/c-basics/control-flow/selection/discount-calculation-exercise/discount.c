#include <stdio.h>
#include <stdbool.h> 

int main(void)
{
    int amount = 5000;    // 0%
//    int amount = 25000;   // 2%
//    int amount = 75000;   // 5%
//    int amount = 150000;  // 10%

    int discount;

    // TODO

    printf("amount = EUR %5.2f   discount = %d%%\n", amount/100.0, discount);

    return 0;
}
