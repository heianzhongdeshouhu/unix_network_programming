// hook_ShowWindowTestDlg.h : header file
//

#pragma once


// Chook_ShowWindowTestDlg dialog
class Chook_ShowWindowTestDlg : public CDialog
{
// Construction
public:
	Chook_ShowWindowTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_HOOK_SHOWWINDOWTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCreateProcess();
};
