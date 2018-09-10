/*
 * Copyright 2016-2018 NXP Semiconductor, Inc.
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
 * @file    MK64FN1M0xxx12_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
//#include "fsl_debug_console.h"
#include "RGB.h"
#include "Delay.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
/*flags used for input from switches*/
uint8_t FlagPortC = FALSE;
uint8_t FlagPortA = FALSE;

int main(void) {

	uint8_t statePortC = 0;
	uint8_t statePortA = 0;

	gpio_pin_control_register_t input_intr_config = GPIO_MUX1|GPIO_PE|GPIO_PS|INTR_FALLING_EDGE;

	Colors_t color = NO_COLOR;

	RGB_init();

	RGB_red_led_on_off(LED_ON);
	delay(DELAY);
	RGB_red_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_blue_led_on_off(LED_ON);
	delay(DELAY);
	RGB_blue_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_green_led_on_off(LED_ON);
	delay(DELAY);
	RGB_green_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_yellow_led_on_off(LED_ON);
	delay(DELAY);
	RGB_yellow_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_white_led_on_off(LED_ON);
	delay(DELAY);
	RGB_white_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_purple_led_on_off(LED_ON);
	delay(DELAY);
	RGB_purple_led_on_off(LED_OFF);
	delay(DELAY);

	color = RGB_color_selector();

/*this loop make the call to interrupt to do in RGB if any flag is on TRUE*/
    while(1)
    {


    	if(TRUE == FlagPortC)
    	{
        	color = RGB_color_selector();
    		RGB_led_on(color);
    		statePortC = !statePortC;
    		FlagPortC = FALSE;
    	}

    	if(TRUE == FlagPortA)
		{
    		color = RGB_color_selector();
			RGB_led_on(color);
			statePortA = !statePortA;
			FlagPortA = FALSE;
		}


    }
    return 0 ;
}
