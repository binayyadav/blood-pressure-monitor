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

#include "rtcc.h"
#ifdef __XC16__
#include <xc.h>
#endif
#define    MINUTES_SECONDS 0
#define    WEEKDAY_HOURS 1
#define    MONTH_DAY  2
#define    YEAR  3

#ifdef __XC16__
rtcc flash_clock __attribute__((persistent));
#else
rtcc flash_clock;
#endif

void rtcc_set(rtcc *r)
{
    if(r->hour_tens > 2) {
        r->hour_tens = 0;
    }
    if(r->hour_ones > 9) {
        r->hour_ones = 0;
    }
    if(r->min_tens > 5) {
        r->min_tens = 0; 
    }
    if(r->min_ones > 9) {
        r->min_ones = 0; 
    }
    if(r->hour > 0x24) {
        r->hour = 0x24;
    }
    if(r->min > 0x59) {
        r->min = 0x59; 
    }


#ifdef __XC16__
    RCFGCALbits.RTCPTR = 3;
    RTCVAL = r->year;
    RTCVAL = r->month_day;
    RTCVAL = r->weekday_hour;
    RTCVAL = r->min_sec;
    flash_clock.year         = r->year;         
    flash_clock.month_day    = r->month_day;
    flash_clock.weekday_hour = r->weekday_hour;
    flash_clock.min_sec      = r->min_sec;
#endif // __XC16__
}
void rtcc_read(rtcc *r)
{   
#ifdef __XC16__
    //if(RCFGCALbits.RTCSYNC == 0) // Add this later
    r->year = RTCVAL;
    RCFGCALbits.RTCPTR = 2;
    r->month_day =RTCVAL;  
    RCFGCALbits.RTCPTR = 1;
    r->weekday_hour = RTCVAL;  
    RCFGCALbits.RTCPTR = 0;
    r->min_sec = RTCVAL;  
#endif // __XC16__
}
rtcc* rtcc_new(void)
{
    rtcc *r = (rtcc *)malloc(sizeof(rtcc)); 

    r->year         = flash_clock.year;
    r->month_day    = flash_clock.month_day;
    r->weekday_hour = flash_clock.weekday_hour;
    r->min_sec      = flash_clock.min_sec;

    //r->year = 0;
    //r->weekday_hour = 0;
    //r->month_day = 0;
    //r->min_sec = 0;
    return r; 
}

void rtcc_cpy(rtcc *dst, rtcc *src)
{
    dst->year         = src->year ;
    dst->weekday_hour = src->weekday_hour ;
    dst->month_day    = src->month_day ;
    dst->min_sec      = src->min_sec ;
}

