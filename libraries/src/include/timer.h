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

#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

typedef struct TxCON_tag{
    uint16_t PRx;
  union {
      uint16_t u16;
    struct {
      uint8_t :1;
      uint8_t TCS:1;
      uint8_t TSYNC:1;
      uint8_t :1;
      uint8_t TCKPS:2;
      uint8_t TGATE:1;
      uint8_t :1;
      uint8_t TECS:2;
      uint8_t :3;
      uint8_t TSIDL:1;
      uint8_t :1;
      uint8_t TON:1;
    };
    struct {
      uint8_t :4;
      uint8_t TCKPS0:1;
      uint8_t TCKPS1:1;
      uint8_t :2;
      uint8_t T1ECS0:1;
      uint8_t T1ECS1:1;
    };
    struct {
      uint8_t :8;
      uint8_t T1ECS:2;
    };
    struct {
      uint8_t :8;
      uint8_t TECS0:1;
      uint8_t TECS1:1;
    };
  };
} TxCON;

uint16_t timer_auto_PRx(uint32_t FOSC, uint32_t f);
uint16_t timer_auto_TxCON(uint32_t FOSC, uint32_t f);
uint32_t timer_calculate_freq(uint32_t FOSC, uint32_t PRx, uint32_t PS);
uint16_t timer_freq_set_16bit(uint16_t control, uint32_t FOSC, uint32_t f);
uint32_t timer_TCKPS2literal(TxCON t);
uint32_t timer_TCKPS2literal_u16(uint16_t config);

#endif //TIMER_TCKPS2LITERAL_U16_H

