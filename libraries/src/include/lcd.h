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

#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define LCD_DEGREE 0x82
#define LCD_SIGMA       0xa1
#define LCD_UPPER_DELTA 0xc6

#define LCD_MAX_X 37
#define LCD_MAX_Y 7
#define LCD_CANVAS_MAX_X 200
#define LCD_CANVAS_MAX_Y 8
#define buffer_SIZE 60

#define LCD_BANNER_OFF  0
#define LCD_BANNER_LEFT 1
#define LCD_BANNER_RIGHt 2

//#define BPM_Rev_01     //Blood Pressure Meter demo board (MPG-BPM-PCB-1) Rev 0.1 [1st Version]
#define BPM_Rev_B        //Blood Pressure Meter demo board (MPG-BPM-PCB-1) Rev B   [2nd Version, LCD pins were modified.]

typedef union 
{
    uint16_t byte;
    struct
    {
        uint8_t bit0:1;
        uint8_t bit1:1;
        uint8_t bit2:1;
        uint8_t bit3:1;
        uint8_t bit4:1;
        uint8_t bit5:1;
        uint8_t bit6:1;
        uint8_t bit7:1;
        uint8_t bit8:1;
        uint8_t bit9:1;
        uint8_t bit10:1;
        uint8_t bit11:1;
        uint8_t bit12:1;
        uint8_t bit13:1;
        uint8_t bit14:1;
        uint8_t stop:1;
    };
}uint16_c;

/**
 * \brief A data stucture to contain a single text character.
 */
typedef struct 
{
    uint8_t c[5]; ///< Column Data
    uint8_t w;    ///< Width
}lcd_character;

typedef struct
{
    uint16_t fallrate; // px/tick;
    uint16_t hold;     // tick;
    uint16_t peak;
    int16_t  state;
    struct {
        unsigned tick:1;
    };
}_peakhold;
/**
 * \brief The LCD data structure.
 */
typedef struct 
{
    _peakhold peakhold;
    volatile uint8_t half_sec;
    uint8_t canvas_win_x;
    uint8_t canvas_win_y;
    char buffer[buffer_SIZE];
    int16_t cursor;
    int16_t scroll_indices[LCD_CANVAS_MAX_X];
    uint16_t msg_width_px;
    uint16_t scroll_zero;
    uint16_c canvas[LCD_CANVAS_MAX_X];
    uint16_c canvas_cpy[LCD_CANVAS_MAX_X];
    uint8_t printf_disabled;
    uint8_t icons_disabled;
    uint64_t blink_mask;
    uint8_t  blink_enable;
    uint8_t efficient_raster_override;
    union {
        uint64_t iconALL;
        struct
        {
            uint8_t iconDollar	:1;
            uint8_t iconWHEEL1	:1;
            uint8_t iconWHEEL2	:1;
            uint8_t iconWHEEL3	:1;
            uint8_t iconWHEEL4	:1;
            uint8_t iconWHEEL5	:1;
            uint8_t iconWHEEL6	:1;
            uint8_t iconWHEEL7	:1;
            uint8_t iconWHEEL8	:1;
            uint8_t iconWHEEL9	:1;
            uint8_t iconWHEEL10	:1;
            uint8_t iconSUN:1;
            uint8_t iconPAN:1;
            uint8_t iconWIFI:1;
            uint8_t iconZIG:1;
            uint8_t iconCLOUD:1;
            uint8_t iconHEART:1;
            uint8_t iconSTRIP:1;
            uint8_t iconBAT1:1;
            uint8_t iconBAT2:1;
            uint8_t iconBAT3:1;
            uint8_t iconBAT4:1;
            uint8_t iconDROP:1;
            uint8_t iconTHERMO:1;
            uint8_t iconCELCIUS:1;
            uint8_t iconFAREN:1;
            uint8_t iconMICROCHIP:1;
            uint8_t iconCENT:1;
            uint8_t iconRMB:1;
        };
    };
}lcd;

/**
 * @defgroup LCDGEN LCD General Functions
 * @{
 */

/**
 * \brief Displays formated text to the LCD.
 * \param format A character string 
 * \param ... an argument list
 * \return character count
 */
int lcd_printf(const char * format, ...);

/**
 * \brief The font array used to generate all the test in this demo.
 */
extern lcd_character F0507A00RP[]; 

// LCD [shape=record,label="<here> LCD | {Canvas|Icon}"];
/**
 * \brief Generates a new LCD object
 * \param  None
 * \return pointer to new lcd object
 *  \dot
 *  digraph structs {
 *  node [shape=record];
 *  ratio=compress;
 *      AUDIO [shape=record,label="<mic>Microphone|<hp>Headphone Jack|<opa>MCP6602"];
 *      TEMPERATURE [shape=record,label="{<ntc>NTC|<tc>TC77}"]; 
 *      ADCDEMO [shape=record,label="{a|b|c}"]; 
 *
 *
 *      "CDC Demo" -> "USB Device";
 *      "EXT. Measurement" -> "SigmaDelta ADC";
 *      "LCD Test" -> LCD;
 *      "Pot/Lite/Ext." -> "Pipeline ADC";
 *      "Waveform Generator" -> DAC -> Breakout;
 *      Audio -> "Pipeline ADC" -> Breakout;
 *      Audio -> "SigmaDelta ADC" -> "2.5V Reference";
 *      "SigmaDelta ADC" -> Breakout;
 *      Audio -> DAC -> AUDIO:opa;
 *      Clock -> RTCC -> "32kHz SOSC";
 *      Temperature -> CTMU -> C2INB -> TEMPERATURE:ntc;
 *      Temperature -> SPI -> TEMPERATURE:tc;
 *      UI -> mTouchCap;
 *      mTouchCap -> "Pipeline ADC";
 *      GPIO -> LEDs;
 *      CTMU -> "Internal Diode";
 *      AUDIO:mic -> Breakout;
 *      AUDIO:opa -> AUDIO:hp;
 *      subgraph cluster2 {
 *           label="Demos";
 *           UI;
 *           "CDC Demo";
 *           Clock;
 *           "EXT. Measurement"
 *           "Pot/Lite/Ext."
 *           "Waveform Generator"
 *           Temperature;
 *           "LCD Test";
 *           Audio;
 *      }
 *      subgraph cluster1 {
 *           label="24FJ128GC010 Peripherals";
 *           "USB Device";
 *           SPI;
 *           LCD;
 *           DAC;
 *           GPIO;
 *           CTMU;
 *           RTCC;
 *           "Pipeline ADC";
 *           "SigmaDelta ADC";
 *      }
 *
 *      subgraph cluster0 {
 *           label="MLA";
 *           mTouchCap;
 *           "CDC Device Driver";
 *      }
 *  }
 *  \enddot
 */
lcd* lcd_new(void);
  //DEMO [shape=record,label="<clock>Clock|<adc16>EXT Measure|<adc12>Pot/Lite|<dac>Waveform|<temp>Temperature|<lcd>LCD Test|<audio>Audio"];
 //*      PIC [shape=record,label="<usb>USB Device|<spi>SPI|<lcd>LCD|<dac>DAC|<gpio>GPIO|<CTMU>CTMU|<rtcc>RTCC|<adc12>Pipeline ADC|<adc16>SigmaDelta ADC"];
 //*      TEMPERATURE [shape=record,label="<ntc>NTC|<tc>TC77"]; 
/**
 * \brief Moves the display 1 px to the left
 * \param p pointer to lcd object
 *  \dot
 *  digraph structs {
 *  node [shape=record];
 *  ratio=compress;
 *  rankdir = LR;
 *    
PIC_spi -> TEMPERATURE_tc;
DEMO_clock -> PIC_rtcc;
DEMO_adc16 -> PIC_adc16;
DEMO_dac -> PIC_dac;
DEMO_adc12 -> PIC_adc12;
DEMO_temp -> PIC_spi;
DEMO_temp -> PIC_ctmu;
DEMO_temp -> PIC_adc12;

 *      subgraph cluster2 {
 *           label="Demos";
 *      }
 *  }
 *  \enddot
 */
void lcd_scroll_left(lcd *p);

/**
 * \brief Moves the display 1 px to the right 
 * \param p pointer to lcd object
 */
void lcd_scroll_right(lcd *p);

uint16_t getbit(uint16_t data, uint8_t bit);


/**
 * \brief calculates the pixel width of the string contained by p
 * \param p pointer to lcd object
 */
uint16_t lcd_msg_length_px(lcd *p);
uint8_t lcd_scroll_indices_set(lcd *p, int16_t v_zero, uint16_t max);
uint8_t lcd_canvas_haschanged(lcd *p);

/**
 * \brief Clear the Canvas
 * \param p pointer to lcd object
 */
void lcd_canvas_clr(lcd *p);

/**
 * \brief Applies the mask selected by XXX to the canvas.
 * \param p pointer to lcd object
 */
void lcd_canvas_clr_blink_mask(lcd *p);

void lcd_canvas_printf(lcd *p);
void lcd_canvas_raster(lcd *p);
void lcd_icon_raster_mcu(lcd *p);
void lcd_canvas_raster_mcu(lcd *p);
void lcd_canvas_update_cpy(lcd *p);
uint8_t lcd_draw_peakhold_tick(lcd *p);
/**
 * \brief 
 * \param p pointer to lcd object
 * \param x1 Top-Left x
 * \param y1 Top-Left y
 * \param x2 Bottom-right x
 * \param y2 Bottom-right y
 */
void lcd_draw_box(lcd *p, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

/**
 * \brief 
 * \param p pointer to lcd object
 */

void lcd_draw_peakhold(lcd *p, uint8_t x, uint8_t y, uint8_t value);

/**
 * \brief 
 * \param p pointer to lcd object
 */
void lcd_draw_rbox(lcd *p, uint8_t x, uint8_t y, uint8_t h, uint8_t w);

/**
 * \brief 
 * \param p pointer to lcd object
 */
void lcd_draw_rbox_fill(lcd *p, uint8_t x, uint8_t y, uint8_t h, uint8_t w);

/**
 * \brief 
 * \param p pointer to lcd object
 */
void lcd_draw_hline(lcd *p, uint8_t x, uint8_t y, uint8_t length);

/**
 * \brief 
 * \param p pointer to lcd object
 */
void lcd_draw_vline(lcd *p, uint8_t x, uint8_t y, uint8_t length);

/**
 * \brief Draws a saw-wave
 * \param p pointer to lcd object
 */
void lcd_draw_wave_saw(lcd *p);

/**
 * \brief Draws a saw-wave
 * \param p pointer to lcd object
 */
void lcd_draw_wave_sin(lcd *p);

/**
 * \brief Draws a sine-wave
 * \param p pointer to lcd object
 */
void lcd_draw_wave_square(lcd *p);

/**
 * \brief Draws a square-wave
 * \param p pointer to lcd object
 */
void lcd_draw_wave_triangle(lcd *p);

/**
 * \brief Draws a triangle-wave
 * \param p pointer to lcd object
 */
void lcd_pixel_draw(lcd *p, uint8_t x, uint8_t y);

/**
 * \brief Draws a saw-wave
 * \param p pointer to lcd object
 */
void lcd_pixel_erase(lcd *p, uint8_t x, uint8_t y);


void lcd_icon_clr(lcd *p);
/** @} */
#ifdef __XC16__
#include <xc.h>

#ifdef BPM_Rev_01
#define	X0Y0  _S8C0
#define	X0Y1  _S8C1
#define	X0Y2  _S8C2
#define	X0Y3  _S8C3
#define	X0Y4  _S8C4
#define	X0Y5  _S8C5
#define	X0Y6  _S8C6
#define Dollar	  _S8C7
              //
#define	X1Y0   _S9C0
#define	X1Y1   _S9C1
#define	X1Y2   _S9C2
#define	X1Y3   _S9C3
#define	X1Y4   _S9C4
#define	X1Y5   _S9C5
#define	X1Y6   _S9C6
#define WHEEL1	  _S9C7
              ////
#define	X2Y0 	  _S12C0
#define	X2Y1 	  _S12C1
#define	X2Y2 	  _S12C2
#define	X2Y3 	  _S12C3
#define	X2Y4 	  _S12C4
#define	X2Y5 	  _S12C5
#define	X2Y6 	  _S12C6
#define WHEEL2	  _S12C7

#define	X3Y0 	  _S13C0
#define	X3Y1 	  _S13C1
#define	X3Y2 	  _S13C2
#define	X3Y3 	  _S13C3
#define	X3Y4 	  _S13C4
#define	X3Y5 	  _S13C5
#define	X3Y6 	  _S13C6
#define WHEEL3	  _S13C7

#define	X4Y0 	  _S14C0
#define	X4Y1 	  _S14C1
#define	X4Y2 	  _S14C2
#define	X4Y3 	  _S14C3
#define	X4Y4 	  _S14C4
#define	X4Y5 	  _S14C5
#define	X4Y6 	  _S14C6
#define WHEEL4	  _S14C7

#define	X5Y0 	  _S15C0
#define	X5Y1 	  _S15C1
#define	X5Y2 	  _S15C2
#define	X5Y3 	  _S15C3
#define	X5Y4 	  _S15C4
#define	X5Y5 	  _S15C5
#define	X5Y6 	  _S15C6
#define WHEEL5	  _S15C7

#define	X6Y0 	  _S16C0
#define	X6Y1 	  _S16C1
#define	X6Y2 	  _S16C2
#define	X6Y3 	  _S16C3
#define	X6Y4 	  _S16C4
#define	X6Y5 	  _S16C5
#define	X6Y6 	  _S16C6
#define WHEEL6	  _S16C7

#define	X7Y0 	  _S25C0
#define	X7Y1 	  _S25C1
#define	X7Y2 	  _S25C2
#define	X7Y3 	  _S25C3
#define	X7Y4 	  _S25C4
#define	X7Y5 	  _S25C5
#define	X7Y6 	  _S25C6
#define WHEEL7	  _S25C7

#define	X8Y0 	  _S26C0
#define	X8Y1 	  _S26C1
#define	X8Y2 	  _S26C2
#define	X8Y3 	  _S26C3
#define	X8Y4 	  _S26C4
#define	X8Y5 	  _S26C5
#define	X8Y6 	  _S26C6
#define WHEEL8	  _S26C7

#define	X9Y0 	  _S28C0
#define	X9Y1 	  _S28C1
#define	X9Y2 	  _S28C2
#define	X9Y3 	  _S28C3
#define	X9Y4 	  _S28C4
#define	X9Y5 	  _S28C5
#define	X9Y6 	  _S28C6
#define WHEEL9	  _S28C7

#define	X10Y0 	  _S29C0
#define	X10Y1 	  _S29C1
#define	X10Y2 	  _S29C2
#define	X10Y3 	  _S29C3
#define	X10Y4 	  _S29C4
#define	X10Y5 	  _S29C5
#define	X10Y6 	  _S29C6
#define WHEEL10	  _S29C7

#define	X11Y0 	 _S31C0
#define	X11Y1 	 _S31C1
#define	X11Y2 	 _S31C2
#define	X11Y3 	 _S31C3
#define	X11Y4 	 _S31C4
#define	X11Y5 	 _S31C5
#define	X11Y6 	 _S31C6
#define SUN 	 _S31C7

#define	X12Y0 	  _S62C0
#define	X12Y1 	  _S62C1
#define	X12Y2 	  _S62C2
#define	X12Y3 	  _S62C3
#define	X12Y4 	  _S62C4
#define	X12Y5 	  _S62C5
#define	X12Y6 	  _S62C6
#define PAN 	  _S62C7

#define	X13Y0 	  _S61C0
#define	X13Y1 	  _S61C1
#define	X13Y2 	  _S61C2
#define	X13Y3 	  _S61C3
#define	X13Y4 	  _S61C4
#define	X13Y5 	  _S61C5
#define	X13Y6 	  _S61C6
#define WIFI 	  _S61C7

#define	X14Y0 	  _S60C0
#define	X14Y1 	  _S60C1
#define	X14Y2 	  _S60C2
#define	X14Y3 	  _S60C3
#define	X14Y4 	  _S60C4
#define	X14Y5 	  _S60C5
#define	X14Y6 	  _S60C6
#define ZIG 	  _S60C7

#define	X15Y0 	  _S59C0
#define	X15Y1 	  _S59C1
#define	X15Y2 	  _S59C2
#define	X15Y3 	  _S59C3
#define	X15Y4 	  _S59C4
#define	X15Y5 	  _S59C5
#define	X15Y6 	  _S59C6
#define CLOUD 	  _S59C7

#define	X16Y0 	  _S57C0
#define	X16Y1 	  _S57C1
#define	X16Y2 	  _S57C2
#define	X16Y3 	  _S57C3
#define	X16Y4 	  _S57C4
#define	X16Y5 	  _S57C5
#define	X16Y6 	  _S57C6
#define HEART 	  _S57C7

#define	X17Y0 	  _S56C0
#define	X17Y1 	  _S56C1
#define	X17Y2 	  _S56C2
#define	X17Y3 	  _S56C3
#define	X17Y4 	  _S56C4
#define	X17Y5 	  _S56C5
#define	X17Y6 	  _S56C6
#define STRIP 	  _S56C7

#define	X18Y0 	  _S55C0
#define	X18Y1 	  _S55C1
#define	X18Y2 	  _S55C2
#define	X18Y3 	  _S55C3
#define	X18Y4 	  _S55C4
#define	X18Y5 	  _S55C5
#define	X18Y6 	  _S55C6
#define BAT1 	  _S55C7

#define	X19Y0	  _S34C0
#define	X19Y1	  _S34C1
#define	X19Y2	  _S34C2
#define	X19Y3	  _S34C3
#define	X19Y4	  _S34C4
#define	X19Y5	  _S34C5
#define	X19Y6	  _S34C6
#define BAT2 	  _S34C7

#define	X20Y0	  _S37C0
#define	X20Y1	  _S37C1
#define	X20Y2	  _S37C2
#define	X20Y3	  _S37C3
#define	X20Y4	  _S37C4
#define	X20Y5	  _S37C5
#define	X20Y6	  _S37C6
#define BAT3 	  _S37C7

#define	X21Y0	  _S38C0
#define	X21Y1	  _S38C1
#define	X21Y2	  _S38C2
#define	X21Y3	  _S38C3
#define	X21Y4	  _S38C4
#define	X21Y5	  _S38C5
#define	X21Y6	  _S38C6
#define BAT4 	  _S38C7

#define	X22Y0	  _S54C0
#define	X22Y1	  _S54C1
#define	X22Y2	  _S54C2
#define	X22Y3	  _S54C3
#define	X22Y4	  _S54C4
#define	X22Y5	  _S54C5
#define	X22Y6	  _S54C6
#define DROP 	  _S54C7

#define	X23Y0	  _S53C0
#define	X23Y1	  _S53C1
#define	X23Y2	  _S53C2
#define	X23Y3	  _S53C3
#define	X23Y4	  _S53C4
#define	X23Y5	  _S53C5
#define	X23Y6	  _S53C6
#define THERMO 	  _S53C7

#define	X24Y0	  _S52C0
#define	X24Y1	  _S52C1
#define	X24Y2	  _S52C2
#define	X24Y3	  _S52C3
#define	X24Y4	  _S52C4
#define	X24Y5	  _S52C5
#define	X24Y6	  _S52C6
#define CEL 	  _S52C7

#define	X25Y0	  _S51C0
#define	X25Y1	  _S51C1
#define	X25Y2	  _S51C2
#define	X25Y3	  _S51C3
#define	X25Y4	  _S51C4
#define	X25Y5	  _S51C5
#define	X25Y6	  _S51C6
#define FAREN 	  _S51C7

#define	X26Y0	  _S48C0
#define	X26Y1	  _S48C1
#define	X26Y2	  _S48C2
#define	X26Y3	  _S48C3
#define	X26Y4	  _S48C4
#define	X26Y5	  _S48C5
#define	X26Y6	  _S48C6
#define MICROCHIP _S48C7

#define	X27Y0	  _S49C0
#define	X27Y1	  _S49C1
#define	X27Y2	  _S49C2
#define	X27Y3	  _S49C3
#define	X27Y4	  _S49C4
#define	X27Y5	  _S49C5
#define	X27Y6	  _S49C6
#define CENT      _S49C7

#define	X28Y0	  _S46C0
#define	X28Y1	  _S46C1
#define	X28Y2	  _S46C2
#define	X28Y3	  _S46C3
#define	X28Y4	  _S46C4
#define	X28Y5	  _S46C5
#define	X28Y6	  _S46C6
#define RMB       _S46C7

#define	X29Y0	  _S39C0
#define	X29Y1	  _S39C1
#define	X29Y2	  _S39C2
#define	X29Y3	  _S39C3
#define	X29Y4	  _S39C4
#define	X29Y5	  _S39C5
#define	X29Y6	  _S39C6
#define	X36Y0     _S39C7

#define	X30Y0	  _S40C0
#define	X30Y1	  _S40C1
#define	X30Y2	  _S40C2
#define	X30Y3	  _S40C3
#define	X30Y4	  _S40C4
#define	X30Y5	  _S40C5
#define	X30Y6	  _S40C6
#define	X36Y1     _S40C7

#define	X31Y0	  _S41C0
#define	X31Y1	  _S41C1
#define	X31Y2	  _S41C2
#define	X31Y3	  _S41C3
#define	X31Y4	  _S41C4
#define	X31Y5	  _S41C5
#define	X31Y6	  _S41C6
#define	X36Y2     _S41C7

#define	X32Y0	  _S42C0
#define	X32Y1	  _S42C1
#define	X32Y2	  _S42C2
#define	X32Y3	  _S42C3
#define	X32Y4	  _S42C4
#define	X32Y5	  _S42C5
#define	X32Y6	  _S42C6
#define	X36Y3     _S42C7

#define	X33Y0	  _S43C0
#define	X33Y1	  _S43C1
#define	X33Y2	  _S43C2
#define	X33Y3	  _S43C3
#define	X33Y4	  _S43C4
#define	X33Y5	  _S43C5
#define	X33Y6	  _S43C6
#define	X36Y4     _S43C7

#define	X34Y0	  _S50C0
#define	X34Y1	  _S50C1
#define	X34Y2	  _S50C2
#define	X34Y3	  _S50C3
#define	X34Y4	  _S50C4
#define	X34Y5	  _S50C5
#define	X34Y6	  _S50C6
#define	X36Y5     _S50C7

#define	X35Y0	  _S45C0
#define	X35Y1	  _S45C1
#define	X35Y2	  _S45C2
#define	X35Y3	  _S45C3
#define	X35Y4	  _S45C4
#define	X35Y5	  _S45C5
#define	X35Y6	  _S45C6
#define	X36Y6     _S45C7

#define S1      _SE08
#define S2      _SE09
#define S3      _SE12
#define S4 	    _SE13
#define S5 	    _SE14
#define S6 		_SE15
#define S7 		_SE16
#define S8 		_SE25
#define S9		_SE26
#define S10		_SE28
#define S11		_SE29
#define S12		_SE31
#define S13		_SE34
#define S14		_SE37
#define S15		_SE38
#define S16		_SE39
#define S17		_SE40
#define S18		_SE41
#define S19		_SE42
#define S20		_SE43
#define S21		_SE45
#define S22		_SE46
#define S23		_SE48
#define S24		_SE49
#define S25		_SE50
#define S26		_SE51
#define S27		_SE52
#define S28		_SE53
#define S29		_SE54
#define S30		_SE55
#define S31		_SE56
#define S32		_SE57
#define S33		_SE59
#define S34		_SE60
#define S35		_SE61
#define S36		_SE62
#endif

#ifdef BPM_Rev_B
#define	X0Y0  _S45C0
#define	X0Y1  _S45C1
#define	X0Y2  _S45C2
#define	X0Y3  _S45C3
#define	X0Y4  _S45C4
#define	X0Y5  _S45C5
#define	X0Y6  _S45C6
#define Dollar	  _S45C7
              //
#define	X1Y0   _S37C0
#define	X1Y1   _S37C1
#define	X1Y2   _S37C2
#define	X1Y3   _S37C3
#define	X1Y4   _S37C4
#define	X1Y5   _S37C5
#define	X1Y6   _S37C6
#define WHEEL1	  _S37C7
              ////
#define	X2Y0 	  _S31C0
#define	X2Y1 	  _S31C1
#define	X2Y2 	  _S31C2
#define	X2Y3 	  _S31C3
#define	X2Y4 	  _S31C4
#define	X2Y5 	  _S31C5
#define	X2Y6 	  _S31C6
#define WHEEL2	  _S31C7

#define	X3Y0 	  _S53C0
#define	X3Y1 	  _S53C1
#define	X3Y2 	  _S53C2
#define	X3Y3 	  _S53C3
#define	X3Y4 	  _S53C4
#define	X3Y5 	  _S53C5
#define	X3Y6 	  _S53C6
#define WHEEL3	  _S53C7

#define	X4Y0 	  _S54C0
#define	X4Y1 	  _S54C1
#define	X4Y2 	  _S54C2
#define	X4Y3 	  _S54C3
#define	X4Y4 	  _S54C4
#define	X4Y5 	  _S54C5
#define	X4Y6 	  _S54C6
#define WHEEL4	  _S54C7

#define	X5Y0 	  _S16C0
#define	X5Y1 	  _S16C1
#define	X5Y2 	  _S16C2
#define	X5Y3 	  _S16C3
#define	X5Y4 	  _S16C4
#define	X5Y5 	  _S16C5
#define	X5Y6 	  _S16C6
#define WHEEL5	  _S16C7

#define	X6Y0 	  _S8C0
#define	X6Y1 	  _S8C1
#define	X6Y2 	  _S8C2
#define	X6Y3 	  _S8C3
#define	X6Y4 	  _S8C4
#define	X6Y5 	  _S8C5
#define	X6Y6 	  _S8C6
#define WHEEL6	  _S8C7

#define	X7Y0 	  _S9C0
#define	X7Y1 	  _S9C1
#define	X7Y2 	  _S9C2
#define	X7Y3 	  _S9C3
#define	X7Y4 	  _S9C4
#define	X7Y5 	  _S9C5
#define	X7Y6 	  _S9C6
#define WHEEL7	  _S9C7

#define	X8Y0 	  _S38C0
#define	X8Y1 	  _S38C1
#define	X8Y2 	  _S38C2
#define	X8Y3 	  _S38C3
#define	X8Y4 	  _S38C4
#define	X8Y5 	  _S38C5
#define	X8Y6 	  _S38C6
#define WHEEL8	  _S38C7

#define	X9Y0 	  _S39C0
#define	X9Y1 	  _S39C1
#define	X9Y2 	  _S39C2
#define	X9Y3 	  _S39C3
#define	X9Y4 	  _S39C4
#define	X9Y5 	  _S39C5
#define	X9Y6 	  _S39C6
#define WHEEL9	  _S39C7

#define	X10Y0 	  _S12C0
#define	X10Y1 	  _S12C1
#define	X10Y2 	  _S12C2
#define	X10Y3 	  _S12C3
#define	X10Y4 	  _S12C4
#define	X10Y5 	  _S12C5
#define	X10Y6 	  _S12C6
#define WHEEL10	  _S12C7

#define	X11Y0 	 _S40C0
#define	X11Y1 	 _S40C1
#define	X11Y2 	 _S40C2
#define	X11Y3 	 _S40C3
#define	X11Y4 	 _S40C4
#define	X11Y5 	 _S40C5
#define	X11Y6 	 _S40C6
#define SUN 	 _S40C7

#define	X12Y0 	  _S25C0
#define	X12Y1 	  _S25C1
#define	X12Y2 	  _S25C2
#define	X12Y3 	  _S25C3
#define	X12Y4 	  _S25C4
#define	X12Y5 	  _S25C5
#define	X12Y6 	  _S25C6
#define PAN 	  _S25C7

#define	X13Y0 	  _S26C0
#define	X13Y1 	  _S26C1
#define	X13Y2 	  _S26C2
#define	X13Y3 	  _S26C3
#define	X13Y4 	  _S26C4
#define	X13Y5 	  _S26C5
#define	X13Y6 	  _S26C6
#define WIFI 	  _S26C7

#define	X14Y0 	  _S46C0
#define	X14Y1 	  _S46C1
#define	X14Y2 	  _S46C2
#define	X14Y3 	  _S46C3
#define	X14Y4 	  _S46C4
#define	X14Y5 	  _S46C5
#define	X14Y6 	  _S46C6
#define ZIG 	  _S46C7

#define	X15Y0 	  _S59C0
#define	X15Y1 	  _S59C1
#define	X15Y2 	  _S59C2
#define	X15Y3 	  _S59C3
#define	X15Y4 	  _S59C4
#define	X15Y5 	  _S59C5
#define	X15Y6 	  _S59C6
#define CLOUD 	  _S59C7

#define	X16Y0 	  _S60C0
#define	X16Y1 	  _S60C1
#define	X16Y2 	  _S60C2
#define	X16Y3 	  _S60C3
#define	X16Y4 	  _S60C4
#define	X16Y5 	  _S60C5
#define	X16Y6 	  _S60C6
#define HEART 	  _S60C7

#define	X17Y0 	  _S61C0
#define	X17Y1 	  _S61C1
#define	X17Y2 	  _S61C2
#define	X17Y3 	  _S61C3
#define	X17Y4 	  _S61C4
#define	X17Y5 	  _S61C5
#define	X17Y6 	  _S61C6
#define STRIP 	  _S61C7

#define	X18Y0 	  _S49C0
#define	X18Y1 	  _S49C1
#define	X18Y2 	  _S49C2
#define	X18Y3 	  _S49C3
#define	X18Y4 	  _S49C4
#define	X18Y5 	  _S49C5
#define	X18Y6 	  _S49C6
#define BAT1 	  _S49C7

#define	X19Y0	  _S41C0
#define	X19Y1	  _S41C1
#define	X19Y2	  _S41C2
#define	X19Y3	  _S41C3
#define	X19Y4	  _S41C4
#define	X19Y5	  _S41C5
#define	X19Y6	  _S41C6
#define BAT2 	  _S41C7

#define	X20Y0	  _S55C0
#define	X20Y1	  _S55C1
#define	X20Y2	  _S55C2
#define	X20Y3	  _S55C3
#define	X20Y4	  _S55C4
#define	X20Y5	  _S55C5
#define	X20Y6	  _S55C6
#define BAT3 	  _S55C7

#define	X21Y0	  _S56C0
#define	X21Y1	  _S56C1
#define	X21Y2	  _S56C2
#define	X21Y3	  _S56C3
#define	X21Y4	  _S56C4
#define	X21Y5	  _S56C5
#define	X21Y6	  _S56C6
#define BAT4 	  _S56C7

#define	X22Y0	  _S57C0
#define	X22Y1	  _S57C1
#define	X22Y2	  _S57C2
#define	X22Y3	  _S57C3
#define	X22Y4	  _S57C4
#define	X22Y5	  _S57C5
#define	X22Y6	  _S57C6
#define DROP 	  _S57C7

#define	X23Y0	  _S62C0
#define	X23Y1	  _S62C1
#define	X23Y2	  _S62C2
#define	X23Y3	  _S62C3
#define	X23Y4	  _S62C4
#define	X23Y5	  _S62C5
#define	X23Y6	  _S62C6
#define THERMO 	  _S62C7

#define	X24Y0	  _S50C0
#define	X24Y1	  _S50C1
#define	X24Y2	  _S50C2
#define	X24Y3	  _S50C3
#define	X24Y4	  _S50C4
#define	X24Y5	  _S50C5
#define	X24Y6	  _S50C6
#define CEL 	  _S50C7

#define	X25Y0	  _S51C0
#define	X25Y1	  _S51C1
#define	X25Y2	  _S51C2
#define	X25Y3	  _S51C3
#define	X25Y4	  _S51C4
#define	X25Y5	  _S51C5
#define	X25Y6	  _S51C6
#define FAREN 	  _S51C7

#define	X26Y0	  _S52C0
#define	X26Y1	  _S52C1
#define	X26Y2	  _S52C2
#define	X26Y3	  _S52C3
#define	X26Y4	  _S52C4
#define	X26Y5	  _S52C5
#define	X26Y6	  _S52C6
#define MICROCHIP _S52C7

#define	X27Y0	  _S48C0
#define	X27Y1	  _S48C1
#define	X27Y2	  _S48C2
#define	X27Y3	  _S48C3
#define	X27Y4	  _S48C4
#define	X27Y5	  _S48C5
#define	X27Y6	  _S48C6
#define CENT      _S48C7

#define	X28Y0	  _S34C0
#define	X28Y1	  _S34C1
#define	X28Y2	  _S34C2
#define	X28Y3	  _S34C3
#define	X28Y4	  _S34C4
#define	X28Y5	  _S34C5
#define	X28Y6	  _S34C6
#define RMB       _S34C7

#define	X29Y0	  _S29C0
#define	X29Y1	  _S29C1
#define	X29Y2	  _S29C2
#define	X29Y3	  _S29C3
#define	X29Y4	  _S29C4
#define	X29Y5	  _S29C5
#define	X29Y6	  _S29C6
#define	X36Y0     _S29C7

#define	X30Y0	  _S28C0
#define	X30Y1	  _S28C1
#define	X30Y2	  _S28C2
#define	X30Y3	  _S28C3
#define	X30Y4	  _S28C4
#define	X30Y5	  _S28C5
#define	X30Y6	  _S28C6
#define	X36Y1     _S28C7

#define	X31Y0	  _S42C0
#define	X31Y1	  _S42C1
#define	X31Y2	  _S42C2
#define	X31Y3	  _S42C3
#define	X31Y4	  _S42C4
#define	X31Y5	  _S42C5
#define	X31Y6	  _S42C6
#define	X36Y2     _S42C7

#define	X32Y0	  _S43C0
#define	X32Y1	  _S43C1
#define	X32Y2	  _S43C2
#define	X32Y3	  _S43C3
#define	X32Y4	  _S43C4
#define	X32Y5	  _S43C5
#define	X32Y6	  _S43C6
#define	X36Y3     _S43C7

#define	X33Y0	  _S13C0
#define	X33Y1	  _S13C1
#define	X33Y2	  _S13C2
#define	X33Y3	  _S13C3
#define	X33Y4	  _S13C4
#define	X33Y5	  _S13C5
#define	X33Y6	  _S13C6
#define	X36Y4     _S13C7

#define	X34Y0	  _S14C0
#define	X34Y1	  _S14C1
#define	X34Y2	  _S14C2
#define	X34Y3	  _S14C3
#define	X34Y4	  _S14C4
#define	X34Y5	  _S14C5
#define	X34Y6	  _S14C6
#define	X36Y5     _S14C7

#define	X35Y0	  _S15C0
#define	X35Y1	  _S15C1
#define	X35Y2	  _S15C2
#define	X35Y3	  _S15C3
#define	X35Y4	  _S15C4
#define	X35Y5	  _S15C5
#define	X35Y6	  _S15C6
#define	X36Y6     _S15C7

#define S1  _SE45
#define S2  _SE37
#define S3  _SE31
#define S4  _SE53
#define S5  _SE54
#define S6  _SE16
#define S7  _SE08
#define S8  _SE09
#define S9  _SE38
#define S10 _SE39
#define S11 _SE12
#define S12 _SE40
#define S13 _SE41
#define S14 _SE55
#define S15 _SE56
#define S16 _SE29
#define S17 _SE28
#define S18 _SE42
#define S19 _SE43
#define S20 _SE13
#define S21 _SE14
#define S22 _SE15
#define S23 _SE34
#define S24 _SE48
#define S25 _SE52
#define S26 _SE51
#define S27 _SE50
#define S28 _SE62
#define S29 _SE57
#define S30 _SE49
#define S31 _SE61
#define S32 _SE60
#define S33 _SE59
#define S34 _SE46
#define S35 _SE26
#define S36 _SE25
#endif

#endif 

#endif //LCD_TASKS_H

