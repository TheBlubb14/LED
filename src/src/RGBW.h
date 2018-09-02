#pragma once

#ifndef _RGBW_H_
#define _RGBW_H_

#include <cstdint>

typedef struct RGBW
{
    operator uint32_t() const
    {
        return rgbw;
    }
    union
    {
        uint32_t rgbw;
        
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        struct{
            uint8_t w;
            uint8_t b;           
            uint8_t g;
            uint8_t r;
        };
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        struct{
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t w;
        };
#else
    #error compiler not supported
#endif
    };
} __attribute__((packed)) RGBW;
#endif /* _RGBW_H_ */