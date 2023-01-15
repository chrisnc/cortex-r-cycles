#pragma once

#include "arm_coprocessor.h"

#include <stdint.h>

static inline void cycle_count_enable(void)
{
    /* Enable all counters and reset the cycle counter. */
    pmcr_oreq(PMCR_E | PMCR_C);
    /* Enable the cycle counter. */
    pmcntenset_oreq(PMCNTEN_C);
}

static inline uint32_t cycle_count(void)
{
    return pmccntr();
}
