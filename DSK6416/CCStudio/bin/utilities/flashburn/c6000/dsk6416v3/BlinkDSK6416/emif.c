/*H*****************************************************************************
*
* $Archive::                                                                   $
* $Revision::                                                                  $
* $Date::                                                                      $
* $Author::                                                                    $
*
* DESCRIPTION:  TMS320C6416 DSK emif code 
*
* GLOBALS 
*
* PUBLIC FUNCTIONS:
*                              
* PRIVATE FUNCTIONS:
*
* USAGE/LIMITATIONS:
*
* NOTES: Assumptions:
*             TMS320C6416 DSK
*             CPLD connected to EMIF B, TBCE0
*             AMD29LV400BT flash connected to EMIF B, TBCE1
*             SDRAM connected to EMIF A, TACE0
*
* COMPILE SWITCHES:

*H***************************************************************************/
#define emif_c

/*---- compilation control switches ----------------------------------------*/

/*****************************************************************************
* INCLUDE FILES
*****************************************************************************/
/*---- system and platform files -------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <c6x.h>
/*---- program files -------------------------------------------------------*/

#include "c6416dsk.h"
#include "emif.h"

/*****************************************************************************
* EXTERNAL REFERENCE    
*****************************************************************************/
/*---- data declarations ---------------------------------------------------*/

/*---- function prototypes -------------------------------------------------*/

/*****************************************************************************
* PUBLIC DECLARATIONS 
*****************************************************************************/

/*---- data declarations ---------------------------------------------------*/

/*****************************************************************************
* PRIVATE DECLARATIONS  
*****************************************************************************/
/*---- context -------------------------------------------------------------*/

/*---- data declarations ---------------------------------------------------*/
	
/*---- function prototypes -------------------------------------------------*/

/*---- macros --------------------------------------------------------------*/

/*****************************************************************************
* PUBLIC FUNCTION DEFINITIONS
*****************************************************************************/
/*F***************************************************************************
* NAME:   EMIF_Init()
*
* DESCRIPTION: Setup the DSK EMIF A and B.       
*       
* NOTES:
*   
*F***************************************************************************/

void EMIF_Init( void )
{
    EMIFA_Config EmifA;
    EMIFB_Config EmifB;

    // These settings are for 720 MHz operation but will also work at 600 MHz 
	EMIFA_getConfig( &EmifA );
	EmifA.gblctl =  0x00012070;
	EmifA.cectl0 =  0xffffffd3;
	EmifA.sdctl  =  0x47115000;
	EmifA.sdtim  =  0x00000618;  // Optimally 0x750 at 720 MHz
	EmifA.sdext  =  0x001faf4d;
	EMIFA_config( &EmifA );
	
	EMIFB_getConfig( &EmifB );
	EmifB.gblctl = 0x00002060;
	EmifB.cectl0 = 0x02a08a00;
	EmifB.cectl1 = 0x02a08a00;
	EMIFB_config( &EmifB );
	
	return;
}
