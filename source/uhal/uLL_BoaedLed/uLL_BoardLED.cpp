/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   uLL_BoardLED.cpp                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: Nathan Embedded <Anh.Embedded@gmail.com>            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2022/10/07 10:51:30 by Nathan Embed          #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2022/10/07 10:51:30 by Nathan Embed         ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "uLL_BoardLED.hpp"

const constexpr auto PORT_PCR_MUX_GPIO = 0x01U;

static auto greenLedInit() -> void
{
    /*
     * Initialize the RED LED (PTE5)
     */
    BOARD_LED_RED_GPIO_PORT->PCR[BOARD_LED_RED_GPIO_PIN] |= PORT_PCR_MUX(PORT_PCR_MUX_GPIO);

    /* Set the pins direction to output */

    FPTE->PDDR |= BOARD_LED_RED_GPIO_PIN;

    /* Set the initial output state to high */
    FPTE->PSOR |= BOARD_LED_RED_GPIO_PIN;
}

static auto redLedInit() -> void
{
    /*
     * Initialize the Green LED (PTE5)
     */

    /* Set the PTE29 pin multiplexer to GPIO mode */
    BOARD_LED_GREEN_GPIO_PORT->PCR[BOARD_LED_GREEN_GPIO_PIN] |= PORT_PCR_MUX(PORT_PCR_MUX_GPIO);

    /* Set the pins direction to output */
    FPTD->PDDR |= BOARD_LED_GREEN_GPIO_PIN;

    /* Set the initial output state to high */
    FPTD->PSOR |= BOARD_LED_GREEN_GPIO_PIN;
}

auto OnBoardLED::init() -> void
{
    greenLedInit();
    redLedInit();
}
