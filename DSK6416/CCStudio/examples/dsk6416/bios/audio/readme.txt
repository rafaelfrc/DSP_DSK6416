TITLE
-----
Audio examples (swi_audio, tsk_audio, and pip_audio) for the C6416 DSK card.

USAGE
-----
These samples are tests for the audio aic23 codec on the TMS320C6416 DSK board 
and use the dsk6416_edma_aic23 mini-driver to transfer data to and from the 
serial port. Each of the samples must link both libraries from the generic 
driver and from the specific driver in order for it to function correctly. 
These libraries are called dsk6416_edma_aic23.l64 and c6x1x_edma_mcbsp.l64
and can be found in the audio directory as well.

DESCRIPTION
-----------
- swi_audio test:
  --------------
  This example demonstrates how an application can use a codec mini-driver via
  the SIO module in SWI threads. This is a loopback application. Audio is read
  from an input SIO, then send back out on an output SIO. This application is
  configured to use the DIO adapter.  This adapter library can be found in the
  CCS lib directory.

- tsk_audio test:
  --------------
  This example demonstrates how an application can use a codec mini-driver via
  the SIO module in TSK threads. This is a loopback application. Audio is read
  from an input SIO, then send back out on an output SIO. This application is 
  configured to use the DIO adapter.  This adapter library can be found in the
  CCS lib directory.

- pip_audio test:
  --------------
  This example demonstrates how an application can use a codec mini-driver via
  the PIP module in SWI threads. This is a loopback application. Audio is read
  from an input PIP, then send back out on an output PIP. This application is
  configured to use the PIO adapter.  This adapter library can be found in this
  local audio directory.

FILES
-----
- swi_audio64.pjt: project files to build the application swi_audio test.
- tsk_audio64.pjt: project files to build the application tsk_audio test.
- pip_audio64.pjt: project files to build the application pip_audio test.
- swi_audio.c: implementation of swi_audio test.
- tsk_audio.c: implementation of tsk_audio test.
- pip_audio.c: implementation of pip_audio test.
- readme.txt: this file

NOTES
-----
- Files in the library are compiled with "no optimization switch" turned on, 
  and the same is true for the project files. If you plan to use this module 
  in a project release, you should rebuild the library with optimization 
  turned on.

Known Problems At Release
-------------------------
- None.

Q&A
---
Q1: How do I run the sample test?
Q2: Where can I find the source code to the audio codec driver?
Q3: What is the documentation for writing IOM drivers?

---
Q1: How to run the sample test?
A1: Here are the steps to run the sample test:
    1) Connect a speaker to the board's audio output and an audio source to the
       board's audio input connector.
    2) Run CCS setup to specify the correct target board. 
    3) Start the musical audio source. 
    4) Open CCS and load .out file from the Debug directory within the DDK tree.
    5) Run the application. You should hear music playing continuously until 
       you halt the application. 

Q2: Where can I find the source code to the audio codec driver?
A2: The souce code to the driver used in the audio example can be found, along
    with many other driver examples and documentation, in the Device Driver 
    Developer's Kit (DDK).  The DDK can be down loaded at no cost from the TI 
    Developer's Village (at http://dspvillage.ti.com).

Q3: What is the documentation for writing IOM drivers?
A3: The literature number is SPRU616, DSP/BIOS Device Driver Developer's Guide.
