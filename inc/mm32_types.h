////////////////////////////////////////////////////////////////////////////////
/// @file    MM32_TYPES.H
/// @author  AE TEAM
/// @version V3.0.0
/// @date    2021-01-25
/// @brief   THIS FILE PROVIDES ALL THE TYPE FIRMWARE FUNCTIONS.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT 2018 MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion ---------------------------------------
#ifndef __MM32_TYPES_H
#define __MM32_TYPES_H

// Includes  -------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>

#ifndef __I
    #define __I                         volatile const                          ///< Defines 'read only' permissions
#endif

#ifndef __O
    #define __O                         volatile                                ///< Defines 'write only' permissions
#endif

#ifndef __IO
    #define __IO                        volatile                                ///< Defines 'read / write' permissions
#endif

typedef int64_t                         s64;                                    ///< 64 Bit variable
typedef int32_t                         s32;                                    ///< 32 Bit variable
typedef int16_t                         s16;                                    ///< 16 Bit variable
typedef int8_t                          s8;                                     ///< 8 Bit variable

typedef const int64_t                   sc64;                                   ///< const 64 Bit variable
typedef const int32_t                   sc32;                                   ///< const 32 Bit variable
typedef const int16_t                   sc16;                                   ///< const 16 Bit variable
typedef const int8_t                    sc8;                                    ///< const 8 Bit variable

typedef volatile int64_t                vs64;                                   ///< volatile 64 Bit variable
typedef volatile int32_t                vs32;                                   ///< volatile 32 Bit variable
typedef volatile int16_t                vs16;                                   ///< volatile 16 Bit variable
typedef volatile int8_t                 vs8;                                    ///< volatile 8 Bit variable

typedef volatile const int64_t          vsc64;                                  ///< volatile const 64 Bit variable
typedef volatile const int32_t          vsc32;                                  ///< volatile const 32 Bit variable
typedef volatile const int16_t          vsc16;                                  ///< volatile const 16 Bit variable
typedef volatile const int8_t           vsc8;                                   ///< volatile const 8 Bit variable

typedef uint64_t                        u64;                                    ///< 64 Bit unsigned variable
typedef uint32_t                        u32;                                    ///< 32 Bit unsigned variable
typedef uint16_t                        u16;                                    ///< 16 Bit unsigned variable
typedef uint8_t                         u8;                                     ///< 8 Bit unsigned variable

typedef const uint64_t                  uc64;                                   ///< const 64 Bit unsigned variable
typedef const uint32_t                  uc32;                                   ///< const 32 Bit unsigned variable
typedef const uint16_t                  uc16;                                   ///< const 16 Bit unsigned variable
typedef const uint8_t                   uc8;                                    ///< const 8 Bit unsigned variable

typedef volatile uint64_t               vu64;                                   ///< volatile 64 Bit unsigned variable
typedef volatile uint32_t               vu32;                                   ///< volatile 32 Bit unsigned variable
typedef volatile uint16_t               vu16;                                   ///< volatile 16 Bit unsigned variable
typedef volatile uint8_t                vu8;                                    ///< volatile 8 Bit unsigned variable

typedef volatile const uint64_t         vuc64;                                  ///< volatile const 64 Bit unsigned variable
typedef volatile const uint32_t         vuc32;                                  ///< volatile const 32 Bit unsigned variable
typedef volatile const uint16_t         vuc16;                                  ///< volatile const 16 Bit unsigned variable
typedef volatile const uint8_t          vuc8;                                   ///< volatile const 8 Bit unsigned variable

#ifndef BOOL
    typedef bool                        BOOL;                                   ///< Bool type
#endif

#define U8_MAX                          (UINT8_MAX)                             ///< unsigned 8 bit max value
#define U16_MAX                         (UINT16_MAX)                            ///< unsigned 16 bit max value
#define U32_MAX                         (UINT32_MAX)                            ///< unsigned 32 bit max value

#define S8_MAX                          (INT8_MAX)                              ///< 8 bit max value
#define S16_MAX                         (INT16_MAX)                             ///< 16 bit max value
#define S32_MAX                         (INT32_MAX)                             ///< 32 bit max value

#define S8_MIN                          (INT8_MIN)                              ///< 8 bit min value
#define S16_MIN                         (INT16_MIN)                             ///< 16 bit min value
#define S32_MIN                         (INT32_MIN)                             ///< 32 bit min value

#ifndef MAX
    #define MAX(a,b)                    ((a)>(b)?(a):(b))                       ///< Max function
#endif

#ifndef MIN
    #define MIN(a,b)                    ((a)<(b)?(a):(b))                       ///< Min function
#endif

#endif  // __MM32_TYPES_H
