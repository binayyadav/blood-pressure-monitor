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

#include "mcu_adc_pipeline.h"

adc_pipeline adc0;

void mcu_adc_pipeline_init(uint16_t ADCReferences, uint16_t ADCFormat)
{
    uint16_t IPLSave;

    PMD1bits.ADC1MD = 0;    //Clear PMD bit to allow ADC operation
    
    //Recommended to keep ADC disabled while adjusting critical parameters 
    //like ADC clock settings
    ADCON1bits.ADON = 0;  //Disable ADC, if it was previously on
    ADCON3 = 0x0001;      //ADC clock is system clock derived
    ADCON2 = 0x0700 | ADCReferences; //Select the ADC references, buffer mode, power mode, other global settings
    ADCON1 = 0x0001 | ADCFormat; //Select ADC result formatting and other settings.
    
    //Enable the ADC module now
    ADCON1bits.ADON = 1;
    //Wait for hardware self calibration to complete
    while(ADSTATHbits.ADREADY == 0);
    
    //Apply A0 silicon workaround, to ensure self calibration gets loaded internally
    IPLSave = SR & 0x00E0;   //Save interrupt settings
    SRbits.IPL = 7; //Set CPU to max priority, so as to disable interrupts for
                    //below workaround code (which must not be interrupted to
                    //ensure it works correctly).
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;    
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;
    ADCON1bits.ADCAL = 1;  
    //Okay to restore previous interrupt settings now
    SR = (SR & 0xFF1F) | IPLSave; 
    //Wait for hardware self calibration to complete
    while(ADSTATHbits.ADREADY == 0);
    
    //The ADC is now ready to use.  Set up a sample list and generate a trigger
    //event to get result data.    
}    

void mcu_adc_pipeline_disable(void)
{
    //Disable the ADC module and configure for minimum current consumption
    PMD1bits.ADC1MD = 0;    
    ADCON1bits.ADON = 0;//Disable ADC module
    ADCON2 = 0xC000;    //Reserved setting: A0 workaround to minimize IPD current.
}    

uint16_t mcu_adc_pipeline_get_average_result(uint16_t ChannelSetting, uint8_t SamplingTime, uint16_t SamplesInAverage)
{
    uint16_t SamplesRemaining = SamplesInAverage;
    uint8_t SamplesForNextAccumulation;
    uint16_t Remainder;
    uint16_t Result;

    //Error check input params
    if(SamplesInAverage == 0)
        return 0;

    //Make sure ADC sample lists and Accumulator feature are in known states
    ADCON3 &= 0xF0FF;       //Clear SLENn bits to take command of all sample lists
    ACCONH = 0x0000;        //Disable accumulation for the moment
    ACRES = 0x00000000;    //Clear previous accumulation count

    //Prepare Sample List 0 to include the target ChannelSetting
    ADTBL0 = ChannelSetting;

    //Configure Sample List 0 settings
    ADL0PTR = 0;        //Point to start of sample list 0
    ADL0CONH = 0x0000 | (SamplingTime & 0x1F);   //Set SAMC bits to the value the user passed us
    ADL0CONL = 0x0100;  //Sample list not enabled yet, SAMP = 0, Manual trigger on every Tad when ACEN is set and SAMP = 0.
    ADL0CONLbits.SLEN = 1;  //Sample list enabled!  Accumulation will commence when ACEN is also set.

    //Now begin accumulation and continue until we have the desired number of 
    //total samples
    while(SamplesRemaining != 0)
    {
        //Configure Accumulation Settings
        if(SamplesRemaining >= 256)
        {
            SamplesForNextAccumulation = 0; //0 results in 256 samples exactly
            SamplesRemaining -= 256;
        }
        else   
        {
            SamplesForNextAccumulation = SamplesRemaining;
            SamplesRemaining = 0;
        }     
        ACCONL = SamplesForNextAccumulation;    //Using sample list 0 entry 0 (ADTBL0), with SamplesForNextAccumulation number of samples
        ACCONH = 0x00C0;    //Enable accumulation feature and accumulation interrupt generation

        //Wait for accumulations to complete.
        while(ACCONHbits.ACEN == 1);
    }

    //We now have the results.  Divide by sample count to get the average.  We
    //use a builtin function for enhanced speed and access to remainder for rounding.
    Result = __builtin_divmodud((unsigned long int)ACRES, (uint16_t)SamplesInAverage, &Remainder);  
    //Perform rounding of result
    if(Remainder >= (SamplesInAverage >> 1))
    {
        return ++Result;    //Increment by one to round up result.
    }    
    return Result;
}    

void adc_pipeline_sl_assign(uint8_t sample_list_number, SampleList *sl)
{
    switch(sample_list_number) {
        case 0:
            ADCON3 |= 0x0100;
            break;
        case 1:
            ADCON3 |= 0x0200;
            break;
        case 2:
            ADCON3 |= 0x0400;
            break;
        case 3:
            ADCON3 |= 0x0800;
            break;
    }
    switch(sample_list_number)
    {
        case 0:
            ADL0CONHbits.SAMC    = sl->ADLnCONH.SAMC;
            ADL0CONHbits.MULCHEN = sl->ADLnCONH.MULCHEN;
            ADL0CONHbits.PINTRIS = sl->ADLnCONH.PINTRIS;
            ADL0CONHbits.CTMEN   = sl->ADLnCONH.CTMEN;
            ADL0CONHbits.CM      = sl->ADLnCONH.CM;
            ADL0CONHbits.WM      = sl->ADLnCONH.WM;
            ADL0CONHbits.SLINT   = sl->ADLnCONH.SLINT;
            ADL0CONHbits.ASEN    = sl->ADLnCONH.ASEN;

            ADL0CONLbits.SLSIZE  = sl->ADLnCONL.SLSIZE;
            ADL0CONLbits.THSRC   = sl->ADLnCONL.THSRC;
            ADL0CONLbits.SLTSRC  = sl->ADLnCONL.SLTSRC;
            ADL0CONLbits.SLENCLR = sl->ADLnCONL.SLENCLR;
            ADL0CONLbits.SAMP    = sl->ADLnCONL.SAMP;
            ADL0CONLbits.SLEN    = sl->ADLnCONL.SLEN;

            ADL0PTRbits.ADNEXT   = sl->ADLnPTR.ADNEXT;

            ADTH0L               = sl->ADTHnL;
            ADTH0H               = sl->ADTHnH;
            ADL0MSEL0            = sl->ADLnMSEL0;
            ADL0MSEL1            = sl->ADLnMSEL1;
            ADL0MSEL2            = sl->ADLnMSEL2;
            ADL0MSEL3            = sl->ADLnMSEL3;
            break;
        case 1:
            ADL1CONHbits.SAMC    = sl->ADLnCONH.SAMC;
            ADL1CONHbits.MULCHEN = sl->ADLnCONH.MULCHEN;
            ADL1CONHbits.PINTRIS = sl->ADLnCONH.PINTRIS;
            ADL1CONHbits.CTMEN   = sl->ADLnCONH.CTMEN;
            ADL1CONHbits.CM      = sl->ADLnCONH.CM;
            ADL1CONHbits.WM      = sl->ADLnCONH.WM;
            ADL1CONHbits.SLINT   = sl->ADLnCONH.SLINT;
            ADL1CONHbits.ASEN    = sl->ADLnCONH.ASEN;

            ADL1CONLbits.SLSIZE  = sl->ADLnCONL.SLSIZE;
            ADL1CONLbits.THSRC   = sl->ADLnCONL.THSRC;
            ADL1CONLbits.SLTSRC  = sl->ADLnCONL.SLTSRC;
            ADL1CONLbits.SLENCLR = sl->ADLnCONL.SLENCLR;
            ADL1CONLbits.SAMP    = sl->ADLnCONL.SAMP;
            ADL1CONLbits.SLEN    = sl->ADLnCONL.SLEN;

            ADL1PTRbits.ADNEXT   = sl->ADLnPTR.ADNEXT;

            ADTH1L               = sl->ADTHnL;
            ADTH1H               = sl->ADTHnH;
            ADL1MSEL0            = sl->ADLnMSEL0;
            ADL1MSEL1            = sl->ADLnMSEL1;
            ADL1MSEL2            = sl->ADLnMSEL2;
            ADL1MSEL3            = sl->ADLnMSEL3;
            break;
        default:
            break;
    }
}

void adc_pipeline_sample_table_set(_ADTBLn *tbl, size_t tbl_size)
{
    ADTBL0BITS *ADTBLx = (ADTBL0BITS *)&ADTBL0;;
    size_t index;
    for(index = 0; index < tbl_size; index++)
    {
        ADTBLx[index].ADCH  = tbl[index].ADCH;
        ADTBLx[index].DIFF  = tbl[index].DIFF;
        ADTBLx[index].UCTMU = tbl[index].UCTMU;

    } 
}

void adc_pipeline_config_begin(void)
{

    ADCON1bits.ADON = 0;
    adc0.sl0used = 0;
    adc0.sl1used = 0;
    adc0.sl2used = 0;
    adc0.sl3used = 0;
    ADCON1bits.PUMPEN = 1;
    ADCON1bits.FORM = 0;
    ADCON2bits.BUFORG = 1;

}
void adc_pipeline_config_end(void)
{
    ADCON1bits.ADON = 1;
}
