#include <stdio.h>

#define N 12

int main(void)
{
    int values[N] = {-7, 0, 12, 6, -2, 23, 12, 9, -10, 19, -16, -1};

    int min = values[0];    // init value
    int max = values[0];    // init value
    int sum = 0;

    for(int i=0; i<N; i++)
    {
        sum += values[i];   // sum = sum + values[i];

        if(values[i] < min)
            min = values[i];

        if(values[i] > max)
            max = values[i];
    }
    double mean = (double)sum/N;    // without (double) => 3.0000 !!!
    printf("\tmin=%d\tmax=%d\tmean=%f\n", min, max, mean);

    return 0;
}
