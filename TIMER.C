/* **********************************************************************

         Copyright (c) 2002-2013 Beyond Innovation Technology Co., Ltd

        All rights are reserved. Reproduction in whole or in parts is
    prohibited without the prior written consent of the copyright owner.

   ----------------------------------------------------------------------
    Software License Agreement

    The software supplied herewith by Beyond Innovation Technology Co., Ltd
    (the "Company") is intended and supplied to you, the Company's
    customer, for use solely and exclusively on BiTEK products.

    The software is owned by the Company and/or its supplier, and is
    protected under applicable copyright laws. All rights are reserved.
    Any use in violation of the foregoing restrictions may subject the
    user to criminal sanctions under applicable laws, as well as to
    civil liability for the breach of the terms and conditions of this
    license.

    THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
    TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
    IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

   ----------------------------------------------------------------------

    Module: TIMER.C

    Purpose: Implementation of TIMER module.

    Version: 0.01                                   07:27PM  2013/03/16

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 07:27PM  2013/03/16 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#define _TIMER_C_

/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bit1618c.h"
#include "bitek.h"
#include "mcu.h"
#include "osd.h"
#include "saradc.h"
#include "timer.h"
#include "vp.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */

/* ------------------------------------
    Type Definitions
   ------------------------------------ */


/* ------------------------------------
    Variables Definitions
   ------------------------------------ */


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */


/* -------------------------------------------------------------------
    Name: TIMER_Init - To initialize TIMER module.
    Purpose:
    Passed: None.
    Returns: None.
    Notes:

    Reference: [3]87, [3]89
   ------------------------------------------------------------------- */
void TIMER_Init (void)
{
    // [3]64, 89
    // TMODE (SFR 0x89)
    TMOD            = TMODE_SETUP;

    // Setup TIMER0/1/2/22 clock mode for COUNTER MODE only !
    BITEK_TxByte(BITEK_18A_TIMER_ATTR, TIMER_BASE);


    /* ::::::::::::::::::::::::::::::::::::
        TIMER0
       :::::::::::::::::::::::::::::::::::: */
    #if ((TMODE_TIMER0 == TIMER0_16BIT_TIMER)   ||  \
         (TMODE_TIMER0 == TIMER0_16BIT_COUNTER)         )
    // Timer Mode 1 (16-bit Timer/Counter)
    TH0 = (65535 - TIMER0_DIVIDER + 1) / 256;
    TL0 = (65535 - TIMER0_DIVIDER + 1) % 256;

    #elif ((TMODE_TIMER0 == TIMER0_8BIT_TIMER)  ||  \
           (TMODE_TIMER0 == TIMER0_8BIT_COUNTER)        )
    // Timer Mode 2 (8-bit Auto-Reload Timer/Counter)
    TH0 = 255 - TIMER0_DIVIDER + 1;
    TL0 = 255 - TIMER0_DIVIDER + 1;
    #else
        #error TIMER.C - Invalid TMODE_TIMER0 !
    #endif

    /* [3]89 Timer 0 start running */
    TR0 = TRUE;

    /* [3]87 Enable Timer 0 overflow interrupt */
    ET0 = TRUE;


    /* ::::::::::::::::::::::::::::::::::::
        TIMER1
       :::::::::::::::::::::::::::::::::::: */
    #if ((TMODE_TIMER1 == TIMER1_16BIT_TIMER)   ||  \
         (TMODE_TIMER1 == TIMER1_16BIT_COUNTER)         )
    // Timer Mode 1 (16-bit Timer/Counter)
    TH1 = (65535 - TIMER1_DIVIDER + 1) / 256;
    TL1 = (65535 - TIMER1_DIVIDER + 1) % 256;

    #elif ((TMODE_TIMER1 == TIMER1_8BIT_TIMER)  ||  \
           (TMODE_TIMER1 == TIMER1_8BIT_COUNTER)        )
    // Timer Mode 2 (8-bit Auto-Reload Timer/Counter)
    TH1 = 255 - TIMER1_DIVIDER + 1;
    TL1 = 255 - TIMER1_DIVIDER + 1;
    #else
        #error TIMER.C - Invalid TMODE_TIMER1 !
    #endif

    /* [3]89 Timer 1 start running */
    TR1 = TRUE;

    /* [3]87 Enable Timer 1 overflow interrupt */
    ET1 = TRUE;


    /* ::::::::::::::::::::::::::::::::::::
        TIMER2
       :::::::::::::::::::::::::::::::::::: */
    // Timer Mode (16-bit Timer/Counter)
    TH2     = (65535 - TIMER2_DIVIDER + 1) / 256;
    TL2     = (65535 - TIMER2_DIVIDER + 1) % 256;
    RCAP2H  = (65535 - TIMER2_DIVIDER + 1) / 256;
    RCAP2L  = (65535 - TIMER2_DIVIDER + 1) % 256;

    /* [3]89 Timer 2 start running by T2CON in MCU_SETUP_INT() */
  //TR2 = TRUE;
} /* TIMER_Init */


/* -------------------------------------------------------------------
    Name: TIMER0_ISR -
    Purpose: Timer0 Interrupt Service Routine (ISR).
    Passed: None
    Returns: None.
    Notes:

    Reference: [2]19
   ------------------------------------------------------------------- */
void TIMER0_ISR (void) interrupt 1
{
    #if ((TMODE_TIMER0 == TIMER0_16BIT_TIMER)   ||  \
         (TMODE_TIMER0 == TIMER0_16BIT_COUNTER)         )
    // Timer Mode 1 (16-bit Timer/Counter))
    TH0 = (65535 - TIMER0_DIVIDER + 1) / 256;
    TL0 = (65535 - TIMER0_DIVIDER + 1) % 256;
    #endif


    wTIMER0_TickCnt++;
    fTIMER0_Task = TRUE;
} /* TIMER0_ISR */


/* -------------------------------------------------------------------
    Name: TIMER1_ISR -
    Purpose: Timer1 Interrupt Service Routine (ISR).
    Passed: None
    Returns: None.
    Notes:

    Reference: [2]19
   ------------------------------------------------------------------- */
void TIMER1_ISR (void) interrupt 3  using 3
{
    #if ((TMODE_TIMER1 == TIMER1_16BIT_TIMER)   ||  \
         (TMODE_TIMER1 == TIMER1_16BIT_COUNTER)         )
    // Timer Mode 1 (16-bit Timer/Counter)
    TH1 = (65535 - TIMER1_DIVIDER + 1) / 256;
    TL1 = (65535 - TIMER1_DIVIDER + 1) % 256;
    #endif


    /* ....................................
       TIMER module
       .................................... */
    wTIMER1_TickCnt++;
    fTIMER1_Task = TRUE;


    /* ....................................
       bMCU_BL_Cnt
       .................................... */
    if (bMCU_BL_Cnt)
        bMCU_BL_Cnt--;

	/* ....................................
       bVD_STD_Cnt
       .................................... */
    if (bVD_STD_Cnt)
        bVD_STD_Cnt--;

    /* ....................................
       bOSD_Cnt
       .................................... */
    if (bOSD_Cnt)
        bOSD_Cnt--;


    /* ....................................
       SARADC
       .................................... */
    fSARADC_VR_Task = TRUE;



	#ifdef NOT_JUNK
    bTIMER_TickCnt++;

    /* ....................................
       KEY module
       .................................... */
    /* To scan the keypad every 16 System Ticks since
       the debounce needs 64 ms at least                */
    // Period = 16 Ticks
    if ((wTIMER_TickCnt & 0x000F) == 0)
        KEY_Scan();
    if (wTIMER_Tick)
        wTIMER_Tick--;



    /* ....................................
       DISPATCH module
       .................................... */
    if (wTIMER_BurnInTick)
        wTIMER_BurnInTick--;

    /* ....................................
       MENU module
       .................................... */
    if (wMENU_Tick)
        wMENU_Tick--;


    /* ....................................
       LED module
       .................................... */
    if (fLED_RED_Blink)
    {
        // Period = 128 Ticks
        // 50% duty cycle
        if ((wTIMER_TickCnt & 0x007F) == 0x0000)
            LED_RED_OFF;

        if ((wTIMER_TickCnt & 0x007F) == 0x0040)
            LED_RED_ON;
    }


    if (fLED_GREEN_Blink)
    {
        // Period = 128 Ticks
        // 50% duty cycle
        if ((wTIMER_TickCnt & 0x007F) == 0x0010)
            LED_GREEN_OFF;

        if ((wTIMER_TickCnt & 0x007F) == 0x0050)
            LED_GREEN_ON;
    }

    if (fLED_YELLOW_Blink)
    {
        // Period = 128 Ticks
        // 50% duty cycle
        if ((wTIMER_TickCnt & 0x007F) == 0x0020)
            LED_YELLOW_OFF;

        if ((wTIMER_TickCnt & 0x007F) == 0x0060)
            LED_YELLOW_ON;
    }
    #endif

} /* TIMER1_ISR */


/* -------------------------------------------------------------------
    Name: TIMER2_ISR -
    Purpose: Timer2 Interrupt Service Routine (ISR).
    Passed: None
    Returns: None.
    Notes:

    Reference: [2]19
   ------------------------------------------------------------------- */
void TIMER2_ISR (void) interrupt 5
{
    TF2 = 0;
  //T2CON   = SFR_T2CON;

	// Timer Mode: 16-bit Auto-Reload Timer/Counter
    // Nothing to do !

    wTIMER2_TickCnt++;
    fTIMER2_Task = TRUE;
} /* TIMER2_ISR */



#if (TIMER_DELAYMS)
/* -------------------------------------------------------------------
    Name: TIMER_DelayMS -
    Purpose: To wait a moment in milli-seconds.
    Passed:
        wMS = 1..65530                  @ System tick = 6ms

        Delay duration = 1 Tick         @ wMS = 1
                       = 6 ms           @ wMS = 1
        Delay duration = 10922 Ticks    @ wMS = 65530
                       = 65532 ms       @ wMS = 65530

    Returns: None.
    Notes:
    Reference: [2]19
   ------------------------------------------------------------------- */
void TIMER_DelayMS (UW16 wMS)
{
    TIMER_RUN   = FALSE;

    wTIMER_Tick = (wMS + MS_PER_TICK - 1) / MS_PER_TICK;

    TIMER_RUN   = TRUE;

    while (wTIMER_Tick)        
        ;                      
} /* TIMER_DelayMS */
#endif


/* -------------------------------------------------------------------
    Name:  -
    Purpose: .
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */


/* **********************************************************************

    Description:


   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
