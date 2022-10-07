#include "uLL_BoardButton.hpp"
#include "uhal/uLL_ClockControl/uLL_ClockControl.hpp"

void uLL_onBoardButton::init()
{
    clockControl::systemClock::enableClkPortC();
    /*
     * Initialize the SW1
     */

    /* Set the PTC3 pin multiplexer to GPIO mode/ Enable pull-up resistor */
    PORTC->PCR[3] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

    /* Set the pins direction to input */
    CLEAR_BIT(FPTC->PDDR, BOARD_SW1_GPIO_PIN);

    /*
     * Initialize the SW2
     */

    /* Set the PTC3 pin multiplexer to GPIO mode/ Enable pull-up resistor */
    PORTC->PCR[12] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

    /* Set the pins direction to input */
    CLEAR_BIT(FPTC->PDDR, BOARD_SW3_GPIO_PIN);
}
