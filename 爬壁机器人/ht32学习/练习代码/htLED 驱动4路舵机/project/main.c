
#include "ht32.h"
#include "GPIO.h"
#include "time.h"

void delay(){

	unsigned int i,j;
	for(i=0;i<3500;i++){
	
	for(j=0;j<3000;j++){
	 }	
	}

}

//-----------------------------------------------------------------------------
int main(void)
{
	GPIOC14_Configuration();
	GPIOC15_Configuration();
    GPTM_PWM_init();
//	Servo_Run(45);
  while (1)
  {
	  
		LED1_ON();
		delay();
		LED1_OFF();
		delay();	
	  
//		Servo_Run(0);
//		delay();
//		Servo_Run(45);
//		delay();
		
		Servo_Run3(0);
		delay();
		Servo_Run3(180);
		delay();
//		
//		Servo_Run3(0);
//		delay();
//		Servo_Run3(45);
//		delay();
//		
//		Servo_Run4(0);
//		delay();
//		Servo_Run4(45);
//		delay();

	  
  }
}
