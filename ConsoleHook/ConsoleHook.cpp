// ConsoleHook.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "ConsoleHandler.h"
#include "ConsoleHook.h"

//////////////////////////////////////////////////////////////////////////////

ConsoleHandler	g_consoleHandler;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID /* lpReserved */)
{
	TRACE(L"DLL main!\n");
	
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			g_hModule = (HMODULE)hModule;
			g_consoleHandler.StartMonitorThread();

			break;
		}

		case DLL_THREAD_ATTACH:
			break;

		case DLL_THREAD_DETACH:
			break;

		case DLL_PROCESS_DETACH:

			g_consoleHandler.StopMonitorThread();
			TRACE(L"Hook exiting!\n");
			break;
	}

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
