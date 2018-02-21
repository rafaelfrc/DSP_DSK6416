/**********************************************************************
*          (C) COPYRIGHT TEXAS INSTRUMENTS, INC. 2000 				  *
***********************************************************************
* FILENAME
*   c6416dsk.h -- Loosely copied from preliminary file
*
*
* DESCRIPTION
*   DSK Header File
*   Used by Russ as part of FlashBurn project.
*
*/

/* Register definitions for C6416 chip on DSK */

/* Define EMIF Registers  */
#define EMIF_CE1		0x1A80004	/* Address of EMIF CE1 control			*/


#define FLASH_SIZE		0x80000 
#define FLASH_START		0x64000000
#define FLASH_END		(FLASH_START + FLASH_SIZE)

#define FLASH_ADR1		0x64000AAA
#define FLASH_ADR2		0x64000555
#define FLASH_KEY1		0xAA
#define FLASH_KEY2		0x55
#define FLASH_KEY3		0xA0
#define FLASH_KEY4		0x80
#define FLASH_KEY5		0x10
#define CE1_8			0x02a08a00  /* reg to set CE1 as 8bit async */
#define CE1_32			0x02a08a20  /* reg to set CE1 as 32bit async */
