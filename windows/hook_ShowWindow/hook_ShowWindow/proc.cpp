#include "stdafx.h"

#include "common.h"

CRITICAL_SECTION g_secNum;
PROC g_pfnOrigin[64];
PSTR g_moduleCallee[1024][128];
PROC g_pfnNew[64];

int log_log(const char *msg);

typedef BOOL(WINAPI *pfnShowWindow)(
				__in HWND hWnd,
				__in int nCmdShow);

BOOL
WINAPI
hook_ShowWindow(
		   __in HWND hWnd,
		   __in int nCmdShow)
{
	//return ShowWindow(hWnd, SW_HIDE);
	log_log("hook_ShowWindow() is called ^_^\n");
	return ((pfnShowWindow)(g_pfnOrigin[__ShowWindow]))(hWnd, SW_HIDE);
	
}

int log_log(const char *msg)
{
	UINT uTypeError = MB_OK| MB_ICONERROR| MB_SYSTEMMODAL;
	FILE *pFile = NULL;
	errno_t ival = fopen_s(&pFile, "e:\\on_get.txt", "a+b");
	if (ival)
	{
		MessageBoxA(NULL, "fopen_s() fails!", "error", uTypeError);
	}
	else
	{
		size_t num = fwrite(msg, strlen(msg), 1, pFile);
		if (1 != num)
		{
			MessageBoxA(NULL, "fwrite() fails!", "error", uTypeError);
		}
		int _ival = fclose(pFile);
		if (EOF == _ival)
		{
			MessageBoxA(NULL, "fclose() fails!", "error", uTypeError);
		}
	}
	return 0;
}  


int hook_on(PSTR pszCalleeModeName, PSTR pszFuncName, PROC ppfnHook, int index)
{
	if (pszCalleeModeName && pszFuncName && ppfnHook)
	{
		__try
		{
			EnterCriticalSection(&g_secNum);

			strcpy_s((char *)(g_moduleCallee[index]), 128, pszCalleeModeName);
			HMODULE hModule = GetModuleHandleA(LPCSTR(g_moduleCallee[index]));

			if (NULL == hModule)
			{
				DWORD dwError = GetLastError();
				if ((ERROR_MOD_NOT_FOUND == dwError) && (0 == strcmp(pszCalleeModeName, "Ws2_32.dll")))
				{					
					HMODULE hDll = GetModuleHandleW(L"Ws2_32.dll");
					if (!hDll)
					{
						HMODULE  hLoaded = LoadLibraryW(L"Ws2_32.dll");
						if (!hLoaded)
						{
							DWORD dwError = GetLastError();
							const int Len = 1024;
							char desc[Len];
							sprintf_s(desc, Len,"hook_on LoadLibrary(Ws2_32.dll) fails. GetLastError() = %u\r\n", dwError);
							log_log(desc);
						}					
					}
					hModule = GetModuleHandleA(LPCSTR(g_moduleCallee[index]));
				}
				else
				{
					const int Len = 1024;
					char desc[Len];
					sprintf_s(desc, Len, "GetModuleHandle()  fails, GetLastError() = %u.", 
						dwError);
					log_log(desc);
				}
			}

			g_pfnOrigin[index] = GetProcAddress(hModule, pszFuncName);
			if (!(g_pfnOrigin[index]))
			{
				DWORD dwError = GetLastError();

				if (ERROR_PROC_NOT_FOUND != dwError)
				{
					const int Len = 1024;
					char desc[Len];
					sprintf_s(desc, Len, "GetProcAddress() init fails, GetLastError() = %u.\tpModule = [%s] pProc = [%s]\r\n", 
						dwError, pszCalleeModeName, pszFuncName);
					log_log(desc);
				}
			}

			g_pfnNew[index] = ppfnHook;

		}
		__finally
		{
			LeaveCriticalSection(&g_secNum);
		}
	}

	return 0;
}