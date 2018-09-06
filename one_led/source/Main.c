/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    PushButton.c
 * @brief   Application entry point.
 */

#include "DataTypeDefinitions.h"
#include "MK64F12.h"
#include "RGB.h"
#include "GPIO.h"

/*
 * @brief   Application entry point.
 */
/*ponding pin for Switch 3 on port A*/


/*Value set for use on the delay() function*/
#define DELAY 65000u




void delay(uint16 delay);


int main(void) {
	/**Variable to capture the input value*/
		uint32 inputValue = 0;

	/*Initializes Clock Gating for ports A, B, C and E*/
	  GPIO_clockGating(GPIO_A);
	  GPIO_clockGating(GPIO_B);
	  GPIO_clockGating(GPIO_C);
	  GPIO_clockGating(GPIO_E);

	  /*Configure RGB LED pins for GPIO with MUX_Alt 1 and as output */
	  LED_setUp();
	  /**Assigns a safe value to the output pins 21 and 22 of the GPIOB and for pin 26 of the GPIOE*/
	  LEDsOff();
	  /**Configures for GPIO the switch pins with MUX_Alt 1 and as input with pull-up resistors enabled*/
	  SW_setUp();


	  /*Initializes the counter to the first state*/
		int contador=1;
	    while(1) {
	    	/**Reads all the GPIOC*/
			inputValue = GPIOC->PDIR | GPIOA->PDIR ;
			/**Masks the GPIOC in the bit of interest*/
			inputValue = inputValue & 0x50;
			/**Note that the comparison is not inputValur == False, because it is safer if we switch the arguments*/

			/*Check if both switches are pressed*/
			if(FALSE == inputValue)
			{
				LED_On(RGB_white);	//turns on all LEDs
				delay(DELAY);
			}

			/*Checks if SW2 is either pressed*/
			else if (0x40 == inputValue)
			{
				if (contador>=5 )  //If counter is at top value, restarts its value to the first state
				{
					contador=1;
				}
				else
				{
					contador++;			//Other way, it increments by one the counter
					delay(DELAY);
				}

				/*Checks if SW3 is either pressed*/
			}
			else if (0x10 == inputValue)
			{ 	if (contador<=1)
				{
					contador=6;	 //If counter is at lowest value, restarts its value to the last state
				}
				else
				{
					contador--;		//Decreases counter value by one
					delay(DELAY);
				}
			}


			/*Evaluates the counter's value and turns on the respective LEDs*/
			switch(contador){ //0: apagar todo 1:verde 2:azul 3:morado 4:rojo 5:amarillo
			case RGB_white:
				LEDsOff();
				delay(DELAY);
				break;

			case RGB_yellow: //yellow
				LEDsOff();
				LED_On(RGB_yellow);
				delay(DELAY);
				break;

			case RGB_red:
				LEDsOff();
				LED_On(RGB_red);
				delay(DELAY);
				break;

			case RGB_purple:
				LEDsOff();
				LED_On(RGB_purple);
				delay(DELAY);
				break;

			case RGB_blue:
				LEDsOff();
				LED_On(RGB_blue);
				delay(DELAY);
				break;

			case RGB_green:
				LEDsOff();
				LED_On(RGB_green);
				delay(DELAY);

				break;
			default:
				break;
			}

			delay(DELAY);
	    }
	    return 0 ;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////

void delay(uint16 delay)
{
	volatile uint16 counter;
	for(counter=delay; counter > 0; counter--)
	{
	}
}

