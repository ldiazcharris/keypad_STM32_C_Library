/*
 * API_delay.h
 *
 *  Created on: 30/11/2021
 *      Author: VIN
 */

#include <stdint.h>
#include <stdbool.h>

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

typedef uint32_t tick_t;
typedef bool bool_t;


typedef struct{
	tick_t startTime;
	tick_t duration;
	bool_t running;
} delay_t;


void delayInit(delay_t * delay, tick_t duration);
bool_t delayRead(delay_t * delay);
void delayWrite(delay_t * delay, tick_t duration);

#endif /* API_INC_API_DELAY_H_ */
