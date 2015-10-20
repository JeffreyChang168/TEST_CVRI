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

    Module: BITEK.C - BITEK.

    Purpose: Implementation of BITEK module.

    Version: 0.01                                   04:28PM  2013/03/18

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 04:28PM  2013/03/18 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */


#define _BITEK_C_


/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bitek.h"
#include "common.h"

#define SFR_IDA     0x94

/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#define BITEK_ASM   0

#if (BITEK_ASM)
#pragma SRC
#endif


/* ------------------------------------
    Type Definitions
   ------------------------------------ */


/* ------------------------------------
    Variables Definitions
   ------------------------------------ */

/* ------------------------------------
    Function Prototypes
   ------------------------------------ */


#if (BITEK_INIT)
/* -------------------------------------------------------------------
    Name: BITEK_Init -
    Purpose: To initialize the BITEK module.
    Passed: None.
    Returns: None.
    Notes:
  ------------------------------------------------------------------- */
void BITEK_Init (void)
{
} /* BITEK_Init */
#endif



#if (BITEK_RX_BYTE)
/* -------------------------------------------------------------------
    Name: BITEK_RxByte -
    Purpose: To receive one byte data from BiTEKbus slave device.
    Passed:
        UB8     bSLA    = BITEK slave address.
        UW16    wREG    = BITEK register address.
    Returns: One byte received data.
    Notes:
   ------------------------------------------------------------------- */
UB8 BITEK_RxByte (UW16 wREG)           /* BITEK register address */
{
    return( BITEK_REGS_RAM[ wREG ] );
} /* BITEK_RxByte */
#endif


#if (BITEK_TX_BURST)
/* -------------------------------------------------------------------
    Name: BITEK_TxBurst -
    Purpose: To transmit bulk data to BiTEK registers.
    Passed:
        UW16 wREG       = starting register address
        UB8  bCNT       = The number of data which will be transmitted (0..255)
        UB8  *pbDATA    = The pointer which points to the first data item.
            excluding slave and register address (wCNT: 1..65535).
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void BITEK_TxBurst (
UW16        wREG,          /* BITEK starting register address */
UB8         bCNT,          /* The number of data which will be transmitted */
UB8 CODE    *pbDATA        /* Point to the first DATA item */
)
{
#if (BITEK_ASM)

        #pragma asm
        MOV     A,          R6
        MOV     SFR_IDA,    A

        MOV     A,      R7
        MOV     R1,     A

        MOV     DPH,    R2
        MOV     DPL,    R3


LABEL_BITEK_TxBurst:
        CLR     A
        MOVC    A,      @A + DPTR
        MOVX    @R1,    A

        INC     DPTR
        INC     R1
        DJNZ    R5,     LABEL_BITEK_TxBurst

        #pragma endasm
#else

    //////////////////////////////////////////////////////////////////
    // CODE SIZE: 0x2F
    for (; bCNT; bCNT--)
    {
        BITEK_REGS_RAM[ wREG++ ] = *pbDATA++;
    }
    //////////////////////////////////////////////////////////////////

#endif

} /* BITEK_TxBurst */
#endif


#if (BITEK_TX_REPEAT)
/* -------------------------------------------------------------------
    Name: BITEK_TxRepeat -
    Purpose: To transmit the same data to BiTEKbus slave device repeatly.
    Passed:
        UW16 wREG   = BiTEKbus register address.
        UB8  bCNT   = The number of data which will be transmitted (0..255)
        UB8  bDATA  = The repeated data.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void BITEK_TxRepeat (
UW16 wREG,          /* BITEK register address */
UB8  bCNT,          /* The number of data which will be transmitted */
UB8  bDATA          /* The repeated DATA */
)
{
#if (BITEK_ASM)

        #pragma asm
        MOV     DPH,    R6
        MOV     DPL,    R7

        MOV     A,      R3

LABEL_BITEK_TxRepeat:
        MOVX    @DPTR,  A
        INC     DPTR
        DJNZ    R5,     LABEL_BITEK_TxRepeat

        #pragma endasm
#else

    //////////////////////////////////////////////////////////////////
    // CODE SIZE: 0x1F
    while (bCNT--)
        BITEK_REGS_RAM[ wREG++ ] = bDATA;
    //////////////////////////////////////////////////////////////////

#endif

} /* BITEK_TxRepeat */
#endif // BITEK_TX_REPEAT


#if (BITEK_TX_BYTE)
/* -------------------------------------------------------------------
    Name: BITEK_TxByte -
    Purpose: To transmit one word data to BiTEKbus slave device.
    Passed:
        UB8  bSLA   = BiTEKbus slave address.
        UW16 wREG   = BiTEKbus register address.
        UB8  bDATA  = One word transmitted data.
    Returns: None.
    Notes: To send LSB first and then MSB.
   ------------------------------------------------------------------- */
void BITEK_TxByte (
UW16 wREG,          /* BITEK register address */
UB8  bDATA          /* DATA item */
)
{
    BITEK_REGS_RAM[ wREG ] = bDATA;
} /* BITEK_TxByte */
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

