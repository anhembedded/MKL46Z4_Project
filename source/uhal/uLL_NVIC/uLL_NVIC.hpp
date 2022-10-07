/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   uLL_NVIC.hpp                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: Nathan Embedded <Anh.Embedded@gmail.com>            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2022/10/07 13:55:24 by Nathan Embed          #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2022/10/07 13:55:24 by Nathan Embed         ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef MKL46Z4_PROJECT_SOURCE_UHAL_ULL_NVIC_ULL_NVIC_HPP
#define MKL46Z4_PROJECT_SOURCE_UHAL_ULL_NVIC_ULL_NVIC_HPP

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

namespace uLL_NVIC
{
    namespace SW1
    {
        __STATIC_FORCEINLINE void setRriority(uint32_t u32Priority);
        __STATIC_FORCEINLINE void clearMask();
        __STATIC_FORCEINLINE void clearPendingBit();
        __STATIC_FORCEINLINE bool isFlagSet();
    }
    namespace SW3
    {
        __STATIC_FORCEINLINE void setRriority(uint32_t u32Priority);
        __STATIC_FORCEINLINE void clearMask();
        __STATIC_FORCEINLINE void clearPendingBit();
        __STATIC_FORCEINLINE bool isFlagSet();
    }
} /* namespace uLL_NVIC */

#endif // MKL46Z4_PROJECT_SOURCE_UHAL_ULL_NVIC_ULL_NVIC_HPP
