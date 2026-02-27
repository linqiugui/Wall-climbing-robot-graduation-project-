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

/**********************TH32 ´®¿ÚµãµÆ**********************
Author:Ð¡Òó

Date:2022-4-18
******************************************************/
uint8_t data = 0;

int main()
{
	GPIO_Configuration();
	USARTx_Init();
	Usart_SendStr(COM1_PORT,(uint8_t *)"------HT32 UART TEST-------\r\n");//Ñ­»··¢ËÍ×Ö·û´®£¬²âÊÔÓÃ
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
