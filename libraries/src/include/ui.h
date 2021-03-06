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

#ifndef UI_H
#define UI_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lcd.h"
#include "math.h"

/**
 * @defgroup UI UI
 * @{
 */

#define UI_START                  0 
#define DISPLAY_DATA              1 
#define TRANSITION_RIGHT          2 
#define TRANSITION_RIGHT_CANCEL   3 
#define TRANSITION_LEFT           4 
#define SUB_MENU_TRANSITION       5 
#define DISPLAY_DEMO_TITLE        6 
#define DISPLAY_DEMO_DESCRIPTION  7 
/*
#define BLINK_COLON   0x0008000000000000UL ///< blink borp (for large font)
#define BLINK_HOUR_T  0xF800000000000000UL// 11111x
#define BLINK_HOUR_O  0x03E0000000000000UL// 0000 0x11 111
#define BLINK_MIN_T   0x0003E00000000000UL// 0000 0x00 000x 0x11 1110
#define BLINK_MIN_O   0x00000F8000000000UL// 0000 0x00 000x 0x00 000x 1111 1
*/
#define BLINK_COLON   0x0080000000000000UL ///< blink borp (for narrow font)
#define BLINK_HOUR_T  0xE000000000000000UL//
#define BLINK_HOUR_O  0x0E00000000000000UL//
#define BLINK_MIN_T   0x0038000000000000UL//
#define BLINK_MIN_O   0x0003800000000000UL//

#define TITLE_DELAY 10

#define UI_LEFT 0
#define UI_CIRCLE 1
#define UI_RIGHT 2
#define UI_BTN_MAX 3

typedef struct ui_tag
{
    uint8_t goto_sleep;
    char demo_description[60];
    char demo_title[60];
    int8_t state_internal;
    int8_t menu_state;
    int8_t menu_state_max;
    int8_t submenu_state;
    int8_t submenu_state_max;
    lcd *p_lcd;
    uint8_t button_event[UI_BTN_MAX];
    uint8_t button_state[UI_BTN_MAX];
    uint8_t button_state_prev[UI_BTN_MAX];
    uint8_t demo_description_delay;
    uint8_t demo_title_delay;
    uint8_t btn_left_event;
    uint8_t btn_right_event;
    uint32_t refresh_rate_while_scrolling;
    uint32_t Fosc;
    uint32_t refresh_rate_not_scrolling;
    void (*menu)(void);
}ui;

void ui_callback_set_scroll_speed(uint32_t FOSC, uint32_t f);
/**
 * \brief Allocates and initlizes a new UI Object
 * \param ui_menu_callback The user-selected menuing function
 * \returns reference to newly created UI object
 *
 *
 */
ui* ui_new(void (*ui_menu_callback)(void));
uint8_t ui_btn_pressed(ui *p, uint8_t btn);
uint8_t ui_tasks(ui *p);

/** @} */
#endif //UI_H

