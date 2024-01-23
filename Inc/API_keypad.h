/*
 * API_keypad.h
 *
 *  Created on: 1/12/2021
 *      Author: Luis David Díaz Charris
 */


#ifndef API_INC_API_KEYPAD_H_
#define API_INC_API_KEYPAD_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>
#include "API_delay.h"
#include "API_debounce.h"

typedef bool bool_t;
typedef uint8_t tecla_t;

typedef uint8_t keyboard_t;

typedef enum{
	COL_1 = 0,
	COL_2,
	COL_3,
	COL_4,
} keypadState_t;

typedef struct{
	//Columnas
	uint8_t col_1_pin;
	uint8_t col_1_port;
	uint8_t col_2_pin;
	uint8_t col_2_port;
	uint8_t col_3_pin;
	uint8_t col_3_port;
	uint8_t col_4_pin;
	uint8_t col_4_port;
	//Filas
	uint8_t row_A_pin;
	uint8_t row_A_port;
	uint8_t row_B_pin;
	uint8_t row_B_port;
	uint8_t row_C_pin;
	uint8_t row_C_port;
	uint8_t row_D_pin;
	uint8_t row_D_port;

}keypad_t;


bool_t keypadInit(keypad_t keypad);

tecla_t keypadRead(keypad_t keypad);

tecla_t keypadReadUser(keypad_t keypad, keyboard_t keyboard[4][4]);

uint16_t pin(uint8_t pin);

GPIO_TypeDef * port(uint8_t port);


#endif /* API_INC_API_KEYPAD_H_ */
