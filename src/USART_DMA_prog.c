/************************************************************/
/* AUTHOR      : Omar Sameh Mahmoud                         */
/* DESCRIPTION : USART_DMA_Prog.c                           */
/* DATE        : 27 Jan 2020                                */
/************************************************************/
#include "STD_Types.h"
#include "UART_DMA_int.h"
#include "RCC_int.h"
#include "DIO_int.h"
#include "Systick_int.h"
#include "Flash_Int.h"

/*Length of Our Message*/
#define MAX_BUFFER_LENGTH                     ((u32) 9u)

/*Our Receive Buffer*/
volatile u8 RxDMABuffer[MAX_BUFFER_LENGTH];

/*Our Flash State*/
static FLASH_StateType currentState = FLASH_IDLE;

/*Transmitting Message*/
static char hello[] = "Welcome to Flash Controller Bootloader!";
static char select_cmd[] = "Select command from the following: ";
static char lock[] = "1: Flash Lock";
static char unlock[] = "2: Flash Unlock";
static char write_data[] = "3: Write Data";
static char read_data[] = "4: Read Data";
static char Page_erase[] = "5: Page Erase";
static char Mass_erase[] = "6: Mass Erase";
static char jump[] = "7: Direct Jump";
static char line[] = "**********************************************";

static char Success_lock[] = "Flash Lock Successfully Done";
static char Success_Unlock[] = "Flash UnLock Successfully";

static char NACK[] = "NACK";

/*Our String Transmitter*/
static void strTransmit(const char * str, u8 size);

/*************************************************************/
/* Description : This Func used to Our String Transmitter    */
/*************************************************************/
static void strTransmit(const char * str, u8 size) {
	/* Check null pointers */
	if (NULL != str) {
		/* Wait until DMA_Channel4 is disabled */
		while (GET_BIT(DMA->CCR4, DMA1_Channel4_Enable) == 1) {
			CLR_BIT(DMA->CCR4, DMA1_Channel4_Enable);
			/* Do nothing, the enable flag shall reset
			 * when DMA transfer complete */
		}
		/* Set memory address */
		DMA->CMAR4 = (u32) str;

		/* Set number of data items */
		DMA->CNDTR4 = size;

		SET_BIT(DMA->CCR4, DMA1_Channel4_Enable);

		for (int var = 0; var < 100000; ++var) {
			if (var == 99999) {
				if (GET_BIT(DMA->ISR, TCIF4) == 1) {
					/* Clear all interrupt flags */
					CLR_BIT(DMA->IFCR, CGIF4);
					CLR_BIT(DMA->IFCR, CTCIF4);
					CLR_BIT(DMA->IFCR, CHTIF4);
					CLR_BIT(DMA->IFCR, CTEIF4);

					/* Disable channel */
					CLR_BIT(DMA->CCR4, DMA1_Channel4_Enable);
				}
			}
		}

	} else {
		/* Null pointers, do nothing */
	}

}

/**************************************************************************/
/* Description : This Func used to initialize usart and dma Preipheral    */
/**************************************************************************/
void USART_Init(void) {
	/* Select 1 Start bit, 9 Data bits, n Stop bit */
	SET_BIT(USART1_Reg->CR1, USART_CR1_M);

	/* Enable USART1 & Transmitter & Receiver */
	SET_BIT(USART1_Reg->CR1, USART_CR1_UE);
	SET_BIT(USART1_Reg->CR1, USART_CR1_TE);
	SET_BIT(USART1_Reg->CR1, USART_CR1_RE);

	/*Enable DMA1 Transmission & Reception */
	SET_BIT(USART1_Reg->CR3, USART_CR3_DMAT);
	SET_BIT(USART1_Reg->CR3, USART_CR3_DMAR);

	/* Select odd parity */
	SET_BIT(USART1_Reg->CR1, USART_CR1_PS);

	/* Enable Parity Control */
	SET_BIT(USART1_Reg->CR1, USART_CR1_PCE);

	/* Select one stop bit */
	CLR_BIT(USART1_Reg->CR2, USART_CR2_STOP_0);
	CLR_BIT(USART1_Reg->CR2, USART_CR2_STOP_1);

	CLR_BIT(DMA->IFCR, CGIF5);
	CLR_BIT(DMA->IFCR, CTCIF5);
	CLR_BIT(DMA->IFCR, CHTIF5);
	CLR_BIT(DMA->IFCR, CTEIF5);

	/* Select our Baud rate 9600 */
	USART1_Reg->BRR = 0x341;

}

/*************************************************************/
/* Description : This Func used to USART_DMA Transmitter    */
/*************************************************************/
void USART_DMA_TX(void) {
	/*Wait Until TXE Flag become Not Equal to Zero*/
	while ((USART1_Reg->SR | (1 << USART_TXE)) == 0)
		;
	/* Set memory size */
	DMA->CCR4 |= MEMSIZE_Type;
	/* set peripheral Size */
	DMA->CCR4 |= PREFSIZE_Type;
	/* Configuration of DMA_Channel_4_USART_TX */
	DMA->CCR4 = DMA_Channel4_Configuration;
	/* set peripheral address */
	DMA->CPAR4 = (u32) (&(USART1_Reg->DR));
	CLR_BIT(USART1_Reg->SR, USART_SR_TC);

}
/*************************************************************/
/* Description : This Func used to USART_DMA Receiver        */
/*************************************************************/
void USART_DMA_RX(void) {
	/* Wait Until RXNE Flag Not Equal to Zero*/
	while ((USART1_Reg->SR | (1 << USART_RXNE)) == 0)
		;
	/* set peripheral address */
	DMA->CPAR5 = (u32) &(USART1_Reg->DR);
	/* set memory address */
	DMA->CMAR5 |= (u32) &RxDMABuffer;
	/* set transfered data count */
	DMA->CNDTR5 = 9;
	/* Set memory size */
	DMA->CCR5 |= MEMSIZE_Type;
	/* set peripheral Size */
	DMA->CCR5 |= PREFSIZE_Type;
	/* Configuration of DMA_Channel_5_USART_RX */
	DMA->CCR5 = DMA_Channel5_Configuration;
	/* enable channel */
	DMA->CCR5 |= 0x00000001;

}

/*************************************************************/
/* Description : This Func used to USART_DMA RX TEST         */
/*************************************************************/
void DMA_USART_RX_Test(void) {
	u32 address = 0;
	u32 data = 0;
	u32 val = 0;
	u32 tmp = 0;
	switch (RxDMABuffer[0]) {
	case 1:/* Flash Lock */
		/* Write lock bit */
		SET_BIT(FLASH_CR, FLASH_CR_LOCK);
		strTransmit(Success_lock, sizeof(Success_lock));
		break;
	case 2:/* Flash Unlock */
		/* Write KEY1 */
		FLASH_KEYR = FLASH_KEY1;
		/* Write KEY2 */
		FLASH_KEYR = FLASH_KEY2;
		strTransmit(Success_Unlock, sizeof(Success_Unlock));
		break;
	case 3:/* Write Data */
		/* Check if flash is Locked*/
		if (FLASH_CR_LOCK == 1) {
			/*Unlock Flash Memory*/
			Flash_Unlock();
		} else {
			/*Wait for last operation */
			while ((GET_BIT(FLASH_SR, FLASH_SR_BSY)) != 0)
				;
			/* Enable flash programming */
			SET_BIT(FLASH_CR, FLASH_CR_PG);

			/* Write data into flash */
			address = *(u16 *) &RxDMABuffer[1];
		}
			 for(u32 idx = 0; idx < 4; ++idx)
			 {
			data = *(u16 *) &RxDMABuffer[5+ (idx * 4)];
			*(volatile u16*) (address) = data;

			  address += 4;

		//proceed to program the new second half word

		/*Wait for last operation */
		while ((GET_BIT(FLASH_SR, FLASH_SR_BSY)) != 0)
			;
			 }

		break;
	case 4:
		/* Read Data */
		address = *(u16 *) &RxDMABuffer[1];
		val = *(u16 *) address;
		strTransmit((char *) &val, sizeof(val));
		break;
	case 5:
		/* Page Erase */
		/* Check if flash is Locked*/
		if (FLASH_CR_LOCK == 1) {
			/*Unlock Flash Memory*/
			Flash_Unlock();
		} else {
			/*Wait for last operation */
			while ((GET_BIT(FLASH_SR, FLASH_SR_BSY)) != 0)
				;
			/* Enable Page erase */
			SET_BIT(FLASH_CR, FLASH_CR_PER);
			/*Write Address of page*/
			address = *(u32 *) &RxDMABuffer[1];
			FLASH_AR = address;
			/* Start Page erase */
			SET_BIT(FLASH_CR, FLASH_CR_STRT);
		}
		/*Wait for last operation */
		while ((GET_BIT(FLASH_SR, FLASH_SR_BSY)) != 0)
			;
		/*Disable Page Erase*/
		CLR_BIT(FLASH_CR, FLASH_CR_PER);
		break;
	case 6:
		/* Mass Erase */
		/* Check if flash is Locked*/
		if (FLASH_CR_LOCK == 1) {
			/*Unlock Flash Memory*/
			Flash_Unlock();
		} else {
			/*Wait for last operation */
			while ((GET_BIT(FLASH_SR, FLASH_SR_BSY)) != 0)
				;
			/* Enable Mass erase */
			SET_BIT(FLASH_CR, FLASH_CR_MER);
			/* Start Mass erase */
			SET_BIT(FLASH_CR, FLASH_CR_STRT);
		}
		/*Wait for last operation */
		while ((GET_BIT(FLASH_SR, FLASH_SR_BSY)) != 0)
			;
		/* Disable Mass erase */
		CLR_BIT(FLASH_CR, FLASH_CR_MER);
		break;
	case 7:/* Direct Jump */

		/* Get jump address */
		address = *(u16 *) &RxDMABuffer[1];
		val = *(u16 *) address;
		/* Check if it has valid stack pointer in the RAM */
		if (0x20000000 == (val & 0x20000000)) {

			/* Disable all interrupts */
			asm("MOV R0,#1");
			asm("MSR PRIMASK,R0");

			/* Reset GPIOA and USART1 */
			RCC_APB2RSTR |= (1 << USART1_RST);

			/* Release reset */
			RCC_APB2RSTR = 0;
			RCC_APB1RSTR = 0;

			/* Reset RCC */
			/* Set HSION bit to the reset value */
			SET_BIT(RCC_CR, RCC_HSI_ON);

			/* Wait till HSI is ready */
			while (!(RCC_CR & (1 << RCC_HSI_RDY)))
				;

			/* Reset CFGR register */
			RCC_CFGR = 0;

			/* Wait till clock switch is ready and
			 * HSI oscillator selected as system clock */
			while (0 != (RCC_CFGR_SWS & RCC_CFGR)) {
				/* Waiting */
			}

			/* Clear HSEON, HSEBYP and CSSON bits */
			CLR_BIT(RCC_CR, RCC_HSE_ON);
			CLR_BIT(RCC_CR, RCC_HSE_BYP);
			CLR_BIT(RCC_CR, RCC_CSS_ON);

			/* Wait till HSE is disabled */
			while (0 != (RCC_HSE_RDY & RCC_CR)) {
				/* Waiting */
			}

			/* Clear PLLON bit */
			CLR_BIT(RCC_CR, RCC_PLL_ON);

			/* Wait till PLL is disabled */
			while (0 != (RCC_PLL_RDY & RCC_CR)) {
				/* Waiting */
			}

			/* Reset SysTick */
			Systick_Load = 0;
			Systick_Value = 0;
			Systick_CSR = 0;

			/* Set jump to the reset handler */
			void (*jump_address)(void) = (void *)(*((u32 *)(address + 4)));

			/* Jump */
			jump_address();

		} else {
			/* No valid stack pointer */
			strTransmit(NACK, sizeof(NACK));
		}
		break;
	default:
		break;
	}
}

/*************************************************************/
/* Description : This Func used to Our IRQ DMA Receiver      */
/*************************************************************/
void DMA1_Channel5_IRQHandler(void) {
	/* Check transfer complete flag */
	if (GET_BIT(DMA->ISR, TCIF5) == 1) {
		CLR_BIT(DMA->IFCR, CGIF5);
		CLR_BIT(DMA->IFCR, CTCIF5);
		CLR_BIT(DMA->IFCR, CHTIF5);
		CLR_BIT(DMA->IFCR, CTEIF5);
		DMA_USART_RX_Test();
	} else {

	}
}

/*************************************************************/
/* Description : This Func used to Our IRQ DMA Transmitter   */
/*************************************************************/
void DMA1_Channel4_IRQHandler(void) {
	/* Check transfer complete flag */
	if (GET_BIT(DMA->ISR, TCIF4) == 1) {
		/* Clear all interrupt flags */
		CLR_BIT(DMA->IFCR, CGIF4);
		CLR_BIT(DMA->IFCR, CTCIF4);
		CLR_BIT(DMA->IFCR, CHTIF4);
		CLR_BIT(DMA->IFCR, CTEIF4);
	}

	else {
		/* Do nothing, this interrupt is not handled */
	}
}

/*Our Start Code*/
void Start(void) {
	/* Check current USART state */
	switch (currentState) {
	case FLASH_IDLE:
		USART_DMA_TX();
		/* Transmit data */
		strTransmit(line, sizeof(line));
		strTransmit(hello, sizeof(hello));
		strTransmit(select_cmd, sizeof(select_cmd));
		strTransmit(line, sizeof(line));
		strTransmit(lock, sizeof(lock));
		strTransmit(unlock, sizeof(unlock));
		strTransmit(write_data, sizeof(write_data));
		strTransmit(read_data, sizeof(read_data));
		strTransmit(Page_erase, sizeof(Page_erase));
		strTransmit(Mass_erase, sizeof(Mass_erase));
		strTransmit(jump, sizeof(jump));
		strTransmit(line, sizeof(line));
		/* Go to next state */
		currentState = FLASH_WAIT_FOR_CMD;
		break;
	case FLASH_WAIT_FOR_CMD:
		USART_DMA_RX();
		/* Go to next state */
		currentState = FLASH_WAIT_FOR_CMD;
		break;
	default:
		break;
	}
}
