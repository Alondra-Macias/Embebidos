/*
 * RGB.h
 *
 *  Created on: 05/09/2018
 *      Author: AlondraItzel
 */
#include "GPIO.h"
#include "GPIO.c"
#include "MK64F12.h"
#include "DataTypeDefinitions.h"

#ifndef RGB_H_
#define RGB_H_


#define	Blue 0x00200000//Blue led
#define Green 0x4000000//Green led
#define Red  0x00400000//Red led on
#define PinSw 0x00000103 //pin switches
#define SW3pin 4
#define SW2pin 6
//#define PCSW 0x00000103
#define PinRed 22
#define PinBlue 21
#define PinGreen 26
#define Pin6 0x40
#define Pin4 0x10
#define Mask1 0x50;

//1:verde 2:azul 3:morado 4:rojo 5:amarillo
 typedef enum{Verde, /*!< Definition to select GPIO A */
			 Azul, /*!< Definition to select GPIO B */
			 Morado, /*!< Definition to select GPIO C */
			 Rojo, /*!< Definition to select GPIO D */
			 Amarillo, /*!< Definition to select GPIO E */
			 Blanco  /*!< Definition to select GPIO F */
			} LED_Color;

void RGB_on(LED_Color color);
void RGBySw_CR();
void RGB_PDOR();
void RGB_DR();
void init_CG();
uint8 GetSw();



#endif /* RGB_H_ */
