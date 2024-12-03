/*
 * software_timer.h
 *
 *  Created on: Dec 2, 2024
 *      Author: QUI
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;

void setTimer1(int dur);
void setTimer2(int dur);
void setTimer3(int dur);
void setTimer4(int dur);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
