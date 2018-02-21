/*   Do *not* directly modify this file.  It was    */
/*   generated by the Configuration Tool; any  */
/*   changes risk being overwritten.                */

/* INPUT hostio.cdb */

#define CHIP_6416 1

/*  Include Header Files  */
#include <std.h>
#include <hst.h>
#include <swi.h>
#include <tsk.h>
#include <log.h>
#include <sts.h>

#ifdef __cplusplus
extern "C" {
#endif

extern far HST_Obj RTA_fromHost;
extern far HST_Obj RTA_toHost;
extern far HST_Obj input_HST;
extern far HST_Obj output_HST;
extern far SWI_Obj KNL_swi;
extern far SWI_Obj A2DscaleD2A_SWI;
extern far TSK_Obj TSK_idle;
extern far LOG_Obj LOG_system;
extern far LOG_Obj trace;
extern far STS_Obj IDL_busyObj;
extern far void CSL_cfgInit();

#ifdef __cplusplus
}
#endif /* extern "C" */
