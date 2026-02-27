#include "fire.h"
#include "led.h"

void Init_Fire(void)
{
		CKCU_PeripClockConfig_TypeDef FIRELOCK ={{0}};
		FIRELOCK.Bit.PC = 1; //使用PC
		
		CKCU_PeripClockConfig(FIRELOCK,ENABLE); //使能时钟
		
		//AFIO_GPxConfig(GPIO_PA,HT_GPIO_FIRE_PIN,AFIO_MODE_DEFAULT);
		//GPIO_DirectionConfig(HT_GPIO_TypeDef* HT_GPIOx, u16 GPIO_PIN_nBITMAP, GPIO_DIR_Enum GPIO_DIR_INorOUT);
		GPIO_DirectionConfig(HT_GPIO_PORT,HT_GPIO_FIRE_PIN,GPIO_DIR_IN); //配置PD1/2/3为输入模式	
		GPIO_PullResistorConfig(HT_GPIO_PORT,HT_GPIO_FIRE_PIN,GPIO_PR_DOWN); //上拉
		GPIO_InputConfig(HT_GPIO_PORT,HT_GPIO_FIRE_PIN,ENABLE);	
		//GPIO_WriteOutBits(HT_GPIO_PORT,HT_GPIO_FIRE_PIN,RESET);
}





