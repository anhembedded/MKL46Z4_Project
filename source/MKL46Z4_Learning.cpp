/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   MKL46Z4_Learning.cpp                                      :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: Nathan Embedded <Anh.Embedded@gmail.com>            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2022/10/07 18:35:08 by Nathan Embed          #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2022/10/07 18:35:08 by Nathan Embed         ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

extern "C"
{
#include "board.h"
#include "MKL46Z4.h"
}

#include "uhal/uLL_BoaedLed/uLL_BoardLED.hpp"
#include "uhal/uLL_ClockControl/uLL_ClockControl.hpp"
#include "uhal/uLL_BoardButton/uLL_BoardButton.hpp"
volatile uint32_t msTicks = 123; /* Variable to store millisecond ticks */
uintmax_t umaxTickCounter;
extern "C"
{
    void SysTick_Handler(void)
    {
        /* SysTick interrupt Handler. */
        msTicks++; /* See startup file startup_LPC17xx.s for SysTick vector */
        NVIC_ClearPendingIRQ(SysTick_IRQn);
    }
}

uint32_t watchVar = 0;

__NO_RETURN int main(void)
{
    clockControl::systemClock::enableClkPortD();
    clockControl::systemClock::enableClkPortE();
    OnBoardLED::init();
    OnBoardButton::pollingMethod::init();
    SystemInit();

    SysTick_Config(SystemCoreClock / 1000);

    while (true)
    {
        if (OnBoardButton::pollingMethod::SW1::isPress())
        {
            OnBoardLED::ledRed::off();
            watchVar = 1;
        }

        if (!OnBoardButton::pollingMethod::SW1::isPress())
        {

            OnBoardLED::ledRed::on();
            watchVar = 0;
        }
    }
    // NEW OnClassChanged;git
    return (0);
}
