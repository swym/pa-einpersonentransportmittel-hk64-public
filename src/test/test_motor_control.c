/*
 * test_motor_control.c
 *
 *  Created on: Nov 19, 2013
 *      Author: alexandermertens
 */


/* *** INCLUDES ************************************************************** */
#include "test_motor_control.h"

#include "../motor_control.h"
#include "../md25.h"

#include <util/delay.h>
#include <stdio.h>
/* *** DECLARATIONS ********************************************************** */

/* local type and constants     */

/* local function declarations  */


/* *** FUNCTION DEFINITIONS ************************************************** */
void test_motor_control_set_different_speeds(void)
{
	motor_contol_speed_t speed;
	motor_contol_speed_t printf_speed;

	//init
	md25_set_mode(MD25_MODE_SIGNED_SPEED);

	printf("test_motor_control_set_different_speeds(void)");
	printf("init\n");

	motor_control_get_current_speed(&printf_speed);
	printf("current: M1 = %d , M2 = %d\n",printf_speed.motor_1, printf_speed.motor_2);

	//1:neue Geschwindigkeit einstellen
	//2:delay
	//goto 1
	speed.motor_1 = 0;
	speed.motor_2 = 0;

	motor_control_prepare_new_speed(&speed);
	motor_control_set_new_speed();

	motor_control_get_current_speed(&printf_speed);
	printf("current: M1 = %d , M2 = %d\n",printf_speed.motor_1, printf_speed.motor_2);


	_delay_ms(2000.0);


	// SPEED 1
	speed.motor_1 = 100;
	speed.motor_2 = 100;

	motor_control_prepare_new_speed(&speed);

	_delay_ms(2000.0);

	motor_control_set_new_speed();
	motor_control_get_current_speed(&printf_speed);
	printf("current: M1 = %d , M2 = %d\n",printf_speed.motor_1, printf_speed.motor_2);

	_delay_ms(2000.0);


	// SPEED 1
	speed.motor_1 = 0;
	speed.motor_2 = 0;

	motor_control_prepare_new_speed(&speed);

	_delay_ms(1000.0);

	motor_control_set_new_speed();
	motor_control_get_current_speed(&printf_speed);
	printf("current: M1 = %d , M2 = %d\n",printf_speed.motor_1, printf_speed.motor_2);

	_delay_ms(2000.0);


	// SPEED 1
	speed.motor_1 = 0;
	speed.motor_2 = -100;

	motor_control_prepare_new_speed(&speed);

	_delay_ms(1000.0);

	motor_control_set_new_speed();
	motor_control_get_current_speed(&printf_speed);
	printf("current: M1 = %d , M2 = %d\n",printf_speed.motor_1, printf_speed.motor_2);

	_delay_ms(2000.0);

	// SPEED 1
	speed.motor_1 = -100;
	speed.motor_2 = 0;

	motor_control_prepare_new_speed(&speed);

	_delay_ms(1000.0);

	motor_control_set_new_speed();
	motor_control_get_current_speed(&printf_speed);
	printf("current: M1 = %d , M2 = %d\n",printf_speed.motor_1, printf_speed.motor_2);

	_delay_ms(2000.0);

	// SPEED 1
	speed.motor_1 = -100;
	speed.motor_2 = 100;

	motor_control_prepare_new_speed(&speed);

	_delay_ms(1000.0);

	motor_control_set_new_speed();
	motor_control_get_current_speed(&printf_speed);
	printf("current: M1 = %d , M2 = %d\n",printf_speed.motor_1, printf_speed.motor_2);

	_delay_ms(2000.0);

	// SPEED 1
	speed.motor_1 = 0;
	speed.motor_2 = 0;

	motor_control_prepare_new_speed(&speed);

	_delay_ms(1000.0);

	motor_control_set_new_speed();
	motor_control_get_current_speed(&printf_speed);
	printf("current: M1 = %d , M2 = %d\n",printf_speed.motor_1, printf_speed.motor_2);

	_delay_ms(2000.0);

	printf("stop\n");
}
