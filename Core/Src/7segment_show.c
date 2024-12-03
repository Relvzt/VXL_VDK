/*
 * 7segment_show.c
 *
 *  Created on: Dec 2, 2024
 *      Author: QUI
 */
#include "main.h"
#include "7segment_show.h"

int status = 0;
const uint8_t segDigits[10] = {
    0b01000000, // 0: Seg0, Seg1, Seg2, Seg3, Seg4, Seg5
    0b01111001, // 1: Seg1, Seg2
    0b00100100, // 2: Seg0, Seg1, Seg3, Seg4, Seg6
    0b00110000, // 3: Seg0, Seg1, Seg2, Seg3, Seg6
    0b00011001, // 4: Seg1, Seg2, Seg5, Seg6
    0b00010010, // 5: Seg0, Seg2, Seg3, Seg5, Seg6
    0b00000010, // 6: Seg0, Seg2, Seg3, Seg4, Seg5, Seg6
    0b01111000, // 7: Seg0, Seg1, Seg2
    0b00000000, // 8: Seg0, Seg1, Seg2, Seg3, Seg4, Seg5, Seg6
    0b00010000  // 9: Seg0, Seg1, Seg2, Seg3, Seg5, Seg6
};
void displayDigit(uint8_t digit) {
    HAL_GPIO_WritePin(Seg0_GPIO_Port, Seg0_Pin, (segDigits[digit] & 0x01) ? 1 : 0);
    HAL_GPIO_WritePin(Seg1_GPIO_Port, Seg1_Pin, (segDigits[digit] & 0x02) ? 1 : 0);
    HAL_GPIO_WritePin(Seg2_GPIO_Port, Seg2_Pin, (segDigits[digit] & 0x04) ? 1 : 0);
    HAL_GPIO_WritePin(Seg3_GPIO_Port, Seg3_Pin, (segDigits[digit] & 0x08) ? 1 : 0);
    HAL_GPIO_WritePin(Seg4_GPIO_Port, Seg4_Pin, (segDigits[digit] & 0x10) ? 1 : 0);
    HAL_GPIO_WritePin(Seg5_GPIO_Port, Seg5_Pin, (segDigits[digit] & 0x20) ? 1 : 0);
    HAL_GPIO_WritePin(Seg6_GPIO_Port, Seg6_Pin, (segDigits[digit] & 0x40) ? 1 : 0);
}

void segSHOW(int A){
	displayDigit(A);
}

