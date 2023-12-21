#include "stm32c0xx.h"

#include "stm32c0xx_ll_bus.h"
#include "stm32c0xx_ll_gpio.h"
#include "stm32c0xx_ll_utils.h"

void _start(void)
{
        SystemCoreClockUpdate();
        LL_Init1msTick(SystemCoreClock);

        LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);

        LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
        LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);

        while(1) {
                LL_mDelay(500);

                LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_5);
        }
}
