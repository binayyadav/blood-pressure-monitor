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

#ifndef MCU_ADC_PIPELINE_H
#define MCU_ADC_PIPELINE_H
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>


typedef struct {
    unsigned ADCH:7;
    unsigned unused:7;
    unsigned DIFF:1;
    unsigned UCTMU:1;
} 
_ADTBLn;

typedef struct {
    unsigned SAMC:5;
    unsigned MULCHEN:1;
    unsigned PINTRIS:1;
    unsigned CTMEN:1;
    unsigned CM:3;
    unsigned WM:2;
    unsigned SLINT:2;
    unsigned ASEN:1;
} 
_ADLnCONH;

typedef struct {
    unsigned SLSIZE:6;
    unsigned THSRC:1;
    unsigned SLTSRC:5;
    unsigned SLENCLR:1;
    unsigned SAMP:1;
    unsigned SLEN:1;
} 
_ADLnCONL;

typedef struct tagADL0PTR {
    unsigned ADNEXT:7;
} 
_ADLnPTR;

typedef struct {
    unsigned ADLIF:1;
    unsigned ADTDLY:1;
    unsigned LBUSY:1;
    unsigned ADTACT:1;
} 
_ADLnSTAT;

typedef struct SampleList_tag
{
    _ADLnCONH   ADLnCONH;
    _ADLnCONL   ADLnCONL;
    _ADLnPTR    ADLnPTR;
    _ADLnSTAT   ADLnSTAT;
    uint16_t    ADTHnL;
    uint16_t    ADTHnH;
    uint16_t    ADLnMSEL0;
    uint16_t    ADLnMSEL1;
    uint16_t    ADLnMSEL2;
    uint16_t    ADLnMSEL3;

}SampleList;

//Definitions for the ADCReferences parameter
#define POSREF_AVDD     0x0000
#define POSREF_EXTREF   0x4000
#define POSREF_BGBUF    0x8000

#define NEGREF_AVSS     0x0000
#define NEGREF_EXTREF   0x1000

//Definitions for the ADCFormat parameter
#define ADCFORM_UINT    0x0000
#define ADCFORM_SINT    0x0100
#define ADCFORM_SFRACTIONAL 0x0300
#define ADCFORM_UFRACTIONAL 0x0200

typedef struct 
{
    unsigned sl0used:1;
    unsigned sl1used:1;
    unsigned sl2used:1;
    unsigned sl3used:1;
}adc_pipeline;
void mcu_adc_pipeline_init(uint16_t ADCReferences, uint16_t ADCFormat);
void mcu_adc_pipeline_disable(void);
uint16_t mcu_adc_pipeline_get_average_result(uint16_t ChannelSetting, uint8_t SamplingTime, uint16_t SamplesInAverage);
void adc_pipeline_sl_assign(uint8_t sample_list_number, SampleList *sl);


void adc_pipeline_sample_table_set(_ADTBLn *tbl, size_t tbl_size);

void adc_pipeline_config_begin(void);
void adc_pipeline_config_end(void);

#endif // MCU_ADC_PIPELINE_H
