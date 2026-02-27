#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"
#include "uart.h"
#include "dht11.h"
#include "oled.h"
#include "fire.h"
#include "buzzer.h"

/**********************TH32 火焰报警**********************
Author:小殷

Date:2022-5-1
******************************************************/
uint8_t data = 0;
uint8_t sendbuf[128] = {0};



//火焰检测 
void Fire_Test(void)
{
	//火焰传感器1
	if(GPIO_Read_Stat1() == RESET)
	{
		//LED1_ON();
		//printf("has fire\n"); //测试提示
		Buzzer_Running();
		//delay_ms(1000);
	}
	else{
		
		//LED1_OFF();
		//printf("has no fire\n"); //测试提示
		//delay_ms(1000);
		Buzzer_OFF();
	}
	//火焰传感器2
	if(GPIO_Read_Stat2() == RESET)
	{
		//LED2_ON();
		//printf("has fire2\n");
		Buzzer_Running();
		//delay_ms(500);
	}
	else{
		
		//LED2_OFF();
		//printf("has no fire2\n"); //测试提示
		Buzzer_OFF();
		//delay_ms(1000);
	}
	//火焰传感器3
	
	if(GPIO_Read_Stat3() == RESET)
	{
		//LED2_ON();
		//printf("has fire3\n"); //测试提示
		Buzzer_Running();
		//delay_ms(500);
	}
	else{
		
		//LED2_OFF();
		//printf("has no fire3\n"); // 测试提示
		//delay_ms(1000);	
		Buzzer_OFF();
	}
	//火焰传感器4
	if(GPIO_Read_Stat4() == RESET)
	{
		//LED2_ON();
		//printf("has fire4\n"); //测试提示
		Buzzer_Running();
		//delay_ms(500);
	}
	else{
		
		//LED2_OFF();
		//printf("has no fire4\n"); //测试提示
		//delay_ms(1000);		
		Buzzer_OFF();
	}	
}


int main()
{
	Led_Init();  					 //LED初始化
	//dou_dht11_init(); 		//dht11初始化
	USARTx_Init();   			//uart初始化
	//OLED_Init();     			//oled 初始化
	Init_Fire();
	Buzzer_Init();          //Buzzer初始化
	Usart_SendStr(HT_USART1,(uint8_t *)"------HT32 fire TEST-------\r\n");//循环发送字符串，测试用

	while(1)
	{
		//LED2_ON();
	  Fire_Test();
	}
		
}






