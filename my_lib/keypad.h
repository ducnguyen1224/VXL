#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "stm32f10x.h"

char keypad_Press(void);
void keypad_Init(void);
void Delay_ms(uint16_t time);

#endif
