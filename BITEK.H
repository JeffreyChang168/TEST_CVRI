/*  ***********************************************************************

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

    Module: BITEK.H - BITEKbus.

    Purpose: Interface of BITEK module.

    Version: 0.01                                   04:29PM  2013/03/18

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 04:29PM  2013/03/18 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   *********************************************************************** */

#ifndef _BITEK_H_
#define _BITEK_H_


/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "common.h"


/* ------------------------------------
    Macro Definition
   ------------------------------------ */
#undef  EXTERN

#ifdef  _BITEK_C_
    #define EXTERN
#else
    #define EXTERN extern
#endif


#define BITEK_REGS_RAM      ((UB8 volatile xdata *) 0x0000)


#define BITEK_INIT          OFF

#define BITEK_RX_BYTE       OFF

#define BITEK_SET_ACK       OFF

#define BITEK_TX_BURST      ON
#define BITEK_TX_BYTE       OFF
#define BITEK_TX_REPEAT     ON


/* ::::::::::::::::::::::::::::::::::::
    BITEK Configuration
   :::::::::::::::::::::::::::::::::::: */

#define BITEK_RxByte(wREG)                      \
    BITEK_REGS_RAM[ wREG ]

#define BITEK_TxByte(wREG, bDATA)               \
        BITEK_REGS_RAM[ wREG ] = bDATA


#ifdef NOT_JUNK
#define BITEK_RxBurst(bSLA, wREG, wCNT, pbDATA)  \
    I2C_RxBurst((bSLA) | (((wREG) >> 7) & 0x1E), (wREG), (wCNT), (pbDATA))


#define BITEK_RxWord(bSLA, wREG)                 \
    I2C_RxWord((bSLA) | (((wREG) >> 7) & 0x1E), (wREG))


#define BITEK_TxWord(bSLA, wREG, wDATA)                 \
    I2C_TxWord((bSLA) | (((wREG) >> 7) & 0x1E), (wREG), (wDATA))
#endif



/* ------------------------------------
    Type Definitions
   ------------------------------------ */

/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */

/* ------------------------------------
    Function Prototypes
   ------------------------------------ */
#if (BITEK_INIT)
void BITEK_Init(void);
#endif

#if (BITEK_RX_BYTE)
UB8  BITEK_RxByte(UW16 wREG);
#endif

#if (BITEK_TX_BYTE)
void BITEK_TxByte(UW16 wREG, UB8 bDATA);
#endif

#if (BITEK_TX_BURST)
void BITEK_TxBurst(UW16 wREG, UB8 bCNT, UB8 CODE *pbDATA);
#endif

#if (BITEK_TX_REPEAT)
void BITEK_TxRepeat(UW16 wREG, UB8 bCNT, UB8 bDATA);
#endif


#endif /* _BITEK_H_ */



/* **********************************************************************

    Description:

   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
