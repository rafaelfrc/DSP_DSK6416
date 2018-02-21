/*H***************************************************************************
*
* $Archive:: /TI/product/sdtsrv/user/sdti_reg6x.c                            $
* $Revision:: 1                                                              $
* $Date:: 10/14/03 7:55a                                                     $
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

* (C) Copyright 2000 by Spectrum Digital Incorporated
* All rights reserved
*
*H***************************************************************************/
#define sdti_reg6x_c

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
/*---- Packet information for this device. ---------------------------------*/

/*-- Private data per instance of .dll -------------------------------------*/

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
#define NOT_USED  0

static TREG_DESC SDTI_RegDef_c6000[] = 
{
    {"PC",       sizeof(TREG_32),        NOT_USED    },  // PC
    {"SP",       sizeof(TREG_32),        NOT_USED    },  // SP 
    {"CSR",      sizeof(TREG_32),        NOT_USED    },
    {"A0",       sizeof(TREG_32),        NOT_USED    },
    {"A1",       sizeof(TREG_32),        NOT_USED    },
    {"A2",       sizeof(TREG_32),        NOT_USED    },
    {"A3",       sizeof(TREG_32),        NOT_USED    },
    {"A4",       sizeof(TREG_32),        NOT_USED    },
    {"A5",       sizeof(TREG_32),        NOT_USED    },
    {"A6",       sizeof(TREG_32),        NOT_USED    },
    {"A7",       sizeof(TREG_32),        NOT_USED    },
    {"A8",       sizeof(TREG_32),        NOT_USED    },
    {"A9",       sizeof(TREG_32),        NOT_USED    },
    {"A10",      sizeof(TREG_32),        NOT_USED    },
    {"A11",      sizeof(TREG_32),        NOT_USED    },
    {"A12",      sizeof(TREG_32),        NOT_USED    },
    {"A13",      sizeof(TREG_32),        NOT_USED    },
    {"A14",      sizeof(TREG_32),        NOT_USED    },
    {"A15",      sizeof(TREG_32),        NOT_USED    },
#if defined( PROD_C64 )
    {"A16",      sizeof(TREG_32),        NOT_USED    },
    {"A17",      sizeof(TREG_32),        NOT_USED    },
    {"A18",      sizeof(TREG_32),        NOT_USED    },
    {"A19",      sizeof(TREG_32),        NOT_USED    },
    {"A20",      sizeof(TREG_32),        NOT_USED    },
    {"A21",      sizeof(TREG_32),        NOT_USED    },
    {"A22",      sizeof(TREG_32),        NOT_USED    },
    {"A23",      sizeof(TREG_32),        NOT_USED    },
    {"A24",      sizeof(TREG_32),        NOT_USED    },
    {"A25",      sizeof(TREG_32),        NOT_USED    },
    {"A26",      sizeof(TREG_32),        NOT_USED    },
    {"A27",      sizeof(TREG_32),        NOT_USED    },
    {"A28",      sizeof(TREG_32),        NOT_USED    },
    {"A29",      sizeof(TREG_32),        NOT_USED    },
    {"A30",      sizeof(TREG_32),        NOT_USED    },
    {"A31",      sizeof(TREG_32),        NOT_USED    },
#endif
    {"B0",       sizeof(TREG_32),        NOT_USED    },
    {"B1",       sizeof(TREG_32),        NOT_USED    },
    {"B2",       sizeof(TREG_32),        NOT_USED    },
    {"B3",       sizeof(TREG_32),        NOT_USED    },
    {"B4",       sizeof(TREG_32),        NOT_USED    },
    {"B5",       sizeof(TREG_32),        NOT_USED    },
    {"B6",       sizeof(TREG_32),        NOT_USED    },
    {"B7",       sizeof(TREG_32),        NOT_USED    },
    {"B8",       sizeof(TREG_32),        NOT_USED    },
    {"B9",       sizeof(TREG_32),        NOT_USED    },
    {"B10",      sizeof(TREG_32),        NOT_USED    },
    {"B11",      sizeof(TREG_32),        NOT_USED    },
    {"B12",      sizeof(TREG_32),        NOT_USED    },
    {"B13",      sizeof(TREG_32),        NOT_USED    },
    {"B14",      sizeof(TREG_32),        NOT_USED    },
    {"B15",      sizeof(TREG_32),        NOT_USED    },
#if defined( PROD_C64 )
    {"B16",      sizeof(TREG_32),        NOT_USED    },
    {"B17",      sizeof(TREG_32),        NOT_USED    },
    {"B18",      sizeof(TREG_32),        NOT_USED    },
    {"B19",      sizeof(TREG_32),        NOT_USED    },
    {"B20",      sizeof(TREG_32),        NOT_USED    },
    {"B21",      sizeof(TREG_32),        NOT_USED    },
    {"B22",      sizeof(TREG_32),        NOT_USED    },
    {"B23",      sizeof(TREG_32),        NOT_USED    },
    {"B24",      sizeof(TREG_32),        NOT_USED    },
    {"B25",      sizeof(TREG_32),        NOT_USED    },
    {"B26",      sizeof(TREG_32),        NOT_USED    },
    {"B27",      sizeof(TREG_32),        NOT_USED    },
    {"B28",      sizeof(TREG_32),        NOT_USED    },
    {"B29",      sizeof(TREG_32),        NOT_USED    },
    {"B30",      sizeof(TREG_32),        NOT_USED    },
    {"B31",      sizeof(TREG_32),        NOT_USED    },
#endif

    {"AMR",      sizeof(TREG_32),        NOT_USED    },
    {"IFR",      sizeof(TREG_32),        NOT_USED    },
    {"ISR",      sizeof(TREG_32),        NOT_USED    },
    {"ICR",      sizeof(TREG_32),        NOT_USED    },
    {"IER",      sizeof(TREG_32),        NOT_USED    },
    {"ISTP",     sizeof(TREG_32),        NOT_USED    },
    {"IRP",      sizeof(TREG_32),        NOT_USED    },
    {"NRP",      sizeof(TREG_32),        NOT_USED    },
    {"ARP",      sizeof(TREG_32),        NOT_USED    },
#if defined( PROD_C64 )
    {"DIE",      sizeof(TREG_32),        NOT_USED   },
    {"PCE1",     sizeof(TREG_32),        NOT_USED   },
    {"GFPGFR",   sizeof(TREG_32),        NOT_USED   },
    {"EM",       sizeof(TREG_32),        NOT_USED   },
    {"ER",       sizeof(TREG_32),        NOT_USED   },
#endif
    {(char *)NULL,             0,              0       }
};
