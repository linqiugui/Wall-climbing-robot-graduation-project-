//-----------------------------------------------------------------------------
#include "GPIO.h"

//-----------------------------------------------------------------------------
void GPIO_Configuration(void)
{
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
  CKCUClock.Bit.PC    = 1;
  CKCUClock.Bit.PA    = 1;
  CKCUClock.Bit.AFIO  = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);


  
  GPIO_ClearOutBits       (OUT_PA4_GPIO_PORT, OUT_PA4_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA4_GPIO_PORT, OUT_PA4_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA5_GPIO_PORT, OUT_PA5_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA5_GPIO_PORT, OUT_PA5_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA6_GPIO_PORT, OUT_PA6_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA6_GPIO_PORT, OUT_PA6_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_SetOutBits         (OUT_PA7_GPIO_PORT, OUT_PA7_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA7_GPIO_PORT, OUT_PA7_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN, GPIO_DIR_OUT);
}

//-----------------------------------------------------------------------------


