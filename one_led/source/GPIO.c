/*
 * GPIO.c
 *
 *  Created on: Sep 4, 2018
 *      Author: marga
 */

#include "GPIO.h"
#include "MK64F12.h"



/*
	\brief
 	 	 This function configure different characteristics in an specific GPIO:
 	 	 pullup or pulldown resistor,alternative functions in the GPIO
 	 \param[in] portName Port to be configured.
 	 \param[in]  pin Specific pin to be configured.
 	 \param[in]  pinControlRegister Pointer to a constant configuration value that configures the pin characteristics. In particular this function
 	 uses the definitions GPIO_PS, GPIO_PE, GPIO_MUX1 etc. For example, in order to configure the pullup resistor ans the pin as GPIO it is need to
 	 declare the type in following way:
 	 GPIO_pinControlRegisterType PinControlRegister = GPIO_MUX1|GPIO_PS|GPIO_PE;
 	 \return 1 if the portName is valid else return 0

 */
uint8 GPIO_pinControlRegister(GPIO_portNameType portName, uint8 pin, const GPIO_pinControlRegisterType*  pinControlRegister)
{
	switch(portName)
		{
			case (GPIO_A):	/** GPIO A is selected*/
				PORTA->PCR[pin] = *pinControlRegister;
				break;
			case (GPIO_B):	/** GPIO B is selected*/
				PORTB->PCR[pin] = *pinControlRegister;
				break;
			case (GPIO_C):	/** GPIO C is selected*/
				PORTC->PCR[pin] = *pinControlRegister;
				break;
			case (GPIO_D):	/** GPIO D is selected*/
				PORTD->PCR[pin] = *pinControlRegister;
				break;
			case (GPIO_E):	/** GPIO E is selected*/
				PORTE->PCR[pin] = *pinControlRegister;
				break;
			default:
				return (FALSE);
				break;
		}
	return (TRUE);
}


/*
 \brief
 	 	 This function configures a specific GPIO pin as input or as output
 	 \param[in] portName Port to be configured.
 	 \param[in]  pinConf value to set on previously specified pin
 	 \return void
 */
void GPIO_dataDirectionRegister(GPIO_portNameType portName, uint32 portConf)
{
	switch(portName)
	{
		case (GPIO_A):
			GPIOA->PDDR = portConf;
			break;
		case (GPIO_B):
			GPIOB->PDDR = portConf;
			break;
		case (GPIO_C):
			GPIOC->PDDR = portConf;
			break;
		case (GPIO_D):
			GPIOD->PDDR = portConf;
			break;
		case (GPIO_E):
			GPIOE->PDDR = portConf;
			break;
		default:
			break;
	}
}


/*
 \brief
 	 	 This function configures a specific GPIO pin as input or as output
 	 \param[in] portName Port to be configured.
 	 \param[in]  data value to be set on the specific port.
 	 \return void
 */
void GPIO_dataOutputRegister(GPIO_portNameType portName, uint32 data)
{
	switch(portName)
	{
		case (GPIO_A):
			GPIOA->PDOR = data;
			break;
		case (GPIO_B):
			GPIOB->PDOR = data;
			break;
		case (GPIO_C):
			GPIOC->PDOR = data;
			break;
		case (GPIO_D):
			GPIOD->PDOR = data;
			break;
		case (GPIO_E):
			GPIOE->PDOR = data;
			break;
		default:
			break;
	}
}



/*!
 	 \brief	 This function enables the GPIO clock by configuring the corresponding bit
 	 	 and register in the System Clock Gating Control Register.

 	 \param[in]  portName Port to be configured.
 	 \return 1 if the portName is valid else return 0
 */
void GPIO_clockGating(GPIO_portNameType portName)
{
	switch(portName)
	{
		case (GPIO_A):
			SIM->SCGC5 |= GPIO_SCGC5_PORTA;
			break;
		case (GPIO_B):
			SIM->SCGC5 |= GPIO_SCGC5_PORTB;
			break;
		case (GPIO_C):
			SIM->SCGC5 |= GPIO_SCGC5_PORTC;
			break;
		case (GPIO_D):
			SIM->SCGC5 |= GPIO_SCGC5_PORTD;
			break;
		case (GPIO_E):
			SIM->SCGC5 |= GPIO_SCGC5_PORTE;
			break;
		default:
			break;
	}
}

