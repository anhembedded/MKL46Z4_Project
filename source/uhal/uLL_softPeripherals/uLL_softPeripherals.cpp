#include "uLL_softPeripherals.hpp"
#define MY_DELAY_CNT (1000000)

void softPeripherals::delay() {
    uint32_t i;
    for (i = 0; i < MY_DELAY_CNT; i++)
    {
        __asm("nop");
    }
}
