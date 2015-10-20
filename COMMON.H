/* **********************************************************************

         Copyright (c) 2002-2012 Beyond Innovation Technology Co., Ltd

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

    Module: COMMON.H -

    Purpose: Interface of COMMON.

    Version: 0.01                                   09:51AM  2012/05/02

    Compiler: Keil 8051 C Compiler v9.03

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 09:51AM  2012/05/02 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#ifndef _COMMON_H_
#define _COMMON_H_


/* ------------------------------------
    Header Files
   ------------------------------------ */


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _COMMON_C_
    #define EXTERN
#else
    #define EXTERN  extern
#endif


#define FALSE       0
#define TRUE        (! FALSE)

#define LOW         0
#define HIGH        (! LOW)

#define OFF         0
#define ON          (! OFF)

#define NO          0
#define YES         (! NO)

#define MINUS       0
#define PLUS        (! MINUS)


/* ::::::::::::::::::::::::::::::::::::
    MCU Memory Model Configuration
   :::::::::::::::::::::::::::::::::::: */
#define CODE                code
#define IDATA               idata
#define XDATA               xdata


/* ::::::::::::::::::::::::::::::::::::
    High/Low Byte (Big endian/Little endian)
   :::::::::::::::::::::::::::::::::::: */
#define HIBYTE(word)        ((word) >> 8)
#define LOBYTE(word)        ((UB8) word)


/* ------------------------------------
    Type Definitions
   ------------------------------------ */
/* [2]64 */
typedef bit                 BOOL;       /* Boolean */

typedef unsigned char       UB8;        /* 8-bit data */
typedef unsigned short int  UW16;       /*16-bit data */
typedef unsigned long       UL32;       /*32-bit data */

typedef signed char         SB8;        /* 8-bit data */
typedef signed short int    SW16;       /*16-bit data */
typedef signed long         SL32;       /*32-bit data */


/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */
EXTERN  UB8     bByte;
EXTERN  UW16    wWord;


/* ------------------------------------
    Function Prototypes
   ------------------------------------ */


#endif /* _COMMON_H_ */


/* **********************************************************************

    Description:

   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
