//-----------------------------------------------------------------------------
#include "ht32.h"
#include "GPIO.h"
#include "OLED.h"
#include "OLED_Font.h"
#include "ADC.h"
void delay(){

	unsigned int i,j;
	for(i=0;i<1000;i++){
	
	for(j=0;j<1000;j++){
	 }	
	}

}

//-----------------------------------------------------------------------------
int main(void)
{
  GPIO_Configuration();

  while (1)
  {
	OLED_ShowString(35,1,(unsigned char *)"C_T:",3); // Current_Temperature 当前温度
	OLED_ShowCHinese_Three(85,0,11); //C
	
	OLED_ShowString(35,3,(unsigned char *)"C_H:",3); // Current_Humidity 当前湿度
	OLED_ShowCHinese_Three(85,2,13); //
	
	  
	  
	  GPIO_ClearOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//点灯
	  delay();//延时
	  
	  GPIO_SetOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//灭灯
	  delay();//延时
	  
  }
}
