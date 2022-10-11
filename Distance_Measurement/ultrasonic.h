/************************************************
* [File Name] : ultrasonic.h
* [Description]: Header File of ultrasonic sensor Driver
* [Author]: Mahmoud Khaled
* [Data]: 9/10/2022
************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
/*******************************************************************
*                        Definitions                               *
*******************************************************************/
#define Ultrasonic_PORT_ID PORTB_ID
#define Ultrasonic_Trigger_PIN_ID PIN5_ID
#define Ultrasonic_Trigger_Pulse 10
/*******************************************************************
*                        Function Prototype                        *
*******************************************************************/

/*******************************************************************
* [Function Name]: Ultrasonic_init
* [Description]: Initialize ICU Driver and setCallback Function
* [Arguments]: No Arguments
* [Returns]: No Return
********************************************************************/
void Ultrasonic_init(void);

/*******************************************************************
* [Function Name]: Ultrasonic_Trigger
* [Description]: Send Trigger Pulse to Ultrasonic Sensor
* [Arguments]: No Arguments
* [Returns]: No Return
********************************************************************/
void Ultrasonic_Trigger(void);

/*******************************************************************
* [Function Name]: Ultrasonic_readDistance
* [Description]: ICU Start Timer when Pulse sends to Ultrasonic Sensor
* [Arguments]: No Arguments
* [Returns]: Returns The Distance Measurement
********************************************************************/
uint16 Ultrasonic_readDistance(void);

/*******************************************************************
* [Function Name]: Ultrasonic_edgeProcessing
* [Description]: Initialize ICU Driver and setCallback Function
* [Arguments]: No Arguments
* [Returns]: No Return
********************************************************************/
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */
