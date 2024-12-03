/*
 * button.h
 *
 *  Created on: Dec 2, 2024
 *      Author: QUI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESS_STATE GPIO_PIN_RESET
#define NUM_OF_BUTTON 3

extern int button_flag[NUM_OF_BUTTON];
extern int TimeOutForKeyPress[NUM_OF_BUTTON];
extern int button_pressed[NUM_OF_BUTTON];
extern int button_long_pressed[NUM_OF_BUTTON];
extern int button_flag[NUM_OF_BUTTON];

void getKeyInput();
int isButtonPressed(int index);
int isButtonLongPressed(int index);
//void getkeyInput();

#endif /* INC_BUTTON_H_ */
