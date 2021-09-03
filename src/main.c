/*************************************************************************/
/* AUTHOR      : Omar Sameh Mahmoud                                      */
/* DESCRIPTION :Main   [ main.c]        BootLoader_Project               */
/* DATE        : 27 January 2020                                         */
/* VERSION     : V01                                                     */
/*************************************************************************/
#include "STD_types.h"
#include "BIT_math.h"
#include "RCC_int.h"
#include "DIO_int.h"
#include "NVIC_int.h"
#include "Systick_int.h"
#include "OS_Init.h"
#include "UART_DMA_int.h"

/**************************Function Of Task (Red_Off)**********************/
void Blink_Red_Off(void) {
	DIO_SetPinValue(PORTA, PIN0, LOW);
}

/**************************Function Of Task (Red_On)***********************/
void Blink_Red_On(void) {
	DIO_SetPinValue(PORTA, PIN0, HIGH);
}

/***************************Main Function*********************************/
int main(void) {

	/*Initialization of RCC*/
	RCC_Init();

	/*Enable RCC Clock For DMA1*/
	RCC_voidEnableClock(RCC_CLK_DMA1);
	/*Enable RCC Clock For USART1*/
	RCC_voidEnableClock(RCC_USART1_EN);
	/*Enable RCC Clock For IOPA*/
	RCC_voidEnableClock(RCC_CLK_IOPA);

	/*Initialization of USART*/
	USART_Init();

	/*Initialization of NVIC*/
	myNVIC_Init();
	/*Enable DMA1_Channel5_IRQ*/
	NVIC_EnableInt(DMA1_Channel5); //DMA For USART1 Reception
	/*Enable DMA1_Channel5_IRQ*/
	NVIC_EnableInt(DMA1_Channel4); //DMA For USART1 Transmittion

	/*Initialization of DIO*/
	DIO_init();

	/* Set PIN9,PIN10 */
	DIO_SetPinValue(PORTA, PIN9, HIGH); //TX1
	DIO_SetPinValue(PORTA, PIN10, HIGH); //RX1

	/*Simple Operating System Creating*/
	OS_Init();

	/*Infinite Loop and It's Return*/
	while (1) {

	}
	return 0;
}

