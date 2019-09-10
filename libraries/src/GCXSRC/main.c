/*******************************************************************

    Microchip Blood Pressure Monitor Reference Design Main Code

********************************************************************
 FileName:        main.c
 Description:     Blood Pressure Monitor (BPM) Demo Main Code
 Processor:       PIC24FJ128GC010
 Compiler:        Microchip XC16 Compiler v1.11 (with MPLAB X IDE v1.95)
 Company:         Microchip Technology Inc.
 Author:          Zhang Feng, Medical Products Group

********************************************************************
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

********************************************************************
 MEDICAL DEMO WARNINGS, RESTRICTIONS AND DISCLAIMER:

 This demo is intended solely for evaluation and development purposes.
 It is not intended for medical diagnostic use.

********************************************************************
 Change History:

 Author       Rev   Date          Description
 Zhang Feng   1.0   03/01/2013    Initial Release for BPM Demo Schematic Rev 0.3, GC10 Rev B1.
 Zhang Feng   1.1   08/05/2013    Added Firmware Version display menu.
 Zhang Feng   1.2   01/10/2014    Adjusted Calibrate_Pressure table for each demo board.
 Zhang Feng   1.3   02/12/2014    Modified calculation method for SYS & DIA in Calculate_BP().
 Zhang Feng   1.4   04/25/2014    Added USB data output code printf_usb().
                                  Added WiFi code for Home Health Hub demo.
 Zhang Feng   2.0   06/23/2014    Corrected bugs in blood pressure calculation routines and Algorithm 1.
 Zhang Feng   2.1   07/23/2014    Changed ADC_Sample_Rate from 500 to 250.
                                  Changed Sample_Window_Interval from 125 to 200 and no longer use pulse_peak_threshold.
 Zhang Feng   3.0   02/05/2015    Replaced the R2 resistor from 150 kohm to 100 kohm to reduce the Gain1 from 151 to 101.
                                  Changed the pressure_reading calculation equation.
                                  Replaced the digital filter with a 20-point moving average filter.
                                  Changed blood pressure calculation algorithm to Algorithm_2 using MAP's pulse amplitude.
                                  Added Find_MaxMin_MovingWindow() function and Rev 3.0 using this function to detect
                                  pulses' High/Low with running window determined by the very first two valid pulses.
 Zhang Feng   3.1   02/20/2015    Used a new 2-stage 32-point moving average filter to filter both ADC1 & ADC2.
                                  Used a 1-stage 3-point moving average filter to filter the delta[CURRENT].
                                  Rev 3.1 using a new pulse detection routine with UPPER_THRESHOLD & LOWER_THRESHOLD & AMPLITUDE_THRESHOLD to detect pulses' High/Low.
 Zhang Feng   3.2   03/26/2015    Added 10 more demo boards (MPG-BPM-PCB-1 Rev 0.1), S/N 11 to 20.
 Zhang Feng   4.0   03/27/2015    Changed to newer demo board Rev B. LCD pins were modified.
                                  Must define in the lcd.h file to select old board (Rev 01) or new board (Rev B) for LCD display.



********************************************************************
 Additional Note:

 - 8MHz Internal Clock (FRC with PLL), Fosc=32MHz.
 - ADC sampling rate = 250 Hz.
 - pressure_reading = SpanVoltage_kPa * 7.5; -> Convert kPa to mmHg,
   where Gain1=101, 2SMPP-02, SpanVoltage_kPa = ADC1_temp * (3.3/4096) * 1000 * 37 / 31 / 101;

*******************************************************************/
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mTouch.h"
#include "ui.h"
#include "lcd.h"
#include "timer.h"
#include "mcu_adc_pipeline.h"
#include "sigma_delta_adc.h"
#include "usb_config.h"
#include "usb_gc010.h"
#include "waveform_tables.h"
#include "rtcc.h"
#include "filter.h"

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

_CONFIG2( POSCMD_NONE 
        & WDTCLK_SOSC         //       WDT uses SOSC input
        & OSCIOFNC_ON         //       OSCO/CLKO/RC15 functions as port I/O (RC15)
        & FCKSM_CSDCMD        //       Clock switching and Fail-Safe Clock Monitor are disabled
        & FNOSC_FRCPLL        //       FRC with PLL
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
        & GWRP_OFF             //       Disable
        & GCP_OFF              //       Code protection is disabled
        & JTAGEN_OFF )         //       Disabled


lcd *LCD37x7;
ui *gcui;
rtcc *clock;

#define sleep_go() \
    if(gcui->goto_sleep == 1) {\
        _T1IE   = 0;\
        _T2IE   = 0;\
        _T3IE   = 0;\
        _T4IE   = 0;\
        _T5IE   = 0;\
        _USB1IE = 0;\
        LCD37x7->blink_enable = 0;\
        LCD37x7->blink_mask = 0;\
        lcd_printf("%02x:%02x%c%c%c",clock->hour,clock->min,0x85,0x83,0x84);\
        lcd_canvas_raster(LCD37x7);\
        ALCFGRPTbits.AMASK= 2;\
        gcui->menu_state = CLOCK;\
        LCD37x7->iconALL = 0;\
        LCD37x7->iconMICROCHIP = 1;\
        lcd_icon_raster_mcu(LCD37x7);\
        Sleep();\
    }\

#define sleep_wake()\
    ALCFGRPTbits.AMASK = 0;\
    _T1IE   = 1;\
    _T2IE   = 1;\
    _T3IE   = 1;\
    _T4IE   = 1;\
    _T5IE   = 1;\
    _USB1IE = 1;

//*****************************************************************************
// Global Definitions for BPM Demo
//*****************************************************************************
#define SoftwareVer "4.0"      //SoftwareVer is the revision of the code.
//#define Rev01_ENG1           //Must be defined and match the demo board serial# !
//#define Rev01_ENG2
//#define Rev01_1
//#define Rev01_2
//#define Rev01_3
//#define Rev01_4
//#define Rev01_5
//#define Rev01_6
//#define Rev01_7
//#define Rev01_8
//#define Rev01_9
//#define Rev01_10        //Gold Unit

//#define Rev01_11
//#define Rev01_12
//#define Rev01_13
//#define Rev01_14
//#define Rev01_15
//#define Rev01_16
//#define Rev01_17
//#define Rev01_18
//#define Rev01_19
//#define Rev01_20

//#define RevB_21
//#define RevB_22
//#define RevB_23
//#define RevB_24
//#define RevB_25
#define RevB_26

//HardwareVer is the serial# of the demo board, BoardVersion.Serial#
#ifdef Rev01_ENG1
#define HardwareVer "1.ENG1"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_ENG2
#define HardwareVer "1.ENG2"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_1
#define HardwareVer "1.1"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_2
#define HardwareVer "1.2"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_3
#define HardwareVer "1.3"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_4
#define HardwareVer "1.4"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_5
#define HardwareVer "1.5"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_6
#define HardwareVer "1.6"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             30
#endif
#ifdef Rev01_7
#define HardwareVer "1.7"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_8
#define HardwareVer "1.8"
#define pulse_peak_threshold        1220       //1250, 11000
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_9
#define HardwareVer "1.9"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif
#ifdef Rev01_10
#define HardwareVer "1.10"
#define pulse_peak_threshold        1220
#define HR_peak_threshold           1300
#define pressure_offset             20
#endif

#ifdef Rev01_11
#define HardwareVer "1.11"
#define pressure_offset             20
#endif
#ifdef Rev01_12
#define HardwareVer "1.12"
#define pressure_offset             40
#endif
#ifdef Rev01_13
#define HardwareVer "1.13"
#define pressure_offset             40
#endif
#ifdef Rev01_14
#define HardwareVer "1.14"
#define pressure_offset             47
#endif
#ifdef Rev01_15
#define HardwareVer "1.15"
#define pressure_offset             34
#endif
#ifdef Rev01_16
#define HardwareVer "1.16"
#define pressure_offset             35
#endif
#ifdef Rev01_17
#define HardwareVer "1.17"
#define pressure_offset             30
#endif
#ifdef Rev01_18
#define HardwareVer "1.18"
#define pressure_offset             32
#endif
#ifdef Rev01_19
#define HardwareVer "1.19"
#define pressure_offset             35
#endif
#ifdef Rev01_20
#define HardwareVer "1.20"
#define pressure_offset             25
#endif

#ifdef RevB_21
#define HardwareVer "B.21"
#define pressure_offset             20
#endif
#ifdef RevB_22
#define HardwareVer "B.22"
#define pressure_offset             40
#endif
#ifdef RevB_23
#define HardwareVer "B.23"
#define pressure_offset             26
#endif
#ifdef RevB_24
#define HardwareVer "B.24"
#define pressure_offset             20
#endif
#ifdef RevB_25
#define HardwareVer "B.25"
#define pressure_offset             16
#endif
#ifdef RevB_26
#define HardwareVer "B.26"
#define pressure_offset             25
#endif

#define Algorithm_2     //Blood pressure calculation algorithm 2 using MAP's pulse amplitude.
//#define U1WiFi

#define FOSC 32000000/*Hz*/
#define ADC_Sample_Rate 250     //500

#define BPM                 0
#define PreviousResult      1
#define CLOCK               2
#define FirmwareVersion     3
#define WiFi                4
#define MAX_STATE           5

#define menu_Start          0
#define menu_PumpAir        1
#define menu_Measuring      2
#define menu_ReleaseAir     3
#define menu_Result         4

#define Valve_OpenClose _LATE7
#define open    0           //valve open
#define close   1           //valve close
#define fast    1           //pump speed fast
#define slow    2           //pump speed slow
#define Gain_CP	0.07        //pressure_reading = ADC1_temp * (3.3/4096) * 1000 * 37 / 31 / 101 * 7.5 ~= ADC1_temp * 0.07
#define pressure_buf_length         64
#define overPressure_limit          200     //in mmHg
#define MAP_Sample_Window_Interval  2   //2
#define SpeedChange_Threshold   35      //45
#define RR_Interval_Number 3    //capture 4 valid pulses that is 3 RR intervals to calculate heart rate

#define cmd_reboot      0
#define cmd_CMD         1
#define cmd_set         2
#define cmd_save        3

unsigned char buf[128];
#define CMD_HDR buf[0]

//Ryan Bartling filter
#define FIR_SIZE 32     //32-point moving average
#define FIR_PASSES 2    //2-stage moving average filter

#define CURRENT 0
#define PREVIOUS 1

#define UPPER_THRESHOLD 12      //for pulse detection
#define LOWER_THRESHOLD -12     //for pulse detection
#define AMPLITUDE_THRESHOLD 300

//*****************************************************************************
// Global Variables for BPM Demo
//*****************************************************************************
uint16_t pressure_reading0, pressure_reading, SpanVoltage_kPa;
unsigned int Sample_Window_Counter;
unsigned char overPressure;
unsigned int HR_ADCcounter;
unsigned int CP_Peak_Buf[pressure_buf_length];
unsigned char mx, xp;
unsigned char PeakFound;
unsigned int ADC_sample_counts;
unsigned char SpeedChange_value;
uint16_t ADC1_new_raw;
uint16_t ADC2_new_raw;

unsigned int Systolic_Pressure, Systolic_Pressure_previous;
unsigned int Diastolic_Pressure, Diastolic_Pressure_previous;
unsigned int Heart_Rate, Heart_Rate_previous;
unsigned char TMR4_counter;
unsigned int PumpSpeed;
unsigned int MAP;
double ks, kd;
unsigned char xSYS, xDIA;

unsigned char Target_Pressure_Set;
unsigned int MAP_temp_Max;
unsigned char MAP_Sample_Window_Counter;
unsigned char mx_temp;
uint16_t Target_Pressure, MAP_target;
unsigned char Error;

//filterLowPass k;

#ifdef U1WiFi
unsigned char SYS_String[4], DIA_String[4], HR_String[4];
unsigned char string_length, sl;
unsigned char SYS_symbol[13] = {0x53, 0x59, 0x53, 0x20, 0x28, 0x6d, 0x6d, 0x48, 0x67, 0x29, 0x20, 0x3d, 0x20};      // "SYS (mmHg) = "
unsigned char DIA_symbol[13] = {0x44, 0x49, 0x41, 0x20, 0x28, 0x6d, 0x6d, 0x48, 0x67, 0x29, 0x20, 0x3d, 0x20};      // "DIA (mmHg) = "
unsigned char PUL_symbol[13] = {0x50, 0x52, 0x20, 0x20, 0x28, 0x62, 0x70, 0x6d, 0x29, 0x20, 0x20, 0x3d, 0x20};      // "PR  (bmp)  = "
unsigned int delayWF;

const char set_wlan_ssid[26] = {'s','e','t',' ','w','l','a','n',' ','s','s','i','d',' ','M','P','G','_','D','e','m','o','_','A','P',0x0d};      //set wlan ssid: MPG_Demo_AP
const char set_wlan_phrase[26] = {'s','e','t',' ','w','l','a','n',' ','p','h','r','a','s','e',' ','M','P','G','D','e','m','o','A','P',0x0d};    //set wlan phrase: MPGDemoAP
const char set_ip_host[26] = {'s','e','t',' ','i','p',' ','h','o','s','t',' ','1','9','2','.','1','6','8','.','1','.','1','0','7',0x0d};        //set ip host <IP address 192.168.1.107>
const char set_ip_remote[19] = {'s','e','t',' ','i','p',' ','r','e','m','o','t','e',' ','9','7','7','1',0x0d};                                  //set ip remote <port number 9771>
const char set_ip_dhcp[14] = {'s','e','t',' ','i','p',' ','d','h','c','p',' ','1',0x0d};                            //set ip dhcp 1 (DHCP=ON)
const char set_wlan_join[16] = {'s','e','t',' ','w','l','a','n',' ','j','o','i','n',' ','1',0x0d};                  //set wlan join 1
const char set_wlan_auth[16] = {'s','e','t',' ','w','l','a','n',' ','a','u','t','h',' ','4',0x0d};                  //set wlan auth 4: MIXED
const char set_sys_autoconn[19] = {'s','e','t',' ','s','y','s',' ','a','u','t','o','c','o','n','n',' ','1',0x0d};   //set sys autoconn 1 (automaticlly connect)
const char set_uart_mode[16] = {'s','e','t',' ','u','a','r','t',' ','m','o','d','e',' ','2',0x0d};                  //set uart mode 2
const char set_o_d[12] = {'s','e','t',' ','o',' ','d',' ','B','P','M',0x0d};                                        //set o d BPM (DeviceID=BPM)
const char set_comm_remote[18] = {'s','e','t',' ','c','o','m','m',' ','r','e','m','o','t','e',' ','0',0x0d};        //set comm remote 0 (send 0 to remote TCP client when TCP port is opened
const char set_comm_idle[16] = {'s','e','t',' ','c','o','m','m',' ','i','d','l','e',' ','5',0x0d};                  //set comm idle 5 (close TCP connection after 5sec of inactivity
const char SAVE[5] = {'s','a','v','e',0x0D};                                                                        //save
const char REBOOT[7] = {'r','e','b','o','o','t',0x0D};                                                              //reboot
const char EXIT[5] = {'e','x','i','t',0x0D};                                                                        //exit
const char CMD[3] = {'$','$','$'};                                                                                  //$$$
const char joining[7] = {'j','o','i','n','i','n','g'};
#endif

unsigned int debug=0;
unsigned char U1RX_State, cmd_type, RN_Ready, RN_save, RN_AOK, RN_CMD, ji=1;

unsigned char HRcounterFlag, Pulse_Detection_Enable;
unsigned int wheel_counter=0;
unsigned char w=1;
unsigned char usb_display;

unsigned int pulseHigh_Buf[pressure_buf_length];
unsigned int pulseLow_Buf[pressure_buf_length];
unsigned int PulseAmplitude_Buf[pressure_buf_length];
signed int Pulse_Amplitude;
unsigned int MAP_Amplitude;

//Ryan Bartling filter
int state;
int16_t dataPulse[2], dataCuff[2];
int16_t delta[2];
int16_t peakValue;
int16_t pulseHigh;
int16_t pulseLow;
int16_t rawDataPulse, rawDataCuff;
int16_t valueCuff;


//*****************************************************************************
// Local Function Prototypes
//*****************************************************************************
void one_short_beep(void);
void one_long_beep(void);
void pump_air(int spd);
void release_air(void);
void uitoa(WORD Value, BYTE* Buffer);
void U1_write1byte (unsigned char value);
void str_Int(uint16_t i);
void U1_WiFi (void);
void Calculate_BP(void);
void BPMDemoMenu(void);
void send2U1(unsigned char* Uart_Output, unsigned char sz);
void sendChar2U1(unsigned char ch);
void CTMU_current_cal(void);
void Init(void);
void Wait4RNresponse(void);
void Wheel_Position (unsigned char value);
void USB_Command();

typedef struct
{
	int32_t *reg;
	uint16_t size;
	uint16_t position;
	int32_t sum;
}moving_average;

moving_average* NewMovingAverage(uint16_t _size);
void DestroyMovingAverage(moving_average* _this);
int16_t MoveAverage(moving_average* _this, int16_t input);
void ClearAverage(moving_average* _this);

moving_average *maCuff[FIR_PASSES];
moving_average *maPulse[FIR_PASSES];
moving_average *maDelta;

/*****************************************************************************
 * Function Name: void Wheel_Position (unsigned char value)
 * Specification: Spinning the wheel.
 *****************************************************************************/
void Wheel_Position (unsigned char value)
{
    switch (value)
    {
        case 0:
            WHEEL1=0;WHEEL2=0;WHEEL3=0;WHEEL4=0;WHEEL5=0;WHEEL6=0;WHEEL7=0;WHEEL8=0;WHEEL9=0;WHEEL10=0;
            break;
        case 1:
            WHEEL1=1;WHEEL2=0;WHEEL3=0;WHEEL4=0;WHEEL5=0;WHEEL6=0;WHEEL7=0;WHEEL8=0;WHEEL9=0;WHEEL10=0;
            break;
        case 2:
            WHEEL1=0;WHEEL2=1;WHEEL3=0;WHEEL4=0;WHEEL5=0;WHEEL6=0;WHEEL7=0;WHEEL8=0;WHEEL9=0;WHEEL10=0;
            break;
        case 3:
            WHEEL1=0;WHEEL2=0;WHEEL3=1;WHEEL4=0;WHEEL5=0;WHEEL6=0;WHEEL7=0;WHEEL8=0;WHEEL9=0;WHEEL10=0;
            break;
        case 4:
            WHEEL1=0;WHEEL2=0;WHEEL3=0;WHEEL4=1;WHEEL5=0;WHEEL6=0;WHEEL7=0;WHEEL8=0;WHEEL9=0;WHEEL10=0;
            break;
        case 5:
            WHEEL1=0;WHEEL2=0;WHEEL3=0;WHEEL4=0;WHEEL5=1;WHEEL6=0;WHEEL7=0;WHEEL8=0;WHEEL9=0;WHEEL10=0;
            break;
        case 6:
            WHEEL1=0;WHEEL2=0;WHEEL3=0;WHEEL4=0;WHEEL5=0;WHEEL6=1;WHEEL7=0;WHEEL8=0;WHEEL9=0;WHEEL10=0;
            break;
        case 7:
            WHEEL1=0;WHEEL2=0;WHEEL3=0;WHEEL4=0;WHEEL5=0;WHEEL6=0;WHEEL7=1;WHEEL8=0;WHEEL9=0;WHEEL10=0;
            break;
        case 8:
            WHEEL1=0;WHEEL2=0;WHEEL3=0;WHEEL4=0;WHEEL5=0;WHEEL6=0;WHEEL7=0;WHEEL8=1;WHEEL9=0;WHEEL10=0;
            break;
        case 9:
            WHEEL1=0;WHEEL2=0;WHEEL3=0;WHEEL4=0;WHEEL5=0;WHEEL6=0;WHEEL7=0;WHEEL8=0;WHEEL9=1;WHEEL10=0;
            break;
        case 10:
            WHEEL1=0;WHEEL2=0;WHEEL3=0;WHEEL4=0;WHEEL5=0;WHEEL6=0;WHEEL7=0;WHEEL8=0;WHEEL9=0;WHEEL10=1;
            break;
        case 11:
            WHEEL1=1;WHEEL2=1;WHEEL3=1;WHEEL4=1;WHEEL5=1;WHEEL6=1;WHEEL7=1;WHEEL8=1;WHEEL9=1;WHEEL10=1;
            break;
    }
}

/*****************************************************************************
 * Function Name: void one_short_beep(void)
 * Specification: One short beep.
 *****************************************************************************/
void one_short_beep(void)
{
    unsigned int delay_beep;

    if (OC3CON1bits.OCM != 7) {
	OC3CON1bits.OCM = 7;		// Turn on Buzzer
    }
    for (delay_beep=0; delay_beep<60000; delay_beep++);
    OC3CON1bits.OCM = 0;		// Turn off Buzzer
    for (delay_beep=0; delay_beep<60000; delay_beep++);
}

/*****************************************************************************
 * Function Name: void one_long_beep(void)
 * Specification: One long beep.
 *****************************************************************************/
void one_long_beep(void)
{
    unsigned int delay_beep1, delay_beep2;

    if (OC3CON1bits.OCM != 7) {
        OC3CON1bits.OCM = 7;	// Turn on Buzzer
    }
    for (delay_beep2=0; delay_beep2<10; delay_beep2++)
    {
        for (delay_beep1=0; delay_beep1<60000; delay_beep1++);
    }
    OC3CON1bits.OCM = 0;	// Turn off Buzzer
}

/*****************************************************************************
 * Function Name: void pump_air(int spd)
 * Specification: Pumping air into cuff in fast or slow mode
 *****************************************************************************/
void pump_air(int spd)
{
    unsigned int delay;
    Valve_OpenClose = close;        // Close release valve
    PumpSpeed = spd;
    switch (spd)
    {
        case fast:
            for (OC1R=0x1000; OC1R>0; OC1R--)   // Pumping air in fast speed with soft start
            {
                for (delay=0; delay<100; delay++);
                if (OC1CON1bits.OCM != 7) {
                    OC1CON1bits.OCM = 7;        // Enable OC1/PWM1 for pump
                }
            }
            break;
        case slow:
            for (OC1R=OC1R; OC1R<0x01ff; OC1R++)   // Pumping air in slow speed, change OC1R(duty cycle) to 0x01ff(50%)
            {
                for (delay=0; delay<10; delay++);
                if (OC1CON1bits.OCM != 7) {
                    OC1CON1bits.OCM = 7;        // Enable OC1/PWM1 for pump
                }
            }
            break;
    }
}

/*****************************************************************************
 * Function Name: void release_air(void)
 * Specification: Releasing air from cuff
 *****************************************************************************/
void release_air(void)
{
    Valve_OpenClose = open;         // Open release valve
    OC1R = 0xffff;                  // Stop pump
    if (OC1CON1bits.OCM != 7) {
        OC1CON1bits.OCM = 7;        // Enable OC1/PWM1 for pump
    }
    one_long_beep();
}

/*****************************************************************************
  Function:
	void uitoa(WORD Value, BYTE* Buffer)

  Summary:
	Converts an unsigned integer to a decimal string.

  Description:
	Converts a 16-bit unsigned integer to a null-terminated decimal string.

  Precondition:
	None

  Parameters:
	Value	- The number to be converted
	Buffer	- Pointer in which to store the converted string

  Returns:
  	None
  ***************************************************************************/
void uitoa(WORD Value, BYTE* Buffer)
{
	BYTE i;
	WORD Digit;
	WORD Divisor;
	BOOL Printed = FALSE;

	if(Value)
	{
		for(i = 0, Divisor = 10000; i < 5u; i++)
		{
			Digit = Value/Divisor;
			if(Digit || Printed)
			{
				*Buffer++ = '0' + Digit;
				Value -= Digit*Divisor;
				Printed = TRUE;
			}
			Divisor /= 10;
		}
	}
	else
	{
		*Buffer++ = '0';
	}

	*Buffer = '\0';
}

/*****************************************************************************
 * Function Name: U1_write1byte(unsigned char value)
 * Specification: Write one byte to UART serial port
 *****************************************************************************/
void U1_write1byte (unsigned char value)
{
	while (!U1STAbits.TRMT);		//wait until Transmit Shift Register is empty
	U1TXREG = value;			//write 1 byte to serial port
}

/*****************************************************************************
 * Function Name: void str_Int(uint16_t i)
 * Specification: Converts integer to ASCII.
 *****************************************************************************/
void str_Int(uint16_t i)
{
    uint8_t ctr = 0;

    // Decimal Output
    while (i >= 10000)  { i -= 10000; ctr++; } U1_write1byte(ctr + 0x30); ctr = 0;
    while (i >=  1000)  { i -=  1000; ctr++; } U1_write1byte(ctr + 0x30); ctr = 0;
    while (i >=   100)  { i -=   100; ctr++; } U1_write1byte(ctr + 0x30); ctr = 0;
    while (i >=    10)  { i -=    10; ctr++; } U1_write1byte(ctr + 0x30); ctr = 0;
    while (i >=     1)  { i -=     1; ctr++; } U1_write1byte(ctr + 0x30);

    U1_write1byte(0x3b);
}

#ifdef U1WiFi
/*****************************************************************************
 * Function Name: Wait4RNresponse(void)
 * Specification: Wait for command response from RN171 module.
 *****************************************************************************/
void Wait4RNresponse(void)
{
    unsigned char junk;
    while (IFS0bits.U1RXIF == 0);
    junk = U1RXREG;
    IFS0bits.U1RXIF = 0;
    U1STAbits.OERR = 0;
}
/*****************************************************************************
 * Function Name: void U1_WiFi (void)
 * Specification: Send blood pressure result to WiFi
 *****************************************************************************/
void U1_WiFi (void)
{
    uitoa(Systolic_Pressure, SYS_String);
    uitoa(Diastolic_Pressure, DIA_String);
    uitoa(Heart_Rate, HR_String);

    // For display on WiFly Apps
/*
    sendChar2U1(0x0d);			//cr
    sendChar2U1(0x0a);                  //lf

    send2U1(SYS_symbol, 13);
    string_length = strlen(SYS_String);
    for (sl=0; sl<string_length; sl++) {
        sendChar2U1(SYS_String[sl]);
    }
    sendChar2U1(0x0d);			//cr
    sendChar2U1(0x0a);

    send2U1(DIA_symbol, 13);
    string_length = strlen(DIA_String);
    for (sl=0; sl<string_length; sl++) {
        sendChar2U1(DIA_String[sl]);
    }
    sendChar2U1(0x0d);			//cr
    sendChar2U1(0x0a);

    send2U1(PUL_symbol, 13);
    string_length = strlen(HR_String);
    for (sl=0; sl<string_length; sl++) {
        sendChar2U1(HR_String[sl]);
    }
    sendChar2U1(0x0d);			//cr
    sendChar2U1(0x0a);
*/
    //For display on Home Health Hub Webpage
    for (sl=0; sl<4; sl++)
    {
        if(SYS_String[sl] == 0x00)
        {
            SYS_String[sl] = 0x20;
        }
        sendChar2U1(SYS_String[sl]);
    }

    for (sl=0; sl<4; sl++)
    {
        if(DIA_String[sl] == 0x00)
        {
            DIA_String[sl] = 0x20;
        }
        sendChar2U1(DIA_String[sl]);
    }

    for (sl=0; sl<4; sl++)
    {
        if(HR_String[sl] == 0x00)
        {
            HR_String[sl] = 0x20;
        }
        sendChar2U1(HR_String[sl]);
    }
}
#endif

/*****************************************************************************
 * Function Name: void Calculate_BP(void)
 * Specification: Calculate blood pressure and heart rate.
 *****************************************************************************/
void Calculate_BP(void)
{
    unsigned char xs, xd;
    double Ad, As, tempD, tempD_diff, tempS, tempS_diff;

#ifdef Algorithm_2
//  Coefficient lookup table for blood pressure calculation
    //ks is the coefficient for Systolic Pressure
    if (MAP>200)                //lower ks to increase SYS, increase ks to lower SYS
        ks = 0.50;  //0.70
    else if (MAP<=200 && MAP>150)
        ks = 0.29;  //0.49
    else if (MAP<=150 && MAP>135)
        ks = 0.45;  //0.65
    else if (MAP<=135 && MAP>120)
        ks = 0.52;  //0.72
    else if (MAP<=120 && MAP>110)
        ks = 0.58;  //0.77
    else if (MAP<=110 && MAP>80)
        ks = 0.60;  //0.78
    else if (MAP<=80 && MAP>70)
        ks = 0.61;  //0.80
    else if (MAP<=70)
        ks = 0.64;  //0.84

    //kd is the coefficient for Distolic Pressure
    if (MAP>180)                //increase kd to increase DIA reading
        kd = 0.70;  //0.70
    else if (MAP<=180 && MAP>140)
        kd = 0.65;  //0.75
    else if (MAP<=140 && MAP>120)
        kd = 0.60;  //0.82
    else if (MAP<=120 && MAP>60)
        kd = 0.50;  //0.85
    else if (MAP<=60 && MAP>50)
        kd = 0.45;  //0.78
    else if (MAP<=50)
        kd = 0.40;  //0.60

    As = MAP_Amplitude * ks;    //for SYS
    Ad = MAP_Amplitude * kd;    //for DIA

    tempD = fabs(Ad - PulseAmplitude_Buf[0]);		//start comparaing
    xDIA = 0;
    for (xd=1; xd<xp; xd++)
    {
        tempD_diff = fabs(Ad - PulseAmplitude_Buf[xd]);
        if (tempD_diff < tempD)
        {
            xDIA = xd;
            tempD = tempD_diff;
        }
    }

    tempS = fabs(As - PulseAmplitude_Buf[xp+1]);
    xSYS = xp+1;
    for (xs=xp+2; xs<mx; xs++)
    {
        tempS_diff = fabs(As - PulseAmplitude_Buf[xs]);
        if ( tempS_diff < tempS)
        {
            xSYS = xs;
            tempS = tempS_diff;
        }
    }

//    printf_usb("%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;\r\n", 12, mx, xp, xDIA, xSYS, mx_temp, Osc_Peak_Buf[0], CP_Peak_Buf[xp], CP_Peak_Buf[xSYS], Osc_Peak_Buf[xSYS], CP_Peak_Buf[xDIA], Osc_Peak_Buf[xDIA]);

    Systolic_Pressure = CP_Peak_Buf[xSYS] * Gain_CP + pressure_offset;
    Diastolic_Pressure = CP_Peak_Buf[xDIA] * Gain_CP + pressure_offset;
#endif

    Heart_Rate = 60 * RR_Interval_Number * ADC_Sample_Rate / HR_ADCcounter;        // Heart_Rate = 60sec/(((1/ADCsampleRate)*HR_ADCcounter)/RRintervalNumber)

}

/*****************************************************************************
 * Function Name: void BPMDemoMenu(void)
 * Specification: BPM Demo Main Menu: (1)BPM (2)LastResult (3)CLOCK (4)Firmware Version (5)WiFi
 *****************************************************************************/
void BPMDemoMenu(void)
{
    int i;

    LCD37x7->iconMICROCHIP = 1;
    if (RN_Ready) LCD37x7->iconWIFI = 1;
    gcui->menu_state_max = MAX_STATE;
    switch(gcui->menu_state)
    {
        case BPM:       //Menu of blood pressure measurement
            strcpy(gcui->demo_title,"BPM");
            strcpy(gcui->demo_description,"S D H");     //S=SYS, D=DIA, H=HR
            gcui->submenu_state_max = 5;
            switch(gcui->submenu_state)
            {
                case menu_Start:
                    lcd_printf("Start");      // Press S2 button to start measuring
                    break;

                case menu_PumpAir:
                    mx = 0;                   // Reset buffer index
                    Error = 0;
                    MAP_temp_Max = 0;
                    PeakFound = 0;
                    overPressure = 0;
                    pressure_reading = 0;
                    pressure_reading0 = 0;
                    HR_ADCcounter = 0;
                    Systolic_Pressure_previous = Systolic_Pressure;     //update previous result
                    Diastolic_Pressure_previous = Diastolic_Pressure;   //update previous result
                    Heart_Rate_previous = Heart_Rate;                   //update previous result
                    Systolic_Pressure = 0;
                    Diastolic_Pressure = 0;
                    Heart_Rate = 0;
                    Target_Pressure_Set = 0;
                    Pulse_Detection_Enable = 0;
                    HRcounterFlag = 0;
                    ADC_sample_counts = 0;
                    usb_display = 0;

                    dataPulse[CURRENT] = 0;
                    dataCuff[CURRENT] = 0;
                    delta[CURRENT] = 0;
                    for (i = 0; i < FIR_PASSES; i++)
                    {
                        ClearAverage(maPulse[i]);
                        ClearAverage(maCuff[i]);
                    }
                    ClearAverage(maDelta);
                    state = 0;

                    one_short_beep();
                    one_short_beep();
                    pump_air(fast);           // Pumping air in fast mode
                    _AD1IF = 0;
                    _SL1IF = 0;
                    _AD1IE = 1;               // Enable ADC1 interrupt to start collecting ADC data
                    gcui->submenu_state = menu_Measuring;
                    if (gcui->btn_left_event) {gcui->submenu_state = menu_ReleaseAir;}  //Press S1 button to stop pump and release air
                    if (gcui->btn_right_event) {gcui->submenu_state = menu_ReleaseAir;} //Press S3 button to stop pump and release air
                    break;

                case menu_Measuring:
                    if (pressure_reading0 <= 0)
                    {
                        lcd_printf("mmHg");
                    }
                    else
                    {
                        lcd_printf("mmHg%d", pressure_reading);
                    }
                    if (PumpSpeed == fast)
                    {
                        if (pressure_offset > SpeedChange_Threshold) { SpeedChange_value = pressure_offset; }
                        else { SpeedChange_value = SpeedChange_Threshold; }
                        if (pressure_reading > SpeedChange_value)
                        {
                            pump_air(slow);     //Pumping air in slow mode
                        }
                    }
                    if (PeakFound)
                    {
                        PeakFound = 0;
                        LCD37x7->iconHEART = 1;
                        one_short_beep();
                        Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
                    }
                    if (overPressure)       //If cuff pressure >= 250mmHg then release air
                    {
                        _AD1IE = 0;         //Disable ADC1 interrupt
                        T4CONbits.TON = 0;  //Stop Timer4
                        gcui->submenu_state = menu_ReleaseAir;
                    }
                    if (gcui->btn_left_event) {gcui->submenu_state = menu_ReleaseAir;}
                    if (gcui->btn_right_event) {gcui->submenu_state = menu_ReleaseAir;}
                    break;

                case menu_ReleaseAir:
                    release_air();
                    _AD1IE = 0;             //Disable ADC1 interrupt
                    T4CONbits.TON = 0;      //Stop Timer4
                    gcui->submenu_state = menu_Result;
                    break;

                case menu_Result:
                    switch (Error)  //Checking to see if any errors occured
                    {
                        case 0:     //No error, send blood pressure result to WiFi
                            #ifdef U1WiFi
                            //debug++;                      //for debug purpose
                            //Systolic_Pressure = debug+1;  //for debug purpose
                            //Diastolic_Pressure = debug+2; //for debug purpose
                            //Heart_Rate = debug+3;         //for debug purpose
                            U1_WiFi();      //Send result to WiFi
                            #endif
                            Error = 1;
                            break;
                        case 1:     //No error, display blood pressure result on LCD
                            lcd_printf("%d %d %d", Systolic_Pressure, Diastolic_Pressure, Heart_Rate);
//                            lcd_printf("%d %d %d", Systolic_Pressure, Diastolic_Pressure, MAP);
//                            lcd_printf("MAP %d", MAP);
                            if (usb_display==0) {
                                //printf_usb("SYS:%d DIA:%d HR:%d\r\n", Systolic_Pressure, Diastolic_Pressure, Heart_Rate);
                                //printf_usb("%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;\r\n", Systolic_Pressure, Diastolic_Pressure, Heart_Rate, mx, xp, xSYS, xDIA, CP_Peak_Buf[xp], CP_Peak_Buf[xSYS], CP_Peak_Buf[xDIA], PulseAmplitude_Buf[xSYS], PulseAmplitude_Buf[xDIA], MAP_Amplitude);
                                //printf_usb("%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;\r\n", Systolic_Pressure, Diastolic_Pressure, Heart_Rate, mx, xp, xSYS, xDIA, CP_Peak_Buf[xp], CP_Peak_Buf[xSYS], CP_Peak_Buf[xDIA], PulseAmplitude_Buf[xSYS], PulseAmplitude_Buf[xDIA], MAP_Amplitude, MAP, Moving_Window, WindowCounter, maxCounter);
                                printf_usb("%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;\r\n", Systolic_Pressure, Diastolic_Pressure, Heart_Rate, mx, xp, xSYS, xDIA, CP_Peak_Buf[xp], CP_Peak_Buf[xSYS], CP_Peak_Buf[xDIA], PulseAmplitude_Buf[xSYS], PulseAmplitude_Buf[xDIA], MAP_Amplitude, MAP);
                                usb_display = 1;
                            }
                            break;
                        case 2:     //Error1 (over preset pressure limit) occured, display error message
                            lcd_printf("Err 1");
                            if (usb_display==0) {
                                printf_usb("Err 1: over pressure %d\r\n", pressure_reading);
                                usb_display = 1;
                            }
                            break;
                    }
            }
            break;

        case PreviousResult:    //Menu of previous result display
            strcpy(gcui->demo_title,"Previous");
            strcpy(gcui->demo_description,"Result");
            lcd_printf("%d %d %d", Systolic_Pressure_previous, Diastolic_Pressure_previous, Heart_Rate_previous);
            break;

        case CLOCK:         //Menu of RTCC
            strcpy(gcui->demo_title,"CLOCK");
            strcpy(gcui->demo_description,"HH:MM");
            gcui->submenu_state_max = 5;
            switch(gcui->submenu_state)
            {
                case 0:
                    rtcc_read(clock);
                    LCD37x7->blink_mask = BLINK_COLON;
                    break;
                case 1:
                    LCD37x7->blink_mask = BLINK_HOUR_T;
                    if(gcui->btn_left_event)  {rtcc_read(clock); clock->hour_tens--; rtcc_set(clock);}
                    if(gcui->btn_right_event) {rtcc_read(clock); clock->hour_tens++; rtcc_set(clock);}
                    break;
                case 2:
                    LCD37x7->blink_mask = BLINK_HOUR_O;
                    if(gcui->btn_left_event)  {rtcc_read(clock); clock->hour_ones--; rtcc_set(clock);}
                    if(gcui->btn_right_event) {rtcc_read(clock); clock->hour_ones++; rtcc_set(clock);}
                   break;
                case 3:
                    LCD37x7->blink_mask = BLINK_MIN_T;
                    if(gcui->btn_left_event)  {rtcc_read(clock); clock->min_tens--; rtcc_set(clock);}
                    if(gcui->btn_right_event) {rtcc_read(clock); clock->min_tens++; rtcc_set(clock);}
                   break;
                case 4:
                    LCD37x7->blink_mask = BLINK_MIN_O;
                    if(gcui->btn_left_event)  {rtcc_read(clock); clock->min_ones--; rtcc_set(clock);}
                    if(gcui->btn_right_event) {rtcc_read(clock); clock->min_ones++; rtcc_set(clock);}
                   break;
                default:
                    break;
            }
            lcd_printf("%02x:%02x",clock->hour,clock->min);
            //lcd_printf("%02x:%02x%c%c%c",clock->hour,clock->min,0x85,0x83,0x84);
            //lcd_printf("%s",__TIME__);
            break;

        case FirmwareVersion:    //Menu of Firmware Version display
            strcpy(gcui->demo_title,"Firmware");
            strcpy(gcui->demo_description,"Version");
//            lcd_printf(Firmware_Version);
            lcd_printf("%s_%s", SoftwareVer, HardwareVer);
            break;

        case WiFi:       //Menu of WiFi module RN171 control
            strcpy(gcui->demo_title,"WiFi");
            strcpy(gcui->demo_description,"Config");
            gcui->submenu_state_max = 4;
            switch(gcui->submenu_state)
            {
                case 0:
                    #ifdef U1WiFi
                    lcd_printf("S2=Join");  // Press S2 button to join WiFi network SSID: MPG_Demo_AP
                    #else
                    lcd_printf("N/A");
                    #endif
                    break;

                #ifdef U1WiFi
                case 1:
                    LCD37x7->iconWIFI = 0;
                    RN_CMD = 0;
                    RN_AOK = 0;
                    RN_save = 0;
                    RN_Ready = 0;
                    cmd_type = 0;
                    gcui->submenu_state = 2;
                    break;
                case 2:
                    //cmd_type = cmd_CMD;
                    send2U1 (CMD, 3);
                    Wait4RNresponse();
                    //while (!RN_CMD);
                    //cmd_type = cmd_set;
                    send2U1 (set_wlan_ssid, 26);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_wlan_phrase, 26);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_ip_host, 26);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_ip_remote, 19);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_ip_dhcp, 14);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_wlan_auth, 16);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_sys_autoconn, 19);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_uart_mode, 16);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_o_d, 12);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_comm_remote, 18);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_comm_idle, 16);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    send2U1 (set_wlan_join, 16);
                    Wait4RNresponse();
                    //while (!RN_AOK);
                    //RN_AOK = 0;
                    //cmd_type = cmd_save;
                    send2U1 (SAVE, 5);
                    Wait4RNresponse();
                    //while (!RN_save);
                    cmd_type = cmd_reboot;
                    send2U1 (REBOOT, 7);
                    //Wait4RNresponse();
                    //while (!RN_Ready);
                    gcui->submenu_state = 3;
                    break;
                case 3:
                    if (RN_Ready == 0)
                    {
                        lcd_printf("%.*s", ji, joining);
                        for(delayWF=0;delayWF<1000;delayWF++);
                        ji++;
                        if (ji>=8) ji=1;
                    }
                    else    //RN_Ready==1
                    {
                        lcd_printf("Ready");
                        LCD37x7->iconWIFI = 1;
                    }
                    break;
                #endif
            }
            break;
    }
}

extern void ui_callback_set_scroll_speed(uint32_t Fosc, uint32_t f)
{
    T1CON = timer_auto_TxCON(Fosc, f);
    PR1   = timer_auto_PRx(Fosc,   f); 
    _T1IF = 0;
    _T1IE = 1;
}

//**********************************************************************
// Interrupt Service Routine
//**********************************************************************
#define _MyISR __attribute__((__interrupt__,__auto_psv__))

#define T1_INTERRUPT_RATE 42/*Hz*/
void _MyISR _T1Interrupt(void)
{
    ui_tasks(gcui);
    lcd_canvas_raster(LCD37x7);

    gcui->button_state[0] = MTouchGetButtonState(0);
    gcui->button_state[1] = MTouchGetButtonState(1);
    gcui->button_state[2] = MTouchGetButtonState(2);

    _T1IF = 0;
}

#define T2_INTERRUPT_RATE   ADC_Sample_Rate/*Hz*/
void _MyISR _T2Interrupt(void)
{
    //printf_usb("%04x\t%04x\t%04x\t%04x\t%04x\t%04x\t%04x\n\r",ADRES0,ADRES1,ADRES2,ADRES3,ADRES4,ADRES5,ADRES6);
    _T2IF = 0;
}

#define T3_INTERRUPT_RATE 5000/*Hz*/
void _MyISR _T3Interrupt(void)
{   
    MTouchAcquisition();
    MTouchDecode();
    _T3IF = 0;
}

void _MyISR _T4Interrupt(void)
{
    TMR4_counter++;
    _T4IF = 0;      // Clear Timer Interrupt Flag
}
/*
void _MyISR _CompInterrupt(void)
{
    if (CMSTATbits.C2EVT)
    {
        CM2_counter++;
        CM2CONbits.CEVT = 0;    //Clear comparator event bit
        _CMIF = 0;              //Clear Comparator Interrupt Flag
    }
}
*/
void _MyISR _RTCCInterrupt(void)
{
    asm volatile("disi #0x3fff");
    LCD37x7->half_sec ^= 1;
    if(gcui->menu_state == CLOCK) {
        LCD37x7->blink_enable ^= 1;
    } else {
        LCD37x7->blink_enable = 0;
    }
    rtcc_read(clock);
    _RTCIF = 0;
    asm volatile("disi #0x0");
    sleep_wake();
    sleep_go();
}

void __attribute__((__interrupt__, no_auto_psv)) _OC1Interrupt(void)
{
    Wheel_Position(w);
    if (wheel_counter == 1000)
    {
        if (w < 10) { w++; }
        else { w = 0; }
        wheel_counter = 0;
    }
    wheel_counter++;
    _OC1IF = 0;
}

#ifdef U1WiFi
void __attribute__((__interrupt__,no_auto_psv)) _U1RXInterrupt(void)
{
    unsigned char dataIn;

    if (U1STAbits.OERR == 1)
        U1STAbits.OERR = 0;

    while(U1STAbits.URXDA) //If Rx FIFO buffer has data
    {
        dataIn = U1RXREG;

        switch (cmd_type)
        {
            case cmd_reboot:
                switch (U1RX_State)
                {
                    case 0:
                        if (dataIn == '*')
                        {
                            U1RX_State = 1;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                    case 1:
                        if (dataIn == 'O')
                        {
                            U1RX_State = 2;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                    case 2:
                        if (dataIn == 'P')          //*OPEN* is received -> Turn on WiFi logo.
                        {
                            RN_Ready = 1;
                            U1RX_State = 0;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                }
                break;

            case cmd_CMD:     //cmd_$$$
                switch (U1RX_State)
                {
                    case 0:
                        if (dataIn == 'C')
                        {
                            U1RX_State = 1;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                    case 1:
                        if (dataIn == 'M')
                        {
                            U1RX_State = 2;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                    case 2:
                        if (dataIn == 'D')
                        {
                            RN_CMD = 1;     //CMD is responsed
                            U1RX_State = 0;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                }
                break;

            case cmd_set:     //cmd_set
                switch (U1RX_State)
                {
                    case 0:
                        if (dataIn == 'A')
                        {
                            U1RX_State = 1;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                    case 1:
                        if (dataIn == 'O')
                        {
                            U1RX_State = 2;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                    case 2:
                        if (dataIn == 'K')
                        {
                            RN_AOK = 1;     //AOK is responsed
                            U1RX_State = 0;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                }
                break;

            case cmd_save:     //cmd_save
                switch (U1RX_State)
                {
                    case 0:
                        if (dataIn == 'S')
                        {
                            U1RX_State = 1;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                    case 1:
                        if (dataIn == 't')
                        {
                            U1RX_State = 2;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                    case 2:
                        if (dataIn == 'o')
                        {
                            RN_save = 1;    //Sto is responsed
                            U1RX_State = 0;
                        }
                        else
                        {
                            U1RX_State = 0;
                        }
                        break;
                }
                break;
        }
    }
    IFS0bits.U1RXIF = 0;	//Clear UART_Rx interrupt flag
}
#endif

//Functions for 2-stage 32-point moving average filter.
moving_average* NewMovingAverage(uint16_t _size)
{
	moving_average* _this;
	_this = (moving_average*)malloc(sizeof(moving_average));
	_this->size = _size;
	_this->reg = (int32_t*)malloc(_size * sizeof(int32_t));
	_this->position = 0;
	_this->sum = 0;
	return _this;
}

void DestroyMovingAverage(moving_average* _this)
{
	free (_this->reg);
	free (_this);
}

int16_t MoveAverage(moving_average* _this, int16_t input)
{
	int16_t output;
	_this->sum -= _this->reg[_this->position];
	_this->sum += input;
	_this->reg[_this->position] = input;
	_this->position++;
	_this->position %= _this->size;
	output = _this->sum / (int32_t) _this->size;
	return output;
}

void ClearAverage(moving_average* _this)
{
	int i;
	_this->sum = 0;
	for (i = 0; i < _this->size; i++)
	{
            _this->reg[i] = 0;
	}
}

int16_t FilterPass(int16_t input, moving_average** filters, int16_t passes)
{
	int16_t output;

	if (passes == 0)
	{
		output = input;
	}
	else
	{
		passes--;
		output = MoveAverage(filters[passes], FilterPass(input, filters, passes));
	}
	return output;
}

// ADC sampling rate 500Hz (500 samples/second), triggered by Timer2 interrrupt, defined by T2_INTERRUPT_RATE.
// Each ADC data must be acquired and processed within 2ms before next ADC data comes in.
void _MyISR _ADC1Interrupt(void)
{
    if (_SL1IF)      //AD Sample List 1 interrupt event occurred indicating AD results are ready
    {
//        _RG7 = 1;   // for debugging, disable UART1 module first.
        ADC1_new_raw = ADRES1;      //Channel1(ADC1) = Cuff pressure
        ADC2_new_raw = ADRES2;      //Channel2(ADC2) = Extracted oscillation signal

        dataPulse[PREVIOUS] = dataPulse[CURRENT];
        dataCuff[PREVIOUS] = dataCuff[CURRENT];
        delta[PREVIOUS] = delta[CURRENT];
        rawDataPulse = (int16_t)ADRES2 << (int16_t)3;   //raw ADC data * 8
        rawDataCuff = (int16_t)ADRES1 << (int16_t)3;    //raw ADC data * 8
        dataPulse[CURRENT] = FilterPass(rawDataPulse, maPulse, FIR_PASSES); //Retrieve and filter ADC data
        //delta[CURRENT] = dataPulse[CURRENT] - dataPulse[PREVIOUS];
        delta[CURRENT] = MoveAverage(maDelta, dataPulse[CURRENT] - dataPulse[PREVIOUS]);

        dataCuff[CURRENT] = FilterPass(rawDataCuff, maCuff, FIR_PASSES); //Retrieve and filter ADC data

        //printf_usb("%05d;%05d;%05d;%05d;\r\n", rawDataCuff, rawDataPulse, dataCuff[CURRENT], dataPulse[CURRENT]);

        //SpanVoltage_kPa = ADC1_temp * (3.3/4096) * 1000 * 37 / 31 / 151;    //Span Voltage is 31mV@37kPa for 2SMPP-02.
        //SpanVoltage_kPa = ADC1_temp * (3.3/4096) * 1000 * 50 / 42 / 151;    //Span Volgtage is 42mV@50kPa for 2SMPP-03.
        //SpanVoltage_kPa = ADC1_temp * 0.006;        //Gain1=151
        //SpanVoltage_kPa = ADC1_temp * 0.0095 + 3.5;   //Gain1=101, 2SMPP-02, SpanVoltage_kPa = ADC1_temp * (3.3/4096) * 1000 * 37 / 31 / 101; 3.5=Offset
        //pressure_reading = (ADC1_temp * 0.07 + 26.25) + pressure_offset;      //pressure_reading = SpanVoltage_kPa * 7.5; -> Convert kPa to mmHg, 1kPa=760/101.325=7.5mmHg
        
        //Gain1 is reduced from 151 to 101 so that 12-bit ADC (4096) with 3.3V Vref+ can cover enough pressure range up to 280mmHg.
        //SpanVoltage_kPa = ADC1_temp * (3.3/4096) * 1000 * 37 / 31 / 101;    //Span Voltage is 31mV@37kPa for 2SMPP-02.
        //-> pressure_reading = SpanVoltage_kPa * 7.5; -> Convert kPa to mmHg, 1kPa=760/101.325=7.5mmHg
        //-> pressure_reading = ADC1_temp * (3.3/4096) * 1000 * 37 / 31 / 101 * 7.5 ~= ADC1_temp * 0.07
        //pressure_reading = ADC1_temp * Gain_CP + pressure_offset;

        pressure_reading0 = (dataCuff[CURRENT]/8) * Gain_CP;
        pressure_reading = pressure_reading0 + pressure_offset;

        //printf_usb("ADC1:%05d,mmHg:%05d,kPa:%05d\r\n", ADC1_temp,pressure_reading,SpanVoltage_kPa);
        //printf_usb("%05d;%05d;%05d;%05d;%05d;%05d;\r\n", pressure_reading, ADC1_temp, ADC2_temp, Osc_Peak_Buf[mx-1], CP_Peak_Buf[mx-1], PulseAmplitude_Buf[mx-1]);
        //printf_usb("%05d;%05d;%05d;%05d;%05d;\r\n", pressure_reading, rawDataCuff, rawDataPulse, dataCuff[CURRENT], dataPulse[CURRENT]);

        if (PumpSpeed==slow)
            ADC_sample_counts++;

        if (ADC_sample_counts > 500)       //Enable pulse detection process 500 adc counts after changing to low speed pumping.
            Pulse_Detection_Enable = 1;

        if (Pulse_Detection_Enable)
        {
            switch (state)
            {
                case 0:
                    if (delta[CURRENT] >= UPPER_THRESHOLD)   //Steep up slope?
                    {
                        state = 1;
                    }
                    break;
                case 1:
                    if (delta[PREVIOUS] > 0 && delta[CURRENT] <= 0) // Peak value?
                    {
                        peakValue = dataPulse[PREVIOUS];
                        valueCuff = dataCuff[PREVIOUS];
                        state = 2;
                    }
                    break;
                case 2:
                        if (delta[CURRENT] <= LOWER_THRESHOLD) // Steep down slope?
                    {
                        //PeakFound = 1;
                        //pulseHigh = peakValue;
                        state = 3;
                    }
                    else if (delta[CURRENT] > 0)
                    {
                        state = 0;
                    }
                    break;
                case 3:
                    if (delta[PREVIOUS] < 0 && delta[CURRENT] >= 0) // Trough value?
                    {
                        //Save or output pulseHigh, pulseLow, and valueCuff
                        if (peakValue - dataPulse[PREVIOUS] > AMPLITUDE_THRESHOLD)
                        {
                            PeakFound = 1;

                            pulseHigh = peakValue;
                            pulseLow = dataPulse[PREVIOUS];
                            pulseHigh_Buf[mx] = pulseHigh;
                            pulseLow_Buf[mx] = pulseLow;
                            CP_Peak_Buf[mx] = valueCuff / 8;
                            Pulse_Amplitude = pulseHigh - pulseLow;
                            PulseAmplitude_Buf[mx] = Pulse_Amplitude;

                            mx++;

                            if (pressure_reading >= 70)
                            {
                                HRcounterFlag++;
                            }
                            if (!Target_Pressure_Set)
                            {
                                if (Pulse_Amplitude > MAP_temp_Max)     //USe the largest pulse_amplitude to determine MAP location
                                {
                                    MAP_temp_Max = Pulse_Amplitude;     //USe the largest pulse_amplitude to determine MAP location
                                    MAP_Sample_Window_Counter = MAP_Sample_Window_Interval;  //number of pulse peaks needed after peak Max is found
                                    xp = mx-1;  //buffer index for MAP = current index - 1
                                }
                                else
                                {
                                    MAP_Sample_Window_Counter--;
                                    if (MAP_Sample_Window_Counter == 0)
                                    {
                                        MAP = CP_Peak_Buf[xp] * Gain_CP + pressure_offset;
                                        MAP_Amplitude = PulseAmplitude_Buf[xp];
                                        Target_Pressure = CP_Peak_Buf[xp] * Gain_CP + pressure_offset;     //MAP pressure
                                        Target_Pressure = Target_Pressure * 1.5;    //1.6
                                        Target_Pressure_Set = 1;
                                        MAP_temp_Max = 0;
                                    }
                                }
                            }
                        }
                        state = 0;
                    }
                    break;
                default:
                    break;
            }
            //printf_usb("%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;\r\n", pressure_reading, rawDataCuff, rawDataPulse, dataCuff[CURRENT], dataPulse[CURRENT], pulseHigh, pulseLow, valueCuff, state, delta[CURRENT], CP_Peak_Buf[mx-1], PulseAmplitude_Buf[mx-1]);
            //printf_usb("%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;\r\n", pressure_reading, rawDataCuff, rawDataPulse, dataCuff[CURRENT], dataPulse[CURRENT], pulseHigh, pulseLow, CP_Peak_Buf[mx-1], PulseAmplitude_Buf[mx-1]);
            printf_usb("%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;%05d;\r\n", pressure_reading, dataCuff[CURRENT], dataPulse[CURRENT], pulseHigh, pulseLow, CP_Peak_Buf[mx - 1], PulseAmplitude_Buf[mx - 1], state, delta[CURRENT]);
        }

        if ((HRcounterFlag >= 1) && (HRcounterFlag <= RR_Interval_Number))   //For example, wait for four pulses - three intervals
        {
            HR_ADCcounter++;
        }
        if (Target_Pressure_Set)
        {
            if (pressure_reading >= Target_Pressure)    //If cuff pressure >= Target_Pressure then go to calculate BP and release air
            {
                overPressure = 1;
                Error = 0;  //no error
                Calculate_BP();
            }
        }
        if (pressure_reading >= overPressure_limit)    //If cuff pressure >= overPressure_Limit then go to release air and display error message
        {
            overPressure = 1;
            Error = 2;  //Err2=over preset pressure limit
        }

//        _RG7 = 0;   // for debugging
    }
    _AD1IF = 0;
    _SL1IF = 0;
}

/*****************************************************************************
 * Function Name: void send2U1(unsigned char* Uart_Output, unsigned int sz)
 * Specification: Send string to U1TX
 *****************************************************************************/
void send2U1(unsigned char* Uart_Output, unsigned char sz)  // str is "\0" terminated string
{
    while (sz)
    {
        while (U1STAbits.UTXBF);	// wait when TX buffer full
	U1TXREG = *Uart_Output++;
	sz--;
	Nop();
        Nop();
    }
}

/*****************************************************************************
 * Function Name: void sendChar2U1(unsigned char ch)
 * Specification: Send 1 byte to U1TX
 *****************************************************************************/
void sendChar2U1(unsigned char ch)
{
    while (U1STAbits.UTXBF); // wait when TX buffer full
    U1TXREG = ch;
}

/*****************************************************************************
 * Function Name: void CTMU_current_cal(void)
 * Specification: Set up CTMU to output 100uA constant current to pressure sensor
 *****************************************************************************/
void CTMU_current_cal(void)
{
    int i;
    // Set up AD converter
    ANSBbits.ANSB2 = 1;	// AN2/RB2 is configured to analog
    PORTBbits.RB2 = 0;
    LATBbits.LATB2 = 0;
    TRISBbits.TRISB2 = 1;
    ADTBL0 = 2;		//Select ADC channel AN2/RB2

    CTMUCON1 = 0x1000; //make sure CTMU is disabled
    CTMUCON2 = 0xC0C0;
    CTMUICONbits.ITRIM = 0b100001;
    CTMUICONbits.IRNG = 0;

    CTMUCON1bits.CTMUEN = 1; //Enable the CTMU
    CTMUCON1bits.IDISSEN = 1; //drain charge on the circuit
//  DELAY; //wait 125us
    for (i=0; i<1000; i++);
    CTMUCON1bits.IDISSEN = 0; //end drain of circuit
    CTMUCON2bits.EDG1STAT = 1; //Begin charging the circuit
}

/*****************************************************************************
 * Function Name: void USB_Command()
 * Specification: Start/Stop measuring process in USB terminal
 *****************************************************************************/
void USB_Command()
{
    switch(CMD_HDR)
    {
        case '1':       //Key in 1 to start measuring process.
            gcui->menu_state=BPM;
            clock->min_ones=0;
            clock->sec_ones=0;
            clock->sec_tens=0;
            rtcc_set(clock);
            gcui->submenu_state=menu_PumpAir;
            break;
        default:        //Key in anything other than 1 to stop measuring process.
            gcui->submenu_state=menu_ReleaseAir;
            break;
    }
}

/*****************************************************************************
 * Function Name: void Init(void)
 * Specification: Initialize BPM demo board related functions
 *****************************************************************************/
void Init(void)
{
    PORTGbits.RG7 = 0;
    LATGbits.LATG7 = 0;
    TRISGbits.TRISG7 = 0;
    
    //**********************************************************************
    // Initialize Oscillator, FRC with PLL
    // FRC=8MHz -> /1=8MHz(RCDIV=0) -> /2=4MHz(PLLDIV=1) -> 96MHz PLL -> /3=32MHz -> /1=32MHz=Fosc(CPDIV=0)
    // Fosc=32MHz, Fcy=Fosc/2=16MHz
    //**********************************************************************
    CLKDIVbits.RCDIV = 0;	//FRC postscaler 8MHz
    CLKDIVbits.CPDIV = 0;       //System Clock (Fosc) is 32 MHz

    //**********************************************************************
    // Initialize DAC1 Module for DC_offset
    //**********************************************************************
    ANSGbits.ANSG9 = 1;		// AN49/RG9 is configured to analog
    PORTGbits.RG9 = 0;
    LATGbits.LATG9 = 0;
    TRISGbits.TRISG9 = 0;
    DAC1DAT = 427;		//Set DAC1 output voltage. 427=1V,
    DAC1CON = 0x0080;           //Set bit 7 high
    DAC1CONbits.DACTRIG = 0;
    DAC1CONbits.DACREF = 3;	//2.4V internal band gap
    BUFCON0bits.BUFREF = 0;	//Internal voltage reference output set at 1.2V
    BUFCON0bits.BUFSTBY = 0;	//Buffer output works normally
    BUFCON0bits.BUFEN = 1;	//Vref enabled
//    DAC1CONbits.DACOE = 1;
    DAC1CONbits.DACEN = 1;      //Enable DAC module
    
    //**********************************************************************
    // Initialize Output Compare 1 module for PWM mode to control Air Pump
    //**********************************************************************
    ANSDbits.ANSD0 = 0;				// AN43/RD0/Pin72 is configured to digital
    PORTDbits.RD0 = 0;
    LATDbits.LATD0 = 0;
    TRISDbits.TRISD0 = 0;
    __builtin_write_OSCCONL(OSCCON & 0xBF);
    RPOR5bits.RP11R = 18;			// RP11/RD0/Pin72 tied to OC1
    __builtin_write_OSCCONL(OSCCON | 0x40);
    OC1CON1bits.OCM = 0;			// Disable the Output Compare 1 mode
    OC1R = 0xffff;				// Calculate the desired duty cycles and load them into the OCxR register. (Pump)0x01ff=50% Duty Cycle.
    OC1RS = 0x03ff;				// Calculate the desired period and load it into the OCxRS register. With Fcy=16MHz, (Pump)PWM Freq=15.6kHz->OCxRS=0x03ff.
    OC1CON2bits.SYNCSEL = 0x1f;
    OC1CON2bits.OCTRIG = 0;
    OC1CON1bits.OCTSEL = 7;			// Select clock source - Peripheral clock (FCY)
    OC1CON2bits.OCTRIS = 0;
    _OC1IF = 0;
    _OC1IE = 1;

    //**********************************************************************
    // Initialize Valve control
    //**********************************************************************
    PORTEbits.RE7 = 0;				// RE7/Pin5 is used to open/close the release valve
    LATEbits.LATE7 = 0;
    TRISEbits.TRISE7 = 0;

    //**********************************************************************
    // Initialize Output Compare 3 module for PWM mode to control Buzzer
    //**********************************************************************
    PORTDbits.RD1 = 0;
    LATDbits.LATD1 = 0;
    TRISDbits.TRISD1 = 0;
    __builtin_write_OSCCONL(OSCCON & 0xBF);
    RPOR12bits.RP24R = 20;			// RP24/RD1/Pin76 tied to OC3
    __builtin_write_OSCCONL(OSCCON | 0x40);
    OC3CON1bits.OCM = 0;			// Disable the Output Compare 3 mode
    OC3R = 0x07ff;				// Calculate the desired duty cycles and load them into the OCxR register. (Buzzer)0x07ff=50% dc.
    OC3RS = 0x0fff;				// Calculate the desired period and load it into the OCxRS register. With Fcy=16MHz, (Buzzer)PWM Freq=3.9kHz->OCxRS=0x0fff.
    OC3CON2bits.SYNCSEL = 0x1f;
    OC3CON2bits.OCTRIG = 0;
    OC3CON1bits.OCTSEL = 7;			// Select clock source - Peripheral clock (FCY)
    OC3CON2bits.OCTRIS = 0;

    //**********************************************************************
    // Initialize Op-Amp 2 Module for analog filter
    //**********************************************************************
    ANSFbits.ANSF4 = 1;				// AN11/RF4 is configured to analog for OPA2N3.
    PORTFbits.RF4 = 0;
    LATFbits.LATF4 = 0;
    TRISFbits.TRISF4 = 1;
    ANSFbits.ANSF5 = 0;				// AN10/RF5 is configured to analog for OPA2P2.
    PORTFbits.RF5 = 0;
    LATFbits.LATF5 = 0;
    TRISFbits.TRISF5 = 1;
    ANSBbits.ANSB3 = 0;				// AN3/RB3 is configured to analog for OPA2O.
    PORTBbits.RB3 = 0;
    LATBbits.LATB3 = 0;
    TRISBbits.TRISB3 = 0;

    AMP2CON = 0x00c0;				// Disable Op-Amp, High Power configuration, Amplifier output is sent to a pin (OPA2O/Pin22)
    AMP2CONbits.NINSEL = 4;			// Op-Amp (-) Inverting Input is OPA2N3/Pin49
    AMP2CONbits.PINSEL = 3;			// Op-Amp (+) Non-Inverting Input is OPA2P2/Pin50
    AMP2CONbits.AMPEN = 1;			// Enable Op-Amp module

    //**********************************************************************
    // Initialize UART 1 Module (9600/8-N-1 for U1WiFi)
    // A serial port optical isolator may be required due to noise on TX/RX line.
    //**********************************************************************
/*
    ANSGbits.ANSG7 = 0;				// RG7/RP26 is configured to digital for U1TX
    PORTGbits.RG7 = 0;
    LATGbits.LATG7 = 0;
    TRISGbits.TRISG7 = 0;
    ANSCbits.ANSC1 = 0;				// RC1/RPI38 is configured to digital for U1RX
    PORTCbits.RC1 = 0;
    LATCbits.LATC1 = 0;
    TRISCbits.TRISC1 = 1;
    __builtin_write_OSCCONL(OSCCON & 0xBF);
    RPOR13bits.RP26R = 3;			// RP26/RG7/Pin11 tied to U1TX
    RPINR18bits.U1RXR = 38;			// RPI38/RC1/Pin6 tied to U1RX
    __builtin_write_OSCCONL(OSCCON | 0x40);
    U1MODE = 0x8008; 	 // Uart1 is enabled, BRGH=1, 1 stop and no parity, simplex mode
    U1BRG = 416;  	 // Baud rate 9600 w/ Fcy=16MHz, BRGH=1, 16000000/9600/4-1=416
    IFS0bits.U1RXIF = 0;
    IEC0bits.U1RXIE = 1; // Enable U1RX interrupt
    U1STA = 0x0400;  	 // Transmit Enabled
*/
    //**********************************************************************
    // Initialize IOs & Comparator Module 2 & Comparator Voltage Reference for controlling pump speed optical sensor
    //**********************************************************************
    ANSGbits.ANSG8 = 1;     //RA8 is configured to analog
    PORTGbits.RG8 = 0;
    LATGbits.LATG8 = 0;
    TRISGbits.TRISG8 = 1;   //Set RG8 to input, it's tied to C2IND
    ANSAbits.ANSA7 = 0;     //RA7 is configured to digital
    PORTAbits.RA7 = 0;
    LATAbits.LATA7 = 0;
    TRISAbits.TRISA7 = 0;   //Set RA7 to output
    _RA7 = 1;               //Turn on IR photodiode

    CM2CONbits.COE = 0;     //Comparator output is internal only
    CM2CONbits.CPOL = 1;    //Comparator output is inverted (1=Vin+<Vin-, 0=Vin+>Vin-)
    CM2CONbits.EVPOL = 2;   //Trigger on Low-to-high transition only
    CM2CONbits.CREF = 1;    //Non-inverting input (Vin+) connects to CVref
    CM2CONbits.CCH = 2;     //Inverting input (Vin-) connects to CxIND pin
    CM2CONbits.CEVT = 0;    //Clear comparator event bit

    CVRCONbits.CVREFP = 0;  //CVRx (5-bit DAC) provides the reference voltage
    CVRCONbits.CVROE = 0;   //CVref voltage is disconnected from the CVref pin
    CVRCONbits.CVRSS = 0;   //CVrsrc = AVdd - AVss
    CVRCONbits.CVR = 19;    //CVref = (CVR<4:0>/32)*CVrsrc = 19/32*3.3 ~= 2V
//    CVRCONbits.CVREN = 1;   //CVref is powered on

//    CM2CONbits.CEN = 1;     //Enable Comparator
    _CMIP = 5;              //Comparator Interrupt Priority
    _CMIF = 0;              //Clear comparator interrupt flag
    _CMIE = 1;              //Enable Comparator Interrupt
}

/****************************************************************************
*****************************************************************************
*
* MAIN FUNCTION
*
*****************************************************************************
*****************************************************************************/
int main() 
{
    unsigned char len=0;

#ifdef U1WiFi
    RN_Ready = 0;
    cmd_type = cmd_reboot;
#endif

    Init();

    //**********************************************************************
    // Initialize FIR Lowpass Filter
    //**********************************************************************
    int i;
    for (i = 0; i < FIR_PASSES; i++)
    {
        maPulse[i] = NewMovingAverage(FIR_SIZE);
        maCuff[i] = NewMovingAverage(FIR_SIZE);
    }
    maDelta = NewMovingAverage(3);

    //**********************************************************************
    // Initialize ADC
    //**********************************************************************
    SampleList sl_periph = {
        .ADLnCONH.SAMC = 0x1F,
        .ADLnCONH.MULCHEN = 0,
        .ADLnCONH.PINTRIS = 0,
        .ADLnCONH.CTMEN = 0,
        .ADLnCONH.CM = 0,
        .ADLnCONH.WM = 0,
        .ADLnCONH.SLINT = 1,
        .ADLnCONH.ASEN = 1,

        .ADLnCONL.SLSIZE = 2,   // number of adc input channel
        .ADLnCONL.THSRC = 0,
        .ADLnCONL.SLTSRC = 5,   // 5 = TMR2
        .ADLnCONL.SLENCLR = 0,
        .ADLnCONL.SAMP = 0,
        .ADLnCONL.SLEN = 1, 

        .ADLnSTAT.ADLIF = 0,
        .ADLnSTAT.ADTDLY = 0,
        .ADLnSTAT.LBUSY = 0,
        .ADLnSTAT.ADTACT = 0,

        .ADLnPTR.ADNEXT = 0,

        .ADTHnL = 0,
        .ADTHnH = 0,
        .ADLnMSEL0 = 0,
        .ADLnMSEL1 = 0,
        .ADLnMSEL2 = 0,
        .ADLnMSEL3 = 0
    };

    _ADTBLn SampleTableEntry[] = {   
        [0]={.DIFF = 0, .UCTMU = 0, .ADCH = 50},  // mTouchSL0 50 is arbitrary. the Library will change this value.
        [1]={.DIFF = 0, .UCTMU = 0, .ADCH = 0},   // AN0=ADC1
        [2]={.DIFF = 0, .UCTMU = 0, .ADCH = 17},  // AN17=ADC2
    };
    _AD1IP = 5;
    _AD1IF = 0;
    _SL1IF = 0;

    //**********************************************************************
    // Initialize mTouch
    //**********************************************************************
    MTouchInit();               // Call MTouchInit() before our custom settings
    CTMU_current_cal();		// Output 100 uA constant current to pressure sensor

    MTouchSetSensor(0, CH0_TRIS, CH0_LAT, CH0_IO_BIT, CH0_AN_NUM, 1000, -1, -1);  // sensor #0
    MTouchSetSensor(1, CH1_TRIS, CH1_LAT, CH1_IO_BIT, CH1_AN_NUM, 1000, -1, -1);  // sensor #1
    MTouchSetSensor(2, CH2_TRIS, CH2_LAT, CH2_IO_BIT, CH2_AN_NUM, 1000, -1, -1);  // sensor #2
    MTouchSetButton(0, 0, DECODE_PRESS_RELEASE);
    MTouchSetButton(1, 1, DECODE_PRESS_RELEASE);
    MTouchSetButton(2, 2, DECODE_PRESS_RELEASE);

    adc_pipeline_config_begin();
    adc_pipeline_sl_assign(1,&sl_periph);
    adc_pipeline_sample_table_set(SampleTableEntry,sizeof(SampleTableEntry)/sizeof(_ADTBLn)); 
    adc_pipeline_config_end();

    //**********************************************************************
    // Initialize Timers
    //**********************************************************************
    // Initialize Timer 1 (control ui function, LCD refresh)
    T1CON = timer_auto_TxCON(FOSC, T1_INTERRUPT_RATE);
    PR1   = timer_auto_PRx(FOSC,   T1_INTERRUPT_RATE);
    _T1IP = 4;
    _T1IF = 0;
    _T1IE = 1;

    // Initialize Timer 2 (control ADC sample rate)
    T2CON = timer_auto_TxCON(FOSC, T2_INTERRUPT_RATE);
    PR2   = timer_auto_PRx(FOSC,   T2_INTERRUPT_RATE);
    _T2IP = 5;
    _T2IF = 0;
    _T2IE = 1;

    // Initialize Timer 3 (control mTouch scanning time)
    T3CON = timer_auto_TxCON(FOSC, T3_INTERRUPT_RATE);
    PR3   = timer_auto_PRx(FOSC,   T3_INTERRUPT_RATE); 
    _T3IP = 6;
    _T3IF = 0;
    _T3IE = 1;

    // Initialize Timer 4 (control extra delay time and HR counter)
    T4CONbits.TON = 0;
    T4CONbits.TCS = 0;
    T4CONbits.TCKPS = 1;
    TMR4 = 0;
    PR4 = 0xffff;
    _T4IP = 5;
    _T4IF = 0;
    _T4IE = 1;		// Enable Timer interrupte

    //**********************************************************************
    // Initialize USB
    //**********************************************************************
    _USB1IF = 0;
    _USB1IP = 6;
    _USB1IE = 1;
    USBDeviceInit();

    //**********************************************************************
    // Initialize LCD
    //**********************************************************************
    LCDPSbits.WFT = 0;
    LCDPSbits.LP = 2;
    LCDCONbits.LMUX = 0x07;
    LCDCONbits.CS = 3;
    LCDREGbits.CKSEL = 2;
    LCDREGbits.MODE13 = 1;
    LCDREGbits.BIAS = 7;
    LCDREGbits.CPEN = 1;
    LCDREFbits.LRLAP = 0x03;
    LCDREFbits.LRLBP = 0x03;
    LCDREFbits.LRLAT = 0x03;
    LCDREFbits.LCDIRE = 1;
    LCDREFbits.LCDCST = 2;
    LCDCONbits.LCDEN = 1;

    //**********************************************************************
    // Initialize RTCC
    //**********************************************************************
    asm volatile("DISI #0x3fff");
    __builtin_write_RTCWEN();
    asm volatile("DISI #0");
    RTCPWCbits.RTCLK = 0; // SOSC
    RCFGCALbits.RTCPTR = 3;
    RCFGCALbits.RTCOE = 0;
    ALCFGRPTbits.AMASK = 0; // 1/2s alarm
    ALCFGRPTbits.CHIME = 1; // Chime enabled
    ALCFGRPTbits.ALRMEN = 1; // Alarm enabled
    RCFGCALbits.RTCEN = 1; 
    _RTCIF = 0;
    _RTCIP = 6;
    _RTCIE = 1;

    clock = (rtcc *)rtcc_new();
    char *time = __TIME__;
    clock->hour_tens = time[0]-'0';
    clock->hour_ones = time[1]-'0';
    clock->min_tens  = time[3]-'0';
    clock->min_ones  = time[4]-'0';
    rtcc_set(clock);
    rtcc_read(clock);

    //**********************************************************************
    // Others
    //**********************************************************************
    LCD37x7 = (lcd *)lcd_new();
    gcui = (ui *)ui_new(BPMDemoMenu);
    gcui->menu_state = BPM;
    gcui->p_lcd = LCD37x7;
    gcui->Fosc = FOSC;
    gcui->refresh_rate_while_scrolling = 42;
    gcui->refresh_rate_not_scrolling = 10;
    gcui->goto_sleep = 0;
    LCD37x7->iconMICROCHIP = 1;

    if (RN_Ready) {LCD37x7->iconWIFI = 1;}
    else {LCD37x7->iconWIFI = 0;}

    //**********************************************************************
    // Main Loop
    //**********************************************************************
    while(1)
    {
        LCD37x7->iconHEART = 0;

        SD1CON2bits.SDRDY= 0;
        SD1CON1bits.SDRST = 0;

        if(USBGetDeviceState() == DETACHED_STATE) {
            USBDeviceAttach();
        }
        else if (USBDeviceState==CONFIGURED_STATE )
        {
            len=getsUSBUSART(buf,64);
            if (len>=1)
            {
                USB_Command();
            }
        }
        CDCTxService();
    }

    return 0;
}

void LogChar(char ch){}
