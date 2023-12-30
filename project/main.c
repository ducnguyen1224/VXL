#include "stm32f10x.h"
#include "i2c_lcd.h"
#include "keypad.h"
#include "string.h" 


GPIO_InitTypeDef 					GPIO_InitStructure;
I2C_InitTypeDef						I2C_InitStructure;
void gpio_config(void);
void I2C_Configuration(void);              // chuong trinh con cau hinh I2C
uint8_t key;
uint16_t i, k = 5, flag = 0;
char a[10], pass[10] = "11111";
int main(void) {
	SysTick_Config(SystemCoreClock/1000);
	I2C_Configuration();
	keypad_Init();
	lcd_init ();                                 // ham khoi dong LCD16x2
	gpio_config();
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);		
	Delete_LCD();																// clear lcd
	lcd_goto_XY(1, 1);
	lcd_send_string ("Enter Password");
	i = 0;
  while (1)
  {
		key = keypad_Press();
		if(key == '*') {
			Delete_LCD();	
			lcd_goto_XY(1, 2);
			lcd_send_string ("New Password");
			flag = 1;
			k = 0;
		}
		if(key == '#' || i == k & i != 0) {
			flag = 0;
			i = 0;
			Delete_LCD();
			lcd_goto_XY(1, 1);
			lcd_send_string ("Enter Password");	
		}
		if(flag) {
			if(key != '*' && key != 0xff) {
				pass[k] = key;
				lcd_goto_XY(2, 2 + k);
				lcd_Data_Write(key);
				k++;		
			}
		} 
		if(key != 0xff && flag == 0 && key != '#'){ 
			a[i] = key;
			lcd_goto_XY(2, 5 + i);
			lcd_Data_Write(key);
			i++;
			if(i == k) {
				int j, ok = 1;
				Delay_ms(1000);
				for(j = 0; j < k; j++) {
					if(a[j] != pass[j]) {
						Delete_LCD();
						lcd_goto_XY(1, 3);
						lcd_send_string("Incorrect!");
						Delay_ms(1000);
						ok = 0;
						break;
					}
				}
				if(ok) {
					Delete_LCD();
					lcd_goto_XY(1, 2);
					lcd_send_string("Successful!");
					GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
					Delay_ms(1000);
					GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);					
				}
			}
		}			 	
	}
}


void I2C_Configuration(void)
{
    // cap clock cho ngoai vi va I2C
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);							
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // cau hinh chan SDA va SCL
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;						
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // cau hinh I2C
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = 0x00; 
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;       
    I2C_InitStructure.I2C_ClockSpeed = 100000;										
    I2C_Init(I2C1, &I2C_InitStructure);
    // cho phep bo I2C hoat dong
    I2C_Cmd(I2C1, ENABLE);

}
void gpio_config(void) {
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpio);
}

