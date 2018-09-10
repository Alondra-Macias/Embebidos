/*
 * RGB.c
 *
 *  Created on: 04/09/2018
 *      Author: jlpe
 */


#include "RGB.h"
#include "NVIC.h"
#include "GPIO.h"


void RGB_init(void)
{   /*initialize the PCR to GPIO*/
	gpio_pin_control_register_t led_config = GPIO_MUX1;
	gpio_pin_control_register_t sw_config = GPIO_MUX1 | GPIO_PE | GPIO_PS | INTR_FALLING_EDGE;
	/*initialize the clocks from the leds*/
	GPIO_clock_gating(BLUE_LED_PORT);
	GPIO_clock_gating(RED_LED_PORT);
	GPIO_clock_gating(GREEN_LED_PORT);
	/*initialize the clocks froms switches*/
	GPIO_clock_gating(SW2_PORT);
	GPIO_clock_gating(SW3_PORT);
	/*initialize the pin from every color*/
	GPIO_set_pin(RED_LED_PORT, RED_LED_PIN);
	GPIO_set_pin(BLUE_LED_PORT, BLUE_LED_PIN);
	GPIO_set_pin(GREEN_LED_PORT, GREEN_LED_PIN);
	/*initialize the PCR from LEDs*/
	GPIO_pin_control_register(BLUE_LED_PORT, BLUE_LED_PIN, &led_config);
	GPIO_pin_control_register(RED_LED_PORT, RED_LED_PIN, &led_config);
	GPIO_pin_control_register(GREEN_LED_PORT, GREEN_LED_PIN, &led_config);
	/*initialize the PCR from switches*/
	GPIO_pin_control_register(SW2_PORT, SW2_PIN, &sw_config);
	GPIO_pin_control_register(SW3_PORT, SW3_PIN, &sw_config);


	/*initialize the direction to output*/
	GPIO_data_direction_pin(BLUE_LED_PORT, GPIO_OUTPUT, BLUE_LED_PIN);
	GPIO_data_direction_pin(RED_LED_PORT, GPIO_OUTPUT, RED_LED_PIN);
	GPIO_data_direction_pin(GREEN_LED_PORT, GPIO_OUTPUT, GREEN_LED_PIN);

	/**Sets the threshold for interrupts, if the interrupt has higher priority constant that the BASEPRI, the interrupt will not be attended*/
	NVIC_setBASEPRI_threshold(PRIORITY_11);
	/**Enables and sets a particular interrupt and its priority*/
	NVIC_enableInterruptAndPriotity(PORTC_IRQ,PRIORITY_10);
	/**Enables and sets a particular interrupt and its priority*/
	NVIC_enableInterruptAndPriotity(PORTA_IRQ,PRIORITY_4);

	EnableInterrupts;


}


Colors_t RGB_color_selector(void)
{
	uint8_t input_a = 0;
	uint8_t input_c = 0;
	uint8_t total_color = 0;
	static Colors_t color = RED;

	input_a = GPIO_read_pin(SW2_PORT, SW2_PIN);
	input_c = GPIO_read_pin(SW3_PORT, SW3_PIN);

	total_color = (input_a << 1) | input_c;

	if (SW2 == total_color)
	{
		if(color < YELLOW)
		{
			color++;
		}
		else
		{
			color = GREEN;
		}

	}
	else if(SW3 == total_color)
	{
		if(color == (0x00u))
		{
			color = YELLOW;
		}
		else
		{
			color--;
		}
	}

	do
	{
		input_a = GPIO_read_pin(SW2_PORT, SW2_PIN);
		input_c = GPIO_read_pin(SW3_PORT, SW3_PIN);
		total_color = (input_a << 1) | input_c;
		total_color &= SW_MASK;

	}
	while(SW_MASK != total_color);

	return(color);

}


void RGB_red_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(RED_LED_PORT, RED_LED_PIN);
	}
	else
	{
		GPIO_set_pin(RED_LED_PORT, RED_LED_PIN);
	}

}

void RGB_blue_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(BLUE_LED_PORT, BLUE_LED_PIN);
	}
	else
	{
		GPIO_set_pin(BLUE_LED_PORT, BLUE_LED_PIN);
	}
}

void RGB_green_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(GREEN_LED_PORT, GREEN_LED_PIN);
	}
	else
	{
		GPIO_set_pin(GREEN_LED_PORT, GREEN_LED_PIN);
	}
}

void RGB_yellow_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(GREEN_LED_PORT, GREEN_LED_PIN);
		GPIO_clear_pin(RED_LED_PORT, RED_LED_PIN);
	}
	else
	{
		GPIO_set_pin(GREEN_LED_PORT, GREEN_LED_PIN);
		GPIO_set_pin(RED_LED_PORT, RED_LED_PIN);
	}
}
void RGB_white_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(GREEN_LED_PORT, GREEN_LED_PIN);
		GPIO_clear_pin(RED_LED_PORT, RED_LED_PIN);
		GPIO_clear_pin(BLUE_LED_PORT, BLUE_LED_PIN);
	}
	else
	{
		GPIO_set_pin(GREEN_LED_PORT, GREEN_LED_PIN);
		GPIO_set_pin(RED_LED_PORT, RED_LED_PIN);
		GPIO_set_pin(BLUE_LED_PORT, BLUE_LED_PIN);
	}
}
void RGB_purple_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(BLUE_LED_PORT, BLUE_LED_PIN);
		GPIO_clear_pin(RED_LED_PORT, RED_LED_PIN);
	}
	else
	{
		GPIO_set_pin(BLUE_LED_PORT, BLUE_LED_PIN);
		GPIO_set_pin(RED_LED_PORT, RED_LED_PIN);
	}
}



void RGB_red(void)
{
	RGB_purple_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_OFF);
	RGB_red_led_on_off(LED_ON);
}
void RGB_blue(void)
{
	RGB_purple_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_OFF);
	RGB_blue_led_on_off(LED_ON);
}
void RGB_green(void)
{
	RGB_yellow_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_ON);
	RGB_blue_led_on_off(LED_OFF);
}
void RGB_purple(void)
{
	RGB_blue_led_on_off(LED_OFF);
	RGB_red_led_on_off(LED_OFF);
	RGB_purple_led_on_off(LED_ON);
}
void RGB_yellow(void)
{
	RGB_red_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_OFF);
	RGB_yellow_led_on_off(LED_ON);
}

void no_color(void)
{
	RGB_green_led_on_off(LED_OFF);
	RGB_blue_led_on_off(LED_OFF);
	RGB_red_led_on_off(LED_OFF);
}


void RGB_led_on(Colors_t color)
{
	switch (color)
	{
		case (GREEN):
			RGB_green();
			printf("green\n");
			break;
		case (BLUE):
			RGB_blue();
			printf("blue\n");
			break;
		case (PURPLE):
			RGB_purple();
			printf("purple\n");
			break;
		case (RED):
			RGB_red();
			printf("red\n");
			break;
		case (YELLOW):
			RGB_yellow();
			printf("yellow\n");
			break;
		case (WHITE):
			no_color();
			break;
		default:
			no_color();
			break;
	}
}
