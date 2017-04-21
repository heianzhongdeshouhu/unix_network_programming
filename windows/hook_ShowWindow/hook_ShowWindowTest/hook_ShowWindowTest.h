// hook_ShowWindowTest.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Chook_ShowWindowTestApp:
// See hook_ShowWindowTest.cpp for the implementation of this class
//

class Chook_ShowWindowTestApp : public CWinApp
{
public:
	Chook_ShowWindowTestApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Chook_ShowWindowTestApp theApp;