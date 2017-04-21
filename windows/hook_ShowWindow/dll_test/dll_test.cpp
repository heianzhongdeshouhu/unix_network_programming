// dll_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
typedef int ( *MYPROC)(); 


int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hinstLib; 
	MYPROC ProcAdd; 
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE; 

	// Get a handle to the DLL module.

	hinstLib = LoadLibrary(TEXT("E:\\ef\\meng_local\\pj_test\\vs2008\\hook_ShowWindow\\Debug\\hook_ShowWindow.dll")); 

	// If the handle is valid, try to get the function address.

	if (hinstLib != NULL) 
	{ 
		ProcAdd = (MYPROC) GetProcAddress(hinstLib, "fun_test"); 

		// If the function address is valid, call the function.

		if (NULL != ProcAdd) 
		{
			fRunTimeLinkSuccess = TRUE;
			(ProcAdd) (); 
		}

		// Free the DLL module.

		fFreeResult = FreeLibrary(hinstLib); 
	} 

	// If unable to call the DLL function, use an alternative.

	if (! fRunTimeLinkSuccess) 
		printf("Message printed from executable\n"); 


	return 0;
}

