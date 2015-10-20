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

    Module: POR.C - Power-On-Reset.

    Purpose: Implementation of POR module.

    Version: 0.01                                   08:19PM  2013/03/30

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 08:19PM  2013/03/30 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#define _POR_C_

/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bit1618c.h"
#include "bitek.h"
#include "mcu.h"
#include "osd.h"
#include "por.h"
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
    Name: POR_Init -
    Purpose: To initialize system power-on reset module.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void POR_Init (void)
{
    /* Initiate VP */
    VP_Init();          // To disable Watchdog Timer !


    // Note !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Keep VP_Init(); first !
    // Note !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    /* Initiate MCU */
    MCU_Init();


    /* Initiate TIMER */
    TIMER_Init();

    /* Initiate SARADC */
    SARADC_Init();

    /* Initiate PANEL */
  //PANEL_Init();

    /* Initiate OSD */
    OSD_Init();



    // Note !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Keep OSD and AOSD off !
    // Note !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // 0x00E[5]=1 (BCLK=LCLK)
  //BITEK_TxByte(BITEK_00E_CLK_ATTR4, 0x9F);

    // To setup FLASH BANK !
  //BITEK_TxByte(BITEK_010_M8051_FLASHBANK, 0x00);


    /* [4]87 Enable all interrupts */
  //EA = 1;
    MCU_SETUP_INT();
} /* POR_Init */


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
