/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef LE_DATA_MESSAGES_H_INCLUDE_GUARD
#define LE_DATA_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "cd1229366cba2e53f6f8d43e15e6f840"

#ifdef MK_TOOLS_BUILD
    extern const char** le_data_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*le_data_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "le_data"
#endif


#define _MAX_MSG_SIZE 113

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_le_data_AddConnectionStateHandler 0
#define _MSGID_le_data_RemoveConnectionStateHandler 1
#define _MSGID_le_data_Request 2
#define _MSGID_le_data_Release 3
#define _MSGID_le_data_SetTechnologyRank 4
#define _MSGID_le_data_GetFirstUsedTechnology 5
#define _MSGID_le_data_GetNextUsedTechnology 6
#define _MSGID_le_data_GetTechnology 7
#define _MSGID_le_data_GetDefaultRouteStatus 8
#define _MSGID_le_data_AddRoute 9
#define _MSGID_le_data_DelRoute 10
#define _MSGID_le_data_GetCellularProfileIndex 11
#define _MSGID_le_data_SetCellularProfileIndex 12
#define _MSGID_le_data_GetDate 13
#define _MSGID_le_data_GetTime 14


// Define type-safe pack/unpack functions for all enums, including included types

static inline bool le_data_PackTechnology
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_data_Technology_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_data_UnpackTechnology
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_data_Technology_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_data_PackTimeProtocol
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_data_TimeProtocol_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_data_UnpackTimeProtocol
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_data_TimeProtocol_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_mdc_PackDataBearerTechnology
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_DataBearerTechnology_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_mdc_UnpackDataBearerTechnology
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_DataBearerTechnology_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_mdc_PackPdp
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_Pdp_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_mdc_UnpackPdp
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_Pdp_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_mdc_PackAuth
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_Auth_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_mdc_UnpackAuth
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_Auth_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_mdc_PackConState
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_ConState_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_mdc_UnpackConState
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_ConState_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_mdc_PackDisconnectionReason
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_DisconnectionReason_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_mdc_UnpackDisconnectionReason
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_DisconnectionReason_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_dcs_PackTechnology
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_dcs_Technology_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_dcs_UnpackTechnology
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_dcs_Technology_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_dcs_PackState
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_dcs_State_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_dcs_UnpackState
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_dcs_State_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool le_dcs_PackEvent
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_dcs_Event_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool le_dcs_UnpackEvent
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_dcs_Event_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

// Define pack/unpack functions for all structures, including included types


static inline bool le_mdc_PackProfileInfo
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    const le_mdc_ProfileInfo_t *valuePtr
)
{
    __attribute__((unused))
    bool subResult, result = true;

    LE_ASSERT(valuePtr);
    subResult = le_pack_PackString( bufferPtr, sizePtr,
                                    valuePtr->name, 50);
    result = result && subResult;
    subResult = le_pack_PackUint8( bufferPtr, sizePtr,
                                                 valuePtr->index );
    result = result && subResult;
    subResult = le_pack_PackUint8( bufferPtr, sizePtr,
                                                 valuePtr->type );
    result = result && subResult;

    return result;
}

static inline bool le_mdc_UnpackProfileInfo
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_mdc_ProfileInfo_t *valuePtr
)
{
    bool result = true;
    if (result)
    {
        result = le_pack_UnpackString(bufferPtr, sizePtr,
                                      valuePtr->name,
                                      sizeof(valuePtr->name),
                                      50);
    }
    if (result)
    {
        result = le_pack_UnpackUint8(bufferPtr, sizePtr,
                                                   &valuePtr->index );
    }
    if (result)
    {
        result = le_pack_UnpackUint8(bufferPtr, sizePtr,
                                                   &valuePtr->type );
    }
    return result;
}

static inline bool le_dcs_PackChannelInfo
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    const le_dcs_ChannelInfo_t *valuePtr
)
{
    __attribute__((unused))
    bool subResult, result = true;

    LE_ASSERT(valuePtr);
    subResult = le_pack_PackReference( bufferPtr, sizePtr,
                                                 valuePtr->ref );
    result = result && subResult;
    subResult = le_pack_PackString( bufferPtr, sizePtr,
                                    valuePtr->name, 32);
    result = result && subResult;
    subResult = le_dcs_PackTechnology( bufferPtr, sizePtr,
                                                 valuePtr->technology );
    result = result && subResult;
    subResult = le_dcs_PackState( bufferPtr, sizePtr,
                                                 valuePtr->state );
    result = result && subResult;

    return result;
}

static inline bool le_dcs_UnpackChannelInfo
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    le_dcs_ChannelInfo_t *valuePtr
)
{
    bool result = true;
    if (result)
    {
        result = le_pack_UnpackReference(bufferPtr, sizePtr,
                                                   &valuePtr->ref );
    }
    if (result)
    {
        result = le_pack_UnpackString(bufferPtr, sizePtr,
                                      valuePtr->name,
                                      sizeof(valuePtr->name),
                                      32);
    }
    if (result)
    {
        result = le_dcs_UnpackTechnology(bufferPtr, sizePtr,
                                                   &valuePtr->technology );
    }
    if (result)
    {
        result = le_dcs_UnpackState(bufferPtr, sizePtr,
                                                   &valuePtr->state );
    }
    return result;
}

#endif // LE_DATA_MESSAGES_H_INCLUDE_GUARD