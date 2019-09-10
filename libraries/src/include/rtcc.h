/******************************************************************************************************
 SOFTWARE COPYRIGHT NOTICE:

 © [2013] Microchip Technology Inc. and its subsidiaries.
 You may use this software and any derivatives exclusively with Microchip products.

 THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
 MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS,
 COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

 IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

 MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE TERMS.
******************************************************************************************************/

#ifndef RTCC_H
#define RTCC_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct rtcc_tag {
    union {
        struct {
            union {
                struct {
                    uint8_t sec_ones:4;
                    uint8_t sec_tens:4;
                };
                uint8_t sec;
            };
            union {
                struct {
                    uint8_t min_ones:4;
                    uint8_t min_tens:4;
                };
                uint8_t min;
            };
        };
        uint16_t min_sec;
    };
    union {
        struct {
            union {
                struct {
                    uint8_t hour_ones:4;
                    uint8_t hour_tens:4;
                };
                uint8_t hour;
            }; 
            union {
                struct {
                    uint8_t weekday_ones:4;
                    uint8_t weekday_tens:4;
                };
                uint8_t weekday;
            };
        };
        uint16_t weekday_hour;
    };
    union {
        struct {
            union {
                struct {
                    uint8_t day_ones:4;
                    uint8_t day_tens:4;
                };
                uint8_t day;
            };
            union {
                struct {
                    uint8_t month_ones:4;
                    uint8_t month_tens:4;
                };
                uint8_t month;
            };
        };
        uint16_t month_day;
    };
    union {
        struct {
            uint8_t year_ones:4;
            uint8_t year_tens:4;
        };
        uint8_t year;
    };
}rtcc;
void rtcc_read(rtcc *r);
void rtcc_set(rtcc *r);
void rtcc_cpy(rtcc *dst, rtcc *src);
rtcc* rtcc_new(void);

#endif //RTCC_H
