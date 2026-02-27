//-----------------------------------------------------------------------------
#ifndef __GPIO_H
#define __GPIO_H

#include "ht32.h"

//-----------------------------------------------------------------------------

#define OUT_PA4_PORT           A
#define OUT_PA4_PIN            4
#define OUT_PA4_GPIO_CLK      STRCAT2(P,          OUT_PA4_PORT)
#define OUT_PA4_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA4_PORT)
#define OUT_PA4_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA4_PORT)
#define OUT_PA4_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA4_PIN)
#define OUT_PA4_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA4_HIGH          OUT_PA4_GPIO_PORT->SRR    = OUT_PA4_GPIO_PIN
#define OUT_PA4_LOW           OUT_PA4_GPIO_PORT->RR     = OUT_PA4_GPIO_PIN
#define OUT_PA4_XOR           OUT_PA4_GPIO_PORT->DOUTR ^= OUT_PA4_GPIO_PIN

#define OUT_PA5_PORT           A
#define OUT_PA5_PIN            5
#define OUT_PA5_GPIO_CLK      STRCAT2(P,          OUT_PA5_PORT)
#define OUT_PA5_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA5_PORT)
#define OUT_PA5_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA5_PORT)
#define OUT_PA5_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA5_PIN)
#define OUT_PA5_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA5_HIGH          OUT_PA5_GPIO_PORT->SRR    = OUT_PA5_GPIO_PIN
#define OUT_PA5_LOW           OUT_PA5_GPIO_PORT->RR     = OUT_PA5_GPIO_PIN
#define OUT_PA5_XOR           OUT_PA5_GPIO_PORT->DOUTR ^= OUT_PA5_GPIO_PIN

#define OUT_PA6_PORT           A
#define OUT_PA6_PIN            6
#define OUT_PA6_GPIO_CLK      STRCAT2(P,          OUT_PA6_PORT)
#define OUT_PA6_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA6_PORT)
#define OUT_PA6_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA6_PORT)
#define OUT_PA6_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA6_PIN)
#define OUT_PA6_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA6_HIGH          OUT_PA6_GPIO_PORT->SRR    = OUT_PA6_GPIO_PIN
#define OUT_PA6_LOW           OUT_PA6_GPIO_PORT->RR     = OUT_PA6_GPIO_PIN
#define OUT_PA6_XOR           OUT_PA6_GPIO_PORT->DOUTR ^= OUT_PA6_GPIO_PIN

#define OUT_PA7_PORT           A
#define OUT_PA7_PIN            7
#define OUT_PA7_GPIO_CLK      STRCAT2(P,          OUT_PA7_PORT)
#define OUT_PA7_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA7_PORT)
#define OUT_PA7_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA7_PORT)
#define OUT_PA7_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA7_PIN)
#define OUT_PA7_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA7_HIGH          OUT_PA7_GPIO_PORT->SRR    = OUT_PA7_GPIO_PIN
#define OUT_PA7_LOW           OUT_PA7_GPIO_PORT->RR     = OUT_PA7_GPIO_PIN
#define OUT_PA7_XOR           OUT_PA7_GPIO_PORT->DOUTR ^= OUT_PA7_GPIO_PIN


//-----------------------------------------------------------------------------
#define OUT_PC14_PORT           C
#define OUT_PC14_PIN            14
#define OUT_PC14_GPIO_CLK      STRCAT2(P,          OUT_PC14_PORT)
#define OUT_PC14_GPIO_ID       STRCAT2(GPIO_P,     OUT_PC14_PORT)
#define OUT_PC14_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PC14_PORT)
#define OUT_PC14_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PC14_PIN)
#define OUT_PC14_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PC14_HIGH          OUT_PC14_GPIO_PORT->SRR    = OUT_PC14_GPIO_PIN
#define OUT_PC14_LOW           OUT_PC14_GPIO_PORT->RR     = OUT_PC14_GPIO_PIN
#define OUT_PC14_XOR           OUT_PC14_GPIO_PORT->DOUTR ^= OUT_PC14_GPIO_PIN



//-----------------------------------------------------------------------------
void GPIO_Configuration(void);

#endif

