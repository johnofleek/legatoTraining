

/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */

/**
 * @page c_le_dcs Data Channel Service le_dcs APIs
 *
 * @ref le_dcs_interface.h "API Reference" <br>
 * @ref le_dcs_sample <br>
 *
 * A data channel can be established over a mobile network, WiFi or a fixed link (e.g.,
 * ethernet). The le_dcs APIs provide applications the ability to establish a selected packet
 * switched data channel to communicate with other devices.
 * <HR>
 *
 * Copyright (C) Sierra Wireless Inc.
 */
/**
 * @file le_dcs_interface.h
 *
 * Legato @ref c_le_dcs include file.
 *
 * Copyright (C) Sierra Wireless Inc.
 */

#ifndef LE_DCS_INTERFACE_H_INCLUDE_GUARD
#define LE_DCS_INTERFACE_H_INCLUDE_GUARD


#include "legato.h"


//--------------------------------------------------------------------------------------------------
/**
 * Type for handler called when a server disconnects.
 */
//--------------------------------------------------------------------------------------------------
typedef void (*le_dcs_DisconnectHandler_t)(void *);

//--------------------------------------------------------------------------------------------------
/**
 *
 * Connect the current client thread to the service providing this API. Block until the service is
 * available.
 *
 * For each thread that wants to use this API, either ConnectService or TryConnectService must be
 * called before any other functions in this API.  Normally, ConnectService is automatically called
 * for the main thread, but not for any other thread. For details, see @ref apiFilesC_client.
 *
 * This function is created automatically.
 */
//--------------------------------------------------------------------------------------------------
void le_dcs_ConnectService
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 *
 * Try to connect the current client thread to the service providing this API. Return with an error
 * if the service is not available.
 *
 * For each thread that wants to use this API, either ConnectService or TryConnectService must be
 * called before any other functions in this API.  Normally, ConnectService is automatically called
 * for the main thread, but not for any other thread. For details, see @ref apiFilesC_client.
 *
 * This function is created automatically.
 *
 * @return
 *  - LE_OK if the client connected successfully to the service.
 *  - LE_UNAVAILABLE if the server is not currently offering the service to which the client is
 *    bound.
 *  - LE_NOT_PERMITTED if the client interface is not bound to any service (doesn't have a binding).
 *  - LE_COMM_ERROR if the Service Directory cannot be reached.
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_dcs_TryConnectService
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Set handler called when server disconnection is detected.
 *
 * When a server connection is lost, call this handler then exit with LE_FATAL.  If a program wants
 * to continue without exiting, it should call longjmp() from inside the handler.
 */
//--------------------------------------------------------------------------------------------------
void le_dcs_SetServerDisconnectHandler
(
    le_dcs_DisconnectHandler_t disconnectHandler,
    void *contextPtr
);

//--------------------------------------------------------------------------------------------------
/**
 *
 * Disconnect the current client thread from the service providing this API.
 *
 * Normally, this function doesn't need to be called. After this function is called, there's no
 * longer a connection to the service, and the functions in this API can't be used. For details, see
 * @ref apiFilesC_client.
 *
 * This function is created automatically.
 */
//--------------------------------------------------------------------------------------------------
void le_dcs_DisconnectService
(
    void
);


//--------------------------------------------------------------------------------------------------
/**
 * Interface name string length.
 */
//--------------------------------------------------------------------------------------------------
#define LE_DCS_INTERFACE_NAME_MAX_LEN 100

//--------------------------------------------------------------------------------------------------
/**
 * Channel name string length.
 */
//--------------------------------------------------------------------------------------------------
#define LE_DCS_CHANNEL_NAME_MAX_LEN 32

//--------------------------------------------------------------------------------------------------
/**
 * IP addr string's max length
 */
//--------------------------------------------------------------------------------------------------
#define LE_DCS_IPADDR_MAX_LEN 46

//--------------------------------------------------------------------------------------------------
/**
 * Max # of entries on a data channel list
 * The current define value is one > the # of cellular profiles supported. When more technologies
 * are supported by DCS, e.g. Wifi, this value will be increased accordingly
 */
//--------------------------------------------------------------------------------------------------
#define LE_DCS_CHANNEL_LIST_QUERY_MAX 32

//--------------------------------------------------------------------------------------------------
/**
 */
//--------------------------------------------------------------------------------------------------
#define LE_DCS_CHANNEL_LIST_ENTRY_MAX 64

//--------------------------------------------------------------------------------------------------
/**
 * Reference returned by Request function and used by Release function
 */
//--------------------------------------------------------------------------------------------------
typedef struct le_dcs_ReqObj* le_dcs_ReqObjRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * Reference to a data channel
 */
//--------------------------------------------------------------------------------------------------
typedef struct le_dcs_Channel* le_dcs_ChannelRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * Technologies.
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_DCS_TECH_UNKNOWN = 0,
        ///<
    LE_DCS_TECH_WIFI = 1,
        ///< Wi-Fi
    LE_DCS_TECH_CELLULAR = 2,
        ///< Cellular
    LE_DCS_TECH_MAX = 3
        ///< Unknown state.
}
le_dcs_Technology_t;


//--------------------------------------------------------------------------------------------------
/**
 * Channel states.
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_DCS_STATE_DOWN = 0,
        ///<
    LE_DCS_STATE_UP = 1
        ///<
}
le_dcs_State_t;


//--------------------------------------------------------------------------------------------------
/**
 * Channel events.
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_DCS_EVENT_DOWN = 0,
        ///<
    LE_DCS_EVENT_UP = 1
        ///<
}
le_dcs_Event_t;


//--------------------------------------------------------------------------------------------------
/**
 * Reference type used by Add/Remove functions for EVENT 'le_dcs_Event'
 */
//--------------------------------------------------------------------------------------------------
typedef struct le_dcs_EventHandler* le_dcs_EventHandlerRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * This is the structure with info about each available channel
 */
//--------------------------------------------------------------------------------------------------
typedef struct
{
    le_dcs_ChannelRef_t ref;
    char name[32];
    le_dcs_Technology_t technology;
    le_dcs_State_t state;
}
le_dcs_ChannelInfo_t;


//--------------------------------------------------------------------------------------------------
/**
 * Handler for channel state changes
 */
//--------------------------------------------------------------------------------------------------
typedef void (*le_dcs_EventHandlerFunc_t)
(
    le_dcs_ChannelRef_t channelRef,
        ///< The channel for which the event is
    le_dcs_Event_t event,
        ///< Event up or down
    int32_t code,
        ///< Additional event code, like error code
    void* contextPtr
        ///<
);

//--------------------------------------------------------------------------------------------------
/**
 * Handler for the receiving the results of a channel list query
 */
//--------------------------------------------------------------------------------------------------
typedef void (*le_dcs_GetChannelsHandlerFunc_t)
(
    le_result_t result,
        ///< Result of the channel list query
    const le_dcs_ChannelInfo_t* channelListPtr,
        ///< List of channels returned
    size_t channelListSize,
        ///<
    void* contextPtr
        ///<
);

//--------------------------------------------------------------------------------------------------
/**
 * Add handler function for EVENT 'le_dcs_Event'
 *
 * This event provides information on channel events
 */
//--------------------------------------------------------------------------------------------------
le_dcs_EventHandlerRef_t le_dcs_AddEventHandler
(
    le_dcs_ChannelRef_t channelRef,
        ///< [IN] The channel for which the event is
    le_dcs_EventHandlerFunc_t handlerPtr,
        ///< [IN]
    void* contextPtr
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Remove handler function for EVENT 'le_dcs_Event'
 */
//--------------------------------------------------------------------------------------------------
void le_dcs_RemoveEventHandler
(
    le_dcs_EventHandlerRef_t handlerRef
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Query for a channel's technology type
 *
 * @return
 *      - The given channel's technology type as an enumberator from @ref le_dcs_Technology_t
 */
//--------------------------------------------------------------------------------------------------
le_dcs_Technology_t le_dcs_GetTechnology
(
    le_dcs_ChannelRef_t channelRef
        ///< [IN] channel which technology type is to be queried
);

//--------------------------------------------------------------------------------------------------
/**
 * Query for a channel's state
 *
 * @return
 *      - The given channel's state in the 2nd argument and associated network interface
 *        in 'name'
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_dcs_GetState
(
    le_dcs_ChannelRef_t channelRef,
        ///< [IN] channel which status is to be queried
    le_dcs_State_t* statePtr,
        ///< [OUT] channel state returned as output
    char* interfaceName,
        ///< [OUT] channel's network interface name
    size_t interfaceNameSize
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Request by an app to start a data channel
 *
 * @return
 *      - Object reference to the request (to be used later for releasing the channel)
 *      - NULL if it has failed to process the request
 */
//--------------------------------------------------------------------------------------------------
le_dcs_ReqObjRef_t le_dcs_Start
(
    le_dcs_ChannelRef_t channelRef
        ///< [IN] channel requested to be started
);

//--------------------------------------------------------------------------------------------------
/**
 * Stop for an app its previously started data channel
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_dcs_Stop
(
    le_dcs_ReqObjRef_t reqRef
        ///< [IN] the start request's reference earlier returned
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the object reference of the channel given by the name and its technology type in the first
 * and second arguments as input
 *
 * @return
 *     - The retrieved channel reference is returned in the function's return value upon success.
 *     - Upon failure, 0 is returned back
 */
//--------------------------------------------------------------------------------------------------
le_dcs_ChannelRef_t le_dcs_GetReference
(
    const char* LE_NONNULL name,
        ///< [IN] name of channel which reference is to be retrieved
    le_dcs_Technology_t technology
        ///< [IN] technology of the channel given by its name above
);

//--------------------------------------------------------------------------------------------------
/**
 * Trigger a query for the list of all available data channels that will be returned asynchronously
 * via the ChannelQueryHandler callback notification
 */
//--------------------------------------------------------------------------------------------------
void le_dcs_GetChannels
(
    le_dcs_GetChannelsHandlerFunc_t handlerPtr,
        ///< [IN] requester's handler for receiving results
    void* contextPtr
        ///< [IN]
);

#endif // LE_DCS_INTERFACE_H_INCLUDE_GUARD