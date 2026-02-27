////-----------------------------------------------------------------------------
//#include "ht32.h"

//#include "UART.h"

//void delay(){

//	unsigned int i,j;
//	for(i=0;i<1000;i++){
//	
//	for(j=0;j<1000;j++){
//	 }	
//	}

//}

////-----------------------------------------------------------------------------
//int main(void)
//{
//	GPIO_Configuration();
//	USARTx_Init();
//  while (1)
//  {
//	  GPIO_ClearOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//µãµÆ
//	  delay();//ÑÓÊ±
//	  
//	  GPIO_SetOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//ÃðµÆ
//	  delay();//ÑÓÊ±
//	  Usart_Sendbyte(COM_PORT,0x03);
//  }
//}
#include "ht32.h"
#include "ht32_board.h"
#include "GPIO.h"
#include "uart.h"
#include "key.h"

/**********************TH32 ´®¿ÚµãµÆ**********************
Author:Ð¡Òó

Date:2022-4-18
******************************************************/
uint8_t data = 0;		//´®¿ÚÊý¾Ý
uint8_t key_stat = 0; //°´¼ü×´Ì¬
int main()
{
	GPIOC14_Configuration();
	GPIOC15_Configuration();
	USARTx_Init();
	Key_Init();
	Usart_SendStr(COM1_PORT,(uint8_t *)"------HT32 UART TEST-------\r\n");//Ñ­»··¢ËÍ×Ö·û´®£¬²âÊÔÓÃ
//	GPIO_SetOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//ÃðµÆ
//	GPIO_SetOutBits(OUT_PC15_GPIO_PORT, OUT_PC15_GPIO_PIN);//ÃðµÆ
	while(1)
	{
		
	}
}



void COM_IRQHandler(void)
{
	u8 data;
	
	if( USART_GetFlagStatus(COM_PORT, USART_FLAG_RXDR) )
	{
		data = USART_ReceiveData(COM_PORT);
		
		
		if(data == '0')
		{
			GPIO_ClearOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//ÁÁµÆ
			printf("data = %c \r\n",data);
			printf("LED1 ON\r\n");
		}
		else if(data == '1')
		{
			GPIO_SetOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//ÃðµÆ
			printf("data = %c \r\n",data);
			printf("LED1 OFF\r\n");
		}
		//EXTI_ClearEdgeFlag(EXTI_CHANNEL_2);
	}

}


void EXTI4_15_IRQHandler(void)
{	
    if(key_stat == 0)
		{
			key_stat = 1;
			GPIO_ClearOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//ÁÁµÆ
		}
		else if(key_stat == 1)
		{
			key_stat = 0;
			GPIO_SetOutBits(OUT_PC14_GPIO_PORT, OUT_PC14_GPIO_PIN);//ÃðµÆ
		}
		EXTI_ClearEdgeFlag(EXTI_CHANNEL_4);
}

void EXTI2_3_IRQHandler(void)
{
	 if(key_stat == 0)
		{
			key_stat = 1;
			GPIO_ClearOutBits(OUT_PC15_GPIO_PORT, OUT_PC15_GPIO_PIN);//ÁÁµÆ
		}
		else if(key_stat == 1)
		{
			key_stat = 0;
			GPIO_SetOutBits(OUT_PC15_GPIO_PORT, OUT_PC15_GPIO_PIN);//ÃðµÆ
		}
		EXTI_ClearEdgeFlag(EXTI_CHANNEL_2);
}


