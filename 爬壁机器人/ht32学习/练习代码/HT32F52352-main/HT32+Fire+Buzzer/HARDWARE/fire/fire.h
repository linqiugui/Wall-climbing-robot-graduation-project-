#ifndef _FIRE_H_
#define _FIRE_H_

#include "ht32f5xxxx_ckcu.h"
#include "ht32f5xxxx_gpio.h"


//端口号定义
#define HT_GPIO_PORT HT_GPIOC
//火焰引脚定义
#define GPIP_PIN_FIRE1   GPIO_PIN_1

#define GPIP_PIN_FIRE2   GPIO_PIN_2

#define GPIP_PIN_FIRE3   GPIO_PIN_3

#define GPIP_PIN_FIRE4   GPIO_PIN_13

#define HT_GPIO_FIRE_PIN   (GPIP_PIN_FIRE1|GPIP_PIN_FIRE2|GPIP_PIN_FIRE3 | GPIP_PIN_FIRE4)

//引脚读取
#define GPIO_Read_Stat1()  GPIO_ReadInBit(HT_GPIO_PORT,GPIP_PIN_FIRE1)
#define GPIO_Read_Stat2()  GPIO_ReadInBit(HT_GPIO_PORT,GPIP_PIN_FIRE2)
#define GPIO_Read_Stat3()  GPIO_ReadInBit(HT_GPIO_PORT,GPIP_PIN_FIRE3)
#define GPIO_Read_Stat4()  GPIO_ReadInBit(HT_GPIO_PORT,GPIP_PIN_FIRE4)


void Init_Fire(void);
#endif

