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

    Module: SARADC.H -

    Purpose: Interface of SARADC.

    Version: 0.01                                   04:52PM  2013/04/04

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 04:52PM  2013/04/04 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#ifndef _SARADC_H_
#define _SARADC_H_


/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "common.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _SARADC_C_
    #define EXTERN
#else
    #define EXTERN  extern
#endif


#define SARADC_INT          ON

#define DEBUG_SARADC        ON
#define SARADC_SCAN         OFF
#define SARADC_VR_TASK      ON
#define SARADC_VR_UPDATE    OFF
#define SARADC_VR_VALUE     ON



/* //////////////////////////////////////////////////////////////////////////
    SARADC Configuration
   ////////////////////////////////////////////////////////////////////////// */

/*
    a) SARADC SINGLE
        a.1) SARADC_CH_VHS  OK 03:23PM  2013/03/17
        a.2) SARADC_CH_A_2  OK 03:23PM  2013/03/17
        a.3) SARADC_CH_A_3  OK 03:23PM  2013/03/17

    b) SARADC DUAL
        b.1) SARADC_CH_VHS  OK 03:28PM  2013/03/17
        b.2) SARADC_CH_A_2  OK 03:28PM  2013/03/17

    c) SARADC DUAL
        c.1) SARADC_CH_VHS  OK 03:35PM  2013/03/17
        c.2) SARADC_CH_A_2  OK 03:35PM  2013/03/17
        c.3) SARADC_CH_A_3  OK 03:35PM  2013/03/17

*/
// 0x1A1[7:6]
#define SARADC_IN_SINGLE    0x00            // 00: Single Mode
#define SARADC_IN_DUAL      0x40            // 01: Dual   Mode
#define SARADC_IN_TRIPLE    0x80            // 10: Triple Mode
#define SARADC_IN_QUAD      0xC0            // 11: Quad   Mode

//#define SARADC_IN_MODE    SARADC_IN_SINGLE  // OK 03:23PM  2013/03/17
//#define SARADC_IN_MODE    SARADC_IN_DUAL    // OK 03:27PM  2013/03/17
  #define SARADC_IN_MODE    SARADC_IN_TRIPLE  // OK 03:36PM  2013/03/17
//#define SARADC_IN_MODE    SARADC_IN_QUAD    //

#define SARADC_CH_VBT       (0x00)
#define SARADC_CH_VHS       (0x01)
#define SARADC_CH_A_2       (0x02)
#define SARADC_CH_A_3       (0x03)
#define SARADC_CH_YM        (0x04)
#define SARADC_CH_YP        (0x05)
#define SARADC_CH_XM        (0x06)
#define SARADC_CH_XP        (0x07)

// SARADC1 CH (0x1A1[2:0])
#define SARADC1_CH          (SARADC_CH_VHS << 0)
#define SARADC1_CH1         (SARADC_CH_VHS << 0)
#define SARADC1_CH2         (SARADC_CH_A_2 << 0)
#define SARADC1_CH3         (SARADC_CH_A_3 << 0)
#define SARADC1_CH4         (SARADC_CH_VBT << 0)

// SARADC2 CH (0x1A1[5:3])
#define SARADC2_CH          (SARADC_CH_A_2 << 3)
#define SARADC2_CH1         (SARADC_CH_VHS << 3)
#define SARADC2_CH2         (SARADC_CH_A_2 << 3)
#define SARADC2_CH3         (SARADC_CH_A_3 << 3)
#define SARADC2_CH4         (SARADC_CH_VBT << 3)

// SARADC3 CH (0x1A2[2:0])
#define SARADC3_CH          (SARADC_CH_A_3 << 0)
#define SARADC3_CH1         (SARADC_CH_VHS << 0)
#define SARADC3_CH2         (SARADC_CH_A_2 << 0)
#define SARADC3_CH3         (SARADC_CH_A_3 << 0)
#define SARADC3_CH4         (SARADC_CH_VBT << 0)      

// SARADC4 CH (0x1A2[5:3])
#define SARADC4_CH          (SARADC_CH_VHS << 3)
#define SARADC4_CH1         (SARADC_CH_VHS << 3)
#define SARADC4_CH2         (SARADC_CH_A_2 << 3)      
#define SARADC4_CH3         (SARADC_CH_A_3 << 3)
#define SARADC4_CH4         (SARADC_CH_VBT << 3)

// 0x1A2[7:6]
#define SARADC_OUT1         0x00            // SARADC1
#define SARADC_OUT2         0x40            // SARADC2
#define SARADC_OUT3         0x80            // SARADC3
#define SARADC_OUT4         0xC0            // SARADC4
#define SARADC_OUT_MODE     SARADC_OUT1

// VR
#define SARADC1_CH_VR1      (SARADC_CH_VHS << 0)
#define SARADC1_CH_VR2      (SARADC_CH_A_2 << 0)
#define SARADC1_CH_VR3      (SARADC_CH_A_3 << 0)
#define SARADC1_CH_VR4      (SARADC_CH_VBT << 0)


/* ------------------------------------
    Type Definitions
   ------------------------------------ */
typedef enum VR_ENUM
{
    SARADC_VR_BRIGHTNESS    ,
    SARADC_VR_CONTRAST      ,
    SARADC_VR_SATURATION    ,

    SARADC_VR_SIZE          ,
} enumVR;



/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */
EXTERN BOOL fSARADC_VR_Task;
EXTERN UB8  bSARADC_VR_CH;

#if (SARADC_INT)
EXTERN UB8  bSARADC_VR_Flag;
#endif


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */
void SARADC_Init(void);

#if (SARADC_SCAN)
void SARADC_Scan(void);
#endif

#if (SARADC_VR_TASK)
void SARADC_VR_Task(void);
#endif

#endif /* _SARADC_H_ */


/* **********************************************************************

    Description:

   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
