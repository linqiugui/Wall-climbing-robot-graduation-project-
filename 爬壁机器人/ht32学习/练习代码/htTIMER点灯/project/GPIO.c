//-----------------------------------------------------------------------------
#include "GPIO.h"

//-----------------------------------------------------------------------------
void GPIOC14_Configuration(void)
{
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
  CKCUClock.Bit.PC    = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);



  GPIO_ClearOutBits       (OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN, GPIO_DIR_OUT);
}

void GPIOC15_Configuration(void)
{
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
  CKCUClock.Bit.PC    = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);



  GPIO_ClearOutBits       (OUT_PC15_GPIO_PORT, OUT_PC15_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PC15_GPIO_PORT, OUT_PC15_GPIO_PIN, GPIO_DIR_OUT);
}
//-----------------------------------------------------------------------------

void LED1_ON(void)
{

	GPIO_ClearOutBits       (OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);

}
void LED1_OFF(void)
{

	GPIO_SetOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//ÃðµÆ

}


void LED2_ON(void)
{

	GPIO_ClearOutBits       (OUT_PC15_GPIO_PORT, OUT_PC15_GPIO_PIN);

}
void LED2_OFF(void)
{

	GPIO_SetOutBits(OUT_PC15_GPIO_PORT, OUT_PC15_GPIO_PIN);//ÃðµÆ

}
