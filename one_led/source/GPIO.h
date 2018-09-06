/*
 * GPIO.h
 *
 *  Created on: Sep 3, 2018
 *      Author: marga
 */

#include "board.h"
#include "DataTypeDefinitions.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#ifndef GPIO_H_
#define GPIO_H_


/** Constant that represent the clock enable for GPIO A */
#define GPIO_SCGC5_PORTA 0x00000200
/** Constant that represent the clock enable for GPIO B */
#define GPIO_SCGC5_PORTB 0x00000400
/** Constant that represent the clock enable for GPIO C */
#define GPIO_SCGC5_PORTC 0x00000800
/** Constant that represent the clock enable for GPIO D */
#define GPIO_SCGC5_PORTD 0x00001000
/** Constant that represent the clock enable for GPIO E */
#define GPIO_SCGC5_PORTE 0x00002000

/*Selects pull-up resistor*/
#define GPIO_PS 0x0000001
/*Enables pull-up/down resistors*/
#define GPIO_PE 0x0000020

/*Selects Alternative 1 for GPIO*/
#define GPIO_MUX_1 0x00000100
/*Selects Alternative 2 for GPIO*/
#define GPIO_MUX_2 0x00000200
/*Selects Alternative 3 for GPIO*/
#define GPIO_MUX_3 0x00000300
/*Selects Alternative 4 for GPIO*/
#define GPIO_MUX_4 0x00000400
/*Selects Alternative 5 for GPIO*/
#define GPIO_MUX_5 0x00000500
/*Selects Alternative 6 for GPIO*/
#define GPIO_MUX_6 0x00000600
/*Selects Alternative 7 for GPIO*/
#define GPIO_MUX_7 0x00000700


/*! This data type is used to configure the pin control register*/
typedef const uint32 GPIO_pinControlRegisterType;

/*Constants used to define if the pin is used as an input or output*/
typedef enum {GPIO_INPUT,/*!< Definition to configure a pin as input */
			  GPIO_OUTPUT /*!< Definition to configure a pin as output */
			 }GPIO_PIN_CONFIG;

 /*! These constants are used to select an specific port in the different API functions*/
 typedef enum{GPIO_A, /*!< Definition to select GPIO A */
			 GPIO_B, /*!< Definition to select GPIO B */
			 GPIO_C, /*!< Definition to select GPIO C */
			 GPIO_D, /*!< Definition to select GPIO D */
			 GPIO_E, /*!< Definition to select GPIO E */
			 GPIO_F  /*!< Definition to select GPIO F */
			} GPIO_portNameType;


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
uint8 GPIO_pinControlRegister(GPIO_portNameType portName, uint8 pinNumber, uint32  pinControlRegister);


/*
 \brief
 	 	 This function configures a specific GPIO pin as input or as output
 	 \param[in] portName Port to be configured.
 	 \param[in]  pin Specific pin to be configured.
 	 \param[in]  pinConf value to set on previously specified pin
 	 \return void
 */
void GPIO_dataDirectionRegister(GPIO_portNameType portName, uint32 pinNumber);


/*
 \brief
 	 	 This function configures a specific GPIO pin as input or as output
 	 \param[in] portName Port to be configured.
 	 \param[in]  data value to be set on the specific port.
 	 \return void
 */
void GPIO_dataOutputRegister(GPIO_portNameType portName, uint32 data);


/*!
 	 \brief	 This function enables the GPIO clock by configuring the corresponding bit
 	 	 and register in the System Clock Gating Control Register.

 	 \param[in]  portName Port to be configured.
 	 \return 1 if the portName is valid else return 0
 */
void GPIO_clockGating(GPIO_portNameType portName);


#endif /* GPIO_H_ */
