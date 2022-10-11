/************************************************
* [File Name] : Application.c
* [Description]: Source File of Application
* [Author]: Mahmoud Khaled
* [Data]: 9/10/2022
************************************************/
#include "lcd.h"
#include "ultrasonic.h"
#include "avr/io.h"
int main(){
	/* Enable Global Interrupt  (I-bit) */
	SREG |= (1 << 7);
	/* Initialize LCD Driver */
	LCD_init();
	/* Initialize ultra-sonic sensor */
	Ultrasonic_init();
	/* Declare a variable that will be used to store Distance */
	uint16 Distance = 0;
	/* Display String on LCD Screen that will be displayed All Program execution */
	LCD_displayString("Distance=    cm");
	while(1){
		/* Store Distance read to Variable */
		Distance= Ultrasonic_readDistance();
		/* Move cursor to specific Position To display Distance measured */
		LCD_moveCursor(0, 10);
		/* this check is used when Distance consist of 3 digits and Suddenly Distance consist of 2 digits
		 * The last digit when the distance was 3 digits will remain in the case of 2 digits
		 * so, to avoid this bug --> Print space in the last digit in the case of 2-digits */
		if(Distance >= 100){
			/* Print the digit in the Required Position */
			LCD_integerToString(Distance);
		}
		else{
			/* Print the digit in the Required Position */
			LCD_integerToString(Distance);
			/* Print the Space in the last Position */
			LCD_displayString(" ");
		}
	};
}
