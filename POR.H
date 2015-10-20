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

    Module: POR.H - Power-On Reset.

    Purpose: Interface of POR.

    Version: 0.01                                   08:18PM  2013/03/30

    Compiler: Keil 8051 C Compiler v9.03

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 08:18PM  2013/03/30 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#ifndef _POR_H_
#define _POR_H_

/* ------------------------------------
    Header Files
   ------------------------------------ */

/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#undef EXTERN

#ifdef _POR_C_
    #define EXTERN         
#else                      
    #define EXTERN  extern
#endif


/* ------------------------------------
    Type Definitions
   ------------------------------------ */

/* ------------------------------------
    Variables Definitions/Declarations
   ------------------------------------ */

/* ------------------------------------
    Function Prototypes
   ------------------------------------ */
void POR_Init(void);


#endif /* _POR_H_ */


/* **********************************************************************

    Description:

   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
