
#include "pch.h"
#include "MUT.h"
#include <iostream>


long PassThruClose(unsigned long DeviceID)
{
    return PassThruClose_DLL(DeviceID);
}

long PassThruConnect(unsigned long DeviceID, unsigned long ProtocolID, unsigned long Flags, unsigned long BaudRate, unsigned long* pChannelID)
{
    return PassThruConnect_DLL(DeviceID, ProtocolID, Flags, BaudRate, pChannelID);
}

long PassThruDisconnect(unsigned long ChannelID)
{
    return PassThruDisconnect_DLL(ChannelID);
}

long PassThruGetLastError(char* pErrorDescription)
{
    return PassThruGetLastError_DLL(pErrorDescription);
}

long PassThruIoctl(unsigned long ChannelID, unsigned long IoctlID, void* pInput, void* pOutput)
{
    return PassThruIoctl_DLL(ChannelID, IoctlID, pInput, pOutput);
}

long PassThruOpen(void* pName, unsigned long* pDeviceID)
{
    return PassThruOpen_DLL(pName, pDeviceID);
}

long PassThruReadMsgs(unsigned long ChannelID, PASSTHRU_MSG* pMsg, unsigned long* pNumMsgs, unsigned long Timeout)
{
    return PassThruReadMsgs_DLL(ChannelID, pMsg, pNumMsgs, Timeout);
}

long PassThruReadVersion(unsigned long DeviceID, char* pFirmwareVersion, char* pDllVersion, char* pApiVersion)
{
    return PassThruReadVersion_DLL(DeviceID, pFirmwareVersion, pDllVersion, pApiVersion);
}

long PassThruSetProgrammingVoltage(unsigned long DeviceID, unsigned long PinNumber, unsigned long Voltage)
{
    return PassThruSetProgrammingVoltage_DLL(DeviceID, PinNumber, Voltage);
}

long PassThruStartMsgFilter(unsigned long ChannelID, unsigned long FilterType, PASSTHRU_MSG* pMaskMsg, PASSTHRU_MSG* pPatternMsg, PASSTHRU_MSG* pFlowControlMsg, unsigned long* pFilterID)
{
    return PassThruStartMsgFilter_DLL(ChannelID, FilterType, pMaskMsg, pPatternMsg, pFlowControlMsg, pFilterID);
}

long PassThruStartPeriodicMsg(unsigned long ChannelID, PASSTHRU_MSG* pMsg, unsigned long* pMsgID, unsigned long TimeInterval)
{
    return PassThruStartPeriodicMsg_DLL(ChannelID, pMsg, pMsgID, TimeInterval);
}

long PassThruStopMsgFilter(unsigned long ChannelID, unsigned long FilterID)
{
    return PassThruStopMsgFilter_DLL(  ChannelID,   FilterID);
}

long PassThruStopPeriodicMsg(unsigned long ChannelID, unsigned long MsgID)
{
    return PassThruStopPeriodicMsg_DLL(ChannelID, MsgID);
}

long PassThruWriteMsgs(unsigned long ChannelID, PASSTHRU_MSG* pMsg, unsigned long* pNumMsgs, unsigned long Timeout)
{
    return PassThruWriteMsgs_DLL(ChannelID, pMsg, pNumMsgs, Timeout);
}
