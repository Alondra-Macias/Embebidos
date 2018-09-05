/*
 * RGB.c
 *
 *  Created on: 05/09/2018
 *      Author: AlondraItzel
 */
#include "MK64F12.h"
#include "DataTypeDefinitions.h"
#include "GPIO.h"
#include "RGB.h"




/*void RGBySw_CR(){
		GPIO_pinControlRegister(PORTA, SW3pin, PCSW);
		GPIO_pinControlRegister(PORTB, PinBlue, PORT_PCR_MUX(1));
		GPIO_pinControlRegister(PORTB, PinRed, PORT_PCR_MUX(1));
		GPIO_pinControlRegister(PORTC, SW2pin, PCSW);
		GPIO_pinControlRegister(PORTE, PinGreen, PORT_PCR_MUX(1));
}*/

void RGB_PDOR(){
	GPIO_dataDirectionRegister(GPIO_B, Blue);
	GPIO_dataDirectionRegister(GPIO_B, Red);
	GPIO_dataDirectionRegister(GPIO_E, Green);
	}
void RGB_DR(){
	GPIO_dataDirectionRegister(GPIO_C, Pin6);
	GPIO_dataDirectionRegister(GPIO_A, Pin4);
	GPIO_dataDirectionRegister(GPIO_B, Blue);
	GPIO_dataDirectionRegister(GPIO_B, Red);
	GPIO_dataDirectionRegister(GPIO_E, Green);
}
void init_CG(){	/*Initializes Clock Gating for ports A, B, C and E*/
GPIO_clockGating(GPIO_A);
GPIO_clockGating(GPIO_B);
GPIO_clockGating(GPIO_C);
GPIO_clockGating(GPIO_E);
}

uint8 GetSw(){uint8 value;
	//value = GPIO_inputRegister(GPIO_C); | GPIO_inputRegister(GPIO_A);
	value=value & Mask1;
	return(value);
}
void RGB_on(LED_Color color){
	switch(color)
			{
				case (Verde):	/** GPIO A is selected*/
	         /*	GPIO_dataOutputRegister(GPIO_B, &~Red);
				GPIO_dataOutputRegister(GPIO_B, Blue);
				GPIO_dataOutputRegister(GPIO_B, Red);
				GPIO_dataOutputRegister(GPIO_B, Green);*/
							//GPIOB->PDOR &= ~(0x0400000);/**red led on*/
							//GPIOB->PDOR |= 0x00200000;/**Blue led off*/
							//GPIOE->PDOR &= ~(0x4000000);/**Green led on
					break;
				case (Azul):
					break;
				case (Morado):
					break;
				case (Rojo):
					break;
				case (Amarillo):
					break;
				case (Blanco):
					break;
				default:
					break;
							}
}

