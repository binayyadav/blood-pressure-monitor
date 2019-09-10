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

#ifndef J_MATH_H
#define J_MATH_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
typedef struct vector_u_tag
{
    int32_t offset;
    int32_t zero;
    uint32_t n;
    double *p_double;
}vector_u;

uint8_t math_acos_double(void);
uint8_t math_asin_double(void);
uint8_t math_atan_double(void);
uint8_t math_cos_double(void);
double math_deg2rad_double(double deg);
uint16_t math_delta_u16(uint16_t a, uint16_t b);
double math_sin_double(double radian);
double math_sum_double(uint32_t count, double *terms);
uint8_t math_tan_double(void);
void math_vector_copy(uint32_t count, double *src, double *dest);
void math_vector_mult_double(uint32_t count, double *a, double *b, double *result);
void math_vector_reverse(uint32_t count, double *vector);
uint16_t math_virtual_index(int32_t n, int32_t v_zero, int32_t v_offset);

double fabs(double);

#endif //MATH_VIRTUAL_INDEX_H

