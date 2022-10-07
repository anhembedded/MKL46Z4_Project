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

#define RED_LED_PIN (1 << 29)
#define GREEN_LED_PIN (1 << 5)

const constexpr auto PORT_PCR_MUX_GPIO = 0x01U;

static void greenLedInit()
{
    BOARD_LED_RED_GPIO_PORT->PCR[BOARD_LED_RED_GPIO_PIN] = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);

    /* Set the pins direction to output */

    SET_BIT(FPTE->PDDR, BOARD_LED_RED_GPIO_PIN);

    /* Set the initial output state to high */
    SET_BIT(FPTE->PSOR, BOARD_LED_RED_GPIO_PIN);
}

static void redLedInit()
{
    /* Set the PTE29 pin multiplexer to GPIO mode */
    BOARD_LED_GREEN_GPIO_PORT->PCR[BOARD_LED_GREEN_GPIO_PIN] = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
    /* Set the pins direction to output */
    SET_BIT(FPTD->PDDR, BOARD_LED_GREEN_GPIO_PIN);
    /* Set the initial output state to high */
    SET_BIT(FPTD->PSOR, BOARD_LED_GREEN_GPIO_PIN);
}

void OnBoardLED::init()
{
    greenLedInit();
    redLedInit();
}
