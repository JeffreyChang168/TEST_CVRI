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

    Module: OSD.H -

    Purpose: Interface of OSD.

    Version: 0.01                                   05:07PM  2013/03/18

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 05:07PM  2013/03/18 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#ifndef _OSD_H_
#define _OSD_H_

/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bit1618c.h"
#include "common.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _OSD_C_
    #define EXTERN
#else
    #define EXTERN  extern
#endif


#define PROGRESS_TV         0
#define PROGRESS_PC         1
#define PROGRESS_BAR        PROGRESS_TV


#define OSD_SHOW_HEX                ON
#define OSD_SHOW_PROGRESS_BAR       ON
#define OSD_SHOW_VALUE              ON


/* ::::::::::::::::::::::::::::::::::::
    OSD Configuration
   :::::::::::::::::::::::::::::::::::: */
#define OSD0_OFF                    0x04
#define OSD0_ON                     0x84
#define OSD1_OFF                    0x04
#define OSD1_ON                     0x84
#define OSD2_OFF                    0x04
#define OSD2_ON                     0x84


/* .....................................
    OSD Windows Configuration
   ..................................... */

// =====================================
// OSD Display
#define OSD_DISPLAY_CODE            BITEK_400_4FF_OSD_LSB

// OSD0
#define OSD0_WIDTH                  10
#define OSD0_HEIGHT                 1
#define OSD0_AREA                   (OSD0_WIDTH * OSD0_HEIGHT   )

#define VP_SHOW_OSD0                OSD_DISPLAY_CODE
#define VP_SHOW_OSD0_LSB            ((VP_SHOW_OSD0 >> 0) & 0xFF )
#define VP_SHOW_OSD0_MSB            ((VP_SHOW_OSD0 >> 8) & 0x07 )

#define VP_SHOW_OSD0_ROW0           (VP_SHOW_OSD0                       )
#define VP_SHOW_OSD0_ROW1           (VP_SHOW_OSD0_ROW0 + OSD0_WIDTH     )
#define VP_SHOW_OSD0_ROW2           (VP_SHOW_OSD0_ROW1 + OSD0_WIDTH     )


// OSD1
#define OSD1_WIDTH                  20
#define OSD1_HEIGHT                 7
//#define OSD1_WIDTH                1
//#define OSD1_HEIGHT               1
#define OSD1_AREA                   (OSD1_WIDTH * OSD1_HEIGHT   )

#define VP_SHOW_OSD1                (VP_SHOW_OSD0 + OSD0_AREA   )
#define VP_SHOW_OSD1_LSB            ((VP_SHOW_OSD1 >> 0) & 0xFF )
#define VP_SHOW_OSD1_MSB            ((VP_SHOW_OSD1 >> 8) & 0x07 )

#define VP_SHOW_OSD1_ROW0           (VP_SHOW_OSD1                       )
#define VP_SHOW_OSD1_ROW1           (VP_SHOW_OSD1_ROW0 + OSD1_WIDTH     )
#define VP_SHOW_OSD1_ROW2           (VP_SHOW_OSD1_ROW1 + OSD1_WIDTH     )
#define VP_SHOW_OSD1_ROW3           (VP_SHOW_OSD1_ROW2 + OSD1_WIDTH     )
#define VP_SHOW_OSD1_ROW4           (VP_SHOW_OSD1_ROW3 + OSD1_WIDTH     )
#define VP_SHOW_OSD1_ROW5           (VP_SHOW_OSD1_ROW4 + OSD1_WIDTH     )
#define VP_SHOW_OSD1_ROW6           (VP_SHOW_OSD1_ROW5 + OSD1_WIDTH     )
#define VP_SHOW_OSD1_ROW7           (VP_SHOW_OSD1_ROW6 + OSD1_WIDTH     )


// OSD2
#define OSD2_WIDTH                  20
#define OSD2_HEIGHT                 2
#define OSD2_AREA                   (OSD2_WIDTH * OSD2_HEIGHT   )

#define VP_SHOW_OSD2                (VP_SHOW_OSD1 + OSD1_AREA   )
#define VP_SHOW_OSD2_LSB            ((VP_SHOW_OSD2 >> 0) & 0xFF )
#define VP_SHOW_OSD2_MSB            ((VP_SHOW_OSD2 >> 8) & 0x07 )

#define VP_SHOW_OSD2_ROW0           (VP_SHOW_OSD2                       )
#define VP_SHOW_OSD2_ROW1           (VP_SHOW_OSD2_ROW0 + OSD2_WIDTH     )
#define VP_SHOW_OSD2_ROW2           (VP_SHOW_OSD2_ROW1 + OSD2_WIDTH     )

////////////////////////////////////////////////////////////////////////////////
// OSD0
#define VP_SHOW_COLOR_STD           (VP_SHOW_OSD0_ROW0                  )

// OSD1
#define VP_SHOW_IR_TX               (VP_SHOW_OSD1_ROW3                  )

#define VP_SHOW_IR_IN0              (VP_SHOW_OSD1_ROW0          )
#define VP_SHOW_IR_IN1              (VP_SHOW_IR_IN0 + 3         )
#define VP_SHOW_IR_REPEAT           (VP_SHOW_IR_IN0 + 5         )
#define VP_SHOW_IR_TEST             (VP_SHOW_OSD1_ROW1          )

#define VP_SHOW_SARADC              (VP_SHOW_OSD1_ROW0                  )
#define VP_SHOW_SARADC1             (VP_SHOW_OSD1_ROW0                  )
#define VP_SHOW_SARADC2             (VP_SHOW_OSD1_ROW1                  )
#define VP_SHOW_SARADC3             (VP_SHOW_OSD1_ROW2                  )
#define VP_SHOW_SARADC4             (VP_SHOW_OSD1_ROW3                  )

#define VP_SHOW_TIMER0              (VP_SHOW_OSD1_ROW0 + OSD1_WIDTH - 5)
#define VP_SHOW_TIMER1              (VP_SHOW_OSD1_ROW1 + OSD1_WIDTH - 5)
#define VP_SHOW_TIMER2              (VP_SHOW_OSD1_ROW2 + OSD1_WIDTH - 5)

#define VP_SHOW_DEBUG0              (VP_SHOW_OSD1_ROW0                  )
#define VP_SHOW_DEBUG1              (VP_SHOW_OSD1_ROW1                  )
#define VP_SHOW_DEBUG2              (VP_SHOW_OSD1_ROW2                  )
#define VP_SHOW_DEBUG3              (VP_SHOW_OSD1_ROW3                  )

// OSD2
#define VP_SHOW_UART_TXD            (VP_SHOW_OSD2_ROW2          )
#define VP_SHOW_UART_RXD            (VP_SHOW_OSD2_ROW2 + 2      )

#define VP_SHOW_DATE                (VP_SHOW_OSD2_ROW0                  )
#define VP_SHOW_VERSION             (VP_SHOW_OSD2_ROW1                  )

#define VP_SHOW_TITLE               (VP_SHOW_OSD2_ROW0                  )
#define VP_SHOW_VALUE               (VP_SHOW_OSD2_ROW0 + OSD2_WIDTH - 3 )
#define VP_SHOW_DEBUG_A             (VP_SHOW_OSD2_ROW0 + 10             )
#define VP_SHOW_DEBUG_B             (VP_SHOW_OSD2_ROW0 + 13             )

#define VP_SHOW_BAR_TV              (VP_SHOW_OSD2_ROW1 + 0              )   // For PROGRESS TV
#define VP_SHOW_BAR_PC              (VP_SHOW_OSD2_ROW1 + 0              )   // For PROGRESS PC
#define VP_SHOW_BAR                 (VP_SHOW_OSD2_ROW1 + 0              )

// =====================================
// OSD Attribute
#define OSD_DISPLAY_ATTR            BITEK_500_5FF_OSD_MSB

// OSD0
#define VP_ATTR_OSD0                OSD_DISPLAY_ATTR
#define VP_ATTR_OSD0_ROW0           (VP_ATTR_OSD0                   )
#define VP_ATTR_OSD0_ROW1           (VP_ATTR_OSD0_ROW0 + OSD0_WIDTH )
#define VP_ATTR_OSD0_ROW2           (VP_ATTR_OSD0_ROW1 + OSD0_WIDTH )

// OSD1
#define VP_ATTR_OSD1                (VP_ATTR_OSD0 + OSD0_AREA       )
#define VP_ATTR_OSD1_ROW0           (VP_ATTR_OSD1                   )
#define VP_ATTR_OSD1_ROW1           (VP_ATTR_OSD1_ROW0 + OSD1_WIDTH )
#define VP_ATTR_OSD1_ROW2           (VP_ATTR_OSD1_ROW1 + OSD1_WIDTH )
#define VP_ATTR_OSD1_ROW3           (VP_ATTR_OSD1_ROW2 + OSD1_WIDTH )
#define VP_ATTR_OSD1_ROW4           (VP_ATTR_OSD1_ROW3 + OSD1_WIDTH )
#define VP_ATTR_OSD1_ROW5           (VP_ATTR_OSD1_ROW4 + OSD1_WIDTH )
#define VP_ATTR_OSD1_ROW6           (VP_ATTR_OSD1_ROW5 + OSD1_WIDTH )
#define VP_ATTR_OSD1_ROW7           (VP_ATTR_OSD1_ROW6 + OSD1_WIDTH )


// OSD2
#define VP_ATTR_OSD2                (VP_ATTR_OSD1 + OSD1_AREA       )
#define VP_ATTR_OSD2_ROW0           (VP_ATTR_OSD2                   )
#define VP_ATTR_OSD2_ROW1           (VP_ATTR_OSD2 + OSD1_WIDTH      )

////////////////////////////////////////////////////////////////////////////////
#define VP_ATTR_HINT                (VP_ATTR_OSD0)

#define VP_ATTR_MENU                (VP_ATTR_OSD1_ROW0)
#define VP_ATTR_MAINMENU            (VP_ATTR_OSD1_ROW0)
#define VP_ATTR_SUBMENU             (VP_ATTR_OSD1_ROW1)
#define VP_ATTR_PROGRESSBAR         (VP_ATTR_OSD1_ROW7)

#define VP_ATTR_VOLUME              (VP_ATTR_OSD2_ROW0)
#define VP_ATTR_VOLUME_PROGRESSBAR  (VP_ATTR_OSD2_ROW1)

/* .....................................
    OSD Palette Color Configuration
   ..................................... */
                                            //          B G R
#define OSD_BLACK                   0       // Black    0 0 0
#define OSD_RED                     1       // Red      0 0 1
#define OSD_GREEN                   2       // Green    0 1 0
#define OSD_YELLOW                  3       // Yellow   0 1 1
#define OSD_BLUE                    4       // Blue     1 0 0
#define OSD_MAGENTA                 5       // Magenta  1 0 1
#define OSD_CYAN                    6       // Cyan     1 1 0
#define OSD_WHITE                   7       // White    1 1 1
#define OSD_GREY                    8       // Grey     1 1 1

                                            //          B G R
#define OSD_R_BLACK                 0x00    // Black    0 0 0
#define OSD_R_RED                   0x3F    // Red      0 0 1
#define OSD_R_GREEN                 0x00    // Green    0 1 0
#define OSD_R_YELLOW                0x3F    // Yellow   0 1 1
#define OSD_R_BLUE                  0x00    // Blue     1 0 0
#define OSD_R_MAGENTA               0x3F    // Magenta  1 0 1
#define OSD_R_CYAN                  0x00    // Cyan     1 1 0
#define OSD_R_WHITE                 0x3F    // White    1 1 1
#define OSD_R_GREY                  0x20    // Grey     1 1 1

                                            //          B G R
#define OSD_G_BLACK                 0x00    // Black    0 0 0
#define OSD_G_RED                   0x00    // Red      0 0 1
#define OSD_G_GREEN                 0x3F    // Green    0 1 0
#define OSD_G_YELLOW                0x3F    // Yellow   0 1 1
#define OSD_G_BLUE                  0x00    // Blue     1 0 0
#define OSD_G_MAGENTA               0x00    // Magenta  1 0 1
#define OSD_G_CYAN                  0x3F    // Cyan     1 1 0
#define OSD_G_WHITE                 0x3F    // White    1 1 1
#define OSD_G_GREY                  0x20    // Grey     1 1 1

                                            //          B G R
#define OSD_B_BLACK                 0x00    // Black    0 0 0
#define OSD_B_RED                   0x00    // Red      0 0 1
#define OSD_B_GREEN                 0x00    // Green    0 1 0
#define OSD_B_YELLOW                0x00    // Yellow   0 1 1
#define OSD_B_BLUE                  0x3F    // Blue     1 0 0
#define OSD_B_MAGENTA               0x3F    // Magenta  1 0 1
#define OSD_B_CYAN                  0x3F    // Cyan     1 1 0
#define OSD_B_WHITE                 0x3F    // White    1 1 1
#define OSD_B_GREY                  0x20    // Grey     1 1 1


/* .....................................
    OSD Attribute Configuration
   ..................................... */
/* .....................................
    OSD Palette Attribute Configuration
   ..................................... */
#define OSD_NONE                    0x00
#define OSD_FG_FADE                 0x01    // Foreground Fade
#define OSD_BG_FADE                 0x02    // Background Fade
#define OSD_BLINK                   0x04    // Blink
#define OSD_2LAYER                  0x08    // 2 Layer
#define OSD_TRANSPARENT             0x10    // Transparent

//                                    // BG=YELLOW,    FG=RED
//#define OSD0_ATTR_LSB               ((OSD_YELLOW << 4)   | OSD_RED          )
//#define OSD0_ATTR_MSB               (OSD_NONE                               )

                                    // BG=BLACK,    FG=GREEN
#define OSD0_ATTR_LSB               ((OSD_BLACK << 4)   | OSD_GREEN         )
#define OSD0_ATTR_MSB               (OSD_TRANSPARENT                        )

                                    // BG=RED,      FG=YELLOW
#define OSD1_ATTR_LSB               ((OSD_RED << 4)     | OSD_YELLOW        )
#define OSD1_ATTR_MSB               (OSD_NONE                               )

									// BG=BLUE      FG=WHITE
#define OSD2_ATTR_LSB               ((OSD_BLUE << 4)    | OSD_WHITE         )
#define OSD2_ATTR_MSB               (OSD_NONE                               )



#ifdef NOT_JUNK
                                    // BG=BLACK,    FG=RED
#define OSD0_ATTR_LSB               ((OSD_RED << 4)     | OSD_GREEN         )
#define OSD0_ATTR_MSB               (OSD_NONE                               )

                                    // BG=GREEN,    FG=YELLOW
#define OSD1_ATTR_LSB               ((OSD_GREEN << 4)   | OSD_BLUE          )
#define OSD1_ATTR_MSB               (OSD_NONE                               )

                                    // BG=BLUE      FG=MAGENTA
#define OSD2_ATTR_LSB               ((OSD_BLUE << 4)    | OSD_RED           )
#define OSD2_ATTR_MSB               (OSD_NONE                               )
#endif


/* .....................................
    OSD Attribute Index
   ..................................... */
#define OSD_FONT_1BP                0x00
#define OSD_FONT_2BP                0x01
#define OSD_FONT_48BP               0x02        // BIT7: 0=4BP, 1=8BP
#define OSD_FONT_FIXED              0x03

#define OSD0_NM_ATTR                ((0 << 4)   | OSD_FONT_FIXED            )
#define OSD1_NM_ATTR                ((1 << 4)   | OSD_FONT_FIXED            )
#define OSD2_NM_ATTR                ((2 << 4)   | OSD_FONT_FIXED            )



/* ::::::::::::::::::::::::::::::::::::
    [1]125 OSD Fixed Font
   :::::::::::::::::::::::::::::::::::: */
#define FONT_00_DASH_0              0x00
#define FONT_01_DASH_1              0x01
#define FONT_02_DASH_2              0x02
#define FONT_03_DASH_3              0x03

#define FONT_0E_MUTE_OFF_SAVE       0x0E
#define FONT_0F_MUTE_ON_SAVE        0x0F

#define FONT_17_CONTRAST            0x17
#define FONT_18_SATURATION          0x18
#define FONT_19_HUE                 0x19
#define FONT_1B_BRIGHTNESS          0x1B

#define FONT_1C_LEFT_ARROW          0x1C
#define FONT_1D_RIGHT_ARROW         0x1D
#define FONT_20_BLANK               0x20

#define FONT_2F_SLASH               0x2F
#define FONT_30_DIGIT_0             0x30
#define FONT_31_DIGIT_1             0x31
#define FONT_39_DIGIT_9             0x39
#define FONT_3A                     0x3A
#define FONT_3C_CHECK_OFF           0x3C
#define FONT_2C_CHECK_ON            0x2C

#define FONT_00_TRACK_0             0x00
#define FONT_01_TRACK_1             0x01
#define FONT_06_TRACK_2             0x06
#define FONT_07_TRACK_3             0x07

#define FONT_5B_BAR_LEFT            0x5B
#define FONT_10_BAR_0               0x10
#define FONT_11_BAR_1               0x11
#define FONT_12_BAR_2               0x12
#define FONT_13_BAR_3               0x13
#define FONT_14_BAR_4               0x14
#define FONT_15_BAR_5               0x15
#define FONT_16_BAR_6               0x16
#define FONT_5D_BAR_RIGHT           0x5D

#define FONT_4E_N                   0x50
#define FONT_50_P                   0x50

#define FONT_DUMMY                  0x20



/* ------------------------------------
    Type Definitions
   ------------------------------------ */


/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */
#ifdef _OSD_C_

UB8 CODE abOSD_PALETTE_R[] = {
    OSD_R_BLACK     ,
    OSD_R_RED       ,
    OSD_R_GREEN     ,
    OSD_R_YELLOW    ,
    OSD_R_BLUE      ,
    OSD_R_MAGENTA   ,
    OSD_R_CYAN      ,
    OSD_R_WHITE     ,
    OSD_R_GREY      ,
};

UB8 CODE abOSD_PALETTE_G[] = {
    OSD_G_BLACK     ,
    OSD_G_RED       ,
    OSD_G_GREEN     ,
    OSD_G_YELLOW    ,
    OSD_G_BLUE      ,
    OSD_G_MAGENTA   ,
    OSD_G_CYAN      ,
    OSD_G_WHITE     ,
    OSD_G_GREY      ,
};


UB8 CODE abOSD_PALETTE_B[] = {
    OSD_B_BLACK     ,
    OSD_B_RED       ,
    OSD_B_GREEN     ,
    OSD_B_YELLOW    ,
    OSD_B_BLUE      ,
    OSD_B_MAGENTA   ,
    OSD_B_CYAN      ,
    OSD_B_WHITE     ,
    OSD_B_GREY      ,
};


UB8 CODE abOSD_PALETTE_A[] = {
    OSD0_ATTR_LSB    ,
    OSD0_ATTR_MSB    ,
    OSD1_ATTR_LSB    ,
    OSD1_ATTR_MSB    ,
    OSD2_ATTR_LSB    ,
    OSD2_ATTR_MSB    ,
};




UB8 CODE abOSD0_Setup[] = {
    0xBF,                                       // BITEK_100105_OSD0_X
    0x1C,                                       // BITEK_101105_OSD0_Y
    VP_SHOW_OSD0_LSB,                           // BITEK_102104_OSD0_INDEXS
    0x00,                                       // BITEK_103104_OSD0_INDEXB
    0x00,                                       // BITEK_104_OSD0_INDEX_MSB
    0x02,                                       // BITEK_105_OSD0_MSB
    OSD0_WIDTH - 1,                             // BITEK_106_OSD0_W
    OSD0_HEIGHT - 1,                            // BITEK_107_OSD0_H
    0x00,                                       // BITEK_108_OSD0_MUL
    0x00,                                       // BITEK_109_OSD0_SPC
    0x00,                                       // BITEK_10A_OSD0_FRINGE_SEL    OSD Fade Level
    0x30,                                       // BITEK_10B_OSD0_ATTR0         OSD Font Fringe
    0x00,                                       // BITEK_10C_OSD0_ATTR1
    0x04,                                       // BITEK_10D_OSD0_ATTR2
};


UB8 CODE abOSD1_Setup[] = {
    0x71,                                       // BITEK_110115_OSD1_X
    0x8D,                                       // BITEK_111115_OSD1_Y
    VP_SHOW_OSD1_LSB,                           // BITEK_112114_OSD1_INDEXS
    0x00,                                       // BITEK_113114_OSD1_INDEXB
    0x00,                                       // BITEK_114_OSD1_INDEX_MSB
    0x00,                                       // BITEK_115_OSD0_MSB
    OSD1_WIDTH - 1,                             // BITEK_116_OSD1_W
    OSD1_HEIGHT - 1,                            // BITEK_117_OSD1_H
    0x00,                                       // BITEK_118_OSD1_MUL
    0x00,                                       // BITEK_119_OSD1_SPC
    0x00,                                       // BITEK_11A_OSD1_FRINGE_SEL    OSD Fade Level
    0x30,                                       // BITEK_11B_OSD1_ATTR0         OSD Font Fringe
    0x00,                                       // BITEK_11C_OSD1_ATTR1
    0x84,                                       // BITEK_11D_OSD1_ATTR2         FOR_DEBUG !!!
};

UB8 CODE abOSD2_Setup[] = {
    0xCF,                                       // BITEK_120125_OSD2_X
    0xB3,                                       // BITEK_121125_OSD2_Y
    VP_SHOW_OSD2_LSB,                           // BITEK_122124_OSD2_INDEXS
    0x00,                                       // BITEK_123124_OSD2_INDEXB
    0x00,                                       // BITEK_124_OSD2_INDEX_MSB
    0x08,                                       // BITEK_125_OSD2_MSB
    OSD2_WIDTH - 1,                             // BITEK_126_OSD2_W
    OSD2_HEIGHT - 1,                            // BITEK_127_OSD2_H
    0x11,                                       // BITEK_128_OSD2_MUL           2X2Y
    0x00,                                       // BITEK_129_OSD2_SPC
    0x00,                                       // BITEK_12A_OSD2_FRINGE_SEL    OSD Fade Level
    0x30,                                       // BITEK_12B_OSD2_ATTR0         OSD Font Fringe
    0x00,                                       // BITEK_12C_OSD2_ATTR1
    0x04,                                       // BITEK_12D_OSD2_ATTR2
};


#else
    extern UB8 CODE abOSD_PALETTE_R[];
    extern UB8 CODE abOSD_PALETTE_G[];
    extern UB8 CODE abOSD_PALETTE_B[];
    extern UB8 CODE abOSD_PALETTE_A[];

    extern UB8 CODE abOSD0_Setup[];
  //extern UB8 CODE abOSD1_Setup[];
    extern UB8 CODE abOSD2_Setup[];
#endif


EXTERN UB8  bOSD_Cnt;
EXTERN BOOL fOSD_Vanish;


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */
#if (OSD_SHOW_HEX)
void OSD_ShowHex(UW16 wREG, UB8 bDATA);
#endif

void OSD_Init(void);


#if (OSD_SHOW_PROGRESS_BAR)
void OSD_ShowProgressBar(UW16 wREG, UB8 bDATA);
#endif

#if (OSD_SHOW_VALUE)
void OSD_ShowValue(UW16 wREG, UW16 wDATA, UW16 wMask, UB8  bBlank);
#endif

#endif /* _OSD_H_ */


/* **********************************************************************

    Description:

   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
