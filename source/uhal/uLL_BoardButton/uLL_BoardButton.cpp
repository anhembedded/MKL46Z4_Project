
#include "uhal/uLL_ClockControl/uLL_ClockControl.hpp"
#include "uhal/uLL_BoardButton/uLL_BoardButton.hpp"

/***********************************
 * 1000 INTERRUPT WHEN LOGIC ZERO. *
 * 1001 INTERRUPT ON RISING EDGE.  *
 * 1010 INTERRUPT ON FALLING EDGE. *
 * 1011 INTERRUPT ON EITHER EDGE.  *
 * 1100 INTERRUPT WHEN LOGIC ONE.
 ***********************************/

constexpr auto PORT_PCR_IRQC_LOGIC_ZERO = 0b1000U;
constexpr auto PORT_PCR_IRQC_RISING_EDGE = 0b1001U;
constexpr auto PORT_PCR_IRQC_FALLING_EDGE = 0b1010U;
constexpr auto PORT_PCR_IRQC_EITHER_EDGE = 0b1011U;
constexpr auto PORT_PCR_IRQC_LOGIC_ONE = 0b1100U;

void OnBoardButton::pollingMethod::init()
{

    clockControl::systemClock::enableClkPortC();

    /* Set the PTC3 pin multiplexer to GPIO mode/ Enable pull-up resistor */
    PORTC->PCR[3] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

    /* Set the pins direction to input */
    CLEAR_BIT(FPTC->PDDR, BOARD_SW1_GPIO_PIN);

    /* Set the PTC3 pin multiplexer to GPIO mode/ Enable pull-up resistor */
    PORTC->PCR[12] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

    /* Set the pins direction to input */
    CLEAR_BIT(FPTC->PDDR, BOARD_SW3_GPIO_PIN);
}

void OnBoardButton::interrupt::init()
{
    clockControl::systemClock::enableClkPortC();
    BOARD_SW1_PORT->PCR[BOARD_SW1_GPIO_PIN] |= PORT_PCR_IRQC(PORT_PCR_IRQC_FALLING_EDGE);
    BOARD_SW3_PORT->PCR[BOARD_SW3_GPIO_PIN] |= PORT_PCR_IRQC(PORT_PCR_IRQC_FALLING_EDGE);
    NVIC_EnableIRQ(PORTC_PORTD_IRQn);
}