/*
 * configuration_manager.h
 *
 *  Created on: Dec 12, 2013
 *      Author: alexandermertens
 */

#ifndef CONFIGURATION_MANAGER_H_
#define CONFIGURATION_MANAGER_H_


#include <stdint.h>
#include <stdbool.h>

#define CONFIGURATION_MANAGER_CONFIG_COUNT					6
#define CONFIGURATION_MANAGER_CONFIG_VERSION				3
#define CONFIGURATION_MANAGER_CONFIG_COMMENT_LENGTH			60

typedef struct {
	pid_configuration_t pid;
	accelerationsensor_config_t accelerationsensor;

	uint8_t config_version;
	char comment[CONFIGURATION_MANAGER_CONFIG_COMMENT_LENGTH];
	bool has_changed;
} configuration_t;

typedef struct {
	int16_t p_factor;
	int16_t i_factor;
	int16_t d_factor;
	uint16_t scalingfactor;
} pid_configuration_t;

typedef struct {
	acceleration_t acceleration_offset;
	uint16_t position_multiplier;
} accelerationsensor_config_t;

/* extern functions */
extern int16_t configuration_manager_current_config_get_p_factor(void);
extern void configuration_manager_current_config_set_p_factor(int16_t);

extern int16_t configuration_manager_current_config_get_i_factor(void);
extern void configuration_manager_current_config_set_i_factor(int16_t);

extern int16_t configuration_manager_current_config_get_d_factor(void);
extern void configuration_manager_current_config_set_d_factor(int16_t);

extern uint16_t configuration_manager_current_config_get_scalingfactor(void);
extern void configuration_manager_current_config_set_scalingfactor(uint16_t);

extern void configuration_manager_current_config_get_acceleration_offset(acceleration_t *); /* acceleration_t *accel */
extern void configuration_manager_current_config_set_acceleration_offset(acceleration_t *); /* acceleration_t *accel */

extern uint16_t configuration_manager_current_config_get_position_multiplier(void);
extern void configuration_manager_current_config_set_position_multiplier(uint16_t);

extern void configuration_manager_init(void);

extern void configuration_manager_write_config(void);

#endif /* CONFIGURATION_MANAGER_H_ */
