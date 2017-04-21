enum __type
{
	__ShowWindow,

	__type_reserved
};

int hook_on(PSTR pszCalleeModeName, PSTR pszFuncName, PROC ppfnHook, int index);
BOOL
WINAPI
hook_ShowWindow(
				__in HWND hWnd,
				__in int nCmdShow);

extern PROC g_pfnOrigin[64];
