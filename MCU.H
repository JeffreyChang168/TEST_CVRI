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

    Module: MCU.H

    Purpose: Interface of MCU module.

    Version: 0.02                                   07:26PM  2013/03/16

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

   ----------------------------------------------------------------------
    v0.02 10:53PM  2013/04/04 Jeffrey Chang
    Reason:
        1. To add SARADC interrupt approach.
    Solution:

   ********************************************************************** */

#ifndef _MCU_H_
#define _MCU_H_

/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "common.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _MCU_C_
    #define EXTERN
#else
    #define EXTERN  extern
#endif


#define DEBUG_MCU               ON


/* ::::::::::::::::::::::::::::::::::::
    MCU Pins Assignment
   :::::::::::::::::::::::::::::::::::: */
#define MCU_DC_ON               {                       }
#define MCU_DC_OFF              {                       }

#define MCU_AUDIO_ON            {                       }
#define MCU_AUDIO_OFF           {                       }

#define MCU_PANEL_ON            {                       }
#define MCU_PANEL_OFF           {                       }

#define MCU_TCON_ON             {                       }
#define MCU_TCON_OFF            {                       }

#define MCU_WP_ON               {                       }
#define MCU_WP_OFF              {                       }

/*
  //////////////////////////////////////////////////////////////////////////////
  RTS0 as Backlight control
  //////////////////////////////////////////////////////////////////////////////
*/
#define BL_OFF                  0x44
#define BL_ON                   0x64

#define MCU_BL_ON               { BITEK_TxByte(BITEK_0FB_RTS0_ATTR, BL_ON);   }
#define MCU_BL_OFF              { BITEK_TxByte(BITEK_0FB_RTS0_ATTR, BL_OFF);  }


/*
; ------------------------------------------------------------------------------
;   TCON (SFR 0x88)
; 7 6 5 4 3 2 1 0
; | | | | | | | |_ IT0 (Interrupt 0 Type control bit)
; | | | | | | |         0=low level    triggered External
; | | | | | | |         1=falling edge triggered External
; | | | | | | |___ IE0 (External Interrupt 0 edge flag)
; | | | | | |           0=when interrupt is processed.
; | | | | | |           1=when External Interrupt edge detected
; | | | | | |_____ IT1 (Interrupt 1 Type control bit)
; | | | | |             0=low level    triggered External
; | | | | |             1=falling edge triggered External
; | | | | |_______ IE1 (External Interrupt 1 edge flag)
; | | | |               0=when interrupt is processed.
; | | | |               1=when External Interrupt edge detected
; | | | |_________ TR0 (Timer 0 run control bit)
; | | |                 0=turn Timer/Counter 0 OFF
; | | |                 1=turn Timer/Counter 0 ON
; | | |___________ TF0 (Timer 0 overflow flag)
; | |                   0=processor vectors to the service routine
; | |                   1=when the Timer/Counter 0 overflows
; | |_____________ TR1 (Timer 1 run control bit)
; |                     0=turn Timer/Counter 1 OFF
; |                     1=turn Timer/Counter 1 ON
; |_______________ TF1 (Timer 1 overflow flag)
;                       0=processor vectors to the service routine
;                       1=when the Timer/Counter 1 overflows
; 0 1 0 0-0 0 0 0   0x40    TIMER1 ON,            INT1 Low level
; 0 1 0 0-0 1 0 0   0x44    TIMER1 ON,            INT1 Falling edge
; 0 1 0 0-0 1 0 1   0x45    TIMER1 ON,            INT1 Falling edge, INT0 Falling edge
; 0 1 0 0-1 1 1 1   0x4F    TIMER1 ON,            INT1 Falling edge, INT0 Falling edge
; 0 1 0 1-1 1 1 1   0x5F    TIMER1 ON, TIMER0 ON, INT1 Falling edge, INT0 Falling edge
; 0 1 0 1-0 0 0 0   0x50    TIMER1 ON, TIMER0 ON, INT1 Low level,    INT0 INT1 Low level
*/
//#define SFR_TCON          0x50        // TIMER1 ON, TIMER0 ON, INT1 Low level,    INT0 INT1 Low level
  #define SFR_TCON          0x5F        // TIMER1 ON, TIMER0 ON, INT1 Falling edge, INT0 Falling edge


/*
; ------------------------------------------------------------------------------
;   IE (SFR 0xA8)
; 7 6 5 4 3 2 1 0
; | | | | | | | |_ EX0 (External INT0)
; | | | | | | |___ ET0 (TIMER0)
; | | | | | |_____ EX1 (External INT1)
; | | | | |_______ ET1 (TIMER1)
; | | | |_________ ES  (UART)
; | | |___________ ET2 (TIMER2)
; |_______________ EA
; 1 0 0 0 0 0 1 0   0x82                                TIMER0
; 1 0 0 0 0 1 1 1   0x87                          INT1, TIMER0, INT0
; 1 0 0 0 1 0 0 0   0x88                  TIMER1
; 1 0 0 0 1 0 1 0   0x8A                  TIMER1,       TIMER0
; 1 0 0 0 1 1 0 1   0x8D                  TIMER1, INT1,         INT0
; 1 0 0 1 1 1 0 1   0x9D            UART  TIMER1, INT1,         INT0
; 1 0 0 1 1 1 1 1   0x9F            UART, TIMER1, INT1, TIMER0, INT0
; 1 0 1 0 1 0 1 0   0xAA    TIMER2,       TIMER1,       TIMER0
; 1 0 1 0 1 1 1 1   0xAF    TIMER2,       TIMER1, INT1, TIMER0, INT0
; 1 0 1 1 1 1 1 1   0xBF    TIMER2, UART, TIMER1, INT1, TIMER0, INT0
*/

  #define INT_OFF           0x00
//#define INT_ON            0x9D        //         UART  TIMER1, INT1,         INT0
//#define INT_ON            0x9F        //         UART, TIMER1, INT1, TIMER0, INT0
//#define INT_ON            0xAA        // TIMER2,       TIMER1,       TIMER0,
  #define INT_ON            0xAF        // TIMER2,       TIMER1, INT1, TIMER0, INT0
//#define INT_ON            0xBF        // TIMER2, UART, TIMER1, INT1, TIMER0, INT0


/*
; ------------------------------------------------------------------------------
;   IP (SFR 0xB8)
; 7 6 5 4 3 2 1 0
; | | | | | | | |_ PX0 (External INT0)
; | | | | | | |___ PT0 (TIMER0)
; | | | | | |_____ PX1 (External INT1)
; | | | | |_______ PT1 (TIMER1)
; | | | |_________ PS  (UART)
; | | |___________ PT2 (TIMER2)
; |_______________
; 0 0 0 0 1 0 0 0   0x08                    TIMER1
; 0 0 0 0 1 0 1 0   0x0A                    TIMER1 +        TIMER0
; 0 0 0 1 0 0 0 0   0x10             UART
; 0 0 1 0 0 0 0 0   0x20    TIMER2
; 0 0 1 1 1 1 1 1   0x2A    TIMER2 +        TIMER1 +        TIMER0
; 0 0 1 0 1 1 1 1   0x2F    TIMER2 +        TIMER1 + INT1 + TIMER0 + INT0
; 0 0 1 1 1 1 1 1   0x3F    TIMER2 + UART + TIMER1 + INT1 + TIMER0 + INT0
*/

//#define SFR_IP            0x02    //                                 TIMER0
//#define SFR_IP            0x08    //                 TIMER1
//#define SFR_IP            0x0A    //                 TIMER1 +        TIMER0
//#define SFR_IP            0x10    //          UART
//#define SFR_IP            0x20    // TIMER2
//#define SFR_IP            0x2A    // TIMER2 +        TIMER1 +        TIMER0
  #define SFR_IP            0x2F    // TIMER2 +        TIMER1 + INT1 + TIMER0 + INT0
//#define SFR_IP            0x3F    // TIMER2 + UART + TIMER1 + INT1 + TIMER0 + INT0

/*
; ------------------------------------------------------------------------------
;   T2CON (SFR 0xC8)
; 7 6 5 4 3 2 1 0
; | | | | | | | |_ CP/RL2   (Capture/Reload flag)
; | | | | | | |         When set, captures will occur on negative transitions at T2EX if EXEN2 = 1.
; | | | | | | |         When cleared, auto-reloads will occur either with Timer 2 overflows or negative transitions at T2EX when
; | | | | | | |         EXEN2 = 1. When either RCLK = 1 or TCLK = 1, this bit is ignored and the timer is forced to auto-reload
; | | | | | | |         on Timer 2 overflow.
; | | | | | | |
; | | | | | | |___ C/T2 Timer or counter select. (Timer 2)
; | | | | | |           0 = Internal timer (OSC/2)
; | | | | | |           1 = External event counter (falling edge triggered).
; | | | | | |
; | | | | | |_____ TR2  (Timer 2 run control bit)
; | | | | |              Start/stop control for Timer 2. A logic 1 starts the timer.
; | | | | |
; | | | | |_______ EXEN2    (Timer 2 external enable flag)
; | | | |               When set, allows a capture or reload to occur as a result of a negative
; | | | |               transition on T2EX if Timer 2 is not being used to clock the serial port.
; | | | |               EXEN2 = 0 causes Timer 2 to ignore events at T2EX.
; | | | |
; | | | |_________ TCLK (Transmit clock flag)
; | | |                 When set, causes the serial port to use Timer 2 overflow pulses for its transmit clock
; | | |                 in modes 1 and 3. TCLK = 0 causes Timer 1 overflows to be used for the transmit clock.
; | | |
; | | |___________ RCLK (Receive clock flag)
; | |                   When set, causes the serial port to use Timer 2 overflow pulses for its receive clock
; | |                   in modes 1 and 3. RCLK = 0 causes Timer 1 overflow to be used for the receive clock.
; | |
; | |_____________ EXF2 (Timer 2 external flag)
; |                     Timer 2 external flag set when either a capture or reload is
; |                     caused by a negative transition on T2EX and EXEN2 = 1.
; |                     When Timer 2 interrupt is enabled, EXF2 = 1 will cause the CPU to vector to the Timer 2
; |                     interrupt routine. EXF2 must be cleared by software.
; |                     EXF2 does not cause an interrupt in up/down counter mode (DCEN = 1).
; |
; |_______________ TF2  (Timer 2 overflow flag)
;                       Timer 2 overflow flag set by a Timer 2 overflow and must be cleared by software.
;                       TF2 will not be set when either RCLK or TCLK = 1.
; 0 0 0 0 0 1 0 0   0x04                    EXEN2=0, TR2=1, C/T2=0, (16-bit Auto-reload Timer  )
; 0 0 0 0 0 1 1 0   0x06                    EXEN2=0, TR2=1, C/T2=1, (16-bit Auto-reload Counter)
; 0 0 0 0 1 1 1 0   0x0E                    EXEN2=1, TR2=1, C/T2=1, (16-bit Auto-reload Counter)
; 0 0 1 1 0 1 0 0   0x34    RCLK=1. TCLK=1, EXEN2=0, TR2=1, C/T2=0, (Baud rate generator)
*/
//#define SFR_T2CON         0x04    //                 EXEN2=0, TR2=1, C/T2=0   OK (16-bit Auto-Reload Timer  )
  #define SFR_T2CON         0x06    //                 EXEN2=0, TR2=1, C/T2=1   OK (16-bit Auto-Reload Counter)
//#define SFR_T2CON         0x0E    //                 EXEN2=1, TR2=1, C/T2=1   NG
//#define SFR_T2CON         0x14    //         TCLK=1, EXEN2=0, TR2=1, C/T2=0   OK
//#define SFR_T2CON         0x24    // RCLK=1.         EXEN2=0, TR2=1, C/T2=0   OK
//#define SFR_T2CON         0x34    // RCLK=1. TCLK=1, EXEN2=0, TR2=1, C/T2=0   OK (Baud rate generator)



/*
; ------------------------------------------------------------------------------
;   INT0 ACK (0x004)
; 7 6 5 4 3 2 1 0
; | | | | | | | |_ VD SIGNAL READY
; | | | | | | |___ VP SIGNAL READY
; | | | | | |_____ VIDEO_ADC
; | | | | |_______ VD_MV
; | | | |_________ VD_CC
; | | |___________ ADC
; | |_____________ IR
; |_______________ GPI
; 0 0 0 0 0 0 0 1   0x01    VD SIGNAL READY
; 0 0 1 0 0 0 0 1   0x21    VD SIGNAL READY, ADC
*/
//#define INT0_ACK          0x01        // VD SIGNAL READY
  #define INT0_ACK          0x21        // VD SIGNAL READY, ADC


/*
; ------------------------------------------------------------------------------
;   INT1 ACK (0x007)
; 7 6 5 4 3 2 1 0
; | | | | | | | |_ VD NO SIGNAL
; | | | | | | |___ VP NO SIGNAL
; | | | | | |_____ VP MODE
; | | | | |_______ VD STANDARD
; | | | |_________ LINE BUFFER
; | | |___________ ADC
; | |_____________ IR
; |_______________ GPI
; 0 0 0 0 0 0 0 1   0x01    VD NO SIGNAL
; 0 0 0 0 1 0 0 0   0x08    VD STANDARD CHANGE
; 0 0 0 0 1 0 0 1   0x09    VD STANDARD CHANGE, VD NO SIGNAL
; 0 1 0 0 1 0 0 1   0x49    VD STANDARD CHANGE, VD NO SIGNAL, IR
*/
//#define INT1_ACK          0x49        // VD STANDARD CHANGE, VD NO SIGNAL, IR
  #define INT1_ACK          0x09        // VD STANDARD CHANGE, VD NO SIGNAL


/*
; ------------------------------------------------------------------------------
;   INT ATTR (0x008)
; 7 6 5 4 3 2 1 0
; | | | | | | | |_ INT0 Interrupt POLARITY
; | | | | | | |     0=High level or Rising  edge active
; | | | | | | |     1=Low  level or Falling edge active
; | | | | | | |___ INT0 Interrupt TYPE
; | | | | | |       0=Edge  type
; | | | | | |       1=Level type
; | | | | | |_____ INT1 Interrupt POLARITY
; | | | | |         0=High level or Rising  edge active
; | | | | |         1=Low  level or Falling edge active
; | | | | |_______ INT1 Interrupt TYPE
; | | | |           0=Edge  type
; | | | |           1=Level type
; | | | |_________ Video ADC change detection (0=Disable, 1=Enable) AIN11
; | | |___________ Video ADC change detection (0=Disable, 1=Enable) AIN12
; | |_____________ Video ADC change detection (0=Disable, 1=Enable) AIN2
; |_______________ ADC interface interrupt type (0=Edge trigger, 1=Level trigger)
; 0 0 0 0 0 1 0 1   0x05 INT1 Falling edge, INT0 Falling edge
; 0 0 0 0 1 1 1 1   0x0F INT1 Low level, INT0 Low level
*/
//#define INT_ATTR            0x05  // INT1 Falling edge, INT0 Falling edge
  #define INT_ATTR            0x0F  // INT1 Low level, INT0 Low level



/* ------------------------------------
    Type Definitions
   ------------------------------------ */

/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */
EXTERN UB8  bMCU_BL_Cnt;

#if (DEBUG_MCU)
EXTERN UB8  bMCU_INT0_Cnt;
EXTERN UB8  bMCU_INT1_Cnt;
#endif


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */
void MCU_Init(void);
void MCU_INT0_RESET(void);
void MCU_INT1_RESET(void);
void MCU_SETUP_INT(void);

#endif  /* _MCU_H_ */


/* **********************************************************************

    Description:

   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
