// dllmain.cpp : Defines the entry point for the DLL application.

#include "pch.h"
#include <iostream>
#include "structs.h"



BOOL WINAPI MyHandlerRoutine(DWORD dwCtrlType) {
    TerminateProcess(GetCurrentProcess(), 2);
    return TRUE;
}

typedef long(WINAPI* PassThruClose_WINAPI)(unsigned long);
PassThruClose_WINAPI PassThruClose_DLL;

typedef long(WINAPI* PassThruConnect_WINAPI)(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long*);
PassThruConnect_WINAPI PassThruConnect_DLL;

typedef long(WINAPI* PassThruDisconnect_WINAPI)(unsigned long);
PassThruDisconnect_WINAPI PassThruDisconnect_DLL;

typedef long(WINAPI* PassThruGetLastError_WINAPI)(char*);
PassThruGetLastError_WINAPI PassThruGetLastError_DLL;

typedef long(WINAPI* PassThruIoctl_WINAPI)(unsigned long, unsigned long, void*, void*);
PassThruIoctl_WINAPI PassThruIoctl_DLL;

typedef long(WINAPI* PassThruOpen_WINAPI)(void*, unsigned long*);
PassThruOpen_WINAPI PassThruOpen_DLL;

typedef long(WINAPI* PassThruReadMsgs_WINAPI)(unsigned long, PASSTHRU_MSG*, unsigned long*, unsigned long);
PassThruReadMsgs_WINAPI PassThruReadMsgs_DLL;

typedef long(WINAPI* PassThruReadVersion_WINAPI)(unsigned long , char* , char* , char* );
PassThruReadVersion_WINAPI PassThruReadVersion_DLL;

typedef long(WINAPI* PassThruSetProgrammingVoltage_WINAPI)(unsigned long, unsigned long, unsigned long);
PassThruSetProgrammingVoltage_WINAPI PassThruSetProgrammingVoltage_DLL;

typedef long(WINAPI* PassThruStartMsgFilter_WINAPI)(unsigned long , unsigned long , PASSTHRU_MSG* , PASSTHRU_MSG* , PASSTHRU_MSG* , unsigned long* );
PassThruStartMsgFilter_WINAPI PassThruStartMsgFilter_DLL;

typedef long(WINAPI* PassThruStartPeriodicMsg_WINAPI)(unsigned long, PASSTHRU_MSG*, unsigned long*, unsigned long);
PassThruStartPeriodicMsg_WINAPI PassThruStartPeriodicMsg_DLL;

typedef long(WINAPI* PassThruStopMsgFilter_WINAPI)(unsigned long, unsigned long);
PassThruStopMsgFilter_WINAPI PassThruStopMsgFilter_DLL;

typedef long(WINAPI* PassThruStopPeriodicMsg_WINAPI)(unsigned long , unsigned long );
PassThruStopPeriodicMsg_WINAPI PassThruStopPeriodicMsg_DLL;

typedef long(WINAPI* PassThruWriteMsgs_WINAPI)(unsigned long, PASSTHRU_MSG*, unsigned long*, unsigned long);
PassThruWriteMsgs_WINAPI PassThruWriteMsgs_DLL;


FILE* f1 = NULL, * f2 = NULL, * f3 = NULL;

HINSTANCE hDLL;               // Handle to DLL


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)

{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        AllocConsole();
        SetConsoleCtrlHandler(MyHandlerRoutine, TRUE);
        freopen_s(&f1, "CONIN$", "rb", stdin);
        freopen_s(&f2, "CONOUT$", "wb", stdout);
        freopen_s(&f3, "CONOUT$", "wb", stderr);
        
        hDLL = LoadLibrary(L"C:\\windows\\system32\\op20pt32.dll");

        if (hDLL != NULL)
        {
            PassThruClose_DLL = (PassThruClose_WINAPI)GetProcAddress(hDLL, "PassThruClose");
            std::cout << "PassThruClose_DLL found at 0x" << PassThruClose_DLL << std::endl;
            if (!PassThruClose_DLL)
            {
                FreeLibrary(hDLL);
            }

            

            PassThruConnect_DLL = (PassThruConnect_WINAPI)GetProcAddress(hDLL, "PassThruConnect");
            std::cout << "PassThruConnect_DLL found at 0x" << PassThruConnect_DLL << std::endl;
            if (!PassThruConnect_DLL)
            {
                FreeLibrary(hDLL);
            }
            

            PassThruDisconnect_DLL = (PassThruDisconnect_WINAPI)GetProcAddress(hDLL, "PassThruDisconnect");
            std::cout << "PassThruDisconnect_DLL found at 0x" << PassThruDisconnect_DLL << std::endl;
            if (!PassThruDisconnect_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruGetLastError_DLL = (PassThruGetLastError_WINAPI)GetProcAddress(hDLL, "PassThruGetLastError");
            std::cout << "PassThruGetLastError_DLL found at 0x" << PassThruGetLastError_DLL << std::endl;
            if (!PassThruGetLastError_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruIoctl_DLL = (PassThruIoctl_WINAPI)GetProcAddress(hDLL, "PassThruIoctl");
            std::cout << "PassThruIoctl_DLL found at 0x" << PassThruIoctl_DLL << std::endl;
            if (!PassThruIoctl_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruOpen_DLL = (PassThruOpen_WINAPI)GetProcAddress(hDLL, "PassThruOpen");
            std::cout << "PassThruOpen_DLL found at 0x" << PassThruOpen_DLL << std::endl;
            if (!PassThruOpen_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruReadMsgs_DLL = (PassThruReadMsgs_WINAPI)GetProcAddress(hDLL, "PassThruReadMsgs");
            std::cout << "PassThruReadMsgs_DLL found at 0x" << PassThruReadMsgs_DLL << std::endl;
            if (!PassThruReadMsgs_DLL)
            {
                FreeLibrary(hDLL);
            }


            PassThruReadVersion_DLL = (PassThruReadVersion_WINAPI)GetProcAddress(hDLL, "PassThruReadVersion");
            std::cout << "PassThruReadVersion_DLL found at 0x" << PassThruReadVersion_DLL << std::endl;
            if (!PassThruReadVersion_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruSetProgrammingVoltage_DLL = (PassThruSetProgrammingVoltage_WINAPI)GetProcAddress(hDLL, "PassThruSetProgrammingVoltage");
            std::cout << "PassThruSetProgrammingVoltage_DLL found at 0x" << PassThruSetProgrammingVoltage_DLL << std::endl;
            if (!PassThruSetProgrammingVoltage_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruStartMsgFilter_DLL = (PassThruStartMsgFilter_WINAPI)GetProcAddress(hDLL, "PassThruStartMsgFilter");
            std::cout << "PassThruStartMsgFilter_DLL found at 0x" << PassThruStartMsgFilter_DLL << std::endl;
            if (!PassThruStartMsgFilter_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruStartPeriodicMsg_DLL = (PassThruStartPeriodicMsg_WINAPI)GetProcAddress(hDLL, "PassThruStartPeriodicMsg");
            std::cout << "PassThruStartPeriodicMsg_DLL found at 0x" << PassThruStartPeriodicMsg_DLL << std::endl;
            if (!PassThruStartPeriodicMsg_DLL)
            {
                FreeLibrary(hDLL);
            }
            
            PassThruStopMsgFilter_DLL = (PassThruStopMsgFilter_WINAPI)GetProcAddress(hDLL, "PassThruStopMsgFilter");
            std::cout << "PassThruStopMsgFilter_DLL found at 0x" << PassThruStopMsgFilter_DLL << std::endl;
            if (!PassThruStopMsgFilter_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruStopPeriodicMsg_DLL = (PassThruStopPeriodicMsg_WINAPI)GetProcAddress(hDLL, "PassThruStopPeriodicMsg");
            std::cout << "PassThruStopPeriodicMsg_DLL found at 0x" << PassThruStopPeriodicMsg_DLL << std::endl;
            if (!PassThruStopPeriodicMsg_DLL)
            {
                FreeLibrary(hDLL);
            }

            PassThruWriteMsgs_DLL = (PassThruWriteMsgs_WINAPI)GetProcAddress(hDLL, "PassThruWriteMsgs");
            std::cout << "PassThruWriteMsgs_DLL found at 0x" << PassThruWriteMsgs_DLL << std::endl;
            if (!PassThruWriteMsgs_DLL)
            {
                FreeLibrary(hDLL);
            }

        }
       
        break;
    }

    case DLL_PROCESS_DETACH:
    {

        fclose(f1);
        fclose(f2);
        fclose(f3);
        FreeConsole();
        if (hDLL != NULL)
        {
            FreeLibrary(hDLL);
        }
        break;
    }
    }
    return TRUE;
}