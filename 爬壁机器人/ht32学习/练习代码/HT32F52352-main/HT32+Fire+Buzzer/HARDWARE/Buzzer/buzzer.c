#include "buzzer.h"
#include "delay.h"


void Buzzer_Init(void)
{
		CKCU_PeripClockConfig_TypeDef BuzzerCLOCK ={{0}};
		BuzzerCLOCK.Bit.PC = 1; //使用PC
		
		//CKCU_PeripClockConfig(CKCU_PeripClockConfig_TypeDef Clock, ControlStatus Cmd);
		CKCU_PeripClockConfig(BuzzerCLOCK,ENABLE); //使能时钟
		//GPIO_DirectionConfig(HT_GPIO_TypeDef* HT_GPIOx, u16 GPIO_PIN_nBITMAP, GPIO_DIR_Enum GPIO_DIR_INorOUT);
		GPIO_DirectionConfig(HT_GPIO_Buzzer_PORT,HT_GPIO_Buzzer_PIN,GPIO_DIR_OUT); //配置GPIO PC15为输出模式
		//GPIO_WriteOutBits(HT_GPIO_TypeDef* HT_GPIOx, u16 GPIO_PIN_nBITMAP, FlagStatus Status);
		GPIO_WriteOutBits(HT_GPIO_Buzzer_PORT,HT_GPIO_Buzzer_PIN,SET); //将LED1 LED2 熄灭	
}



void Buzzer_Running(void)
{
	uint8_t i = 0;
	for(i = 0;i < 10;i++)
	{
		Buzzer_ON();
		delay_ms(500);
		Buzzer_OFF();
		delay_ms(500);
	}
	
}