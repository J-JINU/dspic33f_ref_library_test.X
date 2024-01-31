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
FINAL_IMAGE=${DISTDIR}/dspic33f_ref_library_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/dspic33f_ref_library_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=dspic33fj256gp710aLIB/ADC.c dspic33fj256gp710aLIB/AT45DB021D.c dspic33fj256gp710aLIB/CAN.c dspic33fj256gp710aLIB/gpio.c dspic33fj256gp710aLIB/MCP3201.c dspic33fj256gp710aLIB/PWM.c dspic33fj256gp710aLIB/SPI.c dspic33fj256gp710aLIB/system.c dspic33fj256gp710aLIB/timer.c dspic33fj256gp710aLIB/UART.c dspic33fj256gp710aLIB/DMA.c dspic33fj256gp710aLIB/InputCapture.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o.d ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=dspic33fj256gp710aLIB/ADC.c dspic33fj256gp710aLIB/AT45DB021D.c dspic33fj256gp710aLIB/CAN.c dspic33fj256gp710aLIB/gpio.c dspic33fj256gp710aLIB/MCP3201.c dspic33fj256gp710aLIB/PWM.c dspic33fj256gp710aLIB/SPI.c dspic33fj256gp710aLIB/system.c dspic33fj256gp710aLIB/timer.c dspic33fj256gp710aLIB/UART.c dspic33fj256gp710aLIB/DMA.c dspic33fj256gp710aLIB/InputCapture.c main.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/dspic33f_ref_library_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ256GP710A
MP_LINKER_FILE_OPTION=,--script=p33FJ256GP710A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o: dspic33fj256gp710aLIB/ADC.c  .generated_files/flags/default/9c17cd409dc4aad5729aa166d6d96f084960fd3c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/ADC.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o: dspic33fj256gp710aLIB/AT45DB021D.c  .generated_files/flags/default/89bc68f6ba4cdd09400da10d4f1dca7e1571b4cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/AT45DB021D.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o: dspic33fj256gp710aLIB/CAN.c  .generated_files/flags/default/9334da5863e7cbc7a86b947a299bf42bfabde8a1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/CAN.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o: dspic33fj256gp710aLIB/gpio.c  .generated_files/flags/default/5b3e4d58efb2803f3f0315910f3faf5667fc2e19 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/gpio.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o: dspic33fj256gp710aLIB/MCP3201.c  .generated_files/flags/default/c83c11ba63258f776ed4fda62a9c46e698caf1d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/MCP3201.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o: dspic33fj256gp710aLIB/PWM.c  .generated_files/flags/default/bb63318d84a14ac6a83b14fec0c062f141b400c5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/PWM.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o: dspic33fj256gp710aLIB/SPI.c  .generated_files/flags/default/328ccfbe37d2dd6766905170f51174cae34d662f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/SPI.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/system.o: dspic33fj256gp710aLIB/system.c  .generated_files/flags/default/86fb4776799ae44a702d9df868eed7da3515b3c3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/system.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o: dspic33fj256gp710aLIB/timer.c  .generated_files/flags/default/47a474001a5d2a2339127b57b088e78f39549cb1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/timer.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o: dspic33fj256gp710aLIB/UART.c  .generated_files/flags/default/c4649456e11eff81007a3b5a38f639263df17ce4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/UART.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o: dspic33fj256gp710aLIB/DMA.c  .generated_files/flags/default/f3b4e0b3e3150c378291f1df1de8b4193fca292c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/DMA.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o: dspic33fj256gp710aLIB/InputCapture.c  .generated_files/flags/default/21dcea637ecd2afa973981446ab84b2c35b4522b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/InputCapture.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/88b286e3bc353b190a1d349e6ea658a3f7d83324 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o: dspic33fj256gp710aLIB/ADC.c  .generated_files/flags/default/ff9e88d87fef9fec8ca20ef3547f30e50cd63887 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/ADC.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/ADC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o: dspic33fj256gp710aLIB/AT45DB021D.c  .generated_files/flags/default/5c6ad35320978cb3d4546b8a046fc8b2d3c8267d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/AT45DB021D.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/AT45DB021D.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o: dspic33fj256gp710aLIB/CAN.c  .generated_files/flags/default/18ed9337603691128ba2f5beb6d54e71867b1506 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/CAN.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/CAN.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o: dspic33fj256gp710aLIB/gpio.c  .generated_files/flags/default/6e4915c1018a292d91b961edb68dc5aa23d6e0e0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/gpio.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/gpio.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o: dspic33fj256gp710aLIB/MCP3201.c  .generated_files/flags/default/731152cb6bde459ff3b68add7947a8194dc083c4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/MCP3201.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/MCP3201.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o: dspic33fj256gp710aLIB/PWM.c  .generated_files/flags/default/80157b704f0d10a4b9a1e319e34633d4df1d3e47 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/PWM.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/PWM.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o: dspic33fj256gp710aLIB/SPI.c  .generated_files/flags/default/36e3cd716dcf6b19c7c96879fd3ac6f2330bb5f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/SPI.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/SPI.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/system.o: dspic33fj256gp710aLIB/system.c  .generated_files/flags/default/7469e155569c21daf639a70d679cbcd6afacbf8b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/system.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/system.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o: dspic33fj256gp710aLIB/timer.c  .generated_files/flags/default/1f9f970b52b39d56f156fb8ed21a533566d32e2d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/timer.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o: dspic33fj256gp710aLIB/UART.c  .generated_files/flags/default/8d079a5829b704df48312392732fa47c64631b46 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/UART.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/UART.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o: dspic33fj256gp710aLIB/DMA.c  .generated_files/flags/default/152e839684ff4513cd7c9d103ba8d1797f1703e1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/DMA.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/DMA.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o: dspic33fj256gp710aLIB/InputCapture.c  .generated_files/flags/default/a39b93194e1c9d48a5541236d17ba39f37560019 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/dspic33fj256gp710aLIB" 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o.d 
	@${RM} ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  dspic33fj256gp710aLIB/InputCapture.c  -o ${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/dspic33fj256gp710aLIB/InputCapture.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/c16b93dbbd96c4881832d1dbbe879006096297cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${DISTDIR}/dspic33f_ref_library_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/dspic33f_ref_library_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/dspic33f_ref_library_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/dspic33f_ref_library_test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/dspic33f_ref_library_test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
