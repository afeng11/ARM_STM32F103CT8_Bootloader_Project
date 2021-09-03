/************************************************************/
/* AUTHOR      : Omar Sameh Mahmoud                         */
/* DESCRIPTION : DMA DRIVER    [ DMA_Config.h]              */
/* DATE        : 6 December 2019                            */
/************************************************************/
#ifndef _DMA1_C0NFG_H
#define _DMA1_C0NFG_H

/* DMA */
/**********************************************************************************************************************/
/*                                                Channel Triggring events                                            */
/**********************************************************************************************************************/
/*    CHANNEL1     :   ADC1, TIM2_CH3, TIM2_CH3                                                                       */
/**********************************************************************************************************************/
/*    CHANNEL2     :   USART3_TX, SPI1_RX, TIM3_CH3, TIM1_CH1, TIM2_UP                                                */
/**********************************************************************************************************************/
/*    CHANNEL3     :   SPI1_TX, TIM1_CH2, TIM3_CH4, TIM3_UP, USART3_RX                                                */
/**********************************************************************************************************************/
/*    CHANNEL4     :   USART1_TX, TIM1_CH4, SPI/I2S2_RX, I2C2_TX, TIM1_TRIG, TIM4_CH2 , TIM1_COM                      */
/**********************************************************************************************************************/
/*    CHANNEL5     :   USART1_RX, TIM1_UP, TIM4_CH3, TIM2_CH1, SPI/I2S2_TX, I2C2_RX                                   */
/**********************************************************************************************************************/
/*    CHANNEL6     :   I2C1_TX, TIM3_CH1, USART2_RX, TIM3_TRIG, TIM1_CH3                                              */
/**********************************************************************************************************************/
/*    CHANNEL7     :   I2C1_RX, TIM2_CH2, USART2_TX, TIM2_CH4, TIM4_UP                                                */
/**********************************************************************************************************************/


/************************************************************/
/*  Macro      : CHx_MEM2MEM_STATE                          */
/*  Description: Channel triggering mode.                   */
/*  Range:                                                  */
/*       MEM2MEM_ENABLE   [auto triggering]                 */
/*       MEM2MEM_DISABLE  [peripheral event triggering]     */
/************************************************************/
#define CH1_MEM2MEM_STATE           MEM2MEM_ENABLE

#define CH2_MEM2MEM_STATE           MEM2MEM_ENABLE

#define CH3_MEM2MEM_STATE           MEM2MEM_ENABLE

#define CH4_MEM2MEM_STATE           MEM2MEM_DISABLE

#define CH5_MEM2MEM_STATE           MEM2MEM_DISABLE

#define CH6_MEM2MEM_STATE           MEM2MEM_ENABLE

#define CH7_MEM2MEM_STATE           MEM2MEM_ENABLE

/************************************************************/
/*  Macro      : CHx_PRIORITY_LEVEL                         */
/*  Description: channel priority in case of arbitraion.    */
/*  Range:                                                  */
/*       PRIORITY_LOW                                       */
/*       PRIORITY_MEDIUM                                    */
/*       PRIORITY_HIGH                                      */
/*       PRIORITY_VERY_HIGH                                 */
/************************************************************/
#define CH1_PRIORITY_LEVEL          PRIORITY_HIGH

#define CH2_PRIORITY_LEVEL          PRIORITY_LOW

#define CH3_PRIORITY_LEVEL          PRIORITY_LOW

#define CH4_PRIORITY_LEVEL          PRIORITY_VERY_HIGH

#define CH5_PRIORITY_LEVEL          PRIORITY_VERY_HIGH

#define CH6_PRIORITY_LEVEL          PRIORITY_LOW

#define CH7_PRIORITY_LEVEL          PRIORITY_LOW

/************************************************************/
/*  Macro      : CHx_SRC                                    */
/*  Description: Channel Data Source.                       */
/*  Range      :                                            */
/*             DMA1_PERIPHERAL                              */
/*             DMA1_MEMORY                                  */
/************************************************************/
#define CH1_SRC                     DMA1_PERIPHERAL

#define CH2_SRC                     DMA1_PERIPHERAL

#define CH3_SRC                     DMA1_PERIPHERAL

#define CH4_SRC                     DMA1_MEMORY

#define CH5_SRC                     DMA1_PERIPHERAL

#define CH6_SRC                     DMA1_PERIPHERAL

#define CH7_SRC                     DMA1_MEMORY

/************************************************************/
/*  Macro      : CHx_PRF_INC_MODE                           */
/*  Description: increment PRF address every cycle.         */
/*  Range:                                                  */
/*       PRF_INC_ENABLE  [PRF address is incremented]       */
/*       PRF_INC_DISABLE [PRF address isn't incremented]    */
/************************************************************/
#define CH1_PRF_INC_MODE            PRF_INC_ENABLE

#define CH2_PRF_INC_MODE            PRF_INC_ENABLE

#define CH3_PRF_INC_MODE            PRF_INC_ENABLE

#define CH4_PRF_INC_MODE            PRF_INC_DISABLE

#define CH5_PRF_INC_MODE            PRF_INC_DISABLE

#define CH6_PRF_INC_MODE            PRF_INC_ENABLE

#define CH7_PRF_INC_MODE            PRF_INC_ENABLE

/************************************************************/
/*  Macro      : CHx_MEM_INC_MODE                           */
/*  Description: increment destination address every cycle. */
/*  Range:                                                  */
/*       MEM_INC_ENABLE  [PRF address is incremented]       */
/*       MEM_INC_DISABLE [destination address not changed]  */
/************************************************************/
#define CH1_MEM_INC_MODE            MEM_INC_ENABLE

#define CH2_MEM_INC_MODE            MEM_INC_ENABLE

#define CH3_MEM_INC_MODE            MEM_INC_ENABLE

#define CH4_MEM_INC_MODE            MEM_INC_ENABLE

#define CH5_MEM_INC_MODE            MEM_INC_ENABLE

#define CH6_MEM_INC_MODE            MEM_INC_ENABLE

#define CH7_MEM_INC_MODE            MEM_INC_DISABLE

/************************************************************/
/*  Macro      : CHx_CIRCULAR_MODE                          */
/*  Description: retrigger the DMA enable after finishing.  */
/*  Range:                                                  */
/*       CIRCULAR_ENABLE                                    */
/*       CIRCULAR_DISABLE                                   */
/************************************************************/
#define CH1_CIRCULAR_MODE           CIRCULAR_DISABLE

#define CH2_CIRCULAR_MODE           CIRCULAR_DISABLE

#define CH3_CIRCULAR_MODE           CIRCULAR_DISABLE

#define CH4_CIRCULAR_MODE           CIRCULAR_DISABLE

#define CH5_CIRCULAR_MODE           CIRCULAR_ENABLE

#define CH6_CIRCULAR_MODE           CIRCULAR_DISABLE

#define CH7_CIRCULAR_MODE           CIRCULAR_DISABLE

/************************************************************/
/*  Macro      : CHx_TRANSFER_ERROR_IR                      */
/*  Description: IRQ generation control for transfer errors.*/
/*  Range:                                                  */
/*       TRANSFER_ERROR_ENABLE                              */
/*       TRANSFER_ERROR_DISABLE                             */
/************************************************************/
#define CH1_TRANSFER_ERROR_IRQ      TRANSFER_ERROR_ENABLE

#define CH2_TRANSFER_ERROR_IRQ      TRANSFER_ERROR_ENABLE

#define CH3_TRANSFER_ERROR_IRQ      TRANSFER_ERROR_ENABLE

#define CH4_TRANSFER_ERROR_IRQ      TRANSFER_ERROR_ENABLE

#define CH5_TRANSFER_ERROR_IRQ      TRANSFER_ERROR_DISABLE

#define CH6_TRANSFER_ERROR_IRQ      TRANSFER_ERROR_ENABLE

#define CH7_TRANSFER_ERROR_IRQ      TRANSFER_ERROR_ENABLE

/************************************************************/
/*  Macro      : CHx_TRANSFER_COMPLETE_IRQ                  */
/*  Description: IRQ generation for transfer complete.      */
/*  Range:                                                  */
/*       TRANSFER_COMPLETE_ENABLE                           */
/*       TRANSFER_COMPLETE_DISABLE                          */
/************************************************************/
#define CH1_TRANSFER_COMPLETE_IRQ   TRANSFER_COMPLETE_ENABLE

#define CH2_TRANSFER_COMPLETE_IRQ   TRANSFER_COMPLETE_ENABLE

#define CH3_TRANSFER_COMPLETE_IRQ   TRANSFER_COMPLETE_ENABLE

#define CH4_TRANSFER_COMPLETE_IRQ   TRANSFER_COMPLETE_ENABLE

#define CH5_TRANSFER_COMPLETE_IRQ   TRANSFER_COMPLETE_ENABLE

#define CH6_TRANSFER_COMPLETE_IRQ   TRANSFER_COMPLETE_ENABLE

#define CH7_TRANSFER_COMPLETE_IRQ   TRANSFER_COMPLETE_ENABLE

/************************************************************/
/*  Macro      : CHx_HALF_TRANSFER_IRQ                      */
/*  Description: IRQ generation for half transfer complete. */
/*  Range:                                                  */
/*       HALF_TRANSFER_ENABLE                               */
/*       HALF_TRANSFER_DISABLE                              */
/************************************************************/
#define CH1_HALF_TRANSFER_IRQ       HALF_TRANSFER_ENABLE

#define CH2_HALF_TRANSFER_IRQ       HALF_TRANSFER_ENABLE

#define CH3_HALF_TRANSFER_IRQ       HALF_TRANSFER_ENABLE

#define CH4_HALF_TRANSFER_IRQ       HALF_TRANSFER_ENABLE

#define CH5_HALF_TRANSFER_IRQ       HALF_TRANSFER_DISABLE

#define CH6_HALF_TRANSFER_IRQ       HALF_TRANSFER_ENABLE

#define CH7_HALF_TRANSFER_IRQ       HALF_TRANSFER_ENABLE

/************************************************************/
/*  Macro      : MemSize_Type                               */
/*  Description: Memory Size                                */
/*  Range:                                                  */
/*       MEM_8_BIT                                          */
/*       MEM_16_BIT                                         */
/* 		 MEM_32_BIT                                         */
/************************************************************/
#define MEMSIZE_Type                MEM_8_BIT

/************************************************************/
/*  Macro      : PREFSIZE_Type                              */
/*  Description: Pherpherial Size                           */
/*  Range:                                                  */
/*       PRF_8_BIT                                          */
/*       PRF_16_BIT                                         */
/* 		 PRF_32_BIT                                         */
/************************************************************/
#define PREFSIZE_Type                PRF_8_BIT

#endif
