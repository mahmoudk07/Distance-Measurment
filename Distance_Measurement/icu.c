/************************************************
* [File Name] : icu.c
* [Description]: Source File of ICU Driver
* [Author]: Mahmoud Khaled
* [Data]: 6/10/2022
************************************************/
#include "icu.h"
#include "common_macros.h"
#include "avr/io.h"
#include "avr/interrupt.h"
/********************************************************************************
 *                       Global variables                                       *
* ******************************************************************************/
/* Global variable to Point to adress of callBack function in Application*/
static volatile void(*callBack_ptr)(void) = NULL;

/********************************************************************************
 *                       Interrupt Service Routines                             *
 *******************************************************************************/
ISR(TIMER1_CAPT_vect){
	if(callBack_ptr != NULL){
		(*callBack_ptr)();
	}
}
/*******************************************************************************
 *                      Functions Definitions                                  *
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
void ICU_init(const Icu_ConfigType* config_ptr){
	/* Configure Pin 6 in DDRD register as input pin*/
	DDRD &= ~(1 << PD6);

	/* Configure Timer1 to operate in Normal Mode */
	TCCR1A = (1 << FOC1A) | (1 << FOC1B);

	/* set clock to Timer1 */
	TCCR1B = (TCCR1B & 0xF8) | (config_ptr->clock);

	/* set edge that will be detected by ICU */
	TCCR1B = (TCCR1B & 0xBF) | ((config_ptr->edge) << 6);

	/* Enable Interrupt capture to generate an interrupt when edge detected*/
	TIMSK = (1 << TICIE1);

	/* Initialize Timer1 with 0 */
	TCNT1 = 0;

	/* Initialize value of Interrupt capture register*/
	ICR1 = 0;
}

/********************************************************************************
* [Function Name]: ICU_setCallback
* [Description]: Function set Pointer argument to Point to Function that will be executed
*                at ISR
* [Arguments]: Pointer that will point to passed Function that will be executed when
*              The interrupt(detection) occurs
* [Returns]: No Return type
********************************************************************************/
void ICU_setCallback(void(*a_ptr)(void)){
	/* Make global variable points to same function to be called in ISR when an detection occur*/
	callBack_ptr = a_ptr;
}

/********************************************************************************
* [Function Name]: ICU_setEdgeDetectionType
* [Description]: Function used to set edge detection by ICU
* [Arguments]: Enum object of type Icu_edge to set edge detection
* [Returns]: No Return type
********************************************************************************/
void ICU_setEdgeDetectionType(const Icu_edge edge){
	/* insert the required edge type in ICES1 bit in TCCR1B Register */
	TCCR1B = (TCCR1B & 0xBF) | (edge << 6);
}

/********************************************************************************
* [Function Name]: Icu_getInputCaptureValue
* [Description]: Function get value exist in Input capture Register ICR1
* [Arguments]: No arguments
* [Returns]: Return 16-bit value exist on Input capture register
********************************************************************************/
uint16 ICU_getInputCaptureValue(void){
	return ICR1;
}

/********************************************************************************
* [Function Name]: ICU_Deinit
* [Description]: Function disable and stop ICU driver
* [Arguments]: No arguments
* [Returns]: No Returns
********************************************************************************/
void ICU_Deinit(void){
	/* Clear Timer Register */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;
	/* Disable Interrupt capture */
	TIMSK &= ~(1 << TICIE1);
}

/********************************************************************************
* [Function Name]: ICU_clearTimerValue
* [Description]: Function clear Timer to start from 0
* [Arguments]: No arguments
* [Returns]: No Returns
********************************************************************************/
void ICU_clearTimerValue(void){
	/* Initialize Timer to start with 0 again */
	TCNT1 = 0;
}

















