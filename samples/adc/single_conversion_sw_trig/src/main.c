#include "stm32c0xx.h"

#include "stm32c0xx_ll_adc.h"
#include "stm32c0xx_ll_bus.h"

#include <stdint.h>

static uint16_t vdda, vssa;

void _start(void)
{
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC);

        LL_ADC_EnableInternalRegulator(ADC1);
        while(!LL_ADC_IsInternalRegulatorEnabled(ADC1));

        LL_ADC_StartCalibration(ADC1);
        while(!LL_ADC_IsActiveFlag_EOCAL(ADC1));

        LL_ADC_REG_SetSequencerChannels(ADC1, LL_ADC_CHANNEL_VDDA | LL_ADC_CHANNEL_VSSA);

        while(!LL_ADC_IsActiveFlag_CCRDY(ADC1));

        LL_ADC_SetLowPowerMode(ADC1, LL_ADC_LP_AUTOWAIT);

        LL_ADC_Enable(ADC1);
        while(!LL_ADC_IsActiveFlag_ADRDY(ADC1));

        LL_ADC_REG_StartConversion(ADC1);

        while(!LL_ADC_IsActiveFlag_EOC(ADC1));
        vdda = LL_ADC_REG_ReadConversionData12(ADC1);

        while(!LL_ADC_IsActiveFlag_EOC(ADC1));
        vssa = LL_ADC_REG_ReadConversionData12(ADC1);

        while(1) {
        }
}
