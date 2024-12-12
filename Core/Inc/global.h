/*
 * global.h
 *
 *  Created on: Dec 12, 2024
 *      Author: QUI
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define RED_INIT		5
#define YELLOW_INIT		2
#define GREEN_INIT		3

void LedTimeDurationInit();
extern int mode;
extern int red_value, yellow_value, green_value;
extern int red_draft, yellow_draft, green_draft;

#endif /* INC_GLOBAL_H_ */
