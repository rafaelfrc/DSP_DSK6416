/*H***************************************************************************
*
* $Archive:: /TI/product/sdtsrv/user/sdti_reg55x.c                           $
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
#define sdti_reg55x_c

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
extern void SDTI_PutErrMsg( char * ErrMessage );

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

static TREG_DESC SDTI_RegDef_55x[] = 
{             
    {"PC",        sizeof(TREG_32),        NOT_USED   },  // 0x52 
    {"SP",        sizeof(TREG_16),        NOT_USED   },  // 0x18 
    {"SSP",       sizeof(TREG_16),        NOT_USED   },  // 0x4C
	{"SPH",       sizeof(TREG_16),        NOT_USED   },  // 0x4E
	{"ST0",       sizeof(TREG_16),        NOT_USED   },  // 0x02
	{"ST1",       sizeof(TREG_16),        NOT_USED   },  // 0x03
	{"ST2",       sizeof(TREG_16),        NOT_USED   },  // 0x4B
	{"ST3",       sizeof(TREG_16),        NOT_USED   },  // 0x04 

	{"AC0",       sizeof(TREG_32),        NOT_USED   },  // 0x09-0x08
    {"AG0",       sizeof(TREG_16),        NOT_USED   },  // 0x0A
	{"AC1",       sizeof(TREG_32),        NOT_USED   },  // 0x0C-0x0B
    {"AG1",       sizeof(TREG_16),        NOT_USED   },  // 0x0D
	{"AC2",       sizeof(TREG_32),        NOT_USED   },  // 0x25-0x24
    {"AG2",       sizeof(TREG_16),        NOT_USED   },  // 0x26
	{"AC3",       sizeof(TREG_32),        NOT_USED   },  // 0x29-0x28
    {"AG3",       sizeof(TREG_16),        NOT_USED   },  // 0x2A

    {"AR0",       sizeof(TREG_16),        NOT_USED   },  // 0x10
    {"AR1",       sizeof(TREG_16),        NOT_USED   },  // 0x11
    {"AR2",       sizeof(TREG_16),        NOT_USED   },  // 0x12
    {"AR3",       sizeof(TREG_16),        NOT_USED   },  // 0x13
    {"AR4",       sizeof(TREG_16),        NOT_USED   },  // 0x14
    {"AR5",       sizeof(TREG_16),        NOT_USED   },  // 0x15
    {"AR6",       sizeof(TREG_16),        NOT_USED   },  // 0x16
    {"AR7",       sizeof(TREG_16),        NOT_USED   },  // 0x17

	{"BK03",      sizeof(TREG_16),        NOT_USED   },  // 0x19
	{"BK47",      sizeof(TREG_16),        NOT_USED   },  // 0x30
	{"BKC",       sizeof(TREG_16),        NOT_USED   },  // 0x31

	{"BRC0",      sizeof(TREG_16),        NOT_USED   },  // 0x1A
	{"BRC1",      sizeof(TREG_16),        NOT_USED   },  // 0x39
	{"BRS1",      sizeof(TREG_16),        NOT_USED   },  // 0x3A
	
    {"BSA01",     sizeof(TREG_16),        NOT_USED   },  // 0x32
    {"BSA23",     sizeof(TREG_16),        NOT_USED   },  // 0x33
	{"BSA45",     sizeof(TREG_16),        NOT_USED   },  // 0x34
	{"BSA67",     sizeof(TREG_16),        NOT_USED   },  // 0x35
	{"BSAC",      sizeof(TREG_16),        NOT_USED   },  // 0x36
	
    {"CDP",       sizeof(TREG_16),        NOT_USED   },  // 0x27
	{"CDPH",      sizeof(TREG_16),        NOT_USED   },  // 0x4F
    {"CSR",       sizeof(TREG_16),        NOT_USED   },  // 0x3B
	{"DP",        sizeof(TREG_16),        NOT_USED   },  // 0x2E
	{"DPH",       sizeof(TREG_16),        NOT_USED   },  // 0x2B
    {"MDPO5",     sizeof(TREG_16),        NOT_USED   },  // 0x2C
    {"MDP67",     sizeof(TREG_16),        NOT_USED   },  // 0x2D
	
    {"DBIER0",    sizeof(TREG_16),        NOT_USED   },  // 0x47
	{"DBIER1",    sizeof(TREG_16),        NOT_USED   },  // 0x48
	{"IER0",      sizeof(TREG_16),        NOT_USED   },  // 0x00
	{"IER1",      sizeof(TREG_16),        NOT_USED   },  // 0x45
	{"IFR0",      sizeof(TREG_16),        NOT_USED   },  // 0x01
	{"IFR1",      sizeof(TREG_16),        NOT_USED   },  // 0x46
	{"IVDP",      sizeof(TREG_16),        NOT_USED   },  // 0x49
	{"IVDPH",     sizeof(TREG_16),        NOT_USED   },  // 0x4A
	{"PDP",       sizeof(TREG_16),        NOT_USED   },  // 0x2F
    
    {"RSA0L",     sizeof(TREG_16),        NOT_USED   },  // 0x1B
	{"REA0",      sizeof(TREG_32),        NOT_USED   },  // 0x3E-0x3F
	{"REA1",      sizeof(TREG_32),        NOT_USED   },  // 0x42-0x43

    {"REA0L",     sizeof(TREG_16),        NOT_USED   },  // 0x1C
	{"RSA0",      sizeof(TREG_32),        NOT_USED   },  // 0x3C-0x3D
	{"RSA1",      sizeof(TREG_32),        NOT_USED   },  // 0x40-0x41
    
    {"RPTC",      sizeof(TREG_16),        NOT_USED   },  // 0x44

	{"T0",        sizeof(TREG_16),        NOT_USED   },  // 0x20
	{"T1",        sizeof(TREG_16),        NOT_USED   },  // 0x21
	{"T2",        sizeof(TREG_16),        NOT_USED   },  // 0x22
    {"T3",        sizeof(TREG_16),        NOT_USED   },  // 0x23
	{"TRN0",      sizeof(TREG_16),        NOT_USED   },  // 0x0F
	{"TRN1",      sizeof(TREG_16),        NOT_USED   },  // 0x38

    {"ST0P",      sizeof(TREG_16),        NOT_USED   },  // 0x06
	{"ST1P",      sizeof(TREG_16),        NOT_USED   },  // 0x07
	{"PMST",      sizeof(TREG_16),        NOT_USED   },  // 0x1D
	{"XPC",       sizeof(TREG_16),        NOT_USED   },  // 0x1E
	{"BIOS",      sizeof(TREG_16),        NOT_USED   },  // 0x37
    
	{"XAR0",      sizeof(TREG_32),        NOT_USED   },  // (XARS:ARx)
	{"XAR1",      sizeof(TREG_32),        NOT_USED   },
	{"XAR2",      sizeof(TREG_32),        NOT_USED   },
	{"XAR3",      sizeof(TREG_32),        NOT_USED   },
	{"XAR4",      sizeof(TREG_32),        NOT_USED   },
	{"XAR5",      sizeof(TREG_32),        NOT_USED   },
	{"XAR6",      sizeof(TREG_32),        NOT_USED   },
	{"XAR7",      sizeof(TREG_32),        NOT_USED   },
	{"XCDP",      sizeof(TREG_32),        NOT_USED   },  // CDPH:CDP
	{"XDP",       sizeof(TREG_32),        NOT_USED   },  // MDP:DP 
	{"XSP",       sizeof(TREG_32),        NOT_USED   },  // SPH:SP 
	{"XSSP",      sizeof(TREG_32),        NOT_USED   },  // SPH:SSP
	{"RETA",      sizeof(TREG_32),        NOT_USED   },  
    {"CFCT",      sizeof(TREG_16),        NOT_USED   },
    {(char *)NULL,             0,              0     }
};

