cmake_minimum_required(VERSION 3.27.7)

project(stm32c0xx LANGUAGES C)

include(boards/stm32c0xx/nucleo_c031c6/CMakeLists.txt)
include(samples/blinky/CMakeLists.txt)

add_subdirectory(modules)

set(CMAKE_EXECUTABLE_SUFFIX ".elf")
set(CMAKE_C_FLAGS "-ffreestanding -mthumb -mcpu=cortex-m0plus -fdata-sections -ffunction-sections")
set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs -nostartfiles -T ${LINKER_SCRIPT}")
