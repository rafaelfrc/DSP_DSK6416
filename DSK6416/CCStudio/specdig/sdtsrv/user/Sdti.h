/*H***************************************************************************
*
* $Archive:: /TI/product/sdtsrv/user/Sdti.h                                  $
* $Revision:: 10                                                             $
* $Date:: 8/25/04 7:01a                                                      $
* $Author:: Tonyc                                                            $
*
* DESCRIPTION:
*
* USAGE/LIMITATIONS:
*
* NOTES:
*   
* (C) Copyright 2000 by Spectrum Digital Incorporated
* All rights reserved
*
*H***************************************************************************/

#ifndef sdti_h
#define sdti_h

/*---- compilation control switches ----------------------------------------*/

/*****************************************************************************
* INCLUDE FILES (minimize nesting of header files)
*****************************************************************************/
#if defined( _WIN32 )
    #if (_MSC_VER >= 900 )
       #define	WIN32_LEAN_AND_MEAN
       #define 	INC_OLE2
       #define	NOSERVICE
    #endif 

    #include <windows.h>
#else  
    #include <stdlib.h>
    #include <string.h>
    #include <file.h>
	// Define BOOL if not in a WIN32 environment
	#define BOOL int   
#endif
/*---- system and platform files -------------------------------------------*/

/*---- program files -------------------------------------------------------*/

/*****************************************************************************
* FILE CONTENT
*****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
* FUNCTIONAL AREA DETAIL
*****************************************************************************/
//----------------------------------------------------------------------------
// Interface Version/Revision 
//
#define SDTI_VERSION        2
#define SDTI_REVISION       1

//----------------------------------------------------------------------------
// Sub-Interface Version/Revision 
//

// REVISION 2 - changes
// 1) Added support for CCS v3 TRG_INIT changes as well as TRG_connect and
//    TRG_disconnect.  The SDTI connect function will check to see if low
//    level driver is built for CCS V3.  If so then following the TRG_init
//    it will automaticly do a TRG_connect.  There is no explicit 
//    TRG_disconnect call.  If TRG_quit is called then OTIS will do an
//    internal disconnect.
//
#define SDTI_CFG_VERSION        1
#define SDTI_CFG_REVISION       2
#define CCS_V3                  // Must be defined to enable CCS V3

#define SDTI_REG_VERSION        1
#define SDTI_REG_REVISION       1

// REVISION 2 - changes
// Added in ARM dbg_com support
#define SDTI_MEM_VERSION        2
#define SDTI_MEM_REVISION       2

// REVISION 2 - changes
// 1) Set unused bits of TREG to 0 on read
#define SDTI_EVT_VERSION        1
#define SDTI_EVT_REVISION       2

// REVISION 2 - changes
// 1) Added in realtime functions EnterRealtimeMode() and ExitRealtimeMode().
//    These functions are supported on C28x, C55xx, and C64xx via TI
//    IceMaker emulation.  These functions are basicly pass-through to lower
//    level of emulation drivers and may require additional setup external
//    to SDTI.
#define SDTI_EXE_VERSION        1
#define SDTI_EXE_REVISION       2

//----------------------------------------------------------------------------
// Interface handle
//
typedef void * SDTI_HNDL;

//----------------------------------------------------------------------------
// Target register types
//
typedef unsigned char  TREG_8;			// 8-bit register
typedef unsigned short TREG_16;			// 16-bit register
typedef unsigned long  TREG_32;			// 32-bit register

typedef struct treg_64					// 33-64 bit register
{
    unsigned long   RegL;
    unsigned long   RegH;
}TREG_64, *PTREG_64;

typedef union treg
{
    TREG_8   Reg8;
    TREG_16  Reg16;
    TREG_32  Reg32;
    TREG_64  Reg64;
}TREG, * PTREG;

// TREG_DESC is used by sdti_regXXX.c to describe each target register
// 
typedef struct treg_desc
{
    char    *pRegName;		// Register name, hopefully match the data book
    int     RegSize;		// Read/Write size of the register
    int     RegId;			// An Id for the register, not really used
} TREG_DESC, * PTREG_DESC;

//----------------------------------------------------------------------------
// Target memory types
//
// For Harvard devices the memory space can be Program or Data.  For 
// compatibility with TI DSP there is also an I/O space.
// If the processor is not Harvard then use the default of M_NATURAL.
//
// MEM_ACCESS_SIZE provides a way to force target processor accesses
// to a certain access boundary.  This is generally required by byte
// addressable processors with I/O device access size restrictions.
// Some common rules to apply:
// 
// 1) If your processor is a 16 bit fixed point DSP that can only
//    perform 16 bit read/writes then use M_SIZE16 or M_SIZE_NATURAL.
//
// 2) If your processor is a 32 bit fixed point DSP that can only
//    perform 32 bit read/writes then use M_SIZE32 or M_SIZE_NATURAL.
//
// 3) If you processor is a byte addressable machine and you are
//    fetching program or data memory then M_SIZE_NATURAL is recommended.
//    Else, use the size that matches your processor bus width.
//
// 4) For other cases use the size that matches the access restrictions
//    of your I/O or memory devices.
//
// The arguments in TMEM_DESC are pretty obvious with exception
// of Asize and Bsize.  Asize is the access size of the processor
// memory read/write operation, see rules above.  Bsize is the
// size of an element in the read/write buffer.  By having the
// Bsize option the user can pass in a pointer to a 32 bit buffer
// that only has 16 bits of valid data in each 32 bit element.
// Example:
//    unsigned long  *pD32;
//    unsigned short *pD16;
// 
//    *pD32++ = (unsigned long)(*pD16++) & 0x0000FFFFL;
//
// Another example is when the buffer size is smaller then the
// target processor access size.  This is generally the case
// on a fixed point DSP where you want "char" data that is
// 8 bit instead of the 16 bit DSP "char".
// Example:
//     unsigned char *pD8;   // Host 8 bit char data
//     unsigned char *pD16;  // DSP 16 bit data
//  
//     *pD8++ = (unsigned char)(*pD16++);
//
// When the Asize and Bsize do not match the unused data bits
// are set to zero.
//
typedef enum mem_space
{
    M_NATURAL = 0,          // Natural space for processor, !Harvard
    M_PROGRAM,              // Program space
    M_DATA,                 // Data space
    M_IO                    // I/O space
}MEM_SPACE, * PMEM_SPACE;

typedef enum mem_access_size
{
    M_SIZE_NATURAL = 0,     // Natural size of processor memory bus
    M_SIZE8,                // 8-Bit
    M_SIZE16,               // 16-Bit
    M_SIZE32,               // 32-Bit
    M_SIZE64,               // 64-Bit
    M_COFF                  // Preserve TI-COFF accesses
}MEM_ACCESS_SIZE, * PMEM_ACCESS_SIZE;

typedef unsigned long   MEM_TADDR;  // 32 Bit memory address

typedef struct tmem
{
    MEM_TADDR           Taddr;      // Target address
    MEM_SPACE           Space;      // Target memory space
    MEM_ACCESS_SIZE     Asize;      // Target memory access size
    MEM_ACCESS_SIZE     Bsize;      // Host memory buffer access size
    unsigned long       Length;     // Number of elements in ACCESS_SIZE
    void            *   pData;      // Src/Dst data
} TMEM_DESC, *PTMEM_DESC;

#define TDBGCOM_FLAG_XMIT_POLL        ((DWORD)0x00000001)
#define TDBGCOM_FLAG_RECV_POLL        ((DWORD)0x00000002)
#define TDBGCOM_FLAG_RECV_BEFORE_XMIT ((DWORD)0x00000004)

typedef struct tdbg_com
{
    int      StructSz;                   // Size of this structure
    DWORD    Flags;                      // Per command flags

    DWORD   WR_IntervalTimeoutMs;        // Interval operation timeout
    DWORD   WR_TotalTimeoutMs;           // TotalTimeout for complete operation
    DWORD   WR_IntervalDelayUs;          // Delay between consectutive accesses
    DWORD   WR_ByteCount;                // Number of 8 bit bytes to send
    DWORD  *pWR_RetByteCount;            // Actual nuber of bytes sent
    UCHAR  *pWR_Buf;                     // pointer to send buffer

    DWORD   RD_IntervalTimeoutMs;        // Interval operation timeout
    DWORD   RD_TotalTimeoutMs;           // TotalTimeout for complete operation
    DWORD   RD_IntervalDelayUs;          // Delay between consectutive accesses
    DWORD   RD_ByteCount;                // Number of 8 bit bytes to recv
    DWORD  *pRD_RetByteCount;            // Actual nuber of bytes recv
    UCHAR  *pRD_Buf;                     // pointer to recv buffer
}TDBG_COM, *PTDBG_COM;

//----------------------------------------------------------------------------
// Target event types
//
typedef enum evt_type
{
    EVT_NONE     = 0,               // No event
    EVT_HALT,                       // Target halted, by user or non-brkpoint
    EVT_SWBP,                       // Software
    EVT_HWIAQ,                      // Hardware break, Instruction
    EVT_HWDATA                      // Hardware break, Data access
}EVT_TYPE, * PEVT_TYPE;

typedef enum evt_system
{
    EVT_SYS_NONE     = 0,           // No event
	EVT_SYS_WARN,                   // Generic warning, not an error
    EVT_SYS_ERROR,                  // Generic non-target error
    EVT_SYS_TARGET,                 // Generic target error
    EVT_SYS_TARGET_DISCONNECT,      // Target is disconnected
    EVT_SYS_TARGET_LOSSPOWER,       // Target lost power
    EVT_SYS_TARGET_TIMED_OUT,       // Target operation timed out
    EVT_SYS_TARGET_IN_RESET,        // Target is being held in reset
    EVT_SYS_TARGET_NOT_READY,       // Target is being held not ready
    EVT_SYS_TARGET_BUS_FAULT,       // Target performed a bus fault     
}EVT_SYSTEM, * PEVT_SYSTEM;

typedef struct tevt
{
    unsigned            EvtId;      // The event Id
    MEM_TADDR           Taddr;      // Target address
    MEM_SPACE           Space;      // Target memory space
    EVT_TYPE            Type;       // Type of breakpoint
} TEVT_DESC, *PTEVT_DESC;

typedef struct tevt_stat
{
    // Event information that pertains to breakpoint type events
    unsigned            EvtId;      // The event Id
    MEM_TADDR           Taddr;      // Target address
    MEM_SPACE           Space;      // Target memory space
    EVT_TYPE            Type;       // Type of breakpoint
    
    // Event information that pertains to error type events
    EVT_SYSTEM          System;     // System events 
    int                 Error;
}TEVT_STAT_DESC, *PTEVT__STAT_DESC;

/*A***************************************************************************
* NAME:  Spectrum Digital Target Interface
*
* USAGE: Interface that can sit on top of GTI, OTI or others.  The 
*        interface is processor independent and you can specify your
*        "cpu" family during initialization.  Further, argument options that
*        do not cleanly fit into generic data types are passed in as 
*        strings.  This allows any number of options to be supported without
*        continually changing the interface.
*
* CONNECTION:
*        The interface has only 1 external function "SDTI_GetInterface. The
*        user calls this functions to get a pointer to the "Interface" which
*        contains configuration information plus all the functions (methods)
*        for the interface. You then access functions as follows:
*
*        pIntf->pCfg->Init(...);
*        pIntf->pCfg->Open(...);
*
*        The function SDTI_GetInterface includes a parameter pTargetFamily.
*        This parameter specifies which target processor you are targeting.
*        If the requested target family is not supported then NULL is 
*        returned for the interface.
*
*        This style of interface is most significant when  built as
*        a DLL and explicitly loaded by the caller.  In this case you only
*        have to get a reference to one function "SDTI_GetInterface" then
*        call it to get everything you need to know about the interface.
*
* VERSION/REVISION:
*         The interface provides a version/revision.  The caller should 
*         always check for interface version/revision compatibility.  
*         "Version" changes when a significant change to the interface 
*         occurs that would effect backward compatibility.  "Revision"
*         changes when a minor change occurs that would not affect backward
*         compatibility.  You can also use sizeof( SD_TARGET_INTERFACE )
*         and compare to "StructSz" for another level of checking.
* 
* RETURN : 
*         Return types follow the Microsoft convention 
*         1 - True/Success.  The function completed without error.
*         0 - False/Failure. The function did not complete without error.
*         The error will be queued into the event queue.
*
* POINTERS : 
*         Again following the Microsoft convention all pointer arguments
*         are checked for NULL.  If a pointer is NULL then input arguments
*         are not used and return arguments are not returned.  Example,
*         if you call GetLastError and set pErrString to NULL then no
*         error string is returned.  
*A***************************************************************************/

//----------------------------------------------------------------------------
// Interface config functions
//
// CreateHndl : Create a handle for this debug instance.  If pLibPath and 
//              pLibName are not NULL then use the specified debug library.
//              Else, pDevName must hold the name of the processor family
//              to connect to.  If all three parameters are provided then
//              pFamily will be used to validate the loaded lib..
//              A valid handle is returned except in the rare case of
//              insufficent host memory.  Thus you can call GetLastError
//              if there is an error during CreateHndl.
//
// FreeHndl :   Free the handle from CreateHndl.  Closes the open 
//              debug session if required.  You MUST always call
//              this to release resources if CreateHndl returns
//              a valid handle. FreeHndl will automaticly "Disconnect"
//              if the debug session is still "Connected".
//
// SetOptions : Set the options for this debug session. Options are
//              generally setup prior to connecting to a target. 
//              Options are in the form of "EmulatorId=378,...",
//              using a comma seperator and null terminator.  Once 
//              connected some options cannot be changed until you
//              disconnect, for example your EmulatorId.
//
// GetOptions : Return the current options.  MaxString is the maximum
//              size of the return string.             
//
// FreeOptions : Free the current options and return to the default
//               state. FreeOptions can only be called when in the
//               disconnected state.  You can change current options
//               by calling SetOptions with the restriction that not
//               all options can be changed while in the connected 
//               state.
//
// Connect :     Make a debug connection to the target.  Once connected the
//               target is ready for a debug session.
//
// Disconnect : Disconnect from the debug session. Once disconnected no
//              more target accesses are allowed.
//
// GetErrorString : Get an error string based on the error number
// 
//
//----------------------------------------------------------------------------
// Valid device families for the function CreatHndl 
#define FAMILY_TMS320C5X               "TMS320C5X"
#define FAMILY_TMS320C3X               "TMS320C3X"
#define FAMILY_TMS320VC3X              "TMS320VC3X"
#define FAMILY_TMS320C4X               "TMS320C4X"
#define FAMILY_TMS320C2XX              "TMS320C2XX"
#define FAMILY_TMS320C54X              "TMS320C54X"   
#define FAMILY_TMS320C6XX              "TMS320C6XX"
#define FAMILY_TMS320C55XX             "TMS320C55XX"
#define FAMILY_TMSR470                 "TMSR470"
#define FAMILY_TMS320C27XX             "TMS320C27XX"
#define FAMILY_INTEL_XSCALE            "INTEL_XSCALE"
#define FAMILY_ARM925                  "ARM925"
#define FAMILY_TMS320C64XX             "TMS320C64XX"

typedef struct sdf_cfg
{
    int      StructSz;           // Size of this structure
    int      Version;            // Interface major version                    
    int      Revision;           // Interface minor revision        

    // Create/Free handle for debug instance
    BOOL     (*CreateHndl)  ( SDTI_HNDL *pHndl, char *pLibPath, char *pLibName,
                                                char *pFamily );
    BOOL     (*FreeHndl)    ( SDTI_HNDL Hndl );

    // Option setup prior to connecting to the target
	BOOL     (*SetOptions)   ( SDTI_HNDL Hndl, char *pOptsString );
    BOOL     (*GetOptions)   ( SDTI_HNDL Hndl, int  MaxString, 
                               char *pOptsString );
    BOOL     (*FreeOptions)  ( SDTI_HNDL Hndl );


    // Connect/Disconnect from the target
    BOOL     (*Connect)      ( SDTI_HNDL Hndl                     );   
    BOOL     (*Disconnect)   ( SDTI_HNDL Hndl                     );

    // Get an error string based on the error code
    BOOL     (*GetErrorString) ( SDTI_HNDL Hndl, int Error, int MaxString, 
                                                 char *pErrString );
} SDF_CFG, *PSDF_CFG;

//----------------------------------------------------------------------------
// Register functions
//
// ReadByName  : Read a target register using the "common" register name as
//               the identifier.
// WriteByName : Write a target register using the "common" register name as
//               the identifier.
//
// Each processor has a register mapping file named "sdti_regCPU.c" where
// CPU is a processor identifier.  Each register is defined as:
//     { "Name", Size, Id }
//     C54x Example:
//        {"IMR",      sizeof(TREG_16),         0 },
//        {"IFR",      sizeof(TREG_16),         1 },
//
typedef struct sdf_reg
{
    int      StructSz;           // Size of this structure
    int      Version;            // Interface major version                    
    int      Revision;           // Interface minor revision        

    BOOL     (*ReadByName) ( SDTI_HNDL Hndl, char *pRegName, TREG *pReg );
    BOOL     (*WriteByName)( SDTI_HNDL Hndl, char *pRegName, TREG *pReg );
}SDF_REG, *PSDF_REG;

//----------------------------------------------------------------------------
// Memory functions
// 
// Read  : Read a block of memory.
// Write : Write a block of memory.
// Fill  : Fill a block of memory.
// isBigEndian  : Returns TRUE if processor is big endian or FALSE if little.
// 
// The user can specify a memory type, i.e. program, data, i/o for Harvard(TI),
// or natural for others.
// The user then specifies if the access size is to be 8,16,32,64 bit.
// The length of the block is in "access size" elements.
//
// Data in the memory buffer is passed in host endianess format for the
// specified access size.
//
typedef struct sdf_mem
{
    int      StructSz;           // Size of this structure
    int      Version;            // Interface major version                    
    int      Revision;           // Interface minor revision        
    
    BOOL     (*Read)       ( SDTI_HNDL Hndl, TMEM_DESC *pMem );
    BOOL     (*Write)      ( SDTI_HNDL Hndl, TMEM_DESC *pMem );
    BOOL     (*Fill)       ( SDTI_HNDL Hndl, TMEM_DESC *pMem );
	BOOL     (*isBigEndian)( SDTI_HNDL Hndl                  );
    // REVISION 2 change
    BOOL     (*DbgComReadWrite) (SDTI_HNDL Hndl, TDBG_COM *pDbgCom );
}SDF_MEM, *PSDF_MEM;

//----------------------------------------------------------------------------
// Event functions
//
// Add    : Add an event.  An event Id is returned.
// Delete : Delete an event based on EvtId.
// 
typedef struct sdf_evt
{
    int             StructSz;           // Size of this structure
    int             Version;            // Interface major version                    
    int             Revision;           // Interface minor revision            
    
    BOOL     (*Add)       ( SDTI_HNDL Hndl, TEVT_DESC *pEvt );
    BOOL     (*Delete)    ( SDTI_HNDL Hndl, unsigned EvtId );
}SDF_EVT, *PSDF_EVT;  

//----------------------------------------------------------------------------
// Execution functions 
//
// Reset : Do a hardware or software reset on the connected target.
// Continue : Continue target execution from the current program address.
// Suspend  : Suspend target execution.
// Step  : Step "Count" assembly instructions with interrupts off.
// UserMode : Continue target execution in user mode, i.e. connected but
//            debug disabled.
// IsRunning : Is the target processor running or suspended.  The 
//             target is considered "running" until it is SUCCESSFULLY
//             suspended.  
// IsEvent : Is an event pending. If pEvtStat is not NULL then return the
//             pending event.
//            
// IsEvent returns all events, i.e. breakpoints, errors, status, etc..
// As long as events are in the queue IsEvent will return "TRUE".
//
typedef struct sdf_exe
{
    int             StructSz;           // Size of this structure
    int             Version;            // Interface major version                    
    int             Revision;           // Interface minor revision            
    
    BOOL     (*Reset)      ( SDTI_HNDL Hndl );
    BOOL     (*Continue)   ( SDTI_HNDL Hndl );
    BOOL     (*Suspend)    ( SDTI_HNDL Hndl );
    BOOL     (*Step)       ( SDTI_HNDL Hndl, unsigned long Count );
    BOOL     (*UserMode)   ( SDTI_HNDL Hndl );
    BOOL     (*IsRunning)  ( SDTI_HNDL Hndl );
    BOOL     (*IsEvent)    ( SDTI_HNDL Hndl, TEVT_STAT_DESC *pEvtStat );

// REVISION 2 - changes
// 1) Added in realtime functions EnterRealtimeMode() and ExitRealtimeMode().
//    These functions are supported on C28x, C55xx, and C64xx via TI
//    IceMaker emulation.  These functions are basicly pass-through to lower
//    level of emulation drivers and may require additional setup external
//    to SDTI.
    BOOL     (*EnterRealtimeMode) (SDTI_HNDL Hndl, unsigned long Option );
    BOOL     (*ExitRealtimeMode)  (SDTI_HNDL Hndl );

}SDF_EXE, *PSDF_EXE;


typedef struct sd_target_interface
{
    int             StructSz;           // Size of this structure
    int             Version;            // Interface major version                    
    int             Revision;           // Interface minor revision                  
    int             Type;               // Interface type         
    int             isInitalized;       // True if intf. autoinit 
    char    *       Name;               // Interface name, will contain the
                                        // target family name
    unsigned long   Flags;              // Operation flags           

    SDF_CFG       * pCfg;               // Interface config functions
    SDF_REG       * pReg;               // Register functions
    SDF_MEM       * pMem;               // Memory functions
    SDF_EVT       * pEvt;               // Event functions
    SDF_EXE       * pExe;               // Execution functions

}SD_TARGET_INTERFACE, *PSD_TARGET_INTERFACE ;

typedef enum sdti_errors
{
    ERR_NONE            = 0,

    // Config errors
    CFG_ERR_GENERIC     = 4000,
    GFG_ERR_HOST_MALLOC,                // Fail host memory malloc
    CFG_ERR_LIB_HANDLE,                 // Could not get targ lib handle
    CFG_ERR_LIB_INTERFACE,              // Invalid lib interface
    CFG_ERR_LIB_VERSION,                // Invalid lib version
    CFG_ERR_FAMILY,                     // Invalid processor family
    CFG_ERR_UNKNOWN_OPTION,             // Unknown/unsupported option
    CFG_ERR_HANDLE,                     // Passed handle is invalid
    CFG_ERR_DISCONNECTED,               // Invalid action when targ disconnected
    
    // Register errors
    REG_ERR_GENERIC = 5000,
    REG_ERR_NAME,                       // Invalid register name

    // Memory errors
    MEM_ERR_GENERIC = 6000,
    MEM_ERR_SPACE,                      // Invalid memory space
    MEM_ERR_ACCESS_SIZE,                // Access size not supported
    MEM_ERR_ADDRESS,                    // Invalid or out of range address

    // Event errors 
    EVT_ERR_GENERIC = 7000,
    EVT_ERR_ADDRESS,                    // Invalid or out of range address
    EVT_ERR_SPACE,                      // Invalid memory space
    EVT_ERR_TYPE,                       // Unsupported event type

    // Execution errors
    EXE_ERR_GENERIC = 8000,
    EXE_ERR_TARGET_RUNNING              // Invalid action while running
}SDTI_ERRORS, * PSDTI_ERRORS;


/*---- global data declarations --------------------------------------------*/

/*---- global function prototypes ------------------------------------------*/
#ifdef GLOBAL
    #undef GLOBAL
#endif
#ifdef sdti_c
   #define GLOBAL 
#else
   #define GLOBAL extern
#endif

GLOBAL int 
SDTI_GetInterface( void ** pInterface, char *pFamily );

#ifdef __cplusplus
}
#endif

#endif /* inf_h ------- END OF FILE ----------------------------------------*/

