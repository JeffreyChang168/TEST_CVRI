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

    Module: PANEL.C -

    Purpose: Implementation of PANEL.

    Version: 0.01                                   02:49PM  2013/03/27

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 02:49PM  2013/03/27 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#define _PANEL_C_

/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bit1618c.h"
#include "bitek.h"
#include "common.h"
#include "vp.h"
#include "panel.h"


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
    Name: PANEL_Init -
    Purpose: .
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void PANEL_Init (void)
{
        UB8 CODE abDAC_1F0_1F4[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*1F */ 0x80,0x5E,0x00,0x00,0x08
    };

        UB8 CODE abDAC_1F8_1FF[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*1F */                                         0x8F,0x00,0x00,0x00,0x00,0x4B,0xFF,0x7E,
    };


    BITEK_TxBurst(BITEK_1F0_DAC_OFFSET, sizeof(abDAC_1F0_1F4), abDAC_1F0_1F4);

    // Check DAC BUSY (0x1F4[7])
    while (BITEK_RxByte(BITEK_1F4_DAC_ATTR) & BITEK_MASK_B1690_BUSY_O)
        ;

    // RESET DAC
    BITEK_TxByte(BITEK_1FE_1690_RESET, 0x00);


    {
        UB8     bIdx;
        UW16    wAddr;


        for (bIdx = 255; bIdx; bIdx--)
            ;
        for (bIdx = 255; bIdx; bIdx--)
            ;


        for (bIdx = 0; bIdx < sizeof(abDAC_1F8_1FF); bIdx++)
        {
            if (bIdx == 6)
                continue;

            // Check DAC BUSY (0x1F4[7])
            while (BITEK_RxByte(BITEK_1F4_DAC_ATTR) & BITEK_MASK_B1690_BUSY_O)
                ;

            wAddr = abDAC_1F8_1FF + bIdx;
            BITEK_TxByte(wAddr,  abDAC_1F8_1FF[ bIdx ]);
        }
    }

}



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
