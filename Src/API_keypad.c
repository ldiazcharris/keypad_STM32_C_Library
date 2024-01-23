/*
 * API_keypad.c
 *
 *  Created on: 1/12/2021
 *      Author: VIN
 */

#include "API_keypad.h"


static bool_t assert_ports(keypad_t keypad);

/**
 * @brief Esta función inicializa el teclado matricial 4x4
 * según la estructura definida por el usuario.
 */

bool_t keypadInit(keypad_t keypad)
{
	if (assert_ports(keypad))
	{

	GPIO_InitTypeDef keypad_InitStruct = {0};

	/**
	 * @brief confirgurando los pines dispuestos por el usuario
	 * para las columnas del teclado matricial 4x4
	*/

	HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), GPIO_PIN_RESET);
	keypad_InitStruct.Pin = pin(keypad.col_1_pin);
	keypad_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	keypad_InitStruct.Pull = GPIO_NOPULL;
	keypad_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(port(keypad.col_1_port), &keypad_InitStruct);

	HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), GPIO_PIN_RESET);
	keypad_InitStruct.Pin = pin(keypad.col_2_pin);
	keypad_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	keypad_InitStruct.Pull = GPIO_NOPULL;
	keypad_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(port(keypad.col_2_port), &keypad_InitStruct);

	HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), GPIO_PIN_RESET);
	keypad_InitStruct.Pin = pin(keypad.col_3_pin);
	keypad_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	keypad_InitStruct.Pull = GPIO_NOPULL;
	keypad_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(port(keypad.col_3_port), &keypad_InitStruct);

	HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), GPIO_PIN_RESET);
	keypad_InitStruct.Pin = pin(keypad.col_4_pin);
	keypad_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	keypad_InitStruct.Pull = GPIO_NOPULL;
	keypad_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(port(keypad.col_4_port), &keypad_InitStruct);

	/**
	 * @brief confirgurando los pines dispuestos por el usuario
	 * para las filas del teclado matricial 4x4
	 */

	HAL_GPIO_WritePin(port(keypad.row_A_port), pin(keypad.row_A_pin), GPIO_PIN_RESET);
	keypad_InitStruct.Pin = pin(keypad.row_A_pin);
	keypad_InitStruct.Mode = GPIO_MODE_INPUT;
	keypad_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(port(keypad.row_A_port), &keypad_InitStruct);

	HAL_GPIO_WritePin(port(keypad.row_B_port), pin(keypad.row_B_pin), GPIO_PIN_RESET);
	keypad_InitStruct.Pin = pin(keypad.row_B_pin);
	keypad_InitStruct.Mode = GPIO_MODE_INPUT;
	keypad_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(port(keypad.row_B_port), &keypad_InitStruct);

	HAL_GPIO_WritePin(port(keypad.row_C_port), pin(keypad.row_C_pin), GPIO_PIN_RESET);
	keypad_InitStruct.Pin = pin(keypad.row_C_pin);
	keypad_InitStruct.Mode = GPIO_MODE_INPUT;
	keypad_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(port(keypad.row_C_port), &keypad_InitStruct);

	HAL_GPIO_WritePin(port(keypad.row_D_port), pin(keypad.row_D_pin), GPIO_PIN_RESET);
	keypad_InitStruct.Pin = pin(keypad.row_D_pin);
	keypad_InitStruct.Mode = GPIO_MODE_INPUT;
	keypad_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(port(keypad.row_D_port), &keypad_InitStruct);


	return true;
	}else{return false;}

}

/**
 * @brief Esta función lee el teclado correspondiente
 */

tecla_t keypadRead(keypad_t keypad)
{
	tecla_t pressed_key = 0;
	keyboard_t keyboard[4][4] = {		{'7', '8', '9', '/'},
										{'4', '5', '6', '*'},
										{'1', '2', '3', '-'},
										{'O', '0', '=', '+'}};

	for(uint8_t i = 0; i < 4; i++)
	{
		switch (i)
		{
		case COL_1:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);



			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][0];
			}

		break;

		case COL_2:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);


			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][1];
			}

		break;

		case COL_3:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);



			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][2];
			}

		break;

		case COL_4:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 1);


			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][3];
			}

		break;

		default:
			return pressed_key;

		}//END SWITCH/CASE
	}//END FOR

return pressed_key;
}//END keypadRead()

tecla_t keypadReadUser(keypad_t keypad, keyboard_t keyboard[4][4])
{

	tecla_t pressed_key = 0;

	for(uint8_t i = 0; i < 4; i++)
	{
		switch (i)
		{
		case COL_1:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);



			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][0];
			}

		break;

		case COL_2:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);


			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][1];
			}

		break;

		case COL_3:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);



			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][2];
			}

		break;

		case COL_4:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 1);


			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][3];
			}

		break;

		default:
			return pressed_key;

		}//END SWITCH/CASE
	}//END FOR

return pressed_key;
}//END keypadRead()

/**
 * @brief esta función busca los pines GPIO correspondientes que el usuario ingrese.
 * Se intentó implementar con un switch/case, pero me arrojó el siiguiente error:
 * switch quantity not an integer occurs.
 */

uint16_t pin(uint8_t pin)
{
	switch (pin)
	{

	case 0:
		return GPIO_PIN_0;
	break;

	case 1:
		return GPIO_PIN_1;
	break;

	case 2:
		return GPIO_PIN_2;
	break;

	case 3:
		return GPIO_PIN_3;
	break;

	case 4:
		return GPIO_PIN_4;
	break;

	case 5:
		return GPIO_PIN_5;
	break;

	case 6:
		return GPIO_PIN_6;
	break;

	case 7:
		return GPIO_PIN_7;
	break;

	case 8:
		return GPIO_PIN_8;
	break;

	case 9:
		return GPIO_PIN_9;
	break;

	case 10:
		return GPIO_PIN_10;
	break;

	case 11:
		return GPIO_PIN_11;
	break;

	case 12:
		return GPIO_PIN_12;
	break;

	case 13:
		return GPIO_PIN_13;
	break;

	case 14:
		return GPIO_PIN_14;
	break;

	case 15:
		return GPIO_PIN_15;
	break;

	default:
		return 0;
	}
}


/**
 * @brief esta función busca los puertos GPIO correspondientes que el usuario ingrese.
 *
 */

GPIO_TypeDef * port(uint8_t port)
{
	switch (port)
	{
	case 'A':
		return GPIOA;
	break;

	case 'B':
		return GPIOB;
	break;

	case 'C':
		return GPIOC;
	break;

	case 'D':
		return GPIOD;
	break;

	case 'E':
		return GPIOE;
	break;

	case 'H':
		return GPIOH;
	break;

	default:
		return 0;
	}

}



static bool_t assert_ports(keypad_t keypad)
{

	if( 'A' == keypad.col_1_port || 'A' ==  keypad.col_2_port ||
			'A' == keypad.col_3_port || 'A' == keypad.col_4_port ||
			'A' == keypad.row_A_port || 'A' ==  keypad.row_B_port ||
			'A' == keypad.row_C_port || 'A' == keypad.row_D_port)
		{
			__HAL_RCC_GPIOA_CLK_ENABLE();
		} else

		if( 'B' == keypad.col_1_port || 'B' ==  keypad.col_2_port ||
			'B' == keypad.col_3_port || 'B' == keypad.col_4_port ||
			'B' == keypad.row_A_port || 'B' ==  keypad.row_B_port ||
			'B' == keypad.row_C_port || 'B' == keypad.row_D_port)
			{
				__HAL_RCC_GPIOB_CLK_ENABLE();
			} else

		if( 'C' == keypad.col_1_port || 'C' ==  keypad.col_2_port ||
			'C' == keypad.col_3_port || 'C' == keypad.col_4_port ||
			'C' == keypad.row_A_port || 'C' ==  keypad.row_B_port ||
			'C' == keypad.row_C_port || 'C' == keypad.row_D_port)
			{
				__HAL_RCC_GPIOC_CLK_ENABLE();
			}else


		if( 'D' == keypad.col_1_port || 'D' ==  keypad.col_2_port ||
			'D' == keypad.col_3_port || 'D' == keypad.col_4_port ||
			'D' == keypad.row_A_port || 'D' ==  keypad.row_B_port ||
			'D' == keypad.row_C_port || 'D' == keypad.row_D_port)
			{
				__HAL_RCC_GPIOD_CLK_ENABLE();
			} else

		if( 'E' == keypad.col_1_port || 'E' ==  keypad.col_2_port ||
			'E' == keypad.col_3_port || 'E' == keypad.col_4_port ||
			'E' == keypad.row_A_port || 'E' ==  keypad.row_B_port ||
			'E' == keypad.row_C_port || 'E' == keypad.row_D_port)
			{
				__HAL_RCC_GPIOE_CLK_ENABLE();
			} else

		if( 'H' == keypad.col_1_port || 'H' ==  keypad.col_2_port ||
			'H' == keypad.col_3_port || 'H' == keypad.col_4_port ||
			'H' == keypad.row_A_port || 'H' ==  keypad.row_B_port ||
			'H' == keypad.row_C_port || 'H' == keypad.row_D_port)
			{
				__HAL_RCC_GPIOH_CLK_ENABLE();

			} else

			{
				return false;
			}
	return true;
}

/**
 *  @brief Manejador de error del teclado.
 *
 *
 */



/**
 * @brief códigos de prueba

 * @brief estas funciones buscaban los puertos y pines GPIO correspondientes que el usuario ingrese.
 * Se intentó implementar con un switch/case, pero me arrojó el siiguiente error:
 * switch quantity not an integer occurs.
 * Luego se usaron punteros a variables para retornar los puertos y se pudo resolver el
 * error del switch/case.
 */

/* prueba con if
static uint16_t pin(uint8_t pin)
{
	if(1 == pin){
		return GPIO_PIN_1;
	}

	if(2 == pin){
		return GPIO_PIN_2;
	}

	if(3 == pin){
		return GPIO_PIN_3;
	}

	if(4 == pin){
		return GPIO_PIN_4;
	}

	if(5 == pin){
		return GPIO_PIN_5;
	}

	if(6 == pin){
		return GPIO_PIN_6;
	}

	if(7 == pin){
		return GPIO_PIN_7;
	}

	if(8 == pin){
		return GPIO_PIN_8;
	}

	if(9 == pin){
		return GPIO_PIN_9;
	}

	if(10 == pin){
		return GPIO_PIN_10;
	}

	if(11 == pin){
		return GPIO_PIN_11;
	}

	if(12 == pin){
		return GPIO_PIN_12;
	}

	if(13 == pin){
		return GPIO_PIN_13;
	}

	if(14 == pin){
		return GPIO_PIN_14;
	}

	if(15 == pin){
		return GPIO_PIN_15;
	}

}

*/


/*
static GPIO_TypeDef * port(uint8_t port)
{

	if('A' == port){
		return GPIOA;
	}

	if('B' == port){
		return GPIOB;
	}

	if('C' == port){
		return GPIOC;
	}

	if('D' == port){
		return GPIOD;
	}

	if('E' == port){
		return GPIOE;
	}

	if('H' == port){
		return GPIOH;
	}

}

*/


/*__HAL_RCC_GPIOA_CLK_ENABLE();
__HAL_RCC_GPIOB_CLK_ENABLE();
__HAL_RCC_GPIOC_CLK_ENABLE();
__HAL_RCC_GPIOD_CLK_ENABLE();
__HAL_RCC_GPIOE_CLK_ENABLE();
__HAL_RCC_GPIOH_CLK_ENABLE();
*/

/*
 *
	for(uint8_t i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);



			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][0];
			}
			else
			{
				pressed_key = 0;
			}
			HAL_Delay(time);
		break;

		case 1:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);


			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][1];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][1];
			}
			else
			{
				pressed_key = 0;
			}
			HAL_Delay(time);
		break;

		case 2:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);



			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][2];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][2];
			}
			else
			{
				pressed_key = 0;
			}
			HAL_Delay(time);
		break;

		case 3:
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 1);


			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) )
			{
				pressed_key = keyboard[0][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) )
			{
				pressed_key = keyboard[1][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)))
			{
				pressed_key = keyboard[2][3];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)))
			{
				pressed_key = keyboard[3][3];
			}
			else
			{
				pressed_key = 0;
			}

		break;

		default:
			pressed_key = 0;

		}
	}
 */

/*
for(uint8_t i = 0; i < 4; i++)
	{

		if(0 == i)
		{
			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);

		}

		if(1 == i)
		{

			HAL_GPIO_WritePin(port(keypad.col_1_port), pin(keypad.col_1_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_2_port), pin(keypad.col_2_pin), 1);
			HAL_GPIO_WritePin(port(keypad.col_3_port), pin(keypad.col_3_pin), 0);
			HAL_GPIO_WritePin(port(keypad.col_4_port), pin(keypad.col_4_pin), 0);

		}

		if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) &&
				1 == HAL_GPIO_ReadPin(port(keypad.col_1_port), pin(keypad.col_1_pin)) )
		{
			pressed_key = keyboard[0][0];
		} else

		if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) &&
				1 == HAL_GPIO_ReadPin(port(keypad.col_1_port), pin(keypad.col_1_pin)) )
		{
			pressed_key = keyboard[1][0];
		} else

		if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)) &&
				1 == HAL_GPIO_ReadPin(port(keypad.col_1_port), pin(keypad.col_1_pin)) )
		{
			pressed_key = keyboard[2][0];
		} else

		if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)) &&
				1 == HAL_GPIO_ReadPin(port(keypad.col_1_port), pin(keypad.col_1_pin)) )
		{
			pressed_key = keyboard[3][0];
		}
		else
			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) &&
					1 == HAL_GPIO_ReadPin(port(keypad.col_2_port), pin(keypad.col_2_pin)) )
			{
				pressed_key = keyboard[0][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) &&
					1 == HAL_GPIO_ReadPin(port(keypad.col_2_port), pin(keypad.col_2_pin)) )
			{
				pressed_key = keyboard[1][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)) &&
					1 == HAL_GPIO_ReadPin(port(keypad.col_2_port), pin(keypad.col_2_pin)) )
			{
				pressed_key = keyboard[2][0];
			} else

			if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)) &&
					1 == HAL_GPIO_ReadPin(port(keypad.col_2_port), pin(keypad.col_2_pin)) )
			{
				pressed_key = keyboard[3][0];
			}
			else
		{
			pressed_key = 0;
		}


		if( 1 == HAL_GPIO_ReadPin(port(keypad.row_A_port), pin(keypad.row_A_pin)) &&
				HAL_GPIO_ReadPin(port(keypad.col_2_port), pin(keypad.col_2_pin)) )
		{
			pressed_key = keyboard[0][1];
		} else

		if( 1 == HAL_GPIO_ReadPin(port(keypad.row_B_port), pin(keypad.row_B_pin)) &&
				HAL_GPIO_ReadPin(port(keypad.col_2_port), pin(keypad.col_2_pin)) )
		{
			pressed_key = keyboard[1][1];
		} else

		if( 1 == HAL_GPIO_ReadPin(port(keypad.row_C_port), pin(keypad.row_C_pin)) &&
				HAL_GPIO_ReadPin(port(keypad.col_2_port), pin(keypad.col_2_pin)) )
		{
			pressed_key = keyboard[2][1];
		} else

		if( 1 == HAL_GPIO_ReadPin(port(keypad.row_D_port), pin(keypad.row_D_pin)) &&
				HAL_GPIO_ReadPin(port(keypad.col_2_port), pin(keypad.col_2_pin)) )
		{
			pressed_key = keyboard[3][1];
		}
		else
		{
			pressed_key = 0;
		}
*/
