/************************************************************/
/* AUTHOR      : Omar Sameh Mahmoud                         */
/* DESCRIPTION : Systick DRIVER    [Systick_reg.h]          */
/* DATE        : 17 August 2019                             */
/************************************************************/
#ifndef SYSTICK_REG_H
#define SYSTICK_REG_H

#define Systick_CSR		*((u32*)0xE000E010)
#define Systick_Load	*((u32*)0xE000E014)
#define Systick_Value 	*((u32*)0xE000E018)

#endif
