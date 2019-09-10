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

#include "lcd.h"

#define SKINNY_NUMBERS

lcd_character F0507A00RP[]= {
    {{0x00, 0x00, 0x00, 0x00, 0x00}, .w= 0x03},      /*' '  0x20 */ 
    {{0x5f, 0x00, 0x00, 0x00, 0x00}, .w= 0x01},      /* !   0x21 */
    {{0x07, 0x00, 0x07, 0x00, 0x00}, .w= 0x03},      /* "   0x22 */ 
    {{0x14, 0x7f, 0x14, 0x7f, 0x14}, .w= 0x05},      /* #   0x23 */
    {{0x24, 0x2a, 0x7f, 0x2a, 0x12}, .w= 0x05},      /* $   0x24 */ 
    {{0x23, 0x13, 0x08, 0x64, 0x62}, .w= 0x05},      /* %   0x25 */
    {{0x36, 0x49, 0x55, 0x22, 0x50}, .w= 0x05},      /* &   0x26 */ 
    {{0x03, 0x00, 0x00, 0x00, 0x00}, .w= 0x01},      /* '   0x27 */
    {{0x1c, 0x22, 0x41, 0x00, 0x00}, .w= 0x03},      /* (   0x28 */ 
    {{0x41, 0x22, 0x1c, 0x00, 0x00}, .w= 0x03},      /* )   0x29 */
    {{0x14, 0x08, 0x3e, 0x08, 0x14}, .w= 0x05},      /* *   0x2a */ 
    {{0x08, 0x08, 0x3e, 0x08, 0x08}, .w= 0x05},      /* +   0x2b */
    {{0x50, 0x30, 0x00, 0x00, 0x00}, .w= 0x02},      /* ,   0x2c */ 
    {{0x08, 0x08, 0x08, 0x08, 0x08}, .w= 0x03},      /* -   0x2d */
    {{0x40, 0x00, 0x00, 0x00, 0x00}, .w= 0x01},      /* .   0x2e */ 
    {{0x20, 0x10, 0x08, 0x04, 0x02}, .w= 0x05},      /* /   0x2f */
#ifdef SKINNY_NUMBERS
    {{0x3e, 0x41, 0x3e, 0x00, 0x00}, .w= 0x03}, /* 0   0x30 */
    {{0x42, 0x7f, 0x40, 0x00, 0x00}, .w= 0x03}, /* 1   0x31 */
    {{0x62, 0x51, 0x4e, 0x00, 0x00}, .w= 0x03}, /* 2   0x32 */
    {{0x22, 0x49, 0x36, 0x00, 0x00}, .w= 0x03}, /* 3   0x33 */
    {{0x0f, 0x08, 0x7f, 0x00, 0x00}, .w= 0x03}, /* 4   0x34 */
    {{0x4f, 0x49, 0x39, 0x00, 0x00}, .w= 0x03}, /* 5   0x35 */
    {{0x3e, 0x49, 0x32, 0x00, 0x00}, .w= 0x03}, /* 6   0x36 */
    {{0x03, 0x71, 0x0f, 0x00, 0x00}, .w= 0x03}, /* 7   0x37 */
    {{0x36, 0x49, 0x36, 0x00, 0x00}, .w= 0x03}, /* 8   0x38 */
    {{0x26, 0x49, 0x3e, 0x00, 0x00}, .w= 0x03}, /* 9   0x39 */
#else
    {{0x3e, 0x51, 0x49, 0x45, 0x3e}, .w= 0x05},      /* 0   0x30 */ 
    {{0x00, 0x42, 0x7f, 0x40, 0x00}, .w= 0x05},      /* 1   0x31 */ 
    {{0x42, 0x61, 0x51, 0x49, 0x46}, .w= 0x05},      /* 2   0x32 */ 
    {{0x21, 0x41, 0x45, 0x4b, 0x31}, .w= 0x05},      /* 3   0x33 */
    {{0x18, 0x14, 0x12, 0x7f, 0x10}, .w= 0x05},      /* 4   0x34 */ 
    {{0x27, 0x45, 0x45, 0x45, 0x39}, .w= 0x05},      /* 5   0x35 */
    {{0x3c, 0x4a, 0x49, 0x49, 0x30}, .w= 0x05},      /* 6   0x36 */ 
    {{0x03, 0x01, 0x71, 0x09, 0x07}, .w= 0x05},      /* 7   0x37 */
    {{0x36, 0x49, 0x49, 0x49, 0x36}, .w= 0x05},      /* 8   0x38 */ 
    {{0x06, 0x49, 0x49, 0x29, 0x1e}, .w= 0x05},      /* 9   0x39 */
#endif
    {{0x36, 0x36, 0x00, 0x00, 0x00}, .w= 0x01},      /* :   0x3a */ 
    {{0x56, 0x36, 0x00, 0x00, 0x00}, .w= 0x02},      /* ;   0x3b */
    {{0x08, 0x14, 0x22, 0x41, 0x00}, .w= 0x04},      /* <   0x3c */ 
    {{0x14, 0x14, 0x14, 0x14, 0x14}, .w= 0x05},      /* =   0x3d */
    {{0x41, 0x22, 0x14, 0x08, 0x00}, .w= 0x04},      /* >   0x3e */ 
    {{0x02, 0x01, 0x51, 0x09, 0x06}, .w= 0x05},      /* ?   0x3f */
    {{0x32, 0x49, 0x79, 0x41, 0x3e}, .w= 0x05},      /* @   0x40 */ 
    {{0x7e, 0x11, 0x11, 0x11, 0x7e}, .w= 0x05},      /* A   0x41 */
    {{0x7f, 0x49, 0x49, 0x49, 0x36}, .w= 0x05},      /* B   0x42 */ 
    {{0x3e, 0x41, 0x41, 0x41, 0x22}, .w= 0x05},      /* C   0x43 */
    {{0x7f, 0x41, 0x41, 0x22, 0x1c}, .w= 0x05},      /* D   0x44 */ 
    {{0x7f, 0x49, 0x49, 0x49, 0x41}, .w= 0x05},      /* E   0x45 */
    {{0x7f, 0x09, 0x09, 0x09, 0x01}, .w= 0x05},      /* F   0x46 */ 
    {{0x3e, 0x41, 0x49, 0x49, 0x7a}, .w= 0x05},      /* G   0x47 */
    {{0x7f, 0x08, 0x08, 0x08, 0x7f}, .w= 0x05},      /* H   0x48 */ 
    {{0x41, 0x7f, 0x41, 0x00, 0x00}, .w= 0x03},      /* I   0x49 */
    {{0x20, 0x40, 0x41, 0x3f, 0x01}, .w= 0x05},      /* J   0x4a */ 
    {{0x7f, 0x08, 0x14, 0x22, 0x41}, .w= 0x05},      /* K   0x4b */
    {{0x7f, 0x40, 0x40, 0x40, 0x40}, .w= 0x03},      /* L   0x4c */ 
    {{0x7f, 0x02, 0x0c, 0x02, 0x7f}, .w= 0x05},      /* M   0x4d */
    {{0x7f, 0x04, 0x08, 0x10, 0x7f}, .w= 0x05},      /* N   0x4e */ 
    {{0x3e, 0x41, 0x41, 0x41, 0x3e}, .w= 0x05},      /* O   0x4f */
    {{0x7f, 0x09, 0x09, 0x09, 0x06}, .w= 0x05},      /* P   0x50 */ 
    {{0x3e, 0x41, 0x51, 0x21, 0x5e}, .w= 0x05},      /* Q   0x51 */
    {{0x7f, 0x09, 0x19, 0x29, 0x46}, .w= 0x05},      /* R   0x52 */ 
    {{0x46, 0x49, 0x49, 0x49, 0x31}, .w= 0x05},      /* S   0x53 */
    {{0x01, 0x01, 0x7f, 0x01, 0x01}, .w= 0x05},      /* T   0x54 */ 
    {{0x3f, 0x40, 0x40, 0x40, 0x3f}, .w= 0x05},      /* U   0x55 */
    {{0x1f, 0x20, 0x40, 0x20, 0x1f}, .w= 0x05},      /* V   0x56 */ 
    {{0x3f, 0x40, 0x30, 0x40, 0x3f}, .w= 0x05},      /* W   0x57 */
    {{0x63, 0x14, 0x08, 0x14, 0x63}, .w= 0x05},      /* X   0x58 */ 
    {{0x07, 0x08, 0x70, 0x08, 0x07}, .w= 0x05},      /* Y   0x59 */
    {{0x61, 0x51, 0x49, 0x45, 0x43}, .w= 0x05},      /* Z   0x5a */ 
    {{0x7f, 0x41, 0x41, 0x00, 0x00}, .w= 0x03},      /* [   0x5b */
    {{0x15, 0x16, 0x7c, 0x16, 0x15}, .w= 0x05},      /* y   0x5c */ 
    {{0x41, 0x41, 0x7f, 0x00, 0x00}, .w= 0x03},      /* ]   0x5d */
    {{0x04, 0x02, 0x01, 0x02, 0x04}, .w= 0x05},      /* ^   0x5e */ 
    {{0x40, 0x40, 0x40, 0x40, 0x40}, .w= 0x05},      /* _   0x5f */
    {{0x01, 0x02, 0x04, 0x00, 0x00}, .w= 0x03},      /* `   0x60 */ 
    {{0x20, 0x54, 0x54, 0x54, 0x78}, .w= 0x05},      /* a   0x61 */
    {{0x7f, 0x48, 0x44, 0x44, 0x38}, .w= 0x05},      /* b   0x62 */ 
    {{0x38, 0x44, 0x44, 0x44, 0x20}, .w= 0x05},      /* c   0x63 */
    {{0x38, 0x44, 0x44, 0x48, 0x7f}, .w= 0x05},      /* d   0x64 */ 
    {{0x38, 0x54, 0x54, 0x18, 0x00}, .w= 0x04},      /* e   0x65 */
    {{0x08, 0x7e, 0x09, 0x01, 0x02}, .w= 0x05},      /* f   0x66 */ 
    {{0x0c, 0x52, 0x52, 0x52, 0x3e}, .w= 0x05},      /* g   0x67 */
    {{0x7f, 0x08, 0x04, 0x04, 0x78}, .w= 0x05},      /* h   0x68 */ 
    {{0x44, 0x7d, 0x40, 0x00, 0x00}, .w= 0x03},      /* i   0x69 */
    {{0x20, 0x40, 0x44, 0x3d, 0x00}, .w= 0x04},      /* j   0x6a */ 
    {{0x7f, 0x10, 0x28, 0x44, 0x00}, .w= 0x04},      /* k   0x6b */
    {{0x41, 0x7f, 0x40, 0x00, 0x00}, .w= 0x03},      /* l   0x6c */ 
    {{0x7c, 0x04, 0x18, 0x04, 0x78}, .w= 0x05},      /* m   0xed */
    {{0x7c, 0x08, 0x04, 0x04, 0x78}, .w= 0x05},      /* n   0x6e */ 
    {{0x38, 0x44, 0x44, 0x44, 0x38}, .w= 0x05},      /* o   0x6f */
    {{0x7c, 0x14, 0x14, 0x14, 0x08}, .w= 0x05},      /* p   0x70 */ 
    {{0x08, 0x14, 0x14, 0x18, 0x7c}, .w= 0x05},      /* q   0x71 */
    {{0x7c, 0x08, 0x04, 0x04, 0x08}, .w= 0x05},      /* r   0x72 */ 
    {{0x48, 0x54, 0x54, 0x54, 0x20}, .w= 0x05},      /* s   0x73 */
    {{0x04, 0x3f, 0x44, 0x20, 0x00}, .w= 0x04},      /* t   0x74 */ 
    {{0x3c, 0x40, 0x40, 0x20, 0x7c}, .w= 0x05},      /* u   0x75 */
    {{0x1c, 0x20, 0x40, 0x20, 0x1c}, .w= 0x05},      /* v   0x76 */ 
    {{0x3c, 0x40, 0x30, 0x40, 0x3c}, .w= 0x05},      /* w   0x77 */
    {{0x44, 0x28, 0x10, 0x28, 0x44}, .w= 0x05},      /* x   0x78 */ 
    {{0x0c, 0x50, 0x50, 0x50, 0x3c}, .w= 0x05},      /* y   0x79 */
    {{0x44, 0x64, 0x54, 0x4c, 0x44}, .w= 0x05},      /* z   0x7a */ 
    {{0x08, 0x36, 0x41, 0x00, 0x00}, .w= 0x03},      /* {   0x7b */
    {{0x7f, 0x00, 0x00, 0x00, 0x00}, .w= 0x01},      /* |   0x7c */ 
    {{0x41, 0x36, 0x08, 0x00, 0x00}, .w= 0x03},      /* }   0x7d */
    {{0x08, 0x08, 0x2a, 0x1c, 0x08}, .w= 0x05},      /* ->  0x7e */ 
    {{0x08, 0x1c, 0x2a, 0x08, 0x08}, .w= 0x05},      /* <-  0x7f */  
    {{0x63, 0x55, 0x49, 0x41, 0x41}, .w= 0x05},      /*     0x80 */ // SIGMA
    {{0x70, 0x4c, 0x43, 0x4c, 0x70}, .w= 0x05},      /*     0x81 */ // Delta
    {{0x06, 0x09, 0x09, 0x06, 0x00}, .w= 0x04},      /*     0x82 */ // DEGREE 
    {{0x31, 0x29, 0x25, 0x23, 0x00}, .w= 0x04},      /*     0x83 */ // HIGHZ
    {{0x62, 0x52, 0x4a, 0x46, 0x00}, .w= 0x04},      /*     0x84 */ // LOWZ
    {{0x00, 0x00, 0x00, 0x00, 0x00}, .w= 0x01},      /*     0x85 */ // space 3
    {{0x70, 0x4c, 0x43, 0x4c, 0x70}, .w= 0x05}};                                                   
uint8_t lcd_draw_peakhold_tick(lcd *p)
{
    switch(p->peakhold.state)
    {
        case 0: // Hold
            p->peakhold.hold--;
            if(p->peakhold.hold==0){
                p->peakhold.state++;
            }
            break;
        case 1: // Fall 
            p->peakhold.peak -= p->peakhold.fallrate;
            break;

    }
    return 0;
}
void lcd_pixel_draw(lcd *p, uint8_t x, uint8_t y)
{

    if(!p->printf_disabled){
        if(x <= LCD_MAX_X && y <= LCD_MAX_Y) {
            p->canvas[x].byte |= 1<<y;
        }
    }
}
void lcd_pixel_erase(lcd *p, uint8_t x, uint8_t y)
{
    if(!p->printf_disabled){
        if(x <= LCD_MAX_X && y <= LCD_MAX_Y) {
            p->canvas[x].byte &= ~(1<<y);
        }
    }
}
void lcd_draw_hline(lcd *p, uint8_t x, uint8_t y, uint8_t length)
{
    uint8_t index;
    if(!p->printf_disabled){
        if(x <= LCD_MAX_X && y <= LCD_MAX_Y) {
            for(index = x; index < length + x; index++)
            {
                p->canvas[index].byte |= 1<<y;
            } 
        }
    }
}
void lcd_draw_vline(lcd *p, uint8_t x, uint8_t y, uint8_t length)
{
    uint8_t index;
    if(!p->printf_disabled){
        if(x <= LCD_MAX_X && y <= LCD_MAX_Y) {
            for(index = y; index < length + y; index++)
            {
                p->canvas[x].byte |= 1<<index;
            } 
        }
    }
}
void lcd_draw_box(lcd *p, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    lcd_draw_hline(p,x1,y1,x2-x1+1);
    lcd_draw_hline(p,x1,y2,x2-x1+1);

    lcd_draw_vline(p,x1,y1,y2-y1+1);
    lcd_draw_vline(p,x2,y1,y2-y1+1);
}
void lcd_draw_rbox(lcd *p, uint8_t x, uint8_t y, uint8_t h, uint8_t w)
{
     lcd_draw_hline(p,x,y,w);
     lcd_draw_hline(p,x,y+h,w);

     lcd_draw_vline(p,x+w,y,h+1);
     lcd_draw_vline(p,x,y,h);
   
}
void lcd_draw_rbox_fill(lcd *p, uint8_t x, uint8_t y, uint8_t h, uint8_t w)
{
    uint8_t index;
    for(index = y; index < h+y; index++)
    {
        lcd_draw_hline(p,x,index,w);
    } 


}
void lcd_draw_peakhold(lcd *p, uint8_t x, uint8_t y, uint8_t value)
{
    //p->peakhold.peak;
    //p->peakhold.hold;
    //p->peakhold.fallrate;

    if(value > LCD_MAX_X)
        value = LCD_MAX_X;

    if(value > p->peakhold.peak) {
        p->peakhold.state=0;
        p->peakhold.peak = value;
        p->peakhold.hold = 2;
    }

    // Bar
    lcd_draw_rbox_fill(p,x,y,3,value);
    // Peak
    lcd_draw_rbox_fill(p,p->peakhold.peak,y,3,1);
}
void lcd_canvas_clr(lcd *p)
{
    uint16_t index;
    for(index = 0; index < LCD_CANVAS_MAX_X; index++)
    {
        p->canvas[index].byte = 0x00;
    } 
}
void lcd_canvas_clr_blink_mask(lcd *p)
{
    uint64_t mask = p->blink_mask;
    uint16_t index;
    uint8_t temp_stop;
    for(index = 0; index < 64; index++) {
        if(mask & 0x8000000000000000) {
            temp_stop = p->canvas[index].stop;
            p->canvas[index].byte = 0;
            p->canvas[index].stop = temp_stop;
        }
        mask <<= 1;
    } 
}
void lcd_canvas_printf(lcd *p)
{
    uint16_t i,j;
    uint16_t cursor_cpy;
    cursor_cpy = p->cursor;
    p->msg_width_px = 0;

    for(i = 0; i < strlen(p->buffer); i++) {
        for(j = 0; j < F0507A00RP[(uint8_t)p->buffer[i]-' '].w; j++) {
            p->canvas[p->cursor++].byte = F0507A00RP[(uint8_t)p->buffer[i]-' '].c[j];
            p->msg_width_px++;
        } 
        p->cursor++;
        p->msg_width_px++;
    } 
    if(p->msg_width_px < LCD_MAX_X) {
        p->msg_width_px = LCD_MAX_X;
    }
    p->cursor = p->msg_width_px;
    if(p->blink_mask != 0 && p->blink_enable) {
        lcd_canvas_clr_blink_mask(p);
    }
    p->canvas[cursor_cpy].stop = 1;
}
uint8_t lcd_canvas_haschanged(lcd *p)
{
    uint16_t index;
    for(index = 0; index < LCD_CANVAS_MAX_X; index++) {
        if((p->efficient_raster_override)||(p->canvas[index].byte != p->canvas_cpy[index].byte)) {
            return 1;
        }
    } 
    return 0;
}
void lcd_canvas_update_cpy(lcd *p)
{
    uint16_t index;
    for(index = 0; index < LCD_CANVAS_MAX_X; index++) {
        p->canvas_cpy[index].byte = p->canvas[index].byte;
    } 
}
void lcd_icon_clr(lcd *p)
{
    p->iconALL = 0x00;
    lcd_icon_raster_mcu(p);
}
void lcd_canvas_raster(lcd *p)
{
    if(lcd_canvas_haschanged(p)) {
        lcd_canvas_raster_mcu(p);
    }
    lcd_icon_raster_mcu(p);
    lcd_canvas_update_cpy(p);
}
uint16_t getbit(uint16_t data, uint8_t b)
{
    return (data>>b)&0x0001;
}
void lcd_icon_raster_mcu(lcd *p)
{
#if defined __XC16__
    if(!p->icons_disabled) {
        Dollar = p->iconDollar;
        WHEEL1 = p->iconWHEEL1;
        WHEEL2 = p->iconWHEEL2;
        WHEEL3 = p->iconWHEEL3;
        WHEEL4 = p->iconWHEEL4;
        WHEEL5 = p->iconWHEEL5;
        WHEEL6 = p->iconWHEEL6;
        WHEEL7 = p->iconWHEEL7;
        WHEEL8 = p->iconWHEEL8;
        WHEEL9 = p->iconWHEEL9;
        WHEEL10 = p->iconWHEEL10;
        SUN = p->iconSUN;
        PAN = p->iconPAN;
        WIFI = p->iconWIFI;
        ZIG = p->iconZIG;
        CLOUD = p->iconCLOUD;
        HEART = p->iconHEART;
        STRIP = p->iconSTRIP;
        BAT1 = p->iconBAT1;
        BAT2 = p->iconBAT2;
        BAT3 = p->iconBAT3;
        BAT4 = p->iconBAT4;
        DROP = p->iconDROP;
        THERMO = p->iconTHERMO;
        CEL = p->iconCELCIUS;
        FAREN = p->iconFAREN;
        MICROCHIP = p->iconMICROCHIP;
        CENT = p->iconCENT;
        RMB = p->iconRMB;
    } else {
        Dollar = 0;
        WHEEL1 = 0;
        WHEEL2 = 0;
        WHEEL3 = 0;
        WHEEL4 = 0;
        WHEEL5 = 0;
        WHEEL6 = 0;
        WHEEL7 = 0;
        WHEEL8 = 0;
        WHEEL9 = 0;
        WHEEL10 = 0;
        SUN = 0;
        PAN = 0;
        WIFI = 0;
        ZIG = 0;
        CLOUD = 0;
        HEART = 0;
        STRIP = 0;
        BAT1 = 0;
        BAT2 = 0;
        BAT3 = 0;
        BAT4 = 0;
        DROP = 0;
        THERMO = 0;
        CEL = 0;
        FAREN = 0;
        MICROCHIP = 0;
        CENT = 0;
        RMB = 0;
    }
#endif // __XC16__
}
void lcd_canvas_raster_mcu(lcd *p)
#ifdef __XC16__
{

    X0Y0 = p->canvas[p->scroll_indices[0]].bit0;
    X0Y1 = p->canvas[p->scroll_indices[0]].bit1;
    X0Y2 = p->canvas[p->scroll_indices[0]].bit2;
    X0Y3 = p->canvas[p->scroll_indices[0]].bit3;
    X0Y4 = p->canvas[p->scroll_indices[0]].bit4;
    X0Y5 = p->canvas[p->scroll_indices[0]].bit5;
    X0Y6 = p->canvas[p->scroll_indices[0]].bit6;

    X1Y0 = p->canvas[p->scroll_indices[1]].bit0;
    X1Y1 = p->canvas[p->scroll_indices[1]].bit1;
    X1Y2 = p->canvas[p->scroll_indices[1]].bit2;
    X1Y3 = p->canvas[p->scroll_indices[1]].bit3;
    X1Y4 = p->canvas[p->scroll_indices[1]].bit4;
    X1Y5 = p->canvas[p->scroll_indices[1]].bit5;
    X1Y6 = p->canvas[p->scroll_indices[1]].bit6;

    X2Y0 = p->canvas[p->scroll_indices[2]].bit0;
    X2Y1 = p->canvas[p->scroll_indices[2]].bit1;
    X2Y2 = p->canvas[p->scroll_indices[2]].bit2;
    X2Y3 = p->canvas[p->scroll_indices[2]].bit3;
    X2Y4 = p->canvas[p->scroll_indices[2]].bit4;
    X2Y5 = p->canvas[p->scroll_indices[2]].bit5;
    X2Y6 = p->canvas[p->scroll_indices[2]].bit6;	

    X3Y0 = p->canvas[p->scroll_indices[3]].bit0;
    X3Y1 = p->canvas[p->scroll_indices[3]].bit1;
    X3Y2 = p->canvas[p->scroll_indices[3]].bit2;
    X3Y3 = p->canvas[p->scroll_indices[3]].bit3;
    X3Y4 = p->canvas[p->scroll_indices[3]].bit4;
    X3Y5 = p->canvas[p->scroll_indices[3]].bit5;
    X3Y6 = p->canvas[p->scroll_indices[3]].bit6;

    X4Y0 = p->canvas[p->scroll_indices[4]].bit0;
    X4Y1 = p->canvas[p->scroll_indices[4]].bit1;
    X4Y2 = p->canvas[p->scroll_indices[4]].bit2;
    X4Y3 = p->canvas[p->scroll_indices[4]].bit3;
    X4Y4 = p->canvas[p->scroll_indices[4]].bit4;
    X4Y5 = p->canvas[p->scroll_indices[4]].bit5;
    X4Y6 = p->canvas[p->scroll_indices[4]].bit6;

    X5Y0 = p->canvas[p->scroll_indices[5]].bit0;
    X5Y1 = p->canvas[p->scroll_indices[5]].bit1;
    X5Y2 = p->canvas[p->scroll_indices[5]].bit2;
    X5Y3 = p->canvas[p->scroll_indices[5]].bit3;
    X5Y4 = p->canvas[p->scroll_indices[5]].bit4;
    X5Y5 = p->canvas[p->scroll_indices[5]].bit5;
    X5Y6 = p->canvas[p->scroll_indices[5]].bit6;

    X6Y0 = p->canvas[p->scroll_indices[6]].bit0;
    X6Y1 = p->canvas[p->scroll_indices[6]].bit1;
    X6Y2 = p->canvas[p->scroll_indices[6]].bit2;
    X6Y3 = p->canvas[p->scroll_indices[6]].bit3;
    X6Y4 = p->canvas[p->scroll_indices[6]].bit4;
    X6Y5 = p->canvas[p->scroll_indices[6]].bit5;
    X6Y6 = p->canvas[p->scroll_indices[6]].bit6;	

    X7Y0 = p->canvas[p->scroll_indices[7]].bit0;
    X7Y1 = p->canvas[p->scroll_indices[7]].bit1;
    X7Y2 = p->canvas[p->scroll_indices[7]].bit2;
    X7Y3 = p->canvas[p->scroll_indices[7]].bit3;
    X7Y4 = p->canvas[p->scroll_indices[7]].bit4;
    X7Y5 = p->canvas[p->scroll_indices[7]].bit5;
    X7Y6 = p->canvas[p->scroll_indices[7]].bit6;	

    X8Y0 = p->canvas[p->scroll_indices[8]].bit0;
    X8Y1 = p->canvas[p->scroll_indices[8]].bit1;
    X8Y2 = p->canvas[p->scroll_indices[8]].bit2;
    X8Y3 = p->canvas[p->scroll_indices[8]].bit3;
    X8Y4 = p->canvas[p->scroll_indices[8]].bit4;
    X8Y5 = p->canvas[p->scroll_indices[8]].bit5;
    X8Y6 = p->canvas[p->scroll_indices[8]].bit6;	

    X9Y0 = p->canvas[p->scroll_indices[9]].bit0;
    X9Y1 = p->canvas[p->scroll_indices[9]].bit1;
    X9Y2 = p->canvas[p->scroll_indices[9]].bit2;
    X9Y3 = p->canvas[p->scroll_indices[9]].bit3;
    X9Y4 = p->canvas[p->scroll_indices[9]].bit4;
    X9Y5 = p->canvas[p->scroll_indices[9]].bit5;
    X9Y6 = p->canvas[p->scroll_indices[9]].bit6;	

    X10Y0 = p->canvas[p->scroll_indices[10]].bit0;
    X10Y1 = p->canvas[p->scroll_indices[10]].bit1;
    X10Y2 = p->canvas[p->scroll_indices[10]].bit2;
    X10Y3 = p->canvas[p->scroll_indices[10]].bit3;
    X10Y4 = p->canvas[p->scroll_indices[10]].bit4;
    X10Y5 = p->canvas[p->scroll_indices[10]].bit5;
    X10Y6 = p->canvas[p->scroll_indices[10]].bit6;	

    X11Y0 = p->canvas[p->scroll_indices[11]].bit0;
    X11Y1 = p->canvas[p->scroll_indices[11]].bit1;
    X11Y2 = p->canvas[p->scroll_indices[11]].bit2;
    X11Y3 = p->canvas[p->scroll_indices[11]].bit3;
    X11Y4 = p->canvas[p->scroll_indices[11]].bit4;
    X11Y5 = p->canvas[p->scroll_indices[11]].bit5;
    X11Y6 = p->canvas[p->scroll_indices[11]].bit6;	

    X12Y0 = p->canvas[p->scroll_indices[12]].bit0;
    X12Y1 = p->canvas[p->scroll_indices[12]].bit1;
    X12Y2 = p->canvas[p->scroll_indices[12]].bit2;
    X12Y3 = p->canvas[p->scroll_indices[12]].bit3;
    X12Y4 = p->canvas[p->scroll_indices[12]].bit4;
    X12Y5 = p->canvas[p->scroll_indices[12]].bit5;
    X12Y6 = p->canvas[p->scroll_indices[12]].bit6;	

    X13Y0 = p->canvas[p->scroll_indices[13]].bit0;
    X13Y1 = p->canvas[p->scroll_indices[13]].bit1;
    X13Y2 = p->canvas[p->scroll_indices[13]].bit2;
    X13Y3 = p->canvas[p->scroll_indices[13]].bit3;
    X13Y4 = p->canvas[p->scroll_indices[13]].bit4;
    X13Y5 = p->canvas[p->scroll_indices[13]].bit5;
    X13Y6 = p->canvas[p->scroll_indices[13]].bit6;	

    X14Y0 = p->canvas[p->scroll_indices[14]].bit0;
    X14Y1 = p->canvas[p->scroll_indices[14]].bit1;
    X14Y2 = p->canvas[p->scroll_indices[14]].bit2;
    X14Y3 = p->canvas[p->scroll_indices[14]].bit3;
    X14Y4 = p->canvas[p->scroll_indices[14]].bit4;
    X14Y5 = p->canvas[p->scroll_indices[14]].bit5;
    X14Y6 = p->canvas[p->scroll_indices[14]].bit6;	

    X15Y0 = p->canvas[p->scroll_indices[15]].bit0;
    X15Y1 = p->canvas[p->scroll_indices[15]].bit1;
    X15Y2 = p->canvas[p->scroll_indices[15]].bit2;
    X15Y3 = p->canvas[p->scroll_indices[15]].bit3;
    X15Y4 = p->canvas[p->scroll_indices[15]].bit4;
    X15Y5 = p->canvas[p->scroll_indices[15]].bit5;
    X15Y6 = p->canvas[p->scroll_indices[15]].bit6;	

    X16Y0 = p->canvas[p->scroll_indices[16]].bit0;
    X16Y1 = p->canvas[p->scroll_indices[16]].bit1;
    X16Y2 = p->canvas[p->scroll_indices[16]].bit2;
    X16Y3 = p->canvas[p->scroll_indices[16]].bit3;
    X16Y4 = p->canvas[p->scroll_indices[16]].bit4;
    X16Y5 = p->canvas[p->scroll_indices[16]].bit5;
    X16Y6 = p->canvas[p->scroll_indices[16]].bit6;	

    X17Y0 = p->canvas[p->scroll_indices[17]].bit0;
    X17Y1 = p->canvas[p->scroll_indices[17]].bit1;
    X17Y2 = p->canvas[p->scroll_indices[17]].bit2;
    X17Y3 = p->canvas[p->scroll_indices[17]].bit3;
    X17Y4 = p->canvas[p->scroll_indices[17]].bit4;
    X17Y5 = p->canvas[p->scroll_indices[17]].bit5;
    X17Y6 = p->canvas[p->scroll_indices[17]].bit6;	

    X18Y0 = p->canvas[p->scroll_indices[18]].bit0;
    X18Y1 = p->canvas[p->scroll_indices[18]].bit1;
    X18Y2 = p->canvas[p->scroll_indices[18]].bit2;
    X18Y3 = p->canvas[p->scroll_indices[18]].bit3;
    X18Y4 = p->canvas[p->scroll_indices[18]].bit4;
    X18Y5 = p->canvas[p->scroll_indices[18]].bit5;
    X18Y6 = p->canvas[p->scroll_indices[18]].bit6;	

    X19Y0 = p->canvas[p->scroll_indices[19]].bit0;
    X19Y1 = p->canvas[p->scroll_indices[19]].bit1;
    X19Y2 = p->canvas[p->scroll_indices[19]].bit2;
    X19Y3 = p->canvas[p->scroll_indices[19]].bit3;
    X19Y4 = p->canvas[p->scroll_indices[19]].bit4;
    X19Y5 = p->canvas[p->scroll_indices[19]].bit5;
    X19Y6 = p->canvas[p->scroll_indices[19]].bit6;	

    X20Y0 = p->canvas[p->scroll_indices[20]].bit0;
    X20Y1 = p->canvas[p->scroll_indices[20]].bit1;
    X20Y2 = p->canvas[p->scroll_indices[20]].bit2;
    X20Y3 = p->canvas[p->scroll_indices[20]].bit3;
    X20Y4 = p->canvas[p->scroll_indices[20]].bit4;
    X20Y5 = p->canvas[p->scroll_indices[20]].bit5;
    X20Y6 = p->canvas[p->scroll_indices[20]].bit6;	

    X21Y0 = p->canvas[p->scroll_indices[21]].bit0;
    X21Y1 = p->canvas[p->scroll_indices[21]].bit1;
    X21Y2 = p->canvas[p->scroll_indices[21]].bit2;
    X21Y3 = p->canvas[p->scroll_indices[21]].bit3;
    X21Y4 = p->canvas[p->scroll_indices[21]].bit4;
    X21Y5 = p->canvas[p->scroll_indices[21]].bit5;
    X21Y6 = p->canvas[p->scroll_indices[21]].bit6;	

    X22Y0 = p->canvas[p->scroll_indices[22]].bit0;
    X22Y1 = p->canvas[p->scroll_indices[22]].bit1;
    X22Y2 = p->canvas[p->scroll_indices[22]].bit2;
    X22Y3 = p->canvas[p->scroll_indices[22]].bit3;
    X22Y4 = p->canvas[p->scroll_indices[22]].bit4;
    X22Y5 = p->canvas[p->scroll_indices[22]].bit5;
    X22Y6 = p->canvas[p->scroll_indices[22]].bit6;	

    X23Y0 = p->canvas[p->scroll_indices[23]].bit0;
    X23Y1 = p->canvas[p->scroll_indices[23]].bit1;
    X23Y2 = p->canvas[p->scroll_indices[23]].bit2;
    X23Y3 = p->canvas[p->scroll_indices[23]].bit3;
    X23Y4 = p->canvas[p->scroll_indices[23]].bit4;
    X23Y5 = p->canvas[p->scroll_indices[23]].bit5;
    X23Y6 = p->canvas[p->scroll_indices[23]].bit6;	

    X24Y0 = p->canvas[p->scroll_indices[24]].bit0;
    X24Y1 = p->canvas[p->scroll_indices[24]].bit1;
    X24Y2 = p->canvas[p->scroll_indices[24]].bit2;
    X24Y3 = p->canvas[p->scroll_indices[24]].bit3;
    X24Y4 = p->canvas[p->scroll_indices[24]].bit4;
    X24Y5 = p->canvas[p->scroll_indices[24]].bit5;
    X24Y6 = p->canvas[p->scroll_indices[24]].bit6;	

    X25Y0 = p->canvas[p->scroll_indices[25]].bit0;
    X25Y1 = p->canvas[p->scroll_indices[25]].bit1;
    X25Y2 = p->canvas[p->scroll_indices[25]].bit2;
    X25Y3 = p->canvas[p->scroll_indices[25]].bit3;
    X25Y4 = p->canvas[p->scroll_indices[25]].bit4;
    X25Y5 = p->canvas[p->scroll_indices[25]].bit5;
    X25Y6 = p->canvas[p->scroll_indices[25]].bit6;	

    X26Y0 = p->canvas[p->scroll_indices[26]].bit0;
    X26Y1 = p->canvas[p->scroll_indices[26]].bit1;
    X26Y2 = p->canvas[p->scroll_indices[26]].bit2;
    X26Y3 = p->canvas[p->scroll_indices[26]].bit3;
    X26Y4 = p->canvas[p->scroll_indices[26]].bit4;
    X26Y5 = p->canvas[p->scroll_indices[26]].bit5;
    X26Y6 = p->canvas[p->scroll_indices[26]].bit6;	

    X27Y0 = p->canvas[p->scroll_indices[27]].bit0;
    X27Y1 = p->canvas[p->scroll_indices[27]].bit1;
    X27Y2 = p->canvas[p->scroll_indices[27]].bit2;
    X27Y3 = p->canvas[p->scroll_indices[27]].bit3;
    X27Y4 = p->canvas[p->scroll_indices[27]].bit4;
    X27Y5 = p->canvas[p->scroll_indices[27]].bit5;
    X27Y6 = p->canvas[p->scroll_indices[27]].bit6;	

    X28Y0 = p->canvas[p->scroll_indices[28]].bit0;
    X28Y1 = p->canvas[p->scroll_indices[28]].bit1;
    X28Y2 = p->canvas[p->scroll_indices[28]].bit2;
    X28Y3 = p->canvas[p->scroll_indices[28]].bit3;
    X28Y4 = p->canvas[p->scroll_indices[28]].bit4;
    X28Y5 = p->canvas[p->scroll_indices[28]].bit5;
    X28Y6 = p->canvas[p->scroll_indices[28]].bit6;	

    X29Y0 = p->canvas[p->scroll_indices[29]].bit0;
    X29Y1 = p->canvas[p->scroll_indices[29]].bit1;
    X29Y2 = p->canvas[p->scroll_indices[29]].bit2;
    X29Y3 = p->canvas[p->scroll_indices[29]].bit3;
    X29Y4 = p->canvas[p->scroll_indices[29]].bit4;
    X29Y5 = p->canvas[p->scroll_indices[29]].bit5;
    X29Y6 = p->canvas[p->scroll_indices[29]].bit6;	

    X30Y0 = p->canvas[p->scroll_indices[30]].bit0;
    X30Y1 = p->canvas[p->scroll_indices[30]].bit1;
    X30Y2 = p->canvas[p->scroll_indices[30]].bit2;
    X30Y3 = p->canvas[p->scroll_indices[30]].bit3;
    X30Y4 = p->canvas[p->scroll_indices[30]].bit4;
    X30Y5 = p->canvas[p->scroll_indices[30]].bit5;
    X30Y6 = p->canvas[p->scroll_indices[30]].bit6;	

    X31Y0 = p->canvas[p->scroll_indices[31]].bit0;
    X31Y1 = p->canvas[p->scroll_indices[31]].bit1;
    X31Y2 = p->canvas[p->scroll_indices[31]].bit2;
    X31Y3 = p->canvas[p->scroll_indices[31]].bit3;
    X31Y4 = p->canvas[p->scroll_indices[31]].bit4;
    X31Y5 = p->canvas[p->scroll_indices[31]].bit5;
    X31Y6 = p->canvas[p->scroll_indices[31]].bit6;	

    X32Y0 = p->canvas[p->scroll_indices[32]].bit0;
    X32Y1 = p->canvas[p->scroll_indices[32]].bit1;
    X32Y2 = p->canvas[p->scroll_indices[32]].bit2;
    X32Y3 = p->canvas[p->scroll_indices[32]].bit3;
    X32Y4 = p->canvas[p->scroll_indices[32]].bit4;
    X32Y5 = p->canvas[p->scroll_indices[32]].bit5;
    X32Y6 = p->canvas[p->scroll_indices[32]].bit6;	

    X33Y0 = p->canvas[p->scroll_indices[33]].bit0;
    X33Y1 = p->canvas[p->scroll_indices[33]].bit1;
    X33Y2 = p->canvas[p->scroll_indices[33]].bit2;
    X33Y3 = p->canvas[p->scroll_indices[33]].bit3;
    X33Y4 = p->canvas[p->scroll_indices[33]].bit4;
    X33Y5 = p->canvas[p->scroll_indices[33]].bit5;
    X33Y6 = p->canvas[p->scroll_indices[33]].bit6;	

    X34Y0 = p->canvas[p->scroll_indices[34]].bit0;
    X34Y1 = p->canvas[p->scroll_indices[34]].bit1;
    X34Y2 = p->canvas[p->scroll_indices[34]].bit2;
    X34Y3 = p->canvas[p->scroll_indices[34]].bit3;
    X34Y4 = p->canvas[p->scroll_indices[34]].bit4;
    X34Y5 = p->canvas[p->scroll_indices[34]].bit5;
    X34Y6 = p->canvas[p->scroll_indices[34]].bit6;	

    X35Y0 = p->canvas[p->scroll_indices[35]].bit0;
    X35Y1 = p->canvas[p->scroll_indices[35]].bit1;
    X35Y2 = p->canvas[p->scroll_indices[35]].bit2;
    X35Y3 = p->canvas[p->scroll_indices[35]].bit3;
    X35Y4 = p->canvas[p->scroll_indices[35]].bit4;
    X35Y5 = p->canvas[p->scroll_indices[35]].bit5;
    X35Y6 = p->canvas[p->scroll_indices[35]].bit6;	

    X36Y0 = p->canvas[p->scroll_indices[36]].bit0;
    X36Y1 = p->canvas[p->scroll_indices[36]].bit1;
    X36Y2 = p->canvas[p->scroll_indices[36]].bit2;
    X36Y3 = p->canvas[p->scroll_indices[36]].bit3;
    X36Y4 = p->canvas[p->scroll_indices[36]].bit4;
    X36Y5 = p->canvas[p->scroll_indices[36]].bit5;
    X36Y6 = p->canvas[p->scroll_indices[36]].bit6;	
}
#else
{   
    uint32_t index;
    for(index = 0; index < p->msg_width_px; index++)
    {
        //printf("%d",p->canvas[/*p->scroll_indices[0]*/index].stop);
        //printf("%d",p->canvas[/*p->scroll_indices[0]*/index].bit6);
        //printf("%d",p->canvas[/*p->scroll_indices[0]*/index].bit5);
        //printf("%d",p->canvas[/*p->scroll_indices[0]*/index].bit4);
        //printf("%d",p->canvas[/*p->scroll_indices[0]*/index].bit3);
        //printf("%d",p->canvas[/*p->scroll_indices[0]*/index].bit2);
        //printf("%d",p->canvas[/*p->scroll_indices[0]*/index].bit1);
        //printf("%d",p->canvas[/*p->scroll_indices[0]*/index].bit0);
        //printf("\n");

    } 
}
#endif

lcd *gclcd;
uint16_t lcd_msg_length_px(lcd *p)
{
    uint16_t index;
    uint16_t msg_px = 0;
    for(index = 0; index < strlen(p->buffer); index++)
    {
        msg_px += F0507A00RP[(uint16_t)p->buffer[index]].w + 1; // +1 for space
    } 
    return msg_px;
}
lcd *lcd_new(void)
{
    lcd *p = (lcd *)malloc(sizeof(lcd));
    gclcd = p;
#ifdef __XC16__
    S1=1; S2=1; S3=1; S4=1; S5=1; S6=1; S7=1; S8=1; S9=1; S10=1;
    S11=1; S12=1; S13=1; S14=1; S15=1; S16=1; S17=1; S18=1; S19=1; S20=1;
    S21=1; S22=1; S23=1; S24=1; S25=1; S26=1; S27=1; S28=1; S29=1; S30=1;
    S31=1; S32=1; S33=1; S34=1; S35=1; S36=1;
#endif
    p->peakhold.peak = 0;
    p->peakhold.hold = 2;
    p->peakhold.fallrate = 1;
    p->peakhold.state = 0;


    p->scroll_zero = 0;
    p->cursor = 0;
    p->blink_enable = 0;
    p->blink_mask = 0;
    p->canvas_win_x = 0;
    p->canvas_win_y = 0;
    p->half_sec = 0;

    p->msg_width_px = 0;
    p->printf_disabled = 0;
    p->icons_disabled = 0;
    p->cursor = 0;
    lcd_canvas_clr(p);
    p->iconALL = 0;

    int16_t index;
    for(index = 0; index < buffer_SIZE; index++) {
        p->buffer[index] = 0;

    } 
    for(index = 0; index < LCD_CANVAS_MAX_X; index++) {
        p->scroll_indices[index]=index;
    } 

    return p;
}
int lcd_printf(const char *format, ...)
{

    va_list args;
    int chcnt;
    if(gclcd->printf_disabled == 0) {

        va_start(args, format);
        chcnt = vsprintf((char *)gclcd->buffer, format, args);


#ifdef __XC16__
        _T1IE = 0;
#endif 
        lcd_canvas_clr(gclcd);

        lcd_scroll_indices_set(gclcd,0,LCD_CANVAS_MAX_X);
        gclcd->cursor = 0;
        lcd_canvas_printf(gclcd);
#ifdef __XC16__
        _T1IE = 1;
#endif

    }
    return chcnt;
}
uint8_t lcd_scroll_indices_set(lcd *p, int16_t v_zero, uint16_t max)
{
    int16_t index = v_zero;
    uint16_t counter = 0;
    while(index < LCD_CANVAS_MAX_X) {
        p->scroll_indices[index++] = counter++;
        if(counter == max) {
            counter = 0;
        }
    }
    if(v_zero > 0) {
        for(index = 0; index < v_zero; index++) {
            p->scroll_indices[index] = counter++;
            if(counter == max) {
                counter = 0;
            }
        } 
    }
    return 0;
}

void lcd_scroll_left(lcd *p)
{
    if(p->scroll_zero == 0)
    {
        p->scroll_zero = LCD_CANVAS_MAX_X-1;
    }
    else
    {
        p->scroll_zero--;
    }
    lcd_scroll_indices_set(p,p->scroll_zero,LCD_CANVAS_MAX_X);
}
void lcd_scroll_right(lcd *p)
{
    if(p->scroll_zero == LCD_CANVAS_MAX_X)
    {
        p->scroll_zero = 0;
    }
    else
    {
        p->scroll_zero++;
    }
    lcd_scroll_indices_set(p,p->scroll_zero,LCD_CANVAS_MAX_X);
}

void lcd_draw_wave_saw(lcd *p)
{
    if(!p->icons_disabled){
        p->canvas[0].byte  = 0x40; 
        p->canvas[1].byte  = 0x20; 
        p->canvas[2].byte  = 0x10; 
        p->canvas[3].byte  = 0x08; 
        p->canvas[4].byte  = 0x04; 
        p->canvas[5].byte  = 0x02; 
        p->canvas[6].byte  = 0x7F; 
        p->canvas[7].byte  = 0x20;
        p->canvas[8].byte  = 0x10;
        p->canvas[9].byte  = 0x08;
        p->canvas[10].byte = 0x04;
        p->canvas[11].byte = 0x02;
        p->canvas[12].byte = 0x7F;
        p->canvas[13].byte = 0x20;
        p->canvas[14].byte = 0x10;
        p->canvas[15].byte = 0x08;
        p->canvas[16].byte = 0x04;
        p->canvas[17].byte = 0x02;
        p->canvas[18].byte = 0x7F;
        p->canvas[19].byte = 0x20;
        p->canvas[20].byte = 0x10;
        p->canvas[21].byte = 0x08;
        p->canvas[22].byte = 0x04;
        p->canvas[23].byte = 0x02;
        p->canvas[24].byte = 0x7F;
        p->canvas[25].byte = 0x20;
        p->canvas[26].byte = 0x10;
        p->canvas[27].byte = 0x08;
        p->canvas[28].byte = 0x04;
        p->canvas[29].byte = 0x02;
        p->canvas[30].byte = 0x7F;
        p->canvas[31].byte = 0x20;
        p->canvas[32].byte = 0x10;
        p->canvas[33].byte = 0x08;
        p->canvas[34].byte = 0x04;
        p->canvas[35].byte = 0x02;
        p->canvas[36].byte = 0x7F;
    }
}
void lcd_draw_wave_sin(lcd *p)
{
    if(!p->icons_disabled){
        p->canvas[0].byte  = 0x1c; // 0001 1100 
        p->canvas[1].byte  = 0x02; // 0000 0010
        p->canvas[2].byte  = 0x01; // 0000 0001
        p->canvas[3].byte  = 0x01; // 0000 0001
        p->canvas[4].byte  = 0x02; // 0000 0010
        p->canvas[5].byte  = 0x1c; // 0001 1100
        p->canvas[6].byte  = 0x20; // 0010 0000
        p->canvas[7].byte  = 0x40; // 0100 0000
        p->canvas[8].byte  = 0x40; // 0100 0000
        p->canvas[9].byte  = 0x20; // 0010 0000
        p->canvas[10].byte = 0x1c; // 0001 1100 
        p->canvas[11].byte = 0x02; // 0000 0010
        p->canvas[12].byte = 0x01; // 0000 0001
        p->canvas[13].byte = 0x01; // 0000 0001
        p->canvas[14].byte = 0x02; // 0000 0010
        p->canvas[15].byte = 0x1c; // 0001 1100
        p->canvas[16].byte = 0x20; // 0010 0000
        p->canvas[17].byte = 0x40; // 0100 0000
        p->canvas[18].byte = 0x40; // 0100 0000
        p->canvas[19].byte = 0x20; // 0010 0000
        p->canvas[20].byte = 0x1c; // 0001 1100 
        p->canvas[21].byte = 0x02; // 0000 0010
        p->canvas[22].byte = 0x01; // 0000 0001
        p->canvas[23].byte = 0x01; // 0000 0001
        p->canvas[24].byte = 0x02; // 0000 0010
        p->canvas[25].byte = 0x1c; // 0001 1100
        p->canvas[26].byte = 0x20; // 0010 0000
        p->canvas[27].byte = 0x40; // 0100 0000
        p->canvas[28].byte = 0x40; // 0100 0000
        p->canvas[29].byte = 0x20; // 0010 0000
        p->canvas[30].byte = 0x1c; // 0001 1100 
        p->canvas[31].byte = 0x02; // 0000 0010
        p->canvas[32].byte = 0x01; // 0000 0001
        p->canvas[33].byte = 0x01; // 0000 0001
        p->canvas[34].byte = 0x02; // 0000 0010
        p->canvas[35].byte = 0x1c; // 0001 1100
        p->canvas[36].byte = 0x20; // 0010 0000
    }                              
}
void lcd_draw_wave_square(lcd *p)
{
    if(!p->icons_disabled){
        p->canvas[0].byte  = 0x7f;
        p->canvas[1].byte  = 0x01;
        p->canvas[2].byte  = 0x01;
        p->canvas[3].byte  = 0x01;
        p->canvas[4].byte  = 0x01;
        p->canvas[5].byte  = 0x7f;
        p->canvas[6].byte  = 0x40;
        p->canvas[7].byte  = 0x40;
        p->canvas[8].byte  = 0x40;
        p->canvas[9].byte  = 0x40;
        p->canvas[10].byte = 0x7f;
        p->canvas[11].byte = 0x01;
        p->canvas[12].byte = 0x01;
        p->canvas[13].byte = 0x01;
        p->canvas[14].byte = 0x01;
        p->canvas[15].byte = 0x7f;
        p->canvas[16].byte = 0x40;
        p->canvas[17].byte = 0x40;
        p->canvas[18].byte = 0x40;
        p->canvas[19].byte = 0x40;
        p->canvas[20].byte = 0x7f;
        p->canvas[21].byte = 0x01;
        p->canvas[22].byte = 0x01;
        p->canvas[23].byte = 0x01;
        p->canvas[24].byte = 0x01;
        p->canvas[25].byte = 0x7f;
        p->canvas[26].byte = 0x40;
        p->canvas[27].byte = 0x40;
        p->canvas[28].byte = 0x40;
        p->canvas[29].byte = 0x40;
        p->canvas[30].byte = 0x7f;
        p->canvas[31].byte = 0x01;
        p->canvas[32].byte = 0x01;
        p->canvas[33].byte = 0x01;
        p->canvas[34].byte = 0x01;
        p->canvas[35].byte = 0x7f;
        p->canvas[36].byte = 0x40;
    }                                
}
void lcd_draw_wave_triangle(lcd *p)
{
    if(!p->icons_disabled){
        p->canvas[0].byte  = 0x40;
        p->canvas[1].byte  = 0x20;
        p->canvas[2].byte  = 0x10;
        p->canvas[3].byte  = 0x08;
        p->canvas[4].byte  = 0x04;
        p->canvas[5].byte  = 0x02;
        p->canvas[6].byte  = 0x01;
        p->canvas[7].byte  = 0x02;
        p->canvas[8].byte  = 0x04;
        p->canvas[9].byte  = 0x08;
        p->canvas[10].byte = 0x10;
        p->canvas[11].byte = 0x20;
        p->canvas[12].byte = 0x40;
        p->canvas[13].byte = 0x20;
        p->canvas[14].byte = 0x10;
        p->canvas[15].byte = 0x08;
        p->canvas[16].byte = 0x04;
        p->canvas[17].byte = 0x02;
        p->canvas[18].byte = 0x01;
        p->canvas[19].byte = 0x02;
        p->canvas[20].byte = 0x04;
        p->canvas[21].byte = 0x08;
        p->canvas[22].byte = 0x10;
        p->canvas[23].byte = 0x20;
        p->canvas[24].byte = 0x40;
        p->canvas[25].byte = 0x20;
        p->canvas[26].byte = 0x10;
        p->canvas[27].byte = 0x08;
        p->canvas[28].byte = 0x04;
        p->canvas[29].byte = 0x02;
        p->canvas[30].byte = 0x01;
        p->canvas[31].byte = 0x02;
        p->canvas[32].byte = 0x04;
        p->canvas[33].byte = 0x08;
        p->canvas[34].byte = 0x10;
        p->canvas[35].byte = 0x20;
        p->canvas[36].byte = 0x40;
    }                                
} 


