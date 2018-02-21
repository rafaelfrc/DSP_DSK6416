/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-05-04 (bios,dsk6416-f06)" */
struct PARMS {
	int Beta;
	int EchoPower;
	int ErrorPower;
	int Ratio;
	struct PARMS *Link;
};

