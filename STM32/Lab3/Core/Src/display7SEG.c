/*
 * display7SEG.c
 *
 *  Created on: Nov 8, 2022
 *      Author: MY-PC
 */

#include "display7SEG.h"

int state7SEG = 1;

void display7SEG(int num, GPIO_TypeDef* GPIOx, uint16_t start_index){
	__IO uint16_t temp;
	switch(num){
	case 0:
		temp = 0b1000000;
		break;
	case 1:
		temp = 0b1111001;
		break;
	case 2:
		temp = 0b0100100;
		break;
	case 3:
		temp = 0b0110000;
		break;
	case 4:
		temp = 0b0011001;
		break;
	case 5:
		temp = 0b0010010;
		break;
	case 6:
		temp = 0b0000010;
		break;
	case 7:
		temp = 0b1111000;
		break;
	case 8:
		temp = 0b0;
		break;
	case 9:
		temp = 0b0010000;
		break;
	default:
		temp = !0b0;
		break;
	}
	uint16_t bitmask = 0b1111111 << start_index ;
	GPIOx->ODR = (GPIOx->ODR & ~bitmask) | (temp << start_index);
}

void displayAll7SEG(int counter1, int counter2) {
	int count1 = counter1%10;
	int count2 = (counter1-count1)/10;

	int count3 = counter2%10;
	int count4 = (counter2-count3)/10;
	switch (state7SEG) {
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);

			display7SEG(count1,GPIOB,0);
			display7SEG(count3,GPIOB,7);
			state7SEG = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			display7SEG(count2,GPIOB,0);
			display7SEG(count4,GPIOB,7);
			state7SEG = 1;
			break;
		default:
			break;
	}
}
