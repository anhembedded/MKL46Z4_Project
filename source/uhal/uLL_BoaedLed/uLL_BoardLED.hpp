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
#include "CMSIS\MKL46Z4.h"
#include "CMSIS\board.h"

static auto greenLedInit() -> void;
static auto redLedInit() -> void;

namespace OnBoardLED
{
    __STATIC_INLINE auto init() -> void
    {
        
    }
    

} // namespace OnBoardLED




#endif // MKL46Z4_PROJECT_SOURCE_UHAL_ULL_BOARDLED_HPP
