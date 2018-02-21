/*H***************************************************************************
*
* $Archive:: /TI/product/sdtsrv/user/sdti_reg2xx.c                           $
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
#define sdti_reg2xx_c

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

TREG_DESC SDTI_RegDef_2xx[] = 
{
    {"PC",       sizeof(TREG_16),        NOT_USED},  // PC
    {"AR0",      sizeof(TREG_16),        NOT_USED},  // FP
    {"AR1",      sizeof(TREG_16),        NOT_USED},  // SP
    {"AR2",      sizeof(TREG_16),        NOT_USED},
    {"AR3",      sizeof(TREG_16),        NOT_USED},
    {"AR4",      sizeof(TREG_16),        NOT_USED},
    {"AR5",      sizeof(TREG_16),        NOT_USED},
    {"AR6",      sizeof(TREG_16),        NOT_USED},
    {"AR7",      sizeof(TREG_16),        NOT_USED},
    {"ACC",      sizeof(TREG_32),        NOT_USED},
    {"ACCH",     sizeof(TREG_16),        NOT_USED},
    {"ACCL",     sizeof(TREG_16),        NOT_USED},
    {"PR",       sizeof(TREG_32),        NOT_USED},
    {"PRH",      sizeof(TREG_16),        NOT_USED},
    {"PRL",      sizeof(TREG_16),        NOT_USED},
    {"TR",       sizeof(TREG_16),        NOT_USED},
    {"GREG",     sizeof(TREG_16),        NOT_USED},
    {"IFR",      sizeof(TREG_16),        NOT_USED},
    {"IMR",      sizeof(TREG_16),        NOT_USED},
    {"ST0",      sizeof(TREG_16),        NOT_USED},
    {"ST1",      sizeof(TREG_16),        NOT_USED},
    {"TOS",      sizeof(TREG_16),        NOT_USED},
    {"RPTC",     sizeof(TREG_16),        NOT_USED},
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

