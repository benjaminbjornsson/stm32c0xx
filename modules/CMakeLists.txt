# include CMSIS headers
target_include_directories(bsp PUBLIC cmsis_core/CMSIS/Core/Include)

# include STM32C0 CMSIS headers
target_include_directories(bsp PUBLIC
        cmsis_stm32c0xx/Include
        hal_stm32c0xx/Inc
)

target_sources(bsp PUBLIC
        hal_stm32c0xx/Src/stm32c0xx_ll_utils.c
)
