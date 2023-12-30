#include "keypad.h"
#include "stm32f10x_gpio.h"

#define SCAN_COL_0			0xef
#define SCAN_COL_1			0xdf
#define SCAN_COL_2			0xbf
#define SCAN_COL_3			0x7f

#define PIN_ROW_0				GPIO_Pin_0
#define PIN_ROW_1 			GPIO_Pin_1
#define PIN_ROW_2 			GPIO_Pin_2
#define PIN_ROW_3 			GPIO_Pin_3

#define PIN_COL_0 			GPIO_Pin_4
#define PIN_COL_1 			GPIO_Pin_5
#define PIN_COL_2 			GPIO_Pin_6
#define PIN_COL_3 			GPIO_Pin_7

#define PORT_KEYPAD 		GPIOA
void Delay_ms(uint16_t time);


GPIO_InitTypeDef GPIO_KEYPAD;


void keypad_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	// cau hinh cot
	GPIO_KEYPAD.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_KEYPAD.GPIO_Pin = PIN_COL_0| PIN_COL_1| PIN_COL_2| PIN_COL_3;
	GPIO_KEYPAD.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_KEYPAD, &GPIO_KEYPAD);
	// cau hinh hang
	GPIO_KEYPAD.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_KEYPAD.GPIO_Pin = PIN_ROW_0| PIN_ROW_1| PIN_ROW_2| PIN_ROW_3;
	GPIO_KEYPAD.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_KEYPAD, &GPIO_KEYPAD);
}

char keypad_Press(void){
	GPIO_Write(PORT_KEYPAD, SCAN_COL_0);
	if(!GPIO_ReadOutputDataBit(PORT_KEYPAD, PIN_COL_0)){
		
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)) {
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)); 
				return '1';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)) {
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)); 
				return '4';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)); 
				return '7';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)); 
				return '*';		
			}
		}
	}
	
	GPIO_Write(PORT_KEYPAD, SCAN_COL_1);
	if(!GPIO_ReadOutputDataBit(PORT_KEYPAD, PIN_COL_1)){
		
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)); 
				return '2';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)); 
				return '5';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)); 
				return '8';				
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)); 
				return '0';		
			}
		}
	}
	GPIO_Write(PORT_KEYPAD, SCAN_COL_2);
	if(!GPIO_ReadOutputDataBit(PORT_KEYPAD, PIN_COL_2)){
		
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)); 
				return '3';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)); 
				return '6';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)); 
				return '9';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)); 
				return '#';		
			}
		}
	}
	GPIO_Write(PORT_KEYPAD, SCAN_COL_3);
	if(!GPIO_ReadOutputDataBit(PORT_KEYPAD, PIN_COL_3)){
		
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_0)); 
				return 'A';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_1)); 
				return 'B';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_2)); 
				return 'C';		
			}
		}
		if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)){
			Delay_ms(10);
			if(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)){
				while(!GPIO_ReadInputDataBit(PORT_KEYPAD, PIN_ROW_3)); 
				return 'D';		
			}
		}
	}
	return 0xff;
}
void Delay_ms(uint16_t time){
	uint16_t i,j;
	for(i = 0; i < time; i++){
		for(j = 0; j < 0x2aff; j++);
	}
}
