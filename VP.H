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

    Module: VP.H - Video Processor.

    Purpose: Interface of VP module.

    Version: 0.01                                   06:37PM  2013/03/16

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 06:37PM  2013/03/16 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#ifndef _VP_H_
#define _VP_H_


/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "common.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _VP_C_
    #define EXTERN
#else
    #define EXTERN extern
#endif


#define VP_DISPLAY_MODE         OFF
#define VP_SET_BLACKLEVEL       OFF
#define VP_SET_BRIGHTNESS       ON
#define VP_SET_COLORSTANDARD    OFF
#define VP_SET_CONTRAST         ON
#define VP_SET_GAMMA_YUV        OFF
#define VP_SET_IMAGE_MIRROR     OFF
#define VP_SET_PLL              OFF
#define VP_SET_PWM_DUTY         OFF
#define VP_SET_PWM_FREQ         OFF
#define VP_SET_PWM_REF          OFF
#define VP_SET_SATURATION       ON
#define VP_SET_COLORKILLER      ON
#define VP_SET_SHARPNESS        OFF
#define VP_SET_TCON_MODE        OFF
#define VP_SET_TESTPATTERN      OFF
#define VP_STD_DETECT           ON


#define OSD_MIN                 0
#define OSD_DEFAULT             30
#define OSD_MAX                 60

//BRIGHTNESS                0x13A   (VP)
//Y = 2 * (X - 50) + 128, X = 0..100, Default X = 50, Y = 128
//  = 2 * X + 28
//Y = 4 * (X - 15) + 128, X = 0..30, Default X = 15, Y = 128
//  = 4 * X + 68
//Y = 2 * (X - 30) + 128, X = 0..60, Default X = 30, Y = 128
//  = 2 * X + 68
#define BRIGHTNESS_MIN          OSD_MIN
#define BRIGHTNESS_DEFAULT      OSD_DEFAULT
#define BRIGHTNESS_MAX          OSD_MAX

//Y = 1 * (X - 30) + 128, X = 0..60, Default X = 30, Y = 128
//  = 1 * X + 98
#define BRIGHTNESS_VALUE        128
#define BRIGHTNESS_SLOPE        1
#define BRIGHTNESS_OFFSET       (BRIGHTNESS_VALUE - BRIGHTNESS_SLOPE * BRIGHTNESS_DEFAULT)

//CONTRAST                  0x13B   (VP)
//Y = 2 * (X - 50) + 128, X = 0..100, Default X = 50, Y = 28
//  = 2 * X + 28
//Y = 2 * (X - 30) + 128, X = 0..60, Default X = 30, Y = 128
//  = 2 * X + 28
#define CONTRAST_MIN            OSD_MIN
#define CONTRAST_DEFAULT        OSD_DEFAULT
#define CONTRAST_MAX            OSD_MAX

#define CONTRAST_VALUE          128
#define CONTRAST_SLOPE          2
#define CONTRAST_OFFSET         (CONTRAST_VALUE - CONTRAST_SLOPE * CONTRAST_DEFAULT)

//SHARPNESS                 0x13C   (VP)
//Y = 1 * (X - 50) + 64, X =  0..100,  Default X = 50, Y = 64
//  = 1 * X + 14
//Y = 1 * (X - 50) + 192, X =  0..100,  Default X = 50, Y = 192
//  = 1 * X + 142
//Y = 2 * (X - 30) + 192, X =  0..60,  Default X = 30, Y = 192
//  = 2 * X + 132
#define SHARPNESS_MIN           OSD_MIN
#define SHARPNESS_DEFAULT       OSD_DEFAULT
#define SHARPNESS_MAX           OSD_MAX

#define SHARPNESS_VALUE         192
#define SHARPNESS_SLOPE         2
#define SHARPNESS_OFFSET        (SHARPNESS_VALUE - SHARPNESS_SLOPE * SHARPNESS_DEFAULT)


//SATURATION                0x13E/0x13F (VP)
//Y = 1 * (X - 50) + 64, X =  0..50,  Default X = 50, Y = 64
//  = 1 * X + 14
//Y = 2 * (X - 50) + 64, X = 50..100, Default X = 50, Y = 64
//  = 2 * X - 36
#define SATURATION_MIN          OSD_MIN
#define SATURATION_DEFAULT      OSD_DEFAULT
#define SATURATION_MAX          OSD_MAX

#if 0
//Y = 2 * (X - 30) + 64, X =  0..60,  Default X = 30, Y = 64
//  = 2 * X + 4
#define SATURATION_VALUE        64
#define SATURATION_SLOPE        2
#define SATURATION_SLOPE2       2
#define SATURATION_OFFSET       (SATURATION_VALUE - SATURATION_SLOPE * SATURATION_DEFAULT)
#define SATURATION_OFFSET2      (SATURATION_SLOPE2 * SATURATION_DEFAULT - SATURATION_VALUE)
#endif

//Y = 2 * (X - 30) + 64,     if X =  0..30,  Default X = 30, Y = 64
//  = 2 * X + 4
//Y = 3 * (X - 30) / 2 + 64, if X = 30..60,  Default X = 30, Y = 64
//  = 3 * X  / 2 + 19
#define SATURATION_VALUE        64
#define SATURATION_SLOPE        2
//#define SATURATION_SLOPE2     (3/2)
#define SATURATION_OFFSET       (SATURATION_VALUE - SATURATION_SLOPE * SATURATION_DEFAULT)
#define SATURATION_OFFSET2      (SATURATION_VALUE - 3 * SATURATION_DEFAULT / 2)

/* ------------------------------------
    Type Definitions
   ------------------------------------ */
typedef enum MENU_ID
{
    MENU_ID_BRIGHTNESS  ,
    MENU_ID_CONTRAST    ,
    MENU_ID_SATURATION  ,

    MENU_ID_SIZE        ,
} enumMENU_ID;



/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */
// VID713-100-124/ (MCU Daughter Board v1.00)
//sbit VP_nRESETo  = P1 ^ 3;
//#define VP_RESET_ON             { VP_nRESETo  = LOW;        }
//#define VP_RESET_OFF            { VP_nRESETo  = HIGH;       }
//#define VP_MAD                  VP_MAD_IF       // VP IF MAD

EXTERN BOOL fVD_NoSignal;
EXTERN UB8  bVD_STD_Cnt;            // one-shot counter


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */
void VP_Init(void);

#if (VP_SET_BRIGHTNESS)
void VP_SetBrightness(UB8 bBrightness);
#endif

#if (VP_SET_CONTRAST)
void VP_SetContrast(UB8 bContrast);
#endif

#if (VP_SET_SATURATION)
void VP_SetSaturation(UB8 bSaturation);
#endif

#if (VP_SET_COLORKILLER)
void VP_SetColorKiller(UB8 bSaturation);
#endif

#if (VP_SET_GAMMA_YUV)
void VP_SetGAMMA_YUV(void);
#endif

#if (VP_STD_DETECT)
void VP_STD_Detect(void);
#endif



#ifdef NOT_JUNK
EXTERN void VP_BlankColor(BOOL fON);

#if (VP_DISPLAY_MODE)
EXTERN void VP_DISPLAY_MODE(UB8 bDisplayMode);
#endif


#if (VP_SET_DAC)
EXTERN void VP_SetDAC(void);
#endif

#if (VP_SET_COLORSTANDARD)
EXTERN void VP_SetColorStandard(UB8 bCS_Mode);
#endif


#if (VP_SET_SHARPNESS)
EXTERN void VP_SetSharpness(UB8 bSharpness);
#endif


#if (VP_SET_TCON_MODE)
EXTERN void VP_SetTCON_Mode(UB8 bTCON_Mode);
#endif

#if (VP_SET_TESTPATTERN)
EXTERN void VP_SetTestPattern(UB8 bColorR, UB8 bColorG, UB8 bColorB, UB8 bPatternType, UB8 bMode);
#endif

#endif

#endif /* _VP_H_ */


/* **********************************************************************

    Description:


   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
