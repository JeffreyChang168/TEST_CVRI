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

    Module: SARADC.C -

    Purpose: Implementation of SARADC.

    Version: 0.02                                   04:33PM  2013/03/18

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 04:33PM  2013/03/18 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ----------------------------------------------------------------------
    v0.02 10:53PM  2013/04/04 Jeffrey Chang
    Reason:
        1. To add SARADC interrupt approach.
    Solution:

   ********************************************************************** */

#define _SARADC_C_

/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bit1618c.h"
#include "bitek.h"
#include "osd.h"
#include "saradc.h"
#include "timer.h"
#include "vp.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
// OSD: 0..60
#define VR_LOW                  20
#define VR_HIGH                 200
#define VR_STEP                 3

#define VR_LOW_BOUND            255         // VR Floating condition LOW boudn
#define VR_HIGH_BOUND           221         // VR dynamic range HIGH bound
#define VR_CRITERIA             (VR_LOW_BOUND + VR_HIGH_BOUND) / 2
#define VR_FLOAT                (256 - VR_CRITERIA)
#define VR_THRESHOLD            VR_STEP     // for Hysteresis

#define VR_OSD_MIN              0
#define VR_OSD_DEFAULT          30
#define VR_OSD_MAX              60


/* ------------------------------------
    Type Definitions
   ------------------------------------ */


/* ------------------------------------
    Variables Definitions
   ------------------------------------ */
static  UB8 bVR_New;
static  UB8 abVR_Old[ SARADC_VR_SIZE ];

#if (SARADC_INT)
static  UB8 abVR_1A2[ SARADC_VR_SIZE ] =
{
    SARADC_OUT1,
    SARADC_OUT2,
    SARADC_OUT3,
};
#else
static  UB8 abVR_1A1[ SARADC_VR_SIZE ] =
{
    SARADC1_CH_VR1,
    SARADC1_CH_VR2,
    SARADC1_CH_VR3,
};
#endif

#define TITLE_WIDTH         (10)

static UB8 CODE * CODE apbTitle[] =
{
   //1234567890
    "Brightness",   // 0 MENU_BRIGHTNESS
    "Contrast  ",   // 1 MENU_CONTRAST
    "Saturation",   // 2 MENU_SATURATION
};

/* ------------------------------------
    Function Prototypes
   ------------------------------------ */
void SARADC_VR_Update(void);
UB8  SARADC_VR_Value(void);


/* -------------------------------------------------------------------
    Name: SARADC_Init -
    Purpose: To initialize SARADC module.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void SARADC_Init (void)
{
    fSARADC_VR_Task = FALSE;

    BITEK_TxByte(BITEK_1A7_ADC_ATTR,        0x02);
    BITEK_TxByte(BITEK_1A8_ADC_COMP_ATTR1,  0x02);

    // To enable SARADC
    BITEK_TxByte(BITEK_00F_SARCLK_ATTR, BITEK_RxByte(BITEK_00F_SARCLK_ATTR) | BITEK_MASK_SARCLK_EN);

    // Set speed to 200kHz
    BITEK_TxByte(BITEK_19F_SARADC_ATTR, BITEK_MASK_SARADC_REF_SEL_H |
                                        BITEK_MASK_SARADC_REF_SEL_L |
                                        BITEK_MASK_SARADC_WRB       |
                                        BITEK_MASK_SARADC_RDB       |
                                        BITEK_MASK_SARADC_LOWSPEED
                );

    #if (SARADC_IN_MODE == SARADC_IN_SINGLE)

    BITEK_TxByte(BITEK_1A1_SARADC12_SEL, SARADC_IN_MODE  | SARADC2_CH1 | SARADC1_CH1);
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT_MODE | SARADC4_CH1 | SARADC3_CH1);

    bSARADC_VR_CH   = SARADC_VR_BRIGHTNESS;

    #elif ((SARADC_IN_MODE == SARADC_IN_DUAL)   ||  \
           (SARADC_IN_MODE == SARADC_IN_TRIPLE) ||  \
           (SARADC_IN_MODE == SARADC_IN_QUAD)           )

    BITEK_TxByte(BITEK_1A1_SARADC12_SEL, SARADC_IN_MODE  | SARADC2_CH  | SARADC1_CH);
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT_MODE | SARADC4_CH  | SARADC3_CH);

    BITEK_TxByte(BITEK_1A3_SARADC_SWITCH, 0x10);     // OK 06:54PM  2013/04/29

    #endif


    #if (SARADC_INT)
    // ADC1/2/3 threshold
    BITEK_TxByte(BITEK_1A6_ADC_THD,  VR_THRESHOLD); // Delta >= VR_THRESHOLD
    BITEK_TxByte(BITEK_1A7_ADC_ATTR, 0x72);         // Loaded by Rising edge
    BITEK_TxByte(BITEK_1A7_ADC_ATTR, 0x02);

    // Clear  ADC1/2/3 flag
    BITEK_TxByte(BITEK_1A9_ADC_INT_ATTR, 0x07);
    // Enable ADC1/2/3 interrupt
    BITEK_TxByte(BITEK_1A9_ADC_INT_ATTR, 0x70);
    #endif
} /* SARADC_Init */


#if (SARADC_SCAN)
/* -------------------------------------------------------------------
    Name: SARADC_Scan -
    Purpose: SARADC process.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void SARADC_Scan (void)
{
    #if (SARADC_IN_MODE == SARADC_IN_SINGLE)
    UB8 bSARADC_New;


    bSARADC_New = BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB);

    if (bSARADC_VR_CH == SARADC1_CH1)
    {
        #if (DEBUG_SARADC)
        OSD_ShowHex(VP_SHOW_SARADC1, bSARADC_New);
        #endif

        bSARADC_VR_CH = SARADC1_CH2;
    }
    else if (bSARADC_VR_CH == SARADC1_CH2)
    {
        #if (DEBUG_SARADC)
        OSD_ShowHex(VP_SHOW_SARADC2, bSARADC_New);
        #endif

        bSARADC_VR_CH = SARADC1_CH3;
    }
    else if (bSARADC_VR_CH == SARADC1_CH3)
    {
        #if (DEBUG_SARADC)
        OSD_ShowHex(VP_SHOW_SARADC3, bSARADC_New);
        #endif

        bSARADC_VR_CH = SARADC1_CH1;
    }

    // Update SARADC1 CH !
    BITEK_TxByte(BITEK_1A1_SARADC12_SEL, SARADC_IN_MODE | SARADC2_CH1 | bSARADC_VR_CH);

    #elif (SARADC_IN_MODE == SARADC_IN_DUAL)

    // SARADC1
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT1 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC1, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif

    // SARADC2
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT2 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC2, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif

    #elif (SARADC_IN_MODE == SARADC_IN_TRIPLE)

    // SARADC1
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT1 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC1, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif

    // SARADC2
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT2 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC2, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif

    // SARADC3
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT3 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC3, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif


    #elif (SARADC_IN_MODE == SARADC_IN_QUAD)

    // SARADC1
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT1 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC1, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif

    // SARADC2
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT2 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC2, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif

    // SARADC3
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT3 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC3, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif

    // SARADC4
    BITEK_TxByte(BITEK_1A2_SARADC34_SEL, SARADC_OUT4 | SARADC4_CH  | SARADC3_CH);
    #if (DEBUG_SARADC)
    OSD_ShowHex(VP_SHOW_SARADC4, BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB));
    #endif

    #endif
} /* SARADC_Scan */
#endif


#if (SARADC_VR_TASK)
/* -------------------------------------------------------------------
    Name: SARADC_VR_Task -
    Purpose: VR process.
    Passed: None.
    Returns: None.
    Notes:
        1) Get current VR raw.
        2) Change VR channel.
        3) Check whether it is floating.
        4) Check whether its delta is over threshold.
        5) Update VR raw.
        6) Adjust VR value for OSD and Register.
   ------------------------------------------------------------------- */
void SARADC_VR_Task (void)
{
    #if (SARADC_INT)
    if (bSARADC_VR_Flag)
    {
        UB8 bVR_Value;


        if (bSARADC_VR_Flag & 0x01)
        {
            bSARADC_VR_CH = SARADC_VR_BRIGHTNESS;
            bSARADC_VR_Flag &= 0xFE;
        }
        else if (bSARADC_VR_Flag & 0x02)
        {
            bSARADC_VR_CH = SARADC_VR_CONTRAST;
            bSARADC_VR_Flag &= 0xFD;
        }
        else
        {
            bSARADC_VR_CH = SARADC_VR_SATURATION;
            bSARADC_VR_Flag &= 0xFB;
        }

        BITEK_TxByte(BITEK_1A2_SARADC34_SEL, abVR_1A2[ bSARADC_VR_CH ] | SARADC4_CH | SARADC3_CH);
        bVR_New = BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB);

        #if (DEBUG_SARADC)
        OSD_ShowHex(VP_SHOW_SARADC, bVR_New);
        #endif


        bVR_Value = SARADC_VR_Value();

        BITEK_TxRepeat(VP_SHOW_OSD2, OSD2_AREA, ' ');

        BITEK_TxBurst(VP_SHOW_TITLE, TITLE_WIDTH, apbTitle[ bSARADC_VR_CH ]);

        OSD_ShowValue(VP_SHOW_VALUE, bVR_Value, 100, ' ');
        OSD_ShowProgressBar(VP_SHOW_BAR, bVR_Value);

        switch (bSARADC_VR_CH)
        {
            case SARADC_VR_BRIGHTNESS:
            default:
                VP_SetBrightness(bVR_Value);
                break;

            case SARADC_VR_CONTRAST:
                VP_SetContrast(bVR_Value);
                break;

            case SARADC_VR_SATURATION:
                VP_SetSaturation(bVR_Value);
                break;
        } // switch

        BITEK_TxByte(BITEK_12D_OSD2_ATTR2, OSD2_ON);
        bOSD_Cnt = OSD_AUTO_START;
    }

    #else

    SARADC_VR_Update();

    #if (SARADC_IN_MODE == SARADC_IN_SINGLE)
    bSARADC_VR_CH = (bSARADC_VR_CH + 1) % SARADC_VR_SIZE;

    // Update SARADC1 CH !
    BITEK_TxByte(BITEK_1A1_SARADC12_SEL, SARADC_IN_MODE | SARADC2_CH1 | abVR_1A1[ bSARADC_VR_CH ]);
    #endif // SARADC_IN_MODE

    #endif // SARADC_INT
} /* SARADC_VR_Task */
#endif


#if (SARADC_VR_UPDATE)
/* -------------------------------------------------------------------
    Name: SARADC_VR_Update -
    Purpose:
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void SARADC_VR_Update (void)
{
    UB8 bVR_Value;
    UB8 bVR_Delta;


    bVR_New = BITEK_RxByte(BITEK_1AA_SARADC_OUT_I_MSB);

    if (bVR_New > abVR_Old[ bSARADC_VR_CH ])
        bVR_Delta = bVR_New - abVR_Old[ bSARADC_VR_CH ];
    else
        bVR_Delta = abVR_Old[ bSARADC_VR_CH ] - bVR_New;

    // Hysteresis
    if (bVR_Delta >= VR_THRESHOLD)
    {
        // Update VR value
        abVR_Old[ bSARADC_VR_CH ] = bVR_New;

        bVR_Value = SARADC_VR_Value();

        BITEK_TxRepeat(VP_SHOW_OSD2, OSD2_AREA, ' ');

        BITEK_TxBurst(VP_SHOW_TITLE, TITLE_WIDTH, apbTitle[ bSARADC_VR_CH ]);

        OSD_ShowValue(VP_SHOW_VALUE, bVR_Value, 100, ' ');
        OSD_ShowProgressBar(VP_SHOW_BAR, bVR_Value);

        switch (bSARADC_VR_CH)
        {
            case SARADC_VR_BRIGHTNESS:
            default:
                VP_SetBrightness(bVR_Value);
                break;

            case SARADC_VR_CONTRAST:
                VP_SetContrast(bVR_Value);
                break;

            case SARADC_VR_SATURATION:
                VP_SetSaturation(bVR_Value);
                break;
        } // switch

        BITEK_TxByte(BITEK_12D_OSD2_ATTR2, OSD2_ON);
        bOSD_Cnt = OSD_AUTO_START;
    }
} // SARADC_VR_Update
#endif


#if (SARADC_VR_VALUE)
/* -------------------------------------------------------------------
    Name: SARADC_VR_Value -
    Purpose:
    Passed: None.
    Returns: 0..30
    Notes:
   ------------------------------------------------------------------- */
UB8 SARADC_VR_Value (void)
{
    if (bVR_New > VR_CRITERIA)
        return( VR_OSD_DEFAULT );
    else if (bVR_New > VR_HIGH)
        return( VR_OSD_MAX );
    else if (bVR_New < VR_LOW)
        return( VR_OSD_MIN );
    else
        return( (bVR_New - VR_LOW) / VR_STEP );
} // SARADC_VR_Value
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
