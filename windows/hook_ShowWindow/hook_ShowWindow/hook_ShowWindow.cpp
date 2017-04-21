// hook_ShowWindow.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "common.h"

extern CRITICAL_SECTION g_secNum;
int log_log(const char *msg);

int fun_test() {

// 	MessageBoxA(NULL, "fun_test() is called", "ok", MB_OK| MB_SYSTEMMODAL);
// 	return 0;

	log_log("fun_test() is called ^_^[this is a test]\n");

	InitializeCriticalSection(&g_secNum);

	hook_on("user32.dll",	"ShowWindow",			(PROC)hook_ShowWindow,			__ShowWindow);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)g_pfnOrigin[__ShowWindow], hook_ShowWindow);

	DetourTransactionCommit();	

	return 0;
}