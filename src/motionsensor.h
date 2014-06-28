/*
 * motionsensor.h
 *
 *  Created on: Jun 28, 2014
 *      Author: alexandermertens
 */


#ifndef MOTIONSENSOR_H_
#define MOTIONSENSOR_H_

/* *** INCLUDES ************************************************************** */

/* * system headers              * */
#include <stdint.h>

/* * local headers               * */

/* *** DECLARATIONS ********************************************************** */

/* * external type and constants * */
typedef struct {
	uint16_t x;
	uint16_t y;
	uint16_t z;
} rotation_t;

typedef struct {
	uint16_t x;
	uint16_t y;
	uint16_t z;
} acceleration_t;

/* * external objects            * */
extern void motionsensor_init();
extern void motionsensor_set_zero_point();

extern double motionsensor_get_position();

//TODO: make static when working
extern void motionsensor_get_current_rotation(rotation_t *rotation);
extern void motionsensor_get_current_acceleration(acceleration_t *acceleration);

/* * external functions          * */

#endif /* MOTIONSENSOR_H_ */
