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

    Module: MAIN.C -

    Purpose: Implementation of MAIN module.

    Version: 0.02                                   06:45PM  2013/04/12

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 04:31PM  2013/03/18 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ----------------------------------------------------------------------
    v0.02 06:15PM  2013/04/12 Jeffrey Chang
    Reason:
        1. To revise for BIT1629B_HB070AM18512A_20130412_02.bin.
    Solution:

    ********************************************************************** */

#define _MAIN_C_


/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bit1618c.h"
#include "bitek.h"
#include "main.h"
#include "mcu.h"
#include "osd.h"
#include "por.h"
#include "saradc.h"
#include "timer.h"
#include "vp.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
// VID1124-110-174 + HSD HB070AM18512A 7" (800 (H) x RGB x 480 (V))
//; //////////////////////////////////////////////////////////////////////////////
//;24C16 = 07h,24C32 = 87h        OVER 400KHz
//;24C16 = 08h,24C32 = 88h
#define SPEED_24C16     0x08
#define SPEED_24C32     0x88
#define EEPROM_SPEED    SPEED_24C32

#define VERSION_DATE        __DATE2__
#define VERSION_TIME        __TIME__
#define VERSION_CODE        "v0.02"
#define VERSION_MESSAGE     "BIT1618C CVRINT" VERSION_CODE

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
    Name: DISPATCH_Task_BL_CNT -
    Purpose: To execute DISPATCH Task of BL.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void DISPATCH_Task_BL_CNT (void)
{
    UB8 CODE abDate[] =
    {
        VERSION_TIME " " VERSION_DATE
	};

    UB8 CODE abVersion[] =
    {
        VERSION_MESSAGE
    };


    BITEK_TxRepeat(VP_SHOW_OSD2, OSD2_AREA, FONT_20_BLANK);

    // Show DATE string
    BITEK_TxBurst(VP_SHOW_DATE, sizeof(abDate) - 1, abDate);

    // Show VERSION string
    BITEK_TxBurst(VP_SHOW_VERSION, sizeof(abVersion) - 1, abVersion);

    BITEK_TxByte(BITEK_12D_OSD2_ATTR2, OSD2_ON);

    bOSD_Cnt = OSD_AUTO_START;

    // BL ON
    MCU_BL_ON;
} /* DISPATCH_Task_BL_CNT */


/* -------------------------------------------------------------------
    Name: main -
    Purpose:
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void main (void)
{
    /* Power-On Reset */
    POR_Init();


    for (;;)
    {
        #ifdef FOR_DEBUG
        if (fTIMER0_Task)
        {
            OSD_ShowValue(VP_SHOW_TIMER0, wTIMER0_TickCnt, 10000, ' ');
            fTIMER0_Task = FALSE;
        }

        OSD_ShowValue(VP_SHOW_TIMER1, bOSD_Cnt, 10000, ' ');
        if (fTIMER1_Task)
        {
            OSD_ShowValue(VP_SHOW_TIMER1, wTIMER1_TickCnt, 10000, ' ');
            fTIMER1_Task = FALSE;
        }

        if (fTIMER2_Task)
        {
            OSD_ShowValue(VP_SHOW_TIMER2, wTIMER2_TickCnt, 10000, ' ');
            fTIMER2_Task = FALSE;
        }

        #endif


        #if (DEBUG_MCU)
        OSD_ShowHex(VP_SHOW_DEBUG0 + 5, bMCU_INT0_Cnt);
        OSD_ShowHex(VP_SHOW_DEBUG1 + 5, bMCU_INT1_Cnt);
        OSD_ShowHex(VP_SHOW_DEBUG2 + 5, BITEK_RxByte(BITEK_1E5_VD_INFO_O));
        OSD_ShowHex(VP_SHOW_DEBUG3 + 5, BITEK_RxByte(BITEK_1E6_STD_INFO_O));
        OSD_ShowValue(VP_SHOW_TIMER0, bVD_STD_Cnt, 10000, ' ');

        BITEK_TxByte(BITEK_11D_OSD1_ATTR2, OSD1_ON);
        #endif


        if (bMCU_BL_Cnt)
        {
            if (bMCU_BL_Cnt <= BL_STOP)
            {
                DISPATCH_Task_BL_CNT();

                bMCU_BL_Cnt = 0;
            }
        }

        if (bVD_STD_Cnt)
        {
            if (bVD_STD_Cnt <= STD_STOP)
            {
                VP_STD_Detect();

                bVD_STD_Cnt = 0;
            }
        }

        if (bOSD_Cnt)
        {
            if (bOSD_Cnt <= OSD_AUTO_STOP)
            {
                BITEK_TxByte(BITEK_10D_OSD0_ATTR2, OSD0_OFF);
                BITEK_TxByte(BITEK_12D_OSD2_ATTR2, OSD2_OFF);

                bOSD_Cnt = 0;
            }
        }


        /* ....................................
            SARADC module
            .................................... */
        if (fSARADC_VR_Task)
        {
            SARADC_VR_Task();

            fSARADC_VR_Task = FALSE;
        }

    } /* for endless loop */
} /* main */


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
