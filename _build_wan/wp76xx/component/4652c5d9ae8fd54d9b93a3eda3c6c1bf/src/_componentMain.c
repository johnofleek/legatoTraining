/*
 * AUTO-GENERATED _componentMain.c for the wanComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _wanComponent_le_data_ServiceInstanceName;
const char** le_data_ServiceInstanceNamePtr = &_wanComponent_le_data_ServiceInstanceName;
void le_data_ConnectService(void);
extern const char* _wanComponent_le_cfg_ServiceInstanceName;
const char** le_cfg_ServiceInstanceNamePtr = &_wanComponent_le_cfg_ServiceInstanceName;
void le_cfg_ConnectService(void);
extern const char* _wanComponent_le_mdc_ServiceInstanceName;
const char** le_mdc_ServiceInstanceNamePtr = &_wanComponent_le_mdc_ServiceInstanceName;
void le_mdc_ConnectService(void);
extern const char* _wanComponent_le_mrc_ServiceInstanceName;
const char** le_mrc_ServiceInstanceNamePtr = &_wanComponent_le_mrc_ServiceInstanceName;
void le_mrc_ConnectService(void);
extern const char* _wanComponent_le_sim_ServiceInstanceName;
const char** le_sim_ServiceInstanceNamePtr = &_wanComponent_le_sim_ServiceInstanceName;
void le_sim_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t wanComponent_LogSession;
le_log_Level_t* wanComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _wanComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _wanComponent_Init(void)
{
    LE_DEBUG("Initializing wanComponent component library.");

    // Connect client-side IPC interfaces.
    le_data_ConnectService();
    le_cfg_ConnectService();
    le_mdc_ConnectService();
    le_mrc_ConnectService();
    le_sim_ConnectService();

    // Register the component with the Log Daemon.
    wanComponent_LogSession = log_RegComponent("wanComponent", &wanComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_wanComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
