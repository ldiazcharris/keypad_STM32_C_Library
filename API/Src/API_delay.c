/*
 * API_delay.c
 *
 *  Created on: 30/11/2021
 *      Author: VIN
 */

#include "API_delay.h"
#include "stm32f4xx_hal.h"

void delayInit( delay_t * delay, tick_t duration)
{
	if(delay == 0 || duration < 0 || duration > HAL_MAX_DELAY)
		while(1);
	delay->duration = duration;
	delay->running = 0;
}

bool_t delayRead(delay_t * delay)
{
	bool_t timeArrived = false;
	if (delay == 0)
		while(1);

	if (!delay->running){
		delay->startTime = HAL_GetTick();
		delay->running = 1;
	}else if((tick_t)(HAL_GetTick() - delay->startTime) >= delay->duration){
				timeArrived = true;
				delay->running = 0;
		}

	return timeArrived;
}

void delayWrite(delay_t * delay, tick_t duration)
{
		delay->duration = duration;
		delay->running = 0;
}
