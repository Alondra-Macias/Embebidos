/*
 * RGB.c
 *
 *  Created on: Sep 5, 2018
 *      Author: marga
 */

#include "RGB.h"
#include "GPIO.h"

/*This function turns on the proper color combination to show the selected color*/
void LED_On(RGB_color color){
	switch(color)
	{
		case RGB_white:
			GPIO_dataOutputRegister(GPIO_B, ~(RGB_PurpleLED));
			GPIO_dataOutputRegister(GPIO_E, ~(RGB_GreenLED));
			break;
		case RGB_red:
			GPIO_dataOutputRegister(GPIO_B, ~(RGB_RedLED));
			GPIO_dataOutputRegister(GPIO_E, RGB_LEDsOff);
			break;
		case RGB_blue:
			GPIO_dataOutputRegister(GPIO_B, ~(RGB_BlueLED));
			GPIO_dataOutputRegister(GPIO_E, RGB_LEDsOff);
			break;
		case RGB_green:
			GPIO_dataOutputRegister(GPIO_B, RGB_LEDsOff);
			GPIO_dataOutputRegister(GPIO_E, ~(RGB_GreenLED));
			break;
		case RGB_purple:
			GPIO_dataOutputRegister(GPIO_E, RGB_LEDsOff);
			GPIO_dataOutputRegister(GPIO_B, ~(RGB_PurpleLED));
			break;
		case RGB_yellow:
			GPIO_dataOutputRegister(GPIO_B, ~(RGB_RedLED));
			GPIO_dataOutputRegister(GPIO_E, ~(RGB_GreenLED));
			break;
		default:
			break;
	}
}


void LED_setUp(){
	/*Configures Blue LED as ALT1*/
	GPIO_pinControlRegister(GPIO_B,  BlueLED_pin, GPIO_MUX_1);
	/*Configures Red LED as ALT1*/
	GPIO_pinControlRegister(GPIO_E, GreenLED_pin, GPIO_MUX_1);
	/*Configures Green LED as ALT1*/
	GPIO_pinControlRegister(GPIO_B,  RedLED_pin, GPIO_MUX_1);

	 /**Configures GPIOB pins 21 and 22 as output*/
	GPIO_dataDirectionRegister(GPIO_B, RGB_BlueLED | RGB_RedLED);
	/**Configures GPIOB pin22 as output*/
	GPIO_dataDirectionRegister(GPIO_E, RGB_GreenLED);
}


void SW_setUp(){

	/*Configures SW2 as ALT1, with Pull up resistor enabled */
	GPIO_pinControlRegister(GPIO_C, SW2_pin, GPIO_MUX_1 | GPIO_PS | GPIO_PE);
	/*Configures SW3 as ALT1, with Pull up resistor enabled */
	GPIO_pinControlRegister(GPIO_A, SW3_pin, GPIO_MUX_1 | GPIO_PS | GPIO_PE);

	/*configures Sw2 as input*/
	GPIO_dataDirectionRegister(GPIO_C, ~(SW2_port));
	/*configures Sw3 as input*/
	GPIO_dataDirectionRegister(GPIO_A, ~(SW3_port));
}


void LEDsOff(){
	/*Turns off LEDs red and blue on port B*/
	GPIO_dataOutputRegister(GPIO_B, RGB_purple);
	/*Turns off green LED on port E*/
	GPIO_dataOutputRegister(GPIO_E,	RGB_green);
}

