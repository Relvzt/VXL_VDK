/*
 * the_mode.c
 *
 *  Created on: Dec 2, 2024
 *      Author: QUI
 */
#include "main.h"
#include "software_timer.h"
#include "7segment_show.h"
#include "led_value.h"


extern int counter;

void mode(int redTime, int yellowTime, int greenTime){
	switch(counter){
	case 1:
		if(timer1_flag == 1){
			setTimer1(redTime);
		HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
		}
		if(timer2_flag == 1){
			setTimer2(yellowTime);
			HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
		}
		if(timer3_flag == 1){
			setTimer3(greenTime);
            HAL_GPIO_TogglePin(G1_GPIO_Port, G1_Pin);
		}
	break;
	case 0:
	break;
}
}

