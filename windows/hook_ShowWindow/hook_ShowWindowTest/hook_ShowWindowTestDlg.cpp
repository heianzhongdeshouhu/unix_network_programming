// hook_ShowWindowTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hook_ShowWindowTest.h"
#include "hook_ShowWindowTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Chook_ShowWindowTestDlg dialog




Chook_ShowWindowTestDlg::Chook_ShowWindowTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Chook_ShowWindowTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Chook_ShowWindowTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Chook_ShowWindowTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_CREATE_PROCESS, &Chook_ShowWindowTestDlg::OnBnClickedButtonCreateProcess)
END_MESSAGE_MAP()


// Chook_ShowWindowTestDlg message handlers

BOOL Chook_ShowWindowTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Chook_ShowWindowTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Chook_ShowWindowTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Chook_ShowWindowTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



typedef int (*pfn_hook_ShowWindow)();
typedef HMODULE( WINAPI *pfnLoadLibraryA)(__in LPCSTR lpLibFileName);

typedef 
FARPROC
(
WINAPI
*pfnGetProcAddress )
(
				__in HMODULE hModule,
				__in LPCSTR lpProcName
				);

typedef HMODULE
(
WINAPI
*pfnGetModuleHandleA)
(
				 __in_opt LPCSTR lpModuleName
				 );

struct ParamInfo {
	pfnGetProcAddress pfn_get_proc_address;
	pfnGetModuleHandleA pfn_get_module_handlea;
	char name_kernel[32];
	char name_load_library[32];
	char name_dll[256];
	char name_fun[32];
};
DWORD WINAPI RemothThreadProc(LPVOID lpParameter) {
	ParamInfo *pinfo = (ParamInfo *)lpParameter;
	if (!pinfo)
	{
		return 0;
	}
	
	pfnGetProcAddress pgpa = pinfo->pfn_get_proc_address;
	pfnGetModuleHandleA pgmh = pinfo->pfn_get_module_handlea;
	pfnLoadLibraryA pfn_load_librarya =  (pfnLoadLibraryA)(pgpa(pgmh(pinfo->name_kernel), pinfo->name_load_library));
	if (pfn_load_librarya)
	{
		HMODULE hdll = pfn_load_librarya(pinfo->name_dll); 
		if (hdll)
		{
			pfn_hook_ShowWindow pfn_hs = (pfn_hook_ShowWindow)pgpa(hdll, pinfo->name_fun);
			if (pfn_hs)
			{
				pfn_hs();
			}
		}
	}
	

	return 0;
}




int inject_dll(DWORD dwProcessId, const char *pszLibFile) {
	PWSTR pszLibFileRemote = NULL;
	LPVOID pfn_remote_thread = NULL;
	__try{
		// Get a handle for the target process.
		HANDLE hProcess = OpenProcess(
			PROCESS_QUERY_INFORMATION |   // Required by Alpha
			PROCESS_CREATE_THREAD     |   // For CreateRemoteThread
			PROCESS_VM_OPERATION      |   // For VirtualAllocEx/VirtualFreeEx
			PROCESS_VM_WRITE,             // For WriteProcessMemory
			FALSE, dwProcessId);
		if (hProcess == NULL) __leave;

		// Calculate the number of bytes needed for the DLL's pathname
		
		

		
		ParamInfo info;
		memset(&info, 0, sizeof(info));
		strcpy(info.name_kernel, "Kernel32");
		strcpy(info.name_load_library, "LoadLibraryA");
		strcpy(info.name_dll, pszLibFile);
		strcpy(info.name_fun, "fun_test");
		info.pfn_get_proc_address = (pfnGetProcAddress)GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "GetProcAddress");
		info.pfn_get_module_handlea = (pfnGetModuleHandleA)GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "GetModuleHandleA");

		SIZE_T cb  = sizeof(info);


		// Allocate space in the remote process for the pathname
		pszLibFileRemote = (PWSTR) 
			VirtualAllocEx(hProcess, NULL, cb, MEM_COMMIT, PAGE_READWRITE);
		if (pszLibFileRemote == NULL) __leave;

		// Copy the DLL's pathname to the remote process's address space
		if (!WriteProcessMemory(hProcess, pszLibFileRemote, 
			(PVOID) &info, cb, NULL)) __leave;
		
		
		cb = (DWORD)inject_dll - (DWORD)RemothThreadProc;
		pfn_remote_thread = VirtualAllocEx(hProcess, NULL, cb, MEM_COMMIT, PAGE_EXECUTE_READWRITE);;
		if (NULL == pfn_remote_thread)
		{
			__leave;
		}
		if (!WriteProcessMemory(hProcess, pfn_remote_thread, 
			(PVOID) &RemothThreadProc, cb, NULL)) {
				__leave;
		}		

		HANDLE hthread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pfn_remote_thread, pszLibFileRemote, 0, NULL);	
		if (NULL == hthread)
		{
			DWORD dwErr = GetLastError();
			printf("dd");
		}
		//CloseHandle(hthread);
	}
	__finally {

	}
	

	return 0;
}
unsigned __stdcall proc_thread( void * ) {

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );


	//char *pcmdline = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe http://www.qq.com/";
//	char *FileName = "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe http://www.qq.com/";
	//char *pcmdline = "E:\\ef\\meng_local\\pj_test\\vs2008\\yp_test_April_13th\\Debug\\exe_with_log.exe";
//	char *pcmdline = "sdi.exe";	
	char *pcmdline = "E:\\x工作日志\\11_配置业务专用\\SmartPlan\\Debug\\SmartPlan.exe";

	// Start the child process. 
	if( !CreateProcess( NULL,   // No module name (use command line)
		pcmdline,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		//CREATE_SUSPENDED,// No creation flags
		0,// No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi )           // Pointer to PROCESS_INFORMATION structure
		) 
	{
		DWORD dwerr = GetLastError();
		printf( "CreateProcess failed (%d)\n", GetLastError() );
		return 0;
	}

	//const char *path_dll = "E:\\ef\\meng_local\\pj_test\\vs2008\\hook_ShowWindow\\Debug\\hook_ShowWindow.dll";
	char *path_dll = "hook_ShowWindow.dll";
	inject_dll(pi.dwProcessId, path_dll);

	ResumeThread(pi.hThread); 

	// Wait until child process exits.
	WaitForSingleObject( pi.hProcess, INFINITE );

	// Close process and thread handles. 
	CloseHandle( pi.hProcess );
	CloseHandle( pi.hThread );

	return 0;
}
void Chook_ShowWindowTestDlg::OnBnClickedButtonCreateProcess()
{
	// TODO: Add your control notification handler code here
	HANDLE hthread = (HANDLE)_beginthreadex(NULL, 0, proc_thread, NULL, 0, NULL);
	if (hthread)
	{
		CloseHandle(hthread);
	}
}
