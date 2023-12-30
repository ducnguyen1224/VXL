#ifndef __I2C_LCD_H
#define __I2C_LCD_H


	 
#include "stm32f10x.h"
#include "stm32f10x_i2c.h"

#define PCF8574A_Address      	0x27 << 1
#define I2C_Chanel      		I2C1

void lcd_Write_byte(char data);
void lcd_init (void);
void lcd_Data_Write(char data);
void lcd_Control_Write(char data);
void lcd_send_string (char *str);
void Delete_LCD(void)            ;
void lcd_goto_XY (int row, int col);
extern void Delay_ms(uint16_t time);
#endif
