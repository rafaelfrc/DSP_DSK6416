/*H***************************************************************************
*
* $Archive:: /TI/product/sdtsrv/user/sdti_reg54x.c                           $
* $Revision:: 2                                                              $
* $Date:: 5/04/01 7:38a                                                      $
* $Author:: Tonyc                                                            $
*
* DESCRIPTION:
*
* GLOBALS
*
* PUBLIC FUNCTIONS:
*                              
* PRIVATE FUNCTIONS:
*
* USAGE/LIMITATIONS:
*
* NOTES:

* (C) Copyright 1999 by Spectrum Digital Incorporated
* All rights reserved
*
*H***************************************************************************/
#define sdti_reg54x_c

/*---- compilation control switches ----------------------------------------*/

/*****************************************************************************
* INCLUDE FILES
*****************************************************************************/
/*---- system and platform files -------------------------------------------*/

/*---- program files -------------------------------------------------------*/
#include "sdti.h"

/*****************************************************************************
* EXTERNAL REFERENCE    
*****************************************************************************/
/*---- data declarations ---------------------------------------------------*/

/*---- function prototypes -------------------------------------------------*/

/*****************************************************************************
* PUBLIC DECLARATIONS 
*****************************************************************************/
/*---- context -------------------------------------------------------------*/

/*---- data declarations ---------------------------------------------------*/
#define NOT_USED  0

TREG_DESC SDTI_RegDef_54x[] = 
{
    {"PC",       sizeof(TREG_16),        NOT_USED},  // PC
    {"SP",       sizeof(TREG_16),        NOT_USED},  // SP
    {"AR0",      sizeof(TREG_16),        NOT_USED},  // 
    {"AR1",      sizeof(TREG_16),        NOT_USED},
    {"AR2",      sizeof(TREG_16),        NOT_USED},
    {"AR3",      sizeof(TREG_16),        NOT_USED},
    {"AR4",      sizeof(TREG_16),        NOT_USED},
    {"AR5",      sizeof(TREG_16),        NOT_USED},
    {"AR6",      sizeof(TREG_16),        NOT_USED},
    {"AR7",      sizeof(TREG_16),        NOT_USED},
    {"A",        sizeof(TREG_32),        NOT_USED},
    {"AL",       sizeof(TREG_16),        NOT_USED},
    {"AH",       sizeof(TREG_16),        NOT_USED},
    {"AG",       sizeof(TREG_16),        NOT_USED},
    {"B",        sizeof(TREG_32),        NOT_USED},
    {"BL",       sizeof(TREG_16),        NOT_USED},
    {"BH",       sizeof(TREG_16),        NOT_USED},
    {"BG",       sizeof(TREG_16),        NOT_USED},
    {"IMR",      sizeof(TREG_16),        NOT_USED},
    {"IFR",      sizeof(TREG_16),        NOT_USED},
    {"ST0",      sizeof(TREG_16),        NOT_USED},
    {"ST1",      sizeof(TREG_16)         NOT_USED},
    {"TREG",     sizeof(TREG_16),        NOT_USED},
	{"TRN",      sizeof(TREG_16),        NOT_USED},
    {"BK",       sizeof(TREG_16),        NOT_USED},
    {"BRC",      sizeof(TREG_16),        NOT_USED},
    {"RSA",      sizeof(TREG_16),        NOT_USED},
    {"REA",      sizeof(TREG_16),        NOT_USED},
    {"PMST",     sizeof(TREG_16),        NOT_USED},
	{"EXT_PC",   sizeof(TREG_32),        NOT_USED},
    {"PMR_ADDR", sizeof(TREG_16),        NOT_USED},
    {"PMR_PAGE", sizeof(TREG_16),        NOT_USED},
    {"PMR_MASK", sizeof(TREG_16),        NOT_USED},
    {"PMR_RANGE",sizeof(TREG_16),        NOT_USED},
    {"PMR_VAL",  sizeof(TREG_16),        NOT_USED},
    {"PMR_ACTIVE",sizeof(TREG_16),       NOT_USED},
    {(char *)NULL,             0,        NOT_USED}
};
/*---- macros --------------------------------------------------------------*/

/*****************************************************************************
* PRIVATE DECLARATIONS  
*****************************************************************************/
/*---- context -------------------------------------------------------------*/

/*---- data declarations ---------------------------------------------------*/

/*---- macros --------------------------------------------------------------*/

/*****************************************************************************
* PUBLIC FUNCTION DEFINITIONS
*****************************************************************************/

/*****************************************************************************
* PRIVATE FUNCTION DEFINITIONS
*****************************************************************************/

/*F***************************************************************************
* NAME:    
*
* DESCRIPTION:  
*       
* NOTES:  
*   
*F***************************************************************************/    

