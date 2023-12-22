#include "stm32c0xx.h"

#include "stm32c0xx_ll_bus.h"
#include "stm32c0xx_ll_dma.h"

const char src_bytes[] = "Hello, DMA!";
static char dest_bytes[20];

void _start(void)
{
        SystemCoreClockUpdate();

        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
        
        LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1, LL_DMA_DIRECTION_MEMORY_TO_MEMORY);
        LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MODE_NORMAL);
        LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PERIPH_INCREMENT);
        LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MEMORY_INCREMENT);
        LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PDATAALIGN_BYTE);
        LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MDATAALIGN_BYTE);
        LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PRIORITY_LOW);

        LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, sizeof(src_bytes));
        LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_1, (uint32_t)src_bytes, (uint32_t)dest_bytes, LL_DMA_DIRECTION_MEMORY_TO_MEMORY);

        LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);

        while(1) {}
}
