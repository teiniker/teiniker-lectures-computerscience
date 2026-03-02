#include <assert.h>
#include <log.h>


int add(int a, int b)
{
    log_debug("add(%i, %i) - start", a, b);
    int sum = a + b;
    log_debug("add() - end");
    return sum;
}

int main(void)
{
    //log_set_quiet(true);
    //log_set_level(LOG_DEBUG);
    log_set_level(LOG_INFO);

    log_debug("main() - start");

    int result = add(5, 10); 
    log_info("Result: %i", result);
    assert (result == 15);

    log_debug("main() - end");
    return 0;
}

