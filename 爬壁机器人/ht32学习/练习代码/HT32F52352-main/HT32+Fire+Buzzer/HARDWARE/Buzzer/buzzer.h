#ifndef _BUZZER_H_
#define _BUZZER_H_

#include "ht32f5xxxx_ckcu.h"
#include "ht32f5xxxx_gpio.h"



//端口号定义
#define HT_GPIO_Buzzer_PORT HT_GPIOD
//Buzzer引脚定义
#define HT_GPIO_Buzzer_PIN  GPIO_PIN_0

//Buzzer 宏定义开和关
#define Buzzer_ON() 	GPIO_WriteOutBits(HT_GPIO_Buzzer_PORT,HT_GPIO_Buzzer_PIN,RESET)
#define Buzzer_OFF()  GPIO_WriteOutBits(HT_GPIO_Buzzer_PORT,HT_GPIO_Buzzer_PIN,SET)
void Buzzer_Init(void);
void Buzzer_Running(void);

#endif
