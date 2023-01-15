#include "cycle.h"

void enable(void)
{
    cycle_count_enable();
}

uint32_t count(void)
{
    return cycle_count();
}
