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

#ifndef MATH_H
#define MATH_H

#include "math.h"

uint8_t math_acos_double(void);
uint8_t math_asin_double(void);
uint8_t math_atan_double(void);
uint8_t math_cos_double(void);
double math_deg2rad_double(double deg)
{
    return deg*((double)3.14159265359/(double)180.0);
}
uint16_t math_delta_u16(uint16_t a, uint16_t b)
{
    if(a<b)
        return b-a;
    return a-b;
}
double math_sum_double(uint32_t count, double *terms)
{
    uint32_t index;
    double sum = 0.0;
    for(index = 0; index < count; index++)
    {
        sum+=terms[index];
    } 
    return sum;
}
uint8_t math_tan_double(void);
double math_sin_double(double radian);
void math_vector_copy(uint32_t count, double *src, double *dest)
{
    uint32_t index;
    for(index = 0; index < count; index++)
    {
        dest[index] = src[index];
    } 
}
void math_vector_mult_double(uint32_t count, double *a, double *b, double *result)
{
    uint32_t index;
    for(index = 0; index < count; index++)
    {
        result[index]=a[index]*b[index];
    } 
}
void math_vector_reverse(uint32_t count, double *vector)
{
    uint32_t head;
    uint32_t tail;
    uint32_t index;
    double temp;
    head = 0;
    tail = count - 1;
    for(index = 0; index < count/2; index++)
    {
        temp = vector[head];
        vector[head] = vector[tail];
        vector[tail] = temp;
        head++;
        tail--;
    } 
}
uint16_t math_virtual_index(int32_t n, int32_t v_zero, int32_t v_offset)
{
    if(v_offset == n)
        return v_zero;
    if(v_zero+v_offset >= n)
        return n%(v_offset+v_zero);
    if(v_offset == 0)
        return v_zero;
    if(v_offset + v_zero == 0)
        return 0;
    if(v_offset < 0)
    {
        do {
        v_offset += n;
        } while (v_offset < 0);
    }
    if(v_offset+v_zero < n)
        return v_offset+v_zero;
    
    return 0x00;
}
#endif //MATH_H
