# Create STM32C031C6 Board support library
add_library(bsp)

add_compile_definitions(STM32C031xx)

target_sources(bsp PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/startup_stm32c031.c
        ${CMAKE_CURRENT_LIST_DIR}/../system_stm32c0xx.c
)

set(LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/gcc/stm32c031c6.ld)
