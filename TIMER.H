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

    Module: TIMER.H

    Purpose: Interface of TIMER module.

    Version: 0.01                                   11:58AM  2013/03/17

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 11:58AM  2013/03/17 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#ifndef _TIMER_H_
#define _TIMER_H_


/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "common.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _TIMER_C_
    #define EXTERN
#else
    #define EXTERN  extern
#endif


#define TIMER_DELAYMS               OFF

/*
; ------------------------------------------------------------------------------
;   TIMER Mode
; ------------------------------------------------------------------------------
;   Fosc = 24.576MHz
;   Fxclk = Fosc / 4 (chose by software)
;   XCLK = 1 / Fxclk = 4 / Fosc = 4 / 24.576 us = 0.1627 us
;   1 Machine Cycle (MC) = 2 * XCLK = 0.3255 us
;   TIMER clock frequency   = Fxclk / 2
;   TIMER clock period      = 2 * XCLK = 0.3255 us
;
;   If Fxclk = Fosc / 1 (chose by software)
;   1 HSYNC = (858 * 13.5MHz / Fxclk) XCLK = (858 * 13.5MHz / 24.576MHz) XCLK
;   1 VSYNC = 262 or 313 HSYNC  @858 x 262/263 or 858 x 312/313

; TMODE (SFR 0x89) [2]85
;
; 7 6 5 4 3 2 1 0
; | | | | | | |_|_ M1 M0    (Operating Mode)
; | | | | | |       0 0     0   13-bit Timer (8048 compatible)
; | | | | | |       0 1     1   16-bit Timer/Counter
; | | | | | |       1 0     2   8-bit Auto-Reload Timer/Counter
; | | | | | |       1 1     3   (Timer 0) TL0 is an 8-bit Timer/Counter controlled by the standard Timer 0
; | | | | | |                   control bits. TH0 is an 8-bit Timer and is controlled by Timer 1 control bits.
; | | | | | |
; | | | | | |_____ C/nT     Timer or Counter selector.
; | | | | |                     Cleared for Timer operation (input from internal system clock).
; | | | | |                     Set for Counter operation (input from Tx input pin).
; | | | | |_______ GATE
; | | | |
; | | |_|_________ M1 M0    (Operating Mode)
; | |               0 0     0   13-bit Timer (8048 compatible)
; | |               0 1     1   16-bit Timer/Counter
; | |               1 0     2   8-bit Auto-Reload Timer/Counter
; | |               1 1     3   (Timer 1) Timer/Counter 1 stopped.
; | |
; | |_____________ C/nT     Timer or Counter selector.
; |                             Cleared for Timer operation (input from internal system clock).
; |                             Set for Counter operation (input from Tx input pin).
; |
; |_______________ GATE
; 0 0 0 1 0 0 0 1       0x11  TIMER1: 16-bit Timer              TIMER0: 16-bit Timer
; 0 0 0 1 0 1 0 1       0x15  TIMER1: 16-bit Timer              TIMER0: 16-bit Counter
; 0 0 1 0 0 0 0 1       0x21  TIMER1: 8-bit Auto-Reload Timer   TIMER0: 16-bit Timer
; 0 0 1 0 0 1 0 1       0x25  TIMER1: 8-bit Auto-Reload Timer   TIMER0: 16-bit Counter
; 0 1 0 1 0 0 0 1       0x51  TIMER1: 16-bit Counter            TIMER0: 16-bit Timer
; 0 1 0 1 0 1 0 1       0x55  TIMER1: 16-bit Counter            TIMER0: 16-bit Counter
; 0 1 0 1 0 1 1 0       0x56  TIMER1: 16-bit Counter            TIMER0: 8-bit Auto-Reload Counter
; 0 1 1 0 0 0 0 1       0x61  TIMER1: 8-bit Auto-Reload Counter TIMER0: 16-bit Timer
; 0 1 1 0 0 1 0 1       0x65  TIMER1: 8-bit Auto-Reload Counter TIMER0: 16-bit Counter
; 0 1 1 0 0 1 1 0       0x66  TIMER1: 8-bit Auto-Reload Counter TIMER0: 8-bit Auto-Reload Counter


; TIMER Attribute (0x18A) (COUNTER MODE only)
; 7 6 5 4 3 2 1 0
; | | | | | | |_|_ TIMER0 clock source
; | | | | | |       00 = OHS
; | | | | | |       01 = OHS
; | | | | | |       10 = IHS
; | | | | | |       11 = BIN[7]
; | | | | | |
; | | | | |_|_____ TIMER1 clock source
; | | | |           00 = OHS
; | | | |           01 = OVS
; | | | |           10 = IHS
; | | | |           11 = BIN[6]
; | | | |
; | | |_|_________ TIMER2 clock source
; | |               00 = OHS
; | |               01 = OVS
; | |               10 = IHS
; | |               11 = BIN[5]
; | |
; |_|_____________ TIMER22 clock source
;                   00 = OHS
;                   01 = OVS
;                   10 = IHS
;                   11 = BIN[4]
;
*/

// OSD Auto Vanish time
//#define OSD_AUTO_DELAY         90         // OSD Vanish time = 90 TIMER1 Ticks
  #define OSD_AUTO_DELAY        120         // OSD Vanish time =120 TIMER1 Ticks
  #define OSD_AUTO_START        255
  #define OSD_AUTO_STOP         (OSD_AUTO_START - OSD_AUTO_DELAY)

// Backlight Delay time
//#define BL_DELAY              16          // Backlight Delay time = 16 TIMER1 Ticks
//#define BL_DELAY              60          // Backlight Delay time = 60 TIMER1 Ticks
  #define BL_DELAY              45          // Backlight Delay time = 45 TIMER1 Ticks
  #define BL_START              255
  #define BL_STOP               (BL_START - BL_DELAY)


// AUTO VTRC Delay time
  #define VTRC_START            16          // 16 TIMER1 Ticks

// Color Standard latency period
  #define STD_DELAY             45          // Color Standard latency time = 45 TIMER1 Ticks
  #define STD_START             255
  #define STD_STOP              (STD_START - STD_DELAY)



/* ::::::::::::::::::::::::::::::::::::
   Timer Configuration
   :::::::::::::::::::::::::::::::::::: */


// [3]64, 89
//0 0 1 0 0 0 0 1       0x21  TIMER1: 8-bit Auto-Reload Timer   TIMER0: 16-bit Timer
//0 1 0 1 0 0 0 1       0x51  TIMER1: 16-bit Counter            TIMER0: 16-bit Timer
//0 1 0 1 0 1 0 1       0x55  TIMER1: 16-bit Counter            TIMER0: 16-bit Counter
//0 1 0 1 0 1 1 0       0x56  TIMER1: 16-bit Counter            TIMER0: 8-bit Auto-Reload Counter
//0 1 1 0 0 0 0 1       0x61  TIMER1: 8-bit Auto-Reload Counter TIMER0: 16-bit Timer
//0 1 1 0 0 1 0 1       0x65  TIMER1: 8-bit Auto-Reload Counter TIMER0: 16-bit Counter
//0 1 1 0 0 1 1 0       0x66  TIMER1: 8-bit Auto-Reload Counter TIMER0: 8-bit Auto-Reload Counter
#define TIMER0_16BIT_TIMER      0x01    // OK 02:21PM  2013/03/17
#define TIMER0_8BIT_TIMER       0x02    // OK 02:41PM  2013/03/17
#define TIMER0_16BIT_COUNTER    0x05    // OK 02:14PM  2013/03/17
#define TIMER0_8BIT_COUNTER     0x06    // OK 02:06PM  2013/03/17

#define TIMER1_16BIT_TIMER      0x10    // OK 02:21PM  2013/03/17
#define TIMER1_8BIT_TIMER       0x20    // OK 02:41PM  2013/03/17
#define TIMER1_16BIT_COUNTER    0x50    // OK 02:06PM  2013/03/17
#define TIMER1_8BIT_COUNTER     0x60    // OK 02:14PM  2013/03/17

//#define TMODE_TIMER0          TIMER0_16BIT_TIMER              // TIMER0: 16-bit Timer
//#define TMODE_TIMER0          TIMER0_8BIT_TIMER               // TIMER0: 8-bit Auto-Reload Timer
//#define TMODE_TIMER0          TIMER0_16BIT_COUNTER            // TIMER0: 16-bit Counter
  #define TMODE_TIMER0          TIMER0_8BIT_COUNTER             // TIMER0: 8-bit Auto-Reload Counter

//#define TMODE_TIMER1          TIMER1_16BIT_TIMER              // TIMER1: 16-bit Timer
//#define TMODE_TIMER1          TIMER1_8BIT_TIMER               // TIMER1: 8-bit Auto-Reload Timer
//#define TMODE_TIMER1          TIMER1_16BIT_COUNTER            // TIMER1: 16-bit Counter
  #define TMODE_TIMER1          TIMER1_8BIT_COUNTER             // TIMER1: 8-bit Auto-Reload Counter

#define TMODE_SETUP             (TMODE_TIMER1 + TMODE_TIMER0)


#define TIMER0_OHS              0x00    // OK 02:31PM  2013/03/17
#define TIMER0_OVS              0x01    // OK 02:07PM  2013/03/17
#define TIMER0_IHS              0x02    // OK 02:33PM  2013/03/17
#define TIMER0_BIN7             0x03

#define TIMER1_OHS              0x00    // OK 02:31PM  2013/03/17
#define TIMER1_OVS              0x04    // OK 02:07PM  2013/03/17
#define TIMER1_IHS              0x08    // OK 02:33PM  2013/03/17
#define TIMER1_BIN6             0x0C

#define TIMER2_OHS              0x00    // OK 02:07PM  2013/03/17
#define TIMER2_OVS              0x10    // OK 02:13PM  2013/03/17
#define TIMER2_IHS              0x20    // OK 02:22PM  2013/03/17
#define TIMER2_BIN5             0x30

#define TIMER22_OHS             0x00
#define TIMER22_OVS             0x40
#define TIMER22_IHS             0x80
#define TIMER22_BIN4            0xC0

//#define TIMER_BASE            (                           TIMER1_OVS | TIMER0_OHS)
//#define TIMER_BASE            (TIMER22_OVS | TIMER2_OVS | TIMER1_OVS | TIMER0_OVS)
//#define TIMER_BASE            (TIMER22_OVS | TIMER2_IHS                          )
//#define TIMER_BASE            (TIMER22_OVS | TIMER2_IHS | TIMER1_OHS | TIMER0_OHS)
//#define TIMER_BASE            (TIMER22_OVS | TIMER2_IHS | TIMER1_IHS | TIMER0_IHS)
//#define TIMER_BASE            (TIMER22_OVS | TIMER2_OHS | TIMER1_OVS | TIMER0_OVS)
//#define TIMER_BASE            (TIMER22_OVS | TIMER2_OHS | TIMER1_OHS | TIMER0_OVS)
//#define TIMER_BASE            (TIMER22_OVS | TIMER2_IHS | TIMER1_OHS | TIMER0_OVS)
  #define TIMER_BASE            (                           TIMER1_OVS | TIMER0_OVS)


/* ::::::::::::::::::::::::::::::::::::
    Timer Divider
   :::::::::::::::::::::::::::::::::::: */
//#define TIMER0_DIVIDER        250     /* 1 TIMER0 Tick =  250 OHS (in COUNTER MODE) */
//#define TIMER0_DIVIDER        1       /* 1 TIMER0 Tick =    1 OVS (in COUNTER MODE) */
  #define TIMER0_DIVIDER        60      /* 1 TIMER0 Tick =   60 OVS (in COUNTER MODE) */
//#define TIMER0_DIVIDER        500     /* 1 TIMER0 Tick =  500 IHS (in COUNTER MODE) */
//#define TIMER0_DIVIDER        30000   /* 1 TIMER0 Tick =          (in TIMER   MODE) */
//#define TIMER0_DIVIDER        255     /* 1 TIMER0 Tick =          (in TIMER   MODE) */

//#define TIMER1_DIVIDER        250     /* 1 TIMER1 Tick =  250 OHS (in COUNTER MODE) */
//#define TIMER1_DIVIDER        500     /* 1 TIMER0 Tick =  500 OHS (in COUNTER MODE) */
  #define TIMER1_DIVIDER        1       /* 1 TIMER1 Tick =    1 OVS (in COUNTER MODE) */
//#define TIMER1_DIVIDER        120     /* 1 TIMER1 Tick =  120 OVS (in COUNTER MODE) */
//#define TIMER1_DIVIDER        250     /* 1 TIMER0 Tick =  500 IHS (in COUNTER MODE) */
//#define TIMER1_DIVIDER        60000   /* 1 TIMER1 Tick =          (in TIMER   MODE) */
//#define TIMER1_DIVIDER        128     /* 1 TIMER1 Tick =          (in TIMER   MODE) */

//#define TIMER2_DIVIDER        500     /* 1 TIMER2 Tick =  500 OHS (in COUNTER MODE) */
//#define TIMER2_DIVIDER        1       /* 1 TIMER2 Tick =    1 OVS (in COUNTER MODE) */
  #define TIMER2_DIVIDER        1000    /* 1 TIMER2 Tick = 1000 IHS (in COUNTER MODE) */
//#define TIMER2_DIVIDER        60000   /* 1 TIMER2 Tick =          (in TIMER   MODE) */
                                        /*
                                                         =60000 * 2 XCLK
                                                         =60000 * 0.3255 us
                                                         =19530 us
                                                         =19.53 ms
                                        */


/* ::::::::::::::::::::::::::::::::::::
    System Tick Configuration
   :::::::::::::::::::::::::::::::::::: */
#define US_PER_TICK             16000   /* Micro-second per System Tick     */
#define MS_PER_TICK             16      /* Milli-second per System Tick     */


/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */
EXTERN UW16 wTIMER0_TickCnt;            // Free-run Up counter
EXTERN UW16 wTIMER1_TickCnt;            // Free-run Up counter
EXTERN UW16 wTIMER2_TickCnt;            // Free-run Up counter
EXTERN BOOL fTIMER0_Task;
EXTERN BOOL fTIMER1_Task;
EXTERN BOOL fTIMER2_Task;


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */

#if (TIMER_DELAYMS)
void TIMER_DelayMS(UW16 wMS);
#endif

void TIMER_Init(void);


#endif /* _TIMER_H_ */


/* **********************************************************************

    Description:

    A) System clock frequency = 24.576 MHz

        24.576 MHz = 24576000 Hz
                   = 24576 * 1000 Hz
                   = 24 * 2^10 * 10^3 Hz
                   = 2^16 * 3 * 5^3 Hz

        A.1) x12 CLOCK MODE

            1 Tick = 8192 Machine Cycles
                   = (8192 * 12) Clocks

            1 second = 1000 000                 us
                     = 24576000                 Clocks
                     = 24576000 / (8192 * 12)   Ticks
                     = 250                      Ticks

            1 Tick = 4 ms

        A.2) x6 CLOCK MODE

            1 Tick = 16384 Machine Cycles
                   = (16384 * 6) Clocks

            1 second = 1000 000                 us
                     = 24576000                 Clocks
                     = 24576000 / (16384 * 6)   Ticks
                     = 250                      Ticks

            1 Tick = 4 ms


   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
