/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   uLL_softPeripherals.hpp                                   :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: Nathan Embedded <Anh.Embedded@gmail.com>            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2022/10/07 19:04:56 by Nathan Embed          #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2022/10/07 19:04:56 by Nathan Embed         ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */


/*--------------------------------------------------------------------
  For including C's header files
--------------------------------------------------------------------*/
#ifndef MKL46Z4_LEARNING_SOURCE_UHAL_ULL_SOFTPERIPHERALS_ULL_SOFTPERIPHERALS_HPP
#define MKL46Z4_LEARNING_SOURCE_UHAL_ULL_SOFTPERIPHERALS_ULL_SOFTPERIPHERALS_HPP

extern "C"
{
#include "CMSIS/cmsis_compiler.h"
#include "board/board.h"
#include "CMSIS/MKL46Z4.h"
}
/*--------------------------------------------------------------------
  For including Cpp's header files
--------------------------------------------------------------------*/
#include "bitManipulation.hpp"
#include <cstdint>


namespace softPeripherals
{
    void delay();
}/* namespace softPeripherals */

#endif // MKL46Z4_LEARNING_SOURCE_UHAL_ULL_SOFTPERIPHERALS_ULL_SOFTPERIPHERALS_HPP
