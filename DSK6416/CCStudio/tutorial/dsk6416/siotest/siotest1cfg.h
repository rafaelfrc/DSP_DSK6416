/*   Do *not* directly modify this file.  It was    */
/*   generated by the Configuration Tool; any  */
/*   changes risk being overwritten.                */

/* INPUT siotest1.cdb */

#define CHIP_6416 1

/*  Include Header Files  */
#include <std.h>
#include <hst.h>
#include <swi.h>
#include <tsk.h>
#include <log.h>
#include <sio.h>
#include <sts.h>

#ifdef __cplusplus
extern "C" {
#endif

extern far HST_Obj RTA_fromHost;
extern far HST_Obj RTA_toHost;
extern far SWI_Obj KNL_swi;
extern far TSK_Obj TSK_idle;
extern far TSK_Obj streamTask;
extern far LOG_Obj LOG_system;
extern far LOG_Obj trace;
extern far SIO_Obj inputStream;
extern far STS_Obj IDL_busyObj;
extern far void CSL_cfgInit();

#ifdef __cplusplus
}
#endif /* extern "C" */
