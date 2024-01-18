#include "stm32c0xx.h"

#include "stm32c0xx_ll_bus.h"
#include "stm32c0xx_ll_gpio.h"
#include "stm32c0xx_ll_tim.h"
#include "stm32c0xx_ll_utils.h"

void _start(void)
{
        SystemCoreClockUpdate();
        LL_Init1msTick(SystemCoreClock);

        LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);

        LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_0, LL_GPIO_MODE_ALTERNATE);
        LL_GPIO_SetAFPin_0_7(GPIOA, LL_GPIO_PIN_0, LL_GPIO_AF_5);

        LL_TIM_OC_ConfigOutput(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_OCPOLARITY_HIGH | LL_TIM_OCIDLESTATE_LOW);
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
        LL_TIM_EnableAllOutputs(TIM1);

        LL_TIM_SetPrescaler(TIM1, 1200);
        LL_TIM_SetAutoReload(TIM1, 100 - 1);
        LL_TIM_EnableCounter(TIM1);

        int i = 0;
        while(1) {
                LL_mDelay(10);
                LL_TIM_OC_SetCompareCH1(TIM1, i);
                i = (i + 1) % 100;
        }
}
