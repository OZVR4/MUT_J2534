#pragma once

#include "structs.h"

#ifdef J2534_EXPORTS
#define J2534_API __declspec(dllexport)
#else
#define J2534_API __declspec(dllimport)
#endif



// Get the position of the current value in the sequence.
extern "C" J2534_API long PassThruClose(unsigned long DeviceID);
extern "C" J2534_API long PassThruConnect(unsigned long DeviceID, unsigned long ProtocolID, unsigned long Flags, unsigned long BaudRate, unsigned long *pChannelID);
extern "C" J2534_API long PassThruDisconnect(unsigned long ChannelID);
extern "C" J2534_API long PassThruGetLastError(char *pErrorDescription);
extern "C" J2534_API long PassThruIoctl(unsigned long ChannelID, unsigned long IoctlID, void* pInput, void* pOutput);
extern "C" J2534_API long PassThruOpen(void *pName,	unsigned long *pDeviceID);
extern "C" J2534_API long PassThruReadMsgs(unsigned long ChannelID, PASSTHRU_MSG *pMsg,	unsigned long* pNumMsgs, unsigned long Timeout);
extern "C" J2534_API long PassThruReadVersion(unsigned long DeviceID, char *pFirmwareVersion, char *pDllVersion, char *pApiVersion);
extern "C" J2534_API long PassThruSetProgrammingVoltage(unsigned long DeviceID,	unsigned long PinNumber, unsigned long Voltage);
extern "C" J2534_API long PassThruStartMsgFilter(unsigned long ChannelID, unsigned long FilterType, PASSTHRU_MSG *pMaskMsg, PASSTHRU_MSG *pPatternMsg, PASSTHRU_MSG *pFlowControlMsg, unsigned long* pFilterID);
extern "C" J2534_API long PassThruStartPeriodicMsg(unsigned long ChannelID, PASSTHRU_MSG *pMsg, unsigned long* pMsgID, unsigned long TimeInterval);
extern "C" J2534_API long PassThruStopMsgFilter(unsigned long ChannelID,	unsigned long FilterID);
extern "C" J2534_API long PassThruStopPeriodicMsg(unsigned long ChannelID, unsigned long MsgID);
extern "C" J2534_API long PassThruWriteMsgs(unsigned long ChannelID, PASSTHRU_MSG *pMsg, unsigned long* pNumMsgs, unsigned long Timeout);

typedef long(WINAPI* PassThruClose_WINAPI)(unsigned long);
extern PassThruClose_WINAPI PassThruClose_DLL;

typedef long(WINAPI* PassThruConnect_WINAPI)(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long*);
extern PassThruConnect_WINAPI PassThruConnect_DLL;

typedef long(WINAPI* PassThruDisconnect_WINAPI)(unsigned long);
extern PassThruDisconnect_WINAPI PassThruDisconnect_DLL;

typedef long(WINAPI* PassThruGetLastError_WINAPI)(char*);
extern PassThruGetLastError_WINAPI PassThruGetLastError_DLL;

typedef long(WINAPI* PassThruIoctl_WINAPI)(unsigned long, unsigned long, void*, void*);
extern PassThruIoctl_WINAPI PassThruIoctl_DLL;

typedef long(WINAPI* PassThruOpen_WINAPI)(void*, unsigned long*);
extern PassThruOpen_WINAPI PassThruOpen_DLL;

typedef long(WINAPI* PassThruReadMsgs_WINAPI)(unsigned long, PASSTHRU_MSG*, unsigned long*, unsigned long);
extern PassThruReadMsgs_WINAPI PassThruReadMsgs_DLL;

typedef long(WINAPI* PassThruReadVersion_WINAPI)(unsigned long, char*, char*, char*);
extern PassThruReadVersion_WINAPI PassThruReadVersion_DLL;

typedef long(WINAPI* PassThruSetProgrammingVoltage_WINAPI)(unsigned long, unsigned long, unsigned long);
extern PassThruSetProgrammingVoltage_WINAPI PassThruSetProgrammingVoltage_DLL;

typedef long(WINAPI* PassThruStartMsgFilter_WINAPI)(unsigned long, unsigned long, PASSTHRU_MSG*, PASSTHRU_MSG*, PASSTHRU_MSG*, unsigned long*);
extern PassThruStartMsgFilter_WINAPI PassThruStartMsgFilter_DLL;

typedef long(WINAPI* PassThruStartPeriodicMsg_WINAPI)(unsigned long, PASSTHRU_MSG*, unsigned long*, unsigned long);
extern PassThruStartPeriodicMsg_WINAPI PassThruStartPeriodicMsg_DLL;

typedef long(WINAPI* PassThruStopMsgFilter_WINAPI)(unsigned long, unsigned long);
extern PassThruStopMsgFilter_WINAPI PassThruStopMsgFilter_DLL;

typedef long(WINAPI* PassThruStopPeriodicMsg_WINAPI)(unsigned long, unsigned long);
extern PassThruStopPeriodicMsg_WINAPI PassThruStopPeriodicMsg_DLL;

typedef long(WINAPI* PassThruWriteMsgs_WINAPI)(unsigned long, PASSTHRU_MSG*, unsigned long*, unsigned long);
extern PassThruWriteMsgs_WINAPI PassThruWriteMsgs_DLL;