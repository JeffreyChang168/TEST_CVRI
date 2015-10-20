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

    Module: MCU.C

    Purpose: Implementation of MCU.

    Version: 0.01                                   07:26PM  2013/03/16

    Compiler: Keil 8051 C Compiler v9.51

    Reference:
    [1] BIT5101 8051 MICROCONTROLLER WITH 64K FLASH AND ISP Version 0.01,
        2004/10/25, Beyond Innovation Technology
    [2] TP2804  8051 MICROCONTROLLER WITH 64K FLASH AND ISP Version 1.2,
        June 2004, TOPRO
    [3] MPC89x58A 8-bit MICRO-CONTROLLER Version A9,
        2006/08, Megawin Technology Co., Ltd.

   ----------------------------------------------------------------------
    Modification:

    v0.01 07:26PM  2013/03/16 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */


#define  _MCU_C_

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
    Name: MCU_Init -
    Purpose: To initialize MCU module.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void MCU_Init (void)
{
    fVD_NoSignal    = TRUE;
    bMCU_BL_Cnt     = BL_START;
    bVD_STD_Cnt     = STD_START;
} /* MCU_Init */


/* -------------------------------------------------------------------
    Name: MCU_INT0_ISR -
    Purpose: INT0 Interrupt Service Routine (ISR).
    Passed: None
    Returns: None.
    Notes:

    Reference: [2]19
   ------------------------------------------------------------------- */
void MCU_INT0_ISR (void) interrupt 0    using 1
{
    UB8 bINT0;


    bINT0 = BITEK_RxByte(BITEK_002_INT0_FLAG_O);

    if (bINT0 & BITEK_MASK_FLAG0_VD_SIGNALREADY)
    {
        fVD_NoSignal    = FALSE;
        bVD_STD_Cnt     = STD_START;

        // R0CD[6]=1
        BITEK_TxByte(BITEK_0CD_DCLAMP_ATTR1, BITEK_RxByte(BITEK_0CD_DCLAMP_ATTR1) | BITEK_MASK_DCLAMP_STABLE_EN);
    }


    #if (SARADC_INT)
    if (bINT0 & BITEK_MASK_FLAG0_ADC)
    {
        // Check SARADC1/2/3
        bSARADC_VR_Flag = BITEK_RxByte(BITEK_1AC_SARADC_INFO) & 0x07;

        OSD_ShowHex(VP_SHOW_OSD1_ROW6 + 3, bSARADC_VR_Flag);


        #if (DEBUG_MCU)
        bMCU_INT0_Cnt++;
        #endif

    }
    #endif



    MCU_INT0_RESET();
} /* MCU_INT0_ISR */


/* -------------------------------------------------------------------
    Name: MCU_INT0_RESET -
    Purpose: To reset INT0.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void MCU_INT0_RESET (void)
{
    BITEK_TxByte(BITEK_003_INT0_MASK, 0xFF);

    // ACK SARADC
    BITEK_TxByte(BITEK_1A9_ADC_INT_ATTR, 0x07);

    // ACK KEY
  //BITEK_TxByte(BITEK_18E_KEY_ACK, 0x00);

    BITEK_TxByte(BITEK_004_INT0_ACK, 0x00);
    BITEK_TxByte(BITEK_004_INT0_ACK, INT0_ACK);

    // ACK KEY
  //BITEK_TxByte(BITEK_18E_KEY_ACK, 0xFC);

    // ACK SARADC
    BITEK_TxByte(BITEK_1A9_ADC_INT_ATTR, 0x70);

    BITEK_TxByte(BITEK_003_INT0_MASK, 0x00);
} /* MCU_INT0_RESET */


/* -------------------------------------------------------------------
    Name: MCU_INT1_ISR -
    Purpose: INT1 Interrupt Service Routine (ISR).
    Passed: None
    Returns: None.
    Notes:

    Reference: [2]19
   ------------------------------------------------------------------- */
void MCU_INT1_ISR (void) interrupt 2    using 2
{
    UB8 bINT1;


    bINT1 = BITEK_RxByte(BITEK_005_INT1_FLAG_O);

    if (bINT1 & BITEK_MASK_FLAG1_VD_NOSIGNAL)
    {
        fVD_NoSignal    = TRUE;
        bVD_STD_Cnt     = STD_START;

        // R0CD[6]=0
        BITEK_TxByte(BITEK_0CD_DCLAMP_ATTR1, BITEK_RxByte(BITEK_0CD_DCLAMP_ATTR1) & ~BITEK_MASK_DCLAMP_STABLE_EN);
    }

    if (bINT1 & BITEK_MASK_FLAG1_VD_STANDARD)
    {
        if (! fVD_NoSignal)
            bVD_STD_Cnt = STD_START;
    }

    #if (DEBUG_MCU)
    bMCU_INT1_Cnt++;
    #endif

    MCU_INT1_RESET();
} /* MCU_INT1_ISR */


/* -------------------------------------------------------------------
    Name: MCU_INT1_RESET -
    Purpose: To reset INT0.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void MCU_INT1_RESET (void)
{
    BITEK_TxByte(BITEK_006_INT1_MASK, 0xFF);


    // ACK KEY
  //BITEK_TxByte(BITEK_18E_KEY_ACK, 0x00);

    BITEK_TxByte(BITEK_007_INT1_ACK, 0x00);
    BITEK_TxByte(BITEK_007_INT1_ACK, INT1_ACK);

    // ACK KEY
  //BITEK_TxByte(BITEK_18E_KEY_ACK, 0xFC);


    BITEK_TxByte(BITEK_006_INT1_MASK, 0x00);
} /* MCU_INT1_RESET */


/* -------------------------------------------------------------------
    Name: MCU_SETUP_INT -
    Purpose: To setup interrupt.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void MCU_SETUP_INT (void)
{
    BITEK_TxByte(BITEK_008_INT_ATTR, INT_ATTR);

    MCU_INT0_RESET();
    MCU_INT1_RESET();

    IP      = SFR_IP;
    TCON    = SFR_TCON;
    T2CON   = SFR_T2CON;
    IE      = INT_ON;
} /* MCU_SETUP_INT */



/* **********************************************************************

    Description:


   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
