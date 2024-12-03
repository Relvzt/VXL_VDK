/*
 * software_timer.c
 *
 *  Created on: Dec 2, 2024
 *      Author: QUI
 */

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;

int timer4_counter = 0;
int timer4_flag = 0;



void setTimer1(int dur){
	timer1_counter = dur;
	timer1_flag = 0;
}

void setTimer2(int dur){
	timer2_counter = dur;
	timer2_flag = 0;
}

void setTimer3(int dur){
	timer3_counter = dur;
	timer3_flag = 0;
}
void setTimer4(int dur){
	timer4_counter = dur;
	timer4_flag = 0;
}
void timerRun(){
	if(timer1_counter > 0){
		timer1_counter --;
		if(timer1_counter <=0){
			timer1_flag = 1;
		}
	}
	if(timer2_counter > 0){
			timer2_counter --;
			if(timer2_counter <=0){
				timer2_flag = 1;
			}
		}
	if(timer3_counter > 0){
				timer3_counter --;
				if(timer3_counter <=0){
					timer3_flag = 1;
				}
			}
	if(timer4_counter > 0){
		timer4_counter --;
		if(timer4_counter <=0){
			timer4_flag = 1;
		}
	}
}


