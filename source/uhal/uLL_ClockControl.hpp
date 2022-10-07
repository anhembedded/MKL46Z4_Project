/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   uLL_ClockControl.hpp                                      :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: Nathan Embedded <Anh.Embedded@gmail.com>            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2022/10/07 10:29:20 by Nathan Embed          #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2022/10/07 10:29:20 by Nathan Embed         ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef MKL46Z4_PROJECT_SOURCE_UHAL_ULL_CLOCKCONTROL_HPP
#define MKL46Z4_PROJECT_SOURCE_UHAL_ULL_CLOCKCONTROL_HPP

/*--------------------------------------------------------------------
  For including C's header files
--------------------------------------------------------------------*/
extern "C"
{
#include "CMSIS/cmsis_compiler.h"
#include "board/board.h"
}
/*--------------------------------------------------------------------
  For including Cpp's header files
--------------------------------------------------------------------*/
#include "bitManipulation.hpp"
#include <cstdint>

namespace iLL_clockControl
{
    namespace coreClock
    {

    } // namespace coreClock
    namespace systemClock
    {
        __STATIC_FORCEINLINE auto enableClkPortA() -> void;
        __STATIC_FORCEINLINE auto enableClkPortC() -> void;
        __STATIC_FORCEINLINE auto enableClkPortD() -> void;
        __STATIC_FORCEINLINE auto enableClkPortE() -> void;
        __STATIC_FORCEINLINE auto enableClkPortF() -> void;
#ifdef GPIOG
        __STATIC_FORCEINLINE auto enableClkPortG() -> void;
#endif
    } // namespace systemClock
    namespace platformClock
    {

    } // namespace platformClock

} // namespace iLL_clockControl

#endif // MKL46Z4_PROJECT_SOURCE_UHAL_ULL_CLOCKCONTROL_HPP
