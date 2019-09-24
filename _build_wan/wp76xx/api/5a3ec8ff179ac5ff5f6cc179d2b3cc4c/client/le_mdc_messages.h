/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef LE_MDC_MESSAGES_H_INCLUDE_GUARD
#define LE_MDC_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "9a55e90a9cb0372ad254ab54cc77d371"

#ifdef MK_TOOLS_BUILD
    extern const char** le_mdc_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*le_mdc_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "le_mdc"
#endif


#define _MAX_MSG_SIZE 13276

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_le_mdc_AddSessionStateHandler 0
#define _MSGID_le_mdc_RemoveSessionStateHandler 1
#define _MSGID_le_mdc_AddMtPdpSessionStateHandler 2
#define _MSGID_le_mdc_RemoveMtPdpSessionStateHandler 3
#define _MSGID_le_mdc_GetProfile 4
#define _MSGID_le_mdc_GetProfileIndex 5
#define _MSGID_le_mdc_StartSession 6
#define _MSGID_le_mdc_StartSessionAsync 7
#define _MSGID_le_mdc_StopSession 8
#define _MSGID_le_mdc_StopSessionAsync 9
#define _MSGID_le_mdc_RejectMtPdpSession 10
#define _MSGID_le_mdc_GetSessionState 11
#define _MSGID_le_mdc_GetInterfaceName 12
#define _MSGID_le_mdc_GetIPv4Address 13
#define _MSGID_le_mdc_GetIPv4GatewayAddress 14
#define _MSGID_le_mdc_GetIPv4DNSAddresses 15
#define _MSGID_le_mdc_GetIPv6Address 16
#define _MSGID_le_mdc_GetIPv6GatewayAddress 17
#define _MSGID_le_mdc_GetIPv6DNSAddresses 18
#define _MSGID_le_mdc_IsIPv4 19
#define _MSGID_le_mdc_IsIPv6 20
#define _MSGID_le_mdc_GetDataBearerTechnology 21
#define _MSGID_le_mdc_GetBytesCounters 22
#define _MSGID_le_mdc_ResetBytesCounter 23
#define _MSGID_le_mdc_StopBytesCounter 24
#define _MSGID_le_mdc_StartBytesCounter 25
#define _MSGID_le_mdc_SetPDP 26
#define _MSGID_le_mdc_GetPDP 27
#define _MSGID_le_mdc_SetAPN 28
#define _MSGID_le_mdc_SetDefaultAPN 29
#define _MSGID_le_mdc_GetAPN 30
#define _MSGID_le_mdc_SetAuthentication 31
#define _MSGID_le_mdc_GetAuthentication 32
#define _MSGID_le_mdc_NumProfiles 33
#define _MSGID_le_mdc_GetProfileFromApn 34
#define _MSGID_le_mdc_GetDisconnectionReason 35
#define _MSGID_le_mdc_GetPlatformSpecificDisconnectionCode 36
#define _MSGID_le_mdc_GetPlatformSpecificFailureConnectionReason 37
#define _MSGID_le_mdc_GetDisconnectionReasonExt 38
#define _MSGID_le_mdc_GetPlatformSpecificDisconnectionCodeExt 39
#define _MSGID_le_mdc_GetPlatformSpecificFailureConnectionReasonExt 40
#define _MSGID_le_mdc_MapProfileOnNetworkInterface 41
#define _MSGID_le_mdc_GetProfileList 42


// Define type-safe pack/unpack functions for all enums, including included types

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

#endif // LE_MDC_MESSAGES_H_INCLUDE_GUARD