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

    Module: BIT1618C.H - BIT1618C header file

    Purpose: Interface of BIT1618C module.

    Version: 0.17                                   11:33AM  2013/03/23

    Compiler: Keil 8051 C Compiler v9.51 or
              Keil 8051 Assembler v8.02b or
              C++ Builder 2010

    Reference:
    [1] BIT1618C_register_v0.6.xls, Beyond Innovation Technology

   ----------------------------------------------------------------------
    Modification:

    v0.01  09:59PM  2012/11/14 Paul lee
    Reason:
        1. Original.  Base on 1618B V28 for 1618C V3
    Solution:

    v0.02  11:00AM  2012/11/20 Paul lee
    Reason:
        1. Base on 1618C V6
    Solution:

    v0.03  18:00PM  2012/11/20 Paul lee
    Reason:
        1. Modify 0x0YYY to 0xYYY value
        2. add comment for 0x12E bit3 and 0x159 bit3 is the same
        3. Modify 0x1EE typeing error
    Solution:

    v0.04  14:00PM  2012/12/22  Paul lee
    Reason:
        1. ATTRx Start form 1 by define order,singal attr without x
        2. Read only register renaming with info replace attr

    Solution:

    v0.06  10:33AM  2012/12/24 Paul lee
    Reason:
        1. Base on 1618C V8
    Solution:

    v0.07 13:30PM  2012/12/26     Paul lee
    Reason:
        1. To revise VSYNC and TOUT2 for UART TxD (R0F1, R0F2).
        2. To revise R177 bit7
    Solution:

    v0.08  16:13PM  2012/12/27 Paul lee
    Reason:
        1. To revise IR define
        2. T0 revise R16F
    Solution:

    v0.09  10:43AM  2012/12/28
    Reason:
        1. To revise OSD R105 Palette define
        2. To revise DMA R16F ,IR R178,R179
    Solution:

    v0.10  13:52PM  20132/01/04
    Reason:
        1. To revise AOSD R162  , RF2
    Solution:

    v0.11  03:29PM  2013/01/07 Jack Su
    Reason:
        1. To revise BITEK_16F_DMA_ATTR BITEK_165_DMA_SPEED definitions.
    Solution:

    v0.12 11:40AM  2013/01/10 Jeffrey Chang
    Reason:
        1. To comment memory mapping.
    Solution:

    v0.13    14:23PM  2013/01/17  Paul lee
    Reason:
        1. To Revise SFR 0x95
    Solution:

    v0.14    17:39PM  2013/01/25  Paul lee
    Reason:
        1. To Revise AOSD
    Solution:

    v0.15    11:33AM  2013/02/19  Paul lee
    Reason:
        1. To Revise for datasheet A0 (R013 ,R092,R0A5,R0D5,R0E0)
    Solution:

   ----------------------------------------------------------------------
    v0.16 07:43PM  2013/03/16 Jeffrey Chang
    Reason:
        1. To fix register 0x182[7:5] typos.
    Solution:

   ----------------------------------------------------------------------
    v0.17 02:31PM  2013/03/23 Jeffrey Chang
    Reason:
        1. To support Keil C51 and A51 both.
    Solution:

   ********************************************************************** */


#ifndef _BIT1618C_H_
#define _BIT1618C_H_


/* ------------------------------------
    Header Files
   ------------------------------------ */


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _BIT1618C_C_
    #define EXTERN
#else
    #define EXTERN extern
#endif


#ifdef  __A51__

; ------------------------------------------------------------------------------
;   Byte-Addressable SFR
; ------------------------------------------------------------------------------
#define IDA                 0x94    /* (BIT1618C) Indirect Address                               */
#define CHIP_FLAG           0x95    /* (BIT1618C) Chip Status Flag                               */
#define P0MOD               0xA4    /* (BIT1618C) P0 MODE (0=Open Drain, 1=Push-Pull) @RIN Port  */
#define P1MOD               0xA5    /* (BIT1618C) P1 MODE (0=Open Drain, 1=Push-Pull) @GIN Port  */
#define P2MOD               0xA6    /* (BIT1618C) P2 MODE (0=Open Drain, 1=Push-Pull) @BIN Port  */
#define P3MOD               0xA7    /* (BIT1618C) P3 MODE (0=Open Drain, 1=Push-Pull) @TOUT Port */


; ------------------------------------------------------------------------------
;   Bit-Addressable SFR
; ------------------------------------------------------------------------------
#define TR2                 0xCA

; SFR
#define T2CON               0xC8
#define RCAP2L              0xCA
#define RCAP2H              0xCB
#define TL2                 0xCC
#define TH2                 0xCD

#endif  // __A51__



#ifdef  __C51__

/*  BYTE Registers  */
sfr P0      = 0x80;     // Port 0
sfr P1      = 0x90;     // Port 1
sfr P2      = 0xA0;     // Port 2
sfr P3      = 0xB0;     // Port 3


sfr SP      = 0x81;     // Stack Pointer

sfr DPL     = 0x82;     // Data Pointer Low
sfr DPH     = 0x83;     // Data Pointer high

sfr PCON    = 0x87;     // Power Control

sfr TCON    = 0x88;     // Timer Control
sfr TMOD    = 0x89;     // Timer Mode
sfr TL0     = 0x8A;     // Timer 0 Low
sfr TL1     = 0x8B;     // Timer 1 Low
sfr TH0     = 0x8C;     // Timer 0 High
sfr TH1     = 0x8D;     // Timer 1 High


sfr SCON    = 0x98;     // Serial Control
sfr SBUF    = 0x99;     // Serial Data Buffer


sfr IE      = 0xA8;     // Interrupt Enable
sfr IP      = 0xB8;     // Interrupt Priority


sfr PSW     = 0xD0;     // Program Status Word
sfr ACC     = 0xE0;     // Accumulator
sfr B       = 0xF0;     // B register

sfr IDA         = 0x94;     // (BIT1618C) Indirect Address
sfr CHIP_FLAG   = 0x95;     // (BIT1618C) Chip Status Flag
sfr P0MOD       = 0xA4;     // (BIT1618C) P0 MODE (0=Open Drain, 1=Push-Pull) @RIN Port
sfr P1MOD       = 0xA5;     // (BIT1618C) P1 MODE (0=Open Drain, 1=Push-Pull) @GIN Port
sfr P2MOD       = 0xA6;     // (BIT1618C) P2 MODE (0=Open Drain, 1=Push-Pull) @BIN Port
sfr P3MOD       = 0xA7;     // (BIT1618C) P3 MODE (0=Open Drain, 1=Push-Pull) @TOUT Port


/* /// 8052 Extensions /// */
sfr T2CON   = 0xC8;     // Timer 2 Control
//sfr T2MOD = 0xC9;     // Timer 2 Mode Control
sfr RCAP2L  = 0xCA;     // Timer 2 Capture Low
sfr RCAP2H  = 0xCB;     // Timer 2 Capture High
sfr TL2     = 0xCC;     // Timer 2 Low
sfr TH2     = 0xCD;     // Timer 2 High


/*  BIT Registers  */

/*  TCON  */
sbit TF1    = 0x8F;
sbit TR1    = 0x8E;
sbit TF0    = 0x8D;
sbit TR0    = 0x8C;
sbit IE1    = 0x8B;
sbit IT1    = 0x8A;
sbit IE0    = 0x89;
sbit IT0    = 0x88;

/* Bit Register */
sbit P0_0   = 0x80;
sbit P0_1   = 0x81;
sbit P0_2   = 0x82;
sbit P0_3   = 0x83;
sbit P0_4   = 0x84;
sbit P0_5   = 0x85;
sbit P0_6   = 0x86;
sbit P0_7   = 0x87;

sbit P1_0   = 0x90;
sbit P1_1   = 0x91;
sbit P1_2   = 0x92;
sbit P1_3   = 0x93;
sbit P1_4   = 0x94;
sbit P1_5   = 0x95;
sbit P1_6   = 0x96;
sbit P1_7   = 0x97;

/*  T2  */
sbit T2EX   = 0x91;
sbit T2     = 0x90;

/*  SCON  */
sbit RI     = 0x98;
sbit TI     = 0x99;
sbit RB8    = 0x9A;
sbit TB8    = 0x9B;
sbit REN    = 0x9C;
sbit SM2    = 0x9D;
sbit SM1    = 0x9E;
sbit SM0    = 0x9F;

/*  P2  */
sbit P2_0   = 0xA0;
sbit P2_1   = 0xA1;
sbit P2_2   = 0xA2;
sbit P2_3   = 0xA3;
sbit P2_4   = 0xA4;
sbit P2_5   = 0xA5;
sbit P2_6   = 0xA6;
sbit P2_7   = 0xA7;

/*  IE  */
sbit EX0    = 0xA8;
sbit ET0    = 0xA9;
sbit EX1    = 0xAA;
sbit ET1    = 0xAB;
sbit ES     = 0xAC;
sbit ET2    = 0xAD;
sbit EA     = 0xAF;

/*  P3  */
sbit P3_0   = 0xB0;
sbit P3_1   = 0xB1;
sbit P3_2   = 0xB2;
sbit P3_3   = 0xB3;
sbit P3_4   = 0xB4;
sbit P3_5   = 0xB5;
sbit P3_6   = 0xB6;
sbit P3_7   = 0xB7;

/*  P3  */
sbit RXD    = 0xB0;
sbit TXD    = 0xB1;
sbit INT0   = 0xB2;
sbit INT1   = 0xB3;
sbit T0     = 0xB4;
sbit T1     = 0xB5;
sbit WR     = 0xB6;
sbit RD     = 0xB7;


/* XICON */
sbit IT2    = 0xC0;     // External interrupt 2 is falling-edge/low-level
sbit IE2    = 0xC1;
sbit EX2    = 0xC2;     // External interrupt 2 enable
sbit PX2    = 0xC3;     // External interrupt 2
sbit IT3    = 0xC4;     // External interrupt 3 is falling-edge/low-level
sbit IE3    = 0xC5;
sbit EX3    = 0xC6;     // External interrupt 3 enable
sbit PX3    = 0xC7;     // External interrupt 3

/*  T2CON  */
sbit CP_RL2 = 0xC8;
sbit C_T2   = 0xC9;         // C/nT2
sbit TR2    = 0xCA;
sbit EXEN2  = 0xCB;
sbit TCLK   = 0xCC;
sbit RCLK   = 0xCD;
sbit EXF2   = 0xCE;
sbit TF2    = 0xCF;

/*  PSW  */
sbit P      = 0xD0;
sbit OV     = 0xD2;
sbit RS0    = 0xD3;
sbit RS1    = 0xD4;
sbit F0     = 0xD5;
sbit AC     = 0xD6;
sbit CY     = 0xD7;

#define DMA_BUSY       (CHIP_FLAG & 0x01)
#define RESET_MODE     (CHIP_FLAG & 0x02)   // 0: Hw reset 1:Sw reset
#define WDT_MODE       (CHIP_FLAG & 0x04)   // 0: Normal   1:Watchdog reset

#define SW_RESET       0x00
#define HW_RESET       0x02
#define WDT_RESET      0x04

#endif // __C51__


/* ::::::::::::::::::::::::::::::::::::
    BITEK Configuration
   :::::::::::::::::::::::::::::::::::: */

// [1] Version Control
#define BITEK_000_HW_VER_INFO                   0x000       // [1] Hardware version
    #define BITEK_MASK_HW_VER                         0xB3    // 7 6 5 4 3 2 1 0
    #define BITEK_MASK_PRODUCT_VER_O                  0x03    // | | | | | | |_|_ Product Version
    #define BITEK_MASK_PRODUCT_NUM_O                  0x1C    // | | | |_|_|_____ Product Number
    #define BITEK_MASK_PRODUCT_GROUP_O                0xE0    // |_|_|___________ Product Group
                                                            // 1 0 1 1 0 0 1 0  0xB2

#define BITEK_001_SW_VER                        0x001       // [1] Software version

// [1] Interrupt Function
#define BITEK_002_INT0_FLAG_O                   0x002       // [1] Interrupt Flag for INT0
    #define BITEK_MASK_FLAG0_VD_SIGNALREADY         0x01    // Video Decoder Signal ready
    #define BITEK_MASK_FLAG0_VP_SIGNALREADY         0x02    // Video Processor Signal ready
    #define BITEK_MASK_FLAG0_VIDEO_ADC              0x04    // Video ADC changes
    #define BITEK_MASK_FLAG0_VD_MV                  0x08    // Video Decoder Macrovision detection
    #define BITEK_MASK_FLAG0_VD_CC_I2CM             0x10    // Video Decoder CC detection/I2C Master
    #define BITEK_MASK_FLAG0_ADC                    0x20    // ADC interface function
    #define BITEK_MASK_FLAG0_IR_I2CS                0x40    // IR/I2C Slave  function
    #define BITEK_MASK_FLAG0_GPI                    0x80    // GPI function

#define BITEK_003_INT0_MASK                     0x003       // [1] Interrupt Mask for INT0
    #define BITEK_MASK_MASK0_VD_SIGNALREADY         0x01    // (0=Enable Interrupt, 1=Disable Interrupt)
    #define BITEK_MASK_MASK0_VP_SIGNALREADY         0x02
    #define BITEK_MASK_MASK0_VIDEO_ADC              0x04
    #define BITEK_MASK_MASK0_VD_MV                  0x08
    #define BITEK_MASK_MASK0_VD_CC_I2CM             0x10
    #define BITEK_MASK_MASK0_ADC                    0x20
    #define BITEK_MASK_MASK0_IR_I2CS                0x40
    #define BITEK_MASK_MASK0_GPI                    0x80

#define BITEK_004_INT0_ACK                      0x004       // [1] Interrupt ACK for INT0
    #define BITEK_MASK_ACK0_VD_SIGNALREADY          0x01    // (0=Clear and Disable Interrupt, 1=Enable Interrupt)
    #define BITEK_MASK_ACK0_VP_SIGNALREADY          0x02
    #define BITEK_MASK_ACK0_VIDEO_ADC               0x04
    #define BITEK_MASK_ACK0_VD_MV                   0x08
    #define BITEK_MASK_ACK0_VD_CC_I2CM              0x10
    #define BITEK_MASK_ACK0_ADC                     0x20
    #define BITEK_MASK_ACK0_IR_I2CS                 0x40
    #define BITEK_MASK_ACK0_GPI                     0x80

#define BITEK_005_INT1_FLAG_O                   0x005       // [1] Interrupt Flag for INT1
    #define BITEK_MASK_FLAG1_VD_NOSIGNAL            0x01    // Video Decoder No Signal
    #define BITEK_MASK_FLAG1_VP_NOSIGNAL            0x02    // Video Processor No Signal
    #define BITEK_MASK_FLAG1_VP_MODE                0x04    // Video Processor Mode change detection
    #define BITEK_MASK_FLAG1_VD_STANDARD            0x08    // Video Decoder Standard change detection
    #define BITEK_MASK_FLAG1_LINE_BUFFER_I2CM       0x10    // Line Buffer error/I2C Master
    #define BITEK_MASK_FLAG1_ADC                    0x20    // ADC interface function
    #define BITEK_MASK_FLAG1_IR_I2CS                0x40    // IR/I2CS function
    #define BITEK_MASK_FLAG1_GPI                    0x80    // GPI function

#define BITEK_006_INT1_MASK                     0x006       // [1] Interrupt Mask for INT1
    #define BITEK_MASK_MASK1_VD_NOSIGNAL            0x01    // (0=Enable Interrupt, 1=Disable Interrupt)
    #define BITEK_MASK_MASK1_VP_NOSIGNAL            0x02
    #define BITEK_MASK_MASK1_VP_MODE                0x04
    #define BITEK_MASK_MASK1_VD_STANDARD            0x08
    #define BITEK_MASK_MASK1_LINE_BUFFER_I2CM       0x10
    #define BITEK_MASK_MASK1_ADC                    0x20
    #define BITEK_MASK_MASK1_IR_I2CS                0x40
    #define BITEK_MASK_MASK1_GPI                    0x80

#define BITEK_007_INT1_ACK                      0x007       // [1] Interrupt ACK for INT1
    #define BITEK_MASK_ACK1_VD_NOSIGNAL             0x01    // (0=Clear and Disable Interrupt, 1=Enable Interrupt)
    #define BITEK_MASK_ACK1_VP_NOSIGNAL             0x02
    #define BITEK_MASK_ACK1_VP_MODE                 0x04
    #define BITEK_MASK_ACK1_VD_STANDARD             0x08
    #define BITEK_MASK_ACK1_LINE_BUFFER_I2CM        0x10
    #define BITEK_MASK_ACK1_ADC                     0x20
    #define BITEK_MASK_ACK1_IR_I2CS                 0x40
    #define BITEK_MASK_ACK1_GPI                     0x80

#define BITEK_008_INT_ATTR                      0x008       // [1] Interrupt Attribute
    #define BITEK_MASK_INT0_POL                     0x01    // Interrupt POLARITY for INT0 (0=High level or Rising edge active, 1=Low level or Falling edge active)
    #define BITEK_MASK_INT0_TYPE                    0x02    // Interrupt TYPE for INT0 (0=Edge type , 1=Level type )
    #define BITEK_MASK_INT1_POL                     0x04    // Interrupt POLARITY for INT1 (0=High level or Rising edge active, 1=Low level or Falling edge active)
    #define BITEK_MASK_INT1_TYPE                    0x08    // Interrupt TYPE for INT1 (0=Edge type , 1=Level type )
    #define BITEK_MASK_INT_CHT_SEL0                 0x10    // Video ADC change detection (0=Disable, 1=Enable) AIN11
    #define BITEK_MASK_INT_CHT_SEL1                 0x20    // Video ADC change detection (0=Disable, 1=Enable) AIN12
    #define BITEK_MASK_INT_CHT_SEL2                 0x40    // Video ADC change detection (0=Disable, 1=Enable) AIN2
    #define BITEK_MASK_INT_CHT_SEL                  0x70    // Video ADC change detection (0=Disable, 1=Enable)
    #define BITEK_MASK_ADCINT_TYPE                  0x80    // ADC interface interrupt type (0=Edge trigger, 1=Level trigger)

#define BITEK_009_INT_SEL                       0x009       // [1] Interrupt Selection
    #define BITEK_MASK_INT0_ISR6_SEL                0x07
    #define BITEK_MASK_INT0_ISR6_IR                 0x00    // IR
    #define BITEK_MASK_INT0_ISR6_SWR                0x01    // S+W+R
    #define BITEK_MASK_INT0_ISR6_SR                 0x02    // S+R
    #define BITEK_MASK_INT0_ISR6_SW                 0x03    // S+W
    #define BITEK_MASK_INT0_ISR6_R                  0x04    // R
    #define BITEK_MASK_INT0_ISR6_W                  0x05    // W
    #define BITEK_MASK_INT0_ISR6_S                  0x06    // Start
    #define BITEK_MASK_INT0_ISR6_P                  0x07    // Stop

    #define BITEK_MASK_INT1_ISR6_SEL                0x38
    #define BITEK_MASK_INT1_ISR6_IR                 0x00    // IR
    #define BITEK_MASK_INT1_ISR6_SWR                0x08    // S+TX+RX
    #define BITEK_MASK_INT1_ISR6_SR                 0x10    // S+RX
    #define BITEK_MASK_INT1_ISR6_SW                 0x18    // S+TX
    #define BITEK_MASK_INT1_ISR6_R                  0x20    // RX
    #define BITEK_MASK_INT1_ISR6_W                  0x28    // TX
    #define BITEK_MASK_INT1_ISR6_S                  0x30    // Start
    #define BITEK_MASK_INT1_ISR6_P                  0x38    // Stop

    #define BITEK_MASK_INT0_ISR4_SEL                0x40
    #define BITEK_MASK_INT1_ISR4_SEL                0x80

// [1] Clock Domain Systems
#define BITEK_00A_CLK_ATTR0                     0x00A       // [1]
    #define BITEK_MASK_LCLK_SEL                     0x07    // LCLK Clock Domain Source Select
    #define BITEK_MASK_LCLK_POL                     0x08    // LCLK Clock Domain Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_LCLK_EN                      0x10    // LCLK Clock Domain Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_XCLK_SEL                     0xE0    // XCLK Clock Domain Source Select (XCLK=OSCCLK/2 ^ XCLK_SEL)

#define BITEK_00B_CLK_ATTR1                     0x00B       // [1]
    #define BITEK_MASK_OCLK_SEL                     0x01    // OCLK Clock Output Selcect
    #define BITEK_MASK_OCLK_POL                     0x02    // OCLK Clock Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_TCLK_PRESEL                  0x0C    // TCLK Pre-division Factor
    #define BITEK_MASK_TCLK_SEL                     0x30    // TCLK Clock Domain Source Select
    #define BITEK_MASK_TCLK_POL                     0x40    // TCLK Clock Domain Polarity
    #define BITEK_MASK_TCLK_EN                      0x80    // TCLK Clock Domain Enable

#define BITEK_00C_CLK_ATTR2                     0x00C       // [1]
    #define BITEK_MASK_MCLK_SEL                     0x03    // MCLK Clock Domain Source Select
    #define BITEK_MASK_MCLK_POL                     0x04    // MCLK Clock Domain Polarity
    #define BITEK_MASK_MCLK_EN                      0x08    // MCLK Clock Domain Enable
    #define BITEK_MASK_PCLK_SEL                     0x30    // PCLK Clock Domain Source Select
    #define BITEK_MASK_PCLK_POL                     0x40    // PCLK Clock Domain Polarity
    #define BITEK_MASK_PCLK_EN                      0x80    // PCLK Clock Domain Enable

#define BITEK_00D_CLK_ATTR3                     0x00D       // [1]
    #define BITEK_MASK_DVPCLK_EN                    0x01    // DVP Clock Domain Enable
    #define BITEK_MASK_DVPCLK_SEL3                  0x02
    #define BITEK_MASK_DVPCLK_POL                   0x04    // DVP Clock Domain Polarity
    #define BITEK_MASK_AFECLK_EN                    0x08    // AFE Clock Domain Enable
    #define BITEK_MASK_AFECLK_SEL                   0x10    // AFE Clock Domain Clock Source Select (0=27MHz, 1=13.5MHz)
    #define BITEK_MASK_AFECLK_POL                   0x20    // AFE Clock Domain Polarity
    #define BITEK_MASK_AFEBUF_SEL                   0x40    // AFE Buffer Clock Domain Clock Source Select (0=DVPCLK, 1=AFECLK))
    #define BITEK_MASK_AFEBUF_POL                   0x80    // AFE Buffer Clock Domain Polarity

#define BITEK_00E_CLK_ATTR4                     0x00E       // [1]
    #define BITEK_MASK_DVPCLK_SEL1                  0x01    // DVP Clock Domain 1 Clock Source Select (0=DVPCLK2, 1=AFE clock)
    #define BITEK_MASK_DVPCLK_SEL2                  0x02    // DVP Clock Domain 2 Clock Source Select (0=PLL, 1=ICLK1)
    #define BITEK_MASK_VDOSCCLK_POL                 0x04
    #define BITEK_MASK_VDOSCCLK_EN                  0x08
    #define BITEK_MASK_BCLK_POL                     0x10
    #define BITEK_MASK_BCLK_SEL                     0x20
    #define BITEK_MASK_OSDCLK_POL                   0x40    // OSD Clock Polarity
    #define BITEK_MASK_OSDCLK_EN                    0x80    // OSD Clock Enable

// [1] SARADC Data Interface
#define BITEK_00F_SARCLK_ATTR                   0x00F
    #define BITEK_MASK_SARCLK_DIV                   0x3F    // SARADC Clock Divider
    #define BITEK_MASK_SARCLK_POL                   0x40    // SARADC Clock Polarity
    #define BITEK_MASK_SARCLK_EN                    0x80    // SARADC Clock Enable

#define BITEK_010_M8051_FLASHBANK               0x010

// M8051 Debug
#define BITEK_011012_M8051_BREAK                0x011
#define BITEK_011_M8051_BREAK_MSB               0x011
#define BITEK_012_M8051_BREAK_LSB               0x012

#define BITEK_013_M8051_BREAKx                  0x013
    #define BITEK_MASK_M8051_BREAKx_TYPE            0x03
    #define BITEK_MASK_M8051_BREAKx_EN              0x04
    #define BITEK_MASK_M8051_STOP                   0x10
    #define BITEK_MASK_M8051_WDT_REGSRST            0x20
    #define BITEK_MASK_M8051_WDT_OSDSRST            0x40
    #define BITEK_MASK_M8051_WDT_BSRST              0x80

#define BITEK_014_M8051_ICACHE                  0x014
    #define BITEK_MASK_M8051_ICACHE_BANK            0x1F
    #define BITEK_MASK_M8051_ICACHE_EN              0x20
    #define BITEK_MASK_M8051_ICACHE_UPDATE          0x40
    #define BITEK_MASK_M8051_ICACHE_RELOAD          0x80

#define BITEK_015_M8051_WATCH                   0x015
    #define BITEK_MASK_M8051_XWATCHMODE             0x03
    #define BITEK_MASK_M8051_IWATCHMODE             0x0C
    #define BITEK_MASK_M8051_XRAM_BANK              0x30
    #define BITEK_MASK_M8051_BREAK_SEL              0xC0

#define BITEK_016_M8051_ATTR                    0x016
    #define BITEK_MASK_M8051_RELEASE                0x01
    #define BITEK_MASK_M8051_SBREAK                 0x02
    #define BITEK_MASK_REGS_CKEN                    0x04    // Register Set Clock Enable
    #define BITEK_MASK_M8051_RESET                  0x08    // 1-reset 0-run  Toggle trigger
    #define BITEK_MASK_INF_SFREN                    0x10    // 1=SFR or 0=IRAM
    #define BITEK_MASK_SOFT_OP5_EN                  0x20
    #define BITEK_MASK_M8051_STEP                   0x40
    #define BITEK_MASK_M8051_DEBUG                  0x80

#define BITEK_017_M8051_WDT_ATTR                0x017
    #define BITEK_MASK_M8051_WDT                    0x7F
    #define BITEK_MASK_M8051_WDT_EN                 0x80


// [1] Panel Timing Setup (OUTPUT)
#define BITEK_01801B_OS_XP                      0x018       // PANEL HSYNC Pulse Width [1]13
#define BITEK_01901B_OS_XS                      0x019       // PANEL Active Window Horizontal Start Position
#define BITEK_01A01B_OS_XW                      0x01A       // PANEL Active Window Horizontal End   Position
#define BITEK_01B_OS_X_MSB                      0x01B
    #define BITEK_MASK_OS_XP_MSB                    0x01
    #define BITEK_MASK_OS_XS_MSB                    0x02
    #define BITEK_MASK_OS_XW_MSB                    0x70

#define BITEK_01C01E_OS_XT_M0                   0x01C       // PANEL Horizontal Total Length Mode 0
#define BITEK_01D01E_OS_XT_M1                   0x01D       // PANEL Horizontal Total Length Mode 1
#define BITEK_01E_OS_XT_MSB                     0x01E
    #define BITEK_MASK_OS_XT_M0_MSB                 0x07
    #define BITEK_MASK_OS_XT_M1_MSB                 0x70

#define BITEK_01F_OS_YP                         0x01F       // PANEL VSYNC Pulse Width
#define BITEK_020_OS_YS                         0x020       // PANEL Active Window Vertical Start Position
#define BITEK_021023_OS_YW                      0x021       // PANEL Active Window Vertical End   Position
#define BITEK_022023_OS_YT                      0x022       // PANEL Vertical Total Length

// [1] Special Timing Adjustment
#define BITEK_023_ATTR                          0x023
    #define BITEK_MASK_OS_YW_MSB                    0x03
    #define BITEK_MASK_OS_YT_MSB                    0x0C
    #define BITEK_MASK_PROTECT_EN                   0x10    // Minimum Output Lines protection
    #define BITEK_MASK_SYNCO_MODE                   0x20    // Two-Field Synchronization mode select
    #define BITEK_MASK_SYNCO_EN                     0x40    // Sync with input VSYNC Enable

// [1] Output Data Path
#define BITEK_024_OUTPUT_ATTR                   0x024       // Output data path
    #define BITEK_MASK_ROUT_ROT                     0x03    // R Data Rotation
    #define BITEK_MASK_GOUT_ROT                     0x0C    // G Data Rotation
    #define BITEK_MASK_BOUT_ROT                     0x30    // B Data Rotation

#define BITEK_025_OUTPUT_ATTR1                  0x025
    #define BITEK_MASK_ROUT_POL                     0x01    // R Data output Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_GOUT_POL                     0x02    // G Data output Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_BOUT_POL                     0x04    // B Data output Polarity (0=Normal, 1=Invert)
//  #define BITEK_MASK_OCLK_POL                     0x08    // Output Clock Polarity (0=Normal, 1=Invert)
//  #define BITEK_MASK_OCLK_SEL                     0x10    // Output Clock Select [1]15
    #define BITEK_MASK_SERILA_MODE                  0x80    // Serial Mode

#define BITEK_026_OUTPUT_ATTR2                  0x026
    #define BITEK_MASK_DLYE_OR                      0x03    // R Channel Output delay n clocks on SWAP source=0
    #define BITEK_MASK_DLYE_OG                      0x0C    // G Channel Output delay n clocks on SWAP source=0
    #define BITEK_MASK_DLYE_OB                      0x30    // B Channel Output delay n clocks on SWAP source=0

#define BITEK_027_OUTPUT_ATTR3                  0x027
    #define BITEK_MASK_DLYO_OR                      0x03    // R Channel Output delay n clocks on SWAP source=1
    #define BITEK_MASK_DLYO_OG                      0x0C    // G Channel Output delay n clocks on SWAP source=1
    #define BITEK_MASK_DLYO_OB                      0x30    // B Channel Output delay n clocks on SWAP source=1
    #define BITEK_MASK_DLY_MODE                     0x80    // Delay Mode select

#define BITEK_028_OUTPUT_ATTR4                  0x028
    #define BITEK_MASK_SWAPE_OGB                    0x01    // G data output swap with B data output on SWAP source=0 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPE_ORG                    0x02    // R data output swap with G data output on SWAP source=0 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPE_ORB                    0x04    // R data output swap with B data output on SWAP source=0 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPO_OGB                    0x08    // G data output swap with B data output on SWAP source=1 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPO_ORG                    0x10    // R data output swap with G data output on SWAP source=1 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAPO_ORB                    0x20    // R data output swap with B data output on SWAP source=1 (0=Disable, 1=Enable)
    #define BITEK_MASK_SWAP_SRC                     0x80    // Even/Odd Swap source (0=Q2H, 1= VCOM)

// 0x29: NONE

// [1] TCON Function
#define BITEK_02A02C_STH_START                  0x02A       // STH Signal Start[7:0]
#define BITEK_02B02C_STH_END                    0x02B       // STH Signal End[7:0]
#define BITEK_02C_STH_MSB                       0x02C       // STH MSB
    #define BITEK_MASK_STH_END_MSB                  0x07    // STH Signal End[10:8]
    #define BITEK_MASK_STH_START_MSB                0x70    // STH Signal Start[10:8]

#define BITEK_02D02F_LD_START                   0x02D       // LD Signal Start[7:0]
#define BITEK_02E02F_LD_END                     0x02E       // LD Signal End[7:0]
#define BITEK_02F_LD_MSB                        0x02F       // LD MSB
    #define BITEK_MASK_LD_END_MSB                   0x07    // LD Signal End[10:8]
    #define BITEK_MASK_LD_START_MSB                 0x70    // LD Signal Start[10:8]

#define BITEK_030032_CKV_START                  0x030       // CKV Signal Start[7:0]
#define BITEK_031032_CKV_END                    0x031       // CKV Signal End[7:0]
#define BITEK_032_CKV_MSB                       0x032       // CKV MSB
    #define BITEK_MASK_CKV_END_MSB                  0x07    // CKV Signal End[10:8]
    #define BITEK_MASK_CKV_START_MSB                0x70    // CKV Signal Start[10:8]

#define BITEK_033035_OEH_START                  0x033       // OEH Signal Start[7:0]
#define BITEK_034035_OEH_END                    0x034       // OEH Signal End[7:0]
#define BITEK_035_OEH_MSB                       0x035       // OEH MSB
    #define BITEK_MASK_OEH_END_MSB                  0x07    // OEH Signal End[10:8]
    #define BITEK_MASK_OEH_START_MSB                0x38    // OEH Signal Start[10:8]
    #define BITEK_MASK_Q2H_SEL                      0xC0    // Q2H Signal select

#define BITEK_036039_VCOM_SHIFT                 0x036       // VCOM Shift
#define BITEK_037039_STV_START                  0x037       // STV Signal Start[7:0]
#define BITEK_038039_STV_END                    0x038       // STV Signal End[7:0]
#define BITEK_039_STV_MSB                       0x039       // STV MSB
    #define BITEK_MASK_STV_END_MSB                  0x03    // STV Signal End[9:8]
    #define BITEK_MASK_STV_START_MSB                0x0C    // STV Signal Start[9:8]
    #define BITEK_MASK_VCOM_SHIFT_MSB               0x70    // VCOM Shift[10:8]
    #define BITEK_MASK_VCOM_OUT                     0x80

#define BITEK_03A_TCON_POL                      0x03A       // TCON Polarity
    #define BITEK_MASK_CKV_POL                      0x01    // CKV Polarity
    #define BITEK_MASK_STV_POL                      0x02    // STV Polarity
    #define BITEK_MASK_STH_POL                      0x04    // STH Polarity
    #define BITEK_MASK_LD_POL                       0x08    // LD  Polarity
    #define BITEK_MASK_FRP_POL                      0x10    // FRP Polarity
    #define BITEK_MASK_OEH_POL                      0x20    // OEH Polarity
    #define BITEK_MASK_OEH_GATE                     0x40    // OEH gated with output data Enable
    #define BITEK_MASK_PREFRP_MODE                  0x80    // PRE-FRP Mode select

#define BITEK_03B_TCON_ATTR0                    0x03B       // TCON Attribute0
    #define BITEK_MASK_STV_SEL                      0x01    // STV Output Select
    #define BITEK_MASK_STH_SEL                      0x02    // STH Output Select
    #define BITEK_MASK_TCON_UD                      0x04    // TCON U/D
    #define BITEK_MASK_TCON_RL                      0x08    // TCON R/L
    #define BITEK_MASK_Q2H_POL                      0x10    // Q2H  Output Polarity
    #define BITEK_MASK_LTPS_MODE                    0x20    // LTPS Mode select
    #define BITEK_MASK_Q2H_MODE                     0x40    // Q2H  Mode select
//  #define BITEK_MASK_DOTINV_EN                    0x80    // Dot Invert Mode enable

// [1] TCON Clock Mode
#define BITEK_03C_TCON_ATTR1                    0x03C       // TCON Attribute1
    #define BITEK_MASK_CPH1E_CLK_SEL                0x03    // CPH1 Clock type selection on SWAP source=0
    #define BITEK_MASK_CPH2E_CLK_SEL                0x0C    // CPH2 Clock type selection on SWAP source=0
    #define BITEK_MASK_CPH3E_CLK_SEL                0x30    // CPH3 Clock type selection on SWAP source=0
    #define BITEK_MASK_VCOM_TYPE                    0xC0    // VCOM Signal Type

#define BITEK_03D_TCON_ATTR2                    0x03D       // TCON Attribute2
    #define BITEK_MASK_CPH1O_CLK_SEL                0x03    // CPH1 Clock type selection on SWAP source=1
    #define BITEK_MASK_CPH2O_CLK_SEL                0x0C    // CPH2 Clock type selection on SWAP source=1
    #define BITEK_MASK_CPH3O_CLK_SEL                0x30    // CPH3 Clock type selection on SWAP source=1
    #define BITEK_MASK_BUS_INV                      0xC0    // Data Bus Control on FRP

#define BITEK_03E_TCON_ATTR3                    0x03E       // TCON Attribute3
    #define BITEK_MASK_CPH1_EN                      0x01    // CPH1 output Enable
    #define BITEK_MASK_CPH2_EN                      0x02    // CPH2 output Enable
    #define BITEK_MASK_CPH3_EN                      0x04    // CPH3 output Enable
    #define BITEK_MASK_CPH_HALF                     0x08    // TCON Clock output mode
    #define BITEK_MASK_CPH1_POL                     0x10    // CPH1 Polarity
    #define BITEK_MASK_CPH2_POL                     0x20    // CPH2 Polarity
    #define BITEK_MASK_CPH3_POL                     0x40    // CPH3 Polarity
//  #define BITEK_MASK_DOTINV_SEL                   0x80    // Dot Invert Mode Select

// [1] Background 1 and Test Pattern Setup
// [1] Background 2
#define BITEK_03F_R_ATTR                        0x03F
    #define BITEK_MASK_TESTPAT_R                    0x3F    // Test Pattern RED Color
    #define BITEK_MASK_BG2_R                        0xC0    // Background 2's R color for 4:3 display

#define BITEK_040_G_ATTR                        0x040
    #define BITEK_MASK_TESTPAT_G                    0x3F    // Test Pattern GREEN Color
    #define BITEK_MASK_BG2_G                        0xC0    // Background 2's G color for 4:3 display

#define BITEK_041_B_ATTR                        0x041
    #define BITEK_MASK_TESTPAT_B                    0x3F    // Test Pattern BLUE Color
    #define BITEK_MASK_BG2_B                        0xC0    // Background 2's B color for 4:3 display

#define BITEK_042_TESTPAT_ATTR                  0x042       // Test Pattern Attribute
    #define BITEK_MASK_TESTPAT_RATIO                0x3F    // Test Pattern Ratio
    #define BITEK_MASK_BACKGROUND_EN                0x40    // Background Mode Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_FREERUN_EN                   0x80    // Free-Run Mode Enable (0=Disable, 1=Enable)

// [1] Auto Blank Screen
#define BITEK_043_AUTOON                        0x043       // Auto Blank
    #define BITEK_MASK_AUTOON_TIME                  0x7F    // Blank Screen to Normal Screen delay
    #define BITEK_MASK_AUTOON_EN                    0x80    // Blank Screen (0=Disable, 1=Enable)

#define BITEK_044_AUTOOFF_TIME                  0x044       // No Signal to Blank screen delay
    #define BITEK_MASK_AUTOOFF_TIME                 0x1F
    #define BITEK_MASK_AUTOON_MODECHG               0x20
    #define BITEK_MASK_AUTOON_NOSIGNAL              0x40
    #define BITEK_MASK_AUTOON_EVEN                  0x80

#define BITEK_045_HLCK_SEL                      0x045       // HLCK selection
    #define BITEK_MASK_NOSIG_SEL                    0x08    // Blank Screen Function Signal Selection (0=VP,1=VD)
    #define BITEK_MASK_PATTERN_TYPE                 0x30    // Test Pattern Type (00=Pure Color, 01=Ramp, 10=Grid, 11=Ramp)
    #define BITEK_MASK_PATTERN_SUBTYPE              0xC0    // Test Pattern Direction (0=Decrease, 1=Increae)

// [1] Input Image Window Setup (Input Windows)
#define BITEK_046048_IS_XS_M0                   0x046       // Input Window Horizontal Start Position Mode 0
#define BITEK_047048_IS_XW_M0                   0x047       // Input Window Horizontal End Position   Mode 0
#define BITEK_048_IS_X_M0_MSB                   0x048       // Input Window Horizontal                Mode 0
    #define BITEK_MASK_IS_XS_M0_MSB                 0x03
    #define BITEK_MASK_IS_XW_M0_MSB                 0xF0

#define BITEK_04904B_IS_YS_M0                   0x049       // Input Window Vertical Start Position   Mode 0
#define BITEK_04A04B_IS_YW_M0                   0x04A       // Input Window Vertical End Position     Mode 0
#define BITEK_04B_IS_Y_M0_MSB                   0x04B       // Input Window Vertical                  Mode 0
    #define BITEK_MASK_IS_YS_M0_MSB                 0x03
    #define BITEK_MASK_IS_YW_M0_MSB                 0x70

#define BITEK_04C04E_IS_XS_M1                   0x04C       // Input Window Horizontal Start Position Mode 1
#define BITEK_04D04E_IS_XW_M1                   0x04D       // Input Window Horizontal End Position   Mode 1
#define BITEK_04E_IS_X_M1_MSB                   0x04E       // Input Window Horizontal                Mode 1
    #define BITEK_MASK_IS_XS_M1_MSB                 0x03
    #define BITEK_MASK_IS_XW_M1_MSB                 0xF0

#define BITEK_04F051_IS_YS_M1                   0x04F       // Input Window Vertical Start Position   Mode 1
#define BITEK_050051_IS_YW_M1                   0x050       // Input Window Vertical End Position     Mode 1
#define BITEK_051_IS_Y_M1_MSB                   0x051       // Input Window Vertical                  Mode 1
    #define BITEK_MASK_IS_YS_M1_MSB                 0x03
    #define BITEK_MASK_IS_YW_M1_MSB                 0x70

// [1] Input Data Path Setup
#define BITEK_052_INPUT_DATAPATH                0x052       // Input Data Path
    #define BITEK_MASK_RIN_POL                      0x01    // R Data Input Polarity
    #define BITEK_MASK_GIN_POL                      0x02    // G Data Input Polarity
    #define BITEK_MASK_BIN_POL                      0x04    // B Data Input Polarity
    #define BITEK_MASK_RIN_ROT                      0x08    // R Data Rotation
    #define BITEK_MASK_GIN_ROT                      0x10    // G Data Rotation
    #define BITEK_MASK_BIN_ROT                      0x20    // B Data Rotation
    #define BITEK_MASK_IDE_SEL                      0xC0    // Input Data Enable Source Select


// [1] Input Format

// [1] Input Mode Selection
#define BITEK_053_INPUT_MODE                    0x053
    #define BITEK_MASK_IDE_POL                      0x02    // Input Data Enable Source Select
    #define BITEK_MASK_IHS_POL                      0x04    // External HS polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_IVS_POL                      0x08    // External VS polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_EVEN_SEL                     0x30    // EVEN/ODD Signal Selection
    #define BITEK_MASK_EXT_SYNC                     0xC0    // Sync source select

#define BITEK_054_INPUT_ATTR0                   0x054       // Input Data Path Attribute
    #define BITEK_MASK_ISWAP_RB                     0x01    // Swap R/B Data Bus
    #define BITEK_MASK_ISWAP_RG                     0x02    // Swap R/G Data Bus
    #define BITEK_MASK_ISWAP_GB                     0x04    // Swap G/B Data Bus
    #define BITEK_MASK_VD_PATH                      0x08    // Bus Select (0=External RGB, 1=VD)
    #define BITEK_MASK_SORT_656                     0x70    // Input format [1]26
    #define BITEK_MASK_VISUAL_TYPE                  0x80    // Visual EVEN/ODD Mode

#define BITEK_055_INPUT_ATTR1                   0x055       // Input Mode Attribute
    #define BITEK_MASK_SRC_SEL                      0x03    // Source Format Select
    #define BITEK_MASK_SWAP_UV                      0x04    // Swap U and V signal
    #define BITEK_MASK_IMODE                        0x08    // Input Mode Select
    #define BITEK_MASK_PCLK_BASE                    0x30
//  #define BITEK_MASK_PIXEL_MODE                   0x30    // Input Active Pixel Mode
    #define BITEK_MASK_RGB2YUV_EN                   0x40    // RGB to YUV color space convert enable
    #define BITEK_MASK_RGB2YUV_SEL                  0x80    // RGB to YUV color space convert select

// [1] Auto Switch
// [1] Auto Switch 2
#define BITEK_056_AUOTSWITCH                    0x056
    #define BITEK_MASK_AUTO_SWITCH                  0x01    // Auto Switch Mode (0=Manual, 1=Auto)
    #define BITEK_MASK_SWITCH_MODE                  0x02    // Switch Mode (0=Mode0, 1=Mode1)
    #define BITEK_MASK_AUTO_SWITCH2                 0x04    // Auto Switch Mode2 (0=Manual, 1=Auto)
    #define BITEK_MASK_SWITCH_MODE2                 0x08    // Switch Mode2 (0=Mode0, 1=Mode1)
    #define BITEK_MASK_AUTOSWITCH_SRC               0x10    // Auto Switch/Switch2 Source Select (0=Mode Type, 1=Video Decoder FIDT)
    #define BITEK_MASK_YUV2RGB_EN                   0x40    // YUV to RGB mode enable (0=Gamma, 1=Non-Gamma)
    #define BITEK_MASK_Y2R_SEL                      0x80    // YUV to RGB mode select (0=Gamma, 1=Non-Gamma)

// [1] Display Window Setup
#define BITEK_057059_PREDIS_ACTX_S0             0x057       // Display Window Pre-Scaling Active Horizontal Width for Switch2 Mode0
#define BITEK_058059_PREDIS_ACTX_S1             0x058       // Display Window Pre-Scaling Active Horizontal Width for Switch2 Mode1
#define BITEK_059_PREDIS_ACTX_MSB               0x059
    #define BITEK_MASK_PREDIS_ACTX_S0_MSB           0x03
    #define BITEK_MASK_PREDIS_ACTX_S1_MSB           0x30

#define BITEK_05A05C_DIS_XS_S0                  0x05A       // Display Window Horizontal Start Position for Switch2 Mode0
#define BITEK_05B05C_DIS_XW_S0                  0x05B       // Display Window Horizontal End   Position for Switch2 Mode0
#define BITEK_05C_DIS_X_S0_MSB                  0x05C
    #define BITEK_MASK_DIS_XS_S0_MSB                0x07
    #define BITEK_MASK_DIS_XW_S0_MSB                0x70

#define BITEK_05D05F_DIS_XS_S1                  0x05D       // Display Window Horizontal Start Position for Switch2 Mode1
#define BITEK_05E05F_DIS_XW_S1                  0x05E       // Display Window Horizontal End   Position for Switch2 Mode1
#define BITEK_05F_DIS_X_S1_MSB                  0x05F
    #define BITEK_MASK_DIS_XS_S1_MSB                0x07
    #define BITEK_MASK_DIS_XW_S1_MSB                0x70

#define BITEK_060062_DIS_YS                     0x060       // Display Window Vertical Start Position for Switch2 Mode1
#define BITEK_061062_DIS_YW                     0x061       // Display Window Vertical End   Position for Switch2 Mode1
#define BITEK_062_DIS_Y_MSB                     0x062
    #define BITEK_MASK_DIS_YW_MSB                   0x03
    #define BITEK_MASK_DIS_YS_MSB                   0x0C

#define BITEK_063065_DIS_XW1                    0x063       // Display Window Horizontal Width
#define BITEK_064065_DIS_XW2                    0x064       // Display Window Horizontal Width Zone 2
#define BITEK_065_DIS_XW_MSB                    0x065       // Display Window Attribute
    #define BITEK_MASK_DIS_XW1_MSB                  0x07
    #define BITEK_MASK_DIS_XW2_MSB                  0x70

// [1] Horizontal Scaling Down (PRESCX) Engine
#define BITEK_066069_PRESCX_START_S0            0x066       // HSD Start        for Switch2 Mode0
#define BITEK_067069_PRESCX_SHIFT_S0            0x067       // HSD Shift        for Switch2 Mode0
#define BITEK_06806A_PRESCX_FIX_S0              0x068       // HSD Fix          for Switch2 Mode0
#define BITEK_069_PRESCX_S0_MSB                 0x069       // HSD Attribute    for Switch2 Mode0
    #define BITEK_MASK_PRESCX_SHIFT_S0_MSB          0x07
    #define BITEK_MASK_PRESCX_START_S0_MSB          0xF0

#define BITEK_06A_PRESCX_S0_ATTR                0x06A       // HSD Attribute                            for Switch2 Mode0
    #define BITEK_MASK_PRESCX_EN_S0                 0x01    // HSD Enable (0=Bypass mode, 1=Scale mode) for Switch2 Mode0 [1]29
    #define BITEK_MASK_PRESCX_FILTER_EN_S0          0x02    // Filter Enable (0=Disable, 1=Enable)      for Switch2 Mode0 [1]29
    #define BITEK_MASK_PRESCX_FILTER_S0             0x04    // Filter Type (0=Bilinear, 1=Box)          for Switch2 Mode0 [1]29
    #define BITEK_MASK_PRESCX_FIX2_EN_S0            0x08    // Scale Down factor 2 Enable (0=Disable, 1=Enable) for Switch2 Mode0 [1]29
    #define BITEK_MASK_PRESCX_FIX_S0_MSB            0x30    // HSD Fix MSB                                      for Switch2 Mode0
    #define BITEK_MASK_PRESCX_OVER_S0               0x80    // Scale Down factor over 2 (0=Disable, 1=Enable)   for Switch2 Mode0 [1]29

#define BITEK_06B06E_PRESCX_START_S1            0x06B       // HSD Start        for Switch2 Mode1 [1]30
#define BITEK_06C06E_PRESCX_SHIFT_S1            0x06C       // HSD Shift        for Switch2 Mode1
#define BITEK_06D06F_PRESCX_FIX_S1              0x06D       // HSD Fix          for Switch2 Mode1
#define BITEK_06E_PRESCX_S1_MSB                 0x06E       // HSD Attribute    for Switch2 Mode1
    #define BITEK_MASK_PRESCX_SHIFT_S1_MSB          0x07
    #define BITEK_MASK_PRESCX_START_S1_MSB          0xF0

#define BITEK_06F_PRESCX_S1_ATTR                0x06F       // HSD Attribute                            for Switch2 Mode1
    #define BITEK_MASK_PRESCX_EN_S1                 0x01    // HSD Enable (0=Bypass mode, 1=Scale mode) for Switch2 Mode1
    #define BITEK_MASK_PRESCX_FILTER_EN_S1          0x02    // Filter Enable (0=Disable, 1=Enable)      for Switch2 Mode1
    #define BITEK_MASK_PRESCX_FILTER_S1             0x04    // Filter Type (0=Bilinear, 1=Box)          for Switch2 Mode1
    #define BITEK_MASK_PRESCX_FIX2_EN_S1            0x08    // Scale Down factor 2 Enable (0=Disable, 1=Enable) for Switch2 Mode1
    #define BITEK_MASK_PRESCX_FIX_S1_MSB            0x30    // HSD Fix MSB                                      for Switch2 Mode1
    #define BITEK_MASK_PRESCX_OVER_S1               0x80    // Scale Down factor over 2 (0=Disable, 1=Enable)   for Switch2 Mode1


// [1] Horizontal Scaling UP  (SCX1) Engine
#define BITEK_070073_SCX1_START_S0              0x070       // HSU Start            for Switch2 Mode0
#define BITEK_071_SCX1_SHIFT_S0                 0x071       // HSU Shift for Zone 1 for Switch2 Mode0
#define BITEK_072073_SCX1_FIX_S0                0x072       // HSU Fix   for Zone 1 for Switch2 Mode0
#define BITEK_073_SCX1_S0_ATTR                  0x073       // HSU Attribute        for Switch2 Mode0
    #define BITEK_MASK_SCX1_START_S0_MSB            0x03
    #define BITEK_MASK_SCX1_FIX_S0_MSB              0x1C
    #define BITEK_MASK_SCX_FILTER_SEL_S0            0x60
    #define BITEK_MASK_SCX_EN_S0                    0x80    // HSU Filter Type Enable (0=Disable, 1=Enable) for Switch2 Mode0

#define BITEK_074077_SCX1_START_S1              0x074       // HSU Start            for Switch2 Mode1
#define BITEK_075_SCX1_SHIFT_S1                 0x075       // HSU Shift for Zone 1 for Switch2 Mode1
#define BITEK_076077_SCX1_FIX_S1                0x076       // HSU Fix   for Zone 1 for Switch2 Mode1
#define BITEK_077_SCX1_S1_ATTR                  0x077       // HSU Attribute        for Switch2 Mode1
    #define BITEK_MASK_SCX1_START_S1_MSB            0x03
    #define BITEK_MASK_SCX1_FIX_S1_MSB              0x1C
    #define BITEK_MASK_SCX_FILTER_SEL_S1            0x60
    #define BITEK_MASK_SCX_EN_S1                    0x80    // HSU Filter Type Enable (0=Disable, 1=Enable) for Switch2 Mode1

#define BITEK_078_SCX2_SHIFT                    0x078       // HSU Shift for Zone 2
#define BITEK_07907C_SCX2_FIX                   0x079       // HSU Fix   for Zone 2
#define BITEK_07A07C_SCX1_INC                   0x07A       // HSU Nonlinear Increase
#define BITEK_07B07C_SCX2_DEC                   0x07B       // HSU Nonlinear Decrease
#define BITEK_07C_SCX_ATTR                      0x07C       // HSU Attribute
    #define BITEK_MASK_SCX2_FIX_MSB                 0x07
    #define BITEK_MASK_SCX1_INC_MSB                 0x30
    #define BITEK_MASK_SCX2_DEC_MSB                 0xC0

#define BITEK_07D_ANZOOM_ATTR                   0x07D       // HSU Attribute
    #define BITEK_MASK_ANZOOM_TYPE                  0x01    // 0=3-Zone Wide Screen, 1=Nonlinear Wide Screen
    #define BITEK_MASK_ANZOOM_EN                    0x02    // Wide Screen Mode Enable (0=Disable, 1=Enable)


// [1] Vertical Scaling (SCY) Engine
#define BITEK_07E082_SCYE_START_M0              0x07E       // VSX EVEN Field Start for Switch Mode0
#define BITEK_07F082_SCYO_START_M0              0x07F       // VSX ODD  Field Start for Switch Mode0
#define BITEK_080082_SCY_SHIFT_M0               0x080       // VSX Shift            for Switch Mode0
#define BITEK_081082_SCY_FIX_M0                 0x081       // VSX Fix              for Switch Mode0
#define BITEK_082_SCY_M0_MSB                    0x082       // VSX Attribute        for Switch Mode0
    #define BITEK_MASK_SCYE_START_M0_MSB            0x03
    #define BITEK_MASK_SCYO_START_M0_MSB            0x0C
    #define BITEK_MASK_SCY_SHIFT_M0_MSB             0x10
    #define BITEK_MASK_SCY_FIX_M0_MSB               0x60
    #define BITEK_MASK_SCY_RESAMPLE_EN_M0           0x80

#define BITEK_083_SCY_ATTR_M0                   0x083       // VSX Attribute        for Switch Mode0
    #define BITEK_MASK_SCY_EN_M0                    0x01    // VSX Enable (0=Bypass mode, 1=Scale mode)
    #define BITEK_MASK_SCY_FILTER_EN_M0             0x02    // VSX Filter Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_SCY_FILTER_M0                0x04    // VSX Filter Type (0=Bilinear, 1=Box)
    #define BITEK_MASK_LINE_MIRROR                  0x10
    #define BITEK_MASK_LINE_CUT_M0                  0x20    // Line buffer Mirror Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_CUT_MODE_M0                  0x40    //
    #define BITEK_MASK_CUT_AUTO_M0                  0x80    // Vertical Pre-Scaling Change Mode (0=Manual, 1=Auto)

#define BITEK_084088_SCYE_START_M1              0x084       // VSX EVEN Field Start for Switch Mode1
#define BITEK_085088_SCYO_START_M1              0x085       // VSX ODD  Field Start for Switch Mode1
#define BITEK_086088_SCY_SHIFT_M1               0x086       // VSX Shift            for Switch Mode1
#define BITEK_087088_SCY_FIX_M1                 0x087       // VSX Fix              for Switch Mode1
#define BITEK_088_SCY_M1_MSB                    0x088       // VSX Attribute        for Switch Mode1
    #define BITEK_MASK_SCYE_START_M1_MSB            0x03
    #define BITEK_MASK_SCYO_START_M1_MSB            0x0C
    #define BITEK_MASK_SCY_SHIFT_M1_MSB             0x10
    #define BITEK_MASK_SCY_FIX_M1_MSB               0x60
    #define BITEK_MASK_SCY_RESAMPLE_EN_M1           0x80

#define BITEK_089_VSX_ATTR_M1                   0x089       // VSX Attribute        for Switch Mode1  [1]33
    #define BITEK_MASK_SCY_EN_M1                    0x01    // VSX Enable (0=Bypass mode, 1=Scale mode)
    #define BITEK_MASK_SCY_FILTER_EN_M1             0x02    // VSX Filter Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_SCY_FILTER_M1                0x04    // VSX Filter Type (0=Bilinear, 1=Box)
//  #define BITEK_MASK_LINE_MIRROR_M1               0x10
    #define BITEK_MASK_LINE_CUT_M1                  0x20    // Line buffer Mirror Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_CUT_MODE_M1                  0x40    //
    #define BITEK_MASK_CUT_AUTO_M1                  0x80    // Vertical Pre-Scaling Change Mode (0=Manual, 1=Auto)


// [1] Timing Adjustment
#define BITEK_08A_MASTER_DLY_M0                 0x08A       // Output VS sysnchorinze Delay time        for Switch Mode0
#define BITEK_08B08D_DLYE_OCLK_M0               0x08B       // Even Field outputs VS delay    in OCLK   for Switch Mode0
#define BITEK_08C08D_DLYO_OCLK_M0               0x08C       // Odd Field outputs VS delay     in OCLK   for Switch Mode0
#define BITEK_08D_DLY_OCLK_M0_MSB               0x08D       // VS delay                                 for Switch Mode0
    #define BITEK_MASK_DLYO_OCLK_M0_MSB             0x0F
    #define BITEK_MASK_DLYE_OCLK_M0_MSB             0xF0

#define BITEK_08E_MASTER_DLY_M1                 0x08E       // Output VS sysnchorinze Delay time        for Switch Mode1
#define BITEK_08F091_DLYE_OCLK_M1               0x08F       // Even Field outputs VS delay    in OCLK   for Switch Mode1
#define BITEK_090091_DLYO_OCLK_M1               0x090       // Odd Field outputs VS delay     in OCLK   for Switch Mode1
#define BITEK_091_DLY_OCLK_M1_MSB               0x091       // VS delay                                 for Switch Mode1
    #define BITEK_MASK_DLYO_OCLK_M1_MSB             0x0F
    #define BITEK_MASK_DLYE_OCLK_M1_MSB             0xF0

// [1] ITU656 Encoder Mode
#define BITEK_092_ITU656_MODE                   0x092
    #define BITEK_MASK_ITU656ENC_R2YSEL             0x01    // ITU656 Encoder
    #define BITEK_MASK_ITU656ENC_MODE               0x06    // ITU656 Encoder Data bus Mode Select
    #define BITEK_MASK_ITU656ENC_FPOL               0x08    // ITU656 Encoder F Field Polarity
    #define BITEK_MASK_ITU656ENC_VPOL               0x10    // ITU656 Encoder V Field Polarity
    #define BITEK_MASK_ITU656ENC_HPOL               0x20    // ITU656 Encoder H Field Polarity
    #define BITEK_MASK_ITU656ENC_HEAD               0x40    // ITU656 Encoder Handle Enable
    #define BITEK_MASK_ITU656ENC_EN                 0x80    // ITU656 Encoder Enable

// 0x93 - 0x95: NONE

//#define BITEK_095097_COMB_AMPSEL1             0x095
#define BITEK_096097_COMB_AMPSEL2               0x096
#define BITEK_097_COMB_AMPSEL                   0x097
    #define BITEK_MASK_COMB_AMPSEL2_MSB             0x0F
  //#define BITEK_MASK_COMB_AMPSEL1_MSB             0xF0

// [1] Comb Filter Process (Video Decoder)
#define BITEK_098_COMB_LUMA_THD                 0x098

#define BITEK_099_COMBY_EN                      0x099       // COMB Y Enable
    #define BITEK_MASK_COMBY_PAL_60                 0x01    // PAL
    #define BITEK_MASK_COMBY_PAL_N                  0x02    // PAL_N
    #define BITEK_MASK_COMBY_SECAM                  0x04    // SECAM
    #define BITEK_MASK_COMBY_PAL_M                  0x08    // PAL_M
    #define BITEK_MASK_COMBY_NTSC443_50             0x10    // NTSC_4.43_50Hz
    #define BITEK_MASK_COMBY_NTSC_M_J               0x20    // NTSC_M / NTSC_J
    #define BITEK_MASK_COMBY_NTSC443_60             0x40    // NTSC_4.43_60Hz
    #define BITEK_MASK_COMBY_BW                     0x80    // Black & White

#define BITEK_09A_COMBC_EN                      0x09A       // COMB C Enable
    #define BITEK_MASK_COMBC_PAL_60                 0x01    // PAL
    #define BITEK_MASK_COMBC_PAL_N                  0x02    // PAL_N
    #define BITEK_MASK_COMBC_SECAM                  0x04    // SECAM
    #define BITEK_MASK_COMBC_PAL_M                  0x08    // PAL_M
    #define BITEK_MASK_COMBC_NTSC443_50             0x10    // NTSC_4.43_50Hz
    #define BITEK_MASK_COMBC_NTSC_M_J               0x20    // NTSC_M / NTSC_J
    #define BITEK_MASK_COMBC_NTSC443_60             0x40    // NTSC_4.43_60Hz
    #define BITEK_MASK_COMBC_BW                     0x80    // Black & White

#define BITEK_09B_COMB_ATTR                     0x09B
    #define BITEK_MASK_COMBY_VAL                    0x0F    // COMB Y factor
    #define BITEK_MASK_COMBY_EN                     0x10    // PAL-60
    #define BITEK_MASK_COMBC_EN                     0x20    // PAL-60
    #define BITEK_MASK_COMB_VTRC_EN                 0x40    // COMB VTRC Mode enable
    #define BITEK_MASK_BURST_EN                     0x80

#define BITEK_09C_AMP_P                         0x09C
#define BITEK_09D_AMP_N                         0x09D
#define BITEK_09E_POSTBL_P                      0x09E
#define BITEK_09F_POSTBL_N                      0x09F
#define BITEK_0A0_PREBL_P_LSB                   0x0A0
#define BITEK_0A1_PREBL_N_LSB                   0x0A1

#define BITEK_0A2_PREBL_MSB                     0x0A2
    #define BITEK_MASK_PREBL_P_MSB                  0x0F
    #define BITEK_MASK_PREBL_N_MSB                  0xF0

#define BITEK_0A3_PREBL_ATTR                    0x0A3
  //#define BITEK_MASK_PREBL_STABLE                 0x03
  //#define BITEK_MASK_PREBL_AUTO                   0x04
  //#define BITEK_MASK_PREBL_UPDATE                 0x08
    #define BITEK_MASK_COMP_AMP_EN                  0x10
  //#define BITEK_MASK_COMP_AMP_SEL                 0x20
    #define BITEK_MASK_PREBL_MODE                   0x40

// [1] Luminance Process
#define BITEK_0A4_APER_ATTR                     0x0A4
    #define BITEK_MASK_BPASS_SEL                    0x03    // Band Pass 1 Frequency Select
    #define BITEK_MASK_COR_SEL                      0x0C    // Coring 1 circuit amplitude value
    #define BITEK_MASK_APER_SEL                     0x70    // Aperture 1 Factor
    #define BITEK_MASK_PREF_EN                      0x80    // Luma Pre-Filter Enable


#define BITEK_0A5_Y_ATTR                        0x0A5
    #define BITEK_MASK_YDEL                         0x0F    // Y Data Path Delay
    #define BITEK_MASK_LUMA_DITHER                  0x10    // Y Dither Process
  //#define BITEK_MASK_LUMA_6BITS                   0x20
    #define BITEK_MASK_CHROMA_FIX24                 0x20
    #define BITEK_MASK_SRC_EN                       0x40
    #define BITEK_MASK_VTRC_SLOW                    0x80


// [1] Video Decoder
// [1] Synchronization Process
#define BITEK_0A6_SYNC_IDEL                     0x0A6       // Horizontal increment delay
#define BITEK_0A7_SYNC_HSYS                     0x0A7       // Horizontal Sync Start
#define BITEK_0A8_SYNC_HCS                      0x0A8       // Clamp Signal Start
#define BITEK_0A9_SYNC_HSS                      0x0A9       // Horizontal Delay
#define BITEK_0AA_BGPU_POINT_N                  0x0AA       // Burst Gap Start Point for 60Hz signal
    #define BITEK_MASK_BGPU_POINT_N_VALUE           0x3F
    #define BITEK_MASK_CR_DLY                       0x40
    #define BITEK_MASK_CB_DLY                       0x80

#define BITEK_0AB_BGPU_POINT_P                  0x0AB       // Burst Gap Start Point for 50Hz signal
    #define BITEK_MASK_BGPU_POINT_P_VALUE           0x3F
    #define BITEK_MASK_VTRC_THD                     0xC0

#define BITEK_0AC_SLICER_THD                    0x0AC       // Sync-Slicer Threshold

#define BITEK_0AD_SYNC_ATTR                     0x0AD
    #define BITEK_MASK_VNOISE_MODE                  0x03    // Vsync Detection Mode
    #define BITEK_MASK_VTRC                         0x04    // VCR Mode Enable
    #define BITEK_MASK_AUTO_VTRC                    0x08    // Auto VCR Mode Enable
    #define BITEK_MASK_FIDT_THD                     0xF0    // 50/60Hz Detect Threshold

#define BITEK_0AE_SYNC_ATTR1                    0x0AE
    #define BITEK_MASK_SYNC_LPADJ                   0x01    // Low Pass Filter Margin Value
    #define BITEK_MASK_SYNC_DTO_SEL                 0x02
    #define BITEK_MASK_SYNC_PDGAIN                  0x0C    // Phase Detection Margin Value
    #define BITEK_MASK_SYNC_LPLMT                   0x10    // Low pass filter trace value
    #define BITEK_MASK_SYNC_HPLL                    0x60    // HPLL Mode Enable
    #define BITEK_MASK_SYNC_CHT_EN                  0x80    // Chroma Trap Enable (0=Disable, 1=Enable)

#define BITEK_0AF0B1_DTO_REF                    0x0AF       // DTO Reference frequency DTO[17:0]
#define BITEK_0AF_DTO_REF07_00                  0x0AF       // DTO Reference frequency DTO[7:0]
#define BITEK_0B0_DTO_REF15_08                  0x0B0       // DTO Reference frequency DTO[15:8]

#define BITEK_0B1_SYNC_ATTR2                    0x0B1
    #define BITEK_MASK_DTO_REF17_16                 0x03    // DTO Reference frequency DTO[17:16]
    #define BITEK_MASK_HLCK_SEL                     0x1C
    #define BITEK_MASK_HLCK_EN                      0x04    // HLCK Detection Enable
    #define BITEK_MASK_SYNCRDY_EN                   0x08    // Sync Ready Detection Enable
    #define BITEK_MASK_STDRDY_EN                    0x10    // Standard Ready Detection Enable
    #define BITEK_MASK_SYNC_PDGAIN_SLOW             0x20
    #define BITEK_MASK_SYNC_CDEL8                   0x40    // Horizontal increment delay for chroma CDEL[8]
    #define BITEK_MASK_SYNC_DLY                     0x80    // Comb line buffer timing Delay

#define BITEK_0B2_SYNC_CDEL07_00                    0x0B2   // Horizontal increment delay for chroma CDEL[7:0]


// [1] Chroma Process
#define BITEK_0B3_CHROMA_CBAMP                  0x0B3       // Chroma Gain Cb
#define BITEK_0B4_CHROMA_CRAMP                  0x0B4       // Chroma Gain Cr

#define BITEK_0B5_CHROMA_GAIN_ATTR              0x0B5       // Chroma Gain
    #define BITEK_MASK_CHROMA_GAIN                  0x7F    // Chroma Fixed-Gain Value
    #define BITEK_MASK_CHROMA_GAIN_SEL              0x80    // 0=Auto-Gain, 1=Fixed-Gain

// [1] Luminance Process
#define BITEK_0B60B7_GAIN_CTRL                  0x0B6       // Chroma Gain Reference value

#define BITEK_0B7_CHROMA_ATTR                   0x0B7
    #define BITEK_MASK_GAIN_CTRL_MSB                0x03    // Chroma Gain Reference value MSB
    #define BITEK_MASK_GAIN_CTRL_SPEED              0x0C    // Auto Chroma Gain Loop Filter [1]43
    #define BITEK_MASK_STD_CKILL                    0x10
    #define BITEK_MASK_CHROMA_PHASE                 0x20    // Chroma Phase Detection Mode (0=Mode1, 1=Mode2)
    #define BITEK_MASK_SECAM_GAINDIS                0x40    // SECAM Gain Disable tracker
    #define BITEK_MASK_SXCR                         0x80    // SECAM Cross Color Reduction (0=Disable, 1=Enable)

#define BITEK_0B8_THRESHOLD_SECAM               0x0B8       // Color Killer Threshold for SECAM
#define BITEK_0B9_THRESHOLD_QAM                 0x0B9       // Color Killer Threshold for PAL and NTSC
#define BITEK_0BA_SECAM_SENSITIVE               0x0BA       // SECAM switch sensitive level
#define BITEK_0BB_PAL_SENSITIVE                 0x0BB       // PAL switch sensitive level
#define BITEK_0BC_STD_OFS00                     0x0BC       // Burst Freq. offset for 3.57MHz
#define BITEK_0BD_STD_OFS01                     0x0BD       // Burst Freq. offset for 4.2 MHz
#define BITEK_0BE_STD_OFS10                     0x0BE       // Burst Freq. offset for 4.43MHz
#define BITEK_0BF_CHROMA_HUE                    0x0BF       // Chroma Hue value

#define BITEK_0C0_CHROMA_ATTR1                  0x0C0
    #define BITEK_MASK_CHROMA_LPPI1                 0x03    // Chroma Low Pass Filter Factor 1
    #define BITEK_MASK_CHROMA_LPPI2                 0x0C    // Chroma Low Pass Filter Factor 2
    #define BITEK_MASK_SQP_LMT                      0x10    // Sub-Carrier Frequency Select
    #define BITEK_MASK_SQP_LPPI                     0x60    // Sub-Carrier Phase Detect factor 1
    #define BITEK_MASK_SQP_SPUP                     0x80    // Sub-Carrier Phase Detect factor 2

#define BITEK_0C1_STANDARD                      0x0C1
    #define BITEK_MASK_CHROMA_RCF_EN                0x01    // Re-comb filter enable [1]44
    #define BITEK_MASK_CDV_SEL                      0x02    // TV / VCR Mode Select (0=Mode1, 1=Mode2)
    #define BITEK_MASK_CHROMA_AMPAUTO               0x04    // Chroma AMP Auto
    #define BITEK_MASK_STD_SECAM_EN                 0x08    // SECAM Standard enable
    #define BITEK_MASK_STD_PALM_EN                  0x10    // PAL-M Standard enable
    #define BITEK_MASK_STD_PALN_EN                  0x20    // PAL-N Standard enable
    #define BITEK_MASK_STD_NTSC4_60_EN              0x40    // NTSC 4.43MHz 60Hz Standard enable
    #define BITEK_MASK_STD_NTSC4_50_EN              0x80    // NTSC4.43MHz 50Hz Standard Enable

// [1] AGC and ACC Process
#define BITEK_0C2_ACLAMP_LEVEL                  0x0C2       // Analog Clamp 1 Level

#define BITEK_0C3_ACLAMP_ATTR0                  0x0C3
    #define BITEK_MASK_ACLAMP_SPEED                 0x3F    // Analog Clamp Tracker Speed
    #define BITEK_MASK_ACLAMP_MODE                  0xC0    // Analog Clamp Tracker Speed Mode

#define BITEK_0C4_ACLAMP_ATTR1                  0x0C4
  //#define BITEK_MASK_ACLAMP_LPPI                  0x03
  //#define BITEK_MASK_ACLAMP_LPPI2                 0x0C
    #define BITEK_MASK_ACLAMP_SPEEDUP_MODE          0x03
    #define BITEK_MASK_ACLAMP_SPEEDUP               0x04
    #define BITEK_MASK_ACLAMP_TYPE                  0x08
    #define BITEK_MASK_ACLAMP_CR_EN                 0x10
    #define BITEK_MASK_ACLAMP_CB_EN                 0x20
    #define BITEK_MASK_ACLAMP_CR_SEL                0x40
    #define BITEK_MASK_ACLAMP_CB_SEL                0x80

#define BITEK_0C5_ACLAMP_ATTR2                  0x0C5
    #define BITEK_MASK_AGAIN_HOLD                   0x01
    #define BITEK_MASK_AGAIN2_VAL                   0x06
    #define BITEK_MASK_AGAIN2_SEL                   0x08
    #define BITEK_MASK_AGAIN1_VAL                   0x30
    #define BITEK_MASK_AGAIN1_SEL                   0x40
    #define BITEK_MASK_ACLAMP_Y_EN                  0x80

#define BITEK_0C6_DCLAMPCB_LEVEL                0x0C6
#define BITEK_0C7_DCLAMPCB_ATTR                 0x0C7
    #define BITEK_MASK_DCLAMPCB_LEVEL_MSB           0x03
    #define BITEK_MASK_DCLAMPCB_HOLD                0x40
    #define BITEK_MASK_DCLAMPCB_EN                  0x80

#define BITEK_0C8_DCLAMPCR_LEVEL                0x0C8
#define BITEK_0C9_DCLAMPCR_ATTR                 0x0C9
    #define BITEK_MASK_DCLAMPCR_LEVEL_MSB           0x03
    #define BITEK_MASK_DCLAMPCR_HOLD                0x40
    #define BITEK_MASK_DCLAMPCR_EN                  0x80

#define BITEK_0CA_DCLAMPY_LEVEL                 0x0CA
#define BITEK_0CB_DCLAMPY_ATTR                  0x0CB
    #define BITEK_MASK_DCLAMPY_LEVEL_MSB            0x03
    #define BITEK_MASK_DCLAMPY_HOLD                 0x40
    #define BITEK_MASK_DCLAMPY_EN                   0x80

#define BITEK_0CC_DCLAMP_ATTR0                  0x0CC
    #define BITEK_MASK_DCLAMP_SPEED                 0x3F    // Digital Clamp Tracker Speed
    #define BITEK_MASK_DCLAMP_MODE                  0xC0    // Digital Clamp Tracker Speed Mode

#define BITEK_0CD_DCLAMP_ATTR1                  0x0CD
  //#define BITEK_MASK_DCLAMP_LPPI                  0x03
  //#define BITEK_MASK_DCLAMP_LPPI2                 0x0C
    #define BITEK_MASK_DCLAMP_STABLE                0x30
    #define BITEK_MASK_DCLAMP_STABLE_EN             0x40
    #define BITEK_MASK_DCLAMP_STABLE_MODE           0x80


#define BITEK_0CE_DGAIN_CB_LEVEL                0x0CE
#define BITEK_0CF_DGAIN_CR_LEVEL                0x0CF
#define BITEK_0D0_DGAIN_ATTR                    0x0D0
    #define BITEK_MASK_DGAIN_CR_LEVEL_MSB           0x03
    #define BITEK_MASK_DGAIN_CR_SEL                 0x04
    #define BITEK_MASK_DGAIN_CB_LEVEL_MSB           0x30
    #define BITEK_MASK_DGAIN_CB_SEL                 0x40


//#define BITEK_0D1_DGAIN_LOW                   0x0D1
#define BITEK_0D1_STABLE_DLY                    0x0D1

#define BITEK_0D2_DGAIN_ATTR1                   0x0D2
    #define BITEK_MASK_DGAIN_SPEED                  0x3F    // Digital Gain Tracker Speed
    #define BITEK_MASK_DGAIN_MODE_LSB               0xC0    // Digital Gain Tracker Speed Mode


#define BITEK_0D3_DGAIN_LEVEL                   0x0D3
#define BITEK_0D4_DGAIN_ATTR2                   0x0D4
    #define BITEK_MASK_DGAIN_LEVEL_MSB              0x03
    #define BITEK_MASK_DGAIN_STABLE_MODE            0x04
    #define BITEK_MASK_DGAIN_STABLE_EN              0x08
    #define BITEK_MASK_DGAIN_STABLE                 0x30
    #define BITEK_MASK_DGAIN_HOLD                   0x40
    #define BITEK_MASK_DGAIN_EN                     0x80

#define BITEK_0D5_GAIN_ATTR                     0x0D5
  #define BITEK_MASK_AGAIN_THD                      0x03
  #define BITEK_MASK_DGAIN_COMPENSATE               0x04
  #define BITEK_MASK_DGAIN_TRACKER                  0x08

// [1] VBI Data Slicer
#define BITEK_0D6_DATA_SLICER_THD               0x0D6       // Data slicer High/Low thresold
#define BITEK_0D7_DATA_SLICER_START             0x0D7       // Data slicer start point

#define BITEK_0D8_DATA_SLICER_E_INFO            0x0D8
    #define BITEK_MASK_DATA_SLICER_LINE_E           0x3F    // Data slicer line select  for EVEN field
    #define BITEK_MASK_DATA_SLICER_EN_E             0x80    // Data slicer Enable       for EVEN field

#define BITEK_0D9_DATA_SLICER_O_INFO            0x0D9
    #define BITEK_MASK_DATA_SLICER_LINE_O           0x3F    // Data slicer line select  for ODD field
    #define BITEK_MASK_DATA_SLICER_EN_O             0x80    // Data slicer Enable       for ODD field


// [1] Source Detection
#define BITEK_0DA_AGC_ATTR                      0x0DA
    #define BITEK_MASK_CR_CHG_THD                   0x03
    #define BITEK_MASK_CB_CHG_THD                   0x0C
    #define BITEK_MASK_Y_CHG_THD                    0x30
    #define BITEK_MASK_FIFO_READY                   0x40
    #define BITEK_MASK_ADC_SPLIT                    0x80    // ADC11/ADC12 Split enable

// [1] AFE and PLL Control
#define BITEK_0DB_AFE_ATTR                      0x0DB
    #define BITEK_MASK_AFE_CS                       0x03    // AFE Clamp current
    #define BITEK_MASK_AFE_CTRPH                    0x0C    // AFE Phase Non-overlap time
    #define BITEK_MASK_AFE_CTRIB                    0x70    // AFE Bias current control
    #define BITEK_MASK_AFE_SH2VCM                   0x80    // AFE Internal shortcut on both PGA

#define BITEK_0DC_AFE_ATTR1                     0x0DC
    #define BITEK_MASK_AFE_ENIB                     0x01    // AFE Bias current Enable
    #define BITEK_MASK_AFE_ENREF                    0x02    // AFE Reference Generator Enable
    #define BITEK_MASK_AFE_ENVBG                    0x04    // AFE Bandgap  Generator Enable
    #define BITEK_MASK_AFE_ENVCM                    0x08    // AFE common voltage Generator Enable
    #define BITEK_MASK_AFE_ENAY                     0x10    // Power Down Input for ADC1 (0=Power down, 1=Normal)
    #define BITEK_MASK_AFE_ENAC                     0x20    // Power Down Input for ADC2 (0=Power down, 1=Normal)
    #define BITEK_MASK_AFE_BYP                      0x40    // Bypass PGA for ADC test
    #define BITEK_MASK_AFE_DEC                      0x80    // Control output data decimator by 8 or none

#define BITEK_0DD_PLL_ATTR                      0x0DD
    #define BITEK_MASK_PLL_POR                      0x01    // PLL Power on Reset (0=Disable, 1=Reset)
    #define BITEK_MASK_PLL_EN                       0x02    // PLL Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_PLL_ICP0                     0x04    // PLL Factor 0
    #define BITEK_MASK_PLL_ICP1                     0x08    // PLL Factor 1
    #define BITEK_MASK_YPBPR675_POL                 0x10    // YPbPr Mode CLK675 Polarity
    #define BITEK_MASK_YPBPR135_POL                 0x20    // YPbPr Mode CLK135 Polarity
    #define BITEK_MASK_CLK27_POL                    0x40    // Video Clock 27M Polarity
    #define BITEK_MASK_CLK27_EN                     0x80    // Video Clock 27M Enable

#define BITEK_0DE_STD_ATTR                      0x0DE
    #define BITEK_MASK_STD_SEL0                     0x07
    #define BITEK_MASK_STD_MOD                      0x08
    #define BITEK_MASK_STD_SEL1                     0x70
    #define BITEK_MASK_STD_AUTO                     0x80

// [1] Input Path Selection
#define BITEK_0DF_AFE_ATTR2                     0x0DF
    #define BITEK_MASK_FSEL                         0x01    // Manual 50/60Hz select (R_AUFD=0)
    #define BITEK_MASK_AUFD                         0x02    // Auto 50/60Hz detection
    #define BITEK_MASK_YSRC_SEL                     0x04    // Path select (1=ADC1, 0=ADC2)
    #define BITEK_MASK_CSRC_SEL                     0x08    // Path select (1=ADC1, 0=ADC2)
    #define BITEK_MASK_YC_EN                        0x10    // Y/C Mode Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_YCBCR_EN                     0x20    // YCbCr Mode Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_YPBPR_EN                     0x40    // YPbPr Mode Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_AFE_SEL                      0x80    // Video mux switch for ADC1 (0=AIN11, 1=AIN12)

#define BITEK_0E0_AFE_ATTR3                     0x0E0
    #define BITEK_MASK_AFE_SPEEDUP_CS               0x03
    #define BITEK_MASK_CHROMA_FSEL                  0x70
    #define BITEK_MASK_CSRC_SWAP                    0x80

// MSF
#define BITEK_0E1_CHROMA_FREQ_07_00             0x0E1
#define BITEK_0E2_CHROMA_FREQ_15_08             0x0E2
#define BITEK_0E3_CHROMA_FREQ_21_16             0x0E3
    #define BITEK_MASK_CHROMA_FREQ_21_16            0x3F

#define BITEK_0E1_CHROMA07_00_F443              0x0E1
#define BITEK_0E1_CHROMA07_00_F428              0x0E1
#define BITEK_0E1_CHROMA07_00_F3582             0x0E1
#define BITEK_0E1_CHROMA07_00_F3579             0x0E1
#define BITEK_0E1_CHROMA07_00_F3576             0x0E1

#define BITEK_0E2_CHROMA15_08_F443              0x0E2
#define BITEK_0E2_CHROMA15_08_F428              0x0E2
#define BITEK_0E2_CHROMA15_08_F3582             0x0E2
#define BITEK_0E2_CHROMA15_08_F3579             0x0E2
#define BITEK_0E2_CHROMA15_08_F3576             0x0E2

#define BITEK_0E3_CHROMA21_16_F443              0x0E3
#define BITEK_0E3_CHROMA21_16_F428              0x0E3
#define BITEK_0E3_CHROMA21_16_F3582             0x0E3
#define BITEK_0E3_CHROMA21_16_F3579             0x0E3
#define BITEK_0E3_CHROMA21_16_F3576             0x0E3

#define BITEK_0E4_CMOS                          0x0E4
    #define BITEK_MASK_CMOS_SENSOR                  0x01
    #define BITEK_MASK_CMOS_SENSOR_PIXEL_POL        0x02
    #define BITEK_MASK_CMOS_SENSOR_LINE_POL         0x04
    #define BITEK_MASK_CMOS_SWAP                    0x08
    #define BITEK_MASK_CMOS_SEL                     0x30


// 0xE5 - 0xE6: NONE

#define BITEK_0E7_INF_SPEED                     0x0E7
    #define BITEK_MASK_INF_SPEED0                   0x0F
    #define BITEK_MASK_INF_SPEED1                   0xF0


// [1] Pad Type Setup (Port Controller)
#define BITEK_0E8_RIN_ATTR                      0x0E8
    #define BITEK_MASK_RIN10_MFP_EN                 0x01
    #define BITEK_MASK_RIN10_MFP_SEL                0x06
    #define BITEK_MASK_RIN10_MFP_SEL_IR_TX          0x00
    #define BITEK_MASK_RIN10_MFP_SEL_UART_TXD       0x02
    #define BITEK_MASK_RIN10_MFP_SEL_I2C_MASTER     0x04
    #define BITEK_MASK_RIN10_MFP_SEL_I2C_SLAVE      0x06
    #define BITEK_MASK_RIN_SPI_EN                   0x08
    #define BITEK_MASK_RIN_GPIO                     0x80    // for P0

#define BITEK_0E9_RIN_PD                        0x0E9       // RIN[7:0] Port Pull-Down resistance on/off
#define BITEK_0EA_RIN_PU                        0x0EA       // RIN[7:0] Port Pull-Up   resistance on/off

#define BITEK_0EB_GIN_ATTR                      0x0EB
    #define BITEK_MASK_GIN10_MFP_EN                 0x01
    #define BITEK_MASK_GIN10_MFP_SEL                0x06
    #define BITEK_MASK_GIN10_MFP_SEL_IR_TX          0x00
    #define BITEK_MASK_GIN10_MFP_SEL_UART_TXD       0x02
    #define BITEK_MASK_GIN10_MFP_SEL_I2C_MASTER     0x04
    #define BITEK_MASK_GIN10_MFP_SEL_I2C_SLAVE      0x06
    #define BITEK_MASK_GIN_SPI_EN                   0x08
    #define BITEK_MASK_GIN_GPIO                     0x80    // for P1

#define BITEK_0EC_GIN_PD                        0x0EC       // GIN[7:0] Port Pull-Down resistance on/off
#define BITEK_0ED_GIN_PU                        0x0ED       // GIN[7:0] Port Pull-Up   resistance on/off

#define BITEK_0EE_BIN_ATTR                      0x0EE
    #define BITEK_MASK_BIN10_MFP_EN                 0x01
    #define BITEK_MASK_BIN10_MFP_SEL                0x06
    #define BITEK_MASK_BIN10_MFP_SEL_IR_TX          0x00
    #define BITEK_MASK_BIN10_MFP_SEL_UART_TXD       0x02
    #define BITEK_MASK_BIN10_MFP_SEL_I2C_MASTER     0x04
    #define BITEK_MASK_BIN10_MFP_SEL_I2C_SLAVE      0x06
    #define BITEK_MASK_BIN_SPI_EN                   0x08
    #define BITEK_MASK_BIN_GPIO                     0x80    // for P2

#define BITEK_0EF_BIN_PD                        0x0EF       // BIN[7:0] Port Pull-Down resistance on/off
#define BITEK_0F0_BIN_PU                        0x0F0       // BIN[7:0] Port Pull-Up   resistance on/off

#define BITEK_0F1_VSYNC_ATTR                    0x0F1
    #define BITEK_MASK_VSYNC_MFP_EN                 0x01
    #define BITEK_MASK_VSYNC_MFP_SEL                0x06
    #define BITEK_MASK_VSYNC_MFP_SEL_IR_TX          0x00
    #define BITEK_MASK_VSYNC_MFP_SEL_UART_TXD       0x02
    #define BITEK_MASK_VSYNC_MFP_SEL_I2C_MASTER     0x04
    #define BITEK_MASK_VSYNC_MFP_SEL_I2C_SLAVE      0x06
    #define BITEK_MASK_VSYNC_GPIO                   0x08
    #define BITEK_MASK_VSYNC_KEY_EN                 0x10
    #define BITEK_MASK_VSYNC_PU                     0x20
    #define BITEK_MASK_VSYNC_PD                     0x40

#define BITEK_0F2_HSYNC_ATTR                    0x0F2
    #define BITEK_MASK_HSYNC_MFP_EN                 0x01
    #define BITEK_MASK_HSYNC_MFP_SEL                0x06
  //#define BITEK_MASK_HSYNC_MFP_SEL_UART_TXD       0x02
    #define BITEK_MASK_HSYNC_MFP_SEL_IR_TX          0x00    // 06:43PM  2013/01/05
    #define BITEK_MASK_HSYNC_MFP_SEL_I2C_MASTER     0x04
    #define BITEK_MASK_HSYNC_MFP_SEL_I2C_SLAVE      0x06
    #define BITEK_MASK_HSYNC_GPIO                   0x08
    #define BITEK_MASK_HSYNC_KEY_EN                 0x10
    #define BITEK_MASK_HSYNC_PU                     0x20
    #define BITEK_MASK_HSYNC_PD                     0x40

#define BITEK_0F3_TOUT_ATTR                     0x0F3
    #define BITEK_MASK_TOUT21_MFP_EN                0x01
    #define BITEK_MASK_TOUT21_MFP_SEL               0x06
    #define BITEK_MASK_TOUT21_MFP_SEL_IR_TX         0x00
    #define BITEK_MASK_TOUT21_MFP_SEL_UART_TXD      0x02
    #define BITEK_MASK_TOUT21_MFP_SEL_I2C_MASTER    0x04
    #define BITEK_MASK_TOUT21_MFP_SEL_I2C_SLAVE     0x06
    #define BITEK_MASK_TOUT_SPI_EN                  0x08
    #define BITEK_MASK_TOUT3_IR_EN                  0x10

#define BITEK_0F4_TOUT_GPIO                     0x0F4
    #define BITEK_MASK_TOUT_GPIO0                   0x01
    #define BITEK_MASK_TOUT_GPIO1                   0x02
    #define BITEK_MASK_TOUT_GPIO2                   0x04
    #define BITEK_MASK_TOUT_GPIO3                   0x08
    #define BITEK_MASK_TOUT_GPIO4                   0x10
    #define BITEK_MASK_TOUT_GPIO5                   0x20
    #define BITEK_MASK_TOUT_GPIO6                   0x40
    #define BITEK_MASK_TOUT_GPIO7                   0x80

#define BITEK_0F5_M8051_ATTR1                   0x0F5
    #define BITEK_MASK_I2C_M_SRC                    0x07
    #define BITEK_MASK_I2C_M_RIN                    0x00   // RIN[1] =SDA ,RIN[0] =SCL
    #define BITEK_MASK_I2C_M_GIN                    0x01   // GIN[1] =SDA ,GIN[0] =SCL
    #define BITEK_MASK_I2C_M_BIN                    0x02   // BIN[1] =SDA ,BIN[0] =SCL
    #define BITEK_MASK_I2C_M_SYNC                   0x03   // VSYNC  =SDA ,HSYNC  =SCL
    #define BITEK_MASK_I2C_M_TOUT                   0x04   // TOUT[2]=SDA ,TOUT[1]=SCL

    #define BITEK_MASK_I2C_S_SRC                    0x38
    #define BITEK_MASK_I2C_S_RIN                    0x00  // RIN[1] =SDA ,RIN[0] =SCL
    #define BITEK_MASK_I2C_S_GIN                    0x08  // GIN[1] =SDA ,GIN[0] =SCL
    #define BITEK_MASK_I2C_S_BIN                    0x10  // BIN[1] =SDA ,BIN[0] =SCL
    #define BITEK_MASK_I2C_S_SYNC                   0x18  // VSYNC  =SDA ,HSYNC  =SCL
    #define BITEK_MASK_I2C_S_TOUT                   0x20  // TOUT[2]=SDA ,TOUT[1]=SCL

    #define BITEK_MASK_M8051_INT0_SRC               0x40

#define BITEK_0F6_M8051_ATTR2                   0x0F6
    #define BITEK_MASK_IR_SRC                       0x07
    #define BITEK_MASK_IR_SRC_RIN7                  0x00
    #define BITEK_MASK_IR_SRC_GIN7                  0x01
    #define BITEK_MASK_IR_SRC_BIN7                  0x02
    #define BITEK_MASK_IR_SRC_VSYNC                 0x03
    #define BITEK_MASK_IR_SRC_TOUT0                 0x04

    #define BITEK_MASK_UART_SRC                     0x38
    #define BITEK_MASK_UART_SRC_RIN0                0x00
    #define BITEK_MASK_UART_SRC_GIN0                0x08
    #define BITEK_MASK_UART_SRC_BIN0                0x10
    #define BITEK_MASK_UART_SRC_HSYNC               0x18
    #define BITEK_MASK_UART_SRC_TOUT1               0x20

    #define BITEK_MASK_M8051_INT1_SRC               0x40

#define BITEK_0F7_M8051_ATTR3                   0x0F7
    #define BITEK_MASK_OUT_MODE                     0x07
    #define BITEK_MASK_DVP_OUT_MODE                 0x08

// [1] GPO Function
#define BITEK_0F8_GPO_REG                       0x0F8       // GPO Value  (0=Low Level, 1=High Level)
#define BITEK_0F9_GPO_TYPE                      0x0F9       // GPO Type   (0=Normal, 1=Tri-State)
#define BITEK_0FA_GPO_SEL                       0x0FA       // GPO Enable (0=Disable, 1=Enable)


// [1] Special Output Setup
#define BITEK_0FB_RTS0_ATTR                     0x0FB
    #define BITEK_MASK_RTS0_SEL                     0x0F    // RTS0 Selection
    #define BITEK_MASK_RTS0_POL                     0x10    // RTS0 Polarity
    #define BITEK_MASK_RTS0_GPO_REG                 0x20
    #define BITEK_MASK_RTS0_GPO_EN                  0x40
    #define BITEK_MASK_RTS0_IR_SEND                 0x80

#define BITEK_0FC_RTS1_ATTR                     0x0FC
    #define BITEK_MASK_RTS1_SEL                     0x0F    // RTS1 Selection
    #define BITEK_MASK_RTS1_POL                     0x10    // RTS1 Polarity
    #define BITEK_MASK_RTS1_GPO_REG                 0x20
    #define BITEK_MASK_RTS1_GPO_EN                  0x40
    #define BITEK_MASK_RTS1_IR_SEND                 0x80

#define BITEK_0FD_RTS2_ATTR                     0x0FD
    #define BITEK_MASK_RTS2_SEL                     0x0F    // RTS2 Selection
    #define BITEK_MASK_RTS2_POL                     0x10    // RTS2 Polarity
    #define BITEK_MASK_RTS2_GPO_REG                 0x20
    #define BITEK_MASK_RTS2_GPO_EN                  0x40
    #define BITEK_MASK_RTS2_IR_SEND                 0x80

// [1] Pad Type Setup
#define BITEK_0FE_PORT_ATTR                     0x0FE       // Port Attribute (1=Tri-state, 0=Normal)
    #define BITEK_MASK_ROUT_TRI                     0x01    // ROUT Port Tri-state Enable
    #define BITEK_MASK_GOUT_TRI                     0x02    // GOUT Port Tri-state Enable
    #define BITEK_MASK_BOUT_TRI                     0x04    // BOUT Port Tri-state Enable
    #define BITEK_MASK_TOUT_TRI                     0x08    // TOUT Port Tri-state Enable
    #define BITEK_MASK_PWM0_TRI                     0x10    // PWM0      Pin  Tri-state Enable
    #define BITEK_MASK_PWM1_TRI                     0x20    // PWM1      Pin  Tri-state Enable
    #define BITEK_MASK_OCLK_TRI                     0x40    // OCLK      Pin  Tri-state Enable

#define BITEK_0FF_TEST_MODE                     0x0FF       // Test Mode Only
    #define BITEK_MASK_TEST_MODE                    0x0F


// [1] OSD Function
// OSD0 Window
// [1] OSD Windowss Function
#define BITEK_100_OSD0_X_LSB                    0x100       // OSD0 Start X position
#define BITEK_100105_OSD0_X                     0x100       // OSD0 Start X position

#define BITEK_101_OSD0_Y_LSB                    0x101       // OSD0 Start Y position
#define BITEK_101105_OSD0_Y                     0x101       // OSD0 Start Y position

#define BITEK_102_OSD0_INDEXS_LSB               0x102       // Display RAM Start Index
#define BITEK_102104_OSD0_INDEXS                0x102       // Display RAM Start Index

#define BITEK_103_OSD0_INDEXB_LSB               0x103       // Display RAM Base  Index
#define BITEK_103104_OSD0_INDEXB                0x103       // Display RAM Base  Index

#define BITEK_104_OSD0_INDEX_MSB                0x104
    #define BITEK_MASK_OSD0_INDEXB_MSB              0x0F
    #define BITEK_MASK_OSD0_INDEXS_MSB              0xF0

#define BITEK_105_OSD0_MSB                      0x105
    #define BITEK_MASK_OSD0_X_MSB                   0x07
    #define BITEK_MASK_OSD0_Y_MSB                   0x18
    #define BITEK_MASK_OSD0_PATSEL                  0x80    // OSD0 Palette Bank select


#define BITEK_106_OSD0_W                        0x106       // OSD0 Width
#define BITEK_107_OSD0_H                        0x107       // OSD0 Height
    #define BITEK_MASK_OSD0_HEIGHT                  0x7F

// [1] OSD Windows Attribute
#define BITEK_108_OSD0_MUL                      0x108
    #define BITEK_MASK_OSD0_MULX                    0x0F    // OSD0 Horizontal Character Size
    #define BITEK_MASK_OSD0_MULY                    0xF0    // OSD0 Vertical Character Size

#define BITEK_109_OSD0_SPC                      0x109
    #define BITEK_MASK_OSD0_SPCX                    0x0F    // OSD0 Character Space
    #define BITEK_MASK_OSD0_SPCY                    0xF0    // OSD0 Line Space

#define BITEK_10A_OSD0_FRINGE_SEL               0x10A       // OSD0 Font Fringe Selection

#define BITEK_10B_OSD0_ATTR                     0x10B
    #define BITEK_MASK_OSD0_FRINGE_COR              0x0F    // OSD0 Window Fringe Color
    #define BITEK_MASK_OSD0_FONTSIZE                0x70    // 30h=12bit width


#define BITEK_10C_OSD0_ATTR1                    0x10C
    #define BITEK_MASK_OSD0_FFADE_VAL               0x0F    // OSD0 Fade In/Out level
    #define BITEK_MASK_OSD0_BFADE_VAL               0xF0    // OSD0 Fade In/Out level

#define BITEK_10D_OSD0_ATTR2                    0x10D
    #define BITEK_MASK_OSD0_WX_MIR                  0x01    // OSD0 Window Horizontal Mirror
    #define BITEK_MASK_OSD0_WY_MIR                  0x02    // OSD0 Window Vertical Mirror
    #define BITEK_MASK_OSD0_FX_MIR                  0x04    // OSD0 Character Horizontal Mirror
    #define BITEK_MASK_OSD0_FY_MIR                  0x08    // OSD0 Character Vertical Mirror
    #define BITEK_MASK_OSD0_BLINK_SEL               0x70    // OSD0 BLINK
    #define BITEK_MASK_OSD0_EN                      0x80    // OSD0 Window Enable

// 0x10E - 0x10F: NONE

// OSD1 Window
#define BITEK_110_OSD1_X_LSB                    0x110       // OSD1 Start X position
#define BITEK_110115_OSD1_X                     0x110       // OSD1 Start X position

#define BITEK_111_OSD1_Y_LSB                    0x111       // OSD1 Start Y position
#define BITEK_111115_OSD1_Y                     0x111       // OSD1 Start Y position

#define BITEK_112_OSD1_INDEXS_LSB               0x112       // Display RAM Start Index
#define BITEK_112114_OSD1_INDEXS                0x112       // Display RAM Start Index

#define BITEK_113_OSD1_INDEXB_LSB               0x113       // Display RAM Base  Index
#define BITEK_113114_OSD1_INDEXB                0x113       // Display RAM Base  Index

#define BITEK_114_OSD1_INDEX_MSB                0x114
    #define BITEK_MASK_OSD1_INDEXB_MSB              0x0F
    #define BITEK_MASK_OSD1_INDEXS_MSB              0xF0

#define BITEK_115_OSD1_MSB                      0x115
    #define BITEK_MASK_OSD1_X_MSB                   0x07
    #define BITEK_MASK_OSD1_Y_MSB                   0x18
    #define BITEK_MASK_OSD1_PATSEL                  0x80    // OSD1 Palette Bank select

#define BITEK_116_OSD1_W                        0x116       // OSD1 Width
#define BITEK_117_OSD1_H                        0x117       // OSD1 Height
    #define BITEK_MASK_OSD1_HEIGHT                  0x7F

// [1] OSD Windows Attribute
#define BITEK_118_OSD1_MUL                      0x118
    #define BITEK_MASK_OSD1_MULX                    0x0F    // OSD1 Horizontal Character Size
    #define BITEK_MASK_OSD1_MULY                    0xF0    // OSD1 Vertical Character Size

#define BITEK_119_OSD1_SPC                      0x119
    #define BITEK_MASK_OSD1_SPCX                    0x0F    // OSD1 Character Space
    #define BITEK_MASK_OSD1_SPCY                    0xF0    // OSD1 Line Space

#define BITEK_11A_OSD1_FRINGE_SEL               0x11A       // OSD1 Font Fringe Selection

#define BITEK_11B_OSD1_ATTR                     0x11B
    #define BITEK_MASK_OSD1_FRINGE_COR              0x0F    // OSD1 Window Fringe Color
    #define BITEK_MASK_OSD1_FONTSIZE                0x70    //


#define BITEK_11C_OSD1_ATTR1                    0x11C
    #define BITEK_MASK_OSD1_FFADE_VAL               0x0F    // OSD1 Fade In/Out level
    #define BITEK_MASK_OSD1_BFADE_VAL               0xF0    // OSD1 Fade In/Out level

#define BITEK_11D_OSD1_ATTR2                    0x11D
    #define BITEK_MASK_OSD1_WX_MIR                  0x01    // OSD1 Window Horizontal Mirror
    #define BITEK_MASK_OSD1_WY_MIR                  0x02    // OSD1 Window Vertical Mirror
    #define BITEK_MASK_OSD1_FX_MIR                  0x04    // OSD1 Character Horizontal Mirror
    #define BITEK_MASK_OSD1_FY_MIR                  0x08    // OSD1 Character Vertical Mirror
    #define BITEK_MASK_OSD1_BLINK_SEL               0x70    // OSD1 BLINK
    #define BITEK_MASK_OSD1_EN                      0x80    // OSD1 Window Enable

// 0x11E - 0x11F: NONE

// OSD2 Window
#define BITEK_120_OSD2_X_LSB                    0x120       // OSD2 Start X position
#define BITEK_120125_OSD2_X                     0x120       // OSD2 Start X position

#define BITEK_121_OSD2_Y_LSB                    0x121       // OSD2 Start Y position
#define BITEK_121125_OSD2_Y                     0x121       // OSD2 Start Y position

#define BITEK_122_OSD2_INDEXS_LSB               0x122       // Display RAM Start Index
#define BITEK_122124_OSD2_INDEXS                0x122       // Display RAM Start Index

#define BITEK_123_OSD2_INDEXB_LSB               0x123       // Display RAM Base  Index
#define BITEK_123124_OSD2_INDEXB                0x123       // Display RAM Base  Index

#define BITEK_124_OSD2_INDEX_MSB                0x124
    #define BITEK_MASK_OSD2_INDEXB_MSB              0x0F
    #define BITEK_MASK_OSD2_INDEXS_MSB              0xF0

#define BITEK_125_OSD2_MSB                      0x125
    #define BITEK_MASK_OSD2_X_MSB                   0x07
    #define BITEK_MASK_OSD2_Y_MSB                   0x18
    #define BITEK_MASK_OSD2_PATSEL                  0x80    // OSD2 Palette Bank select

#define BITEK_126_OSD2_W                        0x126       // OSD2 Width
#define BITEK_127_OSD2_H                        0x127       // OSD2 Height
    #define BITEK_MASK_OSD2_HEIGHT                  0x7F

// [1] OSD Windows Attribute
#define BITEK_128_OSD2_MUL                      0x128
    #define BITEK_MASK_OSD2_MULX                    0x0F    // OSD2 Horizontal Character Size
    #define BITEK_MASK_OSD2_MULY                    0xF0    // OSD2 Vertical Character Size

#define BITEK_129_OSD2_SPC                      0x129
    #define BITEK_MASK_OSD2_SPCX                    0x0F    // OSD2 Character Space
    #define BITEK_MASK_OSD2_SPCY                    0xF0    // OSD2 Line Space

#define BITEK_12A_OSD2_FRINGE_SEL               0x12A       // OSD2 Font Fringe Selection

#define BITEK_12B_OSD2_ATTR                     0x12B
    #define BITEK_MASK_OSD2_FRINGE_COR              0x0F    // OSD2 Window Fringe Color
    #define BITEK_MASK_OSD2_FONTSIZE                0x70    //


#define BITEK_12C_OSD2_ATTR1                    0x12C
    #define BITEK_MASK_OSD2_FFADE_VAL               0x0F    // OSD2 Fade In/Out level
    #define BITEK_MASK_OSD2_BFADE_VAL               0xF0    // OSD2 Fade In/Out level

#define BITEK_12D_OSD2_ATTR2                    0x12D
    #define BITEK_MASK_OSD2_WX_MIR                  0x01    // OSD2 Window Horizontal Mirror
    #define BITEK_MASK_OSD2_WY_MIR                  0x02    // OSD2 Window Vertical Mirror
    #define BITEK_MASK_OSD2_FX_MIR                  0x04    // OSD2 Character Horizontal Mirror
    #define BITEK_MASK_OSD2_FY_MIR                  0x08    // OSD2 Character Vertical Mirror
    #define BITEK_MASK_OSD2_BLINK_SEL               0x70    //
    #define BITEK_MASK_OSD2_EN                      0x80    // OSD2 Window Enable



// Image Enhancement
#define BITEK_12E_OSDPAT_ATTR                   0x12E
    #define BITEK_MASK_OSDPAT_BANK                  0x03    // OSD Palette
    #define BITEK_MASK_OSDPAT_SEL                   0x08    //Same as 0x159 bit3
    #define BITEK_MASK_OSDPAT_BUSY                  0x80

    #define BITEK_MASK_OSDPAT_BANK0                 0x00
    #define BITEK_MASK_OSDPAT_BANK1                 0x01
    #define BITEK_MASK_OSDPAT_BANK2                 0x02
    #define BITEK_MASK_OSDPAT_BANK3                 0x03

    #define BITEK_MASK_OSDPAT_R                     0x00    // OSD Palette Color R
    #define BITEK_MASK_OSDPAT_G                     0x01    // OSD Palette Color G
    #define BITEK_MASK_OSDPAT_B                     0x02    // OSD Palette Color B
    #define BITEK_MASK_OSDPAT_A                     0x03    // OSD Palette Attribute


#define BITEK_12F_OSD_ATTR                      0x12F
    #define BITEK_MASK_OSD_BANK                     0x0F


    #define BITEK_MASK_OSD_BANK0                    0x00
    #define BITEK_MASK_OSD_BANK1                    0x01
    #define BITEK_MASK_OSD_BANK2                    0x02
    #define BITEK_MASK_OSD_BANK3                    0x03
    #define BITEK_MASK_OSD_BANK4                    0x04
    #define BITEK_MASK_OSD_BANK5                    0x05
    #define BITEK_MASK_OSD_BANK6                    0x06
    #define BITEK_MASK_OSD_BANK7                    0x07
    #define BITEK_MASK_OSD_BANK8                    0x08
    #define BITEK_MASK_OSD_BANK9                    0x09
    #define BITEK_MASK_OSD_BANK10                   0x0A
    #define BITEK_MASK_OSD_BANK11                   0x0B
    #define BITEK_MASK_OSD_BANK12                   0x0C
    #define BITEK_MASK_OSD_BANK13                   0x0D
    #define BITEK_MASK_OSD_BANK14                   0x0E
    #define BITEK_MASK_OSD_BANK15                   0x0F



// [1] Post-Processing Brightness/Contrast Adjustment
#define BITEK_130_BRIGHTNESS_R                  0x130       // R Brightness
#define BITEK_131_BRIGHTNESS_G                  0x131       // G Brightness
#define BITEK_132_BRIGHTNESS_B                  0x132       // B Brightness

#define BITEK_133_CONTRAST_R                    0x133       // R Contrast
#define BITEK_134_CONTRAST_G                    0x134       // G Contrast
#define BITEK_135_CONTRAST_B                    0x135       // B Contrast

// [1] Dither
#define BITEK_136_DITHER_L0                     0x136       // Line 0 Dither Factor
#define BITEK_137_DITHER_L1                     0x137       // Line 1 Dither Factor

// [1] LUT Gamma Correction
#define BITEK_138_GAMMA_ATTR                    0x138
  //#define BITEK_MASK_CONTRAST_RGB_MODE            0x01
    #define BITEK_MASK_DITHER_MODE                  0x06    // 0=Disable,1=666,2=565,3=555
    #define BITEK_MASK_GAMMA_MODE                   0x08    //
    #define BITEK_MASK_GAMMA_SEL                    0x30    // Gamma LUT RAM R/W Select
    #define BITEK_MASK_GAMMA_YUV_EN                 0x40    //
    #define BITEK_MASK_GAMMA_EN                     0x80    // Gamma LUT Enable

    #define BITEK_MASK_GAMMA_R                      0x00    // Gamma LUT RAM R
    #define BITEK_MASK_GAMMA_G                      0x10    // Gamma LUT RAM G
    #define BITEK_MASK_GAMMA_B                      0x20    // Gamma LUT RAM B
    #define BITEK_MASK_GAMMA_Y                      0x30    // Gamma LUT RAM Y

// [1] Pre-Processing Brightness/Contrast Adjustment
#define BITEK_139_BLACKLEVEL                    0x139       //
#define BITEK_13A_BRIGHTNESS                    0x13A       // Brightness
#define BITEK_13B_CONTRAST                      0x13B       // Contrast


// [1] Sharpness Process
#define BITEK_13C_UNSHARP_ATTR                  0x13C
    #define BITEK_MASK_UNSHARP_VALUE                0x7F
    #define BITEK_MASK_UNSHARP_EN                   0x80

#define BITEK_13D_UNSHARP_ATTR1                 0x13D
    #define BITEK_MASK_UNSHARP_THD                  0x3F
    #define BITEK_MASK_UNSHARP_TYPE                 0x40

// [1] Saturation and Kill Color Process
#define BITEK_13E_SAT_U                         0x13E
#define BITEK_13F_SAT_V                         0x13F

#define BITEK_140_KILL_COLOR_ATTR               0x140
    #define BITEK_MASK_SAT_MODE                     0x01
    #define BITEK_MASK_KILL_COLOR                   0x02
    #define BITEK_MASK_KILL_COLOR_THD               0x7C

// [1] Chroma Transient Improvement (CTI)
#define BITEK_141_CTI                           0x141
    #define BITEK_MASK_CTI_GA                       0x03
    #define BITEK_MASK_CTI_LI                       0x0C
    #define BITEK_MASK_CTI_NEW                      0x10
    #define BITEK_MASK_CTI_NEW2                     0x20
    #define BITEK_MASK_CTI_CMO                      0x40
    #define BITEK_MASK_CTI_EN                       0x80

#define BITEK_142_CTI_SEL                       0x142
    #define BITEK_MASK_CTI_CMO_VAL                  0x0F
    #define BITEK_MASK_CTI_U_SEL                    0x10
    #define BITEK_MASK_CTI_V_SEL                    0x20

#define BITEK_143_NR_Y                          0x143
    #define BITEK_MASK_NR_Y_THD                     0x1F
    #define BITEK_MASK_NR_Y_SEL                     0x60
    #define BITEK_MASK_NR_Y_EN                      0x80

#define BITEK_144_NR_UV                         0x144
    #define BITEK_MASK_NR_UV_THD                    0x0F
    #define BITEK_MASK_NR_Y_MODE                    0x10
    #define BITEK_MASK_NR_UV_SEL                    0x60
    #define BITEK_MASK_NR_UV_EN                     0x80

#define BITEK_145_LOAD                          0x145
    #define BITEK_MASK_LOAD_EN                      0x01
    #define BITEK_MASK_LOAD_TYPE                    0x02
    #define BITEK_MASK_NR_UV_MAX                    0xFC

//  AOSD
#define BITEK_146_AOSD_START07_00               0x146
#define BITEK_146_AOSD_ROUND_ATTR               0x146
    #define BITEK_MASK_AOSD_ROUND_L00               0x0F
    #define BITEK_MASK_AOSD_ROUND_L01               0xF0

#define BITEK_147_AOSD_START15_08               0x147
#define BITEK_147_AOSD_ROUND_ATTR1              0x147
    #define BITEK_MASK_AOSD_ROUND_L02               0x0F
    #define BITEK_MASK_AOSD_ROUND_L03               0xF0

#define BITEK_148_AOSD_START23_16               0x148
#define BITEK_148_AOSD_ROUND_ATTR2              0x148
    #define BITEK_MASK_AOSD_ROUND_L04               0x0F
    #define BITEK_MASK_AOSD_ROUND_L05               0xF0

#define BITEK_149_AOSD_X_LSB                    0x149
#define BITEK_149_AOSD_ROUND_ATTR3              0x149
    #define BITEK_MASK_AOSD_ROUND_L06               0x0F
    #define BITEK_MASK_AOSD_ROUND_L07               0xF0

#define BITEK_14A_AOSD_Y_LSB                    0x14A
#define BITEK_14A_AOSD_ROUND_ATTR4              0x14A
    #define BITEK_MASK_AOSD_ROUND_L08               0x0F
    #define BITEK_MASK_AOSD_ROUND_L09               0xF0

#define BITEK_14B_AOSD_XY_MSB                   0x14B
#define BITEK_14B_AOSD_ROUND_ATTR5              0x14B
   #define BITEK_MASK_AOSD_X_MSB                    0x07
   #define BITEK_MASK_AOSD_Y_MSB                    0x30
   #define BITEK_MASK_AOSD_ROUND_L10                0x0F
   #define BITEK_MASK_AOSD_ROUND_L11                0xF0

#define BITEK_14C_AOSD_W_LSB                    0x14C
#define BITEK_14C_AOSD_ROUND_ATTR6              0x14C
    #define BITEK_MASK_AOSD_ROUND_L12               0x0F
    #define BITEK_MASK_AOSD_ROUND_L13               0xF0

#define BITEK_14D_AOSD_H_LSB                    0x14D
#define BITEK_14D_AOSD_ROUND_ATTR7              0x14D
    #define BITEK_MASK_AOSD_ROUND_L14               0x0F
    #define BITEK_MASK_AOSD_ROUND_L15               0xF0

#define BITEK_14E_AOSD_WH_MSB                   0x14E
   #define BITEK_MASK_AOSD_W_MSB                    0x03
   #define BITEK_MASK_AOSD_H_MSB                    0x0C
   #define BITEK_MASK_AOSD_DLY                      0xF0

#define BITEK_14F_AOSD_NUM                      0x14F

#define BITEK_150_AOSD_ATTR                     0x150
   #define BITEK_MASK_AOSD_FADEVAL                  0x0F
   #define BITEK_MASK_AOSD_FFADE_EN                 0x10
   #define BITEK_MASK_AOSD_BFADE_EN                 0x20
   #define BITEK_MASK_AOSD_ANI                      0x40
   #define BITEK_MASK_AOSD_BIG                      0x80

#define BITEK_151_AOSD_ATTR1                    0x151
   #define BITEK_MASK_AOSD_PATSEL                   0x01
   #define BITEK_MASK_AOSD_MSFSEL                   0x02
   #define BITEK_MASK_AOSD_RLCEN                    0x04
   #define BITEK_MASK_AOSD_ROUND                    0x20
   #define BITEK_MASK_AOSD_TRANSPARENT              0x40
   #define BITEK_MASK_AOSD_ENX                      0x80

#define BITEK_152_AOSD_DELTA_LSB                0x152
#define BITEK_153_AOSD_DELTA_MSB                0x153

#define BITEK_154_AOSD_OFFSET                   0x154
#define BITEK_154_AOSD_OFFSET_LSB               0x154
#define BITEK_155_AOSD_OFFSET_MSB               0x155

#define BITEK_156_AOSD_FADETHD0                 0x156
#define BITEK_157_AOSD_FADETHD1                 0x157

#define BITEK_158_AOSD_ATTR2                    0x158
      #define BITEK_MASK_AOSD_REGSEL                0x03
      #define BITEK_MASK_AOSD_ROUNDSEL              0x04
      #define BITEK_MASK_AOSD_POL                   0x38
      #define BITEK_MASK_AOSD_OSEL                  0xC0

#define BITEK_159_AOSD_ATTR3                    0x159
   #define BITEK_MASK_AOSD_PATBANK                  0x07
   #define BITEK_MASK_AOSD_PAT_SEL                  0x08  //Same as 0x12E bit3
   #define BITEK_MASK_AOSD_LOAD_TYPE                0x10
   #define BITEK_MASK_AOSD_LOAD_EN                  0x20
   #define BITEK_MASK_AOSD_EN                       0x40

   #define BITEK_MASK_AOSDPAT_BANK0                 0x00
   #define BITEK_MASK_AOSDPAT_BANK1                 0x01
   #define BITEK_MASK_AOSDPAT_BANK2                 0x02
   #define BITEK_MASK_AOSDPAT_BANK3                 0x03
   #define BITEK_MASK_AOSDPAT_BANK4                 0x04
   #define BITEK_MASK_AOSDPAT_BANK5                 0x05
   #define BITEK_MASK_AOSDPAT_BANK6                 0x06
   #define BITEK_MASK_AOSDPAT_BANK7                 0x07

   #define BITEK_MASK_AOSDPAT_R0                    0x00    // AOSD Palette0Color R
   #define BITEK_MASK_AOSDPAT_G0                    0x01    // AOSD Palette0Color G
   #define BITEK_MASK_AOSDPAT_B0                    0x02    // AOSD Palette0Color B
   #define BITEK_MASK_AOSDPAT_DUMMY                 0x03    // AOSD Dummy
   #define BITEK_MASK_AOSDPAT_R1                    0x04    // AOSD Palette1Color R
   #define BITEK_MASK_AOSDPAT_G1                    0x05    // AOSD Palette1Color G
   #define BITEK_MASK_AOSDPAT_B1                    0x06    // AOSD Palette1Color B

#define BITEK_15A_AOSD_CNT                      0x15A

#define BITEK_15B_AOSD_INFO_O                   0x15B
   #define BITEK_MASK_AOSD_END_O                    0x01
   #define BITEK_MASK_AOSD_PAT_BUSY_O               0x02
   #define BITEK_MASK_AOSD_INIT_BUSY_O              0x04

#define BITEK_15C_AOSD_BUSINF_ATTR              0x15C
   #define BITEK_MASK_AOSD_BUSINF_CLK_POL           0x01
   #define BITEK_MASK_AOSD_BUSINF_SRST              0x02


#define BITEK_15D_AOSD_DUMMY                    0x15D
#define BITEK_15E_AOSD_OPCODE                   0x15E
#define BITEK_15F_AOSD_ATTR                     0x15F
    #define BITEK_MASK_AOSD_BASE                    0x03
    #define BITEK_MASK_AOSD_SEL                     0x0C
    #define BITEK_MASK_AOSD_RSTATUS_EN              0x10
    #define BITEK_MASK_AOSD_CS_AUTO_EN              0x20

    #define BITEK_MASK_AOSD_BUSY                    0x80

#define BITEK_160_M8051_DUMMY                   0x160
#define BITEK_161_M8051_OPCODE                  0x161

#define BITEK_162_M8051_ATTR4                   0x162
   #define BITEK_MASK_M8051_SEL                     0x07
    #define BITEK_MASK_M8051_BURST_SEL              0x38

    #define BITEK_MASK_M51_BURST_2B                 0x00
    #define BITEK_MASK_M51_BURST_4B                 0x08
    #define BITEK_MASK_M51_BURST_8B                 0x10
    #define BITEK_MASK_M51_BURST_16B                0x18
    #define BITEK_MASK_M51_BURST_32B                0x20
    #define BITEK_MASK_M51_BURST_64B                0x28
    #define BITEK_MASK_M51_BURST_128B               0x30
    #define BITEK_MASK_M51_BURST_256B               0x38


    #define BITEK_MASK_I2C_SPEED08                  0x40

    #define BITEK_MASK_EEPROM_TYPE                  0x80
    #define BITEK_MASK_EEPROM_24C16                 0x00
    #define BITEK_MASK_EEPROM_24C32                 0x80

#define BITEK_163_I2C_SPEED07_00                0x163
// MSF
#define BITEK_164_MSF_ATTR                      0x164
    #define BITEK_MASK_M51_LOAD_EN                  0x01
    #define BITEK_MASK_MSF_TOUT                     0x02
    #define BITEK_MASK_MSF_BIT32_LEVEL              0x0C
    #define BITEK_MASK_MSF_BIT32_EN                 0x10
    #define BITEK_MASK_MSF_SRC                      0x60
    #define BITEK_MASK_MSF_CS_SEL                   0x80

#define BITEK_165_DMA_SPEED                     0x165
   #define BITEK_MASK_DMA_SPEED                     0x7F

#define BITEK_166_DMA_COUNT07_00                0x166
#define BITEK_167_DMA_COUNT15_08                0x167

#define BITEK_168_DMA_EADDR07_00                0x168
#define BITEK_169_DMA_EADDR15_08                0x169
#define BITEK_16A_DMA_EADDR23_16                0x16A
#define BITEK_16B_DMA_RADDR07_00                0x16B
#define BITEK_16C_DMA_RADDR15_08                0x16C

#define BITEK_16D_DMA_DIN                       0x16D
#define BITEK_16E_DMA_OPCODE                    0x16E

#define BITEK_16F_DMA_ATTR                      0x16F
    #define BITEK_MASK_DMA_SEL                      0x0F
    #define BITEK_MASK_DMA_BURST_SEL                0xF0

    #define BITEK_MASK_DMA_BURST_1B                 0x00
    #define BITEK_MASK_DMA_BURST_2B                 0x10
    #define BITEK_MASK_DMA_BURST_4B                 0x20
    #define BITEK_MASK_DMA_BURST_8B                 0x30
    #define BITEK_MASK_DMA_BURST_16B                0x40
    #define BITEK_MASK_DMA_BURST_32B                0x50
    #define BITEK_MASK_DMA_BURST_64B                0x60
    #define BITEK_MASK_DMA_BURST_128B               0x70
    #define BITEK_MASK_DMA_BURST_256B               0x80
    #define BITEK_MASK_DMA_BURST_512B               0x90
    #define BITEK_MASK_DMA_BURST_1K                 0xA0
    #define BITEK_MASK_DMA_BURST_2K                 0xB0
    #define BITEK_MASK_DMA_BURST_4K                 0xC0
    #define BITEK_MASK_DMA_BURST_8K                 0xD0
    #define BITEK_MASK_DMA_BURST_16K                0xE0
    #define BITEK_MASK_DMA_BURST_32K                0xF0


#define BITEK_170_DMA_ATTR1                     0x170
    #define BITEK_MASK_DMA_EN                       0x01    // DMA Enable (rising edge)
    #define BITEK_MASK_DMA_DIS                      0x00
    #define BITEK_MASK_DMA_WAITRDY_EN               0x02
    #define BITEK_MASK_DMA_RSTATUS_EN               0x04
    #define BITEK_MASK_DMA_WENABLE_EN               0x08
    #define BITEK_MASK_DMA_BUS                      0x10
    #define BITEK_MASK_DMA_SPI_BUS                  0x00   //For Flash
    #define BITEK_MASK_DMA_I2C_BUS                  0x10   //For EEPROM
    #define BITEK_MASK_DMA_NWR                      0x20
    #define BITEK_MASK_DMA_WRITE_MODE               0x00
    #define BITEK_MASK_DMA_READ_MODE                0x20
    #define BITEK_MASK_DMA_CONT                     0x40
    #define BITEK_MASK_DMA_CONT_DIS                 0x00
    #define BITEK_MASK_DMA_CONT_EN                  0x40
    #define BITEK_MASK_MSF_ERR_EN                   0x80

#define BITEK_171_DMA_OUT                       0x171

#define BITEK_172_DMA_INFO                      0x172
    #define BITEK_MASK_BUSINF_CONFLICT_O            0x07
    #define BITEK_MASK_BUSINF_STATUS_O              0x18
    #define BITEK_MASK_BUSINF_INISEQ_O              0x20
    #define BITEK_MASK_DMA_BUSY_O                   0x40
    #define BITEK_MASK_DMA_NEXT_O                   0x80

#define BITEK_173_BUSINF_INFO                   0x173
    #define BITEK_MASK_BUSINF_STEP_O                0x0F

// [1] IR Receive
#define BITEK_174_IR_CC07_00                    0x174       // UDCC[7:0]     Code bar
#define BITEK_175_IR_CC15_08                    0x175       // UDCC[15:8]    Code

#define BITEK_176_IR_ATTR                       0x176
    #define BITEK_MASK_IR_POL                       0x01
    #define BITEK_MASK_IR_DISREPT                   0x02
    #define BITEK_MASK_IR_BASE                      0x1C
    #define BITEK_MASK_IR_CHECK                     0xE0

#define BITEK_177_IR_ATTR1                      0x177
    #define BITEK_MASK_IR_EN                        0x01
    #define BITEK_MASK_IR_OUT_SEL                   0x02
    #define BITEK_MASK_IR_DB                        0x0C
    #define BITEK_MASK_IR_TYPE_ACLR                 0x10
    #define BITEK_MASK_IR_TYPE_O                    0x80    // READ ONLY (1=REPEAT)

#define BITEK_178_IR_DATA                       0x178       //R_IR_CODE_I[0:7]  / R_IR_CODE_I[8:15]
#define BITEK_179_IR_CODE                       0x179       //R_IR_CODE_I[16:23]/ R_IR_CODE_I[24:31]

// [1] IR Send
#define BITEK_17A_IR_SEND_ATTR                  0x17A
#define BITEK_17A_IR_SEND_CODE                  0x17A
#define BITEK_17A_IR_SEND_CODEBAR               0x17A
#define BITEK_17A_IR_SEND_DATA                  0x17A
#define BITEK_17A_IR_SEND_DATABAR               0x17A

#define BITEK_17B_IR_REPEAT                     0x17B
#define BITEK_17C_IR_SEND_BASE07_00             0x17C

#define BITEK_17D_IR_SEND_ATTR1                 0x17D
    #define BITEK_MASK_IR_SEND_BASE14_08            0x7F
    #define BITEK_MASK_IR_SEND_EN                   0x80

#define BITEK_17E_IR_SEND_ATTR2                 0x17E
    #define BITEK_MASK_IR_SEND_SEL                  0x03
    #define BITEK_MASK_IR_SEND_POL                  0x08
    #define BITEK_MASK_IR_SEND_BUSY_O               0x80


// [1] PWM Function
#define BITEK_17F180_PWMx_FREQ                  0x17F       // PWMx Frequency[7:0]
#define BITEK_180_PWMx_ATTR                     0x180
    #define BITEK_MASK_PWMx_FREQ_MSB                0x0F    // PWMx Frequency[11:8]
    #define BITEK_MASK_PWMx_REF                     0xF0    // PWMxReference Cycles

#define BITEK_181182_PWMx_DUTY                  0x181       // PWMx Duty[7:0]
#define BITEK_182_PWMx_ATTR1                    0x182       // PWMx Duty[11:8]
    #define BITEK_MASK_PWMx_DUTY_MSB                0x0F    // PWMx Output Duty Cycles
    #define BITEK_MASK_PWMx_POL                     0x20    // PWMx Polarity (0=Normal, 1=Invert)
    #define BITEK_MASK_PWMx_SYNC                    0xC0    // PWMx synchronize with VS

#define BITEK_183_PWMx_ATTR2                    0x183
    #define BITEK_MASK_PWMx_SEL                     0x03    // PWMx output select
    #define BITEK_MASK_PWMx_INV                     0x10
    #define BITEK_MASK_PWM0_EN                      0x20    // PWM0 Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_PWM1_EN                      0x40    // PWM1 Enable (0=Disable, 1=Enable)
    #define BITEK_MASK_PWM2_EN                      0x80    // PWM2 Enable (0=Disable, 1=Enable)

// 0x184: NONE

// [1] SPI Transer Function
#define BITEK_185_SPI_ATTR                      0x185
    #define BITEK_MASK_SPI_INV                      0x07
    #define BITEK_MASK_SPI_SCL_POL                  0x01
    #define BITEK_MASK_SPI_SDA_POL                  0x02
    #define BITEK_MASK_SPI_CS_POL                   0x04
    #define BITEK_MASK_SPI_SDAM                     0x08
    #define BITEK_MASK_SPI_SCLM                     0x30
    #define BITEK_MASK_SPI_SPEED                    0xC0

#define BITEK_186_SPI_DATA07_00                 0x186       // 24bits SPI Transfer Data
#define BITEK_187_SPI_DATA15_08                 0x187
#define BITEK_188_SPI_DATA23_16                 0x188

#define BITEK_189_SPI_ATTR1                     0x189
    #define BITEK_MASK_SPI_BIT                      0x1F
    #define BITEK_MASK_SPI_BUSY_O                   0x20
    #define BITEK_MASK_SPI_SYNC                     0x40
    #define BITEK_MASK_SPI_EN                       0x80

// [1] Timer
#define BITEK_18A_TIMER_ATTR                    0x18A
    #define BITEK_MASK_T0_BASE                      0x03
    #define BITEK_MASK_T1_BASE                      0x0C
    #define BITEK_MASK_T2_BASE                      0x30
    #define BITEK_MASK_T22_BASE                     0xC0

// 0x18B: NONE

// [1] GPI and KEY Function
#define BITEK_18C_KEY_SRC0                      0x18C       //
#define BITEK_18D_KEY_SRC1                      0x18D       //
#define BITEK_18E_KEY_ACK                       0x18E       // Key Trigger Status
#define BITEK_18F_KEY_POL                       0x18F       // Key Source Polarity
#define BITEK_190_KEY_TYPE0                     0x190       // Key detect type select
#define BITEK_191_KEY_TYPE1                     0x191       // Key detect type select
#define BITEK_192_KEY_LONG_EN                   0x192       // Long Key detect enable
#define BITEK_193_KEY_LONG_SEL                  0x193       // Long Key detect type

#define BITEK_194_KEY_ATTR                      0x194
    #define BITEK_MASK_KEY_LONG_TIME                0x1F    // Long Key detect time
    #define BITEK_MASK_KEY_DB                       0xE0    // De-bounce time

#define BITEK_195_KEY_FLAG_O                    0x195       // Key Detection Status
#define BITEK_196_KEY_STATUS_O                  0x196       // Key Real Time Status
#define BITEK_197_KEY_LONG_O                    0x197       // Long Key Status

// [1] PLL and OSC Pads
#define BITEK_198_PLL_DM_M0                     0x198       // PLL DM Value
   #define BITEK_MASK_PLL_DM_M0                     0x1F

#define BITEK_199_PLL_DN_M0                     0x199       // PLL DN Value
   #define BITEK_MASK_PLL_DN_M0                     0x7F

#define BITEK_19A_PLL_DP_M0                     0x19A       // PLL DP Value
   #define BITEK_MASK_PLL_DP_M0                     0x3F

#define BITEK_19B_PLL_DM_M1                     0x19B       // PLL DM Value
   #define BITEK_MASK_PLL_DM_M1                     0x1F

#define BITEK_19C_PLL_DN_M1                     0x19C       // PLL DN Value
   #define BITEK_MASK_PLL_DN_M1                     0x7F

#define BITEK_19D_PLL_DP_M1                     0x19D       // PLL DP Value
   #define BITEK_MASK_PLL_DP_M1                     0x3F

#define BITEK_19E_PLL_ATTR1                     0x19E
    #define BITEK_MASK_PLL_PD                       0x01    // PLL Power Down Enable (0=Normal, 1=Disable)
    #define BITEK_MASK_PLL_RESETN                   0x02    // PLL Reset (0=Reset, 1=Normal)
    #define BITEK_MASK_PLL_HALFCLK                  0x04    // Half clock output
    #define BITEK_MASK_PLL_SEL                      0x08    // PLL clock control


// [1] SARADC
#define BITEK_19F_SARADC_ATTR                   0x19F
    #define BITEK_MASK_SARADC_SLEEP                 0x01
    #define BITEK_MASK_SARADC_LOWSPEED              0x02
    #define BITEK_MASK_SARADC_RDB                   0x04
    #define BITEK_MASK_SARADC_WRB                   0x08
    #define BITEK_MASK_SARADC_REF_SEL_L             0x30
    #define BITEK_MASK_SARADC_REF_SEL_H             0xC0

#define BITEK_1A0_SARADC_ATTR1                  0x1A0
    #define BITEK_MASK_SARADC_YP_O                  0x01
    #define BITEK_MASK_SARADC_XP_O                  0x02
    #define BITEK_MASK_SARADC_YM_O                  0x04
    #define BITEK_MASK_SARADC_XM_O                  0x08
    #define BITEK_MASK_SARADC_YP_C                  0x10
    #define BITEK_MASK_SARADC_XP_C                  0x20
    #define BITEK_MASK_SARADC_YM_C                  0x40
    #define BITEK_MASK_SARADC_XM_C                  0x80

#define BITEK_1A1_SARADC12_SEL                  0x1A1
    #define BITEK_MASK_SARADC1_INSEL                0x07
    #define BITEK_MASK_SARADC2_INSEL                0x38
    #define BITEK_MASK_SARADC_MODE                  0xC0

#define BITEK_1A2_SARADC34_SEL                  0x1A2
    #define BITEK_MASK_SARADC3_INSEL                0x07
    #define BITEK_MASK_SARADC4_INSEL                0x38
    #define BITEK_MASK_SARADC_OUTSEL                0xC0

#define BITEK_1A3_SARADC_SWITCH                 0x1A3

// [1] ADC Data Interface

#define BITEK_1A4_ADC_COMP_MSB                  0x1A4
#define BITEK_1A5_ADC_COMP_ATTR                 0x1A5
    #define BITEK_MASK_ADC_COMP_LSB                 0x0F
    #define BITEK_MASK_ADC_COMP_LOAD                0xF0

#define BITEK_1A6_ADC_THD                       0x1A6       // ADC value change threshold
#define BITEK_1A7_ADC_ATTR                      0x1A7       //
    #define BITEK_MASK_ADC_DB                       0x0F    // ADC Low Pass Filter Threshold
    #define BITEK_MASK_ADC_THDLOAD                  0xF0

#define BITEK_1A8_ADC_COMP_ATTR1                 0x1A8
    #define BITEK_MASK_ADC_COMP_SEL                 0x01
    #define BITEK_MASK_ADC_COMP_CODE_SEL            0x02

#define BITEK_1A9_ADC_INT_ATTR                  0x1A9
    #define BITEK_MASK_ADC_INT_CLR                  0x0F
    #define BITEK_MASK_ADC_INT_EN                   0xF0

#define BITEK_1AA_SARADC_OUT_I_MSB              0x1AA
#define BITEK_1AB_SARADC_OUT_I_LSB              0x1AB
#define BITEK_1AC_SARADC_INFO                   0x1AC
    #define BITEK_MASK_ADC_INT_FLAG_O               0x0F
    #define BITEK_MASK_SARADC_INTRB_O               0x10
    #define BITEK_MASK_SARADC_EOC_O                 0x20

// [1] I2C Slave
#define BITEK_1AE_I2C_S_MAD                     0x1AE       // I2C Slave MAD Address
    #define BITEK_MASK_I2C_S_MAD                    0xFE

#define BITEK_1AF_I2C_S_MASK                    0x1AF       // I2C Slave MAD Mask
    #define BITEK_MASK_I2C_S_MASK                   0xFE

#define BITEK_1B0_I2C_S_TBUF                    0x1B0       // I2C Slave Transfer Data

#define BITEK_1B1_I2C_S_ATTR                    0x1B1
    #define BITEK_MASK_I2C_S_EN                     0x01    // I2C Slave function enable
    #define BITEK_MASK_I2C_S_INT                    0x02    // I2C Slave MAD interrupt
    #define BITEK_MASK_I2C_S_BUSY_O                 0x10    // I2C Busy form Start to End signal
    #define BITEK_MASK_I2C_S_BUS_RW_O               0x20    //
    #define BITEK_MASK_I2C_S_START_O                0x40    // I2C Get Start signal
    #define BITEK_MASK_I2C_S_INT_RW_O               0x80    // I2C Slave Status

#define BITEK_1B2_I2C_S_RBUF_O                  0x1B2       // I2C Slave Receive Data

// [1] I2C Master
#define BITEK_1B3_I2C_M_SPEED                   0x1B3
#define BITEK_1B4_I2C_M_WDATA                   0x1B4

#define BITEK_1B5_I2C_M_ATTR                    0x1B5
    #define BITEK_MASK_I2C_M_STOP                   0x01
    #define BITEK_MASK_I2C_M_RACK_EN                0x02
    #define BITEK_MASK_I2C_M_WACK_EN                0x04
    #define BITEK_MASK_I2C_M_RDATA_EN               0x08
    #define BITEK_MASK_I2C_M_WDATA_EN               0x10
    #define BITEK_MASK_I2C_M_START                  0x20
    #define BITEK_MASK_I2C_M_EN                     0x80

#define BITEK_1B6_I2C_M_RDATA_O                 0x1B6
#define BITEK_1B7_I2C_M_INFO                    0x1B7
    #define BITEK_MASK_I2C_M_ACK_O                  0x01
    #define BITEK_MASK_I2C_M_BUSY_O                 0x02

// 0x1B8: NONE

// I80/M68 Panel
#define BITEK_1B9_CPU_ATTR                      0x1B9
    #define BITEK_MASK_CPU_SKIPNUM                  0x0F
    #define BITEK_MASK_CPU_16BITMODE                0x70

#define BITEK_1BA_CPU_DATAI08_01                0x1BA       // CPU DATAI[08:01]
#define BITEK_1BB_CPU_DATAI17_10                0x1BB       // CPU DATAI[17:10]

#define BITEK_1BC_CPU_ATTR1                     0x1BC
    #define BITEK_MASK_CPU_END                      0x01
    #define BITEK_MASK_CPU_REGSBYTE                 0x02
    #define BITEK_MASK_CPU_BUSBIT                   0x0C
    #define BITEK_MASK_CPU_BUSMODE                  0x10
    #define BITEK_MASK_CPU_CMD                      0x60
    #define BITEK_MASK_CPU_EN                       0x80

#define BITEK_1BD_CPU_ATTR2                     0x1BD
    #define BITEK_MASK_CPU_DATAI0                   0x01    // CPU DATAI[0]
    #define BITEK_MASK_CPU_DATAI9                   0x02    // CPU DATAI[9]
    #define BITEK_MASK_CPU_FIELD                    0x04
    #define BITEK_MASK_CPU_SKIPFRAME                0x08
    #define BITEK_MASK_CPU_DATA0_O                  0x40    // CPU DATAO[0]
    #define BITEK_MASK_CPU_DATA9_O                  0x80    // CPU DATAO[9]

#define BITEK_1BE_CPU_DATAO08_01_O              0x1BE       // CPU DATAO[08:01]
#define BITEK_1BF_CPU_DATAO17_10_O              0x1BF       // CPU DATAO[17:10]


// Status
#define BITEK_1C0_M8051_BREAK_INFO              0x1C0
    #define BITEK_MASK_M8051_BREAK_SRC_O            0x07
    #define BITEK_MASK_M8051_BREAK_TYPE_O           0x30
    #define BITEK_MASK_M8051_BREAK_O                0x80


#define BITEK_1C1_ITU656_CID_O                  0x1C1
    #define BITEK_MASK_ITU656_CID_O                 0x0F

#define BITEK_1C2_IS_XP_O                       0x1C2
#define BITEK_1C31C6_IS_XT_O                    0x1C3
#define BITEK_1C4_IS_YP_O                       0x1C4
#define BITEK_1C51C6_IS_YT_O                    0x1C5
#define BITEK_1C6_IS_T_MSB                      0x1C6
    #define BITEK_MASK_IS_YT_MSB_O                  0x07
    #define BITEK_MASK_IS_XT_MSB_O                  0xF0

#define BITEK_1C71C9_DE_H_O                     0x1C7
#define BITEK_1C81C9_DE_V_O                     0x1C8
#define BITEK_1C9_DE_MSB_O                      0x1C9
    #define BITEK_MASK_DE_H_MSB_O                   0x07
    #define BITEK_MASK_DE_V_MSB_O                   0x30


// [1] Auto Detection
#define BITEK_1CA1CC_DET_XP_O                   0x1CA       // HS Low pulse                   in PCLK
#define BITEK_1CB1CC_DET_XN_O                   0x1CB
#define BITEK_1CC_DET_X_MSB_O                   0x1CC
    #define BITEK_MASK_DET_XN_MSB_O                 0x0F
    #define BITEK_MASK_DET_XP_MSB_O                 0xF0

#define BITEK_1CD_DET_STATUS_O                  0x1CD
    #define BITEK_MASK_MODE_CHG_O                   0x01    // Mode Change Status
    #define BITEK_MASK_MODE_TYPE_O                  0x02    // Mode Status (0=50Hz, 1=60Hz)
    #define BITEK_MASK_EVEN_SAME_O                  0x04    // EVEN Type status (0=Exist, 1=NONE)
    #define BITEK_MASK_SIGIN_O                      0x08
    #define BITEK_MASK_AUTOON_O                     0x10    // Auto On Status (0=Normal, 1=Freerun)
    #define BITEK_MASK_SWAPMODE_O                   0x20    // Auto Switch Status (0=Mode0, 1=Mode1)
    #define BITEK_MASK_IEVEN_O                      0x40    // Input  EVEN/ODD Information (0=Even, 1=Odd)
    #define BITEK_MASK_OEVEN_O                      0x80    // Output EVEN/ODD Information (0=Even, 1=Odd)

#define BITEK_1CE1CF_DET_LINEBUF_COUNT_O        0x1CE       // Line buffer count

#define BITEK_1CF_DET_LINEBUF_STATUS_O          0x1CF       // Line buffer status
    #define BITEK_MASK_DET_LINEBUF_COUNT_MSB_O      0x3F    // Line buffer count
    #define BITEK_MASK_DET_LINEBUF_ERR_TYPE_O       0x60    // Line buffer error status
    #define BITEK_MASK_DET_LINEBUF_ERR_TIMING_O     0x80    // Line buffer timing error


#define BITEK_1D01D1_CB_DCLAMP_O                0x1D0
#define BITEK_1D0_CB_DCLAMP15_08_O              0x1D0
#define BITEK_1D1_CB_DCLAMP07_00_O              0x1D1

#define BITEK_1D21D3_CR_DCLAMP_O                0x1D2
#define BITEK_1D2_CR_DCLAMP15_08_O              0x1D2
#define BITEK_1D3_CR_DCLAMP07_00_O              0x1D3

#define BITEK_1D41D5_Y_DCLAMP_O                 0x1D4
#define BITEK_1D4_Y_DCLAMP15_08_O               0x1D4
#define BITEK_1D5_Y_DCLAMP07_00_O               0x1D5

#define BITEK_1D61D7_Y_DGAIN_O                  0x1D6

#define BITEK_1D7_GAIN_O                        0x1D7
    #define BITEK_MASK_Y_DGAIN_MSB_O                0x03
    #define BITEK_MASK_LUMA_AMPCOMP_MSB_O           0x0C
    #define BITEK_MASK_AGAIN2_O                     0x30
    #define BITEK_MASK_AGAIN1_O                     0xC0

#define BITEK_1D81D7_LUMA_AMPCOMP_O             0x1D8
#define BITEK_1D8_LUMA_AMPCOMP_LSB_O            0x1D8

#define BITEK_1D9_OVER_COMP_O                   0x1D9

#define BITEK_1DA_INCHRO16_O                    0x1DA
    #define BITEK_MASK_INCCHRO16_O                  0x80    // INCCHRO_O[16]
    #define BITEK_MASK_STD_BGPU_POS_O               0x1F


#define BITEK_1DB_INCCHRO15_08_O                0x1DB       // INCCHRO_O[15:8]
#define BITEK_1DC_INCCHRO07_00_O                0x1DC       // INCCHRO_O[ 7:0]

#define BITEK_1DD1DF_STD_GAINOUT_O              0x1DD
#define BITEK_1DE1DF_STD_PHASEOUT_O             0x1DE

#define BITEK_1DF_AFE_INFO_O                    0x1DF
    #define BITEK_MASK_PHASEOUT_MSB_O               0x07
    #define BITEK_MASK_GAINOUT_MSB_O                0xF0

// [1] VBI Data Slicer
#define BITEK_1E0_CC_INFO_O                     0x1E0
    #define BITEK_MASK_CB_DET_O                     0x01    //
    #define BITEK_MASK_CR_DET_O                     0x02    //
    #define BITEK_MASK_Y_DET_O                      0x04    //
    #define BITEK_MASK_MV_DET_O                     0x08    // MV source
    #define BITEK_MASK_MV_TYPE_O                    0x30    // MV type   on Chroma
    #define BITEK_MASK_CC_ERROR_O                   0x40    // Data Slicer Error
    #define BITEK_MASK_CC_INT_O                     0x80    // Data Slicer Interrupt

#define BITEK_1E1_CC_DATA1_EVEN_O               0x1E1       // Data Slicer First Byte   for EVEN field  [1]48
#define BITEK_1E2_CC_DATA2_EVEN_O               0x1E2       // Data Slicer Second Byte  for EVEN field
#define BITEK_1E3_CC_DATA1_ODD_O                0x1E3       // Data Slicer First Byte   for ODD field
#define BITEK_1E4_CC_DATA2_ODD_O                0x1E4       // Data Slicer Second Byte  for ODD field

#define BITEK_1E5_VD_INFO_O                     0x1E5
    #define BITEK_MASK_VD_READY_O                   0x01
    #define BITEK_MASK_VD_HLCK_O                    0x02    // H-LOCK
    #define BITEK_MASK_SYNC_READY_O                 0x04
    #define BITEK_MASK_STD_READY_O                  0x08
    #define BITEK_MASK_VD_STDCHG_O                  0x10
    #define BITEK_MASK_VTRC_O                       0x20    // Auto VTRC mode

// [1] Standard Setting and detection
#define BITEK_1E6_STD_INFO_O                    0x1E6
    #define BITEK_MASK_STD_MODE_O                   0x07
    #define BITEK_MASK_FIDT_O                       0x08    // 0=50Hz, 1=60Hz

    #define BITEK_MASK_STD_PAL                      0x00        // 50Hz
    #define BITEK_MASK_STD_PAL_N                    0x01        // 50Hz
    #define BITEK_MASK_STD_SECAM                    0x02        // 50Hz
    #define BITEK_MASK_STD_PAL_M                   (0x03 + 8)   // 60Hz
    #define BITEK_MASK_STD_NTSC443_50               0x04        // 50Hz
    #define BITEK_MASK_STD_NTSC_M                  (0x05 + 8)   // 60Hz
    #define BITEK_MASK_STD_NTSC443_60              (0x06 + 8)   // 60Hz
    #define BITEK_MASK_STD_BLACK_WHITE50            0x07        // 50Hz
    #define BITEK_MASK_STD_BLACK_WHITE60           (0x07 + 8)   // 60Hz
    #define BITEK_MASK_STD_PAL_60                  (0x00 + 8)   // 60Hz

    #define BITEK_MASK_STD_FREQ_O                   0x30
    #define BITEK_MASK_STD_PHASE_O                  0x40
    #define BITEK_MASK_COLORDET_O                   0x80

#define BITEK_1E71EA_Y_ADC_O                    0x1E7           // MSB
#define BITEK_1E81EA_CB_ADC_O                   0x1E8           // MSB
#define BITEK_1E91EA_CR_ADC_O                   0x1E9           // MSB
#define BITEK_1EA_ADC_LSB_O                     0x1EA
    #define BITEK_MASK_Y_ADC_LSB_O                  0x03
    #define BITEK_MASK_CB_ADC_LSB_O                 0x0C
    #define BITEK_MASK_CR_ADC_LSB_O                 0x30

//#define BITEK_1EB_Y_COMPENSATE                0x1EB

#define BITEK_1EB_MSF_STEP_INFO0_O              0x1EB
#define BITEK_MASK_MSF_DMA_STEP_O                   0x1F
#define BITEK_MASK_MSF_M51_STEP_O                   0xE0

#define BITEK_1EC_MSF_STEP_INFO1_O              0x1EC
#define BITEK_MASK_MSF_STEP_O                       0x1F
#define BITEK_MASK_MSF_AOSD_STEP_O                  0xE0

#define BITEK_1ED_EEPROM_STEP_INFO0_O           0x1ED
#define BITEK_MASK_EEPROM_DMA_STEP_O                0x0F
#define BITEK_MASK_EEPROM_M51_STEP_O                0x70

#define BITEK_1EE_EEPROM_STEP_INFO1_O           0x1EE
#define BITEK_MASK_EEPROM_STEP_O                    0x0F

//0x1EF: NONE

// DAC Adjustment
#define BITEK_1F0_DAC_OFFSET                    0x1F0
#define BITEK_1F1_DAC_AMP                       0x1F1
#define BITEK_1F2_DAC_CLAMP_H                   0x1F2
#define BITEK_1F3_DAC_CLAMP_L                   0x1F3

#define BITEK_1F4_DAC_ATTR                      0x1F4
    #define BITEK_MASK_DAC_DITHER                   0x01
    #define BITEK_MASK_DAC_CLAMP                    0x02
    #define BITEK_MASK_SPI1690_LSB                  0x04
    #define BITEK_MASK_SPI1690_EN                   0x08
    #define BITEK_MASK_B1690_BUSY_O                 0x80

#define BITEK_1F5_B1690_DI_O                    0x1F5

// 0x1F6 - 0x1F7: NONE

// BIT1690
#define BITEK_1F8_DAC_ADDR                      0x1F8
    #define BITEK_MASK_DAC_DEGLITCH                 0x01
    #define BITEK_MASK_DAC_SRST                     0x02
    #define BITEK_MASK_DAC_CLKINV                   0x04
    #define BITEK_MASK_DAC_CEA                      0x08
    #define BITEK_MASK_DAC_C0                       0x10
    #define BITEK_MASK_DAC_C1                       0x20

#define BITEK_1F9_DAC_RED                       0x1F9
#define BITEK_1FA_DAC_GREEN                     0x1FA
#define BITEK_1FB_DAC_BLUE                      0x1FB

#define BITEK_1FC_DAC_ATTR1                     0x1FC
    #define BITEK_MASK_DAC_SYNC_R                   0x01
    #define BITEK_MASK_DAC_SYNC_G                   0x02
    #define BITEK_MASK_DAC_SYNC_B                   0x04
    #define BITEK_MASK_DAC_R_SRC                    0x08
    #define BITEK_MASK_DAC_G_SRC                    0x10
    #define BITEK_MASK_DAC_B_SRC                    0x20
    #define BITEK_MASK_DAC_TEST_EN                  0x40

#define BITEK_1FD_DAC_ATTR2                     0x1FD
    #define BITEK_MASK_REG_MODE                     0x01
    #define BITEK_MASK_BUS_SEL                      0x02

#define BITEK_1FE_1690_RESET                    0x1FE

#define BITEK_1FF_DAC_LCLK_ATTR                 0x1FF
    #define BITEK_MASK_DAC_LCLK_EN                  0x02
    #define BITEK_MASK_DAC_LCLK_SEL                 0x0C
    #define BITEK_MASK_DAC_LCLK_POL                 0x10
    #define BITEK_MASK_DAC_LCLK_SYNC                0x20
  //#define BITEK_MASK_DAC_PCLK_SYNC                0x20


// Memory mapping address (10:50AM  2013/01/10)
#define BITEK_000_0FF_REGISTER0                 0x000
#define BITEK_100_1F7_REGISTER1                 0x100
#define BITEK_1F8_1FF_BIT1690                   0x1F8

#define BITEK_200_2FF_GAMMA                     0x200   // Gamma Table
#define BITEK_300_3FF_OSDPAT                    0x300   // OSD Palette
#define BITEK_400_4FF_OSD_LSB                   0x400   // OSD RAM (Font Code)
#define BITEK_500_5FF_OSD_MSB                   0x500   // OSD RAM (Font Attr)
#define BITEK_400_4FF_UFONT_LSB                 0x400   // OSD User Font LSB
#define BITEK_500_5FF_UFONT_MSB                 0x500   // OSD User Font MSB

#define BITEK_600_6FF_IRAM                      0x600   // IRAM     @Break mode
#define BITEK_700_7FF_XRAM                      0x700   // XRAM     @Break mode

#define BITEK_600_6FF_SFR                       0x600
#define BITEK_700_7FF_ICACHE                    0x700   // ICACHE   @Break mode

#define RAM_8000_9FFF_OSD                       0x8000  // OSD RAM for Master mode ONLY !



/* ------------------------------------
    Type Definitions
   ------------------------------------ */


/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */


#endif /* _BIT1638_H_ */


/* **********************************************************************

    Description:


   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

