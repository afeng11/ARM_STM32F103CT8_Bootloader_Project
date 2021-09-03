/************************************************************/
/* AUTHOR      : Omar Sameh Mahmoud                         */
/* DESCRIPTION : Systick DRIVER    [Systick_reg.h]          */
/* DATE        : 17 August 2019                             */
/************************************************************/
#ifndef _SYSTICK_INT_H
#define _SYSTICK_INT_H

void Systick_Init (u32 load);

void _delay_ms(u32 time);

#include "Systick_reg.h"

#endif
