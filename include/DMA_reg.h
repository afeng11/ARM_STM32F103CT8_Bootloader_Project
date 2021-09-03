/************************************************************/
/* AUTHOR      : Omar Sameh Mahmoud                         */
/* DESCRIPTION : DMA DRIVER    [ DMA_reg.h]                 */
/* DATE        : 6 December 2019                            */
/************************************************************/
#ifndef _DMA_REG_H
#define _DMA_REG_H

/*********************** DMA1 registers *********************/
#define NULL ((void *)0)

typedef struct
{
		u32 ISR;
		u32 IFCR;
		 /* channel 1 */
		u32 CCR1;
		u32 CNDTR1;
		u32 CPAR1;
		u32 CMAR1;
		const u32 Reserved1;
		 /* channel 2 */
		u32 CCR2;
		u32 CNDTR2;
		u32 CPAR2;
		u32 CMAR2;
		const u32 Reserved2;
		/* channel 3 */
		u32 CCR3;
		u32 CNDTR3;
		u32 CPAR3;
		u32 CMAR3;
		const u32 Reserved3;
		/* channel 4 */
		u32 CCR4;
		u32 CNDTR4;
		u32 CPAR4;
		u32 CMAR4;
		const u32 Reserved4;
		/* channel 5 */
		u32 CCR5;
		u32 CNDTR5;
		u32 CPAR5;
		u32 CMAR5;
		const u32 Reserved5;
		/* channel 6 */
		u32 CCR6;
		u32 CNDTR6;
		u32 CPAR6;
		u32 CMAR6;
		const u32 Reserved6;
		/* channel 7 */
		u32 CCR7;
		u32 CNDTR7;
		u32 CPAR7;
		u32 CMAR7;
		const u32 Reserved7;
}DMA_type;

#define DMA ((DMA_type*)0x40020000)


/*********************** DMA1 Flags *********************/
/* Transfer Error Flags */
#define TEIF1                       3
#define TEIF2                       7
#define TEIF3                       11
#define TEIF4                       15
#define TEIF5                       19
#define TEIF6                       23
#define TEIF7                       27
/* Half Transfer Flags */
#define HTIF1                       2
#define HTIF2                       6
#define HTIF3                       10
#define HTIF4                       14
#define HTIF5                       18
#define HTIF6                       22
#define HTIF7                       26
/* Transfer Complete Flags */
#define TCIF1                       1
#define TCIF2                       5
#define TCIF3                       9
#define TCIF4                       13
#define TCIF5                       17
#define TCIF6                       21
#define TCIF7                       25
/* Global Interrupt Flag */
#define GIF1                        0
#define GIF2                        4
#define GIF3                        8
#define GIF4                        12
#define GIF5                        16
#define GIF6                        20
#define GIF7                        24


/********************************************************/
/* Memory to Memory Pin*/
#define MEM2MEM 14

/********************** MEM2MEM_STATE ***********************/
#define MEM2MEM_ENABLE              0x00004000
#define MEM2MEM_DISABLE             0x00000000

/********************* PRIORITY_LEVEL ***********************/
#define PRIORITY_LOW                0x00000000
#define PRIORITY_MEDIUM             0x00001000
#define PRIORITY_HIGH               0x00002000
#define PRIORITY_VERY_HIGH          0x00003000

/************************ CH1_SRC ***************************/
#define DMA1_PERIPHERAL             0x00000000
#define DMA1_MEMORY                 0x00000010

/*********************** PRF_INC_MODE ***********************/
#define PRF_INC_ENABLE              0x00000040
#define PRF_INC_DISABLE             0x00000000

/*********************** MEM_INC_MODE ***********************/
#define MEM_INC_ENABLE              0x00000080
#define MEM_INC_DISABLE             0x00000000

/*********************** CIRCULAR_MODE **********************/
#define CIRCULAR_ENABLE             0x00000020
#define CIRCULAR_DISABLE            0x00000000

/******************** TRANSFER_ERROR_IRQ ********************/
#define TRANSFER_ERROR_ENABLE       0x00000008
#define TRANSFER_ERROR_DISABLE      0x00000000

/******************* TRANSFER_COMPLETE_IRQ ******************/
#define TRANSFER_COMPLETE_ENABLE    0x00000004
#define TRANSFER_COMPLETE_DISABLE   0x00000000

/********************* HALF_TRANSFER_IRQ ********************/
#define HALF_TRANSFER_ENABLE        0x00000002
#define HALF_TRANSFER_DISABLE       0x00000000

/**********************Memory Size****************************/
#define MEM_8_BIT      			    0x00000000
#define MEM_16_BIT                  0x00000400
#define MEM_32_BIT                  0x00000800

/**********************Perpherial Size****************************/
#define PRF_8_BIT                  0x00000000
#define PRF_16_BIT				   0x00000100
#define PRF_32_BIT                 0x00000200
/****************************************************************/
#endif
