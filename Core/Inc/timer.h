/*
 * timer.h
 *
 *  Created on: Dec 13, 2024
 *      Author: QUI
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIMER_CYCLE		10
extern unsigned char timer0_flag;

void setTimer0(int duration);
void timer_run();


#endif /* INC_TIMER_H_ */
