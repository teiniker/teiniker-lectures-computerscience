#include<stdio.h>

//#define DEBUG

void debug(const char *msg)
{
#if defined(DEBUG) 
    printf("DEBUG [%s:%d] %s\n",__FILE__, __LINE__, msg);
#endif
}

// Use: cpp -P debugging.c  to see the cpp output
int main(void)
{
    debug("enter main()");

    printf("Hello Graz!\n");

    debug("leave main()");
    return 0;
}
