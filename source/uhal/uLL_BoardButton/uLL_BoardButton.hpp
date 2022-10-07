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



#endif // MKL46Z4_PROJECT_SOURCE_UHAL_ULL_BOARDBUTTON_ULL_BOARDBUTTON_HPP
