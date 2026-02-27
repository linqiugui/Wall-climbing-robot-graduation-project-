//-----------------------------------------------------------------------------
#include "ht32.h"
#include "GPIO.h"

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
	  GPIO_ClearOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//µãµÆ
	  delay();//ÑÓÊ±
	  
	  GPIO_SetOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//ÃðµÆ
	  delay();//ÑÓÊ±
	  
  }
}
