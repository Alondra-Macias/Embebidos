/*
 * RGB.h
 *
 *  Created on: Sep 5, 2018
 *      Author: marga
 */

#ifndef RGB_H_
#define RGB_H_
 /*! These constants are used to select a specific color (value) to use in the ports */
typedef enum{
		RGB_white,
		RGB_yellow,
		RGB_red,
		RGB_purple,
		RGB_blue,
		RGB_green
}RGB_color;

/*! These constants are used to select between SW2 and SW3*/
typedef enum{SW2,
			SW3
}SWITCH_name;


/*Value used to manipulate corresponding pin for BLUE LED on port B*/
#define RGB_BlueLED 0x00200000
/*Value used to manipulate corresponding pin for RED LED on port B*/
#define RGB_RedLED 0x00400000
/*Value used to manipulate corresponding pin for GREEN LED on port C*/
#define RGB_GreenLED 0x04000000
/*Value used to turn 1 all pins on a port*/
#define RGB_LEDsOff 0xFFFFFFFF
/*Value used to manipulate corresponding pins for PURPLE LED on port B*/
#define RGB_PurpleLED 0x00600000
/*Value used to manipulate corresponding pin for SW3 on port C*/
#define SW3_port 0x00000010
/*Value used to manipulate corresponding pin for SW2 on port A*/
#define SW2_port 0x00000040

/*Constant that represent the pin number for SW2*/
#define SW2_pin 6
/*Constant that represent the pin number for SW2*3*/
#define SW3_pin 4
/*Constant that represent the pin number for RedLED*/
#define RedLED_pin 22
/*Constant that represent the pin number for BlueLED*/
#define BlueLED_pin 21
/*Constant that represent the pin number for GreenLED*/
#define GreenLED_pin 26



/*
 \brief
 	 	 This function turns on the necessary LEDs to result on the specified color
 	 \param[in]  color The resultant color of the RGB combination
 	 \return void
 */
void LED_On(RGB_color color);


/*
 \brief
 	 	 This function configures the three RGB LEDs as GPIO outputs
 	 \return void
 */
void LED_setUp();

/*
 \brief
 	 	 This function turns all LEDs off
 	 \return void
 */
void LEDsOff();

/*
 \brief
 	 	 This function configures SW2 and SW3 s as GPIO inputs with Pull up resistor enabled
 	 \return void
 */
void SW_setUp();

#endif /* RGB_H_ */
