/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */
 
/*
 *  ======== dsk6416_flash.h ========
 *
 *  Interface for the AMD29LV400BT Flash on the DSK6416 board
 */
#ifndef DSK6416_FLASH_
#define DSK6416_FLASH_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>

/* Flash address definitions */
#define DSK6416_FLASH_BASE          0x64000000
#define DSK6416_FLASH_PAGESIZE      0x010000
#define DSK6416_FLASH_PAGES         0x8
#define DSK6416_FLASH_SIZE          0x080000
#define DSK6416_FLASH_CTL555        (DSK6416_FLASH_BASE + 0x555)
#define DSK6416_FLASH_CTLAAA        (DSK6416_FLASH_BASE + 0xaaa)
#define DSK6416_FLASH_SUPPORT       1
 
/* Calculate the checksum of a data range in Flash */
Uint32 DSK6416_FLASH_checksum(Uint32 start, Uint32 length);

/* Erase a segment of Flash memory */
void DSK6416_FLASH_erase(Uint32 start, Uint32 length);

/* Read data from a range in Flash */
void DSK6416_FLASH_read(Uint32 src, Uint32 dst, Uint32 length);

/* Write data to a data range in Flash */
void DSK6416_FLASH_write(Uint32 src, Uint32 dst, Uint32 length);

#ifdef __cplusplus
}
#endif

#endif

