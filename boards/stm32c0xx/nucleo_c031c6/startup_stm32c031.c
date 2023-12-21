/******************************************************************************
 * @file     startup_stm32c031.c
 * @brief    CMSIS-Core(M) Device Startup File for a Cortex-M0+ Device
 * @version  V2.0.3
 * @date     31. March 2020
 ******************************************************************************/
/*
 * Copyright (c) 2009-2020 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined (STM32C031xx)
#include "stm32c031xx.h"
#else
        #error device not specified!
#endif

/*----------------------------------------------------------------------------
        External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
        Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
                                                void Default_Handler(void);

/*----------------------------------------------------------------------------
        Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void WWDG_Handler                       (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_Handler                        (void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_Handler                      (void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_Handler                        (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_1_Handler                    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_3_Handler                    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_15_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel1_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel2_3_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DMAMUX1_Handler                    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1_Handler                       (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_UP_TRG_COM_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_Handler                    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_Handler                       (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM14_Handler                      (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM16_Handler                      (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM17_Handler                      (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_Handler                       (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_Handler                       (void) __attribute__ ((weak, alias("Default_Handler")));
void USART1_Handler                     (void) __attribute__ ((weak, alias("Default_Handler")));
void USART2_Handler                     (void) __attribute__ ((weak, alias("Default_Handler")));

/*----------------------------------------------------------------------------
        Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/**
        \brief Exception / Interrupt Handler Function Prototype
*/
typedef void(*VECTOR_TABLE_Type)(void);

extern const VECTOR_TABLE_Type __VECTOR_TABLE[48];
const VECTOR_TABLE_Type __VECTOR_TABLE[48] __VECTOR_TABLE_ATTRIBUTE = {
        (VECTOR_TABLE_Type)(&__INITIAL_SP),       /*     Initial Stack Pointer */
        Reset_Handler,                            /*     Reset Handler */
        NMI_Handler,                              /* -14 NMI Handler */
        HardFault_Handler,                        /* -13 Hard Fault Handler */
        0,                                        /*     Reserved */
        0,                                        /*     Reserved */
        0,                                        /*     Reserved */
        0,                                        /*     Reserved */
        0,                                        /*     Reserved */
        0,                                        /*     Reserved */
        0,                                        /*     Reserved */
        SVC_Handler,                              /*  -5 SVCall Handler */
        0,                                        /*     Reserved */
        0,                                        /*     Reserved */
        PendSV_Handler,                           /*  -2 PendSV Handler */
        SysTick_Handler,                          /*  -1 SysTick Handler */

        /* Interrupts */
        WWDG_Handler,
        0,
        RTC_Handler,
        FLASH_Handler,
        RCC_Handler,
        EXTI0_1_Handler,
        EXTI2_3_Handler,
        EXTI4_15_Handler,
        0,
        DMA1_Channel1_Handler,
        DMA1_Channel2_3_Handler,
        DMAMUX1_Handler,
        ADC1_Handler,
        TIM1_BRK_UP_TRG_COM_Handler,
        TIM1_CC_Handler,
        0,
        TIM3_Handler,
        0,
        0,
        TIM14_Handler,
        0,
        TIM16_Handler,
        TIM17_Handler,
        I2C1_Handler,
        0,
        SPI1_Handler,
        0,
        USART1_Handler,
        USART2_Handler,
        0,
        0,
        0,
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
        Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
        SystemInit();                             /* CMSIS System Initialization */
        __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*----------------------------------------------------------------------------
        Hard Fault Handler
 *----------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
        while(1);
}

/*----------------------------------------------------------------------------
        Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
        while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
        #pragma clang diagnostic pop
#endif

