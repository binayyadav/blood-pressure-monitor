/******************************************************************************************************
 SOFTWARE COPYRIGHT NOTICE:

 � [2013] Microchip Technology Inc. and its subsidiaries.
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

#include "waveform_tables.h"
uint16_t wavetable_sin[]={512, 576, 639, 700, 758, 812, 862, 906, 944, 975, 998, 1014, 1022, 1022, 1014, 998, 974, 943, 905, 861, 811, 757, 698, 637, 574, 510, 445, 382, 321, 263, 209, 160, 116, 78, 48, 24, 9, 1, 1, 10, 26, 50, 81, 119, 164, 214, 268, 326, 388, 451};
uint16_t wavetable_square[]={1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint16_t wavetable_tri[]={0, 41, 82, 123, 164, 205, 246, 286, 327, 368, 409, 450, 491, 532, 573, 614, 655, 696, 737, 777, 818, 859, 900, 941, 982, 1023, 982, 941, 900, 859, 818, 777, 737, 696, 655, 614, 573, 532, 491, 450, 409, 368, 327, 286, 246, 205, 164, 123, 82, 41};
uint16_t wavetable_ramp[]={0, 20, 41, 61, 82, 102, 123, 143, 164, 184, 205, 225, 246, 266, 286, 307, 327, 348, 368, 389, 409, 430, 450, 471, 491, 512, 532, 552, 573, 593, 614, 634, 655, 675, 696, 716, 737, 757, 777, 798, 818, 839, 859, 880, 900, 921, 941, 962, 982, 1003};
