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

    Module: OSD.C

    Purpose: Implementation of OSD module.

    Version: 0.01                                   06:50PM  2013/03/20

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 06:50PM  2013/03/20 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */


#define _OSD_C_

/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bit1618c.h"
#include "bitek.h"
#include "osd.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */



#if (PROGRESS_BAR == PROGRESS_TV)
    // PROGRESS_TV
    #define FONT_EMPTY      FONT_00_DASH_0
    #define FONT_FULL       FONT_03_DASH_3
    #define BAR_WIDTH       20
    #define BAR_STEP        3              // The bar has 3 steps.
#elif (PROGRESS_BAR == PROGRESS_PC)
    // PROGRESS_PC
    #define FONT_EMPTY      FONT_10_BAR_0
    #define FONT_FULL       FONT_16_BAR_6
    #define BAR_WIDTH       17             //
    #define BAR_STEP        6              // The bar has 6 steps.
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


/* -------------------------------------------------------------------
    Name: OSD_Init -
    Purpose: To initialize OSD module.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void OSD_Init (void)
{
    fOSD_Vanish = FALSE;


    // OSD must be OFF during accessing OSDPAT RAM !

    // OSDPAT_BANK_SEL (0x12E) = BANK0, OSDPAT_R
    BITEK_TxByte(BITEK_12E_OSDPAT_ATTR, BITEK_MASK_OSDPAT_R);
    // Setup Palette R !
    BITEK_TxBurst(BITEK_300_3FF_OSDPAT, sizeof(abOSD_PALETTE_R), abOSD_PALETTE_R);

    // OSDPAT_BANK_SEL (0x12E) = BANK0, OSDPAT_G
    BITEK_TxByte(BITEK_12E_OSDPAT_ATTR, BITEK_MASK_OSDPAT_G);
    // Setup Palette G !
    BITEK_TxBurst(BITEK_300_3FF_OSDPAT, sizeof(abOSD_PALETTE_G), abOSD_PALETTE_G);

    // OSDPAT_BANK_SEL (0x12E) = BANK0, OSDPAT_B
    BITEK_TxByte(BITEK_12E_OSDPAT_ATTR, BITEK_MASK_OSDPAT_B);
    // Setup Palette B !
    BITEK_TxBurst(BITEK_300_3FF_OSDPAT, sizeof(abOSD_PALETTE_B), abOSD_PALETTE_B);

    // OSDPAT_BANK_SEL (0x12E) = BANK0, OSDPAT_A
    BITEK_TxByte(BITEK_12E_OSDPAT_ATTR, BITEK_MASK_OSDPAT_A);
    // Setup Palette ATTRIBUTE !
    BITEK_TxBurst(BITEK_300_3FF_OSDPAT, sizeof(abOSD_PALETTE_A), abOSD_PALETTE_A);


    // OSD_BANK_SEL (0x12F) = BANK0
    BITEK_TxByte(BITEK_12F_OSD_ATTR, BITEK_MASK_OSD_BANK0);

	// OSD Code
    BITEK_TxRepeat(VP_SHOW_OSD0, OSD0_AREA, ' ');
    BITEK_TxRepeat(VP_SHOW_OSD1, OSD1_AREA, ' ');
    BITEK_TxRepeat(VP_SHOW_OSD2, OSD2_AREA, ' ');


    // OSD Attr
    BITEK_TxRepeat(VP_ATTR_OSD0, OSD0_AREA, OSD0_NM_ATTR);
    BITEK_TxRepeat(VP_ATTR_OSD1, OSD1_AREA, OSD1_NM_ATTR);
    BITEK_TxRepeat(VP_ATTR_OSD2, OSD2_AREA, OSD2_NM_ATTR);

    // Setup OSD0
    BITEK_TxBurst(BITEK_100105_OSD0_X, sizeof(abOSD0_Setup), abOSD0_Setup);

    // Setup OSD1
    BITEK_TxBurst(BITEK_110115_OSD1_X, sizeof(abOSD1_Setup), abOSD1_Setup);

    // Setup OSD2
    BITEK_TxBurst(BITEK_120125_OSD2_X, sizeof(abOSD2_Setup), abOSD2_Setup);
} /* OSD_Init */



#if (OSD_SHOW_HEX)
/* -------------------------------------------------------------------
    Name: OSD_ShowHex -
    Purpose: To show one byte value in hexadecimal format at
        specified position of OSD window.
    Passed:
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void OSD_ShowHex (
UW16 wREG,          /* BITEK register address */
UB8  bDATA          /* DATA item (0..255) */
)
{

    //////////////////////////////////////////////////////////////////
    // High Nibble
    bByte = bDATA / 16;
    if (bByte < 10)
        bByte += '0';
    else
        bByte = (bByte - 10) + 'A';

    BITEK_TxByte(wREG, bByte);
    wREG++;

    // Low Nibble
    bByte = bDATA % 16;
    if (bByte < 10)
        bByte += '0';
    else
        bByte = (bByte - 10) + 'A';

    BITEK_TxByte(wREG, bByte);
    //////////////////////////////////////////////////////////////////

} /* OSD_ShowHex */
#endif


#if (OSD_SHOW_PROGRESS_BAR)
/* -------------------------------------------------------------------
    Name: OSD_ShowProgressBar -
    Purpose: To display a progress bar at specified position in OSD window.
    Passed:
        UW16 wREG   = BITEK Register address.
        UB8  bDATA  = One word transmitted data.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void OSD_ShowProgressBar (
UW16 wREG,          /* BITEK register address */
UB8  bDATA          /* DATA value */
)
{
#if (PROGRESS_BAR == PROGRESS_TV)


    //////////////////////////////////////////////////////////////////
  //bDATA *= 2;     // 0..60

    for (bByte = BAR_WIDTH; bByte; bByte--)
    {
        if (bDATA >= BAR_STEP)
        {
            BITEK_TxByte(wREG, FONT_FULL);

            bDATA -= BAR_STEP;
        }
        else
        {
            BITEK_TxByte(wREG, bDATA + FONT_EMPTY);

            bDATA = 0;
        }

        wREG++;
    }
    //////////////////////////////////////////////////////////////////


#elif (PROGRESS_BAR == PROGRESS_PC)


	//////////////////////////////////////////////////////////////////
  //bDATA *= 4;     // 0..120

    BITEK_TxByte(wREG, FONT_5B_BAR_LEFT);
    wREG++;

    if (bDATA)
        bDATA += 2;

    for (bByte = BAR_WIDTH; bByte; bByte--)
    {
        if (bDATA >= BAR_STEP)
        {
            BITEK_TxByte(wREG, FONT_FULL);

            bDATA -= BAR_STEP;
        }
        else
        {
            BITEK_TxByte(wREG, bDATA + FONT_EMPTY);

            bDATA = 0;
        }

        wREG++;
    }

    BITEK_TxByte(wREG, FONT_5D_BAR_RIGHT);
    //////////////////////////////////////////////////////////////////

#endif
} /* OSD_ShowProgressBar */
#endif



#if (OSD_SHOW_VALUE)
/* -------------------------------------------------------------------
    Name: OSD_ShowValue -
    Purpose: To show 16-bit word (5-digit).
    Passed:
        UW16    wREG   = BITEK Register address.
        UUW16   wDATA  = One word transmitted data (0..65535).
        UUW16   wMask  = 10000 (5-digit), 1000 (4-digit)
    Returns: None.
    Notes:
        1) wDATA <= 9 * wMask
        12345 OK
         1234
          123
           12
            1
            0 OK
          105
   ------------------------------------------------------------------- */
void OSD_ShowValue (
UW16 wREG,              /* BITEK register address */
UW16 wDATA,             /* DATA item */
UW16 wMask,
UB8  bBlank             // '0', '-' or ' '
)
{
    #if 0
    if (bBlank == '0')
        fLeading = TRUE;
    else
        fLeading = FALSE;       // ' ' or '-'


    for (wWord = wMask; wWord; wWord /= 10)
    {
        bByte = wDATA / wWord;

        if (fLeading        ||
            bByte           ||
		    (wWord == 1)         )
        {
            bByte += '0';
            fLeading = TRUE;
        }
        else
        {
            bByte = bBlank;
        }


        BITEK_TxByte(wREG, bByte);
        wREG++;

        wDATA %= wWord;
    }
    #endif

    for (wWord = wMask; wWord; wWord /= 10)
    {
        bByte = wDATA / wWord;

        if ((bBlank == '0') ||
            bByte           ||
		    (wWord == 1)         )
        {
            bByte += '0';
            bBlank = '0';
        }
        else
        {
            bByte = bBlank;
        }


        BITEK_TxByte(wREG, bByte);
        wREG++;

        wDATA %= wWord;
    }
} /* OSD_ShowValue */
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
