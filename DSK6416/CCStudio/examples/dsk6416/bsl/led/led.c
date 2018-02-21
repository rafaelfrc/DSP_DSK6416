/*
 *  Copyright 2003 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== led.c ========
 *
 *  This example blinks LED #0 at a rate of about 2.5 times per second using
 *  the LED module of the the 6416 DSK Board Support Library.  The example
 *  also reads the state of DIP switch #3 and lights LED #3 if the switch
 *  is depressed or turns it off if the switch is not depressed.
 *
 *  The purpose of this example is to demonstrate basic BSL usage as well
 *  as provide a project base for your own code.
 *
 *  Please see the 6416 DSK help file under Software/Examples for more
 *  detailed information.
 */

/*
 *  DSP/BIOS is configured using the DSP/BIOS configuration tool.  Settings
 *  for this example are stored in a configuration file called led.cdb.  At
 *  compile time, Code Composer will auto-generate DSP/BIOS related files
 *  based on these settings.  A header file called ledcfg.h contains the
 *  results of the autogeneration and must be included for proper operation.
 *  The name of the file is taken from led.cdb and adding cfg.h.
 */
#include "ledcfg.h"

/*
 *  The 6416 DSK Board Support Library is divided into several modules, each
 *  of which has its own include file.  The file dsk6416.h must be included
 *  in every program that uses the BSL.  This example also includes
 *  dsk6416_led.h and dsk6416_dip.h because it uses the LED and DIP modules.
 */
#include "dsk6416.h"
#include "dsk6416_led.h"
#include "dsk6416_dip.h"


/*
 *  main() - Main code routine, initializes BSL and runs LED application
 */

void main()
{
    /* Initialize the board support library, must be first BSL call */
    DSK6416_init();

    /* Initialize the LED and DIP switch modules of the BSL */
    DSK6416_LED_init();
    DSK6416_DIP_init();
    
    while(1)
    {
        /* Toggle LED #0 */
        DSK6416_LED_toggle(0);
        
        /* Check DIP switch #3 and light LED #3 accordingly, 0 = switch pressed */
        if (DSK6416_DIP_get(3) == 0)
            /* Switch pressed, turn LED #3 on */
            DSK6416_LED_on(3);
        else
            /* Switch not pressed, turn LED #3 off */
            DSK6416_LED_off(3);
            
        /* Spin in a software delay loop for about 200ms */
       DSK6416_waitusec(200000);
    }   
}
