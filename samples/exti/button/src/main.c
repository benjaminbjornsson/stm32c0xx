#include "stm32c0xx.h"

#include "stm32c0xx_ll_bus.h"
#include "stm32c0xx_ll_exti.h"
#include "stm32c0xx_ll_gpio.h"

void _start(void)
{
        SystemCoreClockUpdate();

        LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
        LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOC);

        LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
        LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_13, LL_GPIO_MODE_INPUT);

        LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTC, LL_EXTI_CONFIG_LINE13);
        LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_13);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_13);

        NVIC_EnableIRQ(EXTI4_15_IRQn);

        while(1) {}
}

void EXTI4_15_Handler(void)
{
        LL_EXTI_ClearFallingFlag_0_31(LL_EXTI_LINE_13);
        LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_5);
}
