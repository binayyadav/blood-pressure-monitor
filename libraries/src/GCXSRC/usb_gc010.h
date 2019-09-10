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

#ifndef USB_GC010_H
#define USB_GC010_H
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "./USB/usb.h"
#include "./USB/usb_function_cdc.h"
#include "Compiler.h"
#include "GenericTypeDefs.h"
#include "HardwareProfile.h"
#include "USB/usb.h"
#include "USB/usb_device.h"
#include "usb_config.h"

void USBCBWakeFromSuspend(void);
void USBCB_SOF_Handler(void);
void USBCBErrorHandler(void);
void USBCBCheckOtherReq(void);
void USBCBStdSetDscHandler(void);
void USBCBInitEP(void);
void USBCBSendResume(void);
BOOL USER_USB_CALLBACK_EVENT_HANDLER(int event, void *pdata, WORD size);
void usb_gc010_io_processor(void);
void printf_usb(const char *format, ...);

#endif //USB_GC010_H
