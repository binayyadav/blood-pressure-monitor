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

#include "timer.h"

#define PS_256 3
#define PS_64 2
#define PS_8 1
#define PS_1 0
#define PS_MAX 4


uint16_t timer_auto_TxCON(uint32_t FOSC, uint32_t f)
{
    TxCON tcon;
    tcon.u16 = 0;
    uint32_t max_freq[4];
    max_freq[PS_1]   = timer_calculate_freq(FOSC,1000, 1);
    max_freq[PS_8]   = timer_calculate_freq(FOSC,1000, 8);
    max_freq[PS_64]  = timer_calculate_freq(FOSC,1000, 64);
    max_freq[PS_256] = timer_calculate_freq(FOSC,1000, 256);
    if(f < max_freq[PS_1]){ tcon.TCKPS = PS_1; }
    if(f < max_freq[PS_8]){ tcon.TCKPS = PS_8; }
    if(f < max_freq[PS_64]){ tcon.TCKPS = PS_64; }
    if(f < max_freq[PS_256]){ tcon.TCKPS = PS_256; }
    tcon.TON = 1;
    return tcon.u16;
}

uint16_t timer_auto_PRx(uint32_t FOSC, uint32_t f)
{
    uint16_t PRx;
    uint16_t config = timer_auto_TxCON(FOSC, f);

    PRx = FOSC/(2*f*timer_TCKPS2literal_u16(config));

    return PRx;
}

uint32_t timer_calculate_freq(uint32_t FOSC, uint32_t PRx, uint32_t PS)
{
    if(FOSC == 0 || PRx == 0 || PS == 0)
        return 0;
    return FOSC/(2*PRx*PS);
}

uint16_t timer_freq_set_16bit(uint16_t control, uint32_t FOSC, uint32_t f)
{
    TxCON tcon;
    tcon.u16 = control;
    uint32_t prescaler;
    uint16_t PRx;
    PRx = FOSC/(f>>1);

    switch(tcon.TCKPS)
    {
        case 3: prescaler = 256; break;
        case 2: prescaler = 64; break;
        case 1: prescaler = 8; break;
        case 0: prescaler = 1; break;
    }
    return PRx;

}

uint32_t timer_TCKPS2literal(TxCON t)
{
    uint32_t PS;
    switch(t.TCKPS)
    {
        case 0: PS = 1; break;
        case 1: PS = 8; break;
        case 2: PS = 64; break;
        case 3: PS = 256; break;
        default:
                break;
    }
    return PS;
}

uint32_t timer_TCKPS2literal_u16(uint16_t config)
{
    uint32_t PS;
    TxCON txcon;
    txcon.u16 = config;
    switch(txcon.TCKPS)
    {
        case 0: PS = 1; break;
        case 1: PS = 8; break;
        case 2: PS = 64; break;
        case 3: PS = 256; break;
        default:
                break;
    }
    return PS;
}
