#include <xc.h>
#include "timer.h"

_CONFIG4( DSWDTPS_DSWDTPS1F //     1:68719476736 (25.7 Days)
        & DSWDTOSC_LPRC     //     DSWDT uses LPRC as reference clock
        & DSBOREN_OFF       //     DSBOR Disabled
        & DSWDTEN_OFF       //     DSWDT Disabled
        & DSSWEN_OFF        //     Deep Sleep operation is always disabled
        & RTCBAT_ON         //     RTC operation is continued through VBAT
        & PLLDIV_DIV2       //     Oscillator divided by 2 (8 MHz input)
        & I2C2SEL_SEC       //     I2C2 is multiplexed to SDA2/RF4 and SCL2/RF5
        & IOL1WAY_OFF )     //     The IOLOCK bit can be set and cleared using the unlock sequence

_CONFIG3( WPFP_WPFP0          //       Page 0 (0x00)                              
        & SOSCSEL_ON          //       SOSC circuit selected
        & WDTWIN_PS25_0       //       Watch Dog Timer Window Width is 25 percent
        & BOREN_OFF           //       Brown-out Reset Disabled
        & WPDIS_WPDIS         //       Disabled
        & WPCFG_WPCFGDIS      //       Disabled
        & WPEND_WPSTARTMEM )  //       Write Protect from page 0 to WPFP

_CONFIG2( POSCMD_XT           //       XT Oscillator Enabled                                    
        & WDTCLK_SOSC         //       WDT uses SOSC input
        & OSCIOFCN_ON         //       OSCO/CLKO/RC15 functions as port I/O (RC15)
        & FCKSM_CSDCMD        //       Clock switching and Fail-Safe Clock Monitor are disabled
        & FNOSC_PRIPLL        //       Primary Oscillator with PLL module (XTPLL,HSPLL, ECPLL)
        & ALTADREF_AVREF_RB   //       AVREF+/AVREF- are mapped to RB0/RB1
        & ALTCVREF_CVREF_RB   //       CVREF+/CVREF- are mapped to RB0/RB1
        & WDTCMX_LPRC         //       WDT always uses LPRC as its clock source
        & IESO_OFF )          //       Disabled

_CONFIG1( WDTPS_PS32768        //       1:32,768
        & FWPSA_PR128          //       1:128
        & WINDIS_OFF           //       Standard Watchdog Timer
        & FWDTEN_WDT_DIS       //       WDT disabled in hardware; SWDTEN bit disabled
        & ICS_PGx3             //       Emulator functions are shared with PGEC2/PGED2
        & LPCFG_ON             //       Low voltage regulator controlled in sw by RETEN bit
        & GWRP_OFF             //       Disabled
        & GCP_OFF              //       Code protection is disabled
        & JTAGEN_OFF )         //       Disabled


#define FOSC 32000000

void _ISR _T1Interrupt(void)
{
    _LATE6 ^= 1;
    _T1IF = 0;
}
void main(void)
{

    _TRISE6 = 0;
    T1CON = timer_config_auto(FOSC,20000).u16;
    PR1 = timer_config_auto(FOSC,20000).PRx;



    _T1IF = 0;
    _T1IE = 1;
    while(1){}
}
