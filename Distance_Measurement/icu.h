/************************************************
* [File Name] : icu.h
* [Description]: Header File of ICU Driver
* [Author]: Mahmoud Khaled
* [Data]: 6/10/2022
************************************************/

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"
/**************************************************
*                   Type declaration              *
**************************************************/
typedef enum{
	No_Clock, F_CPU_CLOCK ,F_CPU_8 , F_CPU_64 , F_CPU_256 , F_CPU_1024
}Icu_clock;

typedef enum{
	Falling , Rising
}Icu_edge;

typedef struct{
	Icu_clock clock; // This member to decide which clock ICU will operate on it //
	Icu_edge edge; // This member to decide which edge ICU will detect //
}Icu_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/********************************************************************************
* [Function Name]: ICU_init
* [Description]: 1- Specify which clock ICU will operate
*                2- Specify whick edge ICU will detect
*                3- Initialize Timer1 Registers
*                4- Enable Interrupt capture
* [Arguments]: Pointer to struct of type ICU_configType to set configuration that
*              ICU will operate on it
* [Returns]: No Return type
********************************************************************************/
void ICU_init(const Icu_ConfigType* config_ptr);

/********************************************************************************
* [Function Name]: ICU_setCallback
* [Description]: Function set Pointer argument to Point to Function that will be executed
*                at ISR
* [Arguments]: Pointer that will point to passed Function that will be executed when
*              The interrupt(detection) occurs
* [Returns]: No Return type
********************************************************************************/
void ICU_setCallback(void(*a_ptr)(void));

/********************************************************************************
* [Function Name]: ICU_setEdgeDetectionType
* [Description]: Function used to set edge detection by ICU
* [Arguments]: Enum object of type Icu_edge to set edge detection
* [Returns]: No Return type
********************************************************************************/
void ICU_setEdgeDetectionType(const Icu_edge edge);

/********************************************************************************
* [Function Name]: Icu_getInputCaptureValue
* [Description]: Function get value exist in Input capture Register ICR1
* [Arguments]: No arguments
* [Returns]: Return 16-bit value exist on Input capture register
********************************************************************************/
uint16 ICU_getInputCaptureValue(void);

/********************************************************************************
* [Function Name]: ICU_Deinit
* [Description]: Function disable and stop ICU driver
* [Arguments]: No arguments
* [Returns]: No Returns
********************************************************************************/
void ICU_Deinit(void);

/********************************************************************************
* [Function Name]: ICU_clearTimerValue
* [Description]: Function clear Timer to start from 0
* [Arguments]: No arguments
* [Returns]: No Returns
********************************************************************************/
void ICU_clearTimerValue(void);

#endif /* ICU_H_ */















