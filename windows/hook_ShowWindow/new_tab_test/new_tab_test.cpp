// new_tab_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int create_process_test() {
	

	return 0;
}

int shell_execute_test() {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	char *pcommandline = "";

	// Start the child process. 
	if( !CreateProcess( NULL,   // No module name (use command line)
		pcommandline,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi )           // Pointer to PROCESS_INFORMATION structure
		) 
	{
		printf( "CreateProcess failed (%d)\n", GetLastError() );
		return 0;
	}

	// Wait until child process exits.
	WaitForSingleObject( pi.hProcess, INFINITE );

	// Close process and thread handles. 
	CloseHandle( pi.hProcess );
	CloseHandle( pi.hThread );
	

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	create_process_test();
//	shell_execute_test();

	return 0;
}

