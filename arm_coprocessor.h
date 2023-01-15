#pragma once

#include <stdint.h>

#define ARM_COPROCESSOR_REG(name, coproc, opc1, crn, crm, opc2)                \
    static inline uint32_t name(void)                                          \
    {                                                                          \
        uint32_t x;                                                            \
        __asm__ __volatile__("mrc " coproc ", %1, %0, " crn ", " crm ", %2"    \
                             : "=r"(x)                                         \
                             : "i"(opc1), "i"(opc2));                          \
        return x;                                                              \
    }                                                                          \
                                                                               \
    static inline void name##_set(uint32_t x)                                  \
    {                                                                          \
        __asm__("mcr " coproc ", %1, %0, " crn ", " crm ", %2"                 \
                :                                                              \
                : "r"(x), "i"(opc1), "i"(opc2));                               \
    }                                                                          \
                                                                               \
    static inline void name##_oreq(uint32_t x)                                 \
    {                                                                          \
        name##_set(name() | x);                                                \
    }                                                                          \
                                                                               \
    static inline void name##_andeq(uint32_t x)                                \
    {                                                                          \
        name##_set(name() & x);                                                \
    }

ARM_COPROCESSOR_REG(pmcr, "p15", 0, "c9", "c12", 0)
#define PMCR_E (UINT32_C(1) << 0) /* Enable. */
#define PMCR_C (UINT32_C(1) << 2) /* Cycle counter reset. */

ARM_COPROCESSOR_REG(pmccntr, "p15", 0, "c9", "c13", 0)

ARM_COPROCESSOR_REG(pmcntenset, "p15", 0, "c9", "c12", 1)
ARM_COPROCESSOR_REG(pmcntenclr, "p15", 0, "c9", "c12", 2)
#define PMCNTEN_C (UINT32_C(1) << 31)
