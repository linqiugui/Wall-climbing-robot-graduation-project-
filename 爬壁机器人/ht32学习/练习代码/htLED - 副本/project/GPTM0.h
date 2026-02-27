//-----------------------------------------------------------------------------
#ifndef __GPTM0_H
#define __GPTM0_H


//-----------------------------------------------------------------------------
#include "ht32.h"

//-----------------------------------------------------------------------------
void GPTM0_Configuration(void);
void GPTM0_SetFrequency(u32 freq);
void GPTM0_CH0_SetOnduty(u16 percent);
void GPTM0_CH0_EnablePWMOutput(void);
void GPTM0_CH0_DisablePWMOutput(u8 IO_State);
void GPTM0_CH1_SetOnduty(u16 percent);
void GPTM0_CH1_EnablePWMOutput(void);
void GPTM0_CH1_DisablePWMOutput(u8 IO_State);

//-----------------------------------------------------------------------------
#endif


