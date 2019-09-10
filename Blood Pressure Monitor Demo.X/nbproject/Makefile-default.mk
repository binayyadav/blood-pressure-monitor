#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Blood_Pressure_Monitor_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Blood_Pressure_Monitor_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../libraries/src/GCXSRC/mcu_adc_pipeline.c ../libraries/src/GCXSRC/sigma_delta_adc.c ../libraries/src/GCXSRC/main.c ../libraries/src/GCXSRC/usb_config.c ../libraries/src/GCXSRC/usb_descriptors.c ../libraries/src/GCXSRC/usb_gc010.c ../libraries/src/GCXSRC/waveform_tables.c ../libraries/src/GCXSRC/filter.c ../libraries/src/lcd.c ../libraries/src/math.c ../libraries/src/timer.c ../libraries/src/ui.c ../libraries/src/rtcc.c "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchAcquistion.c" "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchButton.c" "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchControl.c" "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchDebug.c" "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchSensor.c" ../Microchip/USB/usb_device.c "../Microchip/USB/CDC Device Driver/usb_function_cdc.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o ${OBJECTDIR}/_ext/921424376/main.o ${OBJECTDIR}/_ext/921424376/usb_config.o ${OBJECTDIR}/_ext/921424376/usb_descriptors.o ${OBJECTDIR}/_ext/921424376/usb_gc010.o ${OBJECTDIR}/_ext/921424376/waveform_tables.o ${OBJECTDIR}/_ext/921424376/filter.o ${OBJECTDIR}/_ext/1977167009/lcd.o ${OBJECTDIR}/_ext/1977167009/math.o ${OBJECTDIR}/_ext/1977167009/timer.o ${OBJECTDIR}/_ext/1977167009/ui.o ${OBJECTDIR}/_ext/1977167009/rtcc.o ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o ${OBJECTDIR}/_ext/1799924381/mTouchButton.o ${OBJECTDIR}/_ext/1799924381/mTouchControl.o ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o ${OBJECTDIR}/_ext/343710134/usb_device.o ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o.d ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o.d ${OBJECTDIR}/_ext/921424376/main.o.d ${OBJECTDIR}/_ext/921424376/usb_config.o.d ${OBJECTDIR}/_ext/921424376/usb_descriptors.o.d ${OBJECTDIR}/_ext/921424376/usb_gc010.o.d ${OBJECTDIR}/_ext/921424376/waveform_tables.o.d ${OBJECTDIR}/_ext/921424376/filter.o.d ${OBJECTDIR}/_ext/1977167009/lcd.o.d ${OBJECTDIR}/_ext/1977167009/math.o.d ${OBJECTDIR}/_ext/1977167009/timer.o.d ${OBJECTDIR}/_ext/1977167009/ui.o.d ${OBJECTDIR}/_ext/1977167009/rtcc.o.d ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o.d ${OBJECTDIR}/_ext/1799924381/mTouchButton.o.d ${OBJECTDIR}/_ext/1799924381/mTouchControl.o.d ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o.d ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o.d ${OBJECTDIR}/_ext/343710134/usb_device.o.d ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o ${OBJECTDIR}/_ext/921424376/main.o ${OBJECTDIR}/_ext/921424376/usb_config.o ${OBJECTDIR}/_ext/921424376/usb_descriptors.o ${OBJECTDIR}/_ext/921424376/usb_gc010.o ${OBJECTDIR}/_ext/921424376/waveform_tables.o ${OBJECTDIR}/_ext/921424376/filter.o ${OBJECTDIR}/_ext/1977167009/lcd.o ${OBJECTDIR}/_ext/1977167009/math.o ${OBJECTDIR}/_ext/1977167009/timer.o ${OBJECTDIR}/_ext/1977167009/ui.o ${OBJECTDIR}/_ext/1977167009/rtcc.o ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o ${OBJECTDIR}/_ext/1799924381/mTouchButton.o ${OBJECTDIR}/_ext/1799924381/mTouchControl.o ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o ${OBJECTDIR}/_ext/343710134/usb_device.o ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o

# Source Files
SOURCEFILES=../libraries/src/GCXSRC/mcu_adc_pipeline.c ../libraries/src/GCXSRC/sigma_delta_adc.c ../libraries/src/GCXSRC/main.c ../libraries/src/GCXSRC/usb_config.c ../libraries/src/GCXSRC/usb_descriptors.c ../libraries/src/GCXSRC/usb_gc010.c ../libraries/src/GCXSRC/waveform_tables.c ../libraries/src/GCXSRC/filter.c ../libraries/src/lcd.c ../libraries/src/math.c ../libraries/src/timer.c ../libraries/src/ui.c ../libraries/src/rtcc.c ../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchAcquistion.c ../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchButton.c ../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchControl.c ../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchDebug.c ../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchSensor.c ../Microchip/USB/usb_device.c ../Microchip/USB/CDC Device Driver/usb_function_cdc.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Blood_Pressure_Monitor_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GC010
MP_LINKER_FILE_OPTION=,--script=p24FJ128GC010.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o: ../libraries/src/GCXSRC/mcu_adc_pipeline.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/mcu_adc_pipeline.c  -o ${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o: ../libraries/src/GCXSRC/sigma_delta_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/sigma_delta_adc.c  -o ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/main.o: ../libraries/src/GCXSRC/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/main.c  -o ${OBJECTDIR}/_ext/921424376/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/usb_config.o: ../libraries/src/GCXSRC/usb_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/usb_config.c  -o ${OBJECTDIR}/_ext/921424376/usb_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/usb_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/usb_config.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/usb_descriptors.o: ../libraries/src/GCXSRC/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/usb_descriptors.c  -o ${OBJECTDIR}/_ext/921424376/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/usb_descriptors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/usb_descriptors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/usb_gc010.o: ../libraries/src/GCXSRC/usb_gc010.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_gc010.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_gc010.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/usb_gc010.c  -o ${OBJECTDIR}/_ext/921424376/usb_gc010.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/usb_gc010.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/usb_gc010.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/waveform_tables.o: ../libraries/src/GCXSRC/waveform_tables.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/waveform_tables.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/waveform_tables.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/waveform_tables.c  -o ${OBJECTDIR}/_ext/921424376/waveform_tables.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/waveform_tables.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/waveform_tables.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/filter.o: ../libraries/src/GCXSRC/filter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/filter.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/filter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/filter.c  -o ${OBJECTDIR}/_ext/921424376/filter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/filter.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/filter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/lcd.o: ../libraries/src/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/lcd.c  -o ${OBJECTDIR}/_ext/1977167009/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/lcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/lcd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/math.o: ../libraries/src/math.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/math.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/math.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/math.c  -o ${OBJECTDIR}/_ext/1977167009/math.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/math.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/math.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/timer.o: ../libraries/src/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/timer.c  -o ${OBJECTDIR}/_ext/1977167009/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/ui.o: ../libraries/src/ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/ui.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/ui.c  -o ${OBJECTDIR}/_ext/1977167009/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/ui.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/ui.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/rtcc.o: ../libraries/src/rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/rtcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/rtcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/rtcc.c  -o ${OBJECTDIR}/_ext/1977167009/rtcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/rtcc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/rtcc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchAcquistion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchAcquistion.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchButton.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchButton.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchButton.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchButton.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchButton.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchButton.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchButton.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchButton.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchControl.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchControl.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchDebug.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchDebug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchDebug.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchDebug.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchDebug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchSensor.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchSensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchSensor.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchSensor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchSensor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/343710134/usb_device.o: ../Microchip/USB/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/343710134 
	@${RM} ${OBJECTDIR}/_ext/343710134/usb_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/343710134/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Microchip/USB/usb_device.c  -o ${OBJECTDIR}/_ext/343710134/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/343710134/usb_device.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/343710134/usb_device.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/131024517/usb_function_cdc.o: ../Microchip/USB/CDC\ Device\ Driver/usb_function_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/131024517 
	@${RM} ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/USB/CDC Device Driver/usb_function_cdc.c"  -o ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/131024517/usb_function_cdc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/131024517/usb_function_cdc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o: ../libraries/src/GCXSRC/mcu_adc_pipeline.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/mcu_adc_pipeline.c  -o ${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/mcu_adc_pipeline.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o: ../libraries/src/GCXSRC/sigma_delta_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/sigma_delta_adc.c  -o ${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/sigma_delta_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/main.o: ../libraries/src/GCXSRC/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/main.c  -o ${OBJECTDIR}/_ext/921424376/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/main.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/usb_config.o: ../libraries/src/GCXSRC/usb_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/usb_config.c  -o ${OBJECTDIR}/_ext/921424376/usb_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/usb_config.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/usb_config.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/usb_descriptors.o: ../libraries/src/GCXSRC/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/usb_descriptors.c  -o ${OBJECTDIR}/_ext/921424376/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/usb_descriptors.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/usb_descriptors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/usb_gc010.o: ../libraries/src/GCXSRC/usb_gc010.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_gc010.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/usb_gc010.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/usb_gc010.c  -o ${OBJECTDIR}/_ext/921424376/usb_gc010.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/usb_gc010.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/usb_gc010.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/waveform_tables.o: ../libraries/src/GCXSRC/waveform_tables.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/waveform_tables.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/waveform_tables.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/waveform_tables.c  -o ${OBJECTDIR}/_ext/921424376/waveform_tables.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/waveform_tables.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/waveform_tables.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/921424376/filter.o: ../libraries/src/GCXSRC/filter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/921424376 
	@${RM} ${OBJECTDIR}/_ext/921424376/filter.o.d 
	@${RM} ${OBJECTDIR}/_ext/921424376/filter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/GCXSRC/filter.c  -o ${OBJECTDIR}/_ext/921424376/filter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/921424376/filter.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/921424376/filter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/lcd.o: ../libraries/src/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/lcd.c  -o ${OBJECTDIR}/_ext/1977167009/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/lcd.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/lcd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/math.o: ../libraries/src/math.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/math.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/math.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/math.c  -o ${OBJECTDIR}/_ext/1977167009/math.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/math.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/math.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/timer.o: ../libraries/src/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/timer.c  -o ${OBJECTDIR}/_ext/1977167009/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/timer.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/ui.o: ../libraries/src/ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/ui.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/ui.c  -o ${OBJECTDIR}/_ext/1977167009/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/ui.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/ui.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1977167009/rtcc.o: ../libraries/src/rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977167009 
	@${RM} ${OBJECTDIR}/_ext/1977167009/rtcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977167009/rtcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libraries/src/rtcc.c  -o ${OBJECTDIR}/_ext/1977167009/rtcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1977167009/rtcc.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977167009/rtcc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchAcquistion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchAcquistion.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchAcquistion.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchButton.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchButton.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchButton.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchButton.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchButton.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchButton.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchButton.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchButton.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchControl.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchControl.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchControl.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchDebug.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchDebug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchDebug.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchDebug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchDebug.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchDebug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1799924381/mTouchSensor.o: ../Microchip/mTouchCap/PIC18F\ PIC24F\ Library/mTouchSensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1799924381 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/mTouchCap/PIC18F PIC24F Library/mTouchSensor.c"  -o ${OBJECTDIR}/_ext/1799924381/mTouchSensor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1799924381/mTouchSensor.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1799924381/mTouchSensor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/343710134/usb_device.o: ../Microchip/USB/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/343710134 
	@${RM} ${OBJECTDIR}/_ext/343710134/usb_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/343710134/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Microchip/USB/usb_device.c  -o ${OBJECTDIR}/_ext/343710134/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/343710134/usb_device.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/343710134/usb_device.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/131024517/usb_function_cdc.o: ../Microchip/USB/CDC\ Device\ Driver/usb_function_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/131024517 
	@${RM} ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Microchip/USB/CDC Device Driver/usb_function_cdc.c"  -o ${OBJECTDIR}/_ext/131024517/usb_function_cdc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/131024517/usb_function_cdc.o.d"        -g -omf=elf -O0 -I"../Microchip/Include/mTouchCap/PIC18F PIC24F Library" -I"../Microchip/Include/USB" -I"../Microchip/Include" -I"../Microchip" -I"../libraries/src/include" -I"../libraries/src/GCXSRC/" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/131024517/usb_function_cdc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Blood_Pressure_Monitor_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Blood_Pressure_Monitor_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--heap=2500,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="../../../../../../Program Files/Microchip/xc16/v1.10/lib",--no-force-link,--smart-io,-Map="${DISTDIR}/PIC24FJ128GC010Demo.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Blood_Pressure_Monitor_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Blood_Pressure_Monitor_Demo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=2500,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="../../../../../../Program Files/Microchip/xc16/v1.10/lib",--no-force-link,--smart-io,-Map="${DISTDIR}/PIC24FJ128GC010Demo.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Blood_Pressure_Monitor_Demo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
