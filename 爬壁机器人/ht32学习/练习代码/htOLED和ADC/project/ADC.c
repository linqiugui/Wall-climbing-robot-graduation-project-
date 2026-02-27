#include "ADC.h"

uint32_t AD_Value[4];

void ADC_Configuration(void)
{
	PDMACH_InitTypeDef PDMACH_InitStructure;                    //定义结构体，配置PDMA
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};//定义结构体，配置时钟
    CKCUClock.Bit.PA = 1;                       //开启GPIOA时钟
    CKCUClock.Bit.ADC = 1;                      //开启ADC时钟
    CKCUClock.Bit.AFIO = 1;                     //开启AFIO时钟
    CKCUClock.Bit.PDMA = 1;                     //开启PDMA时钟
    CKCU_PeripClockConfig(CKCUClock, ENABLE);   //使能外设时钟

    ADC_Reset(HT_ADC);                          //重置ADC
    CKCU_SetADCPrescaler(CKCU_ADCPRE_DIV4);     //设置ADC时钟分频

    AFIO_GPxConfig(GPIO_PA, AFIO_PIN_0, AFIO_FUN_ADC); //配置PA0引脚AFIO模式为ADC
    AFIO_GPxConfig(GPIO_PA, AFIO_PIN_1, AFIO_FUN_ADC); 
    AFIO_GPxConfig(GPIO_PA, AFIO_PIN_2, AFIO_FUN_ADC); 
    AFIO_GPxConfig(GPIO_PA, AFIO_PIN_3, AFIO_FUN_ADC);
    // https://blog.zeruns.tech
    ADC_RegularChannelConfig(HT_ADC, ADC_CH_0, 0);      //配置ADC规则组，在规则组的序列0写入通道0
    ADC_RegularChannelConfig(HT_ADC, ADC_CH_1, 1);      //配置ADC规则组，在规则组的序列1写入通道1
    ADC_RegularChannelConfig(HT_ADC, ADC_CH_2, 2);
    ADC_RegularChannelConfig(HT_ADC, ADC_CH_3, 3);
    // https://blog.vpszj.cn
    ADC_RegularGroupConfig(HT_ADC, CONTINUOUS_MODE, 4, 1);  //配置ADC转换模式为连续转换，队列长度为4
    ADC_RegularTrigConfig(HT_ADC, ADC_TRIG_SOFTWARE);       //配置ADC触发源软件触发
    ADC_SamplingTimeConfig(HT_ADC, 16);                     //配置ADC输入通道采样时间
    // ADC_IntConfig(HT_ADC, ADC_INT_CYCLE_EOC, ENABLE);    //配置ADC中断
    // NVIC_EnableIRQ(ADC_IRQn);                            //使能ADC中断

    
    PDMACH_InitStructure.PDMACH_SrcAddr = (u32)(&HT_ADC->DR);   //源数据地址，设置为ADC_DR寄存器
    PDMACH_InitStructure.PDMACH_DstAddr = (u32)AD_Value;        //目的数据地址
    PDMACH_InitStructure.PDMACH_AdrMod = SRC_ADR_LIN_INC | DST_ADR_LIN_INC | AUTO_RELOAD;//地址自增模式
    PDMACH_InitStructure.PDMACH_Priority = H_PRIO;              //设置通道的转运优先级为高
    PDMACH_InitStructure.PDMACH_BlkCnt = 4;                     //传输计数，设置传输4次
    PDMACH_InitStructure.PDMACH_BlkLen = 1;
    PDMACH_InitStructure.PDMACH_DataSize = WIDTH_32BIT;         //数据宽度，设置为32位
    PDMA_Config(PDMA_CH0, &PDMACH_InitStructure);               //初始化PDMA0

    // PDMA_IntConfig(PDMA_CH0, (PDMA_INT_GE | PDMA_INT_TC), ENABLE);   //配置PDMA中断

    PDMA_EnaCmd(PDMA_CH0, ENABLE);                          //使能PDMA0
    ADC_PDMAConfig(HT_ADC, ADC_PDMA_REGULAR_CYCLE, ENABLE); //使能ADC的PDMA触发信号
    ADC_Cmd(HT_ADC, ENABLE);                                //使能ADC
    ADC_SoftwareStartConvCmd(HT_ADC, ENABLE);               //软件触发ADC转换
    PDMA_SwTrigCmd(PDMA_CH0, ENABLE);                       //软件触发PWMA
}
