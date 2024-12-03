/*
 * button.c
 *
 *  Created on: Dec 2, 2024
 *      Author: QUI
 */

#include "button.h"
#include "the_mode.h"
#include "7segment_show.h"
#include "main.h"
#include "led_value.h"


int counter = 0;
int Keyreg0[NUM_OF_BUTTON] = {NORMAL_STATE};
int Keyreg1[NUM_OF_BUTTON] = {NORMAL_STATE};
int Keyreg2[NUM_OF_BUTTON] = {NORMAL_STATE};
int Keyreg3[NUM_OF_BUTTON] = {NORMAL_STATE};
int Key[NUM_OF_BUTTON] = {NORMAL_STATE};
int timeforKeypress[NUM_OF_BUTTON] = {200};
int rednow;

void readKey(){
	Key[1] = HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin);
	Key[2] = HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin);
	Key[0] = HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin);
}

void subkeyProcess(int number){
	switch(number){
	case 1:
		redTimer = rednow;
		switch(counter){
		case 0:
			segSHOW(1);
			counter=1;
		break;
		case 1:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, 0);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, 1);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, 1);
			segSHOW(2);
			counter=2;
			break;
		case 2:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, 1);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, 0);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, 1);
			segSHOW(3);
			counter=3;
		    break;
		case 3:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, 1);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, 1);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, 0);
			segSHOW(4);
			counter=0;
		    break;
		}
		break;
	case 2:
		segSHOW(redTimer++);
		break;
	case 0:
		redTimer = rednow ;
		//segSHOW(redTimer);
		break;
	}
}
void getkeyInput(){
	readKey();
	for(int i = 0; i < NUM_OF_BUTTON; i++){
		Keyreg2[i] = Keyreg1[i];
		Keyreg1[i] = Keyreg0[i];
		Keyreg0[i] = Key[i];
		if ((Keyreg1[i] == Keyreg0[i]) && (Keyreg1[i] == Keyreg2[i])){
			if (Keyreg2[i] != Keyreg3[i]){
				Keyreg3[i] = Keyreg2[i];
				if (Keyreg3[i] == PRESS_STATE){
					timeforKeypress[i] = 500;
					subkeyProcess(i);
				}
			}
			else{
				timeforKeypress[i] --;
				if (timeforKeypress[i] == 0){
					timeforKeypress[i] = 500;
					if (Keyreg3[i] == PRESS_STATE){
						subkeyProcess(i);
					}
				}
			}
		}
	}
}
