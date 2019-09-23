#include "legato.h"
#include "interfaces.h"

// make this a setting later on
#define WAN_DATA_CHECK_RATE		(10) // seconds

// radio related event op
static void radio_cbh
(
    le_mrc_NetRegState_t state,
    void* contextPtr
)
{
	switch (state)
	{
		case LE_MRC_REG_NONE:
			LE_INFO("Radio Not registered and not currently searching for new operator (LE_MRC_REG_NONE)");
			break;
		case LE_MRC_REG_HOME:
			LE_INFO("Radio Registered, home network (LE_MRC_REG_HOME)");
			break;
		case LE_MRC_REG_SEARCHING:
			LE_INFO("Radio Not registered but currently searching for a new operator (LE_MRC_REG_SEARCHING)");
			break;
		case LE_MRC_REG_DENIED:
			LE_INFO("Radio Registration was denied, usually because of invalid access credentials (LE_MRC_REG_DENIED)");
			break;
		case LE_MRC_REG_ROAMING:
			LE_INFO("Radio Registered to a roaming network (LE_MRC_REG_ROAMING)");
			break;
		default:
			LE_INFO("Radio Unknown state (LE_MRC_REG_UNKNOWN)");
			break;
	}
}



// sim related event op
static void sim_cbh
(
    le_sim_Id_t simId,
	le_sim_States_t simState,
    void* contextPtr
)
{
	switch (simState)
	{
		case LE_SIM_INSERTED:
			LE_INFO("SIM card is inserted and locked (LE_SIM_INSERTED).\n");
			break;
		case LE_SIM_ABSENT:
			LE_INFO("SIM card is absent (LE_SIM_ABSENT).\n");
			break;
		case LE_SIM_READY:
			LE_INFO("SIM card is inserted and unlocked (LE_SIM_READY).\n");
			break;
		case LE_SIM_BLOCKED:
			LE_INFO("SIM card is blocked (LE_SIM_BLOCKED).\n");
			break;
		case LE_SIM_BUSY:
			LE_INFO("SIM card is busy (LE_SIM_BUSY).\n");
			break;
		default:
			LE_INFO("Unknown SIM state.\n");
			break;
	}
}

void wanDataState_cbh
(
    const char* intfName,
    bool isConnected,
    void* contextPtr
)
{
	LE_INFO("wan state change %s = %d", intfName, isConnected );
}



//-------------------------------------------------------------------------------------------------
/*
 * WAN data link test
 *
 *
 */





static le_timer_Ref_t clockTimerRef;
// timer callback handler
 void clock_cbh(le_timer_Ref_t clockTimerRef)
 {
//	 le_result_t res;

	 le_mdc_ProfileRef_t profileRef = le_mdc_GetProfile( LE_MDC_DEFAULT_PROFILE ); // could be we select the wrong profile we need to improve this
//	 le_mrc_NetRegState_t mrcState;
	 le_mdc_ConState_t mdcState;
	 char apnName[100];
	 char ipV4[100];
	/*

	 res = le_mrc_GetNetRegState(&mrcState);

	 if ((res == LE_OK) && (state==LE_MRC_REG_HOME) && (state==LE_MRC_REG_ROAMING))
	 {

	 }
*/
	 le_mdc_GetSessionState(profileRef, &mdcState);

	 le_mdc_GetAPN(profileRef, apnName, sizeof(apnName));
	 le_mdc_GetIPv4Address(profileRef, ipV4, sizeof(ipV4));

	 LE_INFO("WAN state %d APN %s IPv4 %s", mdcState, apnName, ipV4 );
	 if(mdcState == LE_MDC_DISCONNECTED)
	 {
		 LE_INFO("WAN requesting connect" );
		 le_data_Request();
	 }
 }


void startClock(void)
{
    le_clk_Time_t repeatInterval;
	repeatInterval.sec = WAN_DATA_CHECK_RATE;
	repeatInterval.usec = 0;

	clockTimerRef = le_timer_Create ("clock");
	le_timer_SetHandler ( clockTimerRef, clock_cbh);
	le_timer_SetInterval( clockTimerRef, repeatInterval);
	le_timer_SetRepeat( clockTimerRef, 0 )	;	// 0 is forever
	le_timer_Start( clockTimerRef);
}

//-------------------------------------------------------------------------------------------------


COMPONENT_INIT
{
    LE_INFO("Hello, wan.");

    le_sim_AddNewStateHandler(sim_cbh,NULL);
    le_mrc_AddNetRegStateEventHandler(radio_cbh, NULL);
    le_data_AddConnectionStateHandler (wanDataState_cbh, NULL );

    startClock();
}
