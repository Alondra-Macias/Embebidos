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

//activar switches
//atrapar valor de cada uno
#include <stdio.h>
#include "DataTypeDefinitions.h"
#include "MK64F12.h"

void delay(uint16 delay);
/*
 * @brief   Application entry point.
 */
int main(void) {
	/**Variable to capture the input value*/
			uint32 inputValue = 0;
	
	/*Initializes Clock Gating for ports A, B, C and E*/
  SIM->SCGC5 = 0x2E00;
  /*Configure pins for GPIO*/
  PORTA->PCR[4] = 0x00000103; //SWITCH3
  PORTB->PCR[21] = PORT_PCR_MUX(1);
  PORTB->PCR[22] = PORT_PCR_MUX(1);
  PORTC->PCR[6] = 0x00000103;	//SWITCH2
  PORTE->PCR[26] = PORT_PCR_MUX(1);
  
  /**Assigns a safe value to the output pin21 of the GPIOB*/
  GPIOB->PDOR = 0x00200000;
  /**Assigns a safe value to the output pin22 of the GPIOB*/
  GPIOB->PDOR |= 0x00400000;
  /**Assigns a safe value to the output pin26 of the GPIOE*/
  GPIOE->PDOR |= 0x04000000;

	GPIOC->PDDR &=~(0x40);
	GPIOA->PDDR &=~(0x10);
	/**Configures GPIOB pin21 as output*/
	GPIOB->PDDR = 0x00200000;
	/**Configures GPIOB pin22 as output*/
	GPIOB->PDDR |= 0x00400000;
	/**Configures GPIOE pin26 as output*/
	GPIOE->PDDR |= 0x04000000;

	int contador=0;
    while(1) {
    	/**Reads all the GPIOC*/
		inputValue = GPIOC->PDIR;
		/**Masks the GPIOC in the bit of interest*/
		inputValue = inputValue & 0x50;
		/**Note that the comparison is not inputValur == False, because it is safer if we switch the arguments*/
		if (contador>=5 ){contador=0;}
		else if (contador==0){contador=5;}
		if(0x50 == inputValue ) //evaluar primero si los 2 estan apretados?
		{GPIOB->PDOR &= ~0x00200000;/**Blue led off*/
		GPIOE->PDOR &= ~(0x4000000);/**Green led on*/
		GPIOB->PDOR &= ~(0x00400000);/**Red led on*/
		delay(65000);
		}
		else if (0x40 == inputValue) //evaluar sw2
		{
			contador++;
		}
		else if (0x10 == inputValue) //evaluar  sw3
		{
			contador--;
		}

		switch(contador){ //0: apagar todo 1:verde 2:azul 3:morado 4:rojo 5:amarillo
		case 0:
			GPIOB->PDOR |= 0x00200000;/**Blue led off*/
			delay(65000);
			GPIOB->PDOR |= 0x00400000;/**Read led off*/
			delay(65000);
			GPIOE->PDOR |= 0x4000000;/**Green led off*/
			delay(65000);
			break;
		case 1: //yellow
			GPIOB->PDOR &= ~(0x0400000);/**red led on*/
			GPIOE->PDOR &= ~(0x4000000);/**Green led on*/
			delay(65000);
			break;
		case 2: //red
			GPIOB->PDOR &= ~(0x00400000);/**Red led on*/
			delay(65000);
			break;
		case 3: //purple
			GPIOB->PDOR &= ~(0x00400000);/**Red led on*/
			GPIOB->PDOR &= ~0x00200000;/**Blue led off*/
			delay(65000);
			break;
		case 4: //blue
			GPIOB->PDOR &= ~0x00200000;/**Blue led off*/
			delay(65000);
			break;
		case 5: //green
			GPIOE->PDOR &= ~(0x4000000);/**Green led on*/
			delay(65000);
			break;
		case 6: //white
			GPIOE->PDOR &= ~(0x4000000);/**Green led on*/
						delay(65000);
				default:
		break;			 }

		//apagar todo de nuevo
			GPIOB->PDOR |= 0x00200000;/**Blue led off*/
			delay(65000);
			GPIOB->PDOR |= 0x00400000;/**Read led off*/
			delay(65000);
			GPIOE->PDOR |= 0x4000000;/**Green led off*/
			delay(65000);
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
