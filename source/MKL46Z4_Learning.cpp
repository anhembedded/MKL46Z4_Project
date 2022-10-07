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

int main(void)
{
    clockControl::systemClock::enableClkPortD();
    clockControl::systemClock::enableClkPortE();
    OnBoardLED::init();
    OnBoardLED::ledRed::on();
    OnBoardLED::ledRed::off();
    while (true)
    {
    }

    return (0);
}
