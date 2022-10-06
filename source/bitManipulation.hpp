/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   bitManipulation.hpp                                       :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: Nathan Embedded <Anh.Embedded@gmail.com>            +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2022/10/05 18:02:17 by Nathan Embed          #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2022/10/05 18:02:17 by Nathan Embed         ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef MKL46Z4_PROJECT_WORK_SOURCE_BITMANIPULATION_HPP
#define MKL46Z4_PROJECT_WORK_SOURCE_BITMANIPULATION_HPP

#include <inttypes.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * \addtogroup helpers_bitmanipulation Bit-manipulation macros
     * @{
     **/

    /** 32 bit bit accessing macro. **/
#define _BV32(i) (uint32_t)((uint32_t)(1UL << i))

    /** Bit-level access and test macros. **/
#define SET_BIT(port, bit) ((port) |= (1 << (bit)))
#define CLEAR_BIT(port, bit) ((port) &= ~(1 << (bit)))
#define TOGGLE_BIT(port, bit) ((port) ^= (1 << (bit)))
#define IS_BIT_SET(port, bit) (((port) & (1 << (bit))) ? 1 : 0)
#define IS_BIT_CLEAR(port, bit) (((port) & (1 << (bit))) == 0 ? 1 : 0)

    /** 8-bit macros. **/
#define SET_BIT8(port, bit) ((port) |= (uint8_t)(1 << (bit)))
#define CLEAR_BIT8(port, bit) ((port) &= (uint8_t) ~(1 << (bit)))
#define IS_BIT_SET8(port, bit) (((port) & (uint8_t)(1 << (bit))) ? 1 : 0)
#define IS_BIT_CLEAR8(port, bit) (((port) & (uint8_t)(1 << (bit))) == 0 ? 1 : 0)

    /** 32-bit macros. **/
#define SET_BIT32(port, bit) ((port) |= (uint32_t)(1UL << (bit)))
#define CLEAR_BIT32(port, bit) ((port) &= (uint32_t) ~(1UL << (bit)))
#define TOGGLE_BIT32(port, bit) ((port) ^= (uint32_t)(1UL << (bit)))
#define IS_BIT_SET32(port, bit) (((port) & (uint32_t)(1UL << (bit))) ? 1 : 0)
#define IS_BIT_CLEAR32(port, bit) (((port) & (uint32_t)(1UL << (bit))) == 0 ? 1 : 0)

    /** 64-bit macros. **/
#define SET_BIT64(port, bit) ((port) |= (uint64_t)(1ULL << (bit)))
#define CLEAR_BIT64(port, bit) ((port) &= (uint64_t) ~(1ULL << (bit)))
#define TOGGLE_BIT64(port, bit) ((port) ^= (uint64_t)(1ULL << (bit)))
#define IS_BIT_SET64(port, bit) (((port) & (uint64_t)(1ULL << (bit))) ? 1 : 0)
#define IS_BIT_CLEAR64(port, bit) (((port) & (uint64_t)(1ULL << (bit))) == 0 ? 1 : 0)

    /** @} */

    /**
     * \addtogroup helpers_common_symbols Commonly used symbols and macros
     * @{
     **/

    /** Define commonly used C symbols. **/
#ifndef NULL
#define NULL 0
#endif

#define FALSE 0
#define TRUE 1

    /** Number of elements in a static array. **/
#define countof(arr) ((sizeof(arr) / sizeof(arr[0])))

    /** Compile-time assertion in C. **/
#define C_ASSERT(e) extern char __C_ASSERT__[(e) ? 1 : -1]

    /** Compress a C structure to byte aligned boundaries. **/
#define PACKED __attribute__((packed))

    /** @} **/

    /**
     * \addtogroup helpers_math Math macros
     * @{
     **/

    /** Get the minimum of x and y. **/
#define MIN(x, y) ((x) > (y) ? (y) : (x))
    /** Get the maximum of x and y. **/
#define MAX(x, y) ((x) > (y) ? (x) : (y))
    /** Get the absolute value of x. **/
#define ABS(x) ((x) < 0 ? -(x) : (x))

    /**
     * @}
     */

#ifdef __cplusplus
}
#endif

#endif // MKL46Z4_PROJECT_WORK_SOURCE_BITMANIPULATION_HPP
