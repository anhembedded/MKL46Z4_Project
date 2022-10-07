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
#include "uhal/uLL_BoardButton/uLL_BoardButton.cpp"

uint32_t watchVar = 0;

int main(void)
{
    clockControl::systemClock::enableClkPortD();
    clockControl::systemClock::enableClkPortE();
    OnBoardLED::init();
    uLL_onBoardButton::init();
    OnBoardLED::ledRed::on();
    OnBoardLED::ledRed::off();
    while (true)
    {
        if (uLL_onBoardButton::SW1::isPress())
        {
            watchVar = 1;
        }
        else
        {
            watchVar = 0;
        }
    }

    return (0);
}
