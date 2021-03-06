/*
 * project.c
 *
 *  Created on: Oct 12, 2021
 *      Author: Fayrouz
 */



#include "ultrasonic.h"
#include"lcd.h"
#include <util/delay.h> /* For the delay functions */
#include <avr/io.h> /* To use the SREG register */


int main(void)
{
	SREG |= (1<<7);	  /* Enable Global Interrupt I-Bit */
	uint16 distance;
	LCD_init();
	LCD_displayStringRowColumn(0,0,"Distance =");

	while (1)
	{
		Ultrasonic_init();
		distance=Ultrasonic_readDistance();
			LCD_moveCursor(0, 11);
			LCD_intgerToString(distance);
			LCD_displayStringRowColumn(0,14,"cm");
	}
}
