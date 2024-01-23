/*
 * API_debounce.c
 *
 *  Created on: 30/11/2021
 *      Author: VIN
 */

#include "API_debounce.h"


static debounce_t debounceState;
static delay_t delay_button;
static delay_t delay_default;

#define DELAY_TIME 40
#define DELAY_DEFAULT 100
#define LED3 GPIO_PIN_4

bool_t debounceInit()
{
	debounceState = BUTTON_UP;
	delayInit(&delay_button, DELAY_TIME);
	delayInit(&delay_default, DELAY_DEFAULT);
	//Configuración del pin que recibe
	/* Para hacerlo después
	GPIO_InitStruct.Pin = PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = PULL_MODE;
	HAL_GPIO_Init(PORT, &GPIO_InitStruct);
	*/
	return true;
}

debounce_t debounceUpdate(GPIO_PinState pinState)
//void debounceUpdate(
{
	switch(debounceState){
	case BUTTON_UP:

		if(pinState == 1){
			delayRead(&delay_button);
			debounceState = BUTTON_FALLING;
		}

	break;

	case BUTTON_FALLING:
		if(delayRead(&delay_button)){
			if(pinState == 1){
				debounceState = BUTTON_DOWN;
				return BUTTON_DOWN;
				//buttonPressed();
				//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);

				}else{
					debounceState = BUTTON_UP;
			}
		}
	break;
	case BUTTON_DOWN:
		if(pinState == 0){
			delayRead(&delay_button);
			debounceState = BUTTON_RISING;
		}
	break;
	case BUTTON_RISING:
			if(delayRead(&delay_button)){
				if(pinState == 0){
					debounceState = BUTTON_UP;
					return BUTTON_UP;
					//buttonReleased();
					//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
				}
					else{
						debounceState = BUTTON_DOWN;
					}
			}
	break;
	default:
		if (delayRead(&delay_default)){
			HAL_GPIO_TogglePin(GPIOA, LED3);
		}



	} //Fin Switch
}

bool_t buttonPressed()
{
	//HAL_GPIO_TogglePin(GPIOA, LED1);
	return true;
}


bool_t buttonReleased()
{
	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
	return true;
}

