#include "legato.h"
#include "interfaces.h"


static le_timer_Ref_t timerRef;

// This callback event handler called once a second
 void timerPeriodicEvent_cbh(le_timer_Ref_t timerRef)
 {
	LE_INFO("Hello World : timer cbh : count %d", le_timer_GetExpiryCount(timerRef) );
 }


// This sets up the timerPeriodicEvent_cbh
void timerPeriodicEvent_init(int period)
{
	le_clk_Time_t repeatInterval;
	repeatInterval.sec = period;
	repeatInterval.usec = 0;

    timerRef = le_timer_Create ("mainLoopTimer");
    // bind the cbh above to the mainLoopTimer timer event
    le_timer_SetHandler ( timerRef, timerPeriodicEvent_cbh);    
    le_timer_SetInterval( timerRef, repeatInterval);
    le_timer_SetRepeat( timerRef, 0 )	;	// 0 is forever
    le_timer_Start( timerRef);
}


COMPONENT_INIT
{
	char string[1024];

    LE_INFO("Hello, World - timer start");

    timerPeriodicEvent_init(5);

    // demo the le_info interface - LE_INFO and le_info are completely different things!
    // note the binding in .adef file to enable this app to use the le_info service
    LE_INFO("some info about the WP");

    le_info_GetDeviceModel (string, sizeof(string));
    LE_INFO("Device model: %s", string);
    le_info_GetImei(string, sizeof(string));
    LE_INFO("IMEI: %s", string);
    le_info_GetPlatformSerialNumber(string, sizeof(string));
    LE_INFO("Platform serial number: %s", string);

}
