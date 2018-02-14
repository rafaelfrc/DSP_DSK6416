# DSP_DSK6416
Audio Processing Studies and Digital Communications with Digital Signal Processor TMS320C6416

## Target:
### [DSP TMS320C6416](http://www.ti.com/lit/ds/symlink/tms320c6416.pdf)

Fixed-point DSP  
Instruction cycle time mín 1.39 ns  
Word-lenght: 2 channels witch 16-bit each. 

### DSP Starter kit [TI DSK 6416](http://c6000.spectrumdigital.com/dsk6416/V3/docs/dsk6416_TechRef.pdf)

CODEC: [TLV320AIC23](http://www.ti.com/lit/ds/symlink/tlv320aic23.pdf)  
Sampling Frequency: 8 kHz, 16 kHz, 24 kHz, 32 kHz, 44.1 kHz, 48 kHz and 96 kHz  
Signal-to-noise ratio ADC 90 dBA, DAC 100 dBA (weighteid at 48 kHz)  
Software Control Via TI McBSP-Compatible Multiprotocol Serial Port  
Amplitude: 6 Vpp

## Environment:
C Programming language: ANSI C 1989 Version  
Compiler [TMS320C6000 Optimizing Compiler v7.4](http://www.ti.com/lit/ug/spru187u/spru187u.pdf)  
IDE [Code Composer Studio v7](http://processors.wiki.ti.com/index.php/Download_CCS#Code_Composer_Studio_Version_7_Downloads)
S.O. M$ Windows 10 (*nix systems requires offboard JTAG Emulator)

### APIs:

Chip Support Library: [CSL](http://processors.wiki.ti.com/index.php/Chip_support_library#C62x.2C_C671x.2C_C641x.2C_DM64x_Devices)  
Board support library: [BSL](http://c6000.spectrumdigital.com/dsk6416/V3/files/DSK6416.zip)  

***
Prof Dr [Fabrício Simões](http://www.ifba.edu.br/professores/fsimoes/), thanks for the guidance!
