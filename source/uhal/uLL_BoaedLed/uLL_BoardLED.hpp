/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   uLL_BoardLED.hpp                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: Nathan Embedded <Anh.Embedded@gmail.com>            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2022/10/06 23:25:43 by Nathan Embed          #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2022/10/06 23:25:43 by Nathan Embed         ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef MKL46Z4_PROJECT_SOURCE_UHAL_ULL_BOARDLED_HPP
#define MKL46Z4_PROJECT_SOURCE_UHAL_ULL_BOARDLED_HPP

#include <cstdint>

extern "C"
{
#include "CMSIS\MKL46Z4.h"
#include "board\board.h"
}
#include "bitManipulation.hpp"

static auto greenLedInit() -> void;
static auto redLedInit() -> void;

namespace OnBoardLED
{

    auto init() -> void;

    namespace ledRed
    {
        __STATIC_FORCEINLINE void off()
        {
            SET_BIT(BOARD_LED_RED_GPIO->PSOR, BOARD_LED_RED_GPIO_PIN);
        }
        __STATIC_FORCEINLINE void on()
        {
            SET_BIT(BOARD_LED_RED_GPIO->PCOR, BOARD_LED_RED_GPIO_PIN);
        }
        __STATIC_FORCEINLINE void toggle()
        {
            SET_BIT(BOARD_LED_RED_GPIO->PTOR, BOARD_LED_RED_GPIO_PIN);
        }
    } // ledRed

    namespace ledGreen
    {
        __STATIC_FORCEINLINE void on();
        __STATIC_FORCEINLINE void off();
        __STATIC_FORCEINLINE void toggle();
    }
} // namespace OnBoardLED

#endif // MKL46Z4_PROJECT_SOURCE_UHAL_ULL_BOARDLED_HPP
