/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   uLL_BoardButton.hpp                                       :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: Nathan Embedded <Anh.Embedded@gmail.com>            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2022/10/07 12:27:33 by Nathan Embed          #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2022/10/07 12:27:33 by Nathan Embed         ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef MKL46Z4_PROJECT_SOURCE_UHAL_ULL_BOARDBUTTON_ULL_BOARDBUTTON_HPP
#define MKL46Z4_PROJECT_SOURCE_UHAL_ULL_BOARDBUTTON_ULL_BOARDBUTTON_HPP

extern "C"
{
    /**********************************
     *  * FOR INCLUDING C'S HEADER FILES *
     **********************************/
#include "CMSIS\MKL46Z4.h"
#include "board\board.h"
}
/************************************
 * FOR INCLUDING CPP'S HEADER FILES *
 ************************************/
#include "bitManipulation.hpp"

namespace OnBoardButton
{
    namespace pollingMethod
    {
        void init();
        namespace SW1
        {
            __STATIC_FORCEINLINE bool isPress()
            {
                decltype(isPress()) temp = 0;
                temp = !IS_BIT_SET(BOARD_SW1_GPIO->PDIR, BOARD_SW1_GPIO_PIN);
                return (temp);
            }
        } /* namespace SW1 */

        namespace SW3
        {
            __STATIC_FORCEINLINE bool isPress()
            {
                decltype(isPress()) temp = 0;
                temp = !IS_BIT_SET(BOARD_SW3_GPIO->PDIR, BOARD_SW3_GPIO_PIN);
                return (temp);
            }
        } /* namespace SW3 */
    }
    namespace interrupt
    {

        void init();
        namespace SW1
        {
            auto flagReg = &BOARD_SW1_PORT->PCR[BOARD_SW1_GPIO_PIN];
            __STATIC_FORCEINLINE void setRriority(uint32_t u32Priority)
            {
                NVIC_SetPriority(PORTC_PORTD_IRQn, u32Priority);
            }
            __STATIC_FORCEINLINE void clearPendingBit()
            {
                NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);
            }
            __STATIC_FORCEINLINE bool isFlagSet()
            {
                return IS_BIT_SET(*flagReg, PORT_PCR_ISF_SHIFT);
            }
            void (*callbackHandler)();
        } /* SW1 */

        namespace SW3
        {
            auto flagReg = &BOARD_SW3_PORT->PCR[BOARD_SW3_GPIO_PIN];
            __STATIC_FORCEINLINE void setRriority(uint32_t u32Priority)
            {
                NVIC_SetPriority(PORTC_PORTD_IRQn, u32Priority);
            }
            __STATIC_FORCEINLINE void clearPendingBit()
            {
                NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);
            }
            __STATIC_FORCEINLINE bool isFlagSet()
            {
                return IS_BIT_SET(*flagReg, PORT_PCR_ISF_SHIFT);
            }
            void (*callbackHandler)();
        } /* SW3 */
    }     /* interrupt */

}

#endif // MKL46Z4_PROJECT_SOURCE_UHAL_ULL_BOARDBUTTON_ULL_BOARDBUTTON_HPP
